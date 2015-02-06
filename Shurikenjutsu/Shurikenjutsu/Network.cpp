#include "Network.h"
#include <iostream>
#include "ConsoleFunctions.h"
#include "ObjectManager.h"

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
	m_spikeTrapListUpdated = false;
	m_fanListUpdated = false;
	m_respawned = false;
	m_invalidMove = false;
	m_roundRestarted = false;
	m_newLevel = false;
	m_levelName = "";
	m_dashed = false;
	m_restartingRound = false;
	m_timeRestarting = 0;
	m_timerSynced = false;
	m_timerMin = 0;
	m_timerSec = 0;

	m_clientPeer = RakNet::RakPeerInterface::GetInstance();
	
	m_clientPeer->Startup(1, &m_socketDesc, 1);

	m_enemyPlayers = std::vector<PlayerNet>();
	m_shurikensList = std::vector<ShurikenNet>();
	m_fanList = std::vector<FanNet>();

	m_connectionCount = 0;
	m_previousCount = 0;

	m_networkStatus = NETWORKSTATUS_NONE;

	return true;
}

void Network::SetObjectManager(ObjectManager* p_objectManager)
{
	m_objectManager = p_objectManager;
}

void Network::Shutdown()
{
	m_clientPeer->Shutdown(300);
	RakNet::RakPeerInterface::DestroyInstance(m_clientPeer);

	delete m_instance;

	// Add delete objetmanager?

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
			float maxHP, currentHP;
			int team, charNr;;
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
				bitStream.Read(charNr);
				bitStream.Read(maxHP);
				bitStream.Read(currentHP);
				bitStream.Read(isAlive);

				// (Add and) update players position
				UpdatePlayerPos(guid, x, y, z);
				UpdatePlayerDir(guid, dirX, dirY, dirZ);
				UpdatePlayerHP(guid, maxHP, currentHP, isAlive);
				UpdatePlayerTeam(guid, team);
				UpdatePlayerChar(guid, charNr);

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
		case ID_PROJECTILE_THROWN:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float x, y, z;
			float dirX, dirY, dirZ;
			unsigned int uniqueId;
			int projType;
			float speed;

			bitStream.Read(messageID);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);
			bitStream.Read(projType);
			bitStream.Read(uniqueId);
			bitStream.Read(guid);
			bitStream.Read(speed);

			ProjectileThrown(x, y, z, dirX, dirY, dirZ, uniqueId, guid, speed, projType);
			break;
		}
		case ID_PROJECTILE_REMOVE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int uniqueId;
			bitStream.Read(messageID);
			bitStream.Read(uniqueId);

			RemoveShuriken(uniqueId);

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
			float currentHP;
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
			m_restartingRound = false;
			m_timeRestarting = 0;
			std::cout << "New round has started\n";
			break;
		}
		case ID_RESTARTING_ROUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);
			m_restartingRound = true;

			std::cout << "Restarting round in:\n";
			break;
		}
		case ID_RESTARTING_ROUND_TIMER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int time;

			bitStream.Read(messageID);
			bitStream.Read(time);

			m_timeRestarting = time;

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
		case ID_SPIKETRAP_THROW:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			unsigned int spikeTrapId;
			float startPosX, startPosZ, endPosX, endPosZ, lifetime;
			bitStream.Read(messageID);
			bitStream.Read(spikeTrapId);
			bitStream.Read(startPosX);
			bitStream.Read(startPosZ);
			bitStream.Read(endPosX);
			bitStream.Read(endPosZ);
			bitStream.Read(lifetime);
			bitStream.Read(guid);


			UpdateSpikeTrap(guid, spikeTrapId, startPosX, startPosZ, endPosX, endPosZ, lifetime);
			break;
		}
		case ID_SPIKETRAP_REMOVE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int spikeTrapId;
			bitStream.Read(messageID);
			bitStream.Read(spikeTrapId);

			RemoveSpikeTrap(spikeTrapId);
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
		case ID_FAN_THROWN:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float x, y, z;
			float dirX, dirY, dirZ;
			unsigned int id;
			float speed;

			bitStream.Read(messageID);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);
			bitStream.Read(dirX);
			bitStream.Read(dirY);
			bitStream.Read(dirZ);
			bitStream.Read(id);
			bitStream.Read(guid);
			bitStream.Read(speed);

			AddFans(x, y, z, dirX, dirY, dirZ, id, guid, speed);
			break;
		}
		case ID_FAN_UPDATE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			float x, y, z;
			float dirX, dirY, dirZ;
			unsigned int id;
			float speed;
			int nrOfFans;

			bitStream.Read(messageID);
			bitStream.Read(nrOfFans);

			for (int i = 0; i < nrOfFans; i++)
			{
				bitStream.Read(id);
				bitStream.Read(x);
				bitStream.Read(y);
				bitStream.Read(z);
				bitStream.Read(dirX);
				bitStream.Read(dirY);
				bitStream.Read(dirZ);
				bitStream.Read(speed);

				for (unsigned int j = 0; j < m_fanList.size(); j++)
				{
					if (id == m_fanList[j].id)
					{
						m_fanList[j].dirX = dirX;
						m_fanList[j].dirY = dirY;
						m_fanList[j].dirZ = dirZ;
						m_fanList[j].speed = speed;
						m_fanList[j].x = x;
						m_fanList[j].y = y;
						m_fanList[j].z = z;
					}
				}
			}
			break;
		}
		case ID_FAN_REMOVE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int fanId;
			bitStream.Read(messageID);
			bitStream.Read(fanId);
			RemoveFan(fanId);
			break;
		}
		case ID_TIMER_SYNC:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			double sec, min;
			bitStream.Read(messageID);
			bitStream.Read(min);
			bitStream.Read(sec);

			m_timerSynced = true;
			m_timerMin = min;
			m_timerSec = sec;
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

