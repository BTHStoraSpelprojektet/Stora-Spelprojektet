#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}

PlayerManager::~PlayerManager()
{
}

bool PlayerManager::Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName)
{
	m_playerHealth = 100;
	m_gcd = 0.5f;
	m_serverPeer = p_serverPeer;

	m_players = std::vector<PlayerNet>();
	m_spawnPoints = std::vector<LevelImporter::SpawnPoint>();

	// Load spawnpoints
	Level level(p_levelName);
	m_spawnPoints = level.GetSpawnPoints();

	m_boundingBoxes = ModelLibrary::GetInstance()->GetModel(PLAYER_MODEL_NAME)->GetBoundingBoxes();

	return true;
}

void PlayerManager::Shutdown()
{
}

void PlayerManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].gcd > 0.0f)
		{
			m_players[i].gcd -= (float)p_deltaTime;
		}
	}
}

std::vector<PlayerNet> PlayerManager::GetPlayers()
{
	return m_players;
}

void PlayerManager::AddPlayer(RakNet::RakNetGUID p_guid, int p_nrOfConnections)
{
	PlayerNet player;
	player.guid = p_guid;
	player.team = (p_nrOfConnections % 2) + 1;
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
	m_players.push_back(player);

	std::cout << "Player added" << std::endl;

	// Broadcast new player
	BroadcastPlayers();
}

void PlayerManager::MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections)
{
	bool found = false;

	// See if player can move to target position and then update position
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			if (abs(p_x - m_players[i].x) > 1.0f || abs(p_y - m_players[i].y) > 1.0f || abs(p_z - m_players[i].z) > 1.0f)
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

			found = true;
			break;
		}
	}

	// Add player if he doesn't exist in the vector
	if (!found)
	{
		AddPlayer(p_guid, p_nrOfConnections);
	}
}

void PlayerManager::RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			m_players[i].dirX = p_dirX;
			m_players[i].dirY = p_dirY;
			m_players[i].dirZ = p_dirZ;
			break;
		}
	}
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
		bitStream.Write(m_players[i].maxHP);
		bitStream.Write(m_players[i].currentHP);
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

	for (unsigned int i = 0; i < m_boundingBoxes.size(); i++)
	{
		Box box = m_boundingBoxes[i];
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
			break;
		case ABILITIES_DASH:
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
			result = true;
			switch (p_ability)
			{
			case ABILITIES_SHURIKEN:
				if (true)
				{

				}// IF PLAYER SHURIKEn cd is 0 do ability)
				break;
			case ABILITIES_DASH:
				break;
			default:
				break;
			}
		}
	}

	return result;
}

void PlayerManager::ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_readAbility)
{
	RakNet::RakString abilityString = "Hej";
	switch (p_readAbility)
	{
	case ABILITIES_SHURIKEN:
		abilityString = "HEJSAN EN SHURIKEN ÄR KASTAD! d:";
		break;
	case ABILITIES_DASH:
		abilityString = "HEJSAN NU BLEV DET EN DASH! :p";
		break;
	default:
		break;
	}


	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_ABILITY);
	bitStream.Write(p_readAbility);
	bitStream.Write(abilityString);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
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

void PlayerManager::DamagePlayer(RakNet::RakNetGUID p_guid, int p_damage)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			m_players[i].currentHP -= p_damage;
			UpdateHealth(p_guid, m_players[i].currentHP);
		}
	}
}

void PlayerManager::UpdateHealth(RakNet::RakNetGUID p_guid, int p_health)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_HP_CHANGED);
	bitStream.Write(p_guid);
	bitStream.Write(p_health);
	

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

int PlayerManager::GetPlayerHealth(RakNet::RakNetGUID p_guid)
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
			UpdateHealth(p_guid, m_players[i].currentHP);
		}
	}
}