#include "GUIAbility.h"
#include "TextureLibrary.h"


GUIAbility::GUIAbility(){}
GUIAbility::~GUIAbility(){}

bool GUIAbility::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture)
{
	m_border.Initialize(p_position, p_width, p_height, DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	m_ability.Initialize(p_position, p_width, p_height, p_texture);
	m_cooldown.Initialize(p_position, 0, 0, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_cd.png"));
	m_stacks.Initialize(" ", 36.0f, p_position.x, p_position.y + 20.0f, 0xff000000); // Will be used Later
	return true;
}

void GUIAbility::Update(float p_currentCooldown, float p_maxCooldown)
{
	// Update Cooldown
	float percent = p_currentCooldown / p_maxCooldown;

	float newLength = m_ability.GetSize().x * (1.0f - percent);
	
	DirectX::XMFLOAT3 newPos = m_ability.GetPosition();
	newPos.y -= newLength * 0.5f;
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
	//m_stacks.Render();
}
