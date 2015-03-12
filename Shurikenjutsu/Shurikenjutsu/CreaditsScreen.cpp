#include "CreaditsScreen.h"
#include "GUIText.h"
#include "Globals.h"
#include "TextResource.h"
#include "Menu.h"

CreaditsScreen::CreaditsScreen(){}
CreaditsScreen::~CreaditsScreen(){}

void CreaditsScreen::Initialize()
{
	m_originalDevPosY = -500.0f;
	m_originalMusPosY = -2000.0f;
	m_developers = new GUIText();
	m_developers->Initialize(CREDITS_DEVELOPERS, 45.0f, 0.0f, m_originalDevPosY, 0xffffffff);
	m_developersTextPositionY = m_originalDevPosY;
	
	m_music = new GUIText();
	m_music->Initialize(CREDITS_MUSIC, 35.0f, 0.0f, m_originalMusPosY, 0xffffffff);
	m_musicTextPositionY = m_originalMusPosY;
}
void CreaditsScreen::Shutdown()
{
	Menu::Shutdown();
	if (m_developers != nullptr)
	{
		m_developers->Shutdown();
		delete m_developers;
		m_developers = nullptr;
	}
	if (m_music != nullptr)
	{
		m_music->Shutdown();
		delete m_music;
		m_music = nullptr;
	}
}
MenuActionData CreaditsScreen::Update()
{
	MenuActionData returnMenuAction = Menu::Update();
	float textMoveSpeed = 130.0f * (float)GLOBAL::GetInstance().GetDeltaTime();

	m_developersTextPositionY += textMoveSpeed;
	m_musicTextPositionY += textMoveSpeed;

	m_developers->SetPosition(0.0f, m_developersTextPositionY);
	m_music->SetPosition(0.0f, m_musicTextPositionY);
	return returnMenuAction;
}
void CreaditsScreen::Render()
{
	Menu::Render();
	m_developers->Render();
	m_music->Render();
}

void CreaditsScreen::ResetTexts()
{
	m_developersTextPositionY = m_originalDevPosY;
	m_musicTextPositionY = m_originalMusPosY;
	m_developers->SetPosition(0.0f, m_developersTextPositionY);
	m_music->SetPosition(0.0f, m_musicTextPositionY);
}