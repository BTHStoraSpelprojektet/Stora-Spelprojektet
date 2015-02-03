#include "MegaShuriken.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>

MegaShuriken::MegaShuriken(){}
MegaShuriken::~MegaShuriken(){}

bool MegaShuriken::Initialize()
{
	SetDamage(MEGASHURIKEN_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = MEGASHURIKEN_COOLDOWN;
	return true;
}

bool MegaShuriken::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_MEGASHURIKEN,0);
		SetCooldown(MEGASHURIKEN_COOLDOWN);
		std::cout << "MEGASHURIKEN" << std::endl;
		return true;
	}	
	return false;
}