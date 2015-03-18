#include "NaginataNinja.h"
#include "../CommonLibs/ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "NaginataSlash.h"
#include "NaginataStab.h"
#include "InputManager.h"
#include "KunaiAbility.h"
#include "StickyTrapAbility.h"
#include "VolleyAbility.h"
#include "AttackPredictionEditor.h"
#include "ParticleRenderer.h"
#include "Globals.h"
#include "Network.h"
#include "AbilityBar.h"


NaginataNinja::NaginataNinja(){}
NaginataNinja::~NaginataNinja(){}

void* NaginataNinja::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void NaginataNinja::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool NaginataNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr, std::string p_name, UINT32 p_color)
{
	bool result;

	result = Player::Initialize(NAGINATA_NINJA_MODEL_NAME, p_pos, p_direction, p_charNr, p_name, p_color);
	if (!result)
	{
		return false;
	}

	SetSpeed(CHARACTER_NAGINATA_SPEED);

	m_meleeAttack = new NaginataSlash();
	m_meleeAttack->Initialize();

	m_meleeSpecialAttack = new NaginataStab();
	m_meleeSpecialAttack->Initialize();

	m_rangeAttack = new KunaiAbility();
	m_rangeAttack->Initialize();

	m_rangeSpecialAttack = new VolleyAbility();
	m_rangeSpecialAttack->Initialize();

	/*m_toolAbility = new StickyTrapAbility();
	m_toolAbility->Initialize();*/

	SetOriginalSpeed(GetSpeed());
	SetHealth(CHARACTER_NAGINATA_HEALTH);
	SetMaxHealth(CHARACTER_NAGINATA_HEALTH);
	m_stabAttackPerformed = false;

	return true;
}

void NaginataNinja::Shutdown()
{
	Player::Shutdown();
}
void NaginataNinja::RenderAttackLocations()
{
	if (!InputManager::GetInstance()->IsKeyPressed(VkKeyScan(VK_SPACE)))
	{
		if (InputManager::GetInstance()->IsLeftMousePressed())
		{
			if ((float)m_meleeAttack->GetCooldown() <= 0.0f && GLOBAL::GetInstance().APE_ON)
			{
				m_ape->NormalMeleeAttackCone(m_aimFrustrum, m_attackDir, m_position, NAGINATA_RANGE);

				ParticleRenderer::GetInstance()->QueueRender(m_aimFrustrum);
			}
			else
			{
				StillCDText();
			}
		}
		if (InputManager::GetInstance()->IsRightMousePressed())
		{
			if ((m_rangeAttack->GetStacks() > 0 || m_rangeAttack->GetStacks() == -1) && GLOBAL::GetInstance().APE_ON)
			{
				m_ape->ThinArrowPrediction(m_aimArrow, m_aimPole, m_attackDir, m_position, true);

				ParticleRenderer::GetInstance()->QueueRender(m_aimPole);
				ParticleRenderer::GetInstance()->QueueRender(m_aimArrow);
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
				m_ape->ThickRectanglePrediction(m_aimPole, m_attackDir, m_position, NAGINATASTAB_RANGE * 2);

				ParticleRenderer::GetInstance()->QueueRender(m_aimPole);
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
				m_ape->ThrowSphere(m_aimSphere, m_position, 3.5f, VOLLEY_RANGE);
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
				m_ape->ThrowSphere(m_aimSphere, m_position, 7.0f, STICKY_TRAP_RANGE);
				ParticleRenderer::GetInstance()->QueueRender(m_aimSphere);
			}
			else
			{
				StillCDText();
			}
		}
	}
}
void NaginataNinja::CheckForSpecialAttack()
{
	if (m_onPressed)
	{
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('e')))
		{
			if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
			{
				m_ability = m_rangeSpecialAttack;
			}
		}
		if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('q')))
		{
			if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
			{
				m_ability = m_meleeSpecialAttack;
				m_stabAttackPerformed = true;
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
			}
		}
		if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('q')))
		{
			if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
			{
				m_ability = m_meleeSpecialAttack;
				m_stabAttackPerformed = true;
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
void NaginataNinja::UpdateAbilityBar()
{
	if (m_stabAttackPerformed)
	{
		m_globalCooldown = NAGINATASTAB_GLOBAL_COOLDOWN;
		m_maxGlobalCooldown = NAGINATASTAB_GLOBAL_COOLDOWN;
		m_stabAttackPerformed = false;
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