#ifndef FANMELEE_H_
#define FANMELEE_H_

#include "Ability.h"

class FanMelee :
	public Ability
{
public:
	FanMelee();
	~FanMelee();

	bool Initialize() override;
	bool Execute(float p_distance) override;
};

#endif // !FANMELEE_H_