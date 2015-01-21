#ifndef PLAYER
#define PLAYER

#define WIN32_LEAN_AND_MEAN
#include "AnimatedObject.h"
#include "InputManager.h"
#include "Collisions.h"
#include "Globals.h"
#include "Dash.h"
#include "MeleeSwing.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
#include "CollisionManager.h"
#include "HealthBar.h"
#include "AbilityBar.h"
#include "SmokeBombAbility.h"


class Player :
	public AnimatedObject
{
public:
	Player();
	~Player();
	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void Shutdown();
	void UpdateMe();
	void Update();
	void UpdateAbilities();
	void Render();
	//void SetDamage(float p_damage);
	//float GetDamage() const;	
	void SetHealth(int p_health);
	int GetHealth() const;
	void SetMaxHealth(int p_maxHealth);
	int GetMaxHealth() const;
	//void SetAgility(float p_agility);
	//float GetAgility() const;
	void SetPosition(DirectX::XMFLOAT3 p_pos);
	void SendPosition(DirectX::XMFLOAT3 p_pos);

	DirectX::XMFLOAT3 GetFacingDirection();
	void SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection);
	DirectX::XMFLOAT3 GetAttackDirection();
	void SetAttackDirection(DirectX::XMFLOAT3 p_attackDir);
	void SetMyAttackDirection(DirectX::XMFLOAT3 p_attackDir);
	RakNet::RakNetGUID GetGuID();
	void SetGuID(RakNet::RakNetGUID p_guid);
	void SetIsAlive(bool p_isAlive);

	void UpdateHealthBar(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);

	void ResetCooldowns();

	void DoAnimation();

private:
	void CheckForSpecialAttack();
	bool CalculateDirection();
	void CalculateFacingAngle();

	float m_damage = 0; // S�tts nog inviduellt per ability senare.
	//int m_spells; // antalet spells om det beh�vs - skapa lista
	int m_health; // Player health
	int m_maxHealth; // Max player health
	//float m_agility; // Speed p� attacker och rullning m.m
	bool m_isAlive; // bool to check if the player should render and update itself
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
	Ability* m_megaShuriken;
	Ability* m_smokeBombAbility;

	AbilityBar m_abilityBar;
	HealthBar m_healthbar;
};
#endif PLAYER