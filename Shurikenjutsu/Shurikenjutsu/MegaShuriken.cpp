#include "MegaShuriken.h"

MegaShuriken::MegaShuriken()
{

}

MegaShuriken::~MegaShuriken()
{

}

bool MegaShuriken::Initialize()
{
	SetDamage(MEGASHURIKEN_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(MEGASHURIKEN_COOLDOWN);
	return true;
}

bool MegaShuriken::Execute()
{
	if (Ability::Execute())
	{
		Network::GetInstance()->SendAbility(ABILITIES_MEGASHURIKEN);
		SetCooldown(MEGASHURIKEN_COOLDOWN);
		std::cout << "MEGASHURIKEN" << std::endl;
	}	
	return true;
}
