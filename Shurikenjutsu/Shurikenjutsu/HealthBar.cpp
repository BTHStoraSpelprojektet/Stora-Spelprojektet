#include "HealthBar.h"

HealthBar::HealthBar(){}
HealthBar::~HealthBar(){}

bool HealthBar::Initialize(float p_width, float p_height)
{
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_border.Initialize(position, p_width+2.0f, p_height+2.0f, DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	m_background.Initialize(position, p_width, p_height, DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f));
	m_foreground.Initialize(position, p_width, p_height, DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f));

	return true;
}

void HealthBar::Update(DirectX::XMFLOAT3 p_position, int p_health, int p_maxHealth, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	CalculatePosition(p_position, p_view, p_projection);

	float percent = (float)p_health / (float)p_maxHealth;

	float newLength = m_background.GetSize().x * (1.0f - percent);

	DirectX::XMFLOAT3 newPos = m_foreground.GetPosition();
	newPos.x -= newLength;
	m_foreground.SetPosition(newPos);

	DirectX::XMFLOAT2 newSize = m_background.GetSize();
	newSize.x -= newLength;
	m_foreground.SetSize(newSize);

	
}

void HealthBar::Render()
{
	m_border.QueueRender();
	m_background.QueueRender();
	m_foreground.QueueRender();
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

	m_border.SetPosition(position);
	m_foreground.SetPosition(position);
	m_background.SetPosition(position);
}
