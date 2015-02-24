#include "TessenNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "MeleeSwing.h"
#include "Dash.h"
#include "WhipPrimaryAttackAbility.h"
#include "WhipSecondaryAttackAbility.h"
#include "SpikeAbility.h"
#include "FanBoomerangAbility.h"
#include "InputManager.h"
#include "AttackPredictionEditor.h"

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

bool TessenNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr)
{
	bool result;

	result = Player::Initialize(TESSEN_NINJA_MODEL_NAME, p_pos, p_direction, p_charNr);
	if (!result)
	{
		return false;
	}

	SetSpeed(CHARACTER_TESSEN_SPEED);

	m_meleeAttack = new MeleeSwing();
	m_meleeAttack->Initialize();

	m_meleeSpecialAttack = new FanBoomerangAbility();
	m_meleeSpecialAttack->Initialize();

	m_rangeAttack = new WhipPrimaryAttackAbility();
	m_rangeAttack->Initialize();

	m_rangeSpecialAttack = new WhipSecondaryAttackAbility();
	m_rangeSpecialAttack->Initialize();

	/*m_toolAbility = new SpikeAbility();
	m_toolAbility->Initialize();*/

	SetOriginalSpeed(GetSpeed());
	SetHealth(CHARACTER_TESSEN_HEALTH);
	SetMaxHealth(CHARACTER_TESSEN_HEALTH);

	return true;
}

void TessenNinja::Shutdown()
{
	Player::Shutdown();
}
void TessenNinja::RenderAttackLocations()
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
		if ((float)m_rangeAttack->GetCooldown() <= 0.0f)
		{
			m_ape->ThinRectanglePrediction(m_aimPole, m_attackDir, m_position, WHIP_RANGE);

			m_aimPole->Render();
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
			m_ape->ThinArrowPrediction(m_aimArrow, m_aimPole, m_attackDir, m_position, true);

			m_aimArrow->Render();
			m_aimPole->Render();
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
			m_ape->SpinAttackBigSphere(m_aimSphere, m_position, 16.0f);
			m_aimSphere->Render();
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
			m_ape->ThrowSphere(m_aimSphere,m_position, 5.0f, SPIKE_RANGE);
			m_aimSphere->Render();
		}
		else
		{
			StillCDText();
		}
	}
	GraphicsEngine::GetInstance()->TurnOffAlphaBlending();
}