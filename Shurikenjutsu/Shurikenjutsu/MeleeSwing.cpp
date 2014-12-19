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

bool MeleeSwing::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_MELEESWING,0);
		SetCooldown(ALL_AROUND_GOLOBAL_COOLDOWN);
		std::cout << "MELEE" << std::endl;
	}
	return true;
}