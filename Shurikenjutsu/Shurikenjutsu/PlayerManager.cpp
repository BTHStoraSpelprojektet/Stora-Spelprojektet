#include "PlayerManager.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Frustum.h"
#include "Globals.h"
#include "Minimap.h"
#include "VisibilityComputer.h"
#include "..\CommonLibs\ModelNames.h"
#include "KatanaNinja.h"
#include "TessenNinja.h"
#include "NaginataNinja.h"

PlayerManager::PlayerManager(){}
PlayerManager::~PlayerManager(){}
bool PlayerManager::Initialize()
{
	m_enemyListSize = 0;
	m_enemyList = NULL;
	AddPlayer(Network::GetInstance()->GetMyPlayer().charNr, DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));

	return true;
}

void PlayerManager::Shutdown()
{
	if (m_player != nullptr)
	{
		m_player->Shutdown();
		delete m_player;
		m_player = nullptr;
	}
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		m_enemyList[i]->Shutdown();
		delete m_enemyList[i];
	}
	delete[] m_enemyList;
	m_enemyListSize = 0;
}

void PlayerManager::Update(std::vector<StickyTrap*> p_stickyTrapList)
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	m_player->UpdateMe(p_stickyTrapList);

	if (Network::GetInstance()->IsConnected())
	{
		// Check if the round have restarted
		if (Network::GetInstance()->RoundRestarted())
		{
			ResetCooldowns();
		}

		std::vector<PlayerNet> enemyPlayers = Network::GetInstance()->GetOtherPlayers();

		// The player list have added or removed an object
		if (Network::GetInstance()->IsPlayerListUpdated())
		{
			// Add or remove an object

			// Go through the list to see if any player needs to be removed
			for (unsigned int i = 0; i < m_enemyListSize; i++)
			{
				RakNet::RakNetGUID guid = m_enemyList[i]->GetGuID();

				if (!(IsGuidInNetworkList(guid)))
				{
					// Remove player
					RemoveEnemyFromList(i);
					i--;
				}
			}

			// Go through the list to see if any new players need to be added
			for (unsigned int i = 0; i < enemyPlayers.size(); i++)
			{
				if (!IsGuidInEnemyList(enemyPlayers[i].guid))
				{
					// Add player
					AddEnemy(enemyPlayers[i].guid, enemyPlayers[i].charNr, DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z), 
						DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirX, enemyPlayers[i].dirX));
				}
			}

			Network::GetInstance()->SetHaveUpdatedPlayerList();
		}
		
		for (unsigned int i = 0; i < m_enemyListSize; i++)
		{			
			m_enemyList[i]->SetPosition(DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z));				
			m_enemyList[i]->SetAttackDirection(DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirY, enemyPlayers[i].dirZ));
			m_enemyList[i]->SetHealth(enemyPlayers[i].currentHP);
			m_enemyList[i]->SetIsAlive(enemyPlayers[i].isAlive);
			m_enemyList[i]->SetTeam(enemyPlayers[i].team);
			m_enemyList[i]->Update();
		}
	}
	CheckPlayersVisible();
}

void PlayerManager::Render()
{
	m_player->Render();
	m_player->RenderAbilityBar();

	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_frustum->CheckSphere(m_enemyList[i]->GetFrustumSphere(), 1.0f))
		{
			if (m_enemyList[i]->IsVisible() && VisibilityComputer::GetInstance().IsPointVisible(Point(m_enemyList[i]->GetPosition().x, m_enemyList[i]->GetPosition().z)))
			{
				m_enemyList[i]->Render();
			}
		}
	}
}

void PlayerManager::RenderOutliningPassOne()
{
	m_player->Render();
}

void PlayerManager::RenderDepth()
{
	m_player->RenderDepth();

	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (VisibilityComputer::GetInstance().IsPointVisible(Point(m_enemyList[i]->GetPosition().x, m_enemyList[i]->GetPosition().z)))
		{
			m_enemyList[i]->RenderDepth();
		}
	}
}

void PlayerManager::RenderOutliningPassTwo()
{
	m_player->RenderOutlining();
}

void PlayerManager::AddPlayer(int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction)
{
	switch (p_charNr)
	{
	case 0:
	{
		KatanaNinja *tempPlayer = new KatanaNinja();
		tempPlayer->Initialize(p_pos, p_direction, p_charNr);
		m_player = tempPlayer;
		m_player->SendPosition(m_player->GetPosition());
		break;
	}
	case 1:
	{
		TessenNinja *tempPlayer = new TessenNinja();
		tempPlayer->Initialize(p_pos, p_direction, p_charNr);
		m_player = tempPlayer;
		m_player->SendPosition(m_player->GetPosition());
		break;
	}
	case 2:
	{
		// Todo change to ninja 3
		NaginataNinja *tempPlayer = new NaginataNinja();
		tempPlayer->Initialize(p_pos, p_direction, p_charNr);
		m_player = tempPlayer;
		m_player->SendPosition(m_player->GetPosition());
		break;
	}
	case 3:
	{
		// Todo change to ninja 4
		KatanaNinja *tempPlayer = new KatanaNinja();
		tempPlayer->Initialize(p_pos, p_direction, p_charNr);
		m_player = tempPlayer;
		m_player->SendPosition(m_player->GetPosition());
		break;
	}
	}
	
}

