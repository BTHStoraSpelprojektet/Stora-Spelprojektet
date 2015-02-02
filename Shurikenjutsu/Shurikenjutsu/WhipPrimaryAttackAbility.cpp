#include "WhipPrimaryAttackAbility.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>


WhipPrimaryAttackAbility::WhipPrimaryAttackAbility(){}
WhipPrimaryAttackAbility::~WhipPrimaryAttackAbility(){}
bool WhipPrimaryAttackAbility::Initialize()
{
	SetDamage(WHIP_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = WHIP_COOLDOWN;
	return true;
}

bool WhipPrimaryAttackAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_WHIP_PRIMARY, 0);
		SetCooldown(WHIP_COOLDOWN);
		std::cout << "Just whip it!" << std::endl;
		return true;
	}
	return false;
}