#include "Dash.h"


Dash::Dash()
{
}


Dash::~Dash()
{
}

void Dash::Execute()
{
	Network::GetInstance()->SendAbility(ABILITIES_DASH);
}