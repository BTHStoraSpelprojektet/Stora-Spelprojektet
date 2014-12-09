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
	m_shurikenSetTimeLeft = 2.0f;
	m_players = std::vector<PlayerNet>();
	m_shurikens = std::vector<ShurikenNet>();

	// Load level
	m_levelName = "../Shurikenjutsu/Levels/testBana.SSPL";
	Level level(m_levelName);
	m_spawnPoints = level.GetSpawnPoints();

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

			AddPlayer(m_packet->guid);

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
			RemovePlayer(m_packet->guid);
			

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
			RemovePlayer(m_packet->guid);
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
		case ID_PLAYER_ROTATED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			float dirX, dirY, dirZ;

			bitStream.Read(messageID);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);

			RotatePlayer(m_packet->guid, dirX, dirY, dirZ);

			PlayerNet player = GetPlayer(m_packet->guid);

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

			AddShuriken(m_packet->guid, x, y, z, dirX, dirY, dirZ);
			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			BroadcastPlayers();
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

void Server::AddPlayer(RakNet::RakNetGUID p_guid)
{
	PlayerNet player;
	player.guid = p_guid;
	player.team = (m_nrOfConnections % 2) + 1;
	LevelImporter::SpawnPoint spawnPoint = GetSpawnPoint(player.team);
	player.x = spawnPoint.m_translationX;
	player.y = spawnPoint.m_translationY;
	player.z = spawnPoint.m_translationZ;
	player.dirX = 1.0f;
	player.dirY = 0.0f;
	player.dirZ = 0.0f;
	m_players.push_back(player);

	std::cout << "Player added" << std::endl;

	// Broadcast new player
	BroadcastPlayers();
}

void Server::MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z)
{
	bool found = false;

	// See if player can move to target position and then update position
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			if (abs(p_x - m_players[i].x) > 1.0f || abs(p_y - m_players[i].y) > 1.0f || abs(p_z - m_players[i].z) > 1.0f)
			{
				// Moved too far
				SendInvalidMessage(p_guid);
			}
			else
			{
				m_players[i].x = p_x;
				m_players[i].y = p_y;
				m_players[i].z = p_z;
			}			

			found = true;
			break;
		}
	}

	// Add player if he doesn't exist in the vector
	if (!found)
	{
		AddPlayer(p_guid);
	}
}

void Server::RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			m_players[i].dirX = p_dirX;
			m_players[i].dirY = p_dirY;
			m_players[i].dirZ = p_dirZ;
			break;
		}
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
		bitStream.Write(m_players[i].dirX);
		bitStream.Write(m_players[i].dirY);
		bitStream.Write(m_players[i].dirZ);
		bitStream.Write(m_players[i].team);
	}

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void Server::AddShuriken(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ)
{
	// Check if you can add shuriken
	int count = 0;
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (m_shurikens[i].guid == p_guid)
		{
			count++;
		}
	}

	// If true then add shuriken
	if (count < 5)
	{		
		ShurikenNet shuriken;
		shuriken.x = p_posX;
		shuriken.y = p_posY;
		shuriken.z = p_posZ;
		shuriken.dirX = p_dirX;
		shuriken.dirY = p_dirY;
		shuriken.dirZ = p_dirZ;
		shuriken.shurikenId = GetShurikenUniqueId();
		shuriken.guid = p_guid;
		shuriken.lifeTime = m_shurikenSetTimeLeft;
		shuriken.speed = 20.0f;
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
		wBitStream.Write(shuriken.speed);

		m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
	}
}

void Server::UpdateShurikens(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].lifeTime -= (float)p_deltaTime;

		// Calculate the shurikens position
		float lifeTime = m_shurikenSetTimeLeft - m_shurikens[i].lifeTime;
		float newPosX = m_shurikens[i].x + m_shurikens[i].dirX * m_shurikens[i].speed * lifeTime;
		float newPosY = m_shurikens[i].y + m_shurikens[i].dirY * m_shurikens[i].speed * lifeTime;
		float newPosZ = m_shurikens[i].z + m_shurikens[i].dirZ * m_shurikens[i].speed * lifeTime;


		// Check if the time has run out for the shuriken and remove it
		if (m_shurikens[i].lifeTime <= 0)
		{
			// Send removal of shuriken to clients
			BroadcastDestoyedShuriken(m_shurikens[i].shurikenId);

			m_shurikens.erase(m_shurikens.begin() + i);
			i--;
		}
	}
}

