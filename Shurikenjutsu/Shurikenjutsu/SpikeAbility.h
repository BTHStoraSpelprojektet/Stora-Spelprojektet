#ifndef SPIKEBOMBABILITY_H
#define SPIKEBOMBABILITY_H

#include "Ability.h"

class SpikeAbility : public Ability
{
public:
	SpikeAbility();
	~SpikeAbility();
	bool Initialize();
	bool Execute(float p_distance);
	float GetRange();
	float GetRadius();
private:
	float m_radius;
	float m_range;
};
#endif