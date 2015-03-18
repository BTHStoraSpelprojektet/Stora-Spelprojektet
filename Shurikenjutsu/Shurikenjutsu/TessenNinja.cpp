#include "TessenNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "FanMelee.h"
#include "Dash.h"
#include "WhipPrimaryAttackAbility.h"
#include "WhipSecondaryAttackAbility.h"
#include "SpikeAbility.h"
#include "FanBoomerangAbility.h"
#include "InputManager.h"
#include "AttackPredictionEditor.h"
#include "ParticleRenderer.h"
#include "Globals.h"
#include "AbilityBar.h"

TessenNinja::TessenNinja(){}
TessenNinja::~TessenNinja(){}

void* TessenNinja::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void TessenNinja::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool TessenNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr, std::string p_name, UINT32 p_color)
{
	bool result;

	result = Player::Initialize(TESSEN_NINJA_MODEL_NAME, p_pos, p_direction, p_charNr, p_name, p_color);
	if (!result)
	{
		return false;
	}

	SetSpeed(CHARACTER_TESSEN_SPEED);

	m_meleeAttack = new FanMelee();
	m_meleeAttack->Initialize();

	m_meleeSpecialAttack = new FanBoomerangAbility();
	m_meleeSpecialAttack->Initialize();

	m_rangeAttack = new WhipPrimaryAttackAbility();
	m_rangeAttack->Initialize();

	m_rangeSpecialAttack = new WhipSecondaryAttackAbility();
	m_rangeSpecialAttack->Initialize();

	SetOriginalSpeed(GetSpeed());
	SetHealth(CHARACTER_TESSEN_HEALTH);
	SetMaxHealth(CHARACTER_TESSEN_HEALTH);
	m_whipSpinPerformed = false;

	return true;
}

void TessenNinja::Shutdown()
{
	Player::Shutdown();
}
void TessenNinja::RenderAttackLocations()
{
	if (!InputManager::GetInstance()->IsKeyPressed(VkKeyScan(VK_SPACE)))
	{
		if (InputManager::GetInstance()->IsLeftMousePressed())
		{
			if ((float)m_meleeAttack->GetCooldown() <= 0.0f && GLOBAL::GetInstance().APE_ON)
			{
				m_ape->NormalMeleeAttackCone(m_aimFrustrum, m_attackDir, m_position, KATANA_RANGE);

				ParticleRenderer::GetInstance()->QueueRender(m_aimFrustrum);
			}
			else
			{
				StillCDText();
			}
		}
		if (InputManager::GetInstance()->IsRightMousePressed())
		{
			if ((float)m_rangeAttack->GetCooldown() <= 0.0f && GLOBAL::GetInstance().APE_ON)
			{
				m_ape->ThinRectanglePrediction(m_aimPole, m_attackDir, m_position, WHIP_RANGE);

				ParticleRenderer::GetInstance()->QueueRender(m_aimPole);
			}
			else
			{
				StillCDText();
			}
		}
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('q')))
		{
			if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f && GLOBAL::GetInstance().APE_ON)
			{
				m_ape->ThickArrowPrediction(m_aimArrow, m_aimPole, m_attackDir, m_position, true);

				ParticleRenderer::GetInstance()->QueueRender(m_aimPole);
				ParticleRenderer::GetInstance()->QueueRender(m_aimArrow);
			}
			else
			{
				StillCDText();
			}
		}
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('e')))
		{
			if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f && GLOBAL::GetInstance().APE_ON)
			{
				m_ape->SpinAttackBigSphere(m_aimSphere, m_position, 16.0f);
				ParticleRenderer::GetInstance()->QueueRender(m_aimSphere);
			}
			else
			{
				StillCDText();
			}
		}
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('r')))
		{
			if ((float)m_toolAbility->GetCooldown() <= 0.0f && GLOBAL::GetInstance().APE_ON)
			{
				m_ape->ThrowSphere(m_aimSphere, m_position, m_toolAbility->GetRadius(), m_toolAbility->GetRange());
				ParticleRenderer::GetInstance()->QueueRender(m_aimSphere);
			}
			else
			{
				StillCDText();
			}
		}
	}
}
void TessenNinja::CheckForSpecialAttack()
{
	if (m_onPressed)
	{
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('e')))
		{
			if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
			{
				m_ability = m_rangeSpecialAttack;
				m_whipSpinPerformed = true;
			}
		}
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('q')))
		{
			if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
			{
				m_ability = m_meleeSpecialAttack;
			}
		}
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('r')))
		{
			if ((float)m_toolAbility->GetCooldown() <= 0.0f)
			{
				m_ability = m_toolAbility;
			}
		}
	}
	else
	{
		if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('e')))
		{
			if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
			{
				m_ability = m_rangeSpecialAttack;
				m_whipSpinPerformed = true;
			}
		}
		if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('q')))
		{
			if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
			{
				m_ability = m_meleeSpecialAttack;
			}
		}
		if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('r')))
		{
			if ((float)m_toolAbility->GetCooldown() <= 0.0f)
			{
				m_ability = m_toolAbility;
			}
		}
	}
}
void TessenNinja::UpdateAbilityBar()
{
	if (m_whipSpinPerformed && m_globalCooldown < 0)
	{
		m_globalCooldown = WHIP_SP_GLOBAL_COOLDOWN;
		m_maxGlobalCooldown = WHIP_SP_GLOBAL_COOLDOWN;
		m_whipSpinPerformed = false;
	}
	else if (m_globalCooldown < 0)
	{
		m_maxGlobalCooldown = ALL_AROUND_GLOBAL_COOLDOWN;
	}
	if ((float)m_meleeAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_meleeAttack->GetCooldown(), m_meleeAttack->GetTotalCooldown(), m_meleeAttack->GetStacks(), 0);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_meleeAttack->GetStacks(), 0);
	}
	if ((float)m_rangeAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_rangeAttack->GetCooldown(), m_rangeAttack->GetTotalCooldown(), m_rangeAttack->GetStacks(), 1);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_rangeAttack->GetStacks(), 1);
	}
	if ((float)m_meleeSpecialAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_meleeSpecialAttack->GetCooldown(), m_meleeSpecialAttack->GetTotalCooldown(), m_meleeSpecialAttack->GetStacks(), 2);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_meleeSpecialAttack->GetStacks(), 2);
	}
	if ((float)m_rangeSpecialAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_rangeSpecialAttack->GetCooldown(), m_rangeSpecialAttack->GetTotalCooldown(), m_rangeSpecialAttack->GetStacks(), 3);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_rangeSpecialAttack->GetStacks(), 3);
	}
	if ((float)m_toolAbility->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_toolAbility->GetCooldown(), m_toolAbility->GetTotalCooldown(), m_toolAbility->GetStacks(), 4);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_toolAbility->GetStacks(), 4);
	}
}