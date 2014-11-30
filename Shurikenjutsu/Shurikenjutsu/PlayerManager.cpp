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
		if (m_enemyList.size() < enemyPlayers.size())
		{
			AddEnemy("../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(0, 0, -2.0f), DirectX::XMFLOAT3(0, 0, 0), 0.1f, 100, 5, 100, 20);
		}

		for (int i = 0; i < m_enemyList.size(); i++)
		{
			m_enemyList[i].SetPosition(DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z));
			m_enemyList[i].Update(p_deltaTime);
		}
	}
		}

void PlayerManager::Render()
{
	m_player.Render();
	
	for (unsigned int i = 0; i < m_enemyList.size(); i++)
	{
		m_enemyList[i].Render();
	}
}

void PlayerManager::AddPlayer(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	Player tempPlayer;
	tempPlayer.Initialize(p_filepath, p_pos, p_direction, p_speed, p_damage, p_spells, p_health, p_agility);
	m_player = tempPlayer;
}

void PlayerManager::AddEnemy(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	Player tempPlayer;
	tempPlayer.Initialize(p_filepath, p_pos, p_direction, p_speed, p_damage, p_spells, p_health, p_agility);
	m_enemyList.push_back(tempPlayer);
}

DirectX::XMFLOAT3 PlayerManager::GetPlayerPosition()
{
	return m_player.GetPosition();
}