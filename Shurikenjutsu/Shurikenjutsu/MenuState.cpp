#include "MenuState.h"

MenuState::MenuState(){}
MenuState::~MenuState(){}

bool MenuState::Initialize()
{
	// Initialize options menu
	m_options.AddCheckbox(220.0f, 0, 60.0f, MENUACTION_VSYNC);
	m_options.AddCheckbox(220.0f, -70.0f, 60.0f, MENUACTION_FULLSCREEN);
	m_options.AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK);

	// Initialize main menu
	m_main.AddButton(0, 0, 360.0f, 60.0f, MENUACTION_IP);
	m_main.AddButton(0, -70.0f, 360.0f, 60.0f, MENUACTION_OPTIONS);
	m_main.AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK);

	// Initialize play menu
	m_ipbox.Initialize(0.0f, 0, 360.0f, 60.0f);
	m_ipboxText.Initialize(m_ipbox.GetIp(), 36.0f, GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH*1.5f*0.5f, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT*1.17f*0.5f, 0xffffffff);
	m_play.AddButton(0, -70.0f, 360.0f, 60.0f, MENUACTION_CONNECT);
	m_play.AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK);
	m_hideIpBox = true;

	// Initialize connecting menu;
	//m_connecting.AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK); // 

	// Push main menu
	m_menues.push(m_main);

	return true;
}

GAMESTATESWITCH MenuState::Update()
{
	MenuActionData action = m_menues.top().Update();

	// Ipbox special case
	if (!m_hideIpBox)
	{
		m_ipbox.IsClicked();
		m_ipbox.GetInput();
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
		case MENUACTION_OPTIONS:
			m_menues.push(m_options);
			break;

		case MENUACTION_CONNECT:
			m_menues.push(m_connecting);
			m_hideIpBox = true;
			Network::GetInstance()->Connect((std::string)m_ipbox.GetIp());
			Network::GetInstance()->SetNetworkStatusConnecting();
			break;

		case MENUACTION_VSYNC:

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

	m_ipboxText.SetText(m_ipbox.GetIp());

	return GAMESTATESWITCH_NONE;
}

void MenuState::Render()
{
	if (!m_menues.empty())
	{
		m_menues.top().Render();
	}

	// Special case for ipbox
	if (!m_hideIpBox)
	{
		m_ipbox.Render();
		m_ipboxText.Render();
	}
}