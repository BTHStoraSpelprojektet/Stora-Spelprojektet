#include "GameState.h"


GameState::GameState()
{
}


GameState::~GameState()
{
}

bool GameState::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;

	// Initiate playerrs
	m_playerManager = PlayerManager();
	m_playerManager.Initialize(m_serverPeer, LEVEL_NAME);

	// Initiate shurikens
	m_shurikenManager = ShurikenManager();
	m_shurikenManager.Initialize(m_serverPeer);

	// Initiate map
	m_mapManager = MapManager();
	m_mapManager.Initialize(LEVEL_NAME);

	// Initiate collision manager
	m_collisionManager = new CollisionManager();
	m_collisionManager->Initialize(m_mapManager.GetBoundingBoxes());

	return true;
}

void GameState::Shutdown()
{
	m_playerManager.Shutdown();
	m_shurikenManager.Shutdown();
	m_mapManager.Shutdown();
	delete m_collisionManager;
}

void GameState::Update(double p_deltaTime)
{
	m_playerManager.Update(p_deltaTime);
	m_shurikenManager.Update(p_deltaTime);

	m_collisionManager->ShurikenCollisionChecks(&m_shurikenManager, &m_playerManager);
}

void GameState::AddPlayer(RakNet::RakNetGUID p_guid, int p_nrOfConnections)
{
	m_playerManager.AddPlayer(p_guid, p_nrOfConnections);
}

void GameState::RemovePlayer(RakNet::RakNetGUID p_guid)
{
	m_playerManager.RemovePlayer(p_guid);
}

void GameState::MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections)
{
	m_playerManager.MovePlayer(p_guid, p_x, p_y, p_z, p_nrOfConnections);
}

PlayerNet GameState::GetPlayer(RakNet::RakNetGUID p_guid)
{
	return m_playerManager.GetPlayer(p_guid);
}

int GameState::GetPlayerIndex(RakNet::RakNetGUID p_guid)
{
	return m_playerManager.GetPlayerIndex(p_guid);
}

void GameState::RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ)
{
	m_playerManager.RotatePlayer(p_guid, p_dirX, p_dirY, p_dirZ);
}

bool GameState::CanUseAbility(int p_index, ABILITIES p_ability)
{
	return m_playerManager.CanUseAbility(p_index, p_ability);
}

void GameState::UsedAbility(int p_index, ABILITIES p_ability)
{
	m_playerManager.UsedAbility(p_index, p_ability);
}

void GameState::ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_ability)
{
	m_playerManager.ExecuteAbility(p_guid, p_ability, *m_collisionManager, m_shurikenManager);
}

void GameState::BroadcastPlayers()
{
	m_playerManager.BroadcastPlayers();
}