#include "PlayerManager.h"


PlayerManager::PlayerManager()
{

}

PlayerManager::~PlayerManager()
{

}

bool PlayerManager::Initialize(std::vector<Object> p_ModelList)
{
	m_enemyList = std::vector<Player>();
	AddPlayer("../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 10.0f, 100, 5, 100, 20, p_ModelList);

	return true;
}

void PlayerManager::Shutdown()
{

}

void PlayerManager::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	m_player.UpdateMe();

	if (Network::IsConnected())
	{
		PlayerNet myPlayer = Network::GetMyPlayer();

		// Check if the player need to respawn
		if (Network::HasRespawned())
		{
			m_player.SendPosition(DirectX::XMFLOAT3(myPlayer.x, myPlayer.y, myPlayer.z));
			Network::SetHaveRespawned();
		}

		// Check if the player have made an invalid move
		if (Network::MadeInvalidMove())
		{
			m_player.SendPosition(DirectX::XMFLOAT3(myPlayer.x, myPlayer.y, myPlayer.z));
			Network::UpdatedMoveFromInvalidMove();
		}

		std::vector<PlayerNet> enemyPlayers = Network::GetOtherPlayers();

		// The player list have added or removed an object
		if (Network::IsPlayerListUpdated())
		{
			// Add or remove an object

			// Go through the list to see if any player needs to be removed
			for (unsigned int i = 0; i < m_enemyList.size(); i++)
			{
				RakNet::RakNetGUID guid = m_enemyList[i].GetGuID();

				if (!(IsGuidInNetworkList(guid)))
				{
					// Remove player
					m_enemyList.erase(m_enemyList.begin() + i);
					i--;
				}
			}

			// Go through the list to see if any new players need to be added
			for (unsigned int i = 0; i < enemyPlayers.size(); i++)
			{
				if (!IsGuidInEnemyList(enemyPlayers[i].guid))
				{
					// Add player
					AddEnemy(enemyPlayers[i].guid, "../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z), DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirX, enemyPlayers[i].dirX), 0.1f, 100, 5, 100, 20);
				}
			}

			Network::SetHaveUpdatedPlayerList();
		}

		for (unsigned int i = 0; i < m_enemyList.size(); i++)
		{
			m_enemyList[i].SetPosition(DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z));
			m_enemyList[i].SetAttackDirection(DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirY, enemyPlayers[i].dirZ));
			m_enemyList[i].Update();
		}
	}
}

void PlayerManager::Render(SHADERTYPE p_shader)
{
	m_player.Render(p_shader);

	for (unsigned int i = 0; i < m_enemyList.size(); i++)
	{
		m_enemyList[i].Render(p_shader);
	}
}

void PlayerManager::AddPlayer(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility, std::vector<Object> p_ModelList)
{
	Player tempPlayer;
	tempPlayer.Initialize(p_filepath, p_pos, p_direction, p_speed, p_damage, p_spells, p_health, p_agility);

	tempPlayer.SetCollidingObjects(p_ModelList);
	m_player = tempPlayer;
}

void PlayerManager::AddEnemy(RakNet::RakNetGUID p_guid, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	Player tempPlayer;
	tempPlayer.Initialize(p_filepath, p_pos, p_direction, p_speed, p_damage, p_spells, p_health, p_agility);
	tempPlayer.SetGuID(p_guid);
	m_enemyList.push_back(tempPlayer);
}

DirectX::XMFLOAT3 PlayerManager::GetPlayerPosition()
{
	return m_player.GetPosition();
}
DirectX::XMFLOAT3 PlayerManager::GetPlayerDirection()
{
	return m_player.GetDirection();
}
void PlayerManager::SetPlayerDirection(DirectX::XMFLOAT3 p_direction)
{
	DirectX::XMVECTOR tempVector = DirectX::XMVectorSet(p_direction.x, p_direction.y, p_direction.z, 0.0f);
	tempVector = DirectX::XMVector3Normalize(tempVector);
	DirectX::XMFLOAT3 tempFloat;
	DirectX::XMStoreFloat3(&tempFloat, tempVector);
	m_player.SetDirection(tempFloat);
}
DirectX::XMFLOAT3 PlayerManager::GetFacingDirection()
{
	return m_player.GetFacingDirection();
}
void PlayerManager::SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection)
{
	m_player.SetFacingDirection(p_facingDirection);
}
DirectX::XMFLOAT3 PlayerManager::GetAttackDirection()
{
	return m_player.GetAttackDirection();
}
void PlayerManager::SetAttackDirection(DirectX::XMFLOAT3 p_attackDirection)
{
	m_player.SetMyAttackDirection(p_attackDirection);
}

bool PlayerManager::IsGuidInEnemyList(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_enemyList.size(); i++)
	{
		if (m_enemyList[i].GetGuID() == p_guid)
		{
			return true;
		}
	}
	return false;
}

bool PlayerManager::IsGuidInNetworkList(RakNet::RakNetGUID p_guid)
{
	std::vector<PlayerNet> enemyPlayers = Network::GetOtherPlayers();
	for (unsigned int i = 0; i < enemyPlayers.size(); i++)
	{
		if (enemyPlayers[i].guid == p_guid)
		{
			return true;
		}
	}
	return false;
}

DirectX::BoundingBox PlayerManager::GetPlayerBoundingBox()
{
	return m_player.GetPlayerBoundingBox();
}