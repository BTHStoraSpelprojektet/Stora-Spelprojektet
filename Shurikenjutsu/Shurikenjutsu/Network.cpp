#include "Network.h"

RakNet::RakPeerInterface* Network::m_clientPeer;
RakNet::SocketDescriptor Network::m_socketDesc;
RakNet::Packet* Network::m_packet;
ReplicaManager* Network::m_replicaManager;

bool Network::m_connected;
bool Network::m_prevConnected;

bool Network::Initialize()
{
	ServerGlobals::IS_SERVER = false;
	m_connected = false;
	m_prevConnected = false;

	m_clientPeer = RakNet::RakPeerInterface::GetInstance();

	m_clientPeer->Startup(1, &m_socketDesc, 1);
	m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);

	
	RakNet::NetworkIDManager *networkIdManager = RakNet::NetworkIDManager::GetInstance();
	m_replicaManager = new ReplicaManager();
	m_replicaManager->SetNetworkIDManager(networkIdManager);
	m_clientPeer->AttachPlugin(m_replicaManager);

	return true;
}

void Network::Shutdown()
{
	m_clientPeer->Shutdown(300);
	m_clientPeer->DetachPlugin(m_replicaManager);
	RakNet::RakPeerInterface::DestroyInstance(m_clientPeer);
	delete m_replicaManager;
}

void Network::Update()
{
	m_prevConnected = m_connected;
	ReceviePacket();
}

void Network::ReceviePacket()
{
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
		default:
		{
			break;
		}
		}
	}
}

std::vector<PlayerReplica*> Network::GetOtherPlayers()
{
	std::vector<PlayerReplica*> players = std::vector<PlayerReplica*>();

	DataStructures::List<RakNet::Replica3*> replicaList2;
	m_replicaManager->GetReplicasCreatedByMe(replicaList2);

	unsigned int conCount = m_replicaManager->GetConnectionCount();

	for (unsigned int i = 0; i < conCount; i++)
	{
		RakNet::RakNetGUID guid = m_replicaManager->GetConnectionAtIndex(i)->GetRakNetGUID();

		if (guid != m_replicaManager->GetMyGUIDUnified())
		{
			DataStructures::List<RakNet::Replica3*> replicaList;

			m_replicaManager->GetReplicasCreatedByGuid(guid, replicaList);

			for (unsigned int i = 0; i < replicaList.Size(); i++)
			{
				if (((DefaultReplica*)replicaList[i])->GetTypeName() == "Player")
				{
					players.push_back((PlayerReplica*)replicaList[i]);
				}
			}
		}
	}

	return players;
}

void Network::AddReference(DefaultReplica* p_replica)
{
	m_replicaManager->Reference(p_replica);
}

void Network::RemoveReference(DefaultReplica* p_replica)
{
	m_replicaManager->Dereference(p_replica);
}

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