void Network::ChooseChar(int p_charNr)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_CHOOSE_CHAR);
	bitStream.Write(p_charNr);

	m_clientPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);

	m_myPlayer.charNr = p_charNr;
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

void Network::UpdatePlayerChar(RakNet::RakNetGUID p_owner, int p_charNr)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.charNr = p_charNr;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].charNr = p_charNr;
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

void Network::UpdateSpikeTrap(RakNet::RakNetGUID p_guid, unsigned int p_spikeTrapId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime)
{

	bool addSpikeTrap = true;
	SpikeNet temp;
	temp.spikeId = p_spikeTrapId;
	temp.startX = p_startPosX;
	temp.startZ = p_startPosZ;
	temp.endX = p_endPosX;
	temp.endZ = p_endPosZ;
	temp.lifeTime = p_lifetime;
	temp.guid = p_guid;

	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		if (m_spikeTrapList[i].spikeId == temp.spikeId)
		{
			addSpikeTrap = false;
			break;
		}
	}
	if (addSpikeTrap)
	{
		m_spikeTrapList.push_back(temp);
		m_spikeTrapListUpdated = true;
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

void Network::AddFans(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_id, RakNet::RakNetGUID p_guid, float p_speed)
{
	bool add = true;
	FanNet temp;
	temp = FanNet();
	temp.x = p_x;
	temp.y = p_y;
	temp.z = p_z;
	temp.dirX = p_dirX;
	temp.dirY = p_dirY;
	temp.dirZ = p_dirZ;
	temp.id = p_id;
	temp.guid = p_guid;
	temp.speed = p_speed;

	for (unsigned int i = 0; i < m_fanList.size(); i++)
	{
		if (m_fanList[i].guid == temp.guid && m_fanList[i].id == temp.id)
		{
			add = false;
			break;
		}
	}
	if (add)
	{
		m_fanList.push_back(temp);
		m_fanListUpdated = true;
	}
}

std::vector<ShurikenNet> Network::GetShurikens()
{
	return m_shurikensList;
}

std::vector<SmokeBombNet> Network::GetSmokeBombs()
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

void Network::RemoveFan(unsigned int p_id)
{
	for (unsigned int i = 0; i < m_fanList.size(); i++)
	{
		if (m_fanList[i].id == p_id)
		{
			m_fanList.erase(m_fanList.begin() + i);
			m_fanListUpdated = true;
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

void Network::RemoveSpikeTrap(unsigned int p_spikeId)
{
	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		if (m_spikeTrapList[i].spikeId == p_spikeId)
		{
			m_spikeTrapList.erase(m_spikeTrapList.begin() + i);
			m_spikeTrapListUpdated = true;
			break;
		}
	}
}

bool Network::IsSmokeBombListUpdated()
{
	return m_smokebombListUpdated;
}

bool Network::IsSpikeTrapListUpdated()
{
	return m_spikeTrapListUpdated;
}

void Network::SetHaveUpdateSpikeTrapList()
{
	m_spikeTrapListUpdated = false;
}

std::vector<SpikeNet> Network::GetSpikeTraps()
{
	return m_spikeTrapList;
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

void Network::UpdatePlayerHP(RakNet::RakNetGUID p_guid, float p_currentHP, bool p_isAlive)
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

void Network::UpdatePlayerHP(RakNet::RakNetGUID p_guid, float p_maxHP, float p_currentHP, bool p_isAlive)
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

bool Network::IsFanListUpdated()
{
	return m_fanListUpdated;
}

void Network::SetHaveUpdateFanList()
{
	m_fanListUpdated = false;
}

std::vector<FanNet> Network::GetFanList()
{
	return m_fanList;
}

void Network::ProjectileThrown(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_uniqueId, RakNet::RakNetGUID p_guid, float p_speed, int p_projType)
{
	m_objectManager->AddProjectile(p_x, p_y, p_z, p_dirX, p_dirY, p_dirZ, p_uniqueId, p_guid, p_speed, p_projType);
}

bool Network::RoundRestarting()
{
	return m_restartingRound;
}

int Network::GetRestartingTimer()
{
	return m_timeRestarting;
}

void Network::SyncTimer()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_TIMER_SYNC);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

bool Network::TimerSynced(double &p_min, double &p_sec)
{
	if (m_timerSynced)
	{
		m_timerSynced = false;
		p_min = m_timerMin;
		p_sec = m_timerSec;
		return true;
	}
	else
	{
		p_min = 0;
		p_sec = 0;
		return false;
	}
}