void PlayerManager::AddEnemy(RakNet::RakNetGUID p_guid, int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction)
{
	switch (p_charNr)
	{
	case 0:
	{
		KatanaNinja *tempPlayer = new KatanaNinja();
		tempPlayer->Initialize(p_pos, p_direction, p_charNr);
		tempPlayer->SetGuID(p_guid);
		tempPlayer->SetMaxHealth(CHARACTER_KATANA_SHURIKEN_HEALTH);

		AddEnemyToList(tempPlayer);
		break;
	}
	case 1:
	{
		TessenNinja *tempPlayer = new TessenNinja();
		tempPlayer->Initialize(p_pos, p_direction, p_charNr);
		tempPlayer->SetGuID(p_guid);
		tempPlayer->SetMaxHealth(CHARACTER_TESSEN_HEALTH);
		
		AddEnemyToList(tempPlayer);
		break;
	}
	case 2:
	{
		// Todo change to ninja 3
		NaginataNinja *tempPlayer = new NaginataNinja();
		tempPlayer->Initialize(p_pos, p_direction, p_charNr);
		tempPlayer->SetGuID(p_guid);
		tempPlayer->SetMaxHealth(CHARACTER_NAGINATA_HEALTH);
		
		AddEnemyToList(tempPlayer);
		break;
	}
	case 3:
	{
		// Todo change to ninja 4
		break;
	}
	}
	
}

DirectX::XMFLOAT3 PlayerManager::GetPlayerPosition()
{
	return m_player->GetPosition();
}
DirectX::XMFLOAT3 PlayerManager::GetPlayerDirection()
{
	return m_player->GetDirection();
}
void PlayerManager::SetPlayerDirection(DirectX::XMFLOAT3 p_direction)
{
	DirectX::XMVECTOR tempVector = DirectX::XMVectorSet(p_direction.x, p_direction.y, p_direction.z, 0.0f);
	tempVector = DirectX::XMVector3Normalize(tempVector);
	DirectX::XMFLOAT3 tempFloat;
	DirectX::XMStoreFloat3(&tempFloat, tempVector);
	m_player->SetDirection(tempFloat);
}
DirectX::XMFLOAT3 PlayerManager::GetFacingDirection()
{
	return m_player->GetFacingDirection();
}
void PlayerManager::SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection)
{
	m_player->SetFacingDirection(p_facingDirection);
}
DirectX::XMFLOAT3 PlayerManager::GetAttackDirection()
{
	return m_player->GetAttackDirection();
}
void PlayerManager::SetAttackDirection(DirectX::XMFLOAT3 p_attackDirection)
{
	m_player->SetMyAttackDirection(p_attackDirection);
}

bool PlayerManager::IsGuidInEnemyList(RakNet::RakNetGUID p_guid)
{
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_enemyList[i]->GetGuID() == p_guid)
		{
			return true;
		}
	}
	return false;
}

bool PlayerManager::IsGuidInNetworkList(RakNet::RakNetGUID p_guid)
{
	std::vector<PlayerNet> enemyPlayers = Network::GetInstance()->GetOtherPlayers();
	for (unsigned int i = 0; i < enemyPlayers.size(); i++)
	{
		if (enemyPlayers[i].guid == p_guid)
		{
			return true;
		}
	}
	return false;
}

void PlayerManager::UpdateHealthbars(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		m_enemyList[i]->UpdateHealthBar(p_view, p_projection);
	}

	m_player->UpdateHealthBar(p_view, p_projection);
}

void PlayerManager::ResetCooldowns()
{
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		m_enemyList[i]->ResetCooldowns();
	}

	m_player->ResetCooldowns();
}

void PlayerManager::UpdateFrustum(Frustum*  p_frustum)
{
	m_frustum = p_frustum;
}

void PlayerManager::CheckPlayersVisible()
{
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_frustum->CheckSphere(m_enemyList[i]->GetFrustumSphere(), 1.0f))
		{
			m_enemyList[i]->SetIsVisible(true);
		}
		else
		{
			m_enemyList[i]->SetIsVisible(false);
		}
	}
}

bool PlayerManager::IsPlayersVisible(int p_index)
{
	if (m_enemyListSize <= (unsigned int)p_index)
	{
		return false;
	}
	return m_enemyList[p_index]->IsVisible();
}

void PlayerManager::MinimapUpdatePos(Minimap *p_minimap)
{
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{ 
		if (m_enemyList[i]->GetIsAlive())
		{
			p_minimap->UpdatePlayersPositon(i, m_enemyList[i]->GetPosition());
		}
	}
}

int PlayerManager::GetPlayerTeam()
{
	return m_player->GetTeam();
}

int PlayerManager::GetEnemyTeam(int p_index)
{
	if (m_enemyListSize <= (unsigned int)p_index)
	{
		return 0;
	}
	return m_enemyList[p_index]->GetTeam();
}

OBB PlayerManager::GetPlayerBoundingBox()
{
	return m_player->GetOBB();
}

Sphere PlayerManager::GetPlayerSphere()
{
	return m_player->GetSphere();
}

void PlayerManager::AddEnemyToList(Player* p_enemy)
{
	Player** newList = new Player*[m_enemyListSize + 1];
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		newList[i] = m_enemyList[i];
	}
	newList[m_enemyListSize] = p_enemy;
	delete[] m_enemyList;
	m_enemyList = newList;
	m_enemyListSize++;
}

void PlayerManager::RemoveEnemyFromList(unsigned int p_index)
{
	Player** newList = new Player*[m_enemyListSize - 1];
	int index = 0;
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (i == p_index)
		{
			continue;
		}
		newList[index] = m_enemyList[i];
		index++;
	}
	m_enemyList[p_index]->Shutdown();
	delete m_enemyList[p_index];
	delete[] m_enemyList;
	m_enemyList = newList;
	m_enemyListSize--;
}