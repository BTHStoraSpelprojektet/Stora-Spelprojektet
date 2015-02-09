#ifndef STICKYTRAPABILITY_H
#define STICKYTRAPABILITY_H

#include "Ability.h"


class StickyTrapAbility : public Ability
{
public:
	StickyTrapAbility();
	~StickyTrapAbility();
	bool Initialize();
	bool Execute(float p_distance);
};

#endif