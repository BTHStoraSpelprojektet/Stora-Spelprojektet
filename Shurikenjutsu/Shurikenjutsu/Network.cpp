#include "Network.h"
#include <iostream>
#include "ConsoleFunctions.h"
#include "ObjectManager.h"
#include "Globals.h"
#include "DeathBoard.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "ScoreBoard.h"

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
	

	m_clientPeer = RakNet::RakPeerInterface::GetInstance();	
	m_clientPeer->Startup(1, &m_socketDesc, 1);

	m_networkLogger = NetworkLogger();
	m_networkLogger.Initialize();
	m_clientPeer->AttachPlugin(&m_networkLogger);

	InitValues();

	return true;
}

void Network::InitValues()
{
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
	m_redTeamScore = 0;
	m_blueTeamScore = 0;
	m_lastTeamWon = 0;
	m_matchOver = false;
	m_matchWinningTeam = 0;
	m_suddenDeath = false;
	m_suddenDeathBoxIndex = 99;

	m_enemyPlayers = std::vector<PlayerNet>();
	m_shurikensList = std::vector<ShurikenNet>();
	m_fanList = std::vector<FanNet>();
	m_visibleEnemies = std::vector<int>();

	m_connectionCount = 0;
	m_previousCount = 0;

	m_networkStatus = NETWORKSTATUS_NONE;

	m_pingTimer = 5.0;
	m_timeToPing = m_pingTimer;
	m_dealtDamage = 0;

	m_posTimer = 0.01;
	m_timeToSendPos = 0.0;
}

void Network::SetObjectManager(ObjectManager* p_objectManager)
{
	m_objectManager = p_objectManager;
}

void Network::SetSound(Sound* p_sound){
	m_sound = p_sound;
}

void Network::Shutdown()
{
	m_clientPeer->Shutdown(300);
	RakNet::RakPeerInterface::DestroyInstance(m_clientPeer);
	m_clientPeer = nullptr;
	
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}

	// Add delete objetmanager?

}

