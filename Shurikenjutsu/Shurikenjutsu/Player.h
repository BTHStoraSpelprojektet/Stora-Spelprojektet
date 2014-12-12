#ifndef PLAYER
#define PLAYER

#define WIN32_LEAN_AND_MEAN
#include "MovingObject.h"
#include "InputManager.h"
#include "Collisions.h"
#include "Globals.h"
#include "Ability.h"
#include "Dash.h"
#include "CollisionManager.h"

class Player :
	public MovingObject
{
public:
	Player();
	~Player();
	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);
	void Shutdown();
	void UpdateMe();
	void Update();
	void SetDamage(float p_damage);
	float GetDamage() const;	
	void SetHealth(unsigned int p_health);
	unsigned int GetHealth() const;
	void SetAgility(float p_agility);
	float GetAgility() const;
	void SetPosition(DirectX::XMFLOAT3 p_pos);
	void SendPosition(DirectX::XMFLOAT3 p_pos);

	DirectX::XMFLOAT3 GetFacingDirection();
	void SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection);
	DirectX::XMFLOAT3 GetAttackDirection();
	void SetAttackDirection(DirectX::XMFLOAT3 p_attackDir);
	void SetMyAttackDirection(DirectX::XMFLOAT3 p_attackDir);
	RakNet::RakNetGUID GetGuID();
	void SetGuID(RakNet::RakNetGUID p_guid);

private:
	bool CalculateDirection();
	void CalculateFacingAngle();

	float m_damage = 0; // Sätts nog inviduellt per ability senare.
	int m_spells; // antalet spells om det behövs - skapa lista
	unsigned int m_health; // Player health
	float m_agility; // Speed på attacker och rullning m.m
	InputManager* m_inputManager;
	DirectX::XMFLOAT3 m_attackDir;
	RakNet::RakNetGUID m_guid;

	void SetCalculatePlayerPosition();
	DirectX::XMFLOAT3 m_playerPrevPos;

	Sphere m_playerSphere;
	Ability* m_ability;
	Ability* m_noAbility;
	Ability* m_buttonQ;
};

#endif PLAYER