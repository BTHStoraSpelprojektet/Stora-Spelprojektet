#include "MenuButton.h"
#include "Globals.h"
#include "InputManager.h"
#include "TextureLibrary.h"

MenuButton::MenuButton(){}
MenuButton::~MenuButton(){}

bool MenuButton::Initialize(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, MENUACTION p_action)
{
	MenuItem::Initialize(p_x, p_y, p_width, p_height, p_texture);
	m_action = p_action;
	return true;
}

bool MenuButton::Initialize(float p_x, float p_y, float p_size, ID3D11ShaderResourceView* p_texture, MENUACTION p_action)
{
	MenuItem::Initialize(p_x, p_y, p_size, p_texture);
	m_action = p_action;
	return true;
}

bool MenuButton::IsClicked()
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
		if ((input->GetMousePositionX() - halfScreenX) > (m_x - m_width*0.5f) && (input->GetMousePositionX() - halfScreenX) < (m_x + m_width*0.5f))
		{
			if ((input->GetMousePositionY() - halfScreenY)*-1 >= (m_y - m_height*0.5f) && (input->GetMousePositionY() - halfScreenY)*-1 <= (m_y + m_height*0.5f))
			{
				return true;
			}
		}
	}

	return false;
}

MENUACTION MenuButton::GetAction()
{
	return m_action;
}
