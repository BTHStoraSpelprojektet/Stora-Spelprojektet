#ifndef ABILITY_H_
#define ABILITY_H_

class StatusEffect;

class Ability
{
public:
	Ability();
	~Ability();

	virtual bool Initialize();
	virtual void Shutdown();
	virtual void Update();
	virtual bool Execute(float p_distance);

	virtual void SetDamage(unsigned int p_damage);
	virtual unsigned int GetDamage();
	virtual void SetTime(double p_time);
	virtual double GetTime();
	virtual void SetCooldown(double p_cooldown);
	virtual double GetCooldown();
	virtual void SetStatusEffect(StatusEffect *p_statusEffect);
	virtual StatusEffect* GetStatusEffect();
	virtual void ResetCooldown();

protected:
	unsigned int m_damage;
	double m_time;
	double m_cooldown;
	StatusEffect* m_statusEffect;



};
#endif // !ABILITY_H_