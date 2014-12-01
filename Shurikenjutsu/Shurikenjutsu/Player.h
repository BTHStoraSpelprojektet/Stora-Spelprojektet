#ifndef PLAYER
#define PLAYER

#include "Network.h"
#include "MovingObject.h"
#include "InputManager.h"

class Player :
	public MovingObject
{
public:
	Player();
	~Player();
	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);
	void Shutdown();
	void Update(double p_deltaTime);
	void UpdateMe(double p_deltaTime);
	void SetDamage(float p_damage);
	float GetDamage() const;	
	void SetHealth(unsigned int p_health);
	unsigned int GetHealth() const;
	void SetAgility(float p_agility);
	float GetAgility() const;
	void SetPosition(DirectX::XMFLOAT3 p_pos);
	void SetMyPosition(DirectX::XMFLOAT3 p_pos);

	DirectX::XMFLOAT3 GetFacingDirection();
	void SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection);
	DirectX::XMFLOAT3 GetAttackDirection();
	void SetAttackDirection(DirectX::XMFLOAT3 p_attackDir);
private:
	float m_damage = 0; // S�tts nog inviduellt per ability senare.
	int m_spells; // antalet spells om det beh�vs - skapa lista
	unsigned int m_health; // Player health
	float m_agility; // Speed p� attacker och rullning m.m
	InputManager* m_inputManager;
	DirectX::XMFLOAT3 m_attackDir;
};

#endif PLAYER