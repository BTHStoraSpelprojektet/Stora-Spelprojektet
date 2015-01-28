#include "Network.h"
#include <iostream>
#include "ConsoleFunctions.h"

Network* Network::m_instance;

Network::Network(){}
Network::~Network(){}

Network* Network::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Network();
	}

	return m_instance;
}

bool Network::Initialize()
{
	ServerGlobals::IS_SERVER = false;
	m_connected = false;
	m_prevConnected = false;
	m_newOrRemovedPlayers = false;
	m_shurikenListUpdated = false;
	m_smokebombListUpdated = false;
	m_respawned = false;
	m_invalidMove = false;
	m_roundRestarted = false;
	m_newLevel = false;
	m_levelName = "";
	m_dashed = false;

	m_clientPeer = RakNet::RakPeerInterface::GetInstance();
	
	m_clientPeer->Startup(1, &m_socketDesc, 1);

	m_enemyPlayers = std::vector<PlayerNet>();
	m_shurikensList = std::vector<ShurikenNet>();

	m_connectionCount = 0;
	m_previousCount = 0;

	m_networkStatus = NETWORKSTATUS_NONE;

	return true;
}

void Network::Shutdown()
{
	m_clientPeer->Shutdown(300);
	RakNet::RakPeerInterface::DestroyInstance(m_clientPeer);

	delete m_instance;
}

void Network::Update()
{
	m_prevConnected = m_connected;
	ReceviePacket();
}

