#include "ShurikenAbility.h"


ShurikenAbility::ShurikenAbility()
{
}


ShurikenAbility::~ShurikenAbility()
{
}

bool ShurikenAbility::Initialize()
{
	SetDamage(25);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());
	SetCooldown(3.0);
	m_stacks = 3;
	m_stackCD = 3.0;
	return true;
}

void ShurikenAbility::Update()
{
	Ability::Update();
	m_stackCD -= GLOBAL::GetInstance().GetDeltaTime();
	if (m_stacks < 3 && GetCooldown() <= 0.0 && m_stackCD <= 0.0)
	{
		m_stacks += 1;
		m_stackCD = 3.0;
		std::cout << "U gained a stack!" << std::endl;
	}

}

bool ShurikenAbility::Execute()
{
	if (m_stacks >= 1)
	{
		Network::GetInstance()->SendAbility(ABILITIES_SHURIKEN);
		m_stacks -= 1;
		if (m_stacks == 2)
		{
			SetCooldown(3.0);
		}
	}
	return true;
}