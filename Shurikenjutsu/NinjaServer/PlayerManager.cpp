#include "PlayerManager.h"
#include "SpikeManager.h"
#include "FanBoomerangManager.h"
#include "ProjectileManager.h"
#include "StickyTrapManager.h"
#include "VolleyManager.h"
#include "..\CommonLibs\ConsoleFunctions.h"

#include "..\CommonLibs\ModelNames.h"

PlayerManager::PlayerManager(){}
PlayerManager::~PlayerManager(){}

bool PlayerManager::Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName)
{
	m_playerHealth = CHARACTER_KATANA_SHURIKEN_HEALTH;
//	m_gcd = ALL_AROUND_GLOBAL_COOLDOWN;

	m_serverPeer = p_serverPeer;

	m_players = std::vector<PlayerNet>();
	m_spawnPoints = std::vector<LevelImporter::SpawnPoint>();

	// Load spawnpoints
	Level level(p_levelName);
	m_spawnPoints = level.GetSpawnPoints();

	// Todo: move to player
	m_katanaBoundingBoxes = ModelLibrary::GetInstance()->GetModel(KATANA_NINJA_MODEL_NAME)->GetBoundingBoxes();
	m_tessenBoundingBoxes = ModelLibrary::GetInstance()->GetModel(TESSEN_NINJA_MODEL_NAME)->GetBoundingBoxes();
	m_naginataBoundingBoxes = ModelLibrary::GetInstance()->GetModel(NAGINATA_NINJA_MODEL_NAME)->GetBoundingBoxes();

	m_sendIntervall = TICK_RATE;
	m_lastTimeSent = 0.0;

	m_dotIntervall = 0.1;
	m_lastDotSent = 0.0;
	m_canSendDotDamage = true;
	m_haveSentDotDamage = false;

	m_hotIntervall = 3.0;
	m_lastHotSent = 0.0;
	m_canSendDotDamage = true;
	m_haveSentDotDamage = false;

	m_playerVisibility = std::map<RakNet::RakNetGUID, std::vector<int>>();
	ResetTakenSpawnPoints();


	return true;
}

void PlayerManager::ResetTakenSpawnPoints()
{
	m_takenSpawnPoints.clear();
}

void PlayerManager::Shutdown(){}

void PlayerManager::Update(double p_deltaTime)
{
	// Timer for sending position and direction
	m_lastTimeSent -= p_deltaTime;
	if (m_lastTimeSent < 0)
	{
		m_lastTimeSent = m_sendIntervall;
		// Send position and direction of players
		SendPlayerPosAndDir();

		// Send visible players
		SendVisiblePlayers();
	}

	// Timer for dot damage
	m_lastDotSent -= p_deltaTime;
	if (m_haveSentDotDamage)
	{
		m_canSendDotDamage = false;
		m_haveSentDotDamage = false;
	}
	if (m_lastDotSent < 0)
	{
		m_lastDotSent = m_dotIntervall;
		m_canSendDotDamage = true;
	}

	// Timer hot
	m_lastHotSent -= p_deltaTime;
	if (m_haveSentHotDamage)
	{
		m_canSendHotDamage = false;
		m_haveSentHotDamage = false;
	}
	if (m_lastHotSent < 0)
	{
		m_lastHotSent = m_hotIntervall;
		m_canSendHotDamage = true;
	}

	HealPlayer();
}

std::vector<PlayerNet> PlayerManager::GetPlayers()
{
	return m_players;
}

