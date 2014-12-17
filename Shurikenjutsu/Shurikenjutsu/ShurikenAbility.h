#ifndef SHURIKENABILITY_H_
#define SHURIKENABILITY_H_

#include "Ability.h"
#include "Network.h"
class ShurikenAbility :
	public Ability
{
public:
	ShurikenAbility();
	~ShurikenAbility();

	bool Initialize();
	void Update();
	bool Execute();
	void ResetCooldown();
private:
	int m_stacks;
	double m_stackCD;
	double m_gcd;
};
#endif SHURIKENABILITY_H_