void Network::Update()
{
	m_prevConnected = m_connected;
	ReceviePacket();
	m_networkLogger.Update(GLOBAL::GetInstance().GetDeltaTime());

	// Ping
	m_timeToPing -= GLOBAL::GetInstance().GetDeltaTime();
	if (m_timeToPing < 0.0)
	{
		m_clientPeer->Ping(RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT));
		m_timeToPing = m_pingTimer;
	}

	// Pos and dir
	m_timeToSendPos -= GLOBAL::GetInstance().GetDeltaTime();
	if (m_timeToSendPos < 0.0)
	{
		// Send pos
		if (m_sendPos)
		{
			SendLatestPos();
		}

		// Send dir
		if (m_sendDir)
		{
			SendLatestDir();
		}

		// Send visible
		SendVisiblePlayers();

		m_timeToSendPos = m_posTimer;
	}
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

			RakNet::RakString name;
			int nrOfPlayers = 0;
			float x, y, z;
			float dirX, dirY, dirZ;
			float maxHP, currentHP, shield;
			int team, charNr, toolNr, kills, deaths;
			bool isAlive, invis;
			RakNet::RakNetGUID guid;
			int id;
			std::vector<RakNet::RakNetGUID> playerGuids = std::vector<RakNet::RakNetGUID>();
			bitStream.Read(messageID);
			bitStream.Read(nrOfPlayers);

			for (int i = 0; i < nrOfPlayers; i++)
			{
				bitStream.Read(guid);
				bitStream.Read(id);
				bitStream.Read(name);
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
				bitStream.Read(invis);
				bitStream.Read(toolNr);
				bitStream.Read(deaths);
				bitStream.Read(kills);
				bitStream.Read(shield);


				// (Add and) update players position
				UpdatePlayerPos(guid, x, y, z);
				UpdatePlayerDir(guid, dirX, dirY, dirZ);
				UpdatePlayerHP(guid, maxHP, currentHP, isAlive);
				UpdatePlayerTeam(guid, team);
				UpdatePlayerChar(guid, charNr, toolNr);
				UpdatePlayerID(guid, id);
				UpdatePlayerKD(guid, deaths, kills);
				UpdatePlayerInvis(guid, invis);
				UpdatePlayerShield(guid, shield);
				UpdatePlayerName(guid, name);

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

			RemoveProjectile(uniqueId);

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
			UpdatePlayerInvisAll(false);

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
			UpdatePlayerInvis(guid, false);
			SpawnBloodParticles(guid);
			break;
		}
		case ID_ROUND_OVER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int winningTeam;

			bitStream.Read(messageID);
			bitStream.Read(winningTeam);

			// Team 1 = red
			// Team 2 = blue
			if (winningTeam == 1)
			{
				m_redTeamScore++;

				ConsolePrintText("The red team won this round!");
				ConsoleSkipLines(1);
			}
			else if (winningTeam == 2)
			{
				m_blueTeamScore++;

				ConsolePrintText("The blue team won this round!");
				ConsoleSkipLines(1);
			}
			m_lastTeamWon = winningTeam;

			break;
		}
		case ID_RESTARTED_ROUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);

			m_roundRestarted = true;
			m_restartingRound = false;
			m_timeRestarting = 0;
			ClearListsAtNewRound();

			m_sound->CreateDefaultSound(PLAYSOUND_COUNTDOWN_GONG_SOUND, 0, 0, 0);
			ConsolePrintSuccess("A new round has started!");
			ConsoleSkipLines(1);
			break;

		}
		case ID_RESTARTING_ROUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);
			m_restartingRound = true;
			
			ConsolePrintText("Next round starts in: ");
			ConsoleSkipLines(1);
			m_suddenDeath = false;
			break;
		}
		case ID_RESTARTING_ROUND_TIMER:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int time;

			bitStream.Read(messageID);
			bitStream.Read(time);

			m_timeRestarting = time;

			if (time <= 5 && time != 0){
				m_sound->CreateDefaultSound(PLAYSOUND_COUNTDOWN_BEEP_SOUND, 0, 0, 0);
			}
			ConsolePrintText(std::to_string(time) + "...");
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

			m_matchOver = true;
			m_matchWinningTeam = winningTeam;

			if (winningTeam == 1)
			{
				ConsolePrintText("The red team won this match!");
				ConsoleSkipLines(1);
			}

			else
			{
				ConsolePrintText("The blue team won this match!");
				ConsoleSkipLines(1);
			}

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
			m_redTeamScore = 0;
			m_blueTeamScore = 0;
			m_matchOver = false;
			m_matchWinningTeam = 0;
			m_restartingRound = false;

			RakNet::BitStream wBitStream;
			wBitStream.Write((RakNet::MessageID)ID_DOWNLOAD_PLAYERS);
			m_clientPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE, 0, m_packet->guid, false);

			m_sound->CreateDefaultSound(PLAYSOUND_COUNTDOWN_GONG_SOUND, 0, 0, 0);
			ConsolePrintSuccess("Starting a new match.");
			ConsoleSkipLines(1);
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

			// TODO, update local player animation.
			m_playerAnimations[guid] = state;
			break;
		}
		case ID_SPIKETRAP_THROW:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			unsigned int spikeTrapId;
			float startPosX, startPosZ, endPosX, endPosZ, lifetime;
			int team;
			bitStream.Read(messageID);
			bitStream.Read(spikeTrapId);
			bitStream.Read(startPosX);
			bitStream.Read(startPosZ);
			bitStream.Read(endPosX);
			bitStream.Read(endPosZ);
			bitStream.Read(lifetime);
			bitStream.Read(guid);
			bitStream.Read(team);


			UpdateSpikeTrap(guid, spikeTrapId, startPosX, startPosZ, endPosX, endPosZ, lifetime, team);
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
			float x, z;
			unsigned int id;
			int nrOfFans;

			bitStream.Read(messageID);
			bitStream.Read(nrOfFans);

			for (int i = 0; i < nrOfFans; i++)
			{
				bitStream.Read(id);
				bitStream.Read(x);
				bitStream.Read(z);

				for (unsigned int j = 0; j < m_fanList.size(); j++)
				{
					if (m_fanList[j].id == id)
					{
						m_fanList[j].x = x;
						m_fanList[j].z = z;
						break;
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
		case ID_FAN_DEAD_UPDATE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			float lifeTime;
			unsigned int id;
			bitStream.Read(messageID);
			bitStream.Read(id);
			bitStream.Read(lifeTime);

			UpdateFanLifeTime(id, lifeTime);
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
		case ID_STICKYTRAP_THROW:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID guid;
			unsigned int stickyTrapID;
			float startPosX, startPosZ, endPosX, endPosZ, lifetime;
			bitStream.Read(messageID);
			bitStream.Read(stickyTrapID);
			bitStream.Read(startPosX);
			bitStream.Read(startPosZ);
			bitStream.Read(endPosX);
			bitStream.Read(endPosZ);
			bitStream.Read(lifetime);
			bitStream.Read(guid);


			UpdateStickyTrap(guid, stickyTrapID, startPosX, startPosZ, endPosX, endPosZ, lifetime);
			break;
		}
		case ID_STICKYTRAP_REMOVE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned int stickyTrapID;
			bitStream.Read(messageID);
			bitStream.Read(stickyTrapID);

			RemoveStickyTrap(stickyTrapID);
			break;
		}
		case ID_SEND_TEAM_SCORE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			m_redTeamScore = 0;
			m_blueTeamScore = 0;

			unsigned int size;
			int team, score;

			bitStream.Read(messageID);
			bitStream.Read(size);

			for (unsigned int i = 0; i < size; i++)
			{
				bitStream.Read(team);
				bitStream.Read(score);

				// Team 1 = red
				// Team 2 = blue
				if (team == 1)
				{
					m_redTeamScore = score;
				}
				else if (team == 2)
				{
					m_blueTeamScore = score;
				}
			}
			break;
		}
		case ID_NAGINATA_STAB_HAS_OCCURED:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			//TODO: Implement set cooldown for player;

			RakNet::RakNetGUID guid;
			bitStream.Read(messageID);
			bitStream.Read(guid);

			if (m_myPlayer.guid == guid)
			{
				m_NaginataStabPerformed = true;
			}

			break;
		}
		case ID_VOLLEY_THROWN:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			unsigned int id;
			float startX, startZ, endX, endZ;
			RakNet::RakNetGUID guid;
			bitStream.Read(messageID);
			bitStream.Read(id);
			bitStream.Read(startX);
			bitStream.Read(startZ);
			bitStream.Read(endX);
			bitStream.Read(endZ);
			bitStream.Read(guid);

			AddVolley(id, startX, startZ, endX, endZ, guid);
			break;
		}
		case ID_HAS_INFLICTED_DAMAGE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			float damage, x,y,z;
			RakNet::RakNetGUID guid;
			bitStream.Read(messageID);
			bitStream.Read(guid);
			bitStream.Read(damage);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			m_dealtDamage = damage;
			m_dealtDamagePosition = DirectX::XMFLOAT3(x, y, z);
			break;
		}		
		case ID_PLAYER_MOVE_AND_ROTATE:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			unsigned char id;
			signed short mantissa1;
			signed char mantissa2;
			signed char exp;
			float posX, posZ;
			float dirX, dirZ;

			bitStream.Read(messageID);
			bitStream.Read(id);

			// pos x
			bitStream.Read(mantissa1);
			bitStream.Read(exp);
			posX = ((float)mantissa1 / 10000.0f) * powf(2.0f, (float)exp);

			// pos z
			bitStream.Read(mantissa1);
			bitStream.Read(exp);
			posZ = ((float)mantissa1 / 10000.0f) * powf(2.0f, (float)exp);

			// dir x
			bitStream.Read(mantissa2);
			bitStream.Read(exp);
			dirX = ((float)mantissa2 / 100.0f) * powf(2.0f, (float)exp);

			// dir z
			bitStream.Read(mantissa2);
			bitStream.Read(exp);
			dirZ = ((float)mantissa2 / 100.0f) * powf(2.0f, (float)exp);

			UpdatePlayerPos((int)id, posX, 0.0f, posZ);
			UpdatePlayerDir((int)id, dirX, 0.0f, dirZ);
			break;
		}
		case ID_DEATHBOARDKILL:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID takerNinja, killerNinja;
			ABILITIES murderWeapon;

			bitStream.Read(messageID);
			bitStream.Read(takerNinja);
			bitStream.Read(killerNinja);
			bitStream.Read(murderWeapon);

			DeathBoard::GetInstance()->KillHappened(killerNinja, takerNinja, murderWeapon);

			break;
		}
		case ID_PLAY_SOUND_ABILITY:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			
			ABILITIES ability;
			float x, y, z;

			bitStream.Read(messageID);
			bitStream.Read(ability); 
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			//float distance = sqrtf(((m_myPlayer.x - x)*(m_myPlayer.x - x) + (m_myPlayer.z - z)*(m_myPlayer.z - z)));
			//float soundDistanceGain = 4.0f;

			//Hit sounds
			switch (ability)
			{
			case ABILITIES::ABILITIES_SHURIKEN:
			{
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_MEGASHURIKEN:
			{
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_MEGA_SHURIKEN_HIT_SOUND, x, y, z);
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				break;
			}
			case ABILITIES::ABILITIES_KUNAI:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_KUNAI_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_KUNAI_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_MELEESWING:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_KATANA_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_KATANA_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_WHIP_PRIMARY:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_WHIP_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_WHIP_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_WHIP_SECONDARY:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_WHIP_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_WHIP_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_NAGINATASLASH:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_NAGINATA_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_NAGINATA_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_NAGAINATASTAB:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_NAGINATA_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_NAGINATA_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_VOLLEY:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_VOLLEY_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_VOLLEY_HIT_SOUND, x, y, z);
				break;
			}
			case ABILITIES::ABILITIES_FANBOOMERANG:
			{
				//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_SOUND, 1.0f / (distance / soundDistanceGain));
				m_sound->CreateDefaultSound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_SOUND, x, y, z);
				break;
			}
			default:
			{
				break;
			}
			}

			//DeathBoard::GetInstance()->KillHappened(killerNinja, takerNinja, murderWeapon);

			break;
		}
		case ID_PLAY_SOUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			PLAYSOUND sound;
			float x, y, z;

			bitStream.Read(messageID);
			bitStream.Read(sound);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			/*float distance = sqrtf(((m_myPlayer.x - x)*(m_myPlayer.x - x)) + ((m_myPlayer.z - z)*(m_myPlayer.z - z)));
			float soundDistanceGain = 4.0f;
			
			//Hit sounds
			if (distance == 0){
				m_sound->PlaySound(sound, 1.0f);
			}
			else{
				m_sound->PlaySound(sound, 1.0f / (distance / soundDistanceGain));
			}*/

			if (m_sound != NULL){
			m_sound->CreateDefaultSound(sound, x, y, z);
			}

			//DeathBoard::GetInstance()->KillHappened(killerNinja, takerNinja, murderWeapon);

			break;
		}

		case ID_PLAY_AMBIENT_SOUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			PLAYSOUND sound;
			float x, y, z;

			bitStream.Read(messageID);
			bitStream.Read(sound);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);
			Sound::SoundEmitter* soundEmitter;

			if (m_sound != NULL){
				soundEmitter = m_sound->CreateAmbientSound(sound, x, y, z);
			}
			break;
		}

		case ID_STOP_AMBIENT_SOUND:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			PLAYSOUND sound;
			float x, y, z;

			bitStream.Read(messageID);
			bitStream.Read(sound);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);

			if (m_sound != NULL){
				m_sound->CreateAmbientSound(sound, x, y, z);
			}

			break;
		}

		case ID_SCOREBOARDKILL:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			RakNet::RakNetGUID takerNinja, killerNinja;
			int kills, deaths;

			bitStream.Read(messageID);
			bitStream.Read(takerNinja);
			bitStream.Read(killerNinja);
			bitStream.Read(deaths);
			bitStream.Read(kills);

			ScoreBoard::GetInstance()->KillDeathRatio(killerNinja, takerNinja, deaths, kills);

			break;
		}

		case ID_START_SUDDEN_DEATH:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			bitStream.Read(messageID);
			m_suddenDeath = true;

			break;
		}
		case ID_INITIATE_SUDDEN_DEATH_BOX:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);

			int boxIndex = 0;
			bitStream.Read(messageID);
			bitStream.Read(boxIndex);
			m_suddenDeathBoxIndex = boxIndex;

			break;
		}
		case ID_SPAWN_RUNES:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			RakNet::RakNetGUID guid;
			POINTOFINTERESTTYPE poi_type;
			float x, y, z;
			bitStream.Read(messageID);
			for (int i = 0; i < 3; i++)
			{
				bitStream.Read(poi_type);
				bitStream.Read(x);
				bitStream.Read(y);
				bitStream.Read(z);
				SpawnRunes(poi_type, x, y, z);
				//SpawnRunes(0, 0, 0, 10 * i);
			}

			break;
		}
		case ID_RUNE_PICKED_UP:
		{
			/*RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			RakNet::RakNetGUID guid;
			bitStream.Read(messageID);
			bitStream.Read(sound);
			bitStream.Read(x);
			bitStream.Read(y);
			bitStream.Read(z);*/
			break;
		}
		case ID_LOTUS_PICKED_UP:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			RakNet::RakNetGUID guid;
			bitStream.Read(messageID);
			bitStream.Read(guid);
			//bitStream.Read(sound); Add sound
			RunePickedUp(POINTOFINTERESTTYPE_HEAL, guid);
			break;
		}
		case ID_INVIS_PICKED_UP:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			RakNet::RakNetGUID guid;
			bitStream.Read(messageID);
			bitStream.Read(guid);
			//bitStream.Read(sound); Add sound
			RunePickedUp(POINTOFINTERESTTYPE_INVISIBLE, guid);
			RuneInvisPickedUp(guid);
			break;
		}
		case ID_SHIELD_PICKED_UP:
		{
			RakNet::BitStream bitStream(m_packet->data, m_packet->length, false);
			RakNet::RakNetGUID guid;
			bitStream.Read(messageID);
			bitStream.Read(guid);
			//bitStream.Read(sound); Add sound
			RunePickedUp(POINTOFINTERESTTYPE_SHIELD, guid);
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
	ConsolePrintText("Connecting to IP (v4): " + p_ip);
	ConsoleSkipLines(1);

	m_ip = p_ip;
	m_clientPeer->Connect(m_ip.c_str(), SERVER_PORT, 0, 0);
}

