#ifndef MELEESWING_H_
#define MELEESWING_H_

#include "Ability.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

class MeleeSwing : public Ability
{
public:
	MeleeSwing();
	~MeleeSwing();

	bool Initialize();
	bool Execute(float p_distance);
};
#endif // !MELEESWING_H_



