#include "PlayerManager.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Frustum.h"
#include "Globals.h"
#include "Minimap.h"
#include "..\CommonLibs\ModelNames.h"
#include "KatanaNinja.h"
#include "TessenNinja.h"
#include "NaginataNinja.h"
#include "Network.h"
#include "GraphicsEngine.h"

PlayerManager::PlayerManager(){}
PlayerManager::~PlayerManager(){}
bool PlayerManager::Initialize(bool p_inMenu)
{
	m_enemyListSize = 0;
	m_enemyList = NULL;
	m_renderOutliningPlayer = false;
	for (int i = 0; i < 7; i++)
	{
		m_renderOutlingingEnemies[i] = false;
	}

	if (!p_inMenu)
	{
		AddPlayer(Network::GetInstance()->GetMyPlayer().charNr, DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), Network::GetInstance()->GetMyPlayer().name.C_String());
	}
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

void PlayerManager::Update(bool p_inMenu)
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	if (!p_inMenu)
	{
		m_player->UpdateMe();
	}

	if (Network::GetInstance()->IsConnected())
	{
		// Check if the round have restarted
		if (Network::GetInstance()->RoundRestarted())
		{
			ResetCooldowns(p_inMenu);
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
					DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirX, enemyPlayers[i].dirX), enemyPlayers[i].name.C_String());
				}
			}

			Network::GetInstance()->SetHaveUpdatedPlayerList();
		}
		
		for (unsigned int i = 0; i < m_enemyListSize; i++)
		{			
			m_enemyList[i]->InterpolatePos(DirectX::XMFLOAT3(enemyPlayers[i].x, enemyPlayers[i].y, enemyPlayers[i].z));				
			m_enemyList[i]->InterpolateAttackDir(DirectX::XMFLOAT3(enemyPlayers[i].dirX, enemyPlayers[i].dirY, enemyPlayers[i].dirZ));
			m_enemyList[i]->SetHealth(enemyPlayers[i].currentHP);
			m_enemyList[i]->SetIsAlive(enemyPlayers[i].isAlive);
			m_enemyList[i]->SetTeam(enemyPlayers[i].team);
			m_enemyList[i]->SetInvis(enemyPlayers[i].invis);
			m_enemyList[i]->Update();

			if (m_enemyList[i]->m_soundEmitter != NULL) {
				m_enemyList[i]->m_soundEmitter->m_pos.x = enemyPlayers[i].x;
				m_enemyList[i]->m_soundEmitter->m_pos.y = enemyPlayers[i].y;
				m_enemyList[i]->m_soundEmitter->m_pos.z = enemyPlayers[i].z;
			}
		}
	}
	CheckPlayersVisible();
}

void PlayerManager::Render(bool p_inMenu)
{
	if (!p_inMenu)
	{
		m_player->Render();
		m_player->RenderAbilityBar();
	}

	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_frustum->CheckSphere(m_enemyList[i]->GetFrustumSphere(), 1.0f))
		{
			if (!p_inMenu && !Network::GetInstance()->GetMatchOver())
			{
				if (m_enemyList[i]->IsVisible() && GraphicsEngine::IsVisibilityPointVisible(Point(m_enemyList[i]->GetPosition().x, m_enemyList[i]->GetPosition().z)))
				{
					if (!m_enemyList[i]->IsInvis())
					{
						m_enemyList[i]->Render();
					}
				}
			}
			else
			{
				m_enemyList[i]->Render();
			}
		}
	}
}

void PlayerManager::RenderOutliningPassOne()
{
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_renderOutlingingEnemies[i])
		{
			if (GraphicsEngine::IsVisibilityPointVisible(Point(m_enemyList[i]->GetPosition().x, m_enemyList[i]->GetPosition().z)))
			{				
				m_enemyList[i]->RenderDepthOutlining();
			}
		}
	}

	if (m_renderOutliningPlayer)
	{
		m_player->RenderDepthOutlining();
	}
}

