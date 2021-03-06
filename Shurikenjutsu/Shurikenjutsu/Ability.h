#ifndef ABILITY_H_
#define ABILITY_H_

class StatusEffect;
class Sound;

class Ability
{
public:
	Ability();
	~Ability();

	virtual bool Initialize();
	virtual void Shutdown();
	virtual void Update();
	virtual bool Execute(float p_distance);

	virtual void SetDamage(float p_damage);
	virtual float GetDamage();
	virtual void SetTime(double p_time);
	virtual double GetTime();
	virtual void SetCooldown(double p_cooldown);
	virtual double GetCooldown();
	virtual float GetTotalCooldown();
	virtual void SetStatusEffect(StatusEffect *p_statusEffect);
	virtual StatusEffect* GetStatusEffect();
	virtual void ResetCooldown();
	virtual int GetStacks();
	virtual float GetRange();
	virtual float GetRadius();
	void SetSound(Sound* p_sound);

protected:
	float m_damage;
	double m_time;
	double m_cooldown;
	float m_totalCooldown;
	StatusEffect* m_statusEffect;
	int m_stacks;
	Sound* m_sound;

};
#endif // !ABILITY_H_