#include "PlayerManager.h"
#include "SpikeManager.h"

#include "..\CommonLibs\ModelNames.h"

PlayerManager::PlayerManager(){}
PlayerManager::~PlayerManager(){}

bool PlayerManager::Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName)
{
	m_playerHealth = CHARACTER_KATANA_SHURIKEN_HEALTH;
	m_gcd = ALL_AROUND_GLOBAL_COOLDOWN;

	m_serverPeer = p_serverPeer;

	m_players = std::vector<PlayerNet>();
	m_spawnPoints = std::vector<LevelImporter::SpawnPoint>();

	// Load spawnpoints
	Level level(p_levelName);
	m_spawnPoints = level.GetSpawnPoints();

	// Todo: move to player
	m_katanaBoundingBoxes = ModelLibrary::GetInstance()->GetModel(KATANA_NINJA_MODEL_NAME)->GetBoundingBoxes();
	m_tessenBoundingBoxes = ModelLibrary::GetInstance()->GetModel(TESSEN_NINJA_MODEL_NAME)->GetBoundingBoxes();

	return true;
}

void PlayerManager::Shutdown(){}

void PlayerManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].gcd > 0.0f)
		{
			m_players[i].gcd -= (float)p_deltaTime;
		}
		if (m_players[i].cooldownAbilites.shurikenCD > 0.0f)
		{
			m_players[i].cooldownAbilites.shurikenCD -= (float)p_deltaTime;
		}
		if (m_players[i].cooldownAbilites.dashCD > 0.0f)
		{
			m_players[i].cooldownAbilites.dashCD -= (float)p_deltaTime;
		}
		if (m_players[i].cooldownAbilites.meleeSwingCD > 0.0f)
		{
			m_players[i].cooldownAbilites.meleeSwingCD -= (float)p_deltaTime;
		}
	}
}

std::vector<PlayerNet> PlayerManager::GetPlayers()
{
	return m_players;
}

void PlayerManager::AddPlayer(RakNet::RakNetGUID p_guid, int p_charNr)
{
	PlayerNet player;
	player.guid = p_guid;
	player.team = (m_players.size() % 2) + 1;
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
	m_players.push_back(player);

	std::cout << "Player added" << std::endl;

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
			i--;
			std::cout << "Player removed" << std::endl;
			BroadcastPlayers();
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

			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);
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

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);
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
	}

	for (unsigned int i = 0; i < tmpBB.size(); i++)
	{
		Box box = tmpBB[i];
		box.m_center.x += m_players[p_index].x;
		box.m_center.y += m_players[p_index].y;
		box.m_center.z += m_players[p_index].z;

		boundingBoxes.push_back(box);
	}

	// Temp code to create a box around the player
	Box playerBox = Box(0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 1.0f);
	playerBox.m_center.x += m_players[p_index].x;
	playerBox.m_center.y += m_players[p_index].y;
	playerBox.m_center.z += m_players[p_index].z;
	boundingBoxes.push_back(playerBox);

	return boundingBoxes;
}

void PlayerManager::UsedAbility(int p_index, ABILITIES p_ability)
{
	if (p_index >= 0 && p_index < (int)m_players.size())
	{
		m_players[p_index].gcd = m_gcd;
		switch (p_ability)
		{
		case ABILITIES_SHURIKEN:
			m_players[p_index].cooldownAbilites.shurikenCD = ALL_AROUND_GLOBAL_COOLDOWN;
			break;
		case ABILITIES_DASH:
			m_players[p_index].cooldownAbilites.dashCD = DASH_COOLDOWN;
			break;
		case ABILITIES_MELEESWING:
			m_players[p_index].cooldownAbilites.meleeSwingCD = ALL_AROUND_GLOBAL_COOLDOWN;
			break;
		case ABILITIES_MEGASHURIKEN:
			m_players[p_index].cooldownAbilites.megaShurikenCD = MEGASHURIKEN_COOLDOWN;
			break;
		case ABILITIES_WHIP_PRIMARY:
			m_players[p_index].cooldownAbilites.whipAttack = WHIP_COOLDOWN;
			break;
		case ABILITIES_WHIP_SECONDARY:
			m_players[p_index].cooldownAbilites.megaShurikenCD = WHIP_SP_COOLDOWN;
			break;
		default:
			break;
		}

	}
}

