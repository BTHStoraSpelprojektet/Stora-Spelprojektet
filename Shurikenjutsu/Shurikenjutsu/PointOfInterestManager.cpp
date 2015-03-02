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

void PointOfInterestManager::SpawnRunes(int p_index, float p_x, float p_y, float p_z)
{
	PointOfInterest temp;
	
	switch (p_index)
	{
	case 0:
	{
		temp.Initialize(RUNE_LOTUS, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
		temp.SetActive(true);
		m_runes.push_back(temp);

		break;
	}
	case 1:
	{
		temp.Initialize(RUNE_INVIS, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
		temp.SetActive(true);
		m_runes.push_back(temp);
	
		break;
	}
	case 2:
	{
		temp.Initialize(RUNE_SHIELD, DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
		temp.SetActive(true);
		m_runes.push_back(temp);

		break;
	}
	default:
		break;
	}
}

void PointOfInterestManager::RunePickedUp(int p_index)
{
	if (p_index >= 0 && p_index < m_runes.size())
	{
		m_runes[p_index].SetActive(false);
	}
}

void PointOfInterestManager::RoundRestart()
{
	Shutdown();
	Initialize();
}