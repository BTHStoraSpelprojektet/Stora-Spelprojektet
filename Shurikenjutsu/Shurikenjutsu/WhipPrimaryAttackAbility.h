#ifndef WHIPPRIMARYATTACKABILITY_H
#define WHIPPRIMARYATTACKABILITY_H

#include "Ability.h"

class WhipPrimaryAttackAbility : public Ability
{
public:
	WhipPrimaryAttackAbility();
	~WhipPrimaryAttackAbility();


	bool Initialize();
	bool Execute(float p_distance);
};

#endif