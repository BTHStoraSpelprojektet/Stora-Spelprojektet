#include "MeleeSwing.h"

MeleeSwing::MeleeSwing()
{
}


MeleeSwing::~MeleeSwing()
{
}

void MeleeSwing::Execute()
{
	Network::GetInstance()->SendAbility(ABILITIES_MELEESWING);
}