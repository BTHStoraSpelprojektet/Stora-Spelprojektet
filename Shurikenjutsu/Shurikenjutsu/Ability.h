#ifndef ABILITY_H_
#define ABILITY_H_

#include "StatusEffect.h"

class Ability
{
public:
	Ability();
	~Ability();

	bool Initialize();
	void Shutdown();
	void Update();
	void Apply();

	void SetDamage(unsigned int p_damage);
	unsigned int GetDamage();
	void SetTime(double p_time);
	double GetTime();
	void SetStatusEffect(StatusEffect p_statusEffect);
	StatusEffect GetStatusEffect();


private:
	unsigned int m_damage;
	double m_time;
	StatusEffect m_statusEffect;


};
#endif // !ABILITY_H_