void Network::Disconnect()
{
	ConsolePrintText("Disconnected from server");
	ConsoleSkipLines(1);

	m_clientPeer->Shutdown(300);
	m_clientPeer->Startup(1, &m_socketDesc, 1);

	InitValues();
}

void Network::ChooseChar(int p_charNr, int p_toolNr, int p_team)
{
	RakNet::BitStream bitStream;
	RakNet::RakString name = m_playerName.c_str();

	bitStream.Write((RakNet::MessageID)ID_CHOOSE_CHAR);
	bitStream.Write(name);
	bitStream.Write(p_charNr);
	bitStream.Write(p_toolNr);
	bitStream.Write(p_team);

	m_clientPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 0, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);

	m_myPlayer.charNr = p_charNr;
	m_myPlayer.toolNr = p_toolNr;
	m_myPlayer.name = name;
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
	m_latestPos.x = p_x;
	m_latestPos.y = p_y;
	m_latestPos.z = p_z;
	m_sendPos = true;
}

void Network::SendPlayerDir(float p_dirX, float p_dirY, float p_dirZ)
{
	m_latestDir.x = p_dirX;
	m_latestDir.y = p_dirY;
	m_latestDir.z = p_dirZ;
	m_sendDir = true;
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

void Network::UpdatePlayerPos(int p_id, float p_x, float p_y, float p_z)
{
	if (p_id == m_myPlayer.id)
	{
		m_myPlayer.x = p_x;
		m_myPlayer.y = p_y;
		m_myPlayer.z = p_z;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].id == p_id)
			{
				m_enemyPlayers[i].x = p_x;
				m_enemyPlayers[i].y = p_y;
				m_enemyPlayers[i].z = p_z;

				break;
			}
		}
	}
}

