#include "MenuCheckbox.h"

MenuCheckbox::MenuCheckbox(){}
MenuCheckbox::~MenuCheckbox(){}

bool MenuCheckbox::GetState()const
{
	return m_state;
}

void MenuCheckbox::SetState(bool p_state)
{
	m_state = p_state;
}

bool MenuCheckbox::IsClicked()
{
	if (MenuItem::IsClicked())
	{
		if (m_state)
		{
			m_state = false;
		}
		else
		{
			m_state = true;
		}

		return true;
	}

	return false;
}
