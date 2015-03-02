#include "PointOfInterestManager.h"
#include <DirectXMath.h>
#include "../CommonLibs/ModelNames.h"
#include "Collisions.h"

PointOfInterestManager::PointOfInterestManager()
{
}


PointOfInterestManager::~PointOfInterestManager()
{
}


bool PointOfInterestManager::Initialize()
{
	m_nrOfRunes = 3;

	return true;
}

void PointOfInterestManager::Shutdown()
{
	m_runes.clear();
}

void PointOfInterestManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i].IsActive())
		{
			m_runes[i].Update();
		}
	}
}

void PointOfInterestManager::Render()
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i].IsActive())
		{
			m_runes[i].Render();
		}
	}
}

void PointOfInterestManager::RenderDepth()
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i].IsActive())
		{
			m_runes[i].RenderDepth();
		}
	}
}

void PointOfInterestManager::SpawnRunes(PointOfInterestType p_poiType, float p_x, float p_y, float p_z)
{
	PointOfInterest temp;
	
	switch (p_poiType)
	{
	case PointOfInterestType_Heal:
		temp.Initialize(RUNE_LOTUS, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
		temp.SetActive(true);
		m_runes.push_back(temp);
		break;
	case PointOfInterestType_Invisible:
		temp.Initialize(RUNE_INVIS, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
		temp.SetActive(true);
		m_runes.push_back(temp);
		break;
	case PointOfInterestType_Shield:
		temp.Initialize(RUNE_SHIELD, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
		temp.SetActive(true);
		m_runes.push_back(temp);
		break;
	default:
		break;
	}
}

void PointOfInterestManager::RunePickedUp(PointOfInterestType p_poiType)
{
	switch (p_poiType)
	{
	case PointOfInterestType_Heal:
		m_runes[0].SetActive(false);
		break;
	case PointOfInterestType_Invisible:
		m_runes[1].SetActive(false);
		break;
	case PointOfInterestType_Shield:
		m_runes[2].SetActive(false);
		break;
	default:
		break;
	}
}

void PointOfInterestManager::RoundRestart()
{
	Shutdown();
	Initialize();
}