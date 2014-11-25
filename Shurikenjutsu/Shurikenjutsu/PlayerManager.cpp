#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

bool PlayerManager::Initialize(ID3D11Device* p_device)
{
	AddPlayer(p_device, "../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(1,1,0), DirectX::XMFLOAT3(1,0,0), 1.0f, 100, 5, 100, 20);
	return true;
}

void PlayerManager::Shutdown()
{

}

void PlayerManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_playerList.size(); i++)
	{
		m_playerList[i]->Update();
	}
}

void PlayerManager::AddPlayer(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	Player *tempPlayer = new Player();
	tempPlayer->Initialize(p_device, p_filepath, p_pos, p_direction, p_speed, p_damage, p_spells, p_health, p_agility);
	m_playerList.push_back(tempPlayer);
}

Model* PlayerManager::GetModel(int p_index)
{
	return m_playerList[p_index]->GetModel();
}