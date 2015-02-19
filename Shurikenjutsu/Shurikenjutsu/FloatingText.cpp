#include "FloatingText.h"
#include "Globals.h"


void FloatingText::Initialize()
{
	m_receivedDamageText = new GUIText();
	m_receivedDamageText->Initialize("", 30.0f, 20.0f, 115.0f, 0xff0000ff);
	m_timer = 0;
}
void FloatingText::Update(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	CalculatePosition(p_position, p_view, p_projection, m_receivedDamageText);
	DecreaseTextOpacity(m_receivedDamageText);
	DecreaseTextOpacity(m_receivedDamageText);
}
void FloatingText::Shutdown()
{
	if (m_receivedDamageText != nullptr)
	{
		m_receivedDamageText->Shutdown();
		delete m_receivedDamageText;
		m_receivedDamageText = nullptr;
	}
}
void FloatingText::Render()
{
	RenderText(m_receivedDamageText);
}
void FloatingText::ResetTimer()
{
	//m_receivedDamageText->SetColor(0xffffffff);
	m_timer = 0;
}
void FloatingText::DecreaseTextOpacity(GUIText* p_text)
{
	if (p_text->GetColor() < 16777216)
	{
		p_text->SetColor(0);
	}
	else
	{
		p_text->SetColor(p_text->GetColor() - 16777216);
	}
}
void FloatingText::RenderText(GUIText* p_text)
{
	if (p_text->GetColor() > 16777216)
	{
		p_text->Render();
	}
}

void FloatingText::SetReceivedDamageText(std::string p_damage)
{
	std::string temp = p_damage;
	temp.resize(3);
	m_receivedDamageText->SetText(temp);
	m_receivedDamageText->SetColor(0xff0000ff);
}
void FloatingText::CalculatePosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection, GUIText* p_text)
{
	DirectX::XMFLOAT4X4 vp;
	DirectX::XMStoreFloat4x4(&vp, DirectX::XMLoadFloat4x4(&p_view) * DirectX::XMLoadFloat4x4(&p_projection));

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_position.x, p_position.y + 6.0f, p_position.z);
	DirectX::XMStoreFloat3(&position, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&position), DirectX::XMLoadFloat4x4(&vp)));

	position.x *= GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 2.0f;
	position.y *= position.z * GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 2.0f;
	position.z = 1.0f;

	p_text->SetPosition(position.x, position.y);
}