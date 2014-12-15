#include "Dash.h"
#include "Network.h"

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