#ifndef SHURIKENABILITY_H_
#define SHURIKENABILITY_H_

#include "Ability.h"
#include "Network.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
class ShurikenAbility :
	public Ability
{
public:
	ShurikenAbility();
	~ShurikenAbility();

	bool Initialize();
	void Update();
	bool Execute();
private:
	int m_stacks;
	double m_gcd;
};
#endif SHURIKENABILITY_H_