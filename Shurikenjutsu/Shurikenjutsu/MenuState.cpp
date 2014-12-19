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
	m_main.AddButton(0, 0, 360.0f, 60.0f, MENUACTION_PLAY);
	m_main.AddButton(0, -70.0f, 360.0f, 60.0f, MENUACTION_OPTIONS);
	m_main.AddButton(0, -140.0f, 360.0f, 60.0f, MENUACTION_BACK);

	// Push main menu
	m_menues.push(m_main);
	return true;
}

GAMESTATESWITCH MenuState::Update()
{
	MenuActionData action = m_menues.top().Update();

	switch (action.m_action)
	{
		case MENUACTION_BACK:
			m_menues.pop();
			if (m_menues.empty())
			{
				PostQuitMessage(0);
			}
			break;
		case MENUACTION_PLAY:
			return GAMESTATESWITCH_PLAY;
			break;
		case MENUACTION_OPTIONS:
			m_menues.push(m_options);
			break;
		case MENUACTION_VSYNC:

			break;
		case MENUACTION_FULLSCREEN:

			break;
	}

	return GAMESTATESWITCH_NONE;
}

void MenuState::Render()
{
	if (!m_menues.empty())
	{
		m_menues.top().Render();
	}
}