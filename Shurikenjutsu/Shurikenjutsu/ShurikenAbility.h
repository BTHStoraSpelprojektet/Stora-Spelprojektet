#ifndef SHURIKENABILITY_H_
#define SHURIKENABILITY_H_

#include "Ability.h"
#include "Network.h"
class ShurikenAbility :
	public Ability
{
public:
	ShurikenAbility();
	~ShurikenAbility();

	void Execute();
};
#endif SHURIKENABILITY_H_