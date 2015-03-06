#include "HealthBar.h"
#include "GUIElement.h"
#include "GUIElementColor.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "Globals.h"
#include "Network.h"
#include "GUIText.h"

HealthBar::HealthBar(){}
HealthBar::~HealthBar(){}

bool HealthBar::Initialize(float p_width, float p_height, std::string p_name, UINT32 p_color)
{
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);

	m_border = new GUIElement();
	m_border->Initialize(position, p_width, p_height, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/hpBorder.png"));

	m_background = new GUIElement();
	m_background->Initialize(position, p_width - 10.0f, p_height - 6.0f, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/hpRed.png")); //DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f));
	m_foreground = new GUIElement();
	m_foreground->Initialize(position, p_width - 10.0f, p_height - 6.0f, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/hpGreen.png")); //DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f));
	m_nameText = new GUIText();
	m_nameText->Initialize(p_name, 30.0f, position.x, position.y, p_color);
	return true;
}

void HealthBar::Shutdown()
{
	if (m_border)
	{
		delete m_border;
		m_border = nullptr;
	}

	if (m_background)
	{
		delete m_background;
		m_background = nullptr;
	}

	if (m_foreground)
	{
		delete m_foreground;
		m_foreground = nullptr;
	}

	if (m_nameText)
	{
		m_nameText->Shutdown();
		delete m_nameText;
		m_nameText = 0;
	}
}
void HealthBar::Update(DirectX::XMFLOAT3 p_position, int p_health, int p_maxHealth, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	CalculatePosition(p_position, p_view, p_projection);

	float percent = (float)p_health / (float)p_maxHealth;

	float newLength = m_background->GetSize().x * (1.0f - percent);

	DirectX::XMFLOAT3 newPos = m_background->GetPosition();
	m_nameText->SetPosition(newPos.x, newPos.y+20.0f);
	newPos.x -= newLength * 0.5f;
	m_foreground->SetPosition(newPos);

	DirectX::XMFLOAT2 newSize = m_background->GetSize();
	newSize.x -= newLength;
	m_foreground->SetSize(newSize);

	

}

void HealthBar::Render()
{
	if (!Network::GetInstance()->GetMatchOver())
	{
		m_background->QueueRender();
		m_foreground->QueueRender();
		m_border->QueueRender();
		m_nameText->Render();
	}
}

void HealthBar::CalculatePosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	DirectX::XMFLOAT4X4 vp;
	DirectX::XMStoreFloat4x4(&vp, DirectX::XMLoadFloat4x4(&p_view) * DirectX::XMLoadFloat4x4(&p_projection));

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_position.x, p_position.y+5.0f, p_position.z);
	DirectX::XMStoreFloat3(&position, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&position), DirectX::XMLoadFloat4x4(&vp)));

	position.x *= GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH/2.0f;
	position.y *= position.z * GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT/2.0f;
	position.z = 1.0f;

	m_border->SetPosition(position);
	m_foreground->SetPosition(position);
	m_background->SetPosition(position);
}
