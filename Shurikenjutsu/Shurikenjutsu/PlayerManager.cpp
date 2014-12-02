#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

bool PlayerManager::Initialize()
{
	m_enemyList = std::vector<Player>();
	AddPlayer("../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(0,0,-2.0f), DirectX::XMFLOAT3(0,0,0), 0.1f, 100, 5, 100, 20);
	return true;
}

void PlayerManager::Shutdown()
{

}

void PlayerManager::Update(double p_deltaTime)
{
	m_player.UpdateMe(p_deltaTime);

	if (Network::IsConnected())
	{
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
					ConsolePrintText("Removed enemy player in playermanager");
				}
			}

			// Go through the list to see if any new players need to be added
			for (unsigned int i = 0; i < enemyPlayers.size(); i++)
			{
				if (!IsGuidInEnemyList(enemyPlayers[i].guid))
				{
					// Add player
					AddEnemy(enemyPlayers[i].guid, "../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z), DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirX, enemyPlayers[i].dirX), 0.1f, 100, 5, 100, 20);
					ConsolePrintText("Added enemy player in playermanager");
				}
			}

			Network::SetHaveUpdatedPlayerList();
		}

		for (unsigned int i = 0; i < m_enemyList.size(); i++)
		{
			m_enemyList[i].SetPosition(DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z));
			m_enemyList[i].SetAttackDirection(DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirY, enemyPlayers[i].dirZ));
			m_enemyList[i].Update(p_deltaTime);
		}
	}
}

void PlayerManager::Render(SHADERTYPE p_shader)
{
	m_player.Render(p_shader);

	if (p_shader == SHADERTYPE_SCENE)
	{
		Lines::GetInstance().RenderSingleLine(DirectX::XMFLOAT3(m_player.GetPosition().x, 3.0f, m_player.GetPosition().z), DirectX::XMFLOAT3(m_player.GetPosition().x + m_player.GetAttackDirection().x  * 100.0f, 3.0f, m_player.GetPosition().z + m_player.GetAttackDirection().z * 100.0f));
	}

	for (unsigned int i = 0; i < m_enemyList.size(); i++)
	{
		m_enemyList[i].Render(p_shader);

		if (p_shader == SHADERTYPE_SCENE)
		{
			Lines::GetInstance().RenderSingleLine(DirectX::XMFLOAT3(m_enemyList[i].GetPosition().x, 3.0f, m_enemyList[i].GetPosition().z), DirectX::XMFLOAT3(m_enemyList[i].GetPosition().x + m_enemyList[i].GetAttackDirection().x  * 100.0f, 3.0f, m_enemyList[i].GetPosition().z + m_enemyList[i].GetAttackDirection().z * 100.0f));
		}
	}
}

void PlayerManager::AddPlayer(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	Player tempPlayer;
	tempPlayer.Initialize(p_filepath, p_pos, p_direction, p_speed, p_damage, p_spells, p_health, p_agility);
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