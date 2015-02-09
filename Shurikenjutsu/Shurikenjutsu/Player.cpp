#include "Player.h"
#include "CollisionManager.h"
#include "Collisions.h"
#include "Globals.h"
#include "InputManager.h"
#include "Ability.h"
#include "HealthBar.h"
#include "AbilityBar.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "AnimationControl.h"
#include "VisibilityComputer.h"
#include "StickyTrap.h"

Player::Player(){}
Player::~Player(){}

void* Player::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void Player::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool Player::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction)
{
	if (!AnimatedObject::Initialize(p_filepath, p_pos, p_direction))
	{
		return false;
	}
	SetAttackDirection(DirectX::XMFLOAT3(0, 0, 0));
	m_playerSphere = Sphere(0.0f,0.0f,0.0f,0.5f);
	m_inputManager = InputManager::GetInstance();
	
	m_ability = new Ability();
	m_noAbility = new Ability();

	m_healthbar = new HealthBar();
	m_healthbar->Initialize(100.0f, 15.0f);

	m_team = 0;
	m_isDashing = false;

	m_abilityBar = new AbilityBar();
	m_abilityBar->Initialize(0.0f, -420.0f, 5);

	m_directionUpdateTimer = 0.0f;

	m_health = 100.0f;
	m_maxHealth = 100.0f;
	m_isAlive = true;
	m_guid = RakNet::RakNetGUID();
	m_visible = true;
	m_dashDirection = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_dashDistanceLeft = 0.0f;
	m_oldPosition = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);

	throwDistance = 0.0f;

	m_globalCooldown = 0.0f;
	m_maxGlobalCooldown = ALL_AROUND_GLOBAL_COOLDOWN;

	return true;
}

void Player::Shutdown()
{
	AnimatedObject::Shutdown();
	if (m_noAbility != nullptr)
	{
		m_noAbility->Shutdown();
		delete m_noAbility;
	}

	if (m_meleeAttack != nullptr)
	{
		m_meleeAttack->Shutdown();
		delete m_meleeAttack;
	}

	if (m_meleeSpecialAttack != nullptr)
	{
		m_meleeSpecialAttack->Shutdown();
		delete m_meleeSpecialAttack;
	}

	if (m_rangeAttack != nullptr)
	{
		m_rangeAttack->Shutdown();
		delete m_rangeAttack;
	}

	if (m_rangeSpecialAttack != nullptr)
	{
		m_rangeSpecialAttack->Shutdown();
		delete m_rangeSpecialAttack;
	}

	if (m_toolAbility != nullptr)
	{
		m_toolAbility->Shutdown();
		delete m_toolAbility;
	}

	if (m_healthbar != nullptr)
	{
		m_healthbar->Shutdown();
		delete m_healthbar;
	}

	if (m_abilityBar != nullptr)
	{
		m_abilityBar->Shutdown();
}
}

