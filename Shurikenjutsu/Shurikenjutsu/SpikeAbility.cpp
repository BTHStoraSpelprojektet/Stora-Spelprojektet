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