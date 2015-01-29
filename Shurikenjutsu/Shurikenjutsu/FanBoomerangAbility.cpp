#include "FanBoomerangAbility.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>

FanBoomerangAbility::FanBoomerangAbility(){}
FanBoomerangAbility::~FanBoomerangAbility(){}

bool FanBoomerangAbility::Initialize()
{
	SetDamage(10);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	return true;
}

bool FanBoomerangAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_FANBOOMERANG, 0);
		SetCooldown(1.0f);
		std::cout << "FAN BOOMERANG" << std::endl;
		return true;
	}

	return false;
}
