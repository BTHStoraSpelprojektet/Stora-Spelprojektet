#ifndef WHIPSECONDARYATTACKABILITY_H
#define WHIPSECONDARYATTACKABILITY_H

#include "Ability.h"

class WhipSecondaryAttackAbility : public Ability
{
public:
	WhipSecondaryAttackAbility();
	~WhipSecondaryAttackAbility();
	bool Initialize();
	bool Execute(float p_distance);
};
#endif