#include "PointOfInterestManager.h"
#include <DirectXMath.h>
#include "../CommonLibs/ModelNames.h"
#include "Collisions.h"
#include "PointOfInterest.h"

PointOfInterestManager::PointOfInterestManager(){}
PointOfInterestManager::~PointOfInterestManager(){}

bool PointOfInterestManager::Initialize()
{
	m_nrOfRunes = 3;
	m_runes = std::vector<PointOfInterest*>();

	PointOfInterest* healPOI = new PointOfInterest();
	healPOI->Initialize(POINTOFINTERESTTYPE_HEAL, RUNE_LOTUS, DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f, DirectX::XMFLOAT3(1.0f, 0.0f, 0.5f));
	healPOI->SetActive(false);

	PointOfInterest* invisPOI = new PointOfInterest();
	invisPOI->Initialize(POINTOFINTERESTTYPE_INVISIBLE, RUNE_INVIS, DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f, DirectX::XMFLOAT3(0.4f, 0.02f, 0.64f));
	invisPOI->SetActive(false);

	PointOfInterest* shieldPOI = new PointOfInterest();
	shieldPOI->Initialize(POINTOFINTERESTTYPE_SHIELD, RUNE_SHIELD, DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0.0f, DirectX::XMFLOAT3(1.0f, 1.0f, 0.0f));
	shieldPOI->SetActive(false);

	m_runes.push_back(healPOI);
	m_runes.push_back(invisPOI);
	m_runes.push_back(shieldPOI);
	return true;
}

void PointOfInterestManager::Shutdown()
{
	for(unsigned int i = 0; i < m_runes.size(); i++)
	{
		m_runes[i]->Shutdown();
		delete m_runes[i];
	}
	m_runes.clear();
}

void PointOfInterestManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i]->IsActive())
		{
			m_runes[i]->Update();
		}
	}
}

void PointOfInterestManager::Render()
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i]->IsActive())
		{
			m_runes[i]->Render();
		}
	}
}

void PointOfInterestManager::RenderDepth()
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i]->IsActive())
		{
			m_runes[i]->RenderDepth();
		}
	}
}

void PointOfInterestManager::SpawnRune(POINTOFINTERESTTYPE p_poiType, float p_x, float p_y, float p_z)
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i]->GetType() == p_poiType)
		{
			m_runes[i]->SetPosition(DirectX::XMFLOAT3(p_x, p_y, p_z));
			m_runes[i]->SetActive(true);
		}
	}
}

void PointOfInterestManager::DespawnRune(POINTOFINTERESTTYPE p_poiType)
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i]->GetType() == p_poiType)
		{
			m_runes[i]->SetActive(false);
		}
	}
}

void PointOfInterestManager::RunePickedUp(POINTOFINTERESTTYPE p_poiType)
{
	for (unsigned int i = 0; i < m_runes.size(); i++)
	{
		if (m_runes[i]->GetType() == p_poiType)
		{
			m_runes[i]->SetActive(false);
		}
	}
}

void PointOfInterestManager::RoundRestart()
{
	Shutdown();
	Initialize();
}