void PlayerManager::RenderDepth(bool p_inMenu)
{
	if (!p_inMenu)
	{
		m_player->RenderDepth();
	}

	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (!p_inMenu)
		{
			if (GraphicsEngine::IsVisibilityPointVisible(Point(m_enemyList[i]->GetPosition().x, m_enemyList[i]->GetPosition().z)))
			{
				if (!m_enemyList[i]->IsInvis())
				{
					m_enemyList[i]->RenderDepth();
				}
			}
		}
		else
		{
			m_enemyList[i]->RenderDepth();
		}
	}
}

void PlayerManager::RenderOutliningPassTwo()
{
	DirectX::XMFLOAT4 color = DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_renderOutlingingEnemies[i])
		{
			switch (m_enemyList[i]->GetTeam())
			{
			case 1:
				color = DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
				break;
			case 2:
				color = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
				break;
			default:
				break;
			}

			if (GraphicsEngine::IsVisibilityPointVisible(Point(m_enemyList[i]->GetPosition().x, m_enemyList[i]->GetPosition().z)))
			{
				m_enemyList[i]->RenderOutlining(color);
			}
		}
	}

	switch (m_player->GetTeam())
	{
	case 1:
		color = DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
		break;
	case 2:
		color = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
		break;
	default:
		break;
	}

	if (m_renderOutliningPlayer)
	{
		m_player->RenderOutlining(color);
	}
}
void PlayerManager::SetPlayerOutliningRender(bool p_state)
{
	m_renderOutliningPlayer = p_state;
}

void PlayerManager::AddPlayer(int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, std::string p_name)
{
	switch (p_charNr)
	{
		case 0:
		{
			KatanaNinja *tempPlayer = new KatanaNinja();
			tempPlayer->SetSound(m_sound);
			tempPlayer->Initialize(p_pos, p_direction, p_charNr, p_name, 0xff00ffff);
			m_player = tempPlayer;
			m_player->SendPosition(m_player->GetPosition());
			break;
		}

		case 1:
		{
			TessenNinja *tempPlayer = new TessenNinja();
			tempPlayer->SetSound(m_sound);
			tempPlayer->Initialize(p_pos, p_direction, p_charNr, p_name, 0xff00ffff);
			m_player = tempPlayer;
			m_player->SendPosition(m_player->GetPosition());
			break;
		}

		case 2:
		{
			NaginataNinja *tempPlayer = new NaginataNinja();
			tempPlayer->SetSound(m_sound);
			tempPlayer->Initialize(p_pos, p_direction, p_charNr, p_name, 0xff00ffff);
			m_player = tempPlayer;
			m_player->SendPosition(m_player->GetPosition());
			break;
		}

		case 3:
		{
			// Todo change to ninja 4
			KatanaNinja *tempPlayer = new KatanaNinja();
			tempPlayer->SetSound(m_sound);
			tempPlayer->Initialize(p_pos, p_direction, p_charNr, p_name, 0xff00ffff);
			m_player = tempPlayer;
			m_player->SendPosition(m_player->GetPosition());
			break;
		}
	}
}

