#include "PointOfInterestManager.h"
#include "PointOfInterest.h"
#include <DirectXMath.h>
#include "../CommonLibs/ModelNames.h"

PointOfInterestManager::PointOfInterestManager()
{
}


PointOfInterestManager::~PointOfInterestManager()
{
}


bool PointOfInterestManager::Initialize()
{
	m_nrOfRunes = 3;

	DirectX::XMFLOAT3 spawnPoints[3];
	spawnPoints[0] = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
	spawnPoints[1] = DirectX::XMFLOAT3(0.0f, 1.0f, -10.0f);
	spawnPoints[2] = DirectX::XMFLOAT3(0.0f, 1.0f, 10.0f);

	PointOfInterest temp;

	temp.Initialize(RUNE_HOT, spawnPoints[0], DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
	m_runes.push_back(temp);

	temp.Initialize(RUNE_INVIS, spawnPoints[1], DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
	m_runes.push_back(temp);

	temp.Initialize(RUNE_SHIELD, spawnPoints[2], DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f);
	m_runes.push_back(temp);

	return true;
}

void PointOfInterestManager::Shutdown()
{
	m_runes.clear();
}

void PointOfInterestManager::Update()
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

void PointOfInterestManager::SpawnRunes()
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		m_runes[i].SetActive(true);
	}
}

void PointOfInterestManager::PickUprunes()
{

}