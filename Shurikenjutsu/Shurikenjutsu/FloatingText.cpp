#include "FloatingText.h"
#include "Globals.h"


void FloatingText::Initialize()
{
	m_receivedDamageText = new GUIText();
	m_receivedDamageText->Initialize("", 30.0f, 20.0f, 115.0f, 0xff0000ff);

	m_dealtDamageText = new GUIText();
	m_dealtDamageText->Initialize("", 30.0f, 20.0f, 115.0f, 0xff00ffff);

	m_healingText = new GUIText();
	m_healingText->Initialize("", 30.0f, 20.0f, 115.0f, 0xff00ff00);
}
void FloatingText::Update(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	CalculatePosition(p_position, p_view, p_projection, m_receivedDamageText, 1.0f, 6.0f);
	DecreaseTextOpacity(m_receivedDamageText);
	DecreaseTextOpacity(m_receivedDamageText);

	CalculatePosition(p_position, p_view, p_projection, m_dealtDamageText, 2.0f, 0.0f);
	DecreaseTextOpacity(m_dealtDamageText);
	DecreaseTextOpacity(m_dealtDamageText);

	CalculatePosition(p_position, p_view, p_projection, m_healingText, -1.0f, 6.0f);
	DecreaseTextOpacity(m_healingText);
	DecreaseTextOpacity(m_healingText);
}
void FloatingText::Shutdown()
{
	if (m_healingText != nullptr)
	{
		m_healingText->Shutdown();
		delete m_healingText;
		m_healingText = nullptr;
	}
	if (m_dealtDamageText != nullptr)
	{
		m_dealtDamageText->Shutdown();
		delete m_dealtDamageText;
		m_dealtDamageText = nullptr;
	}
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
	RenderText(m_dealtDamageText);
	RenderText(m_healingText);
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

void FloatingText::SetReceivedDamageText(float p_damage)
{
	int resize = 3;
	if ( p_damage > -10)
	{
		resize = 2;
	}
	if (p_damage != 0)
	{
		std::string temp = std::to_string(p_damage);
		temp.resize(resize);
		m_dealtDamageText->SetText(temp);
		m_dealtDamageText->SetColor(0xff0000ff);
	}
}
void FloatingText::SetDealtDamageText(float p_damage)
{
	int resize = 2;
	if (p_damage < 10 && p_damage > 0)
	{
		resize = 1;
	}
	if (p_damage != 0)
	{
		std::string temp = std::to_string(p_damage);
		temp.resize(resize);
		m_dealtDamageText->SetText(temp);
		m_dealtDamageText->SetColor(0xff00ffff);
	}
}
void FloatingText::CalculatePosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection, GUIText* p_text, float p_xOffset, float p_yOffset)
{
	DirectX::XMFLOAT4X4 vp;
	DirectX::XMStoreFloat4x4(&vp, DirectX::XMLoadFloat4x4(&p_view) * DirectX::XMLoadFloat4x4(&p_projection));

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_position.x + p_xOffset, p_position.y + p_yOffset, p_position.z);
	DirectX::XMStoreFloat3(&position, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&position), DirectX::XMLoadFloat4x4(&vp)));

	position.x *= GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 2.0f;
	position.y *= position.z * GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 2.0f;
	position.z = 1.0f;

	p_text->SetPosition(position.x, position.y);
}
void FloatingText::SetHealingText(float p_healing)
{
	int resize = 2;
	if (p_healing < 10 && p_healing > 0)
	{
		resize = 1;
	}
	if (p_healing != 0)
	{
		std::string temp = std::to_string(p_healing);
		temp.resize(resize);
		m_healingText->SetText(temp);
		m_healingText->SetColor(0xff00ff00);
	}
}