void PlayerManager::AddEnemy(RakNet::RakNetGUID p_guid, int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, std::string p_name)
{
	switch (p_charNr)
	{
		case 0:
		{
			KatanaNinja *tempPlayer = new KatanaNinja();

			tempPlayer->SetSound(m_sound);
			/*tempPlayer->m_soundEmitter.m_playSound = PLAYSOUND_STEPS_LEAVES_SOUND;
			tempPlayer->m_soundEmitter.m_x = p_pos.x;
			tempPlayer->m_soundEmitter.m_y = p_pos.y;
			tempPlayer->m_soundEmitter.m_z = p_pos.z;
			m_sound->PlayAmbientSound(&tempPlayer->m_soundEmitter);*/

			tempPlayer->Initialize(p_pos, p_direction, p_charNr, p_name, 0xffffffff);
			tempPlayer->SetGuID(p_guid);
			tempPlayer->SetMaxHealth(CHARACTER_KATANA_SHURIKEN_HEALTH);

			AddEnemyToList(tempPlayer);
			break;
		}

		case 1:
		{
			TessenNinja *tempPlayer = new TessenNinja();

			tempPlayer->SetSound(m_sound);

			tempPlayer->Initialize(p_pos, p_direction, p_charNr, p_name, 0xffffffff);
			tempPlayer->SetGuID(p_guid);
			tempPlayer->SetMaxHealth(CHARACTER_TESSEN_HEALTH);
		
			AddEnemyToList(tempPlayer);
			break;
		}

		case 2:
		{
			// Todo change to ninja 3
			NaginataNinja *tempPlayer = new NaginataNinja();

			tempPlayer->SetSound(m_sound);

			tempPlayer->Initialize(p_pos, p_direction, p_charNr, p_name, 0xffffffff);
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

void PlayerManager::ResetCooldowns(bool p_inMenu)
{
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		m_enemyList[i]->ResetCooldowns();
	}
	if (!p_inMenu)
	{
		m_player->ResetCooldowns();
	}
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

Player* PlayerManager::GetEnemyTeamMember(int p_index)
{
	if (m_enemyListSize <= (unsigned int)p_index)
	{
		return nullptr;
	}

	return m_enemyList[p_index];
}

OBB PlayerManager::GetPlayerBoundingBox()
{
	return m_player->GetOBB();
}

Sphere PlayerManager::GetPlayerSphere()
{
	return m_player->GetSphere();
}

std::vector<OBB> PlayerManager::GetEnemyPlayerBoundingBoxes()
{
	std::vector<OBB> returnList;
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		returnList.push_back(m_enemyList[i]->GetOBB());
	}
	return returnList;
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

//DirectX::XMFLOAT3 PlayerManager::GetTeamMemberPosSpectate(int &p_index, int p_team)
//{
//	for (unsigned int i = 0; i < m_enemyListSize; i++)
//	{
//		if (m_enemyListSize <= (unsigned int)p_index || p_index == -1)
//		{
//			p_index = -1;
//			return m_player->GetPosition();
//		}
//
//		if (m_enemyList[p_index]->GetTeam() == p_team)
//		{
//			return m_enemyList[p_index]->GetPosition();
//		}
//		p_index++;
//	}
//
//	return m_player->GetPosition();
//}

std::vector<Player*> PlayerManager::GetMyTeamPlayers(int p_team)
{
	std::vector<Player*> tempList;
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_enemyList[i]->GetIsAlive())
		{
			if (m_enemyList[i]->GetTeam() == p_team)
			{
				tempList.push_back(m_enemyList[i]);
			}
		}
	}
	return tempList;
}
bool PlayerManager::GetPlayerIsAlive()
{
	return m_player->GetIsAlive();
}

int PlayerManager::GetNrOfPlayersInTeam(int p_team)
{
	int nrOfTeamMates = 0;
	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		if (m_enemyList[i]->GetTeam() == p_team)
		{
			nrOfTeamMates += 1;
		}
	}
	return nrOfTeamMates;
}

void PlayerManager::SetSound(Sound* p_sound)
{
	m_sound = p_sound;
}

void PlayerManager::SetStickyTrapList(std::vector<StickyTrap*> p_stickyTrapList)
{
	m_player->SetStickyTrapList(p_stickyTrapList);
}

std::vector<Player*> PlayerManager::GetEveryPlayer()
{
	std::vector<Player*> players;

	for (unsigned int i = 0; i < m_enemyListSize; i++)
	{
		players.push_back(m_enemyList[i]);
	}

	players.push_back(m_player);

	return players;
}

void PlayerManager::SetOutliningPerEnemy(bool p_renderOutlingingEnemies, int p_index)
{
	m_renderOutlingingEnemies[p_index] = p_renderOutlingingEnemies;
}