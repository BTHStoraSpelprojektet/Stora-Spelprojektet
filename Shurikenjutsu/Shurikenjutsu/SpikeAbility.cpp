#include "SpikeAbility.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"
#include "StatusEffect.h"

SpikeAbility::SpikeAbility(){}
SpikeAbility::~SpikeAbility(){}
bool SpikeAbility::Initialize()
{
	SetDamage(SPIKE_DAMAGE);
	SetTime(0.0f);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = SPIKE_COOLDOWN;
	m_stacks = -1;
	m_radius = 2.3f;
	m_range = SPIKE_RANGE;
	return true;
}
bool SpikeAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_SPIKETRAP, p_distance);
		SetCooldown(SPIKE_COOLDOWN);
		return true;
	}

	return false;
}
float SpikeAbility::GetRange()
{
	return m_range;
}
float SpikeAbility::GetRadius()
{
	return m_radius;
}