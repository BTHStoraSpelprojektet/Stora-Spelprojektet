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
			std::cout << "Cheking enemyplayerlist for updates" << std::endl;
			// Lägg till eller ta bort från listan?
			// atm finns bara lägga till i servern
			
			for (unsigned int i = 0; i < m_enemyList.size(); i++)
			{
				RakNet::RakNetGUID guid = m_enemyList[i].GetGuID();

				//if (!(enemyPlayers.find(guid) == enemyPlayers.end()))
				//{
				//	// remove player
				//	m_enemyList.erase(m_enemyList.begin() + i);
				//	i--;
				//	std::cout << "Removed enemy player in playermanager" << std::endl;
				//}
			}

			for (unsigned int i = 0; i < enemyPlayers.size(); i++)
			{
				if (!IsGuidInEnemyList(enemyPlayers[i].guid))
				{
					// Add player
					AddEnemy(enemyPlayers[i].guid, "../Shurikenjutsu/Models/cubemanWnP.SSP", DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z), DirectX::XMFLOAT3(0, 0, 0), 0.1f, 100, 5, 100, 20);
					std::cout << "Added enemy player in playermanager" << std::endl;
				}
			}

			Network::SetHaveUpdatedPlayerList();
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