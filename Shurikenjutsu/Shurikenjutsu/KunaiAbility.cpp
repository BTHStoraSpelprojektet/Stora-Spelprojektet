#include "KunaiAbility.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include "Globals.h"

KunaiAbility::KunaiAbility(){}
KunaiAbility::~KunaiAbility(){}

bool KunaiAbility::Initialize()
{
	SetDamage(SHURIKEN_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_stacks = KUNAI_MAX_STACK;
	m_totalCooldown = KUNAI_COOLDOWN;
	return true;
}

void KunaiAbility::Update()
{
	Ability::Update();
	if (m_stacks < KUNAI_MAX_STACK && GetCooldown() <= 0.0)
	{
		m_stacks += 1;
		if (m_stacks < KUNAI_MAX_STACK)
		{
			SetCooldown(KUNAI_COOLDOWN);
		}
	}
}

bool KunaiAbility::Execute(float p_distance)
{
	if (m_stacks > 0)
	{
			Network::GetInstance()->SendAbility(ABILITIES_KUNAI, 0);
			if (m_stacks == KUNAI_MAX_STACK)
			{
				SetCooldown(KUNAI_COOLDOWN);
			}
			m_stacks -= 1;
			return true;
	}
	return false;
}

void KunaiAbility::ResetCooldown()
{
	Ability::ResetCooldown();
	m_stacks = KUNAI_MAX_STACK;
}