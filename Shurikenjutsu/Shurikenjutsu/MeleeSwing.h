#ifndef MELEESWING_H_
#define MELEESWING_H_

#include "Ability.h"
#include "Network.h"

class MeleeSwing : public Ability
{
public:
	MeleeSwing();
	~MeleeSwing();

	bool Initialize();
	bool Execute();
};
#endif // !MELEESWING_H_