void Network::ReceviePacket()
{
	// Reset status
	m_networkStatus = NETWORKSTATUS_NONE;

	unsigned char messageID;
	for (m_packet = m_clientPeer->Receive(); m_packet; m_clientPeer->DeallocatePacket(m_packet), m_packet = m_clientPeer->Receive())
	{
		switch (m_packet->data[0])
		{
		case ID_CONNECTION_REQUEST_ACCEPTED:
		{
			ConsolePrintSuccess("Connected to the server.");
			ConsoleSkipLines(1);

			m_connected = true;
			m_networkStatus = NETWORKSTATUS_CONNECTED;

			RakNet::BitStream bitStream;

			bitStream.Write((RakNet::MessageID)ID_DOWNLOAD_PLAYERS);

			m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_packet->guid, false);

			break;
		}
		case ID_CONNECTION_ATTEMPT_FAILED:
		{
			ConsolePrintError("Connection to server failed.");
			m_networkStatus = NETWORKSTATUS_TIMEOUT;
			//m_clientPeer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0);
			break;
		}
		case ID_DISCONNECTION_NOTIFICATION:
		{
			ConsolePrintError("Server shut down.");
			m_networkStatus = NETWORKSTATUS_LOST;
			ConsoleSkipLines(1);

			break;
		}
		case ID_CONNECTION_LOST:
		{
			ConsolePrintError("Lost connection to server.");
			m_networkStatus = NETWORKSTATUS_LOST;
			ConsoleSkipLines(1);

			break;
		}
		case ID_NR_CONNECTIONS:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);
			bitStream.Read(m_connectionCount);

			if (m_connectionCount < m_previousCount)
			{
				ConsolePrintError("Client disconnected.");
			}
			else
			{
				ConsolePrintSuccess("New client connected.");
			}

			ConsolePrintText("Players connected: " + std::to_string(m_connectionCount));
			ConsoleSkipLines(1);

			m_previousCount = m_connectionCount;

			break;
		}
		case ID_DOWNLOAD_PLAYERS:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int nrOfPlayers = 0;
			float x, y, z;
			float dirX, dirY, dirZ;
			int team;
			int maxHP, currentHP;
			bool isAlive;
			RakNet::RakNetGUID guid;
			std::vector<RakNet::RakNetGUID> playerGuids = std::vector<RakNet::RakNetGUID>();
			bitStream.Read(messageID);
			bitStream.Read(nrOfPlayers);

			for (int i = 0; i < nrOfPlayers; i++)
			{
				bitStream.Read(guid);
				bitStream.Read(x);
				bitStream.Read(y);
				bitStream.Read(z);
				bitStream.Read(dirX);
				bitStream.Read(dirY);
				bitStream.Read(dirZ);
				bitStream.Read(team);
				bitStream.Read(maxHP);
				bitStream.Read(currentHP);
				bitStream.Read(isAlive);

				// (Add and) update players position
				UpdatePlayerPos(guid, x, y, z);
				UpdatePlayerDir(guid, dirX, dirY, dirZ);
				UpdatePlayerHP(guid, maxHP, currentHP, isAlive);
				UpdatePlayerTeam(guid, team);

				playerGuids.push_back(guid);				
			}

			// Check for removed players
			CheckForRemovedPlayers(playerGuids);

			m_newOrRemovedPlayers = true;

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
			break;
		}
		case ID_PLAYER_ROTATED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float dirX, dirY, dirZ;

			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);

			UpdatePlayerDir(guid, dirX, dirY, dirZ);
			break;
		}
		case ID_SHURIKEN_THROWN:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float x, y, z;
			float dirX, dirY, dirZ;
			unsigned int shurikenID;
			float speed;
			bool megaShuriken;

			bitStream.Read(messageID);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);
			bitStream.Read(shurikenID);
			bitStream.Read(guid);
			bitStream.Read(speed);
			bitStream.Read(megaShuriken);

			UpdateShurikens(x, y, z, dirX, dirY, dirZ, shurikenID, guid, speed, megaShuriken);
			break;
		}
		case ID_SHURIKEN_REMOVE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int shurikenId;
			bitStream.Read(messageID);
			bitStream.Read(shurikenId);

			RemoveShuriken(shurikenId);

			break;
		}
		case ID_RESPAWN_PLAYER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			float x, y, z;
			bitStream.Read(messageID);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			RespawnPlayer(x, y, z);

			break;
		}
		case ID_PLAYER_INVALID_MOVE:
		{
			m_invalidMove = true;
			break;
		}
		case ID_PLAYER_HP_CHANGED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			int currentHP;
			bool isAlive;

			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(currentHP);
			bitStream.Read(isAlive);

			UpdatePlayerHP(guid, currentHP, isAlive);

			break;
		}
		case ID_ABILITY:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			ABILITIES abilityEnum;
			RakNet::RakString abilityString;
			bitStream.Read(messageID);
			bitStream.Read(abilityEnum);
			bitStream.Read(abilityString);

			std::cout << " " << abilityString << std::endl;

			break;
		}
		case ID_ROUND_OVER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int winningTeam;

			bitStream.Read(messageID);
			bitStream.Read(winningTeam);

			std::cout << "Team " << winningTeam << " won this round\n";
			break;
		}
		case ID_RESTARTED_ROUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);

			m_roundRestarted = true;
			std::cout << "New round has started\n";
			break;
		}
		case ID_RESTARTING_ROUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);

			std::cout << "Restarting round in:\n";
			break;
		}
		case ID_RESTARTING_ROUND_TIMER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int time;

			bitStream.Read(messageID);
			bitStream.Read(time);

			std::cout << time << std::endl;
			break;
		}
		case ID_SMOKEBOMB_THROW:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int smokebombId;
			float startPosX, startPosZ, endPosX, endPosZ, lifetime;
			bitStream.Read(messageID);
			bitStream.Read(smokebombId);
			bitStream.Read(startPosX);
			bitStream.Read(startPosZ);
			bitStream.Read(endPosX);
			bitStream.Read(endPosZ);
			bitStream.Read(lifetime);

			UpdateSmokeBomb(smokebombId, startPosX, startPosZ, endPosX, endPosZ, lifetime);
			break;
		}
		case ID_SMOKEBOMB_REMOVE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int smokeBombID;
			bitStream.Read(messageID);
			bitStream.Read(smokeBombID);

			RemoveSmokeBomb(smokeBombID);
			break;
		}
		case ID_MATCH_OVER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int winningTeam;

			bitStream.Read(messageID);
			bitStream.Read(winningTeam);

			std::cout << "Team " << winningTeam << " won this match\n";
			break;
		}
		case ID_NEW_LEVEL:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakString levelName;

			bitStream.Read(messageID);
			bitStream.Read(levelName);

			m_newLevel = true;
			m_levelName = levelName;

			// Send invalid positions to get an invalid move from server and therefore update correct position according to server
			SendPlayerPos(100.0f, -100.0f, 100.0f);
			SendPlayerPos(-100.0f, 100.0f, -100.0f);

			std::cout << "Starting new level\n";
			break;
		}
		case ID_PLAYER_ANIMATION_CHANGED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			AnimationState state;

			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(state);

			// Todo: Update local player animation
			m_playerAnimations[guid] = state;
			break;
		}
		case ID_DASH_TO_LOCATION:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			float x, y, z;

			bitStream.Read(messageID);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			m_dashLocation = DirectX::XMFLOAT3(x, y, z);

			m_dashed = true;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void Network::Connect(std::string p_ip)
{
	std::cout << "Connecting to: " << p_ip << std::endl;
	m_ip = p_ip;
	m_clientPeer->Connect(m_ip.c_str(), SERVER_PORT, 0, 0);
}

void Network::Disconnect()
{
	std::cout << "Disconnecting from server" << std::endl;
	m_clientPeer->Shutdown(300);
	m_clientPeer->Startup(1, &m_socketDesc, 1);
}

