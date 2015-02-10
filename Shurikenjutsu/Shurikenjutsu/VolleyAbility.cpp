#include "VolleyAbility.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"
#include "StatusEffect.h"

VolleyAbility::VolleyAbility(){}
VolleyAbility::~VolleyAbility(){}

bool VolleyAbility::Initialize()
{
	SetDamage(VOLLEY_DAMAGE);
	SetTime(0.0f);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = VOLLEY_COOLDOWN;
	m_stacks = -1;
	return true;
}
bool VolleyAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_VOLLEY, p_distance);
		SetCooldown(VOLLEY_COOLDOWN);
		return true;
	}

	return false;
}
