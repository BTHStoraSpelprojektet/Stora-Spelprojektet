#ifndef FLASHBANGABILITY_H
#define FLASHBANGABILITY_H

#include "Ability.h"

class FlashBangAbility : public Ability
{
public:
	FlashBangAbility();
	~FlashBangAbility();
	bool Initialize();
	bool Execute(float p_distance);
};

#endif