#include "DeathBoard.h"
#include "GUIElement.h"
#include "TextureLibrary.h"
#include "Globals.h"
#include "../CommonLibs/ModelNames.h"
DeathBoard* DeathBoard::m_instance;

DeathBoard::DeathBoard(){}
DeathBoard::~DeathBoard(){}

DeathBoard* DeathBoard::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new DeathBoard();
	}

	return m_instance;
}

bool DeathBoard::Initialize()
{
	DirectX::XMFLOAT3 m_originalPos = DirectX::XMFLOAT3((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - 140, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT* 0.5f - 30, 0);
	m_deathTimer = 0.0;
	m_killer = new GUIElement();
	m_deadGuy = new GUIElement();
	m_killAbility = new GUIElement();

	m_killer->Initialize(m_originalPos, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_KILL1));
	m_originalPos.x += 55;

	m_killAbility->Initialize(m_originalPos, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_KILL3));
	m_originalPos.x += 55;

	m_deadGuy->Initialize(m_originalPos, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_KILL2));


	return true;
}

void DeathBoard::Shutdown()
{
	if (m_killer != nullptr)
	{
		delete m_killer;
		m_killer = nullptr;
	}
	if (m_deadGuy != nullptr)
	{
		delete m_deadGuy;
		m_deadGuy = nullptr;
	}
	if (m_killAbility != nullptr)
	{
		delete m_killAbility;
		m_killAbility = nullptr;
	}

	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}

}

void DeathBoard::Update()
{
	if (m_deathTimer > 0.0)
	{
		m_deathTimer -= GLOBAL::GetInstance().GetDeltaTime();
	}
}

void DeathBoard::Render()
{
	if (m_deathTimer > 0)
	{
		m_killer->QueueRender();
		m_killAbility->QueueRender();
		m_deadGuy->QueueRender();
	}
}

void DeathBoard::DeathEverywhere()
{
	if (m_deathTimer > 0.0)
	{

	}
	m_deathTimer = 5.0;
	
}