void Player::UpdateMe(std::vector<StickyTrap*> p_stickyTrapList)
{
	// Check values from server
	if (Network::GetInstance()->IsConnected())
	{
		SetHealth(Network::GetInstance()->GetMyPlayer().currentHP);
		SetMaxHealth(Network::GetInstance()->GetMyPlayer().maxHP);
		SetIsAlive(Network::GetInstance()->GetMyPlayer().isAlive);
		SetTeam(Network::GetInstance()->GetMyPlayer().team);
		//SetPosition(DirectX::XMFLOAT3(Network::GetInstance()->GetMyPlayer().x, Network::GetInstance()->GetMyPlayer().y, Network::GetInstance()->GetMyPlayer().z));
	}

	// Move


	//////////////////////*********************************************************************************************
	////	VARF�R UPPDATERAS MOVE TV� G�NGER?? H�NDER �VEN L�NGRE NER
	////    Detta l�ser �ven problemet med att man r�r sig efter man �r d�d.
	////	Speeden var dock tvungen att dubblas nu n�r den bara uppdateras en g�ng per update.
	////////////////////**********************************************************************
	/*if (CalculateDirection() || Network::GetInstance()->ConnectedNow())
	{
		SetCalculatePlayerPosition();
	}*/

	SetSpeed(m_originalSpeed);
	for (unsigned int i = 0; i < p_stickyTrapList.size(); i++)
	{
		if (p_stickyTrapList[i]->GetGUID() != Network::GetInstance()->GetMyGUID())
		{
			if (Collisions::SphereSphereCollision(m_playerSphere, p_stickyTrapList[i]->GetStickyTrapSphere()))
			{
				SetSpeed(m_originalSpeed * STICKY_TRAP_SLOW_PRECENTAGE);
			}
		}
	}

	// Don't update player if he is dead
	if (!m_isAlive)
	{
		return;
	}

	// Check for dash
	if (Network::GetInstance()->HaveDashed())
	{		
		// Calc distance
		float dx = Network::GetInstance()->GetDashLocation().x - m_position.x;
		float dz = Network::GetInstance()->GetDashLocation().z - m_position.z;
		m_dashDistanceLeft = sqrt(dx * dx + dz * dz);

		// Calc dir
		DirectX::XMVECTOR tempVector = DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(dx, 0, dz));
		tempVector = DirectX::XMVector3Normalize(tempVector);
		DirectX::XMStoreFloat3(&m_dashDirection, tempVector);

		m_isDashing = true;
	}
	// Dash movement
	if (m_isDashing)
	{
		float distance = DASH_SPEED * m_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
		Sphere playerSphere = m_playerSphere;
		playerSphere.m_position.x += m_dashDistanceLeft * m_dashDirection.x;
		playerSphere.m_position.y += m_dashDistanceLeft * m_dashDirection.z;		
		if (!CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere))
		{
		if (distance >= m_dashDistanceLeft)
		{
			m_position.x += m_dashDistanceLeft * m_dashDirection.x;
			m_position.z += m_dashDistanceLeft * m_dashDirection.z;
			m_dashDistanceLeft = 0.0f;
			m_isDashing = false;
		}
		else
		{
			m_position.x += (DASH_SPEED * m_speed * (float)GLOBAL::GetInstance().GetDeltaTime()) * m_dashDirection.x;
			m_position.z += (DASH_SPEED * m_speed * (float)GLOBAL::GetInstance().GetDeltaTime()) * m_dashDirection.z;
			m_dashDistanceLeft -= distance;
		}

		// If we dashed, update shadow shapes.
		VisibilityComputer::GetInstance().UpdateVisibilityPolygon(Point(m_position.x, m_position.z), GraphicsEngine::GetDevice());
		}
		else
		{
			m_isDashing = false;
		}

		SendPosition(m_position);
	}

	// Move
	if ((CalculateDirection() || Network::GetInstance()->ConnectedNow()) && !m_isDashing)
	{
		SetCalculatePlayerPosition();

		// If we moved, update shadow shapes.
		VisibilityComputer::GetInstance().UpdateVisibilityPolygon(Point(m_position.x, m_position.z), GraphicsEngine::GetDevice());
	}
	m_playerSphere.m_position = m_position;
	
	m_ability = m_noAbility;
	CheckForSpecialAttack();

	// Range attack
	if (InputManager::GetInstance()->IsRightMousePressed())
	{
		// Check cd so m_ability does not get set if u have cooldown preventing other abilities to be casted.
		if (m_rangeAttack->GetStacks() > 0 || m_rangeAttack->GetStacks() == -1)
		{
			m_ability = m_rangeAttack;
		}
	}

	// Melee attack
	if (InputManager::GetInstance()->IsLeftMousePressed())
	{
		if ((float)m_meleeAttack->GetCooldown() <= 0.0f)
		{
		m_ability = m_meleeAttack;
		}
	}


	// Count down cooldowns
	UpdateAbilities();
	throwDistance = CollisionManager::GetInstance()->CalculateMouseDistanceFromPlayer(m_position);//m_playerSphere.m_position);
	if (m_ability != m_noAbility && m_globalCooldown <= 0.0f)
	{
		if (m_ability->Execute(throwDistance))
		{
			// Play ability animation if we did any
			DoAnimation();

				// Set global cooldown
				m_globalCooldown = m_maxGlobalCooldown;
		}
	}

	UpdateAbilityBar();
}