void Network::UpdatePlayerKD(RakNet::RakNetGUID p_owner, int p_deaths, int p_kills)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.kills = p_kills;
		m_myPlayer.deaths = p_deaths;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].kills = p_kills;
				m_enemyPlayers[i].deaths = p_deaths;
				break;
			}
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

void Network::UpdatePlayerDir(int p_id, float p_dirX, float p_dirY, float p_dirZ)
{
	if (p_id == m_myPlayer.id)
	{
		m_myPlayer.dirX = p_dirX;
		m_myPlayer.dirY = p_dirY;
		m_myPlayer.dirZ = p_dirZ;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].id == p_id)
			{
				m_enemyPlayers[i].dirX = p_dirX;
				m_enemyPlayers[i].dirY = p_dirY;
				m_enemyPlayers[i].dirZ = p_dirZ;
				break;
			}
		}
	}
}

void Network::UpdatePlayerID(RakNet::RakNetGUID p_owner, int p_id)
{
	if (p_owner == m_clientPeer->GetMyGUID())
	{
		m_myPlayer.id = p_id;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_owner)
			{
				m_enemyPlayers[i].id = p_id;
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

void Network::UpdatePlayerChar(RakNet::RakNetGUID p_owner, int p_charNr, int p_toolNr)
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
				m_enemyPlayers[i].toolNr = p_toolNr;
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
	
	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
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

void Network::UpdateSpikeTrap(RakNet::RakNetGUID p_guid, unsigned int p_spikeTrapId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime, int p_team)
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
	temp.team = p_team;

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

void Network::UpdateStickyTrap(RakNet::RakNetGUID p_guid, unsigned int p_stickyTrapId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime)
{
	bool addStickyTrap = true;
	StickyTrapNet temp;
	temp.stickyTrapId = p_stickyTrapId;
	temp.startX = p_startPosX;
	temp.startZ = p_startPosZ;
	temp.endX = p_endPosX;
	temp.endZ = p_endPosZ;
	temp.lifeTime = p_lifetime;
	temp.guid = p_guid;

	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		if (m_stickyTrapList[i].stickyTrapId == temp.stickyTrapId)
		{
			addStickyTrap = false;
			break;
		}
	}
	if (addStickyTrap)
	{
		m_stickyTrapList.push_back(temp);
		m_stickyTrapListUpdated = true;
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
	temp.lifeTime = FANBOOMERANG_COOLDOWN;

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

void Network::RemoveStickyTrap(unsigned int p_stickyTrapID)
{
	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		if (m_stickyTrapList[i].stickyTrapId == p_stickyTrapID)
		{
			m_stickyTrapList.erase(m_stickyTrapList.begin() + i);
			m_stickyTrapListUpdated = true;
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

bool Network::IsStickyTrapListUpdated()
{
	return m_stickyTrapListUpdated;
}

void Network::SetHaveUpdateStickyTrapList()
{
	m_stickyTrapListUpdated = false;
}

std::vector<StickyTrapNet> Network::GetStickyTrapList()
{
	return m_stickyTrapList;
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
	
	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
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

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
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

	m_clientPeer->Send(&bitStream, MEDIUM_PRIORITY, UNRELIABLE, 5, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
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

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 4, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
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

void Network::SyncTeamScore()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SEND_TEAM_SCORE);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 4, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

int Network::GetRedTeamScore()
{
	return m_redTeamScore;
}

int Network::GetBlueTeamScore()
{
	return m_blueTeamScore;
}

int Network::GetLastWinningTeam()
{
	return m_lastTeamWon;
}

void Network::RemoveProjectile(unsigned int p_projId)
{
	m_objectManager->RemoveProjectile(p_projId);
}

bool Network::CheckIfNaginataStabAttackIsPerformed()
{
	return m_NaginataStabPerformed;
}

void Network::ResetNaginataStabBoolean()
{
	m_NaginataStabPerformed = false;
}

void Network::AddVolley(unsigned int p_id, float p_startX, float p_startZ, float p_endX, float p_endZ, RakNet::RakNetGUID p_guid)
{
	m_objectManager->AddVolley(p_id, p_startX, p_startZ, p_endX, p_endZ, p_guid);
}

bool Network::GetMatchOver()
{
	return m_matchOver;
}

int Network::GetMatchWinningTeam()
{
	return m_matchWinningTeam;
}

void Network::ClearListsAtNewRound()
{
	m_shurikensList.clear();
	m_smokeBombList.clear();
	m_spikeTrapList.clear();
	m_stickyTrapList.clear();
	m_fanList.clear();
	m_objectManager->RunesRestartRound();
}

int Network::GetLastPing()
{
	return m_clientPeer->GetLastPing(RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT));
}

DealtDamageStruct Network::GetDealtDamage()
{
	DealtDamageStruct temp;
	temp.m_damage = m_dealtDamage;
	temp.m_position = m_dealtDamagePosition;

	m_dealtDamage = 0;
	m_dealtDamagePosition = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	return temp;
}

void Network::UpdateFanLifeTime(unsigned int p_id, float p_lifeTime)
{
	for (unsigned int i = 0; i < m_fanList.size(); i++)
	{
		if (m_fanList[i].id == p_id)
		{
			m_fanList[i].lifeTime = p_lifeTime;
			break;
		}
	}
}

void Network::SpawnBloodParticles(RakNet::RakNetGUID p_guid)
{
	// Check if spawn blood on player or enemies
	if (m_myPlayer.guid == p_guid)
	{
		m_objectManager->AddBloodSpots(DirectX::XMFLOAT3(m_myPlayer.x, m_myPlayer.y, m_myPlayer.z));
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_guid)
			{
				m_objectManager->AddBloodSpots(DirectX::XMFLOAT3(m_enemyPlayers[i].x, m_enemyPlayers[i].y, m_enemyPlayers[i].z));
			} 
		}
	}
}

int Network::GetTeam(RakNet::RakNetGUID p_guid)
{
	if (m_myPlayer.guid == p_guid)
	{
		return m_myPlayer.team;
	}

	for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
	{
		if (m_enemyPlayers[i].guid == p_guid)
		{
			return m_enemyPlayers[i].team;
		}
	}

	return -1;
}

bool Network::IsSuddenDeath()
{
	return m_suddenDeath;
}

int Network::GetSuddenDeathBoxIndex()
{
	int temp = m_suddenDeathBoxIndex;
	m_suddenDeathBoxIndex = 99;
	return temp;
}

void Network::SendLatestPos()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_MOVED);
	bitStream.Write(m_latestPos.x);
	bitStream.Write(m_latestPos.y);
	bitStream.Write(m_latestPos.z);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, UNRELIABLE_SEQUENCED, 1, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

void Network::SendLatestDir()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PLAYER_ROTATED);
	bitStream.Write(m_latestDir.x);
	bitStream.Write(m_latestDir.y);
	bitStream.Write(m_latestDir.z);

	m_clientPeer->Send(&bitStream, HIGH_PRIORITY, UNRELIABLE, 2, RakNet::SystemAddress(m_ip.c_str(), SERVER_PORT), false);
}

