#ifndef FLASHBANGABILITY_H
#define FLASHBANGABILITY_H

#include "Ability.h"

class FlashBangAbility : public Ability
{
public:
	FlashBangAbility();
	~FlashBangAbility();
	bool Initialize();
	bool Execute(float p_distance);
	float GetRange();
	float GetRadius();
private:
	float m_radius;
	float m_range;
};

#endif