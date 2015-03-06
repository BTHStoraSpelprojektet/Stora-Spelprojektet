#include "MenuCheckbox.h"
#include "GUIElement.h"
#include "..\CommonLibs\TextureLibrary.h"

MenuCheckbox::MenuCheckbox(){}
MenuCheckbox::~MenuCheckbox(){}

bool MenuCheckbox::Initialize(float p_x, float p_y, MENUACTION p_action, bool p_state)
{
	MenuItem::Initialize(p_x, p_y, 100.0f, NULL);

	m_action = p_action;
	SetState(p_state);

	return true;
}



bool MenuCheckbox::GetState()const
{
	return m_state;
}

void MenuCheckbox::SetState(bool p_state)
{
	m_state = p_state;

	if (m_state)
	{
		m_background->SetTexture(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/checkbox_checked.png"));
	}
	else
	{
		m_background->SetTexture(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/checkbox_empty.png"));
	}
}

bool MenuCheckbox::IsClicked()
{
	if (MenuButton::IsClicked())
	{
		if (m_state)
		{
			SetState(false);
		}
		else
		{
			SetState(true);
		}

		return true;
	}

	return false;
}