void Network::SpawnRunes(POINTOFINTERESTTYPE p_poiType, float p_x, float p_y, float p_z)
{
	m_objectManager->SpawnRunes(p_poiType, p_x, p_y, p_z);

	Sound::SoundEmitter* soundEmitter = NULL;
	switch (p_poiType)
	{
	case POINTOFINTERESTTYPE_HEAL:
	{
		m_sound->CreateDefaultSound(PLAYSOUND_RUNE_HEAL_SPAWN_SOUND, p_x, p_y, p_z);
		soundEmitter = m_sound->CreateDefaultSound(PLAYSOUND_RUNE_HEAL_SOUND, p_x, p_y, p_z);
		break;
	}
	case POINTOFINTERESTTYPE_SHIELD:
	{
		m_sound->CreateDefaultSound(PLAYSOUND_RUNE_SHIELD_SPAWN_SOUND, p_x, p_y, p_z);
		soundEmitter = m_sound->CreateDefaultSound(PLAYSOUND_RUNE_SHIELD_SOUND, p_x, p_y, p_z);
		break;
	}
	case POINTOFINTERESTTYPE_INVISIBLE:
	{
		m_sound->CreateDefaultSound(PLAYSOUND_RUNE_INVISIBLE_SPAWN_SOUND, p_x, p_y, p_z);
		soundEmitter = m_sound->CreateDefaultSound(PLAYSOUND_RUNE_INVISIBLE_SOUND, p_x, p_y, p_z);
		break;
	}
	default:
	{
		break;
	}
	}
	//Only support sound for one rune per type for now
	runeSoundEmitters.push_back(soundEmitter);
}

