#ifndef SMOKEBOMBABILITY_H
#define SMOKEBOMBABILITY_H

#include "Ability.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"

class SmokeBombAbility : public Ability
{
public:
	SmokeBombAbility();
	~SmokeBombAbility();
	bool Initialize();
	bool Execute();
};



#endif