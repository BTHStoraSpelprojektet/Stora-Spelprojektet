#ifndef MELEESWING
#define MELEESWING

#include "Ability.h"
#include "Network.h"

class MeleeSwing : public Ability
{
public:
	MeleeSwing();
	~MeleeSwing();

	void Execute();
};
#endif // !MELEESWING