void Network::RunePickedUp(POINTOFINTERESTTYPE p_poiType, RakNet::RakNetGUID p_guid)
{
	//Only support sound for one rune per type for now
	if (m_sound != nullptr){
		for (unsigned int i = 0; i < runeSoundEmitters.size(); i++)
		{
			switch (p_poiType)
			{
			case POINTOFINTERESTTYPE_HEAL:
			{
				if (PLAYSOUND_RUNE_HEAL_SOUND == runeSoundEmitters[i]->m_playSound){
					m_sound->StopAmbientSound(runeSoundEmitters[i]);
				}
				break;
			}
			case POINTOFINTERESTTYPE_SHIELD:
			{
				if (PLAYSOUND_RUNE_SHIELD_SOUND == runeSoundEmitters[i]->m_playSound){
					m_sound->StopAmbientSound(runeSoundEmitters[i]);
				}
				break;
			}
			case POINTOFINTERESTTYPE_INVISIBLE:
			{
				if (PLAYSOUND_RUNE_INVISIBLE_SOUND == runeSoundEmitters[i]->m_playSound){
					m_sound->StopAmbientSound(runeSoundEmitters[i]);
				}
				break;
			}
			default:
			{
				break;
			}
			}
		}
		
	}

	m_objectManager->RunePickedUp(p_poiType, p_guid);
	if (m_myPlayer.guid == p_guid){
		m_myPlayer.x;
	}
}

