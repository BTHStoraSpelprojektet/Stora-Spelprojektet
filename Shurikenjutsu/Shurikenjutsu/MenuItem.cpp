#include "MenuItem.h"


MenuItem::MenuItem(){}
MenuItem::~MenuItem(){}

bool MenuItem::Initialize(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, ID3D11ShaderResourceView* p_texture)
{
	m_x = p_x;
	m_y = p_y;
	m_width = p_width;
	m_height = p_height;
	m_action = p_action;

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_x, p_y, 1.0f);

	m_background.Initialize(position, m_width, m_height, p_texture);
	
	return true;
}

bool MenuItem::Initialize(float p_x, float p_y, float p_size, MENUACTION p_action, ID3D11ShaderResourceView* p_texture)
{ 
	return Initialize(p_x, p_y, p_size, p_size, p_action, p_texture);
}

void MenuItem::Render()
{
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

void MenuItem::SetBackgroundTexture(ID3D11ShaderResourceView* p_texture)
{
	m_background.SetTexture(p_texture);
}