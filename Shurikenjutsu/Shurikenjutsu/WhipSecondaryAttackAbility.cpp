#include "WhipSecondaryAttackAbility.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>


WhipSecondaryAttackAbility::WhipSecondaryAttackAbility(){}
WhipSecondaryAttackAbility::~WhipSecondaryAttackAbility(){}
bool WhipSecondaryAttackAbility::Initialize()
{
	SetDamage(WHIP_SP_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = 0.5f;
	return true;
}

bool WhipSecondaryAttackAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_WHIP_SECONDARY, 0);
		SetCooldown(ALL_AROUND_GLOBAL_COOLDOWN);
		std::cout << "Spin that whip!!" << std::endl;
		return true;
	}
	return false;
}