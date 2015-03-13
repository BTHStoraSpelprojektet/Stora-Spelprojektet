#include "FanMelee.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>


FanMelee::FanMelee()
{
}


FanMelee::~FanMelee()
{
}

bool FanMelee::Initialize()
{
	SetDamage(FANMELEE_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = FANMELEE_COOLDOWN;
	m_stacks = -1;
	return true;
}

bool FanMelee::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		/*if (m_sound != nullptr){
		m_sound->PlaySound(PLAYSOUND::PLAYSOUND_AIR_CUT_SOUND);
		}*/
		Network::GetInstance()->SendAbility(ABILITIES_FANMELEE, 0);
		SetCooldown(FANMELEE_COOLDOWN);

		return true;
	}
	return false;
}