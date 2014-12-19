#include "Dash.h"


Dash::Dash(){}
Dash::~Dash(){}

bool Dash::Initialize()
{
	SetDamage(DASH_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(DASH_COOLDOWN);
	return true;
}

bool Dash::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_DASH,0);
		SetCooldown(DASH_COOLDOWN);
	}
	return true;
}