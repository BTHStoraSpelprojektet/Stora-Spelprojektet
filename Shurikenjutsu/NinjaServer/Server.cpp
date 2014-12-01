#include "Server.h"

Server::Server()
{
}


Server::~Server()
{
}

bool Server::Initialize()
{
	ServerGlobals::IS_SERVER = true;

	m_serverPeer = RakNet::RakPeerInterface::GetInstance();
	m_socketDesc = RakNet::SocketDescriptor(SERVER_PORT, 0);

	m_serverPeer->Startup(MAX_CLIENTS, &m_socketDesc, 1);
	m_serverPeer->SetMaximumIncomingConnections(MAX_CLIENTS);

	m_nrOfConnections = 0;
	m_shurikenId = 0;
	m_players = std::vector<PlayerNet>();
	m_shurikens = std::vector<ShurikenNet>();

	return true;
}

void Server::Shutdown()
{
	m_serverPeer->Shutdown(1000);
	RakNet::RakPeerInterface::DestroyInstance(m_serverPeer);
}

void Server::Update(double p_deltaTime)
{
	ReceviePacket();

	UpdateShurikens(p_deltaTime);
}

void Server::ReceviePacket()
{
	unsigned char messageID;
	for (m_packet = m_serverPeer->Receive(); m_packet; m_serverPeer->DeallocatePacket(m_packet), m_packet = m_serverPeer->Receive())
	{
		switch (m_packet->data[0])
		{
		case ID_NEW_INCOMING_CONNECTION:
		{
			std::cout << "A new connection is incoming" << std::endl;
			m_nrOfConnections++;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_NR_CONNECTIONS);
			bitStream.Write(m_nrOfConnections);

			// Broadcast the nr of connections to all clients
			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);

			break;
		}
		case ID_CONNECTION_REQUEST_ACCEPTED:
		{
			std::cout << "A new connections has connected" << std::endl;
			
			break;
		}
		case ID_DISCONNECTION_NOTIFICATION:
		{
			std::cout << "A client has disconnected" << std::endl;
			RemovePlayer(m_packet->guid);
			m_nrOfConnections--;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_NR_CONNECTIONS);
			bitStream.Write(m_nrOfConnections);

			// Broadcast the nr of connections to all clients
			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);

			break;
		}
		case ID_CONNECTION_LOST:
		{
			std::cout << "A client lost the connection" << std::endl;
			RemovePlayer(m_packet->guid);
			break;
		}
		case ID_PLAYER_MOVED:
		{
			//std::cout << "A player moved" << std::endl;

			RakNet::BitStream rBitStream(m_packet->data, m_packet->length, false);

			rBitStream.Read(messageID);
			float x, y, z;

			rBitStream.Read(x);
			rBitStream.Read(y);
			rBitStream.Read(z);

			// Can player move?
			MovePlayer(m_packet->guid, x, y, z);

			// Get player pos
			PlayerNet player = GetPlayer(m_packet->guid);

			RakNet::BitStream wBitStream;
			wBitStream.Write((RakNet::MessageID)ID_PLAYER_MOVED);
			wBitStream.Write(player.guid);
			wBitStream.Write(player.x);
			wBitStream.Write(player.y);
			wBitStream.Write(player.z);

			m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);

			break;
		}
		case ID_SHURIKEN_THROWN:
		{
			std::cout << "Shuriken thrown \n";
			RakNet::BitStream rBitStream(m_packet->data, m_packet->length, false);

			rBitStream.Read(messageID);
			float x, y, z;
			float dirX, dirY, dirZ;

			rBitStream.Read(x);
			rBitStream.Read(y);
			rBitStream.Read(z);
			rBitStream.Read(dirX);
			rBitStream.Read(dirY);
			rBitStream.Read(dirZ);

			AddShuriken(m_packet->guid, x, y, z, dirX, dirY, dirZ);
			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			BroadcastPlayers();
			break;
		}
		default:
			break;
		}
	}
}

void Server::MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z)
{


	bool found = false;


	// See if player can move to target position and then update position
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			m_players[i].x = p_x;
			m_players[i].y = p_y;
			m_players[i].z = p_z;

			found = true;
			break;
		}
	}

	// Temp
	// Add player if he doesn't exist in the vector
	if (!found)
	{
		PlayerNet player;
		player.guid = p_guid;
		player.x = p_x;
		player.y = p_y;
		player.z = p_z;
		m_players.push_back(player);

		std::cout << "Player added" << std::endl;

		// Broadcast new player
		BroadcastPlayers();
	}
}

PlayerNet Server::GetPlayer(RakNet::RakNetGUID p_guid)
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

void Server::RemovePlayer(RakNet::RakNetGUID p_guid)
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

void Server::BroadcastPlayers()
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
	}

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void Server::AddShuriken(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ)
{
	// Check if you can add shuriken
	// Add code

	// If true then add shuriken
	ShurikenNet shuriken;
	shuriken.x = p_posX;
	shuriken.y = p_posY;
	shuriken.z = p_posZ;
	shuriken.dirX = p_dirX;
	shuriken.dirY = p_dirY;
	shuriken.dirZ = p_dirZ;
	shuriken.shurikenId = m_shurikenId++;
	shuriken.guid = p_guid;
	shuriken.lifeTime = 2.0f;

	m_shurikens.push_back(shuriken);

	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_SHURIKEN_THROWN);
	wBitStream.Write(shuriken.x);
	wBitStream.Write(shuriken.y);
	wBitStream.Write(shuriken.z);
	wBitStream.Write(shuriken.dirX);
	wBitStream.Write(shuriken.dirY);
	wBitStream.Write(shuriken.dirZ);
	wBitStream.Write(shuriken.shurikenId);
	wBitStream.Write(shuriken.guid);

	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void Server::UpdateShurikens(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].lifeTime -= (float)p_deltaTime;
		if (m_shurikens[i].lifeTime <= 0)
		{
			// Send removal of shuriken to clients
			RakNet::BitStream bitStream;
			bitStream.Write((RakNet::MessageID)ID_SHURIKEN_REMOVE);
			bitStream.Write(m_shurikens[i].shurikenId);

			m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);

			m_shurikens.erase(m_shurikens.begin() + i);
			i--;
		}
	}
}