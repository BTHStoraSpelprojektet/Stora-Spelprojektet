#include "GUIAbility.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "..\CommonLibs\ModelNames.h"
#include "GUIElement.h"
#include "GUIText.h"

GUIAbility::GUIAbility(){}
GUIAbility::~GUIAbility(){}

bool GUIAbility::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, std::string p_hotKey)
{
	m_ability = new GUIElement();
	m_ability->Initialize(p_position, p_width - 4.0f, p_height - 4.0f, p_texture);

	m_cooldown = new GUIElement();
	m_cooldown->Initialize(p_position, 0, 0, TextureLibrary::GetInstance()->GetTexture(ABILITY_CD_TEXTURE));

	m_stacks = new GUIText();
	m_stacks->Initialize("", 25.0f, p_position.x, p_position.y + 36.0f, 0xff071e31);

	m_hotKeyText = new GUIText();
	m_hotKeyText->Initialize(p_hotKey, 20.0f, p_position.x, p_position.y - 35.0f, 0xff071e31);

	m_cooldownText = new GUIText();
	m_cooldownText->Initialize("", 36.0f, p_position.x, p_position.y, 0xff0000ff);

	m_lastnrofStacks = -1;
	return true;
}

void GUIAbility::Shutdown()
{
	if (m_ability != nullptr)
	{
		delete m_ability;
		m_ability = nullptr;
	}

	if (m_cooldown != nullptr)
	{
		delete m_cooldown;
		m_cooldown = nullptr;
	}

	if (m_stacks != nullptr)
	{
		delete m_stacks;
		m_stacks = nullptr;
	}

	if (m_hotKeyText != nullptr)
	{
		delete m_hotKeyText;
		m_hotKeyText = nullptr;
	}

	if (m_cooldownText != nullptr)
	{
		delete m_cooldownText;
		m_cooldownText = nullptr;
	}
}

void GUIAbility::Update(float p_currentCooldown, float p_maxCooldown, int p_stacks)
{
	
	// Update Cooldown
	float percent = p_currentCooldown / p_maxCooldown;
	if (percent > 1.0f)
	{
		percent = 1.0f;
	}

	float newLength = m_ability->GetSize().x * (1.0f - percent);
	
	DirectX::XMFLOAT3 newPos = m_ability->GetPosition();
	newPos.y -= newLength * 0.5f;
	m_cooldown->SetPosition(newPos);

	DirectX::XMFLOAT2 newSize = m_ability->GetSize();
	newSize.y -= newLength;
	m_cooldown->SetSize(newSize);

	// Update Cooldown text
	if (p_currentCooldown <= 0.0f)
	{
		m_cooldownText->SetText("");

	}
	else
	{
		std::string cd;
		cd = std::to_string(p_currentCooldown);
		cd.resize(3);
		m_cooldownText->SetText(cd);
	}

	// Update stack text
	if (p_stacks != m_lastnrofStacks)
	{
		m_stacks->SetText(std::to_string(p_stacks));
		m_lastnrofStacks = p_stacks;
	}
	
}

void GUIAbility::Render()
{
	m_ability->QueueRender();
	m_cooldown->QueueRender();
	m_stacks->Render();
	m_cooldownText->Render();
	m_hotKeyText->Render();
}
