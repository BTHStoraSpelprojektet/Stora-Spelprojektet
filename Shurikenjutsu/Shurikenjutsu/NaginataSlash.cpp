#include "NaginataSlash.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>

NaginataSlash::NaginataSlash(){}

NaginataSlash::NaginataSlash(NaginataSlash &other){}

NaginataSlash::~NaginataSlash(){}

bool NaginataSlash::Initialize()
{
	SetDamage(NAGINATA_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = NAGINATA_COOLDOWN;
	m_stacks = -1;
	return true;
}

bool NaginataSlash::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_NAGINATASLASH, 0);
		SetCooldown(NAGINATA_COOLDOWN);

		return true;
	}
	return false;
}