void PlayerManager::AddPlayer(RakNet::RakNetGUID p_guid, RakNet::RakString p_name, int p_charNr, int p_toolNr, int p_team)
{
	if (p_charNr == 0)
	{
		m_playerHealth = CHARACTER_KATANA_SHURIKEN_HEALTH;
	}
	else if (p_charNr == 1)
	{
		m_playerHealth = CHARACTER_TESSEN_HEALTH;
	}
	else if (p_charNr == 2)
	{
		m_playerHealth = CHARACTER_NAGINATA_HEALTH;
	}

	PlayerNet player;
	player.guid = p_guid;
	player.id = GetIdForPlayer();
	player.name = p_name;
	if (p_team == 0)
	{
		player.team = GetTeamForPlayer();
	}
	else
	{
		//player.team = p_team;
		int team1 = 0;
		int team2 = 0;
		for (unsigned int i = 0; i < m_players.size(); i++)
		{
			if (m_players[i].team == 1)
			{
				team1++;
			}
			else if (m_players[i].team == 2)
			{
				team2++;
			}
		}
		if (team1 < 4 && p_team == 1)
		{
			player.team = 1;
		}
		else
		{
			player.team = 2;
		}
	}
	player.charNr = p_charNr;
	LevelImporter::SpawnPoint spawnPoint = GetSpawnPoint(player.guid, player.team);
	player.x = spawnPoint.m_translationX;
	player.y = spawnPoint.m_translationY;
	player.z = spawnPoint.m_translationZ;
	player.dirX = 1.0f;
	player.dirY = 0.0f;
	player.dirZ = 0.0f;
	player.gcd = 0.0f;
	player.maxHP = m_playerHealth;
	player.currentHP = m_playerHealth;
	player.isAlive = true;
	player.invis = false;
	player.dotDamage = 0.0f;
	player.hotHeal = 0.0f;
	player.toolNr = p_toolNr;
	player.kills = 0;
	player.deaths = 0;
	player.shield = 0.0f;
	player.hasHealPOI = false;
	m_players.push_back(player);
	
	ConsolePrintText("New player joined.");

	// Broadcast new player
	BroadcastPlayers();

	RakNet::BitStream bitStream2;
	bitStream2.Write((RakNet::MessageID)ID_CONNECTION_NOTIFICATION);
	bitStream2.Write(player.name);
	bitStream2.Write(player.team);

	m_serverPeer->Send(&bitStream2, MEDIUM_PRIORITY, RELIABLE, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

bool PlayerManager::MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections, bool p_dashed)
{
	// See if player can move to target position and then update position
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			// Check so the player is not dead
			if (m_players[i].isAlive)
			{
				if ((abs(p_x - m_players[i].x) > 5.0f || abs(p_y - m_players[i].y) > 5.0f || abs(p_z - m_players[i].z) > 5.0f) && p_dashed == false)
				{
					// Moved too far
					SendInvalidMessage(p_guid);
				}
				else
				{
					m_players[i].x = p_x;
					m_players[i].y = p_y;
					m_players[i].z = p_z;
				}
			}

			return true;
		}
	}

	return false;
}

bool PlayerManager::RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			if (m_players[i].isAlive)
			{
				m_players[i].dirX = p_dirX;
				m_players[i].dirY = p_dirY;
				m_players[i].dirZ = p_dirZ;
			}
			return true;
		}
	}

	return false;
}

void PlayerManager::RemovePlayer(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			m_takenSpawnPoints.erase(m_players[i].guid);
			m_players.erase(m_players.begin() + i);

			ConsolePrintError("A player disconnected.");
			BroadcastPlayers();

			i--;
			break;
		}
	}
}

