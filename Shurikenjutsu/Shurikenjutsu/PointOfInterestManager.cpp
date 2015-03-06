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
	for(unsigned int i = 0; i < m_runes.size(); i++)
	{
		m_runes[i].Shutdown();
	}
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

void PointOfInterestManager::SpawnRunes(POINTOFINTERESTTYPE p_poiType, float p_x, float p_y, float p_z)
{
	PointOfInterest temp;
	
	switch (p_poiType)
	{
	case POINTOFINTERESTTYPE_HEAL:
		temp.Initialize(RUNE_LOTUS, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f, DirectX::XMFLOAT3(1.0f, 0.0f, 0.5f));
		temp.SetActive(true);
		m_runes.push_back(temp);
		break;
	case POINTOFINTERESTTYPE_INVISIBLE:
		temp.Initialize(RUNE_INVIS, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f, DirectX::XMFLOAT3(0.4f, 0.02f, 0.64f));
		temp.SetActive(true);
		m_runes.push_back(temp);
		break;
	case POINTOFINTERESTTYPE_SHIELD:
		temp.Initialize(RUNE_SHIELD, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f, DirectX::XMFLOAT3(1.0f, 1.0f, 0.0f));
		temp.SetActive(true);
		m_runes.push_back(temp);
		break;
	default:
		break;
	}
}

void PointOfInterestManager::RunePickedUp(POINTOFINTERESTTYPE p_poiType)
{
	if (m_runes.size() == 0)
	{
		return;
	}
	switch (p_poiType)
	{
	case POINTOFINTERESTTYPE_HEAL:
		m_runes[0].SetActive(false);
		break;
	case POINTOFINTERESTTYPE_INVISIBLE:
		m_runes[1].SetActive(false);
		break;
	case POINTOFINTERESTTYPE_SHIELD:
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