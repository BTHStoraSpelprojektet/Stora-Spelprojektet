#ifndef DASH_H_
#define DASH_H_

#include "Ability.h"
#include "Network.h"
#include <iostream>
#include "..\CommonLibs\GameplayGlobalVariables.h"

class Dash : public Ability
{
public:
	Dash();
	~Dash();

	bool Initialize();
	bool Execute();
};
#endif // !DASH_H_