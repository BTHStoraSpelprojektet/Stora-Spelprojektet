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

	m_gasParticle[0] = new ParticleEmitter();
	m_gasParticle[1] = new ParticleEmitter();
	m_gasParticle[2] = new ParticleEmitter();
	m_gasParticle[3] = new ParticleEmitter();
	m_walls = p_walls;
	
	//m_gasParticle[0]->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(0.0f,0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(50.0f, 50.0f), PARTICLE_PATTERN_SMOKE);
	m_gasParticle[0]->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(m_walls[0].m_center.x, m_walls[0].m_center.y, m_walls[0].m_center.z), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(25.0f, 25.0f), PARTICLE_PATTERN_WORLD_MIST);
	m_gasParticle[1]->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(m_walls[1].m_center.x, m_walls[1].m_center.y, m_walls[1].m_center.z), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(25.0f, 25.0f), PARTICLE_PATTERN_WORLD_MIST);
	m_gasParticle[2]->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(m_walls[2].m_center.x, m_walls[2].m_center.y, m_walls[2].m_center.z), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(25.0f, 25.0f), PARTICLE_PATTERN_WORLD_MIST);
	m_gasParticle[3]->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(m_walls[3].m_center.x, m_walls[3].m_center.y, m_walls[3].m_center.z), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(25.0f, 25.0f), PARTICLE_PATTERN_WORLD_MIST);

	m_gasParticle[0]->SetEmitParticleState(true);
	m_gasParticle[1]->SetEmitParticleState(true);
	m_gasParticle[2]->SetEmitParticleState(true);
	m_gasParticle[3]->SetEmitParticleState(true);
}
void SuddenDeathState::Update()
{
	m_gasParticle[0]->Update();
	m_gasParticle[1]->Update();
	m_gasParticle[2]->Update();
	m_gasParticle[3]->Update();
}
void SuddenDeathState::Shutdown()
{
	if (m_gasParticle[0] != nullptr)
	{
		m_gasParticle[0]->Shutdown();
		delete m_gasParticle[0];
		m_gasParticle[0] = nullptr;
	}
	if (m_gasParticle[1] != nullptr)
	{
		m_gasParticle[1]->Shutdown();
		delete m_gasParticle[1];
		m_gasParticle[1] = nullptr;
	}
	if (m_gasParticle[2] != nullptr)
	{
		m_gasParticle[2]->Shutdown();
		delete m_gasParticle[2];
		m_gasParticle[2] = nullptr;
	}
	if (m_gasParticle[3] != nullptr)
	{
		m_gasParticle[3]->Shutdown();
		delete m_gasParticle[3];
		m_gasParticle[3] = nullptr;
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
	m_gasParticle[0]->Render();
	m_gasParticle[1]->Render();
	m_gasParticle[2]->Render();
	m_gasParticle[3]->Render();
}