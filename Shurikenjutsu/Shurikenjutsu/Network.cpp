#include "Network.h"

Network* Network::m_instance;

Network::Network(){}
Network::~Network(){}

Network* Network::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Network();
	}

	return m_instance;
}

bool Network::Initialize()
{
	ServerGlobals::IS_SERVER = false;
	m_connected = false;
	m_prevConnected = false;
	m_newOrRemovedPlayers = false;
	m_shurikenListUpdated = false;
	m_respawned = false;
	m_invalidMove = false;

	m_clientPeer = RakNet::RakPeerInterface::GetInstance();
	
	m_clientPeer->Startup(1, &m_socketDesc, 1);
	m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);

	m_enemyPlayers = std::vector<PlayerNet>();
	m_shurikensList = std::vector<ShurikenNet>();

	m_connectionCount = 0;
	m_previousCount = 0;

	return true;
}

void Network::Shutdown()
{
	m_clientPeer->Shutdown(300);
	RakNet::RakPeerInterface::DestroyInstance(m_clientPeer);

	delete m_instance;
}

void Network::Update()
{
	m_prevConnected = m_connected;
	ReceviePacket();
}

void Network::ReceviePacket()
{
	unsigned char messageID;
	for (m_packet = m_clientPeer->Receive(); m_packet; m_clientPeer->DeallocatePacket(m_packet), m_packet = m_clientPeer->Receive())
	{
		switch (m_packet->data[0])
		{
		case ID_CONNECTION_REQUEST_ACCEPTED:
		{
			ConsolePrintSuccess("Connected to the server.");
			ConsoleSkipLines(1);

			m_connected = true;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_DOWNLOAD_PLAYERS);

			m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_packet->guid, false);

			break;
		}
		case ID_CONNECTION_ATTEMPT_FAILED:
		{
			ConsolePrintError("Connection to server failed, trying to reconnect.");

			m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);
			break;
		}
		case ID_DISCONNECTION_NOTIFICATION:
		{
			ConsolePrintError("Server shut down.");
			ConsoleSkipLines(1);

			break;
		}
		case ID_CONNECTION_LOST:
		{
			ConsolePrintError("Lost connection to server.");
			ConsoleSkipLines(1);

			break;
		}
		case ID_NR_CONNECTIONS:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);
			bitStream.Read(m_connectionCount);

			if (m_connectionCount < m_previousCount)
			{
				ConsolePrintError("Client disconnected.");
			}
			else
			{
				ConsolePrintSuccess("New client connected.");
			}

			ConsolePrintText("Players connected: " + std::to_string(m_connectionCount));
			ConsoleSkipLines(1);

			m_previousCount = m_connectionCount;

			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int nrOfPlayers = 0;
			float x, y, z;
			float dirX, dirY, dirZ;
			int team;
			int maxHP, currentHP;
			RakNet::RakNetGUID guid;
			std::vector<RakNet::RakNetGUID> playerGuids = std::vector<RakNet::RakNetGUID>();
			bitStream.Read(messageID);
			bitStream.Read(nrOfPlayers);

			for (int i = 0; i < nrOfPlayers; i++)
			{
				bitStream.Read(guid);
				bitStream.Read(x);
				bitStream.Read(y);
				bitStream.Read(z);
				bitStream.Read(dirX);
				bitStream.Read(dirY);
				bitStream.Read(dirZ);
				bitStream.Read(team);
				bitStream.Read(maxHP);
				bitStream.Read(currentHP);

				// (Add and) update players position
				UpdatePlayerPos(guid, x, y, z);
				UpdatePlayerDir(guid, dirX, dirY, dirZ);
				UpdatePlayerHP(guid, maxHP, currentHP);

				playerGuids.push_back(guid);				
			}

			// Check for removed players
			CheckForRemovedPlayers(playerGuids);

			m_newOrRemovedPlayers = true;

			break;
		}

		case ID_PLAYER_MOVED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float x, y, z;

			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			UpdatePlayerPos(guid, x, y, z);
			break;
		}
		case ID_PLAYER_ROTATED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float dirX, dirY, dirZ;

			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);

			UpdatePlayerDir(guid, dirX, dirY, dirZ);
			break;
		}
		case ID_SHURIKEN_THROWN:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float x, y, z;
			float dirX, dirY, dirZ;
			unsigned int shurikenID;
			float speed;

			bitStream.Read(messageID);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);
			bitStream.Read(shurikenID);
			bitStream.Read(guid);
			bitStream.Read(speed);

			UpdateShurikens(x, y, z, dirX, dirY, dirZ, shurikenID, guid, speed);
			break;
		}
		case ID_SHURIKEN_REMOVE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int shurikenId;
			bitStream.Read(messageID);
			bitStream.Read(shurikenId);

			RemoveShuriken(shurikenId);

			break;
		}
		case ID_RESPAWN_PLAYER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			float x, y, z;
			bitStream.Read(messageID);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			RespawnPlayer(x, y, z);

			break;
		}
		case ID_PLAYER_INVALID_MOVE:
		{
			m_invalidMove = true;
			break;
		}
		case ID_PLAYER_HP_CHANGED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			int currentHP;

			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(currentHP);

			UpdatePlayerHP(guid, currentHP);

			break;
		}
		case ID_ABILITY:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			ABILITIES abilityEnum;
			RakNet::RakString abilityString;
			bitStream.Read(messageID);
			bitStream.Read(abilityEnum);
			bitStream.Read(abilityString);
			if (abilityEnum == ABILITIES_DASH)
			{
				m_invalidMove = true;
			}

			std::cout << " " << abilityString << std::endl;

			break;
		}
		default:
		{
			break;
		}
		}
	}
}

