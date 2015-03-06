#include "MenuButton.h"
#include "Globals.h"
#include "InputManager.h"
#include "..\CommonLibs\TextureLibrary.h"

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

	float halfScreenX = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - GLOBAL::GetInstance().BORDER_SIZE;
	float halfScreenY = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - (GLOBAL::GetInstance().BORDER_SIZE + GLOBAL::GetInstance().TITLE_BORDER_SIZE) * 0.5f;

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
