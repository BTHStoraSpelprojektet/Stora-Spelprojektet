#include "MenuItem.h"
#include "Globals.h"
#include "GUIElement.h"
#include "InputManager.h"
#include "GUIElement.h"

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
	m_background = new GUIElement();
	m_background->Initialize(position, m_width, m_height, p_texture);
	
	return true;
}

bool MenuItem::Initialize(float p_x, float p_y, float p_size, MENUACTION p_action, ID3D11ShaderResourceView* p_texture)
{ 
	return Initialize(p_x, p_y, p_size, p_size, p_action, p_texture);
}

void MenuItem::Render()
{
	m_background->QueueRender();
}

bool MenuItem::IsClicked()
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
		std::cout << "Mouse: " << input->GetMousePositionX() << ", " << input->GetMousePositionY() << std::endl;
		std::cout << "Half Screen: " << GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH << ", " << GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT << std::endl;
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

MENUACTION MenuItem::GetAction()
{
	return m_action;
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
