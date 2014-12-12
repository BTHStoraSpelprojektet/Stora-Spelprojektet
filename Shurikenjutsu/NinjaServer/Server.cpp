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

	// Set level name
	m_levelName = "../Shurikenjutsu/Levels/testBana.SSPL";
	m_shurikenModelName = "../Shurikenjutsu/Models/shurikenShape.SSP";
	m_playerModelName = "../Shurikenjutsu/Models/cubemanWnP";

	// Initate models (for boundingboxes)
	ModelLibrary::GetInstance()->Initialize(new BaseModel());

	// Initiate players
	m_playerManager = PlayerManager();
	m_playerManager.Initialize(m_serverPeer, m_levelName, m_playerModelName);

	// Initiate shurikens
	m_shurikenManager = ShurikenManager();
	m_shurikenManager.Initialize(m_serverPeer, m_levelName, m_shurikenModelName);

	// Initiate map
	m_mapManager = MapManager();
	m_mapManager.Initialize(m_levelName);

	//Initialize Collision manager
	m_collisionManager = new CollisionManager();
	m_collisionManager->Initialize(m_mapManager.GetBoundingBoxes());
	return true;
}

void Server::Shutdown()
{
	m_playerManager.Shutdown();

	m_serverPeer->Shutdown(1000);
	RakNet::RakPeerInterface::DestroyInstance(m_serverPeer);
}

void Server::Update(double p_deltaTime)
{
	ReceviePacket();

	m_playerManager.Update(p_deltaTime);
	m_shurikenManager.Update(p_deltaTime);

	m_collisionManager->ShurikenCollisionChecks(&m_shurikenManager, &m_playerManager);
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

			m_playerManager.AddPlayer(m_packet->guid, m_nrOfConnections);

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
			
			m_playerManager.RemovePlayer(m_packet->guid);


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
			m_playerManager.RemovePlayer(m_packet->guid);
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
			m_playerManager.MovePlayer(m_packet->guid, x, y, z, m_nrOfConnections);

			// Get player pos
			PlayerNet player = m_playerManager.GetPlayer(m_packet->guid);

			RakNet::BitStream wBitStream;
			wBitStream.Write((RakNet::MessageID)ID_PLAYER_MOVED);
			wBitStream.Write(player.guid);
			wBitStream.Write(player.x);
			wBitStream.Write(player.y);
			wBitStream.Write(player.z);

			m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);

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

			m_playerManager.RotatePlayer(m_packet->guid, dirX, dirY, dirZ);

			PlayerNet player = m_playerManager.GetPlayer(m_packet->guid);

			RakNet::BitStream wBitStream;
			wBitStream.Write((RakNet::MessageID)ID_PLAYER_ROTATED);
			wBitStream.Write(player.guid);
			wBitStream.Write(player.dirX);
			wBitStream.Write(player.dirY);
			wBitStream.Write(player.dirZ);

			m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
			break;
		}
		case ID_SHURIKEN_THROWN:
		{
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

			int index = m_playerManager.GetPlayerIndex(m_packet->guid);
			if (m_playerManager.CanUseAbility(index))
			{
				m_shurikenManager.AddShuriken(m_packet->guid, x, y, z, dirX, dirY, dirZ);
				m_playerManager.UsedAbility(index);
			}
			
			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			m_playerManager.BroadcastPlayers();
			break;
		}
		case ID_MELEE_ATTACK:
		{
			m_collisionManager->NormalMeleeAttack(m_packet->guid, &m_playerManager);
			break;
		}
		default:
			break;
		}
	}
}
