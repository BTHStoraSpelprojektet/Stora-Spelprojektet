#include "FlashBangAbility.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"
#include "StatusEffect.h"


FlashBangAbility::FlashBangAbility(){}
FlashBangAbility::~FlashBangAbility(){}
bool FlashBangAbility::Initialize()
{
	SetDamage(FLASHBANG_DAMAGE);
	SetTime(0.0f);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0f);
	m_totalCooldown = FLASHBANG_COOLDOWN;
	m_stacks = -1;
	m_radius = 10.0f;
	m_range = FLASHBANG_RANGE;
	return true;
}
bool FlashBangAbility::Execute(float p_distance)
{
	if (Ability::Execute(p_distance))
	{
		Network::GetInstance()->SendAbility(ABILITIES_THROW_FLASH, p_distance);
		SetCooldown(FLASHBANG_COOLDOWN);
		return true;
	}

	return false;
}
float FlashBangAbility::GetRange()
{
	return m_range;
}
float FlashBangAbility::GetRadius()
{
	return m_radius;
}