void Player::CheckForSpecialAttack()
{
	if (m_inputManager->IsKeyPressed(VkKeyScan('e')))
	{
		if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
		{
			m_ability = m_rangeSpecialAttack;
		}
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('q')))
	{
		if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
		{
			m_ability = m_meleeSpecialAttack;
		}
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('r')))
	{
		if ((float)m_toolAbility->GetCooldown() <= 0.0f)
		{
			m_ability = m_toolAbility;
		}
	}
}

bool Player::CalculateDirection()
{
	float x, y, z;
	bool moved = false;

	x = 0;
	y = 0;//Box(DirectX::XMFLOAT3(35.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(1.0f, 1.0f, 40.0f)))
	z = 0;
	//m_playerPrevPos = m_position;

	if (m_inputManager->IsKeyPressed(VkKeyScan('w')))
	{
		z += 1;
		moved = true;
	}

	if (m_inputManager->IsKeyPressed(VkKeyScan('a')))
	{
		x += -1;
		moved = true;
	}

	if (m_inputManager->IsKeyPressed(VkKeyScan('s')))
	{
		z += -1;
		moved = true;
	}

	if (m_inputManager->IsKeyPressed(VkKeyScan('d')))
	{
		x += 1;
		moved = true;
	}

	DirectX::XMVECTOR tempVector = DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(x, y, z));
	tempVector = DirectX::XMVector3Normalize(tempVector);
	DirectX::XMFLOAT3 tempFloat;
	DirectX::XMStoreFloat3(&tempFloat, tempVector);
	SetDirection(tempFloat);
	AnimatedObject::HandleInput(tempFloat);

	return moved;
}

void Player::Update()
{
	int state = Network::GetInstance()->AnimationChanged(m_guid);
	if (state != -1)
	{
		AnimatedObject::ChangeAnimationState((AnimationState)state);
	}
}

void Player::UpdateAbilities()
{
	m_meleeAttack->Update();
	m_meleeSpecialAttack->Update();
	m_rangeAttack->Update();
	m_rangeSpecialAttack->Update();
	m_toolAbility->Update();

	if (m_globalCooldown > 0.0f)
	{
		m_globalCooldown -= (float)GLOBAL::GetInstance().GetDeltaTime();
}

}

void Player::ResetCooldowns()
{
	m_meleeAttack->ResetCooldown();
	m_meleeSpecialAttack->ResetCooldown();
	m_rangeAttack->ResetCooldown();
	m_rangeSpecialAttack->ResetCooldown();
	m_toolAbility->ResetCooldown();

	UpdateAbilities();
}

void Player::SetHealth(float p_health)
{
	if (p_health < 0)
	{
		m_health = 0;
	}
	else
	{
		m_health = p_health;
	}	
}

float Player::GetHealth() const
{
	return m_health;
}

void Player::SetMaxHealth(float p_maxHealth)
{
	m_maxHealth = p_maxHealth;
}

float Player::GetMaxHealth() const
{
	return m_maxHealth;
}

void Player::SendPosition(DirectX::XMFLOAT3 p_pos)
{
	SetPosition(p_pos);
	
	if (Network::GetInstance()->IsConnected())
	{
		DirectX::XMFLOAT3 pos = GetPosition();
		Network::GetInstance()->SendPlayerPos(pos.x, pos.y, pos.z);
	}
}

