#include "GameState.h"

#include "MapManager.h"
#include "CollisionManager.h"
#include "SpikeManager.h"
#include "ProjectileManager.h"
#include "StickyTrapManager.h"
#include "VolleyManager.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "PointOfInterestManager.h"

GameState::GameState(){}
GameState::~GameState(){}

bool GameState::Initialize(RakNet::RakPeerInterface *p_serverPeer, std::vector<std::string> p_levelsName, int p_currentLevel)
{
	m_serverPeer = p_serverPeer;
	m_levelsName = p_levelsName;
	m_currentLevel = p_currentLevel;

	// Initiate playerrs
	m_playerManager = new PlayerManager();
	m_playerManager->Initialize(m_serverPeer, p_levelsName[p_currentLevel]);

	// Initiate shurikens
	m_shurikenManager = new ShurikenManager();
	m_shurikenManager->Initialize(m_serverPeer);

	// Initiate map
	m_mapManager = new MapManager();
	m_mapManager->Initialize(p_levelsName[p_currentLevel]);

	// Initiate collision manager
	m_collisionManager = new CollisionManager();
	m_collisionManager->Initialize(m_mapManager->GetBoundingBoxes(), m_mapManager->GetBoundingSpheres());

	m_smokeBombManager = new SmokeBombManager();
	m_smokeBombManager->Initialize(m_serverPeer);

	m_spikeManager = new SpikeManager();
	m_spikeManager->Initialize(m_serverPeer);

	m_stickyTrapManager = new StickyTrapManager();
	m_stickyTrapManager->Initialize(m_serverPeer);

	m_fanBoomerangManager = new FanBoomerangManager();
	m_fanBoomerangManager->Initialize(m_serverPeer);

	m_projectileManager = new ProjectileManager();
	m_projectileManager->Initialize(m_serverPeer);
	m_volleyManager = new VolleyManager();
	m_volleyManager->Initialize(m_serverPeer);
	m_POIManager = new PointOfInterestManager();
	m_POIManager->Initialize(m_serverPeer, p_levelsName, p_currentLevel);
	m_winningTeams = std::map<int, int>();

	// Time
	m_timeMin = 0;
	m_timeSec = 0;

	m_roundRestarting = false;
	m_runesSpawned = false;
	m_runeRespawn = false;
	m_shieldActiveTimer = 0.0f;
	m_invisActiveTimer = 0.0f;

	m_isSuddenDeath = false;
	m_suddenDeathTimer = 0.0f;

	return true;
}

bool GameState::Initialize(int p_currentLevel)
{
	if (m_serverPeer == NULL)
	{
		return false;
	}

	return Initialize(m_serverPeer, m_levelsName, p_currentLevel);
}

void GameState::Shutdown()
{
	m_playerManager->Shutdown();
	m_shurikenManager->Shutdown();
	m_smokeBombManager->Shutdown();
	m_spikeManager->Shutdown();
	m_stickyTrapManager->Shutdown();
	m_mapManager->Shutdown();
	m_fanBoomerangManager->Shutdown();
	m_projectileManager->Shutdown();
	m_volleyManager->Shutdown();

	delete m_playerManager;
	delete m_shurikenManager;
	delete m_smokeBombManager;
	delete m_spikeManager;
	delete m_stickyTrapManager;
	delete m_mapManager;
	delete m_fanBoomerangManager;
	delete m_collisionManager;
	delete m_projectileManager;
	delete m_volleyManager;

	if (m_POIManager != nullptr)
	{
		m_POIManager->Shutdown();
		delete m_POIManager;
		m_playerManager = nullptr;
	}
}

void GameState::Update(double p_deltaTime)
{
	m_collisionManager->SetDeltaTime((float)p_deltaTime);
	m_deltaTime = (float)p_deltaTime;

	m_playerManager->Update(p_deltaTime);
	m_shurikenManager->Update(p_deltaTime);
	m_smokeBombManager->Update(p_deltaTime);
	m_spikeManager->Update(p_deltaTime);
	m_stickyTrapManager->Update(p_deltaTime);
	m_fanBoomerangManager->Update(p_deltaTime, m_playerManager);
	m_projectileManager->Update(p_deltaTime);
	m_volleyManager->Update(p_deltaTime);
	m_POIManager->Update(p_deltaTime);

	m_collisionManager->ShurikenCollisionChecks(m_shurikenManager, m_playerManager);
	m_collisionManager->ProjectileCollisionChecks(m_projectileManager, m_playerManager);
	m_collisionManager->SpikeTrapCollisionChecks(m_spikeManager, m_playerManager);
	m_collisionManager->FanCollisionChecks(p_deltaTime, m_fanBoomerangManager, m_playerManager);
	m_collisionManager->VolleyCollisionChecks(m_volleyManager, m_playerManager);
	m_collisionManager->POICollisionChecks(m_POIManager, m_playerManager);
	m_collisionManager->NaginataStbDot(m_playerManager);

	UpdateTime(p_deltaTime);
	
	if (m_isSuddenDeath)
	{
		if (m_suddenDeathTimer <= 10.0f)
		{
			m_suddenDeathTimer += (float)p_deltaTime;
		}

		else
		{
			m_collisionManager->SuddenDeathDot((float)p_deltaTime, m_playerManager);
		}
	}

	// Spawn rune
	if (m_timeMin == 0 && m_timeSec >= 30)
	{
		if (!m_runesSpawned)
		{
			m_POIManager->SpawnRunes();
			m_runesSpawned = true;
		}
	}
	// Respawn healing rune
	if (m_timeMin == 1 && m_timeSec >= 30)
	{
		if (!m_runeRespawn)
		{
			m_POIManager->SpawnRune(POINTOFINTERESTTYPE_HEAL);
			m_runeRespawn = true;
		}
	}
}

