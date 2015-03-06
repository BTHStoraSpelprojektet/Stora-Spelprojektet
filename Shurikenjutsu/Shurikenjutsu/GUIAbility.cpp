#include "GUIAbility.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "..\CommonLibs\ModelNames.h"

GUIAbility::GUIAbility(){}
GUIAbility::~GUIAbility(){}

bool GUIAbility::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, std::string p_hotKey)
{
	m_border.Initialize(p_position, p_width, p_height, DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	m_ability.Initialize(p_position, p_width - 4.0f, p_height - 4.0f, p_texture);
	m_cooldown.Initialize(p_position, 0, 0, TextureLibrary::GetInstance()->GetTexture(ABILITY_CD_TEXTURE));
	m_stacks.Initialize("", 25.0f, p_position.x, p_position.y + 36.0f, 0xff071e31);
	m_hotKeyText.Initialize(p_hotKey, 20.0f, p_position.x, p_position.y - 35.0f, 0xff071e31);
	m_cooldownText.Initialize("", 36.0f, p_position.x, p_position.y, 0xff0000ff);
	m_lastnrofStacks = -1;
	return true;
}

void GUIAbility::Update(float p_currentCooldown, float p_maxCooldown, int p_stacks)
{
	
	// Update Cooldown
	float percent = p_currentCooldown / p_maxCooldown;
	if (percent > 1.0f)
	{
		percent = 1.0f;
	}

	float newLength = m_ability.GetSize().x * (1.0f - percent);
	
	DirectX::XMFLOAT3 newPos = m_ability.GetPosition();
	newPos.y -= newLength * 0.5f;
	m_cooldown.SetPosition(newPos);

	DirectX::XMFLOAT2 newSize = m_ability.GetSize();
	newSize.y -= newLength;
	m_cooldown.SetSize(newSize);

	// Update Cooldown text
	if (p_currentCooldown <= 0.0f)
	{
		m_cooldownText.SetText("");

	}
	else
	{
		std::string cd;
		cd = std::to_string(p_currentCooldown);
		cd.resize(3);
		m_cooldownText.SetText(cd);
	}

	// Update stack text
	if (p_stacks != m_lastnrofStacks)
	{
		m_stacks.SetText(std::to_string(p_stacks));
		m_lastnrofStacks = p_stacks;
	}
	
}

void GUIAbility::Render()
{
	//m_border.QueueRender();
	m_ability.QueueRender();
	m_cooldown.QueueRender();
	m_stacks.Render();
	m_cooldownText.Render();
	m_hotKeyText.Render();
}