void PlayerManager::BroadcastPlayers()
{
	int nrOfPlayers = m_players.size();

	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_DOWNLOAD_PLAYERS);
	bitStream.Write(nrOfPlayers);

	for (int i = 0; i < nrOfPlayers; i++)
	{
		bitStream.Write(m_players[i].guid);
		bitStream.Write(m_players[i].id);
		bitStream.Write(m_players[i].name);
		bitStream.Write(m_players[i].x);
		bitStream.Write(m_players[i].y);
		bitStream.Write(m_players[i].z);
		bitStream.Write(m_players[i].dirX);
		bitStream.Write(m_players[i].dirY);
		bitStream.Write(m_players[i].dirZ);
		bitStream.Write(m_players[i].team);
		bitStream.Write(m_players[i].charNr);
		bitStream.Write(m_players[i].maxHP);
		bitStream.Write(m_players[i].currentHP);
		bitStream.Write(m_players[i].isAlive);
		bitStream.Write(false);
		bitStream.Write(m_players[i].toolNr);
		bitStream.Write(m_players[i].deaths);
		bitStream.Write(m_players[i].kills);
		bitStream.Write(m_players[i].shield);
		bitStream.Write(m_players[i].hasHealPOI);
	}

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PlayerManager::RespawnPlayer(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			// Reset position
			LevelImporter::SpawnPoint spawnPoint = GetSpawnPoint(m_players[i].guid, m_players[i].team);
			m_players[i].x = spawnPoint.m_translationX;
			m_players[i].y = spawnPoint.m_translationY;
			m_players[i].z = spawnPoint.m_translationZ;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_RESPAWN_PLAYER);
			bitStream.Write(m_players[i].x);
			bitStream.Write(m_players[i].y);
			bitStream.Write(m_players[i].z);

			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 2, p_guid, false);

			// Reset hot effect
			m_players[i].hasHealPOI = false;
			SendHasPOIHealing(m_players[i].guid);

			break;
		}
	}
}

PlayerNet PlayerManager::GetPlayer(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			return m_players[i];
		}
	}

	return PlayerNet();
}

void PlayerManager::SendInvalidMessage(RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_INVALID_MOVE);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 1, p_guid, false);
}

LevelImporter::SpawnPoint PlayerManager::GetSpawnPoint(RakNet::RakNetGUID p_guid, int p_team)
{
	for (unsigned int i = 0; i < m_spawnPoints.size(); i++)
	{
		if (m_spawnPoints[i].m_team == p_team)
		{
			bool taken = false;
			for (std::map<RakNet::RakNetGUID, int>::iterator it = m_takenSpawnPoints.begin(); it != m_takenSpawnPoints.end(); it++)
			{
				if (it->second == i)
				{
					taken = true;
					break;
				}
			}

			if (taken)
		{
				continue;
			}
			m_takenSpawnPoints[p_guid] = i;
			return m_spawnPoints[i];
		}
	}

	// If the player didn't found a spawnpoint for the team he was in then choose a random point
	int index = rand() % m_spawnPoints.size();
	return m_spawnPoints[index];
}

std::vector<Box> PlayerManager::GetBoundingBoxes(int p_index)
{
	std::vector<Box> boundingBoxes = std::vector<Box>();

	// Check so index is not out of bounds
	if (p_index < 0 || p_index > (int)m_players.size() - 1)
	{
		return boundingBoxes;
	}

	std::vector<Box> tmpBB = std::vector<Box>();
	switch (m_players[p_index].charNr)
	{
		case 0:
		{
			tmpBB = m_katanaBoundingBoxes;
			break;
		}
		case 1:
		{
			tmpBB = m_tessenBoundingBoxes;
			break;
		}
		case 2:
		{
			tmpBB = m_naginataBoundingBoxes;
			break;
		}
	}

	for (unsigned int i = 0; i < tmpBB.size(); i++)
	{
		Box box = tmpBB[i];
		box.m_center.x += m_players[p_index].x;
		box.m_center.y += m_players[p_index].y;
		box.m_center.z += m_players[p_index].z;

		boundingBoxes.push_back(box);
	}

	return boundingBoxes;
}

