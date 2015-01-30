#include "Server.h"

Server::Server(){}

Server::~Server(){}

bool Server::Initialize()
{
	ServerGlobals::IS_SERVER = true;

	m_serverPeer = RakNet::RakPeerInterface::GetInstance();
	m_socketDesc = RakNet::SocketDescriptor(SERVER_PORT, 0);

	m_serverPeer->Startup(MAX_CLIENTS, &m_socketDesc, 1);
	m_serverPeer->SetMaximumIncomingConnections(MAX_CLIENTS);

	m_nrOfConnections = 0;

	// Initiate models (for boundingboxes)
	ModelLibrary::GetInstance()->Initialize(new BaseModel());

	// Initiate game state
	m_gameState = new NormalState();
	m_gameState->Initialize(m_serverPeer);

	return true;
}

void Server::Shutdown()
{
	m_gameState->Shutdown();
	delete m_gameState;

	m_serverPeer->Shutdown(1000);
	RakNet::RakPeerInterface::DestroyInstance(m_serverPeer);
}

void Server::Update(double p_deltaTime)
{
	ReceviePacket();

	m_gameState->Update(p_deltaTime);
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
			m_nrOfConnections++;
			std::cout << "A new connection is incoming (" << m_nrOfConnections << ")" << std::endl;
			

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
			m_nrOfConnections--;
			std::cout << "A client has disconnected (" << m_nrOfConnections << ")" <<std::endl;
			
			m_gameState->RemovePlayer(m_packet->guid);


			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_NR_CONNECTIONS);
			bitStream.Write(m_nrOfConnections);

			// Broadcast the nr of connections to all clients
			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);

			break;
		}
		case ID_CONNECTION_LOST:
		{
			m_nrOfConnections--;
			std::cout << "A client lost the connection (" << m_nrOfConnections << ")" << std::endl;
			m_gameState->RemovePlayer(m_packet->guid);
			break;
		}
		case ID_PLAYER_MOVED:
		{
			RakNet::BitStream rBitStream(m_packet->data, m_packet->length, false);

			rBitStream.Read(messageID);
			float x, y, z;

			rBitStream.Read(x);
			rBitStream.Read(y);
			rBitStream.Read(z);

			// Can player move?
			bool canMove = m_gameState->MovePlayer(m_packet->guid, x, y, z, m_nrOfConnections, false);

			if (canMove)
			{
				// Get player pos
				PlayerNet player = m_gameState->GetPlayer(m_packet->guid);

				RakNet::BitStream wBitStream;
				wBitStream.Write((RakNet::MessageID)ID_PLAYER_MOVED);
				wBitStream.Write(player.guid);
				wBitStream.Write(player.x);
				wBitStream.Write(player.y);
				wBitStream.Write(player.z);

				m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
			}
			break;
		}
		case ID_PLAYER_ROTATED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			float dirX, dirY, dirZ;

			bitStream.Read(messageID);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);

			bool canRotate = m_gameState->RotatePlayer(m_packet->guid, dirX, dirY, dirZ);

			if (canRotate)
			{
				PlayerNet player = m_gameState->GetPlayer(m_packet->guid);

				RakNet::BitStream wBitStream;
				wBitStream.Write((RakNet::MessageID)ID_PLAYER_ROTATED);
				wBitStream.Write(player.guid);
				wBitStream.Write(player.dirX);
				wBitStream.Write(player.dirY);
				wBitStream.Write(player.dirZ);

				m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
			}
			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			m_gameState->BroadcastPlayers();
			break;
		}
		case ID_ABILITY:
		{
			RakNet::BitStream rBitStream(m_packet->data, m_packet->length, false);

			rBitStream.Read(messageID);
			ABILITIES readAbility;
			float distanceFromPlayer;
			rBitStream.Read(readAbility);
			rBitStream.Read(distanceFromPlayer);

			int index = m_gameState->GetPlayerIndex(m_packet->guid);
			if (index != -1)
			{
				PlayerNet player = m_gameState->GetPlayer(m_packet->guid);

				if (m_gameState->CanUseAbility(index, readAbility) && player.isAlive)
				{
					m_gameState->ExecuteAbility(m_packet->guid, readAbility, readAbility == ABILITIES_DASH, distanceFromPlayer);
					m_gameState->UsedAbility(index, readAbility);
				}
			}
			break;
		}
		case ID_PLAYER_ANIMATION_CHANGED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			AnimationState state;

			// Read animation state
			bitStream.Read(messageID);
			bitStream.Read(state);

			if (m_gameState->GetPlayerIndex(m_packet->guid) != -1)
			{
				// Broadcast
				RakNet::BitStream wBitStream;
				wBitStream.Write((RakNet::MessageID)ID_PLAYER_ANIMATION_CHANGED);
				wBitStream.Write(m_packet->guid);
				wBitStream.Write(state);

				m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, m_packet->guid, true);
			}
			break;
		}
		case ID_CHOOSE_CHAR:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			std::cout << "Connection " << m_packet->guid.ToString() << " have choosen a character\n";

			int charNr;

			bitStream.Read(messageID);
			bitStream.Read(charNr);

			if (m_gameState->GetPlayerIndex(m_packet->guid) == -1)
			{
				m_gameState->AddPlayer(m_packet->guid, charNr);
			}
			break;
		}
		default:
			break;
		}
	}
}
