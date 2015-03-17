#ifndef PLAYER
#define PLAYER
#define WIN32_LEAN_AND_MEAN

#include "AnimatedObject.h"
#include "../CommonLibs/RakNet/RakNetTypes.h"
#include "Sound.h"

class Ability;
class InputManager;
class HealthBar;
class AbilityBar;
class StickyTrap;
class AttackPredictionEditor;
class FloatingText;
class ParticleEmitter;

class Player : public AnimatedObject
{
public:
	Player();
	~Player();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_ninjaType, std::string p_name, UINT32 p_color);
	void Shutdown();
	void UpdateMe();
	void Update();
	void UpdateAbilities();
	void Render();
	virtual void RenderAttackLocations();
	void RenderDepth();
	void RenderDepthOutlining();
	void RenderOutlining(DirectX::XMFLOAT4 p_color);
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
	void InterpolatePos(DirectX::XMFLOAT3 p_pos);


	DirectX::XMFLOAT3 GetFacingDirection();
	void SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection);
	DirectX::XMFLOAT3 GetAttackDirection();
	void SetAttackDirection(DirectX::XMFLOAT3 p_attackDir);
	void InterpolateAttackDir(DirectX::XMFLOAT3 p_attackDir);
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

	void ChooseTool();

	Sphere GetSphere();
	OBB GetOBB();

	void SetSound(Sound* p_sound);
	void SetStickyTrapList(std::vector<StickyTrap*> p_stickyTrapList);
	Sound::SoundEmitter* m_soundEmitter;

	void SetInvis(bool p_invis);
	bool IsInvis();

	std::string GetName();

protected:
	void CheckForSpecialAttack();
	bool CalculateDirection();
	void CalculateFacingAngle();
	void CalculatePlayerCubeCollision(OBB p_collidingBoxes);
	bool CheckSidesIfMultipleCollisions();
	void SetOriginalSpeed(float p_speed);
	void StillCDText();
	void SetInterpolatingPos(DirectX::XMFLOAT3 p_pos);
	void SetInterpolatingAttackDir(DirectX::XMFLOAT3 p_dir);

	void SpawnBlood();
	void UpdateBlood();

	float m_health; // Player health
	float m_maxHealth; // Max player health
	bool m_isAlive; // bool to check if the player should render and update itself
	DirectX::XMFLOAT3 m_attackDir;
	RakNet::RakNetGUID m_guid;
	int m_team;
	bool m_visible;

	void SetCalculatePlayerPosition();

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

	float m_originalSpeed;

	float m_naginataStbTime;

	bool m_updateVisibility;

	int m_ninjaType;

	Object* m_aimSphere;
	Object* m_aimArrow;
	Object* m_aimPole;
	Object* m_aimFrustrum;
	bool localPlayer;
	AttackPredictionEditor *m_ape;
	FloatingText* m_floatingText;

	Sound* m_sound;

	Trail* m_trail;
	std::vector<StickyTrap*> m_stickyTrapList;

	bool m_invis;
	std::string m_name;

	DirectX::XMFLOAT3 m_interpolatingPos;
	float m_interpolatigPosSpeed;
	bool m_interpolatePos;

	DirectX::XMFLOAT3 m_interpolatingAttackDir;
	float m_interpolatigAttackDirSpeed;
	bool m_interpolateAttackDir;

	bool m_onPressed;

	ParticleEmitter* m_bloodParticles;
	float m_bloodParticlesTimer;
	DirectX::XMFLOAT3 m_bloodPos;

};
#endif PLAYER