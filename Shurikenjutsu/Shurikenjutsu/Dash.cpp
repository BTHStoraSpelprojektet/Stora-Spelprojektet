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
	std::cout << "I DASHED!" << std::endl;
	Network::GetInstance()->SendAbility(ABILITIES_DASH);
}