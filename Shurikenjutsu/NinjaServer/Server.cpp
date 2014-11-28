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

	//RakNet::NetworkIDManager* networkIdManager = RakNet::NetworkIDManager::GetInstance();
	//m_replicaManager = new ReplicaManager();
	//m_replicaManager->SetNetworkIDManager(networkIdManager);
	//m_serverPeer->AttachPlugin(m_replicaManager);

	m_nrOfConnections = 0;
	m_players = std::vector<PlayerNet>();

	return true;
}

void Server::Shutdown()
{
	m_serverPeer->Shutdown(1000);
	//m_serverPeer->DetachPlugin(m_replicaManager);
	RakNet::RakPeerInterface::DestroyInstance(m_serverPeer);
	//delete m_replicaManager;
}

void Server::Update()
{
	ReceviePacket();
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
}