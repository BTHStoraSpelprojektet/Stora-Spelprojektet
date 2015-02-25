#include "VictoryScreenMenu.h"
#include "TextureLibrary.h"


VictoryScreenMenu::VictoryScreenMenu(){}
VictoryScreenMenu::~VictoryScreenMenu(){}

bool VictoryScreenMenu::Initialize()
{
	m_menu = new Menu();
	
	// Continue button
	m_menu->AddButton(0.0f, -1.0f * BUTTONHEIGHT - 2.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/continue.png"), MENUACTION_INGAME_CONTINUE);
	// Main menu button
	m_menu->AddButton(0.0f, -2.0f * BUTTONHEIGHT - 3.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/main_menu.png"), MENUACTION_INGAME_TO_MAIN);

	return true;
}

void VictoryScreenMenu::Shutdown()
{
	if (m_menu != nullptr)
	{
		m_menu->Shutdown();
		delete m_menu;
		m_menu = nullptr;
	}
}

IN_GAME_MENU_ACTION VictoryScreenMenu::Update()
{
	MenuActionData menuData = m_menu->Update();
	switch (menuData.m_action)
	{
		case MENUACTION_INGAME_CONTINUE:
		{
			return IN_GAME_MENU_CONTINUE;
			break;
		}
		case MENUACTION_INGAME_TO_MAIN:
		{
			return IN_GAME_MENU_TO_MAIN;
			break;
		}		
		default:
		{
			return IN_GAME_MENU_IDLE;
			break;
		}
	}
}

void VictoryScreenMenu::Render()
{
	m_menu->Render();
}