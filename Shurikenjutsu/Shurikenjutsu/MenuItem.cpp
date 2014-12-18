#include "MenuItem.h"


MenuItem::MenuItem(){}
MenuItem::~MenuItem(){}

bool MenuItem::Initialize(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action)
{
	m_x = p_x;
	m_y = p_y;
	m_width = p_width;
	m_height = p_height;
	m_action = p_action;

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_x, p_y, 1.0f);
	DirectX::XMFLOAT4 color = DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	m_border.Initialize(position, m_width, m_height, color);

	position = DirectX::XMFLOAT3(p_x, p_y, 1.0f);
	color = DirectX::XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_background.Initialize(position, m_width - 4.0f, m_height - 4.0f, color);
	
	return true;
}

bool MenuItem::Initialize(float p_x, float p_y, float p_size, MENUACTION p_action)
{ 
	return Initialize(p_x, p_y, p_size, p_size, p_action);
}

void MenuItem::Render()
{
	m_border.QueueRender();
	m_background.QueueRender();
}

bool MenuItem::IsClicked()
{
	return false;
}

MENUACTION MenuItem::GetAction()
{
	return m_action;
}
