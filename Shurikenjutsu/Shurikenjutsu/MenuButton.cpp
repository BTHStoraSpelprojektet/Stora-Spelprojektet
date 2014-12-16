#include "MenuButton.h"

MenuButton::MenuButton(){}
MenuButton::~MenuButton(){}

bool MenuButton::Initialize(float p_x, float p_y, float p_width, float p_height)
{
	m_x = p_x;
	m_y = p_y;
	m_width = p_width;
	m_height = p_height;

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_x, p_y, 1.0f);
	DirectX::XMFLOAT4 color = DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	m_border.Initialize(position, p_width, p_height, color);

	position = DirectX::XMFLOAT3(p_x - 2.0f, p_y - 2.0f, 1.0f);
	color = DirectX::XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_background.Initialize(position, p_width - 1.0f, p_height - 1.0f, color);
	return true;
	
}

void MenuButton::Render()
{
	m_border.QueueRender();
	m_background.QueueRender();
}

bool MenuButton::IsClicked()
{
	InputManager* input = InputManager::GetInstance();

	if (input->IsLeftMouseClicked())
	{
		if (input->GetMousePositionX() >= (m_x - m_width) && input->GetMousePositionX() <= (m_x + m_width))
		{
			if (input->GetMousePositionY() >= (m_y - m_height) && input->GetMousePositionY() <= (m_y + m_height))
			{
				return true;
			}
		}
	}

	return false;
}