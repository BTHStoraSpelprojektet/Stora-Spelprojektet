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
	InputManager* input = InputManager::GetInstance();
	int mouseOffsetX = 0;
	int mouseOffsetY = 0;

	if (!GLOBAL::GetInstance().FULLSCREEN)
	{
		mouseOffsetX = 9;
		mouseOffsetY = 18;
	}

	float halfScreenX = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - mouseOffsetX;
	float halfScreenY = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - mouseOffsetY;

	if (input->IsLeftMouseClicked())
	{
		if ((input->GetMousePositionX() - halfScreenX) >= (m_x - m_width*0.5f) && (input->GetMousePositionX() - halfScreenX) <= (m_x + m_width*0.5f))
		{
			if ((input->GetMousePositionY() - halfScreenY)*-1 >= (m_y - m_height*0.5f) && (input->GetMousePositionY() - halfScreenY)*-1 <= (m_y + m_height*0.5f))
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
		}
	}

	return false;
}