void PlayerManager::ExecuteAbility(float p_deltaTime, RakNet::RakNetGUID p_guid, ABILITIES p_readAbility, CollisionManager &p_collisionManager, ShurikenManager &p_shurikenManager, SmokeBombManager &p_smokebomb, SpikeManager &p_spikeTrap, FanBoomerangManager &p_fanBoomerang, ProjectileManager &p_projectileManager, StickyTrapManager &p_stickyTrapManager, VolleyManager &p_volleyManager)
{
	float smokeBombDistance = p_smokebomb.GetCurrentDistanceFromPlayer();
	float spikeTrapDistance = p_spikeTrap.GetCurrentDistanceFromPlayer();
	float stickyTrapDistance = p_stickyTrapManager.GetCurrentDistanceFromPlayer();
	float volleyDistance = p_volleyManager.GetCurrentDistanceFromPlayer();
	PlayerNet player;

	int index = GetPlayerIndex(p_guid);
	RakNet::BitStream l_bitStream;

	switch (p_readAbility)
	{
		case ABILITIES_SHURIKEN:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_shurikenManager.AddShuriken(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ);
			break;
		}

		case ABILITIES_DASH:
		{
			//Calculate new location for the dashing player and inflict damage on enemies
			player = GetPlayer(p_guid);
			SendPlaySound(PLAYSOUND::PLAYSOUND_DASH_STEPS_SOUND, player.x, player.y, player.z);
			float dashDistance = p_collisionManager.CalculateDashRange(p_guid, player, this) - 1.0f;

			l_bitStream.Write((RakNet::MessageID)ID_DASH_TO_LOCATION);
			l_bitStream.Write(player.x + dashDistance * player.dirX);
			l_bitStream.Write(player.y);
			l_bitStream.Write(player.z + dashDistance * player.dirZ);
			m_serverPeer->Send(&l_bitStream, HIGH_PRIORITY, RELIABLE, 3, p_guid, false);
			break;
		}

		case ABILITIES_MELEESWING:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_AIR_CUT_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_collisionManager.NormalMeleeAttack(p_guid, this, p_readAbility);
			break;
		}

		case ABILITIES_MEGASHURIKEN:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_shurikenManager.AddMegaShuriken(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ, p_deltaTime);
			break;
		}

		case ABILITIES_SMOKEBOMB:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			if (smokeBombDistance > SMOKEBOMB_RANGE)
			{
				smokeBombDistance = SMOKEBOMB_RANGE;
			}
			SendPlaySound(PLAYSOUND::PLAYSOUND_SMOKE_BOMB_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_smokebomb.AddSmokeBomb(m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* smokeBombDistance, m_players[index].z + m_players[index].dirZ * smokeBombDistance);
			break;
		}

		case ABILITIES_SPIKETRAP:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			if (spikeTrapDistance > SPIKE_RANGE)
			{
				spikeTrapDistance = SPIKE_RANGE;
			}

			p_spikeTrap.AddSpikeTrap(p_guid, m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* spikeTrapDistance, m_players[index].z + m_players[index].dirZ * spikeTrapDistance, m_players[index].team);
			break;
		}

		case ABILITIES_WHIP_PRIMARY:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_WHIP_AIR_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_collisionManager.WhipPrimaryAttack(p_guid, this);
			break;
		}

		case ABILITIES_WHIP_SECONDARY:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_WHIP_ROTATE_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_collisionManager.WhipSecondaryAttack(p_guid, this);
			break;
		}

		case ABILITIES_FANBOOMERANG:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_fanBoomerang.Add(p_deltaTime, p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ);
			break;
		}

		case ABILITIES_NAGINATASLASH:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_NAGINATA_AIR_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_collisionManager.NormalMeleeAttack(p_guid, this, p_readAbility);
			break;
		}

		case ABILITIES_KUNAI:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_KUNAI_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_projectileManager.AddProjectile(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ, 2);
			break;
		}

		case ABILITIES_STICKY_TRAP:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			if (stickyTrapDistance > STICKY_TRAP_RANGE)
			{
				stickyTrapDistance = STICKY_TRAP_RANGE;
			}

			SendPlaySound(PLAYSOUND::PLAYSOUND_BUBLE_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_stickyTrapManager.AddStickyTrap(p_guid, m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* stickyTrapDistance, m_players[index].z + m_players[index].dirZ * stickyTrapDistance);
			break;
		}

		case ABILITIES_NAGAINATASTAB:
		{
			SendPlaySound(PLAYSOUND::PLAYSOUND_NAGINATA_STAB_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_collisionManager.NaginataStabAttack(p_guid, this);
			break;
		}

		case ABILITIES_VOLLEY:
		{
			if (volleyDistance > VOLLEY_RANGE)
			{
				volleyDistance = VOLLEY_RANGE;
			}

			SendPlaySound(PLAYSOUND::PLAYSOUND_VOLLEY_THROW_SOUND, m_players[index].x, m_players[index].y, m_players[index].z);
			p_volleyManager.Add(p_guid, m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX * volleyDistance, m_players[index].z + m_players[index].dirZ * volleyDistance);
			break;
		}

		default:
		{
			break;
		}
	}

	RakNet::BitStream bitStream;
	bitStream.Write((RakNet::MessageID)ID_ABILITY);
	bitStream.Write(p_readAbility);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, UNRELIABLE, 3, p_guid, false);
}

