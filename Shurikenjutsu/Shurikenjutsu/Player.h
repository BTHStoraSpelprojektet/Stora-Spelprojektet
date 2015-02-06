#ifndef PLAYER
#define PLAYER

#define WIN32_LEAN_AND_MEAN
#include "AnimatedObject.h"
#include "Network.h"


class Ability;
class InputManager;
class HealthBar;
class AbilityBar;
class DebugBox;
class DebugCircle;

class Player :
	public AnimatedObject
{
public:
	Player();
	~Player();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void Shutdown();
	void UpdateMe();
	void Update();
	void UpdateAbilities();
	void Render();
	void RenderDepth();
	void RenderOutlining();
	void RenderAbilityBar();
	//void SetDamage(float p_damage);
	//float GetDamage() const;	
	void SetHealth(float p_health);
	float GetHealth() const;
	void SetMaxHealth(float p_maxHealth);
	float GetMaxHealth() const;
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
	bool GetIsAlive(void);
	void SetTeam(int p_team);
	int GetTeam();

	void UpdateHealthBar(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);
	void UpdateAbilityBar();

	void ResetCooldowns();

	void DoAnimation();

	bool IsVisible();
	void SetIsVisible(bool p_visiblie);

	Sphere GetSphere();
	OBB GetOBB();
	DebugBox debugBox;
	DebugCircle debugCircle;

protected:
	void CheckForSpecialAttack();
	bool CalculateDirection();
	void CalculateFacingAngle();
	void CalculatePlayerCubeCollision(OBB p_collidingBoxes);
	void CalculatePlayerBoxCollision(OBB p_collidingBoxes);


	//float m_damage = 0; // Sätts nog inviduellt per ability senare.
	//int m_spells; // antalet spells om det behövs - skapa lista
	float m_health; // Player health
	float m_maxHealth; // Max player health
	//float m_agility; // Speed på attacker och rullning m.m
	bool m_isAlive; // bool to check if the player should render and update itself
	InputManager* m_inputManager;
	DirectX::XMFLOAT3 m_attackDir;
	RakNet::RakNetGUID m_guid;
	int m_team;
	bool m_visible;

	void SetCalculatePlayerPosition();
	//DirectX::XMFLOAT3 m_playerPrevPos;
	
	DirectX::XMFLOAT3 m_dashDirection;
	float m_dashDistanceLeft;
	bool m_isDashing;
	float throwDistance;

	float m_globalCooldown;
	float m_maxGlobalCooldown;

	Sphere m_playerSphere;
	Ability* m_ability;
	Ability* m_noAbility;
	Ability* m_meleeAttack;
	Ability* m_meleeSpecialAttack;
	Ability* m_rangeAttack;
	Ability* m_rangeSpecialAttack;
	Ability* m_toolAbility;

	HealthBar* m_healthbar;
	AbilityBar* m_abilityBar;

	float m_directionUpdateTimer;
	DirectX::XMFLOAT3 m_oldPosition;
};
#endif PLAYER