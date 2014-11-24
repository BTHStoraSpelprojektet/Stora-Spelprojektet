#ifndef PLAYER
#define PLAYER
#include "MovingObject.h"
class Player :
	public Object
{
public:
	Player();
	~Player();
	bool Initialize(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);
	void Shutdown();
	void SetDirection(DirectX::XMFLOAT3 p_direction);
	DirectX::XMFLOAT3 GetDirection() const;
	void SetSpeed(float p_speed);
	float GetSpeed() const;
	void SetDamage(float p_damage);
	float GetDamage() const;	
	void SetHealth(unsigned int p_health);
	unsigned int GetHealth() const;
	void SetAgility(float p_agility);
	float GetAgility() const;

private:
	DirectX::XMFLOAT3 m_direction; // Riktning på spelare, för att kolla vart han är påväg / vänd.
	float m_speed;
	float m_damage = 0; // Sätts nog inviduellt per ability senare.
	int m_spells; // antalet spells om det behövs - skapa lista
	unsigned int m_health; // Player health
	float m_agility; // Speed på attacker och rullning m.m
};

#endif PLAYER