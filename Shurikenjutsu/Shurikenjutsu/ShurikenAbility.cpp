#include "ShurikenAbility.h"


ShurikenAbility::ShurikenAbility(){}
ShurikenAbility::~ShurikenAbility(){}
bool ShurikenAbility::Initialize()
{
	SetDamage(SHURIKEN_DAMAGE);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(0.0f);
	m_stacks = SHURIKEN_MAX_STACK;
	m_gcd = ALL_AROUND_GOLOBAL_COOLDOWN + 1.0f;
	return true;
}
void ShurikenAbility::Update()
{
	Ability::Update();
	if (m_stacks < SHURIKEN_MAX_STACK && GetCooldown() <= 0.0)
	{
		m_stacks += 1;
		//std::cout << "U gained a stack!" << std::endl;
		if (m_stacks < SHURIKEN_MAX_STACK)
		{
			SetCooldown(SHURIKEN_COOLDOWN);
		}
	}
	m_gcd += GLOBAL::GetInstance().GetDeltaTime();
}
bool ShurikenAbility::Execute()
{
	if (m_gcd > ALL_AROUND_GOLOBAL_COOLDOWN)
	{
		if (m_stacks > 0)
		{
			Network::GetInstance()->SendAbility(ABILITIES_SHURIKEN);
			if (m_stacks == SHURIKEN_MAX_STACK)
			{
				SetCooldown(SHURIKEN_COOLDOWN);
			}
			m_stacks -= 1;
			m_gcd = 0.0;
		}
	}
	
	return true;
}

void ShurikenAbility::ResetCooldown()
{
	Ability::ResetCooldown();
	m_stacks = 3;
}