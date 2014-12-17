#ifndef MEGASHURIKEN_H_
#define MEGASHURIKEN_H_

#include "Ability.h"
#include "Network.h"

class MegaShuriken :
	public Ability
{
public:
	MegaShuriken();
	~MegaShuriken();

	bool Initialize();
	bool Execute();
};

#endif //!MEGASHURIKEN_H_