#include "PlayerManager.h"
#include "SpikeManager.h"
#include "FanBoomerangManager.h"
#include "ProjectileManager.h"
#include "StickyTrapManager.h"
#include "VolleyManager.h"
#include "..\Shurikenjutsu\ConsoleFunctions.h"

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

	m_sendIntervall = 0.03;
	m_lastTimeSent = 0.0;

	m_dotIntervall = 0.1;
	m_lastDotSent = 0.0;
	m_canSendDotDamage = true;
	m_haveSentDotDamage = false;

	return true;
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
}

std::vector<PlayerNet> PlayerManager::GetPlayers()
{
	return m_players;
}

void PlayerManager::AddPlayer(RakNet::RakNetGUID p_guid, int p_charNr, int p_toolNr)
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
	player.team = GetTeamForPlayer();
	player.charNr = p_charNr;
	LevelImporter::SpawnPoint spawnPoint = GetSpawnPoint(player.team);
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
	player.dotDamage = 0.0f;
	player.toolNr = p_toolNr;
	m_players.push_back(player);
	
	ConsolePrintText("New player joined.");

	// Broadcast new player
	BroadcastPlayers();
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
		bitStream.Write(m_players[i].toolNr);
	}

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PlayerManager::RespawnPlayer(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			LevelImporter::SpawnPoint spawnPoint = GetSpawnPoint(m_players[i].team);
			m_players[i].x = spawnPoint.m_translationX;
			m_players[i].y = spawnPoint.m_translationY;
			m_players[i].z = spawnPoint.m_translationZ;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_RESPAWN_PLAYER);
			bitStream.Write(m_players[i].x);
			bitStream.Write(m_players[i].y);
			bitStream.Write(m_players[i].z);

			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 2, p_guid, false);
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

LevelImporter::SpawnPoint PlayerManager::GetSpawnPoint(int p_team)
{
	for (unsigned int i = 0; i < m_spawnPoints.size(); i++)
	{
		if (m_spawnPoints[i].m_team == p_team)
		{
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

void PlayerManager::ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_readAbility, CollisionManager &p_collisionManager, ShurikenManager &p_shurikenManager, SmokeBombManager &p_smokebomb, SpikeManager &p_spikeTrap, FanBoomerangManager &p_fanBoomerang, ProjectileManager &p_projectileManager, StickyTrapManager &p_stickyTrapManager, VolleyManager &p_volleyManager)
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
			p_shurikenManager.AddShuriken(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ);
			break;
		}

		case ABILITIES_DASH:
		{
			//Calculate new location for the dashing player and inflict damage on enemies
			player = GetPlayer(p_guid);
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
			p_collisionManager.NormalMeleeAttack(p_guid, this, p_readAbility);
			break;
		}

		case ABILITIES_MEGASHURIKEN:
		{
			p_shurikenManager.AddMegaShuriken(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ);
			break;
		}

		case ABILITIES_SMOKEBOMB:
		{
			if (smokeBombDistance > SMOKEBOMB_RANGE)
			{
				smokeBombDistance = SMOKEBOMB_RANGE;
			}

			p_smokebomb.AddSmokeBomb(m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* smokeBombDistance, m_players[index].z + m_players[index].dirZ * smokeBombDistance);
			break;
		}

		case ABILITIES_SPIKETRAP:
		{
			if (spikeTrapDistance > SPIKE_RANGE)
			{
				spikeTrapDistance = SPIKE_RANGE;
			}

			p_spikeTrap.AddSpikeTrap(p_guid, m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* spikeTrapDistance, m_players[index].z + m_players[index].dirZ * spikeTrapDistance, m_players[index].team);
			break;
		}

		case ABILITIES_WHIP_PRIMARY:
		{
			p_collisionManager.WhipPrimaryAttack(p_guid, this);
			break;
		}

		case ABILITIES_WHIP_SECONDARY:
		{
			p_collisionManager.WhipSecondaryAttack(p_guid, this);
			break;
		}

		case ABILITIES_FANBOOMERANG:
		{
			p_fanBoomerang.Add(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ);
			break;
		}

		case ABILITIES_NAGINATASLASH:
		{
			p_collisionManager.NormalMeleeAttack(p_guid, this, p_readAbility);
			break;
		}

		case ABILITIES_KUNAI:
		{
			p_projectileManager.AddProjectile(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ, 2);
			break;
		}

		case ABILITIES_STICKY_TRAP:
		{
			if (stickyTrapDistance > STICKY_TRAP_RANGE)
			{
				stickyTrapDistance = STICKY_TRAP_RANGE;
			}

			p_stickyTrapManager.AddStickyTrap(p_guid, m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* stickyTrapDistance, m_players[index].z + m_players[index].dirZ * stickyTrapDistance);
			break;
		}

		case ABILITIES_NAGAINATASTAB:
		{
			p_collisionManager.NaginataStabAttack(p_guid, this);
			break;
		}

		case ABILITIES_VOLLEY:
		{
			if (volleyDistance > VOLLEY_RANGE)
			{
				volleyDistance = VOLLEY_RANGE;
			}

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

void PlayerManager::DamagePlayer(RakNet::RakNetGUID p_defendingGuid, float p_damage, RakNet::RakNetGUID p_attackingGuid, ABILITIES p_usedAbility)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_defendingGuid)
		{
			m_players[i].currentHP -= p_damage;
			if (m_players[i].currentHP <= 0)
			{
				m_players[i].isAlive = false;
				
				// Loop throu players to get ninja nr
				for (unsigned int j = 0; j < m_players.size(); j++)
				{
					if (m_players[j].guid == p_attackingGuid)
					{
						// Send to deathboard
						DeathBoard(m_players[i].charNr, m_players[j].charNr, p_usedAbility);
						break;
					}
				}
			}
			UpdateHealth(p_defendingGuid, m_players[i].currentHP, m_players[i].isAlive);
			SendDealtDamage(p_attackingGuid, p_damage, m_players[i].x, m_players[i].y, m_players[i].z);
			SendPlaySound(p_usedAbility);
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

void PlayerManager::DeathBoard(int p_TakerNinja, int p_AttackerNinja, ABILITIES p_usedAbility)
{
	RakNet::BitStream bitStream;
	bitStream.Write((RakNet::MessageID)ID_DEATHBOARDKILL);
	bitStream.Write(p_TakerNinja);
	bitStream.Write(p_AttackerNinja);
	bitStream.Write(p_usedAbility);
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

void PlayerManager::SendPlaySound(ABILITIES ability)
{
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_PLAY_SOUND);
	wBitStream.Write(ability);

	m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, UNRELIABLE, 2, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PlayerManager::SendPlayerPosAndDir()
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		int exp;
		float mantissa;
		RakNet::BitStream bitStream;

		bitStream.Write((RakNet::MessageID)ID_PLAYER_MOVE_AND_ROTATE);
		bitStream.Write(m_players[i].guid.g);

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