void Player::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	m_directionUpdateTimer += (float)GLOBAL::GetInstance().GetDeltaTime();
	if (m_directionUpdateTimer > 0.03f)
	{
		DirectX::XMFLOAT3 dir;
		dir.x = p_pos.x - m_oldPosition.x;
		dir.y = p_pos.y - m_oldPosition.y;
		dir.z = p_pos.z - m_oldPosition.z;
		AnimatedObject::NetworkInput(dir);
		m_directionUpdateTimer = 0.0f;

		m_oldPosition = p_pos;
	}

	Object::SetPosition(p_pos);
}

DirectX::XMFLOAT3 Player::GetFacingDirection()
{
	return Object::GetRotation();
}

void Player::SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection)
{
	//Object::SetRotation(p_facingDirection);
}

DirectX::XMFLOAT3 Player::GetAttackDirection()
{
	return m_attackDir;
}

void Player::SetMyAttackDirection(DirectX::XMFLOAT3 p_attackDir)
{
	m_attackDir = p_attackDir;
	CalculateFacingAngle();

	AnimatedObject::SetIkDirection(p_attackDir);

	if (Network::GetInstance()->IsConnected())
	{
		DirectX::XMFLOAT3 dir = GetAttackDirection();
		Network::GetInstance()->SendPlayerDir(dir.x, dir.y, dir.z);
	}
}

void Player::SetAttackDirection(DirectX::XMFLOAT3 p_attackDir)
{
	m_attackDir = p_attackDir;
	CalculateFacingAngle();
	AnimatedObject::SetIkDirection(p_attackDir);
}

RakNet::RakNetGUID Player::GetGuID()
{
	return m_guid;
}

void Player::SetGuID(RakNet::RakNetGUID p_guid)
{
	m_guid = p_guid;
}

void Player::CalculateFacingAngle()
{
	DirectX::XMFLOAT3 v1 = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);
	DirectX::XMFLOAT3 v2 = GetAttackDirection();

	float x = (v1.x * v2.z) - (v2.x * v1.z);
	float y = (v1.x * v2.x) - (v1.z * v2.z);

	float faceAngle = atan2(y, x) - 1.57079632679f;
	SetFacingDirection(DirectX::XMFLOAT3(GetFacingDirection().x, faceAngle, GetFacingDirection().z));
}

