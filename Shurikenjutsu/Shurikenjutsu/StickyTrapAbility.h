#ifndef STICKYTRAPABILITY_H
#define STICKYTRAPABILITY_H

#include "Ability.h"


class StickyTrapAbility : public Ability
{
public:
	StickyTrapAbility();
	~StickyTrapAbility();
	bool Initialize();
	bool Execute(float p_distance);
	float GetRange();
	float GetRadius();

private:
	float m_radius;
	float m_range;
};

#endif