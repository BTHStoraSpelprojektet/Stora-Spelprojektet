#include "GUIAbility.h"


GUIAbility::GUIAbility(){}
GUIAbility::~GUIAbility(){}

bool GUIAbility::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture)
{
	m_border.Initialize(p_position, p_width, p_height, DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	m_ability.Initialize(p_position, p_width - 4.0f, p_height - 4.0f, p_texture);
	m_cooldown.Initialize(p_position, 0, 0, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_cd.png"));

	return true;
}

void GUIAbility::Update(float p_currentCooldown, float p_maxCooldown)
{
	// Update Cooldown
	float percent = p_currentCooldown / p_maxCooldown;

	float newLength = m_ability.GetSize().x * 0.5f * (1.0f - percent);

	DirectX::XMFLOAT3 newPos = m_ability.GetPosition();
	newPos.y -= newLength;
	m_cooldown.SetPosition(newPos);

	DirectX::XMFLOAT2 newSize = m_ability.GetSize();
	newSize.y -= newLength;
	m_cooldown.SetSize(newSize);
}

void GUIAbility::Render()
{
	//m_border.QueueRender();
	m_ability.QueueRender();
	m_cooldown.QueueRender();
}