void Player::SetCalculatePlayerPosition()
{
	float speedXDeltaTime = m_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
	// Check collision between player and static boxes
	std::vector<OBB> collidingBoxes = CollisionManager::GetInstance()->CalculateLocalPlayerCollisionWithStaticBoxes(Sphere(m_position, m_playerSphere.m_radius), m_speed, m_direction);
	for (unsigned int i = 0; i < collidingBoxes.size(); i++)
	{ 
		if (m_direction.x == 1 || m_direction.x == -1 || m_direction.z == 1 || m_direction.z == -1)
		{
			Sphere playerSphere = Sphere(m_position, m_playerSphere.m_radius - 0.1f);
			playerSphere.m_position.x = m_position.x;
			playerSphere.m_position.z = m_position.z - 1.0f * speedXDeltaTime;
			bool down = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
			playerSphere.m_position.x = m_position.x;
			playerSphere.m_position.z = m_position.z + 1.0f * speedXDeltaTime;
			bool up = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
			playerSphere.m_position.x = m_position.x + 1.0f * speedXDeltaTime;
			playerSphere.m_position.z = m_position.z;
			bool right = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
			playerSphere.m_position.x = m_position.x - 1.0f * speedXDeltaTime;
			playerSphere.m_position.z = m_position.z;
			bool left = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);

			if (down && m_direction.z == -1)
			{
				SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
			}
			else if (up && m_direction.z == 1)
			{
				SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
			}
			else if (right && m_direction.x == 1)
			{
				SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
			}
			else if (left && m_direction.x == -1)
			{
				SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
			}
		}
		else if (collidingBoxes.size() > 1)
		{

			if (CheckSidesIfMultipleCollisions() == true)
			{
				SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
			}
		else
		{
			CalculatePlayerCubeCollision(collidingBoxes[i]);
		}
	}
		else
		{
			CalculatePlayerCubeCollision(collidingBoxes[i]);
		}
	}

	// Check collision between player and static spheres
	std::vector<Sphere> collidingSpheres = CollisionManager::GetInstance()->CalculateLocalPlayerCollisionWithStaticSpheres(m_playerSphere, m_speed, m_direction);
	for (unsigned int i = 0; i < collidingSpheres.size(); i++)
	{
		float r = collidingSpheres[i].m_radius;
		float deltaZ = m_position.z - collidingSpheres[i].m_position.z;
		float deltaX = m_position.x - collidingSpheres[i].m_position.x;
		float angle = atan2f(deltaZ, deltaX);

		float circleX = cosf(angle) * r;
		float circleY = sinf(angle) * r;

		float dz = collidingSpheres[i].m_position.z - m_position.z;
		float dx = collidingSpheres[i].m_position.x - m_position.x;
		float angle1 = atan2(dz, dx);
		float angle2 = atan2(m_direction.z, m_direction.x);
		float offset = angle1 - angle2;
		

		// Special cases ftw. Dont ask!
		if (angle1 < 0 && angle2 < 0)
		{
			offset *= -1;
		}		
		
		if (angle2 >= 0 && angle1 < 0)
		{
			offset *= -1;
		}

		if (angle2 >= DirectX::XM_PIDIV2 && angle1 <= -DirectX::XM_PIDIV2)
		{
			offset *= -1;
		}

		if (angle2 <= -DirectX::XM_PIDIV2 && angle1 >= DirectX::XM_PIDIV2)
		{
			offset *= -1;
		}


		// Circle equation:
		// circleX * X + circleY * Y = Radius * Radius
		// Bryt ut s� att y blir ensam
		// Y = (Radius * Radius - circleX * X) / circleY		
		float yValue = (r * r - circleX * (circleX + offset)) / circleY;
		
		DirectX::XMFLOAT3 dir = DirectX::XMFLOAT3((circleX + offset) - circleX, 0, yValue - circleY);
		// Normalize
		float length = sqrt(dir.x * dir.x + dir.z * dir.z);
		dir.x = dir.x / length;
		dir.z = dir.z / length;
		SetDirection(dir);
	}

	if (collidingSpheres.size() > 1 || collidingSpheres.size() >= 1 && collidingBoxes.size() >= 1)
	{
		SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
	}

	//float speed_X_Delta = (float)GLOBAL::GetInstance().GetDeltaTime() * m_speed;
	SendPosition(DirectX::XMFLOAT3(m_position.x + m_direction.x * speedXDeltaTime, m_position.y + m_direction.y * speedXDeltaTime, m_position.z + m_direction.z * speedXDeltaTime));
}