void Network::RuneInvisPickedUp(RakNet::RakNetGUID p_player)
{
	if (m_myPlayer.guid == p_player)
	{
		m_myPlayer.invis = true;
	}
	else
	{
		m_myPlayer.invis = false;
	}

	for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
	{
		if (m_enemyPlayers[i].guid == p_player)
		{
			m_enemyPlayers[i].invis = true;
		}
		else
		{
			m_enemyPlayers[i].invis = false;
		}
	}
}

void Network::UpdatePlayerInvis(RakNet::RakNetGUID p_guid, bool p_invis)
{
	if (p_guid == m_myPlayer.guid)
	{
		m_myPlayer.invis = p_invis;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (p_guid == m_enemyPlayers[i].guid)
			{
				m_enemyPlayers[i].invis = p_invis;
			}
		}
	}
}

void Network::UpdatePlayerShield(RakNet::RakNetGUID p_guid, float p_shield)
{
	if (p_guid == m_myPlayer.guid)
	{
		m_myPlayer.shield = p_shield;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (p_guid == m_enemyPlayers[i].guid)
			{
				m_enemyPlayers[i].shield = p_shield;
			}
		}
	}
}

void Network::UpdatePlayerName(RakNet::RakNetGUID p_guid, RakNet::RakString p_name)
{
	if (p_guid == GetMyGUID())
	{
		m_myPlayer.name = p_name;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_guid)
			{
				m_enemyPlayers[i].name = p_name;
				break;
			}
		}
	}
}