bool Network::IsConnected()
{
	return m_connected;
}

bool Network::ConnectedNow()
{
	return (!m_prevConnected && m_connected);
}

void Network::SendPlayerPos(float p_x, float p_y, float p_z)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_MOVED);
	bitStream.Write(p_x);
	bitStream.Write(p_y);
	bitStream.Write(p_z);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(SERVER_ADDRESS, SERVER_PORT), false);
}

void Network::SendPlayerDir(float p_dirX, float p_dirY, float p_dirZ)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_ROTATED);
	bitStream.Write(p_dirX);
	bitStream.Write(p_dirY);
	bitStream.Write(p_dirZ);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(SERVER_ADDRESS, SERVER_PORT), false);
}

void Network::UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.guid = p_owner;
		m_myPlayer.x = p_x;
		m_myPlayer.y = p_y;
		m_myPlayer.z = p_z;
	}
	else
	{
		bool found = false;
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].x = p_x;
				m_enemyPlayers[i].y = p_y;
				m_enemyPlayers[i].z = p_z;

				found = true;
				break;
			}
		}

		if (!found)
		{
			PlayerNet player;
			player.guid = p_owner;
			player.x = p_x;
			player.y = p_y;
			player.z = p_z;
			player.dirX = 1.0f;
			player.dirY = 0.0f;
			player.dirZ = 0.0f;

			m_enemyPlayers.push_back(player);
		}
	}
	
}

void Network::UpdatePlayerDir(RakNet::RakNetGUID p_owner, float p_dirX, float p_dirY, float p_dirZ)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.dirX = p_dirX;
		m_myPlayer.dirY = p_dirY;
		m_myPlayer.dirZ = p_dirZ;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].dirX = p_dirX;
				m_enemyPlayers[i].dirY = p_dirY;
				m_enemyPlayers[i].dirZ = p_dirZ;
				break;
			}
		}
	}
}

void Network::UpdatePlayerTeam(RakNet::RakNetGUID p_owner, int p_team)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.team = p_team;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].team = p_team;
			}
		}
	}
}

std::vector<PlayerNet> Network::GetOtherPlayers()
{
	return m_enemyPlayers;
}

PlayerNet Network::GetMyPlayer()
{
	return m_myPlayer;
}

void Network::AddShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ)
{
	RakNet::BitStream bitStream;
	RakNet::RakNetGUID owner = m_clientPeer->GetMyGUID();
	bitStream.Write((RakNet::MessageID)ID_SHURIKEN_THROWN);
	bitStream.Write(p_x);
	bitStream.Write(p_y);
	bitStream.Write(p_z);
	bitStream.Write(p_dirX);
	bitStream.Write(p_dirY);
	bitStream.Write(p_dirZ);
	
	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(SERVER_ADDRESS, SERVER_PORT), false);
}

