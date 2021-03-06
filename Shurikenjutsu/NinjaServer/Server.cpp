#include "Server.h"
#include <iostream>
#include <fstream>

Server::Server(){}

Server::~Server(){}

bool Server::Initialize()
{
	ServerGlobals::IS_SERVER = true;

	ReadLevels();

	m_serverPeer = RakNet::RakPeerInterface::GetInstance();
	m_socketDesc = RakNet::SocketDescriptor(SERVER_PORT, 0);

	m_serverPeer->Startup(MAX_CLIENTS, &m_socketDesc, 1);
	m_serverPeer->SetMaximumIncomingConnections(MAX_CLIENTS);

	m_networkLogger = NetworkLogger();
	m_networkLogger.Initialize();
	m_serverPeer->AttachPlugin(&m_networkLogger);

	m_nrOfConnections = 0;

	// Initiate models (for boundingboxes)
	ModelLibrary::GetInstance()->Initialize(new BaseModel());

	// Initiate game state
	m_gameState = new NormalState();
	m_gameState->Initialize(m_serverPeer,m_levels,m_currentLevel);

	RakNet::SystemAddress systemAdress = m_serverPeer->GetSystemAddressFromGuid(m_serverPeer->GetMyGUID());
	std::string ip1 = std::to_string(systemAdress.address.addr4.sin_addr.S_un.S_un_b.s_b1);
	std::string ip2 = std::to_string(systemAdress.address.addr4.sin_addr.S_un.S_un_b.s_b2);
	std::string ip3 = std::to_string(systemAdress.address.addr4.sin_addr.S_un.S_un_b.s_b3);
	std::string ip4 = std::to_string(systemAdress.address.addr4.sin_addr.S_un.S_un_b.s_b4);
	std::string ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;

	std::cout << "IP: " << ip << std::endl;;
	std::cout << "PORT: " << systemAdress.debugPort << std::endl << std::endl;

	return true;
}

void Server::ReadLevels(){
	//Read from file
	std::string levelsPath = "../Shurikenjutsu/Levels/";
	std::string settingFile = "../Shurikenjutsu/Settings/ServerLevels.cfg";

	std::ifstream infile(settingFile, std::ifstream::in);
	char line[256];
	while (infile.getline(line,256)){
		std::string level = levelsPath;
		level.append(line);
		if (level.size()>levelsPath.size()){
			m_levels.push_back(level);
		}
	}

	//Set default if file not found
	if (m_levels.size() == 0){
		m_levels.push_back(LEVEL_NAME);
	}

	//Set start level
	m_currentLevel = 0;
}

void Server::Shutdown()
{
	m_gameState->Shutdown();
	delete m_gameState;

	ModelLibrary::GetInstance()->Shutdown();

	m_serverPeer->Shutdown(1000);
	RakNet::RakPeerInterface::DestroyInstance(m_serverPeer);
}

void Server::Update(double p_deltaTime)
{
	ReceviePacket();
	m_networkLogger.Update(p_deltaTime);

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
			
			m_gameState->UserConnected(m_packet->guid);

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_NR_CONNECTIONS);
			bitStream.Write(m_nrOfConnections);
			bitStream.Write(m_packet->guid);

			// Broadcast the nr of connections to all clients
			m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);

			RakNet::BitStream bitStream2;

			bitStream2.Write((RakNet::MessageID)ID_LEVELNAME);
			//std::string lev = "../Shurikenjutsu/Levels/WaterArena.SSPL";
			//std::string lev = "../Shurikenjutsu/Levels/NightTimeArena.SSPL";
			RakNet::RakString levelName(m_levels[m_currentLevel].c_str());
			bitStream2.Write(levelName);

			m_serverPeer->Send(&bitStream2, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_packet->guid, false);

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
			bitStream.Write(m_packet->guid);

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
			m_gameState->MovePlayer(m_packet->guid, x, y, z, m_nrOfConnections, false);

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

			m_gameState->RotatePlayer(m_packet->guid, dirX, dirY, dirZ);
			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			m_gameState->BroadcastPlayers();
			break;
		}
		case ID_DOWNLOAD_RUNES:
		{
			m_gameState->SendCurrentRunes(m_packet->guid);
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

				if (player.isAlive)
				{
					m_gameState->ExecuteAbility(m_packet->guid, readAbility, distanceFromPlayer);
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

				m_serverPeer->Send(&wBitStream, MEDIUM_PRIORITY, UNRELIABLE, 5, m_packet->guid, true);
			}
			break;
		}
		case ID_CHOOSE_CHAR:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			std::cout << "Connection " << m_packet->systemAddress.ToString() << " have choosen a character\n";

			RakNet::RakString name;
			int charNr;
			int toolNr;
			int team;
			bitStream.Read(messageID);
			bitStream.Read(name);
			bitStream.Read(charNr);
			bitStream.Read(toolNr);
			bitStream.Read(team);



			if (m_gameState->GetPlayerIndex(m_packet->guid) == -1)
			{
				m_gameState->AddPlayer(m_packet->guid, name, charNr, toolNr, team);
			}


			break;
		}
		case ID_TIMER_SYNC:
		{
			m_gameState->SyncTime(m_packet->guid);
			break;
		}
		case ID_SEND_TEAM_SCORE:
		{
			m_gameState->SendCurrentTeamScore(m_packet->guid);
			break;
		}
		case ID_SEND_VISIBLE_PLAYERS:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned char size;
			unsigned char id;

			bitStream.Read(messageID);
			bitStream.Read(size);

			unsigned int uiSize = (unsigned int)size;
			int iId;
			std::vector<int> visiblePlayers = std::vector<int>();

			for (unsigned int i = 0; i < uiSize; i++)
			{
				bitStream.Read(id);
				iId = (int)id;

				visiblePlayers.push_back(iId);
			}

			m_gameState->UpdatePlayerVisibility(m_packet->guid, visiblePlayers);

			break;
		}
		case ID_LOBBY_CHOOSE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int charNr, toolNr, team;
			RakNet::RakString name;
			bool isReady;

			bitStream.Read(messageID);
			bitStream.Read(charNr);
			bitStream.Read(toolNr);
			bitStream.Read(team);
			bitStream.Read(name);
			bitStream.Read(isReady);

			m_gameState->SetPlayerInLobby(m_packet->guid, charNr, toolNr, team, name.C_String(), isReady);

			break;
		}
		case ID_START_GAME:
		{
			m_gameState->SendStartGame();
			break;
		}
		default:
			break;
		}
	}
}