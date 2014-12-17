#include "Dash.h"


Dash::Dash()
{
}


Dash::~Dash()
{
}

bool Dash::Initialize()
{
	SetDamage(30);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(8.0);
	return true;
}

bool Dash::Execute()
{
	if (Ability::Execute())
	{
		Network::GetInstance()->SendAbility(ABILITIES_DASH);
		SetCooldown(8.0);
	}
	return true;
}