bool Player::CheckSidesIfMultipleCollisions()
{
	float speedXDeltaTime = m_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
	Sphere playerSphere = Sphere(m_position, m_playerSphere.m_radius - 0.1f);
	playerSphere.m_position.x = m_position.x;
	playerSphere.m_position.z = m_position.z - 1.0f * speedXDeltaTime;
	bool down = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
	playerSphere.m_position.x = m_position.x;
	playerSphere.m_position.z = m_position.z + 1.0f * speedXDeltaTime;
	bool up = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
	playerSphere.m_position.x = m_position.x + 1.0f * speedXDeltaTime;
	playerSphere.m_position.z = m_position.z;
	bool right = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
	playerSphere.m_position.x = m_position.x - 1.0f * speedXDeltaTime;
	playerSphere.m_position.z = m_position.z;
	bool left = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);

	if (!left && !up && !right)
	{
		return false;
	}
	else if (!up && !right && !down)
	{
		return false;
	}
	else if (!right && !down && !left)
	{
		return false;
	}
	else if (!down && !left && !up)
	{
		return false;
	}

	bool x = m_direction.x > 0;
	bool z = m_direction.z > 0;

	if (x && left)
	{
		return false;
	}
	else if (right && !x)
	{
		return false;
	}
	else if (!z && up)
	{
		return false;
	}
	else if (down && z)
	{
		return false;
	}

	return true;
}
void Player::CalculatePlayerCubeCollision(OBB p_collidingBoxes)
{
	float speedXDeltaTime = m_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
	Sphere playerSphere = Sphere(m_position, m_playerSphere.m_radius - 0.1f);
	playerSphere.m_position.x = m_position.x;
	playerSphere.m_position.z = m_position.z - 1.0f * speedXDeltaTime;
	bool aboveBox = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
	playerSphere.m_position.x = m_position.x;
	playerSphere.m_position.z = m_position.z + 1.0f * speedXDeltaTime;
	bool belowBox = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
	playerSphere.m_position.x = m_position.x + 1.0f * speedXDeltaTime;
	playerSphere.m_position.z = m_position.z;
	bool leftOfBox = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);
	playerSphere.m_position.x = m_position.x - 1.0f * speedXDeltaTime;
	playerSphere.m_position.z = m_position.z;
	bool rightOfBox = CollisionManager::GetInstance()->CheckCollisionWithAllStaticObjects(playerSphere);

	float x = m_direction.x;
	float z = m_direction.z;
	if (x < 0 && z < 0)//down left
	{
		if (rightOfBox && aboveBox)
		{
			SetPosition(DirectX::XMFLOAT3(m_position.x, m_position.y, p_collidingBoxes.m_center.z + p_collidingBoxes.m_extents.z + m_playerSphere.m_radius*1.1f));
			x = -1;
			z = 0;
		}
		else
		{
			if (rightOfBox)
			{
				x = 0;
				z = -1;
			}
			if (aboveBox)
			{
				x = -1;
				z = 0;
			}
		}
	}
	else if (x > 0 && z < 0)//down right
	{
		if (leftOfBox && aboveBox)
		{
			SetPosition(DirectX::XMFLOAT3(p_collidingBoxes.m_center.x - p_collidingBoxes.m_extents.x - m_playerSphere.m_radius*1.1f, m_position.y, m_position.z));
			x = 0;
			z = -1;
		}
		else
		{
			if (leftOfBox)
			{
				x = 0;
				z = -1;
			}
			if (aboveBox)
			{
				x = 1;
				z = 0;
			}
		}
	}
	else if (x < 0 && z > 0)//up left // works goood
	{
		if (rightOfBox && belowBox)
		{
			SetPosition(DirectX::XMFLOAT3(p_collidingBoxes.m_center.x + p_collidingBoxes.m_extents.x + m_playerSphere.m_radius*1.1f, m_position.y, m_position.z));
			x = 0;
			z = 1;
		}
		else
		{
			if (rightOfBox)
			{
				x = 0;
				z = 1;
			}
			if (belowBox)
			{
				x = -1;
				z = 0;
			}
		}
	}
	else if (x > 0 && z > 0)//up right // works goood
	{
		if (leftOfBox && belowBox)
		{
			SetPosition(DirectX::XMFLOAT3(m_position.x, m_position.y, p_collidingBoxes.m_center.z - p_collidingBoxes.m_extents.z - m_playerSphere.m_radius*1.1f));
			x = 1;
			z = 0;
		}
		else
		{
			if (leftOfBox)
			{
				x = 0;
				z = 1;
			}
			if (belowBox)
			{
				x = 1;
				z = 0;
			}
		}
	}
	SetDirection(DirectX::XMFLOAT3(x, 0.0f, z));
}

void Player::UpdateHealthBar(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	m_healthbar->Update(m_position, (int)m_health, (int)m_maxHealth, p_view, p_projection);
}

