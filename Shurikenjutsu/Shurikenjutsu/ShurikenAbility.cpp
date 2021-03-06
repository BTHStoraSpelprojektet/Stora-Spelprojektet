#include "ShurikenAbility.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include "Globals.h"

ShurikenAbility::ShurikenAbility(){}
ShurikenAbility::~ShurikenAbility(){}
bool ShurikenAbility::Initialize()
{
	SetDamage(SHURIKEN_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_stacks = SHURIKEN_MAX_STACK;
	m_gcd = ALL_AROUND_GLOBAL_COOLDOWN + 1.0f;
	m_totalCooldown = SHURIKEN_COOLDOWN;
	return true;
}
void ShurikenAbility::Update()
{
	Ability::Update();
	if (m_stacks < SHURIKEN_MAX_STACK && GetCooldown() <= 0.0)
	{
		m_stacks += 1;

		if (m_stacks < SHURIKEN_MAX_STACK)
		{
			SetCooldown(SHURIKEN_COOLDOWN);
		}
	}
	m_gcd += GLOBAL::GetInstance().GetDeltaTime();
}
bool ShurikenAbility::Execute(float p_distance)
{
	if (m_gcd > ALL_AROUND_GLOBAL_COOLDOWN)
	{
		if (m_stacks > 0)
		{
			/*if (m_sound != nullptr){
				m_sound->PlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_THROW_SOUND);
			}*/
			Network::GetInstance()->SendAbility(ABILITIES_SHURIKEN, 0);
			if (m_stacks == SHURIKEN_MAX_STACK)
			{
				SetCooldown(SHURIKEN_COOLDOWN);
			}
			m_stacks -= 1;
			m_gcd = 0.0;
			return true;
		}
	}
	
	return false;
}

void ShurikenAbility::ResetCooldown()
{
	Ability::ResetCooldown();
	m_stacks = SHURIKEN_MAX_STACK;
}