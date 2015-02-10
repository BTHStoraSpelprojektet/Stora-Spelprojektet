#include "GameState.h"

#include "MapManager.h"
#include "CollisionManager.h"
#include "SpikeManager.h"
#include "ProjectileManager.h"
#include "StickyTrapManager.h"
#include "VolleyManager.h"

GameState::GameState(){}
GameState::~GameState(){}

bool GameState::Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName)
{
	m_serverPeer = p_serverPeer;

	// Initiate playerrs
	m_playerManager = new PlayerManager();
	m_playerManager->Initialize(m_serverPeer, LEVEL_NAME);

	// Initiate shurikens
	m_shurikenManager = new ShurikenManager();
	m_shurikenManager->Initialize(m_serverPeer);

	// Initiate map
	m_mapManager = new MapManager();
	m_mapManager->Initialize(LEVEL_NAME);

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

	m_winningTeams = std::map<int, int>();

	// Time
	m_timeMin = 0;
	m_timeSec = 0;

	

	return true;
}

bool GameState::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	return Initialize(p_serverPeer, LEVEL_NAME);	
}

bool GameState::Initialize(std::string p_levelName)
{
	if (m_serverPeer == NULL)
	{
		return false;
	}

	return Initialize(m_serverPeer, p_levelName);
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
	delete m_mapManager;
	delete m_fanBoomerangManager;
	delete m_collisionManager;
	delete m_projectileManager;
	delete m_volleyManager;
}

void GameState::Update(double p_deltaTime)
{
	m_collisionManager->SetDeltaTime((float)p_deltaTime);

	m_playerManager->Update(p_deltaTime);
	m_shurikenManager->Update(p_deltaTime);
	m_smokeBombManager->Update(p_deltaTime);
	m_spikeManager->Update(p_deltaTime);
	m_stickyTrapManager->Update(p_deltaTime);
	m_fanBoomerangManager->Update(p_deltaTime, m_playerManager);
	m_projectileManager->Update(p_deltaTime);
	m_volleyManager->Update(p_deltaTime);

	m_collisionManager->ShurikenCollisionChecks(m_shurikenManager, m_playerManager);
	m_collisionManager->ProjectileCollisionChecks(m_projectileManager, m_playerManager);
	m_collisionManager->SpikeTrapCollisionChecks(m_spikeManager, m_playerManager);
	m_collisionManager->FanCollisionChecks(p_deltaTime, m_fanBoomerangManager, m_playerManager);
	m_collisionManager->VolleyCollisionChecks(m_volleyManager, m_playerManager);

	m_collisionManager->NaginataStbDot(m_playerManager);
	UpdateTime(p_deltaTime);
	
}

void GameState::AddPlayer(RakNet::RakNetGUID p_guid, int p_charNr)
{
	m_playerManager->AddPlayer(p_guid, p_charNr);
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
	m_playerManager->ExecuteAbility(p_guid, p_ability, *m_collisionManager, *m_shurikenManager, *m_smokeBombManager, *m_spikeManager, *m_fanBoomerangManager, *m_projectileManager, *m_stickyTrapManager, *m_volleyManager);
}

void GameState::BroadcastPlayers()
{
	m_playerManager->BroadcastPlayers();
}

void GameState::UpdateTime(double p_deltaTime)
{
	m_timeSec += p_deltaTime;
	if (m_timeSec >= 60)
	{
		m_timeSec -= 60;
		m_timeMin++;
	}
}

void GameState::ResetTime()
{
	m_timeSec = 0;
	m_timeMin = 0;
}

void GameState::SyncTime(RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_TIMER_SYNC);
	bitStream.Write(m_timeMin);
	bitStream.Write(m_timeSec);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);
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

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, p_guid, false);
}