void Player::UpdateAbilityBar()
{
	if ((float)m_meleeAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_meleeAttack->GetCooldown(), m_meleeAttack->GetTotalCooldown(),m_meleeAttack->GetStacks(), 0);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_meleeAttack->GetStacks(), 0);
	}
	if ((float)m_rangeAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_rangeAttack->GetCooldown(), m_rangeAttack->GetTotalCooldown(), m_rangeAttack->GetStacks(), 1);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_rangeAttack->GetStacks(), 1);
	}
	if ((float)m_meleeSpecialAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_meleeSpecialAttack->GetCooldown(), m_meleeSpecialAttack->GetTotalCooldown(), m_meleeSpecialAttack->GetStacks(), 2);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_meleeSpecialAttack->GetStacks(), 2);
	}
	if ((float)m_rangeSpecialAttack->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_rangeSpecialAttack->GetCooldown(), m_rangeSpecialAttack->GetTotalCooldown(), m_rangeSpecialAttack->GetStacks(), 3);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_rangeSpecialAttack->GetStacks(), 3);
	}
	if ((float)m_toolAbility->GetCooldown() > 0.0f)
	{
		m_abilityBar->Update((float)m_toolAbility->GetCooldown(), m_toolAbility->GetTotalCooldown(), m_toolAbility->GetStacks(), 4);
	}
	else
	{
		m_abilityBar->Update(m_globalCooldown, m_maxGlobalCooldown, m_toolAbility->GetStacks(), 4);
	}
}

void Player::Render()
{
	if (m_isAlive)
	{
		m_healthbar->Render();
	}

	AnimatedObject::RenderPlayer(m_team);
}

void Player::RenderDepth()
{
	AnimatedObject::RenderDepth();
}

void Player::RenderOutlining()
{
	if (m_isAlive)
	{
		AnimatedObject::RenderOutlining();
	}
}

void Player::RenderAbilityBar()
{
	m_abilityBar->Render();
}

void Player::SetIsAlive(bool p_isAlive)
{
	if (m_isAlive != p_isAlive)
	{
		if (!p_isAlive)
		{
			AnimatedObject::ChangeAnimationState(AnimationState::Death);
		}
		else
		{
			AnimatedObject::ChangeAnimationState(AnimationState::Spawn);
		}
	}

	m_isAlive = p_isAlive;	
}

bool Player::GetIsAlive()
{
	return m_isAlive;
}

void Player::SetTeam(int p_team)
{
	m_team = p_team;
}

int Player::GetTeam()
{
	return m_team;
}

void Player::DoAnimation()
{
	// DO THIS WITH STATES
	if (m_ability == m_meleeAttack)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Melee);
		Network::GetInstance()->SendAnimationState(AnimationState::Melee);
	}
	else if (m_ability == m_meleeSpecialAttack)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Special1);
		Network::GetInstance()->SendAnimationState(AnimationState::Special1);
	}
	else if (m_ability == m_rangeSpecialAttack)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Special2);
		Network::GetInstance()->SendAnimationState(AnimationState::Special2);
	}
	else if (m_ability == m_toolAbility)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Tool);
		Network::GetInstance()->SendAnimationState(AnimationState::Tool);
	}
	else if (m_ability == m_rangeAttack)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Range);
		Network::GetInstance()->SendAnimationState(AnimationState::Range);
	}
}

bool Player::IsVisible()
{
	return m_visible;
}

void Player::SetIsVisible(bool p_visible)
{
	m_visible = p_visible;
}

Sphere Player::GetSphere()
{
	if (m_boundingSpheres.size() <= 0)
	{
		return Sphere(1000.0f, 1000.0f, 1000.0f, 1.0f);
	}
	return m_boundingSpheres[0];
}

OBB Player::GetOBB()
{
	/*if (m_boundingSpheres.size() <= 0)
	{
		return Sphere(1000.0f, 1000.0f, 1000.0f, 1.0f);
	}*/
	TransformBoundingBoxes();
	return m_boundingBoxes[0];
}

void Player::SetOriginalSpeed(float p_speed)
{
	m_originalSpeed = p_speed;
}