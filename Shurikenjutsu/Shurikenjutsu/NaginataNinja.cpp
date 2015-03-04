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

bool NaginataNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr, std::string p_name)
{
	bool result;

	result = Player::Initialize(NAGINATA_NINJA_MODEL_NAME, p_pos, p_direction, p_charNr, p_name);
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

	return true;
}

void NaginataNinja::Shutdown()
{
	Player::Shutdown();
}
void NaginataNinja::RenderAttackLocations()
{
	if (InputManager::GetInstance()->IsLeftMousePressed())
	{
		if ((float)m_meleeAttack->GetCooldown() <= 0.0f)
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
		if (m_rangeAttack->GetStacks() > 0 || m_rangeAttack->GetStacks() == -1)
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
		if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
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
		if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
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
		if ((float)m_toolAbility->GetCooldown() <= 0.0f)
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