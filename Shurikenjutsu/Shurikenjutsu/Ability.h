#ifndef ABILITY_H_
#define ABILITY_H_

#include "StatusEffect.h"

class Ability
{
public:
	Ability();
	~Ability();

	virtual bool Initialize();
	virtual void Shutdown();
	virtual void Update();
	virtual void Execute();

	virtual void SetDamage(unsigned int p_damage);
	virtual unsigned int GetDamage();
	virtual void SetTime(double p_time);
	virtual double GetTime();
	virtual void SetStatusEffect(StatusEffect p_statusEffect);
	virtual StatusEffect GetStatusEffect();


private:
	unsigned int m_damage;
	double m_time;
	StatusEffect m_statusEffect;


};
#endif // !ABILITY_H_