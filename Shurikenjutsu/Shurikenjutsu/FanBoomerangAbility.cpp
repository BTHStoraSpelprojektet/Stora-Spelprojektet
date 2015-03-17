#include "FanBoomerangAbility.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>

FanBoomerangAbility::FanBoomerangAbility(){}
FanBoomerangAbility::~FanBoomerangAbility(){}

bool FanBoomerangAbility::Initialize()
{
	SetDamage(FANBOOMERANG_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_stacks = -1;

	return true;
}

bool FanBoomerangAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_FANBOOMERANG, 0);
		SetCooldown(FANBOOMERANG_COOLDOWN);

		return true;
	}

	return false;
}
