#include "MenuItem.h"
#include "Globals.h"
#include "GUIElement.h"
#include "InputManager.h"
#include "GUIElement.h"

MenuItem::MenuItem(){}
MenuItem::~MenuItem(){}

bool MenuItem::Initialize(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture)
{
	m_x = p_x;
	m_y = p_y;
	m_width = p_width;
	m_height = p_height;
	
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_x, p_y, 1.0f);
	m_background = new GUIElement();
	m_background->Initialize(position, m_width, m_height, p_texture);
	
	return true;
}

bool MenuItem::Initialize(float p_x, float p_y, float p_size, ID3D11ShaderResourceView* p_texture)
{ 
	return Initialize(p_x, p_y, p_size, p_size, p_texture);
}

void MenuItem::Render()
{
	m_background->QueueRender();
}

void MenuItem::SetBackgroundTexture(ID3D11ShaderResourceView* p_texture)
{
	m_background->SetTexture(p_texture);
}

void MenuItem::Shutdown()
{
	delete m_background;
	m_background = 0;
}

void MenuItem::SetPosition(float p_x, float p_y)
{
	m_x = p_x;
	m_y = p_y;
	m_background->SetPosition(DirectX::XMFLOAT3(m_x, m_y, 1.0f));
}