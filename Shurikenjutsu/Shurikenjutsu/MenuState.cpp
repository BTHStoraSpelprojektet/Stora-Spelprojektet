#include "MenuState.h"
#include "Menu.h"
#include "MenuIpBox.h"
#include "GUIText.h"
#include "Globals.h"
#include "TextureLibrary.h"
#include "GraphicsEngine.h"

// BUTTON
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;
const float BUTTONOFFSET = 10.0f;

// CHECKBOX
const float CHECKBOXSIZE = 100.0f;

// VSYNC
const float VSYNCWIDTH = 254.0f;
const float VSYNCHEIGHT = 59.0f;

// FULLSCREEN
const float FULLSCREENWIDTH = 173.0f;
const float FULLSCREENHEIGHT = 58.0f;


MenuState::MenuState(){}
MenuState::~MenuState(){}

bool MenuState::Initialize()
{
	m_lastvsync = false;
	m_lastfullscreen = false;

	// Initialize options menu
	m_options = new Menu();
	m_vsyncIndex = m_options->AddCheckbox(BUTTONWIDTH - CHECKBOXSIZE*0.5f, 0.0f, MENUACTION_VSYNC, false);
	m_options->AddTexture(-BUTTONWIDTH + VSYNCWIDTH*0.5f, 0.0f, VSYNCWIDTH, VSYNCHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/vs_text.png"));

	m_fullscreenIndex = m_options->AddCheckbox(BUTTONWIDTH - CHECKBOXSIZE*0.5f, -CHECKBOXSIZE - BUTTONOFFSET, MENUACTION_FULLSCREEN, false);
	m_options->AddTexture(-BUTTONWIDTH + FULLSCREENWIDTH*0.5f, -CHECKBOXSIZE, FULLSCREENWIDTH, FULLSCREENHEIGHT - BUTTONOFFSET, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/fullscreen_text.png"));

	m_options->AddButton(BUTTONWIDTH*0.5f + 10.0f, -3.0f * CHECKBOXSIZE, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"), MENUACTION_BACK);
	m_options->AddButton(-BUTTONWIDTH*0.5f - 10.0f, -3.0f * CHECKBOXSIZE, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/apply.png"), MENUACTION_OPTIONAPPLY);

	// Initialize main menu
	m_main = new Menu();
	m_main->AddButton(0.0f, -BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"), MENUACTION_IP);
	//m_main->AddButton(0.0f, -BUTTONHEIGHT - 2.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/choose.png"), MENUACTION_CHOOSENINJA);
	m_main->AddButton(0.0f, -1.0f * BUTTONHEIGHT - 2.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/options.png"), MENUACTION_OPTIONS);
	m_main->AddButton(0.0f, -2.0f * BUTTONHEIGHT - 3.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/quit.png"), MENUACTION_BACK);

	// Initialize play menu
	m_ipbox = new MenuIpBox();
	m_ipbox->Initialize(0.0f, 0.0f, BUTTONWIDTH*0.75f, BUTTONHEIGHT*0.5f);
	m_ipboxText = new GUIText();
	m_ipboxText->Initialize(m_ipbox->GetIp(), 36.0f, 0.0f, 0.0f, 0xffffffff);

	m_play = new Menu();
	m_play->AddButton(0.0f, -BUTTONHEIGHT - 2.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/connect.png"), MENUACTION_CONNECT);
	m_play->AddButton(0.0f, -2.0f*BUTTONHEIGHT -3.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"), MENUACTION_BACK);
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
		if (m_ipbox->IsClicked())
		{
			m_ipboxText->SetText(m_ipbox->GetIp());
		}
		if (m_ipbox->GetInput())
		{
			m_ipboxText->SetText(m_ipbox->GetIp());
		}
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
			m_options->SetCheckboxState(m_vsyncIndex, m_lastvsync);
			m_options->SetCheckboxState(m_fullscreenIndex, m_lastfullscreen);
			break;

		case MENUACTION_CONNECT:
			m_menues.push(m_connecting);
			m_hideIpBox = true;
			Network::GetInstance()->Connect((std::string)m_ipbox->GetIp());
			Network::GetInstance()->SetNetworkStatusConnecting();
			break;

		case MENUACTION_OPTIONAPPLY:
			bool temp = m_options->GetCheckboxState(m_vsyncIndex);
			m_lastvsync = temp;
			GraphicsEngine::SetVsync(temp);

			temp = m_options->GetCheckboxState(m_fullscreenIndex);
			m_lastfullscreen = temp;
			GraphicsEngine::ToggleFullscreen(temp);
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
		m_menues.pop();
		m_hideIpBox = false;
		return GAMESTATESWITCH_CHOOSENINJA;
		break;

	}

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
