#include "CreaditsScreen.h"
#include "GUIText.h"
#include "Globals.h"


CreaditsScreen::CreaditsScreen(){}
CreaditsScreen::~CreaditsScreen(){}

void CreaditsScreen::Initialize()
{
	std::string developerText = "adhdgfhdjfhkjfhkfgkhfgkghjkghjkghjkghjkgjkghjkghjkghjkghjk";
	m_developers = new GUIText();
	m_developers->Initialize(developerText, 25.0f, 0.0f, -200.0f, 0xffffffff);
	m_developersTextPositionY = 0.0;

	m_music = new GUIText();
	m_music->Initialize("a", 25.0f, 0.0f, -200.0f, 0xffffffff);

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
	float textMoveSpeed = 1.0f * GLOBAL::GetInstance().GetDeltaTime();

	m_developersTextPositionY += textMoveSpeed;
	m_developers->SetPosition(0.0f, m_developersTextPositionY);
	m_music->SetPosition(0.0f, 0.0f);
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
	m_developers->SetPosition(0.0f, 0.0f);
	m_music->SetPosition(0.0f, 0.0f);
	m_developersTextPositionY = 0.0;
}