void GameState::AddPlayer(RakNet::RakNetGUID p_guid, RakNet::RakString p_name, int p_charNr, int p_toolNr, int p_team)
{
	m_playerManager->AddPlayer(p_guid, p_name, p_charNr, p_toolNr, p_team);
	SendSuddenDeathMessage(m_isSuddenDeath);
}

void GameState::RemovePlayer(RakNet::RakNetGUID p_guid)
{
	m_playerManager->RemovePlayer(p_guid);
}

bool GameState::MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections, bool p_dash)
{
	return m_playerManager->MovePlayer(p_guid, p_x, p_y, p_z, p_nrOfConnections, p_dash);
}

PlayerNet GameState::GetPlayer(RakNet::RakNetGUID p_guid)
{
	return m_playerManager->GetPlayer(p_guid);
}

int GameState::GetPlayerIndex(RakNet::RakNetGUID p_guid)
{
	return m_playerManager->GetPlayerIndex(p_guid);
}

bool GameState::RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ)
{
	return m_playerManager->RotatePlayer(p_guid, p_dirX, p_dirY, p_dirZ);
}

void GameState::ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_ability, float p_distanceFromPlayer)
{
	m_smokeBombManager->SetCurrentDistanceFromPlayer(p_distanceFromPlayer);
	m_spikeManager->SetCurrentDistanceFromPlayer(p_distanceFromPlayer);
	m_stickyTrapManager->SetCurrentDistanceFromPlayer(p_distanceFromPlayer);
	m_volleyManager->SetCurrentDistanceFromPlayer(p_distanceFromPlayer);
	m_playerManager->ExecuteAbility(m_deltaTime, p_guid, p_ability, *m_collisionManager, *m_shurikenManager, *m_smokeBombManager, *m_spikeManager, *m_fanBoomerangManager, *m_projectileManager, *m_stickyTrapManager, *m_volleyManager, p_distanceFromPlayer);
	AbilityUsedCancelInvis(p_guid);
}

void GameState::BroadcastPlayers()
{
	m_playerManager->BroadcastPlayers();
}

void GameState::UpdateTime(double p_deltaTime)
{
	std::vector<PlayerNet> playerList =	m_playerManager->GetPlayers();
	float redTeam = 0;
	float bluTeam = 0;
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		if (playerList[i].team == 1)
		{
			redTeam++;
		}
		else
		{
			bluTeam++;
		}
	}

	m_timeSec += p_deltaTime;
	if (m_timeSec >= 60)
	{
		m_timeSec -= 60;
		m_timeMin++;
	}

	if (m_timeSec > 0.9f && (redTeam == 0 || bluTeam == 0))
	{
		ResetTime();
		m_POIManager->DespawnRunes();
		m_playerManager->ResetPOIEffects();
		
		for (unsigned int i = 0; i < playerList.size(); i++)
		{
			SyncTime(playerList[i].guid);			
		}
	}

	if (m_timeMin >= ROUND_TIME_LIMIT_MINUTS && !m_isSuddenDeath)
	{
		m_isSuddenDeath = true;

		SendSuddenDeathMessage(m_isSuddenDeath);
	}
}

void GameState::SendSuddenDeathMessage(bool p_isSuddenDeath)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SEND_SUDDEN_DEATH);
	bitStream.Write(p_isSuddenDeath);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void GameState::ResetTime()
{
	m_timeSec = 0;
	m_timeMin = 0;
	m_isSuddenDeath = false;
	m_runesSpawned = false;
	m_runeRespawn = false;
	m_suddenDeathTimer = 0.0f;

	SendSuddenDeathMessage(m_isSuddenDeath);
}

void GameState::SyncTime(RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_TIMER_SYNC);
	bitStream.Write(m_timeMin);
	bitStream.Write(m_timeSec);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 4, p_guid, false);
}

void GameState::SendCurrentTeamScore(RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SEND_TEAM_SCORE);
	bitStream.Write((unsigned int)m_winningTeams.size());
	
	for (auto it = m_winningTeams.begin(); it != m_winningTeams.end(); it++)
	{
		bitStream.Write(it->first);
		bitStream.Write(it->second);
	}

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 4, p_guid, false);
}

void GameState::UserConnected(RakNet::RakNetGUID p_guid)
{
	// If round is restarting send it to the new user
	if (m_roundRestarting)
	{
		RakNet::BitStream bitStream;
		bitStream.Write((RakNet::MessageID)ID_RESTARTING_ROUND);
		m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 4, p_guid, false);
	}
}

void GameState::UpdatePlayerVisibility(RakNet::RakNetGUID p_guid, std::vector<int> p_visiblePlayers)
{
	m_playerManager->UpdateVisiblePlayers(p_guid, p_visiblePlayers);
}

void GameState::AbilityUsedCancelInvis(RakNet::RakNetGUID p_guid)
{
	if (m_playerManager->GetInvis(p_guid))
	{
		m_POIManager->AbilityUsed();
	}
}

void GameState::SendCurrentRunes(RakNet::RakNetGUID p_guid)
{
	m_POIManager->DownloadRunes(p_guid);
}

void GameState::SetPlayerInLobby(RakNet::RakNetGUID p_guid, int p_charNr, int p_toolNr, int p_team, std::string p_name, bool p_isReady)
{
	m_playerManager->SetPlayerInLobby(p_guid, p_charNr, p_toolNr, p_team, p_name, p_isReady);
}

void GameState::SendStartGame()
{
	m_playerManager->SendStartGame();
}