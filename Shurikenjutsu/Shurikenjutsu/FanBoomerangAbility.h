#ifndef FANBOOMERANGABILITY_H_
#define FANBOOMERANGABILITY_H_

#include "Ability.h"

class FanBoomerangAbility : public Ability
{
public:
	FanBoomerangAbility();
	~FanBoomerangAbility();

	bool FanBoomerangAbility::Initialize();
	bool FanBoomerangAbility::Execute(float p_distance);
};

#endif