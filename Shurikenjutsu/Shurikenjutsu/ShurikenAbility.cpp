#include "ShurikenAbility.h"


ShurikenAbility::ShurikenAbility()
{
}


ShurikenAbility::~ShurikenAbility()
{
}

void ShurikenAbility::Execute()
{
	Network::GetInstance()->SendAbility(ABILITIES_SHURIKEN);
}