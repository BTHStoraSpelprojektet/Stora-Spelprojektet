#include "MeleeSwing.h"

MeleeSwing::MeleeSwing()
{
}


MeleeSwing::~MeleeSwing()
{
}

bool MeleeSwing::Initialize()
{
	SetDamage(KATANA_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(0.0f);
	return true;
}

bool MeleeSwing::Execute()
{
	if (Ability::Execute())
	{
		Network::GetInstance()->SendAbility(ABILITIES_MELEESWING);
		SetCooldown(ALL_AROUND_GOLOBAL_COOLDOWN);
		std::cout << "MELEE" << std::endl;
	}
	return true;
}