void Network::ChooseChar()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_CHOOSE_CHAR);

	m_clientPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

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

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

void Network::SendPlayerDir(float p_dirX, float p_dirY, float p_dirZ)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_ROTATED);
	bitStream.Write(p_dirX);
	bitStream.Write(p_dirY);
	bitStream.Write(p_dirZ);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

void Network::UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.guid = p_owner;
		m_myPlayer.x = p_x;
		m_myPlayer.y = p_y;
		m_myPlayer.z = p_z;
	}
	else
	{
		bool found = false;
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].x = p_x;
				m_enemyPlayers[i].y = p_y;
				m_enemyPlayers[i].z = p_z;

				found = true;
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
			player.dirX = 1.0f;
			player.dirY = 0.0f;
			player.dirZ = 0.0f;

			m_enemyPlayers.push_back(player);
		}
	}
	
}

void Network::UpdatePlayerDir(RakNet::RakNetGUID p_owner, float p_dirX, float p_dirY, float p_dirZ)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.dirX = p_dirX;
		m_myPlayer.dirY = p_dirY;
		m_myPlayer.dirZ = p_dirZ;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].dirX = p_dirX;
				m_enemyPlayers[i].dirY = p_dirY;
				m_enemyPlayers[i].dirZ = p_dirZ;
				break;
			}
		}
	}
}

void Network::UpdatePlayerTeam(RakNet::RakNetGUID p_owner, int p_team)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.team = p_team;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].team = p_team;
			}
		}
	}
}

std::vector<PlayerNet> Network::GetOtherPlayers()
{
	return m_enemyPlayers;
}

PlayerNet Network::GetMyPlayer()
{
	return m_myPlayer;
}

void Network::AddShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ)
{
	RakNet::BitStream bitStream;
	RakNet::RakNetGUID owner = m_clientPeer->GetMyGUID();
	bitStream.Write((RakNet::MessageID)ID_SHURIKEN_THROWN);
	bitStream.Write(p_x);
	bitStream.Write(p_y);
	bitStream.Write(p_z);
	bitStream.Write(p_dirX);
	bitStream.Write(p_dirY);
	bitStream.Write(p_dirZ);
	
	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

void Network::UpdateSmokeBomb(unsigned int p_smokebombId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime)
{

	bool addSmokeBomb = true;
	SmokeBombNet temp;
	temp.smokeBombId = p_smokebombId;
	temp.startX = p_startPosX;
	temp.startZ = p_startPosZ;
	temp.endX = p_endPosX;
	temp.endZ = p_endPosZ;
	temp.lifeTime = p_lifetime;

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		if (m_smokeBombList[i].smokeBombId == temp.smokeBombId)
		{
			addSmokeBomb = false;
			break;
		}
	}
	if (addSmokeBomb)
	{
		m_smokeBombList.push_back(temp);
		m_smokebombListUpdated = true;
	}
}
void Network::UpdateShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid, float p_speed, bool p_megaShuriken)
{
	bool addShuriken = true;
	ShurikenNet tempShuriken;
	tempShuriken = ShurikenNet();
	tempShuriken.x = p_x;
	tempShuriken.y = p_y;
	tempShuriken.z = p_z;
	tempShuriken.dirX = p_dirX;
	tempShuriken.dirY = p_dirY;
	tempShuriken.dirZ = p_dirZ;
	tempShuriken.shurikenId = p_shurikenID;
	tempShuriken.guid = p_guid;
	tempShuriken.speed = p_speed;
	tempShuriken.megaShuriken = p_megaShuriken;

	for (unsigned int i = 0; i < m_shurikensList.size(); i++)
	{
		if (m_shurikensList[i].guid == tempShuriken.guid && m_shurikensList[i].shurikenId == tempShuriken.shurikenId)
		{
			addShuriken = false;
			break;
		}
	}
	if (addShuriken)
	{
		m_shurikensList.push_back(tempShuriken);
		m_shurikenListUpdated = true;
	}
}

std::vector<ShurikenNet> Network::GetShurikens()
{
	return m_shurikensList;
}std::vector<SmokeBombNet> Network::GetSmokeBombs()
{
	return m_smokeBombList;
}

RakNet::RakNetGUID Network::GetMyGUID()
{
	return m_clientPeer->GetMyGUID();
}

bool Network::IsPlayerListUpdated()
{
	return m_newOrRemovedPlayers;
}

void Network::SetHaveUpdatedPlayerList()
{
	m_newOrRemovedPlayers = false;
}

void Network::CheckForRemovedPlayers(std::vector<RakNet::RakNetGUID> p_playerGuids)
{
	for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
	{
		if (!(IsGuidInList(p_playerGuids, m_enemyPlayers[i].guid)))
		{
			m_enemyPlayers.erase(m_enemyPlayers.begin() + i);
			i--;
		}
	}
}

