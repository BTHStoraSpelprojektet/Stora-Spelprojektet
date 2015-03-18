#include "StickyTrapAbility.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"
#include "StatusEffect.h"


StickyTrapAbility::StickyTrapAbility(){}
StickyTrapAbility::~StickyTrapAbility(){}
bool StickyTrapAbility::Initialize()
{
	SetDamage(STICKY_TRAP_DAMAGE);
	SetTime(0.0f);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = STICKY_TRAP_COOLDOWN;
	m_stacks = -1;
	m_radius = 3.0f;
	m_range = STICKY_TRAP_RANGE;
	return true;
}
bool StickyTrapAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_STICKY_TRAP, p_distance);
		SetCooldown(STICKY_TRAP_COOLDOWN);
		return true;
	}

	return false;
}
float StickyTrapAbility::GetRange()
{
	return m_range;
}
float StickyTrapAbility::GetRadius()
{
	return m_radius;
}