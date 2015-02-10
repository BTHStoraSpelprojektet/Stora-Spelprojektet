#ifndef VOLLEYABILITY_H_
#define VOLLEYABILITY_H_

#include "Ability.h"

class VolleyAbility: public Ability
{
public:
	VolleyAbility();
	~VolleyAbility();

	bool Initialize();
	bool Execute(float p_distance);

private:
};
#endif
