#include "Network.h"

RakNet::RakPeerInterface* Network::m_clientPeer;
RakNet::SocketDescriptor Network::m_socketDesc;
RakNet::Packet* Network::m_packet;
//ReplicaManager* Network::m_replicaManager;

bool Network::m_connected;
bool Network::m_prevConnected;
int Network::m_connectionCount;
std::vector<PlayerNet> Network::m_players;

bool Network::Initialize()
{
	ServerGlobals::IS_SERVER = false;
	m_connected = false;
	m_prevConnected = false;

	m_clientPeer = RakNet::RakPeerInterface::GetInstance();
	
	m_clientPeer->Startup(1, &m_socketDesc, 1);
	m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);

	
	//RakNet::NetworkIDManager *networkIdManager = RakNet::NetworkIDManager::GetInstance();
	//m_replicaManager = new ReplicaManager();
	//m_replicaManager->SetNetworkIDManager(networkIdManager);
	//m_clientPeer->AttachPlugin(m_replicaManager);

	m_players = std::vector<PlayerNet>();

	return true;
}

void Network::Shutdown()
{
	m_clientPeer->Shutdown(300);
	//m_clientPeer->DetachPlugin(m_replicaManager);
	RakNet::RakPeerInterface::DestroyInstance(m_clientPeer);
	//delete m_replicaManager;
}

void Network::Update()
{
	m_prevConnected = m_connected;
	ReceviePacket();

	//DataStructures::List<RakNet::Replica3*> replicaList2;
	//m_replicaManager->GetReplicasCreatedByMe(replicaList2);

	//for (int i = 0; i < replicaList2.Size(); i++)
	//{
	//	//std::cout << ((PlayerReplica*)replicaList2[i])->GetPosX() << " : " <<((PlayerReplica*)replicaList2[i])->GetPosZ() << std::endl;
	//}
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
			break;
		}
		case ID_CONNECTION_ATTEMPT_FAILED:
		{
			ConsolePrintFailed("Connection to server failed, trying to reconnect");

			m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);
			break;
		}
		case ID_REPLICA_MANAGER_SERIALIZE:
		{
			std::cout << "Serialize in replica manager" << std::endl;
			break;
		}
		case ID_REPLICA_MANAGER_CONSTRUCTION:
		{
			std::cout << "Constructed replica manager" << std::endl;
			break;
		}
		case ID_REPLICA_MANAGER_DOWNLOAD_STARTED:
		{
			std::cout << "Replica manager started downloading objects " << std::endl;
			break;
		}
		case ID_REPLICA_MANAGER_DOWNLOAD_COMPLETE:
		{
			std::cout << "Replica manager completed downloading objects" << std::endl;
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

			//std::cout << "Position: " << x << ", " << y << ", " << z << " from " << guid.ToString() << std::endl;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

//std::vector<PlayerReplica*> Network::GetOtherPlayers()
//{
//	std::vector<PlayerReplica*> players = std::vector<PlayerReplica*>();

	//unsigned int conCount = m_replicaManager->GetConnectionCount();
	//RakNet::SystemAddress remoteAddresses[MAX_CLIENTS];
	//unsigned short nrAddresses = MAX_CLIENTS;
	//m_clientPeer->GetConnectionList((RakNet::SystemAddress*)&remoteAddresses, &nrAddresses);
	//
	//
	////unsigned int conCount = m_connectionCount;
	////std::cout << "Nr of connections: " << conCount << std::endl;

	//for (unsigned int i = 0; i < conCount; i++)
	//{
	//	RakNet::RakNetGUID guid = m_replicaManager->GetConnectionAtIndex(i)->GetRakNetGUID();

	//	if (guid != m_clientPeer->GetMyGUID())
	//	{
	//		DataStructures::List<RakNet::Replica3*> replicaList;

	//		m_replicaManager->GetReplicasCreatedByGuid(guid, replicaList);

	//		for (unsigned int j = 0; j < replicaList.Size(); j++)
	//		{
	//			if (((DefaultReplica*)replicaList[j])->GetTypeName() == "Player")
	//			{
	//				std::cout << ((PlayerReplica*)replicaList[j])->GetPosX() << " : " << ((PlayerReplica*)replicaList[j])->GetPosZ() << std::endl;
	//				players.push_back((PlayerReplica*)replicaList[j]);
	//			}
	//		}
	//	}
	//}

//	return players;
//}

//void Network::AddReference(DefaultReplica* p_replica)
//{
//	m_replicaManager->Reference(p_replica);
//}
//
//void Network::RemoveReference(DefaultReplica* p_replica)
//{
//	m_replicaManager->Dereference(p_replica);
//}

//void Network::RemoveObject(DefaultReplica* p_replica)
//{
//	//m_replicaManager->BroadcastDestruction(p_replica);
//}


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

void Network::UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z)
{
	bool found = false;
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_owner)
		{
			found = true;
			m_players[i].x = p_x;
			m_players[i].y = p_y;
			m_players[i].z = p_z;
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
		m_players.push_back(player);
		std::cout << "New player added in the network list" << std::endl;
	}
}

std::vector<PlayerNet> Network::GetOtherPlayers()
{
	std::vector<PlayerNet> players = std::vector<PlayerNet>();

	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid != m_clientPeer->GetMyGUID())
		{
			players.push_back(m_players[i]);
		}
	}

	return players;
}

PlayerNet Network::GetMyPlayer()
{
	PlayerNet tmp;
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == m_clientPeer->GetMyGUID())
		{
			return m_players[i];
		}
	}

	return tmp;
}