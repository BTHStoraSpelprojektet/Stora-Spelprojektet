#ifndef PLAYER
#define PLAYER

#define WIN32_LEAN_AND_MEAN
#include "MovingObject.h"
#include "InputManager.h"
#include "Collisions.h"
#include "Globals.h"
#include "Ability.h"
#include "Dash.h"
#include "MeleeSwing.h"
#include "ShurikenAbility.h"
#include "CollisionManager.h"
#include "HealthBar.h"

class Player :
	public MovingObject
{
public:
	Player();
	~Player();
	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, int p_health, int p_maxHealth, float p_agility);
	void Shutdown();
	void UpdateMe();
	void Update();
	void Render(SHADERTYPE p_shader);
	void SetDamage(float p_damage);
	float GetDamage() const;	
	void SetHealth(int p_health);
	int GetHealth() const;
	void SetMaxHealth(int p_maxHealth);
	int GetMaxHealth() const;
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

	void UpdateHealthBar(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);

private:
	void CheckForSpecialAttack();
	bool CalculateDirection();
	void CalculateFacingAngle();

	float m_damage = 0; // Sätts nog inviduellt per ability senare.
	int m_spells; // antalet spells om det behövs - skapa lista
	int m_health; // Player health
	int m_maxHealth; // Max player health
	float m_agility; // Speed på attacker och rullning m.m
	InputManager* m_inputManager;
	DirectX::XMFLOAT3 m_attackDir;
	RakNet::RakNetGUID m_guid;

	void SetCalculatePlayerPosition();
	DirectX::XMFLOAT3 m_playerPrevPos;

	Sphere m_playerSphere;
	Ability* m_ability;
	Ability* m_noAbility;
	Ability* m_dash;
	Ability* m_meleeSwing;
	Ability* m_shurikenAbility;

	HealthBar m_healthbar;


	float m_dashCd;
};

#endif PLAYER