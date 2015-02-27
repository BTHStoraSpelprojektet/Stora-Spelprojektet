#include "GameState.h"

#include "MapManager.h"
#include "CollisionManager.h"
#include "SpikeManager.h"
#include "ProjectileManager.h"
#include "StickyTrapManager.h"
#include "VolleyManager.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

GameState::GameState(){}
GameState::~GameState(){}

bool GameState::Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName)
{
	m_serverPeer = p_serverPeer;

	// Initiate playerrs
	m_playerManager = new PlayerManager();
	m_playerManager->Initialize(m_serverPeer, p_levelName);

	// Initiate shurikens
	m_shurikenManager = new ShurikenManager();
	m_shurikenManager->Initialize(m_serverPeer);

	// Initiate map
	m_mapManager = new MapManager();
	m_mapManager->Initialize(p_levelName);

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

	m_roundRestarting = false;

	Level level(p_levelName);
	float xMax = 0, xMin = 0;
	float zMax = 0, zMin = 0;
	for each(LevelImporter::LevelBoundingBox levelBoundingBox in level.getLevelBoundingBoxes())
	{
		Box boundingBox = Box(levelBoundingBox.m_translationX, levelBoundingBox.m_translationY, levelBoundingBox.m_translationZ, levelBoundingBox.m_halfDepth, levelBoundingBox.m_halfHeight, levelBoundingBox.m_halfWidth);
		if (boundingBox.m_center.x > 0.0f)
		{
			xMax = boundingBox.m_center.x;
		}
		if (boundingBox.m_center.x < 0.0f)
		{
			xMin = boundingBox.m_center.x;
		}
		if (boundingBox.m_center.z > 0.0f)
		{
			zMax = boundingBox.m_center.z;
		}
		if (boundingBox.m_center.z < 0.0f)
		{
			zMin = boundingBox.m_center.z;
		}
	}

	float xLength = xMax - xMin;
	float zLength = zMax - zMin;
	std::vector<DirectX::XMFLOAT3> positions;
	positions.push_back(DirectX::XMFLOAT3(-xLength / 4.0f, 0.0f, zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(0.0f, 0.0f, zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(xLength / 4.0f, 0.0f, zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(-xLength / 4.0f, 0.0f, 0.0f));
	positions.push_back(DirectX::XMFLOAT3(xLength / 4.0f, 0.0f, 0.0f));
	positions.push_back(DirectX::XMFLOAT3(-xLength / 4.0f, 0.0f, -zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(0.0f, 0.0f, -zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(xLength / 4.0f, 0.0f, -zLength / 4.0f));

	m_suddenDeathMaxBoxExtentX = xLength / 8.0f;
	m_suddenDeathMaxBoxExtentZ = zLength / 8.0f;
	for (unsigned int i = 0; i < 8; i++)
	{
		m_suddenDeathBoxes.push_back(Box(positions[i], DirectX::XMFLOAT3(0.0f,10.0f,0.0f)));
	}

	m_isSuddenDeath = false;
	m_suddenDeathTimer = 0.0f;
	for (unsigned int i = 0; i < 8; i++)
	{
		m_suddenDeathInActiveBoxes.push_back(i);
	}
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
	delete m_spikeManager;
	delete m_stickyTrapManager;
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

	if (m_isSuddenDeath)
	{
		m_suddenDeathTimer += (float)p_deltaTime;
		m_collisionManager->SuddenDeathDot((float)p_deltaTime, m_playerManager, m_suddenDeathBoxes, m_suddenDeathInActiveBoxes);
		for (unsigned int i = 0; i < m_suddenDeathBoxes.size(); i++)
		{
			if (m_suddenDeathBoxes[i].m_extents.x <= m_suddenDeathMaxBoxExtentX)
			{
				m_suddenDeathBoxes[i].m_extents.x += (float)p_deltaTime;
			}
			if (m_suddenDeathBoxes[i].m_extents.z <= m_suddenDeathMaxBoxExtentZ)
			{
				m_suddenDeathBoxes[i].m_extents.z += (float)p_deltaTime;
			}
		}
	}	
	if (m_suddenDeathTimer > TIME_UNTIL_NEXT_SUDDEN_DEATH_BOX && m_suddenDeathInActiveBoxes.size() > 0)
	{
		int boxIndex = GetNewSuddenDeathBoxIndex();
		SendSuddenDeathBoxActivation(boxIndex);
		m_suddenDeathTimer = 0.0f;
	}

}
void GameState::SendSuddenDeathBoxActivation(int p_boxIndex)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_INITIATE_SUDDEN_DEATH_BOX);
	bitStream.Write(p_boxIndex);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
int GameState::GetNewSuddenDeathBoxIndex()
{
	int random = std::rand() % m_suddenDeathInActiveBoxes.size();
	int returnValue = m_suddenDeathInActiveBoxes[random];
	m_suddenDeathInActiveBoxes.erase(m_suddenDeathInActiveBoxes.begin() + random);
	return returnValue;
}
void GameState::AddPlayer(RakNet::RakNetGUID p_guid, int p_charNr, int p_toolNr, int p_team)
{
	m_playerManager->AddPlayer(p_guid, p_charNr, p_toolNr, p_team);
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

	//if (m_timeSec > 0.9f &&( redTeam == 0|| bluTeam == 0))
	//{
	//	m_timeSec = 0.0f;
	//	m_timeMin = 0.0f;
	//	for (unsigned int i = 0; i < playerList.size(); i++)
	//	{
	//		SyncTime(playerList[i].guid);
	//	}
	//}
	if (m_timeSec >= ROUND_TIME_LIMIT && !m_isSuddenDeath)
	{
		m_isSuddenDeath = true;
		
		SendSuddenDeathMessage();
	}
}

void GameState::SendSuddenDeathMessage()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_START_SUDDEN_DEATH);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
void GameState::ResetTime()
{
	m_timeSec = 0;
	m_timeMin = 0;
	m_isSuddenDeath = false;
	m_suddenDeathTimer = 0.0f;
	for (unsigned int i = 0; i < 8; i++)
	{
		m_suddenDeathInActiveBoxes.push_back(i);
	}
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