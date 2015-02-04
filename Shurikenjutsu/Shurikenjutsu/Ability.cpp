#include "Ability.h"
#include "Globals.h"

#include "StatusEffect.h"
#include "AnimatedObject.h"

Ability::Ability(){}
Ability::~Ability(){}
bool Ability::Initialize()
{
	SetDamage(0);
	SetTime(0.0);
	SetStatusEffect(&StatusEffect());
	SetCooldown(0.0);
	m_totalCooldown = 0.0f;
	m_stacks = -1;
	return true;
}

void Ability::Shutdown(){}
void Ability::Update()
{
	if (m_cooldown > 0.00)
	{
		m_cooldown = m_cooldown - GLOBAL::GetInstance().GetDeltaTime();
	}
}

bool Ability::Execute(float p_distance)
{
	if (m_cooldown <= 0.0)
	{
		return true;
	}

	return false;
}

void Ability::SetDamage(float p_damage)
{
	m_damage = p_damage;
}

float Ability::GetDamage()
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

void Ability::SetCooldown(double p_cooldown)
{
	m_cooldown = p_cooldown;
}

double Ability::GetCooldown()
{
	return m_cooldown;
}

void Ability::SetStatusEffect(StatusEffect *p_statusEffect)
{
	m_statusEffect = p_statusEffect;
}

StatusEffect* Ability::GetStatusEffect()
{
	return m_statusEffect;
}

void Ability::ResetCooldown()
{
	SetCooldown(0.0);
}

float Ability::GetTotalCooldown()
{
	return m_totalCooldown;
}

int Ability::GetStacks()
{
	return m_stacks;
}