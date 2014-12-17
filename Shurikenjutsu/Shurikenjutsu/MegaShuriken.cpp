#include "MegaShuriken.h"

MegaShuriken::MegaShuriken()
{

}

MegaShuriken::~MegaShuriken()
{

}

bool MegaShuriken::Initialize()
{
	SetDamage(40);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(10.0);
	return true;
}

bool MegaShuriken::Execute()
{
	if (Ability::Execute())
	{
		Network::GetInstance()->SendAbility(ABILITIES_MEGASHURIKEN);
		SetCooldown(10.0);
		std::cout << "MEGASHURIKEN" << std::endl;
	}	
	return true;
}
