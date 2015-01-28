#include "SmokeBombAbility.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"
#include "StatusEffect.h"

SmokeBombAbility::SmokeBombAbility(){}
SmokeBombAbility::~SmokeBombAbility(){}
bool SmokeBombAbility::Initialize()
{
	SetDamage(SMOKEBOMB_DAMAGE);
	SetTime(0.0f);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	return true;
}
bool SmokeBombAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_SMOKEBOMB, p_distance);
		SetCooldown(SMOKEBOMB_COOLDOWN);
		return true;
	}

	return false;
}