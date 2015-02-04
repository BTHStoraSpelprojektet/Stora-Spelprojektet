#ifndef KUNAIABILITY_H_
#define KUNAIABILITY_H_

#include "Ability.h"

class KunaiAbility :
	public Ability
{
public:
	KunaiAbility();
	~KunaiAbility();

	bool Initialize();
	void Update();
	bool Execute(float p_distance);
	void ResetCooldown();
};

#endif // !KUNAIABILITY_H_