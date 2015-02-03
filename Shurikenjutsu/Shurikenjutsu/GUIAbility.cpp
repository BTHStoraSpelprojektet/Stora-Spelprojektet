#include "GUIAbility.h"
#include "TextureLibrary.h"
#include "..\CommonLibs\ModelNames.h"

GUIAbility::GUIAbility(){}
GUIAbility::~GUIAbility(){}

bool GUIAbility::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture)
{
	m_border.Initialize(p_position, p_width, p_height, DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	m_ability.Initialize(p_position, p_width - 4.0f, p_height - 4.0f, p_texture);
	m_cooldown.Initialize(p_position, 0, 0, TextureLibrary::GetInstance()->GetTexture(ABILITY_CD_TEXTURE));
	m_stacks.Initialize("HELP ME!", 36.0f, p_position.x, p_position.y + 20.0f, 0xff000000); // Will be used Later
	m_currentCooldown = 0.0f;
	return true;
}

void GUIAbility::Update(float p_currentCooldown, float p_maxCooldown)
{
	//if (p_currentCooldown)
	m_currentCooldown = p_currentCooldown;
	// Update Cooldown
	float percent = m_currentCooldown / p_maxCooldown;

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
	//m_stacks.Render2();
}
