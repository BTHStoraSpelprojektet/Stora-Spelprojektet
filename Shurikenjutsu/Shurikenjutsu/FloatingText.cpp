#include "FloatingText.h"
#include "Globals.h"


void FloatingText::Initialize()
{
	m_receivedDamageText = new GUIText();
	m_receivedDamageText->Initialize("received", 30.0f, 20.0f, 115.0f, 0xff0000ff);

	m_dealtDamageText = new GUIText();
	m_dealtDamageText->Initialize("dealt", 30.0f, 20.0f, 115.0f, 0xff00ffff);

	m_healingText = new GUIText();
	m_healingText->Initialize("healing", 30.0f, 20.0f, 115.0f, 0xff00ff00);

	m_cantUseAbilityText = new GUIText();
	m_cantUseAbilityText->Initialize("Can't use that ability.", 30.0f, 20.0f, 115.0f, 0xff0000ff);
}
void FloatingText::Update(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	m_viewMatrix = p_view;
	m_projectionMatrix = p_projection;
	CalculatePosition(p_position, m_receivedDamageText, 1.0f, 6.0f);
	//CalculatePosition(p_position, m_dealtDamageText, 2.0f, 0.0f);
	CalculatePosition(p_position, m_healingText, -1.0f, 6.0f);
	CalculatePosition(p_position, m_cantUseAbilityText, 0.0f, 2.0f);

	for (unsigned int i = 0; i < 3; i++)
	{
		DecreaseTextOpacity(m_receivedDamageText);
		DecreaseTextOpacity(m_dealtDamageText);
		DecreaseTextOpacity(m_healingText);
		DecreaseTextOpacity(m_cantUseAbilityText);
	}
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
	if (m_cantUseAbilityText != nullptr)
	{
		m_cantUseAbilityText->Shutdown();
		delete m_cantUseAbilityText;
		m_cantUseAbilityText = nullptr;
	}
}
void FloatingText::Render()
{
	RenderText(m_receivedDamageText);
	RenderText(m_dealtDamageText);
	RenderText(m_healingText);
	RenderText(m_cantUseAbilityText);
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
		m_receivedDamageText->SetText(temp);
		m_receivedDamageText->SetColor(0xff0000ff);
	}
}
void FloatingText::SetDealtDamageText(DirectX::XMFLOAT3 p_position, float p_damage)
{
	int resize = 2;
	if (p_damage < 10 && p_damage > 0)
	{
		resize = 1;
	}
	if (p_damage != 0)
	{
		CalculatePosition(p_position, m_dealtDamageText, 0.0f, 0.0f);
		std::string temp = std::to_string(p_damage);
		temp.resize(resize);
		m_dealtDamageText->SetText(temp);
		m_dealtDamageText->SetColor(0xff00ffff);
	}
}
void FloatingText::CalculatePosition(DirectX::XMFLOAT3 p_position, GUIText* p_text, float p_xOffset, float p_yOffset)
{
	DirectX::XMFLOAT4X4 vp;
	DirectX::XMStoreFloat4x4(&vp, DirectX::XMLoadFloat4x4(&m_viewMatrix) * DirectX::XMLoadFloat4x4(&m_projectionMatrix));

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
void FloatingText::SetcantUseAbilityText(int p_messageIndex)
{
	std::string text;

	/*if (p_messageIndex == 1)
	{
		text = "Un fucking believable...";
	}
	else if (p_messageIndex == 2)
	{
		text = "No comment can describe you're stupidity...";
	}
	else if (p_messageIndex == 3)
	{
		text = "Stop H4XX1NG!!";
	}
	else if (p_messageIndex == 4)
	{
		text = "What are you stupid?";
	}
	else
	{
		text = "Can't use that ability.";
	}*/
	
	text = "Can't use that ability.";
	m_cantUseAbilityText->SetText(text);
	m_cantUseAbilityText->SetColor(0xff0000ff);
}