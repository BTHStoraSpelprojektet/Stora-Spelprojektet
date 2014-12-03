#include "Network.h"

RakNet::RakPeerInterface* Network::m_clientPeer;
RakNet::SocketDescriptor Network::m_socketDesc;
RakNet::Packet* Network::m_packet;

bool Network::m_connected;
bool Network::m_prevConnected;
bool Network::m_newOrRemovedPlayers;
bool Network::m_shurikenListUpdated;
bool Network::m_respawned;
int Network::m_connectionCount;
PlayerNet Network::m_myPlayer;
std::vector<PlayerNet> Network::m_enemyPlayers;
std::vector < ShurikenNet > Network::m_shurikensList;

bool Network::Initialize()
{
	ServerGlobals::IS_SERVER = false;
	m_connected = false;
	m_prevConnected = false;
	m_newOrRemovedPlayers = false;
	m_shurikenListUpdated = false;
	m_respawned = false;

	m_clientPeer = RakNet::RakPeerInterface::GetInstance();
	
	m_clientPeer->Startup(1, &m_socketDesc, 1);
	m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);

	m_enemyPlayers = std::vector<PlayerNet>();
	m_shurikensList = std::vector<ShurikenNet>();

	return true;
}

void Network::Shutdown()
{
	m_clientPeer->Shutdown(300);
	RakNet::RakPeerInterface::DestroyInstance(m_clientPeer);
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
			ConsolePrintSuccess("Connected to the server");
			
			m_connected = true;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_DOWNLOAD_PLAYERS);

			m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_packet->guid, false);
			break;
		}
		case ID_CONNECTION_ATTEMPT_FAILED:
		{
			ConsolePrintError("Connection to server failed, trying to reconnect");

			m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);
			break;
		}
		case ID_DISCONNECTION_NOTIFICATION:
		{
			ConsolePrintError("Server has shutdowned");
			break;
		}
		case ID_CONNECTION_LOST:
		{
			ConsolePrintError("Lost connection to server");
			break;
		}
		case ID_NR_CONNECTIONS:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);
			bitStream.Read(m_connectionCount);

			std::cout << m_connectionCount << " A new client connected or disconnected to the server" << std::endl;
			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int nrOfPlayers = 0;
			float x, y, z;
			float dirX, dirY, dirZ;
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

				// (Add and) update players position
				UpdatePlayerPos(guid, x, y, z, dirX, dirY, dirZ);

				playerGuids.push_back(guid);				
			}

			// Check for removed players
			CheckForRemovedPlayers(playerGuids);


			m_newOrRemovedPlayers = true;

			std::cout << "Downloaded new players" << std::endl;
			break;
		}

		case ID_PLAYER_MOVED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float x, y, z;
			float dirX, dirY, dirZ;

			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);

			UpdatePlayerPos(guid, x, y, z, dirX, dirY, dirZ);
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

void Network::SendPlayerPos(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_MOVED);
	bitStream.Write(p_x);
	bitStream.Write(p_y);
	bitStream.Write(p_z);
	bitStream.Write(p_dirX);
	bitStream.Write(p_dirY);
	bitStream.Write(p_dirZ);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(SERVER_ADDRESS, SERVER_PORT), false);
}

void Network::UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.guid = p_owner;
		m_myPlayer.x = p_x;
		m_myPlayer.y = p_y;
		m_myPlayer.z = p_z;
		m_myPlayer.dirX = p_dirX;
		m_myPlayer.dirY = p_dirY;
		m_myPlayer.dirZ = p_dirZ;
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
				m_enemyPlayers[i].dirX = p_dirX;
				m_enemyPlayers[i].dirY = p_dirY;
				m_enemyPlayers[i].dirZ = p_dirZ;

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
			player.dirX = p_dirX;
			player.dirY = p_dirY;
			player.dirZ = p_dirZ;

			m_enemyPlayers.push_back(player);
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
	//bitStream.Write(p_shurikenID);
	//bitStream.Write(owner);
	
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