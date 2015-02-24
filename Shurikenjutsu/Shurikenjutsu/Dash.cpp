#include "Dash.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"
#include <iostream>
#include "StatusEffect.h"

Dash::Dash(){}
Dash::Dash(const Dash& other){}
Dash::~Dash(){}

bool Dash::Initialize()
{
	SetDamage(DASH_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = DASH_COOLDOWN;
	m_stacks = -1;
	return true;
}

bool Dash::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		if (m_sound != nullptr){
			m_sound->PlaySound(PLAYSOUND::PLAYSOUND_DASH_STEPS_SOUND);
		}
		Network::GetInstance()->SendAbility(ABILITIES_DASH,0);
		SetCooldown(DASH_COOLDOWN);
		return true;
	}
	return false;
}

