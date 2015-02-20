#include "InGameMenu.h"
#include "TextureLibrary.h"

InGameMenu::InGameMenu(){}
InGameMenu::~InGameMenu(){}
void InGameMenu::Initialize()
{
	m_menu = new Menu();
	//Resume button
	m_menu->AddButton(0.0f, -BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, 
		TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/resume.png"), MENUACTION_INGAME_RESUME);
	//Main menu button
	m_menu->AddButton(0.0f, -1.0f * BUTTONHEIGHT - 2.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, 
		TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/main_menu.png"), MENUACTION_INGAME_TO_MAIN);
	//Quit button
	m_menu->AddButton(0.0f, -2.0f * BUTTONHEIGHT - 3.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, 
		TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/quit.png"), MENUACTION_INGAME_QUIT);
}
void InGameMenu::Shutdown()
{
	if (m_menu != nullptr)
	{
		m_menu->Shutdown();
		delete m_menu;
		m_menu = nullptr;
	}
}
IN_GAME_MENU_ACTION InGameMenu::Update()
{
	MenuActionData menuData = m_menu->Update();
	switch (menuData.m_action)
	{
	case MENUACTION_INGAME_RESUME:
		return IN_GAME_MENU_RESUME;
		break;
	case MENUACTION_INGAME_TO_MAIN:
		return IN_GAME_MENU_TO_MAIN;
		break;
	case MENUACTION_INGAME_QUIT:
		return IN_GAME_MENU_QUIT;
		break;
	default:
		return IN_GAME_MENU_IDLE;
		break;
	}
}
void InGameMenu::Render()
{
	m_menu->Render();
}
