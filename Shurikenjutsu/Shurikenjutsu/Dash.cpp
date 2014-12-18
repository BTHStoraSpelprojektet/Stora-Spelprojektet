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

bool Dash::Execute()
{
	if (Ability::Execute())
	{
		Network::GetInstance()->SendAbility(ABILITIES_DASH);
		SetCooldown(DASH_COOLDOWN);
	}
	return true;
}