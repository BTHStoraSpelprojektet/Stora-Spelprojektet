#ifndef SHURIKENABILITY_H_
#define SHURIKENABILITY_H_

#include "Ability.h"

class ShurikenAbility :
	public Ability
{
public:
	ShurikenAbility();
	~ShurikenAbility();

	bool Initialize();
	void Update();
	bool Execute(float p_distance);
	void ResetCooldown();
private:
	double m_gcd;
};
#endif SHURIKENABILITY_H_