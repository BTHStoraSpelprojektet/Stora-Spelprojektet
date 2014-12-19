#ifndef MEGASHURIKEN_H_
#define MEGASHURIKEN_H_

#include "Ability.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

class MegaShuriken :
	public Ability
{
public:
	MegaShuriken();
	~MegaShuriken();

	bool Initialize();
	bool Execute(float p_distance);
};

#endif //!MEGASHURIKEN_H_