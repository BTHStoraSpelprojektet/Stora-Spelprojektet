#include "MeleeSwing.h"

MeleeSwing::MeleeSwing()
{
}


MeleeSwing::~MeleeSwing()
{
}

bool MeleeSwing::Initialize()
{
	SetDamage(50);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(0.5);
	return true;
}

bool MeleeSwing::Execute()
{
	if (Ability::Execute())
	{
		Network::GetInstance()->SendAbility(ABILITIES_MELEESWING);
		SetCooldown(0.5);
	}
	return true;
}