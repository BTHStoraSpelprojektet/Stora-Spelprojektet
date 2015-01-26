#include "MenuState.h"
#include "Menu.h"
#include "MenuIpBox.h"
#include "GUIText.h"
#include "Globals.h"
#include "TextureLibrary.h"
#include "GraphicsEngine.h"

MenuState::MenuState(){}
MenuState::~MenuState(){}

bool MenuState::Initialize()
{
	// Initialize options menu
	m_options = new Menu();
	m_options->AddCheckbox(220.0f, 0, MENUACTION_VSYNC, false);
	m_options->AddCheckbox(220.0f, -70.0f, MENUACTION_FULLSCREEN, false);
	m_options->AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"));

	// Initialize main menu
	m_main = new Menu();
	m_main->AddButton(0, 0, 360.0f, 60.0f, MENUACTION_IP, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"));
	m_main->AddButton(0, -70.0f, 360.0f, 60.0f, MENUACTION_CHOOSENINJA, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/choose.png"));
	m_main->AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_OPTIONS, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/options.png"));
	m_main->AddButton(0, -210.0f, 360.0f, 60.0f, MENUACTION_BACK, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/quit.png"));

	// Initialize play menu
	m_ipbox = new MenuIpBox();
	m_ipbox->Initialize(0.0f, 0, 360.0f, 60.0f);
	m_ipboxText = new GUIText();
	m_ipboxText->Initialize(m_ipbox->GetIp(), 36.0f, 0.0f, 0.0f, 0xffffffff);

	m_play = new Menu();
	m_play->AddButton(0, -70.0f, 360.0f, 60.0f, MENUACTION_CONNECT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/connect.png"));
	m_play->AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"));
	m_hideIpBox = true;

	// Initialize connecting menu;
	//m_connecting.AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK); // 
	m_connecting = new Menu();

	// Push main menu
	m_menues.push(m_main);

	return true;
}

void MenuState::Shutdown()
{
	if (m_main != NULL)
	{
		m_main->Shutdown();
		delete m_main;
		m_main = 0;
	}
	if (m_options != NULL)
	{
		m_options->Shutdown();
		delete m_options;
		m_options = 0;
	}
	if (m_play != NULL)
	{
		m_play->Shutdown();
		delete m_play;
		m_play = 0;
	}
	if (m_connecting != NULL)
	{
		m_connecting->Shutdown();
		delete m_connecting;
		m_connecting = 0;
	}
	if (m_ipbox != NULL)
	{
		delete m_ipbox;
		m_ipbox = 0;
	}
	if (m_ipboxText != NULL)
	{
		delete m_ipboxText;
		m_ipboxText = 0;
	}
}
GAMESTATESWITCH MenuState::Update()
{
	MenuActionData action = m_menues.top()->Update();

	// Ipbox special case
	if (!m_hideIpBox)
	{
		m_ipbox->IsClicked();
		m_ipbox->GetInput();
	}

	// Check buttons
	switch (action.m_action)
	{
		case MENUACTION_BACK:
			m_hideIpBox = true;
			m_menues.pop();
			if (m_menues.empty())
			{
				PostQuitMessage(0);
			}
			break;
		case MENUACTION_IP:
			m_hideIpBox = false;
			m_menues.push(m_play);
			break;
		case MENUACTION_PLAY:
			break;
		case MENUACTION_CHOOSENINJA:
			return GAMESTATESWITCH_CHOOSENINJA;
			break;
		case MENUACTION_OPTIONS:
			m_menues.push(m_options);
			break;

		case MENUACTION_CONNECT:
			m_menues.push(m_connecting);
			m_hideIpBox = true;
			Network::GetInstance()->Connect((std::string)m_ipbox->GetIp());
			Network::GetInstance()->SetNetworkStatusConnecting();
			break;

		case MENUACTION_VSYNC:
			GraphicsEngine::ToggleFullscreen(true);
			break;
		case MENUACTION_FULLSCREEN:

			break;
	}

	// Check network status
	NETWORKSTATUS ns = Network::GetInstance()->GetNetworkStatus();

	switch (ns)
	{
	case NETWORKSTATUS_NONE:
		break;
	case NETWORKSTATUS_TIMEOUT:
		m_menues.pop();
		m_hideIpBox = false;
		break;
	case NETWORKSTATUS_CONNECTED:
		return GAMESTATESWITCH_PLAY;
		break;

	}

	m_ipboxText->SetText(m_ipbox->GetIp());

	return GAMESTATESWITCH_NONE;
}

void MenuState::Render()
{
	if (!m_menues.empty())
	{
		if (m_menues.top() != NULL)
		{
			m_menues.top()->Render();
		}
	}

	// Special case for ipbox
	if (!m_hideIpBox)
	{
		m_ipbox->Render();
		m_ipboxText->Render();
	}
}