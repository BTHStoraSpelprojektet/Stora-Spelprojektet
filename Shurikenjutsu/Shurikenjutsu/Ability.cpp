#include "Ability.h"


Ability::Ability()
{
}


Ability::~Ability()
{
}

bool Ability::Initialize()
{
	SetDamage(0);
	SetTime(0.0);
	SetStatusEffect(StatusEffect());

	return true;
}

void Ability::Shutdown()
{

}

void Ability::Update()
{

}

void Ability::Execute()
{

}

void Ability::SetDamage(unsigned int p_damage)
{
	m_damage = p_damage;
}

unsigned int Ability::GetDamage()
{
	return m_damage;
}

void Ability::SetTime(double p_time)
{
	m_time = p_time;
}

double Ability::GetTime()
{
	return m_time;
}

void Ability::SetStatusEffect(StatusEffect p_statusEffect)
{
	m_statusEffect = p_statusEffect;
}

StatusEffect Ability::GetStatusEffect()
{
	return m_statusEffect;
}