int PlayerManager::GetPlayerIndex(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			return i;
		}
	}

	return -1;
}

void PlayerManager::DamagePlayer(RakNet::RakNetGUID p_defendingGuid, float p_damage, RakNet::RakNetGUID p_attackingGuid, ABILITIES p_usedAbility, bool p_suddenDeathDamage)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_defendingGuid)
		{
			// STop healing POI, and send message to stop effect.
			m_players[i].hotHeal = 0.0f;
			if (m_players[i].hasHealPOI)
			{
				m_players[i].hasHealPOI = false;
				SendHasPOIHealing(m_players[i].guid);
			}

			if (m_players[i].shield > 0.0f)
			{
				// Shield active
				// Play Shield sound, now it will play hurt sound
				m_players[i].shield = 0.0f;
			}

			else
			{
				m_players[i].currentHP -= p_damage;

				if (m_players[i].currentHP <= 0)
				{
					m_players[i].isAlive = false;

					if (m_players[i].charNr == 1)
					{
						SendPlaySound(PLAYSOUND_FEMALE_DEATH_SOUND, m_players[i].x, m_players[i].y, m_players[i].z);
					}

					else
					{
						SendPlaySound(PLAYSOUND_MALE_DEATH_SOUND, m_players[i].x, m_players[i].y, m_players[i].z);
					}

					// Loop throu players to get ninja nr
					for (unsigned int j = 0; j < m_players.size(); j++)
					{
						if (m_players[j].guid == p_attackingGuid)
						{
							// Send to deathboard
							DeathBoard(m_players[i].guid, m_players[j].guid, p_usedAbility);

							// Send to scoreboard
							ScoreBoard(m_players[i].guid, m_players[j].guid);

							break;
						}
					}
				}

				UpdateHealth(p_defendingGuid, m_players[i].currentHP, m_players[i].isAlive);
			}

			if (!p_suddenDeathDamage)
			{
				SendDealtDamage(p_attackingGuid, p_damage, m_players[i].x, m_players[i].y, m_players[i].z);
			}

			SendPlaySound(p_usedAbility, m_players[i].x, m_players[i].y, m_players[i].z);

			if (m_players[i].charNr == 1)
			{
				SendPlaySound(PLAYSOUND_FEMALE_HURT_SOUND, m_players[i].x, m_players[i].y, m_players[i].z);
			}

			else
			{
				SendPlaySound(PLAYSOUND_MALE_HURT_SOUND, m_players[i].x, m_players[i].y, m_players[i].z);
			}
		}
	}
}

void PlayerManager::HealPlayer()
{
	if (m_canSendHotDamage)
	{
		for (unsigned int i = 0; i < m_players.size(); i++)
		{
			if (m_players[i].hotHeal > 0.0)
			{
				m_players[i].currentHP += m_players[i].hotHeal;

				if (m_players[i].currentHP > m_players[i].maxHP)
				{
					m_players[i].currentHP = m_players[i].maxHP;
					m_players[i].hotHeal = 0.0;
					m_players[i].hasHealPOI = false;

					SendHasPOIHealing(m_players[i].guid);
				}

				UpdateHealth(m_players[i].guid, m_players[i].currentHP, m_players[i].isAlive);
				m_haveSentHotDamage = true;
			}
		}
	}
}

