#include "SuddenDeathState.h"
#include "GUIElement.h"
#include "GUIText.h"
#include "Globals.h"
#include "ParticleEmitter.h"
#include "GraphicsEngine.h"

SuddenDeathState::SuddenDeathState(){}
SuddenDeathState::~SuddenDeathState(){}
void SuddenDeathState::Initialize(std::vector<Box> p_walls)
{
	m_title = new GUIText();
	m_title->Initialize("SUDDEN FUCKING DEATH", 50.0f, 0.0f, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT*0.25f, 0xffffffff);
	m_walls = p_walls;
	float xMax = 0, xMin = 0;
	float zMax = 0, zMin = 0;
	for (unsigned int i = 0; i < m_walls.size(); i++)
	{
		if (m_walls[i].m_center.x > 0.0f)
		{
			xMax = m_walls[i].m_center.x;
		}
		if (m_walls[i].m_center.x < 0.0f)
		{
			xMin = m_walls[i].m_center.x;
		}
		if (m_walls[i].m_center.z > 0.0f)
		{
			zMax = m_walls[i].m_center.z;
		}
		if (m_walls[i].m_center.z < 0.0f)
		{
			zMin = m_walls[i].m_center.z;
		}
	}

	for (unsigned int i = 0; i < 8; i++)
	{
		m_gasParticle[i] = new ParticleEmitter();
	}
	float xLength = xMax - xMin;
	float zLength = zMax - zMin;
	std::vector<DirectX::XMFLOAT3> positions;
	positions.push_back(DirectX::XMFLOAT3(-xLength / 4.0f, 0.0f, zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(0.0f, 0.0f, zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(xLength / 4.0f, 0.0f, zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(-xLength / 4.0f, 0.0f, 0.0f));
	positions.push_back(DirectX::XMFLOAT3(xLength / 4.0f, 0.0f, 0.0f));
	positions.push_back(DirectX::XMFLOAT3(-xLength / 4.0f, 0.0f, -zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(0.0f, 0.0f, -zLength / 4.0f));
	positions.push_back(DirectX::XMFLOAT3(xLength / 4.0f, 0.0f, -zLength / 4.0f));
	for (unsigned int i = 0; i < 8; i++)
	{
		m_gasParticle[i]->Initialize(GraphicsEngine::GetInstance()->GetDevice(), positions[i], DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(5.0f, 5.0f), PARTICLE_PATTERN_SUDDENDEATH);
	}
	for (unsigned int i = 0; i < 8; i++)
	{
		float sdXMax = positions[i].x + (xLength / 7.0f) - 1.0f;
		float sdXMin = positions[i].x - (xLength / 7.0f) + 1.0f;
		float sdZMax = positions[i].z + (zLength / 7.0f) - 1.0f;
		float sdZMin = positions[i].z - (zLength / 7.0f) + 1.0f;
		m_gasParticle[i]->SetSuddenDeathBoxLimits(sdXMax, sdXMin, sdZMax, sdZMin);
	}
	for (unsigned int i = 0; i < 8; i++)
	{
		m_gasParticle[i]->SetEmitParticleState(true);
	}
}
void SuddenDeathState::Update()
{
	for (unsigned int i = 0; i < 8; i++)
	{
		if (m_gasParticle[i] != nullptr)
		{
			m_gasParticle[i]->Update();
		}
	}
}
void SuddenDeathState::Shutdown()
{
	for (unsigned int i = 0; i < 8; i++)
	{
		if (m_gasParticle[i] != nullptr)
		{
			m_gasParticle[i]->Shutdown();
			delete m_gasParticle[i];
			m_gasParticle[i] = nullptr;
		}
	}
	if (m_title != nullptr)
	{
		m_title->Shutdown();
		delete m_title;
		m_title = nullptr;
	}
}
void SuddenDeathState::Render()
{
	m_title->Render();

	for (unsigned int i = 0; i < 8; i++)
	{
		if (m_gasParticle[i] != nullptr)
		{
			m_gasParticle[i]->Render();
		}
	}
}
void SuddenDeathState::StartEmittingParticles(int p_index)
{
	m_gasParticle[p_index]->SetEmitParticleState(true);
}