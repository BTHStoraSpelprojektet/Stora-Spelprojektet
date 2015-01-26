#include "MenuCheckbox.h"
#include "GUIElement.h"
#include "TextureLibrary.h"

MenuCheckbox::MenuCheckbox(){}
MenuCheckbox::~MenuCheckbox(){}

bool MenuCheckbox::Initialize(float p_x, float p_y, MENUACTION p_action, bool p_state)
{
	MenuItem::Initialize(p_x, p_y, 60.0f, p_action, NULL);

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
		m_background->SetTexture(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/cbtrue.png"));
	}
	else
	{
		m_background->SetTexture(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/cbfalse.png"));
	}
}

bool MenuCheckbox::IsClicked()
{
	if (MenuItem::IsClicked())
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