void PlayerManager::UpdateHealth(RakNet::RakNetGUID p_guid, float p_health, bool p_isAlive)
{
	UpdateHealth(p_guid, p_health, p_isAlive, p_health <= 0);
}

void PlayerManager::UpdateHealth(RakNet::RakNetGUID p_guid, float p_health, bool p_isAlive, bool p_sendReliable)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_HP_CHANGED);
	bitStream.Write(p_guid);
	bitStream.Write(p_health);
	bitStream.Write(p_isAlive);

	PacketReliability reliability = UNRELIABLE_SEQUENCED;
	// Need reliable on dead players and when they get full health
	if (p_sendReliable)
	{
		reliability = RELIABLE;
	}
	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, reliability, 2, RakNet::UNASSIGNED_RAKNET_GUID, true);

}

void PlayerManager::DeathBoard(RakNet::RakNetGUID p_TakerNinja, RakNet::RakNetGUID p_AttackerNinja, ABILITIES p_usedAbility)
{
	RakNet::BitStream bitStream;
	bitStream.Write((RakNet::MessageID)ID_DEATHBOARDKILL);
	bitStream.Write(p_TakerNinja);
	bitStream.Write(p_AttackerNinja);
	bitStream.Write(p_usedAbility);
	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PlayerManager::ScoreBoard(RakNet::RakNetGUID p_deadID, RakNet::RakNetGUID p_killerID)
{
	RakNet::BitStream bitStream;
	int kills, deaths = 0;

	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_killerID)
		{
			if (p_killerID != p_deadID)
			{
				m_players[i].kills += 1;
			}
			kills = m_players[i].kills;
		}
		if (m_players[i].guid == p_deadID)
		{
			m_players[i].deaths += 1;
			deaths = m_players[i].deaths;
		}
	}
	bitStream.Write((RakNet::MessageID)ID_SCOREBOARDKILL);
	bitStream.Write(p_deadID);
	bitStream.Write(p_killerID);
	bitStream.Write(deaths);
	bitStream.Write(kills);
	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

float PlayerManager::GetPlayerHealth(RakNet::RakNetGUID p_guid)
{
	return GetPlayer(p_guid).currentHP;
}

void PlayerManager::ResetHealth(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (p_guid == m_players[i].guid)
		{
			m_players[i].currentHP = m_players[i].maxHP;
			m_players[i].isAlive = true;
			UpdateHealth(p_guid, m_players[i].currentHP, m_players[i].isAlive, true);
		}
	}
}
void PlayerManager::NaginataStabAttackPerformed(RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_NAGINATA_STAB_HAS_OCCURED);
	bitStream.Write(p_guid);
	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 3, p_guid, false);
}

int PlayerManager::GetTeamForPlayer()
{
	int team1 = 0;
	int team2 = 0;
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].team == 1)
		{
			team1++;
		}
		else if (m_players[i].team == 2)
		{
			team2++;
		}
	}

	return team2 >= team1 ? 1 : 2;
}

void PlayerManager::SendPlayerPos()
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		RakNet::BitStream wBitStream;
		wBitStream.Write((RakNet::MessageID)ID_PLAYER_MOVED);
		wBitStream.Write(m_players[i].guid);
		wBitStream.Write(m_players[i].x);
		wBitStream.Write(m_players[i].y);
		wBitStream.Write(m_players[i].z);

		m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, UNRELIABLE_SEQUENCED, 1, RakNet::UNASSIGNED_RAKNET_GUID, true);
	}
}

