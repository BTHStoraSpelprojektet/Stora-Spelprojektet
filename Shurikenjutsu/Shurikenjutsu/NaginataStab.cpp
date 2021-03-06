#include "NaginataStab.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "StatusEffect.h"
#include <iostream>

NaginataStab::NaginataStab(){}
NaginataStab::~NaginataStab(){}

bool NaginataStab::Initialize()
{
	SetDamage(NAGINATASTAB_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = NAGINATASTAB_COOLDOWN;
	m_stacks = -1;
	return true;
}

bool NaginataStab::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_NAGAINATASTAB, 0);
		SetCooldown(NAGINATASTAB_COOLDOWN);

		return true;
	}
	return false;
}