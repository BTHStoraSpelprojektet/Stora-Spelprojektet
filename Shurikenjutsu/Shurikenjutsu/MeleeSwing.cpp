#include "MeleeSwing.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>

MeleeSwing::MeleeSwing(){}
MeleeSwing::~MeleeSwing(){}

bool MeleeSwing::Initialize()
{
	SetDamage(KATANA_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = 0.5f;
	m_stacks = -1;
	return true;
}

bool MeleeSwing::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_MELEESWING,0);
		SetCooldown(ALL_AROUND_GLOBAL_COOLDOWN);
		std::cout << "MELEE" << std::endl;
		return true;
	}
	return false;
}