void PlayerManager::SendPlayerDir()
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		RakNet::BitStream wBitStream;
		wBitStream.Write((RakNet::MessageID)ID_PLAYER_ROTATED);
		wBitStream.Write(m_players[i].guid);
		wBitStream.Write(m_players[i].dirX);
		wBitStream.Write(m_players[i].dirY);
		wBitStream.Write(m_players[i].dirZ);

		m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, UNRELIABLE, 2, RakNet::UNASSIGNED_RAKNET_GUID, true);
	}
}
void PlayerManager::SendDealtDamage(RakNet::RakNetGUID p_attackingPlayerGUID, float p_damage, float p_x, float p_y, float p_z)
{
	RakNet::BitStream bitStream2;
	bitStream2.Write((RakNet::MessageID)ID_HAS_INFLICTED_DAMAGE);
	bitStream2.Write(p_attackingPlayerGUID);
	bitStream2.Write(p_damage);
	bitStream2.Write(p_x);
	bitStream2.Write(p_y);
	bitStream2.Write(p_z);
	m_serverPeer->Send(&bitStream2, HIGH_PRIORITY, UNRELIABLE, 2, p_attackingPlayerGUID, false);
}

void PlayerManager::SendPlaySound(ABILITIES ability, float p_x, float p_y, float p_z)
{
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_PLAY_SOUND_ABILITY);
	wBitStream.Write(ability);
	wBitStream.Write(p_x);
	wBitStream.Write(p_y);
	wBitStream.Write(p_z);

	m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, UNRELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PlayerManager::SendPlaySound(PLAYSOUND sound, float p_x, float p_y, float p_z)
{
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_PLAY_SOUND);
	wBitStream.Write(sound);
	wBitStream.Write(p_x);
	wBitStream.Write(p_y);
	wBitStream.Write(p_z);

	m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, UNRELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PlayerManager::SendPlayAmbientSound(PLAYSOUND sound, float p_x, float p_y, float p_z)
{
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_PLAY_AMBIENT_SOUND);
	wBitStream.Write(sound);
	wBitStream.Write(p_x);
	wBitStream.Write(p_y);
	wBitStream.Write(p_z);

	m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, UNRELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PlayerManager::SendPlayerPosAndDir()
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		int exp;
		float mantissa;
		RakNet::BitStream bitStream;

		bitStream.Write((RakNet::MessageID)ID_PLAYER_MOVE_AND_ROTATE);
		bitStream.Write((unsigned char)m_players[i].id);

		// pos x
		mantissa = frexpf(m_players[i].x, &exp);
		bitStream.Write((signed short)(mantissa * 10000.0f));
		bitStream.Write((signed char)exp);
		
		// pos z
		mantissa = frexpf(m_players[i].z, &exp);
		bitStream.Write((signed short)(mantissa * 10000.0f));
		bitStream.Write((signed char)exp);
		
		// dir x
		mantissa = frexpf(m_players[i].dirX, &exp);
		bitStream.Write((signed char)(mantissa * 100.0f));
		bitStream.Write((signed char)exp);

		// dir z
		mantissa = frexpf(m_players[i].dirZ, &exp);
		bitStream.Write((signed char)(mantissa * 100.0f));
		bitStream.Write((signed char)exp);


		m_serverPeer->Send(&bitStream, HIGH_PRIORITY, UNRELIABLE, 1, RakNet::UNASSIGNED_RAKNET_GUID, true);
	}
}

void PlayerManager::SetPlayerDotDamage(RakNet::RakNetGUID p_guid, float p_damage)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			m_players[i].dotDamage = p_damage;
		}
	}
}

bool PlayerManager::CanSendDotDamage()
{
	m_haveSentDotDamage = true;
	return m_canSendDotDamage;
}

int PlayerManager::GetIdForPlayer()
{
	int id = 0;
	bool idTaken = false;
	do
	{
		idTaken = false;
		for (unsigned int i = 0; i < m_players.size(); i++)
		{
			if (m_players[i].id == id)
			{
				id++;
				idTaken = true;
				break;
			}
		}
	} while (idTaken);

	return id;
}

