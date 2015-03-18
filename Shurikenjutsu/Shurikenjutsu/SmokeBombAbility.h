#ifndef SMOKEBOMBABILITY_H
#define SMOKEBOMBABILITY_H

#include "Ability.h"

class SmokeBombAbility : public Ability
{
public:
	SmokeBombAbility();
	~SmokeBombAbility();
	bool Initialize();
	bool Execute(float p_distance);
	float GetRange();
	float GetRadius();
private:
	float m_radius;
	float m_range;
};



#endif