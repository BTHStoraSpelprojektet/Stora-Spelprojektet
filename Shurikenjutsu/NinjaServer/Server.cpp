#include "Server.h"
bool ServerGlobals::IS_SERVER;

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

	return true;
}

void Server::Shutdown()
{
	RakNet::RakPeerInterface::DestroyInstance(m_serverPeer);
}

void Server::Update()
{
	ReceviePacket();
}

void Server::ReceviePacket()
{
	for (m_packet = m_serverPeer->Receive(); m_packet; m_serverPeer->DeallocatePacket(m_packet), m_packet = m_serverPeer->Receive())
	{
		switch (m_packet->data[0])
		{
		case ID_NEW_INCOMING_CONNECTION:
		{
			std::cout << "A new connection is incoming" << std::endl;

			break;
		}
		case ID_DISCONNECTION_NOTIFICATION:
		{
			std::cout << "A client has disconnected" << std::endl;
			break;
		}
		case ID_CONNECTION_LOST:
		{
			std::cout << "A client lost the connection" << std::endl;
			break;
		}
		default:
			break;
		}
	}
}