bool Network::IsGuidInList(std::vector<RakNet::RakNetGUID> p_playerGuids, RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < p_playerGuids.size(); i++)
	{
		if (p_guid == p_playerGuids[i])
		{
			return true;
		}
	}
	return false;
}

void Network::RemoveShuriken(unsigned int p_shurikenID)
{
	for (unsigned int i = 0; i < m_shurikensList.size(); i++)
	{
		if (m_shurikensList[i].shurikenId == p_shurikenID)
		{
			m_shurikensList.erase(m_shurikensList.begin() + i);
			m_shurikenListUpdated = true;
			break;
		}
	}
}
void Network::RemoveSmokeBomb(unsigned int p_smokeBombID)
{
	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		if (m_smokeBombList[i].smokeBombId == p_smokeBombID)
		{
			m_smokeBombList.erase(m_smokeBombList.begin() + i);
			m_smokebombListUpdated = true;
			break;
		}
	}
}
bool Network::IsSmokeBombListUpdated()
{
	return m_smokebombListUpdated;
}

void Network::SetHaveUpdateSmokeBombList()
{
	m_smokebombListUpdated = false;
}

bool Network::IsShurikenListUpdated()
{
	return m_shurikenListUpdated;
}
void Network::SetHaveUpdateShurikenList()
{
	m_shurikenListUpdated = false;
}

bool Network::HasRespawned()
{
	return m_respawned;
}

void Network::SetHaveRespawned()
{
	m_respawned = false;
}

void Network::RespawnPlayer(float p_x, float p_y, float p_z)
{
	m_myPlayer.x = p_x;
	m_myPlayer.y = p_y;
	m_myPlayer.z = p_z;
	m_respawned = true;
}

void Network::DoMeleeAttack()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_MELEE_ATTACK);
	
	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

bool Network::MadeInvalidMove()
{
	return m_invalidMove;
}

void Network::UpdatedMoveFromInvalidMove()
{
	m_invalidMove = false;
}

void Network::UpdatePlayerHP(RakNet::RakNetGUID p_guid, int p_currentHP, bool p_isAlive)
{
	if (p_guid == m_myPlayer.guid)
	{
		m_myPlayer.currentHP = p_currentHP;
		m_myPlayer.isAlive = p_isAlive;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (p_guid == m_enemyPlayers[i].guid)
			{
				m_enemyPlayers[i].currentHP = p_currentHP;
				m_enemyPlayers[i].isAlive = p_isAlive;
			}
		}
	}
}

void Network::UpdatePlayerHP(RakNet::RakNetGUID p_guid, int p_maxHP, int p_currentHP, bool p_isAlive)
{
	if (p_guid == m_myPlayer.guid)
	{
		m_myPlayer.maxHP = p_maxHP;
		m_myPlayer.currentHP = p_currentHP;
		m_myPlayer.isAlive = p_isAlive;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (p_guid == m_enemyPlayers[i].guid)
			{
				m_enemyPlayers[i].maxHP = p_maxHP;
				m_enemyPlayers[i].currentHP = p_currentHP;
				m_enemyPlayers[i].isAlive = p_isAlive;
			}
		}
	}
}

void Network::SendAbility(ABILITIES p_ability, float p_distanceFromPlayer)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_ABILITY);
	bitStream.Write(p_ability);
	bitStream.Write(p_distanceFromPlayer);


	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

bool Network::RoundRestarted()
{
	return m_roundRestarted;
}

void Network::SetHaveUpdatedAfterRestartedRound()
{
	m_roundRestarted = false;
}

bool Network::NewLevel()
{
	return m_newLevel;
}

void Network::SetHaveUpdateNewLevel()
{
	m_newLevel = false;
}

std::string Network::LevelName()
{
	return m_levelName;
}

NETWORKSTATUS Network::GetNetworkStatus()
{
	return m_networkStatus;
}

void Network::SetNetworkStatusConnecting()
{
	m_networkStatus = NETWORKSTATUS_CONNECTING;
}

void Network::SendAnimationState(AnimationState p_state)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_ANIMATION_CHANGED);
	bitStream.Write(p_state);

	m_clientPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

int Network::AnimationChanged(RakNet::RakNetGUID p_guid)
{
	if (!(m_playerAnimations.find(p_guid) == m_playerAnimations.end()))
	{
		AnimationState state = m_playerAnimations[p_guid];
		m_playerAnimations.erase(p_guid);
		return state;
	}
	return -1;
}

bool Network::HaveDashed()
{
	if (m_dashed)
	{
		m_dashed = false;
		return true;
	}

	return false;
}

DirectX::XMFLOAT3 Network::GetDashLocation()
{
	return m_dashLocation;
}