bool PlayerManager::CanUseAbility(int p_index, ABILITIES p_ability)
{
	bool result = false;

	if (p_index >= 0 && p_index < (int)m_players.size())
	{
		if (m_players[p_index].gcd <= 0.0f)
		{
			switch (p_ability)
			{
			case ABILITIES_SHURIKEN:
				result = true; // controlled locally atm
				break;
			case ABILITIES_DASH:
				result = true; // controlled locally atm
				break;
			case ABILITIES_MELEESWING:
				result = true; // controlled locally atm
				break;
			case ABILITIES_MEGASHURIKEN:
				result = true; // controlled locally atmresult = false;
				break;
			case ABILITIES_SMOKEBOMB:
				result = true;
				break;
			case ABILITIES_SPIKETRAP:
				result = true;
				break;
			case ABILITIES_WHIP_PRIMARY:
				result = true;
				break;
			case ABILITIES_WHIP_SECONDARY:
				result = true;
				break;
			default:
				result = false;
				break;
			}
		}
	}

	return result;
}

void PlayerManager::ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_readAbility, CollisionManager &p_collisionManager, ShurikenManager &p_shurikenManager, int p_nrOfConnections, SmokeBombManager &p_smokebomb, SpikeManager &p_spikeTrap)
{
	float smokeBombDistance = p_smokebomb.GetCurrentDistanceFromPlayer();
	float spikeTrapDistance = p_spikeTrap.GetCurrentDistanceFromPlayer();
	float dashDistance = 10.0f;
	PlayerNet player;
	RakNet::RakString abilityString = "Hej";
	int index = GetPlayerIndex(p_guid);
	RakNet::BitStream l_bitStream;
	switch (p_readAbility)
	{
	case ABILITIES_SHURIKEN:
		abilityString = "Shuriken";
		p_shurikenManager.AddShuriken(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ);
		break;
	case ABILITIES_DASH:
		abilityString = "Dash";
		//Calculate new location for the dashing player and inflict damage on enemies
		player = GetPlayer(p_guid);
		dashDistance = p_collisionManager.CalculateDashRange(player, this) - 1.0f;

		
		l_bitStream.Write((RakNet::MessageID)ID_DASH_TO_LOCATION);
		l_bitStream.Write(player.x + dashDistance * player.dirX);
		l_bitStream.Write(player.y);
		l_bitStream.Write(player.z + dashDistance * player.dirZ);
		m_serverPeer->Send(&l_bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);

		//MovePlayer(p_guid, player.x + dashDistance*player.dirX, player.y, player.z + dashDistance*player.dirZ, p_nrOfConnections, true);
		break;
	case ABILITIES_MELEESWING:
		abilityString = "MeleeSwinged";
		p_collisionManager.NormalMeleeAttack(p_guid, this);
		break;
	case ABILITIES_MEGASHURIKEN:
		abilityString = "MegaShuriken";
		p_shurikenManager.AddMegaShuriken(p_guid, m_players[index].x, m_players[index].y + 2.0f, m_players[index].z, m_players[index].dirX, m_players[index].dirY, m_players[index].dirZ);
		break;
	case ABILITIES_SMOKEBOMB:
		abilityString = "SmokeBooooooooomb";
		if (smokeBombDistance > SMOKEBOMB_RANGE)
		{
			smokeBombDistance = SMOKEBOMB_RANGE;
		}
		p_smokebomb.AddSmokeBomb(m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* smokeBombDistance, m_players[index].z + m_players[index].dirZ * smokeBombDistance);
		break;
	case ABILITIES_SPIKETRAP:
		abilityString = "spike tarp";
		if (spikeTrapDistance > SPIKE_RANGE)
		{
			spikeTrapDistance = SPIKE_RANGE;
		}
		p_spikeTrap.AddSpikeTrap(p_guid, m_players[index].x, m_players[index].z, m_players[index].x + m_players[index].dirX* spikeTrapDistance, m_players[index].z + m_players[index].dirZ * spikeTrapDistance);

		break;
	case ABILITIES_WHIP_PRIMARY:
		abilityString = "whipping the shit out of fuck";
		p_collisionManager.WhipPrimaryAttack(p_guid, this);
		break;
	case ABILITIES_WHIP_SECONDARY:
		abilityString = "not whipping enough!";
		p_collisionManager.WhipSecondaryAttack(p_guid, this);
		break;
	default:
		break;
	}

	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_ABILITY);
	bitStream.Write(p_readAbility);
	bitStream.Write(abilityString);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);
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

void PlayerManager::DamagePlayer(RakNet::RakNetGUID p_guid, float p_damage)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			m_players[i].currentHP -= p_damage;
			if (m_players[i].currentHP <= 0)
			{
				m_players[i].isAlive = false;
			}
			UpdateHealth(p_guid, m_players[i].currentHP, m_players[i].isAlive);
		}
	}
}

void PlayerManager::UpdateHealth(RakNet::RakNetGUID p_guid, float p_health, bool p_isAlive)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_HP_CHANGED);
	bitStream.Write(p_guid);
	bitStream.Write(p_health);
	bitStream.Write(p_isAlive);
	

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
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
			UpdateHealth(p_guid, m_players[i].currentHP, m_players[i].isAlive);
		}
	}
}