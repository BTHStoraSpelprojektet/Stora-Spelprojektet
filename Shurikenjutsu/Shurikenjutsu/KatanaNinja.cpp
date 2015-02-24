#include "KatanaNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "MeleeSwing.h"
#include "Dash.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
#include "SmokeBombAbility.h"
#include "InputManager.h"
#include "AttackPredictionEditor.h"

KatanaNinja::KatanaNinja(){}
KatanaNinja::~KatanaNinja(){}

void* KatanaNinja::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void KatanaNinja::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool KatanaNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr)
{
	bool result;

	result = Player::Initialize(KATANA_NINJA_MODEL_NAME, p_pos, p_direction, p_charNr);
	if (!result)
	{
		return false;
	}

	SetSpeed(CHARACTER_KATANA_SHURIKEN_SPEED);

	m_meleeAttack = new MeleeSwing();
	m_meleeAttack->Initialize();

	m_meleeSpecialAttack = new Dash();
	m_meleeSpecialAttack->Initialize();

	m_rangeAttack = new ShurikenAbility();
	m_rangeAttack->Initialize();

	m_rangeSpecialAttack = new MegaShuriken();
	m_rangeSpecialAttack->Initialize();

	/*m_toolAbility = new SmokeBombAbility();
	m_toolAbility->Initialize();*/

	SetOriginalSpeed(GetSpeed());
	SetHealth(CHARACTER_KATANA_SHURIKEN_HEALTH);
	SetMaxHealth(CHARACTER_KATANA_SHURIKEN_HEALTH);

	return true;
}

void KatanaNinja::Shutdown()
{
	Player::Shutdown();
}

void KatanaNinja::RenderAttackLocations()
{
	GraphicsEngine::GetInstance()->TurnOnAlphaBlending();
	if (InputManager::GetInstance()->IsLeftMousePressed())
	{
		if ((float)m_meleeAttack->GetCooldown() <= 0.0f)
		{
			m_ape->NormalMeleeAttackCone(m_aimFrustrum, m_attackDir, m_position, KATANA_RANGE);

			m_aimFrustrum->Render();
		}
		else
		{
			StillCDText();
		}
	}
	if (InputManager::GetInstance()->IsRightMousePressed())
	{
		if (m_rangeAttack->GetStacks() > 0 || m_rangeAttack->GetStacks() == -1)
		{
			m_ape->ThinArrowPrediction(m_aimArrow, m_aimPole, m_attackDir, m_position, true);

			m_aimPole->Render();
			m_aimArrow->Render();
		}
		else
		{
			StillCDText();
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('q')))
	{
		if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
		{
			m_ape->ThickArrowPrediction(m_aimArrow, m_aimPole, m_attackDir, m_position, DASH_MAX_RANGE, false);

			m_aimPole->Render();
			m_aimArrow->Render();
		}
		else
		{
			StillCDText();
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('e')))
	{
		if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
		{
			m_ape->ThickArrowPrediction(m_aimArrow, m_aimPole, m_attackDir, m_position, true);

			m_aimPole->Render();
			m_aimArrow->Render();
		}
		else
		{
			StillCDText();
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('r')))
	{
		if ((float)m_toolAbility->GetCooldown() <= 0.0f)
		{
			m_ape->ThrowSphere(m_aimSphere,m_position, 7.0f, SMOKEBOMB_RANGE);
			m_aimSphere->Render();
		}
		else
		{
			StillCDText();
		}
	}
	GraphicsEngine::GetInstance()->TurnOffAlphaBlending();
}