unsigned int Server::GetShurikenUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_shurikens.size(); i++)
		{
			if (m_shurikens[i].shurikenId == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);
	
	return ID;
}

void Server::CheckCollisions()
{
	float radius = 1.0f;
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		// Calculate the shurikens position
		float lifeTime = m_shurikenSetTimeLeft - m_shurikens[i].lifeTime;
		float newPosX = m_shurikens[i].x + m_shurikens[i].dirX * m_shurikens[i].speed * lifeTime;
		float newPosY = m_shurikens[i].y + m_shurikens[i].dirY * m_shurikens[i].speed * lifeTime;
		float newPosZ = m_shurikens[i].z + m_shurikens[i].dirZ * m_shurikens[i].speed * lifeTime;

		for (unsigned int j = 0; j < m_players.size(); j++)
		{
			// This is so you dont collide with your own shurikens
			if (m_players[j].guid == m_shurikens[i].guid)
			{
				continue;
			}

			// Make collision test
			if (IntersectionTests::Intersections::SphereSphereCollision(DirectX::XMFLOAT3(m_players[j].x, m_players[j].y, m_players[j].z), 1.0f, DirectX::XMFLOAT3(newPosX, newPosY, newPosZ), 0.5f))
			{
				// Remove shuriken
				BroadcastDestoyedShuriken(m_shurikens[i].shurikenId);

				m_shurikens.erase(m_shurikens.begin() + i);
				i--;

				// Respawn player
				RespawnPlayer(m_players[j].guid);
				break;
			}
		}
	}
}

void Server::BroadcastDestoyedShuriken(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SHURIKEN_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void Server::RespawnPlayer(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].guid == p_guid)
		{
			LevelImporter::SpawnPoint spawnPoint = GetSpawnPoint(m_players[i].team);
			std::cout << m_players[i].team << "\n";
			m_players[i].x = spawnPoint.m_translationX;
			m_players[i].y = spawnPoint.m_translationY;
			m_players[i].z = spawnPoint.m_translationZ;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_RESPAWN_PLAYER);
			bitStream.Write(m_players[i].x);
			bitStream.Write(m_players[i].y);
			bitStream.Write(m_players[i].z);

			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);
			break;
		}
	}
}

void Server::MeleeAttack(RakNet::RakNetGUID p_guid)
{
	PlayerNet attackingPlayer = GetPlayer(p_guid);
	for (unsigned int i = 0; i < m_players.size(); i++)
	{
		// So you don't collide with yourself.
		if (m_players[i].guid == attackingPlayer.guid)
		{
			continue;
		}
		DirectX::XMFLOAT3 spherePos = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, attackingPlayer.dirY, attackingPlayer.dirZ);
		DirectX::XMFLOAT3 boxPosition = DirectX::XMFLOAT3(m_players[i].x, m_players[i].y, m_players[i].z);
		DirectX::XMFLOAT3 boxExtent = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
		// Make collision test
		if (IntersectionTests::Intersections::MeleeAttackCollision(spherePos, 1.0f, boxPosition, boxExtent, attackDirection))
		{
			// Respawn player
			RespawnPlayer(m_players[i].guid);
			break;
		}
	}
}

void Server::SendInvalidMessage(RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_INVALID_MOVE);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);
}

LevelImporter::SpawnPoint Server::GetSpawnPoint(int p_team)
{
	for (unsigned int i = 0; i < m_spawnPoints.size(); i++)
	{
		if (m_spawnPoints[i].m_team == p_team)
		{
			return m_spawnPoints[i];
		}
	}

	// If the player didn't found a spawnpoint for the team he was in then choose a random point
	int index = rand() % m_spawnPoints.size();
	return m_spawnPoints[index];
}