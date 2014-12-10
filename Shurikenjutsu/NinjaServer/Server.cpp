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

	CheckCollisions();
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

			m_shurikenManager.AddShuriken(m_packet->guid, x, y, z, dirX, dirY, dirZ);
			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			m_playerManager.BroadcastPlayers();
			break;
		}
		case ID_MELEE_ATTACK:
		{
			MeleeAttack(m_packet->guid);
			break;
		}
		default:
			break;
		}
	}
}

void Server::CheckCollisions()
{
	float radius = 1.0f;
	std::vector<PlayerNet> playerList = m_playerManager.GetPlayers();
	std::vector<ShurikenNet> shurikenList = m_shurikenManager.GetShurikens();
	for (unsigned int i = 0; i < shurikenList.size(); i++)
	{
		bool collisionFound = false;

		// Get the shurikens position
		float newPosX = m_shurikenManager.GetShurikenPosX(i);
		float newPosY = m_shurikenManager.GetShurikenPosY(i);
		float newPosZ = m_shurikenManager.GetShurikenPosZ(i);

		// Get the shuriken bounding boxes
		std::vector<Box> shurikenBoundingBoxes = m_shurikenManager.GetBoundingBoxes(i);

		// Go through player list
		for (unsigned int j = 0; j < playerList.size(); j++)
		{
			// This is so you don't collide with your own shurikens
			if (playerList[j].guid == shurikenList[i].guid)
			{
				continue;
			}

			// Check so you are not on the same team
			PlayerNet shootingPlayer = m_playerManager.GetPlayer(shurikenList[i].guid);
			if (playerList[j].team == shootingPlayer.team)
			{
				continue;
			}

			// Get the players bounding boxes
			std::vector<Box> playerBoundingBoxes = m_playerManager.GetBoundingBoxes(j);

			// Make collision test
			for (unsigned int k = 0; k < shurikenBoundingBoxes.size(); k++)
			{
				for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
				{
					if (IntersectionTests::Intersections::BoxBoxCollision(playerBoundingBoxes[l].m_center, playerBoundingBoxes[l].m_extents, shurikenBoundingBoxes[k].m_center, shurikenBoundingBoxes[k].m_extents))
					{
						// Remove shuriken
						m_shurikenManager.RemoveShuriken(shurikenList[i].shurikenId);
						shurikenList.erase(shurikenList.begin() + i);
						i--;

						// Respawn player
						m_playerManager.RespawnPlayer(playerList[j].guid);

						collisionFound = true;
						break;
					}
				}
				if (collisionFound)
				{
					break;
				}
			}

			if (collisionFound)
			{
				break;
			}
		}

		// Go through maps bounding boxes
		std::vector<Box> mapBoundingBoxes = m_mapManager.GetBoundingBoxes();
		for (unsigned int j = 0; j < shurikenBoundingBoxes.size(); j++)
		{
			for (unsigned int k = 0; k < mapBoundingBoxes.size(); k++)
			{
				if (IntersectionTests::Intersections::BoxBoxCollision(mapBoundingBoxes[k].m_center, mapBoundingBoxes[k].m_extents, shurikenBoundingBoxes[j].m_center, shurikenBoundingBoxes[j].m_extents))
				{
					// Remove shuriken
					m_shurikenManager.RemoveShuriken(shurikenList[i].shurikenId);
					shurikenList.erase(shurikenList.begin() + i);
					i--;

					collisionFound = true;
					break;
				}
			}
			if (collisionFound)
			{
				break;
			}
		}		
	}
}

void Server::MeleeAttack(RakNet::RakNetGUID p_guid)
{
	PlayerNet attackingPlayer = m_playerManager.GetPlayer(p_guid);
	std::vector<PlayerNet> playerList = m_playerManager.GetPlayers();
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		// So you don't collide with yourself.
		if (playerList[i].guid == attackingPlayer.guid)
		{
			continue;
		}

		// Check so you are not on the same team
		if (playerList[i].team == attackingPlayer.team)
		{
			continue;
		}

		DirectX::XMFLOAT3 spherePos = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, attackingPlayer.dirY, attackingPlayer.dirZ);
		DirectX::XMFLOAT3 boxPosition = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);
		DirectX::XMFLOAT3 boxExtent = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
		// Make collision test
		if (IntersectionTests::Intersections::MeleeAttackCollision(spherePos, 1.0f, boxPosition, boxExtent, attackDirection))
		{
			// Respawn player
			m_playerManager.RespawnPlayer(playerList[i].guid);
			break;
		}
}
}