void Network::UpdateShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid, float p_speed)
{
	bool addShuriken = true;
	ShurikenNet tempShuriken;
	tempShuriken = ShurikenNet();
	tempShuriken.x = p_x;
	tempShuriken.y = p_y;
	tempShuriken.z = p_z;
	tempShuriken.dirX = p_dirX;
	tempShuriken.dirY = p_dirY;
	tempShuriken.dirZ = p_dirZ;
	tempShuriken.shurikenId = p_shurikenID;
	tempShuriken.guid = p_guid;
	tempShuriken.speed = p_speed;

	for (unsigned int i = 0; i < m_shurikensList.size(); i++)
	{
		if (m_shurikensList[i].guid == tempShuriken.guid && m_shurikensList[i].shurikenId == tempShuriken.shurikenId)
		{
			addShuriken = false;
			break;
		}
	}
	if (addShuriken)
	{
		m_shurikensList.push_back(tempShuriken);
		m_shurikenListUpdated = true;
	}
}

std::vector<ShurikenNet> Network::GetShurikens()
{
	return m_shurikensList;
}

RakNet::RakNetGUID Network::GetMyGUID()
{
	return m_clientPeer->GetMyGUID();
}

bool Network::IsPlayerListUpdated()
{
	return m_newOrRemovedPlayers;
}

void Network::SetHaveUpdatedPlayerList()
{
	m_newOrRemovedPlayers = false;
}

void Network::CheckForRemovedPlayers(std::vector<RakNet::RakNetGUID> p_playerGuids)
{
	for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
	{
		if (!(IsGuidInList(p_playerGuids, m_enemyPlayers[i].guid)))
		{
			m_enemyPlayers.erase(m_enemyPlayers.begin() + i);
			i--;
		}
	}
}

bool Network::IsGuidInList(std::vector<RakNet::RakNetGUID> p_playerGuids, RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < p_playerGuids.size(); i++)
	{
		if (p_guid == p_playerGuids[i])
		{
			return true;
		}
	}
	return false;
}

void Network::RemoveShuriken(unsigned int p_shurikenID)
{
	for (unsigned int i = 0; i < m_shurikensList.size(); i++)
	{
		if (m_shurikensList[i].shurikenId == p_shurikenID)
		{
			m_shurikensList.erase(m_shurikensList.begin() + i);
			m_shurikenListUpdated = true;
			break;
		}
	}
}

bool Network::IsShurikenListUpdated()
{
	return m_shurikenListUpdated;
}

void Network::SetHaveUpdateShurikenList()
{
	m_shurikenListUpdated = false;
}

bool Network::HasRespawned()
{
	return m_respawned;
}

void Network::SetHaveRespawned()
{
	m_respawned = false;
}

void Network::RespawnPlayer(float p_x, float p_y, float p_z)
{
	m_myPlayer.x = p_x;
	m_myPlayer.y = p_y;
	m_myPlayer.z = p_z;
	m_respawned = true;
}

void Network::DoMeleeAttack()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_MELEE_ATTACK);
	
	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(SERVER_ADDRESS, SERVER_PORT), false);
}

bool Network::MadeInvalidMove()
{
	return m_invalidMove;
}

void Network::UpdatedMoveFromInvalidMove()
{
	m_invalidMove = false;
}

void Network::UpdatePlayerHP(RakNet::RakNetGUID p_guid, int p_currentHP)
{
	if (p_guid == m_myPlayer.guid)
	{
		m_myPlayer.currentHP = p_currentHP;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (p_guid == m_enemyPlayers[i].guid)
			{
				m_enemyPlayers[i].currentHP = p_currentHP;
			}
		}
	}
}

void Network::UpdatePlayerHP(RakNet::RakNetGUID p_guid, int p_maxHP, int p_currentHP)
{
	if (p_guid == m_myPlayer.guid)
	{
		m_myPlayer.maxHP = p_maxHP;
		m_myPlayer.currentHP = p_currentHP;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (p_guid == m_enemyPlayers[i].guid)
			{
				m_enemyPlayers[i].maxHP = p_maxHP;
				m_enemyPlayers[i].currentHP = p_currentHP;
			}
		}
	}
}

void Network::SendAbility(ABILITIES p_ability)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_ABILITY);
	bitStream.Write(p_ability);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(SERVER_ADDRESS, SERVER_PORT), false);
}