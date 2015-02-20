#include "InGameMenu.h"
#include "MenuButton.h"
#include "Menu.h"
#include "TextureLibrary.h"

InGameMenu::InGameMenu(){}
InGameMenu::~InGameMenu(){}
void InGameMenu::Initialize()
{
	m_menu = new Menu();
	//Resume button
	m_menu->AddButton(0.0f, -BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"), MENUACTION_IP);
	//Main menu button
	m_menu->AddButton(0.0f, -1.0f * BUTTONHEIGHT - 2.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/options.png"), MENUACTION_OPTIONS);
	//Quit button
	m_menu->AddButton(0.0f, -2.0f * BUTTONHEIGHT - 3.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/quit.png"), MENUACTION_BACK);
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
void InGameMenu::Update()
{
	m_menu->Update();
}
void InGameMenu::Render()
{
	m_menu->Render();
}
