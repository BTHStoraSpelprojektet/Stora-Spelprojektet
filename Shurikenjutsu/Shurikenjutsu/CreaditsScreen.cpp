#include "CreaditsScreen.h"
#include "GUIText.h"
#include "Globals.h"
#include "TextResource.h"


CreaditsScreen::CreaditsScreen(){}
CreaditsScreen::~CreaditsScreen(){}

void CreaditsScreen::Initialize()
{
	m_developers = new GUIText();
	m_developers->InitializeCalibri(CREDITS_DEVELOPERS, 40.0f, 0.0f, -500.0f, 0xffffffff);
	m_developersTextPositionY = -500.0f;
	
	m_music = new GUIText();
	m_music->InitializeCalibri(CREDITS_MUSIC, 25.0f, 0.0f, -2200.0f, 0xffffffff);
	m_musicTextPositionY = -2200.0f;
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
	m_developers->SetPosition(0.0f, -500.0f);
	m_music->SetPosition(0.0f, -2200.0f);
	m_developersTextPositionY = -500.0f;
	m_musicTextPositionY = -2200.0f;
}