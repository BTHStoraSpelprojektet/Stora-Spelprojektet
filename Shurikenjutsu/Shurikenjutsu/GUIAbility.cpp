#include "GUIAbility.h"


GUIAbility::GUIAbility(){}
GUIAbility::~GUIAbility(){}

bool GUIAbility::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height)
{
	m_border.Initialize(p_position, p_width, p_height, DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	m_ability.Initialize(p_position, p_width-4.0f, p_height-4.0f, DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f));
	m_cooldown.Initialize(p_position, 0, 0, DirectX::XMFLOAT4(0.2f, 0.2f, 0.2f, 0.9f));

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
	m_border.QueueRender();
	m_ability.QueueRender();
	m_cooldown.QueueRender();
}