void PlayerManager::RuneLotusPickedUp(RakNet::RakNetGUID p_player)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_player)
		{
			m_players[i].hotHeal = LOTUS_HEALTICK;
			m_players[i].hasHealPOI = true;

			SendHasPOIHealing(m_players[i].guid);
		}
	}
}

void PlayerManager::RuneInvisPickedUp(RakNet::RakNetGUID p_player)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_player)
		{
			m_players[i].invis = true;
		}
	}
}

void PlayerManager::RuneShieldPickedUp(RakNet::RakNetGUID p_player)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_player)
		{
			m_players[i].shield = 1.0f;
		}
	}
}

void PlayerManager::UpdateVisiblePlayers(RakNet::RakNetGUID p_player, std::vector<int> p_visiblePlayers)
{
	m_playerVisibility[p_player] = p_visiblePlayers;
}

void PlayerManager::SendVisiblePlayers()
{
	std::vector<int> redTeamVision = std::vector<int>();
	std::vector<int> blueTeamVision = std::vector<int>();

	// Update vector with who the team can see
	for (std::map<RakNet::RakNetGUID, std::vector<int>>::iterator it = m_playerVisibility.begin(); it != m_playerVisibility.end(); it++)
	{
		int team = GetTeam(it->first);
		if (team == 1)
		{
			for (unsigned int i = 0; i < it->second.size(); i++)
			{
				bool found = false;
				for (unsigned int j = 0; j < redTeamVision.size(); j++)
				{
					if (redTeamVision[j] == it->second[i])
					{
						found = true;
						break;
					}
				}

				if (!found)
				{
					redTeamVision.push_back(it->second[i]);
				}
			}
}
		else if (team == 2)
		{
			for (unsigned int i = 0; i < it->second.size(); i++)
			{
				bool found = false;
				for (unsigned int j = 0; j < blueTeamVision.size(); j++)
				{
					if (blueTeamVision[j] == it->second[i])
					{
						found = true;
						break;
					}
				}

				if (!found)
				{
					blueTeamVision.push_back(it->second[i]);
				}
			}
		}
	}

	// Send to players
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		RakNet::BitStream bitStream;

		bitStream.Write((RakNet::MessageID)ID_SEND_VISIBLE_PLAYERS);
		
		int team = GetTeam(m_players[i].guid);

		if (team == 1)
		{
			bitStream.Write((unsigned char)redTeamVision.size());
			for (unsigned int j = 0; j < redTeamVision.size(); j++)
			{
				bitStream.Write((unsigned char)redTeamVision[j]);
			}
		}
		else if (team == 2)
		{
			bitStream.Write((unsigned char)blueTeamVision.size());
			for (unsigned int j = 0; j < blueTeamVision.size(); j++)
			{
				bitStream.Write((unsigned char)blueTeamVision[j]);
			}
		}

		m_serverPeer->Send(&bitStream, HIGH_PRIORITY, UNRELIABLE, 1, m_players[i].guid, false);
	}
}

int PlayerManager::GetTeam(RakNet::RakNetGUID p_player)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_player)
		{
			return m_players[i].team;
		}
	}
	return -1;
}

bool PlayerManager::GetInvis(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			if (m_players[i].invis)
			{
				return true;
			}
		}
	}
	return false;
}

void PlayerManager::SendHasPOIHealing(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			RakNet::BitStream stream;
			stream.Write((RakNet::MessageID)ID_POI_HEALING_BOOL);
			stream.Write(m_players[i].guid);
			stream.Write(m_players[i].hasHealPOI);
			m_serverPeer->Send(&stream, MEDIUM_PRIORITY, RELIABLE, 1, RakNet::UNASSIGNED_RAKNET_GUID, true);

			break;
		}
	}
	
}

void PlayerManager::ResetPOIEffects()
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		m_players[i].shield = false;
		m_players[i].invis = false;
		m_players[i].hasHealPOI = false;

		SendHasPOIHealing(m_players[i].guid);
	}
}