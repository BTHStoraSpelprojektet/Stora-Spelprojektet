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
	m_totalCooldown = KATANA_COOLDOWN;
	m_stacks = -1;
	return true;
}

bool MeleeSwing::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		/*if (m_sound != nullptr){
			m_sound->PlaySound(PLAYSOUND::PLAYSOUND_AIR_CUT_SOUND);
		}*/
		Network::GetInstance()->SendAbility(ABILITIES_MELEESWING,0);
		SetCooldown(KATANA_COOLDOWN);

		return true;
	}
	return false;
}