#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

bool PlayerManager::Initialize()
{

	AddPlayer("../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(0,0,-2.0f), DirectX::XMFLOAT3(0,0,0), 0.1f, 100, 5, 100, 20);
	return true;
}

void PlayerManager::Shutdown()
{

}

void PlayerManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_playerList.size(); i++)
	{
		m_playerList[i].Update(p_deltaTime);
	}
}

void PlayerManager::AddPlayer(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	Player tempPlayer;
	tempPlayer.Initialize(p_filepath, p_pos, p_direction, p_speed, p_damage, p_spells, p_health, p_agility);
	m_playerList.push_back(tempPlayer);
}

Model PlayerManager::GetModel(int p_index)
{
	return m_playerList[p_index].GetModel();
}

std::vector<Player> PlayerManager::GetListOfPlayers() const
{
	return m_playerList;
}

DirectX::XMFLOAT3 PlayerManager::GetPosition(int p_index)
{
	return m_playerList[p_index].GetPosition();
}