void Network::SetPlayerName(std::string p_playerName)
{
	m_playerName = p_playerName;
}

std::string Network::GetPlayerName(RakNet::RakNetGUID p_guid)
{
	std::string name = "";
	if (p_guid == GetMyGUID())
	{
		return m_myPlayer.name.C_String();
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_guid)
			{
				return m_enemyPlayers[i].name.C_String();
			}
		}
	}
	return "";
}

void Network::UpdatePlayerInvisAll(bool p_invis)
{
	m_myPlayer.invis = p_invis;

	for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
	{
		m_enemyPlayers[i].invis = p_invis;
	}
}

int Network::GetCharNr(RakNet::RakNetGUID p_guid)
{
	if (p_guid == GetMyGUID())
	{
		return m_myPlayer.charNr;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_guid)
			{
				return m_enemyPlayers[i].charNr;
			}
		}
	}

	return -1;
}

void Network::SetVisiblePlayers(std::vector<RakNet::RakNetGUID> p_visiblePlayers)
{
	m_visibleEnemies = std::vector<int>();
	for (int i = 0; i < p_visiblePlayers.size(); i++)
	{
		if (GetTeam(p_visiblePlayers[i]) != m_myPlayer.team)
		{
			m_visibleEnemies.push_back(GUIDToID(p_visiblePlayers[i]));
		}
	}
}

int Network::GUIDToID(RakNet::RakNetGUID p_guid)
{
	if (p_guid == GetMyGUID())
	{
		return m_myPlayer.id;
	}
	else
	{
		for (unsigned int i = 0; i < m_enemyPlayers.size(); i++)
		{
			if (m_enemyPlayers[i].guid == p_guid)
			{
				return m_enemyPlayers[i].id;
			}
		}
	}

	return -1;
}

void Network::SendVisiblePlayers()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SEND_VISIBLE_PLAYERS);

	bitStream.Write((unsigned char)m_visibleEnemies.size());
	
	for (unsigned int i = 0; i < m_visibleEnemies.size(); i++)
	{
		bitStream.Write((unsigned char)m_visibleEnemies[i]);
	}
}