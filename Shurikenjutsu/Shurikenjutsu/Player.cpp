#include "Player.h"

#include "SmokeBombAbility.h"
#include "SpikeAbility.h"
#include "CollisionManager.h"
#include "Dash.h"
#include "Collisions.h"
#include "Globals.h"
#include "MeleeSwing.h"
#include "InputManager.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
#include "Ability.h"
#include "HealthBar.h"
#include "AbilityBar.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "AnimationControl.h"
#include "VisibilityComputer.h"

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
	if (!AnimatedObject::Initialize(p_filepath, p_pos, p_direction, CHARACTAR_KATANA_SHURIKEN_SPEED))
	{
		return false;
	}
	SetAttackDirection(DirectX::XMFLOAT3(0, 0, 0));
	m_playerSphere = Sphere(0.0f,0.0f,0.0f,0.5f);
	m_inputManager = InputManager::GetInstance();
	
	m_ability = new Ability();
	m_noAbility = new Ability();

	m_dash = new Dash();
	m_dash->Initialize();

	m_meleeSwing = new MeleeSwing();
	m_meleeSwing->Initialize();

	m_shurikenAbility = new ShurikenAbility();
	m_shurikenAbility->Initialize();
	m_isAlive = true;

	m_megaShuriken = new MegaShuriken();
	m_megaShuriken->Initialize();

	m_smokeBombAbility = new SmokeBombAbility();
	m_smokeBombAbility->Initialize();

	m_spikeAbility = new SpikeAbility();
	m_spikeAbility->Initialize();

	m_healthbar = new HealthBar();
	m_healthbar->Initialize(100.0f, 15.0f);

	m_team = 0;
	m_isDashing = false;

	m_abilityBar = new AbilityBar();
	m_abilityBar->Initialize(0.0f, -420.0f, 5);

	m_directionUpdateTimer = 0.0f;

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

	if (m_dash != nullptr)
	{
		m_dash->Shutdown();
		delete m_dash;
	}

	if (m_meleeSwing != nullptr)
	{
		m_meleeSwing->Shutdown();
		delete m_meleeSwing;
	}

	if (m_shurikenAbility != nullptr)
	{
		m_shurikenAbility->Shutdown();
		delete m_shurikenAbility;
	}

	if (m_megaShuriken != nullptr)
	{
		m_megaShuriken->Shutdown();
		delete m_megaShuriken;
	}

	if (m_smokeBombAbility != nullptr)
	{
		m_smokeBombAbility->Shutdown();
		delete m_smokeBombAbility;
	}
	if (m_spikeAbility != nullptr)
	{
		m_spikeAbility->Shutdown();
		delete m_spikeAbility;
	}
	if (m_healthbar != nullptr)
	{
		m_healthbar->Shutdown();
		delete m_healthbar;
	}

	/*if (m_abilityBar != nullptr)
	{
		m_abilityBar->Shutdown();
	}*/
}

void Player::UpdateMe()
{
	// Check values from server
	if (Network::GetInstance()->IsConnected())
	{
		SetHealth(Network::GetInstance()->GetMyPlayer().currentHP);
		SetMaxHealth(Network::GetInstance()->GetMyPlayer().maxHP);
		SetIsAlive(Network::GetInstance()->GetMyPlayer().isAlive);
		SetTeam(Network::GetInstance()->GetMyPlayer().team);
	}

	m_playerSphere.m_position = m_position;
	// Move
	if (CalculateDirection() || Network::GetInstance()->ConnectedNow())
	{
		SetCalculatePlayerPosition();
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

		SendPosition(m_position);
	}

	// Move
	if ((CalculateDirection() || Network::GetInstance()->ConnectedNow()) && !m_isDashing)
	{
		SetCalculatePlayerPosition();

		// If we moved, update shadow shapes.
		VisibilityComputer::GetInstance().UpdateVisibilityPolygon(Point(m_position.x, m_position.z), GraphicsEngine::GetDevice());
	}
	
	m_ability = m_noAbility;
	CheckForSpecialAttack();


	// Melee attack
	if (InputManager::GetInstance()->IsLeftMousePressed())
	{
		m_ability = m_meleeSwing;
	}

	// Cast shuriken
	if (InputManager::GetInstance()->IsRightMousePressed())
	{
		m_ability = m_shurikenAbility;
	}

	// Check health from server
	if (Network::GetInstance()->IsConnected())
	{
		SetHealth(Network::GetInstance()->GetMyPlayer().currentHP);
	}

	// Temp to set max health
	if (Network::GetInstance()->ConnectedNow())
	{
		SetMaxHealth(Network::GetInstance()->GetMyPlayer().maxHP);
	}

	// Count down cooldowns
	UpdateAbilities();
	float temp = CollisionManager::GetInstance()->CalculateMouseDistanceFromPlayer(m_playerSphere.m_position);
	if (m_ability->Execute(temp))
	{
		// Play ability animation if we did any
		DoAnimation();
	}

	UpdateAbilityBar();
}

void Player::CheckForSpecialAttack()
{
	if (m_inputManager->IsKeyPressed(VkKeyScan('e')))
	{
		m_ability = m_megaShuriken;
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('q')))
	{
		m_ability = m_dash;
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('r')))
	{
		m_ability = m_smokeBombAbility;
		//m_ability = m_spikeAbility;
	}
}
bool Player::CalculateDirection()
{
	float x, y, z;
	bool moved = false;

	x = 0;
	y = 0;//Box(DirectX::XMFLOAT3(35.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(1.0f, 1.0f, 40.0f)))
	z = 0;
	m_playerPrevPos = m_position;

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
	m_dash->Update();
	m_meleeSwing->Update();
	m_shurikenAbility->Update();
	m_megaShuriken->Update();
	m_smokeBombAbility->Update();
	m_spikeAbility->Update();
}

void Player::ResetCooldowns()
{
	m_dash->ResetCooldown();
	m_meleeSwing->ResetCooldown();
	m_shurikenAbility->ResetCooldown();
	m_megaShuriken->ResetCooldown();
	m_smokeBombAbility->ResetCooldown();
	m_spikeAbility->ResetCooldown();

	UpdateAbilities();
}
void Player::SetHealth(int p_health)
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

int Player::GetHealth() const
{
	return m_health;
}

void Player::SetMaxHealth(int p_maxHealth)
{
	m_maxHealth = p_maxHealth;
}

int Player::GetMaxHealth() const
{
	return m_maxHealth;
}

void Player::SendPosition(DirectX::XMFLOAT3 p_pos)
{
	AnimatedObject::SetPosition(p_pos);
	
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
	// Check collision between player and static boxes
	std::vector<OBB> collidingBoxes = CollisionManager::GetInstance()->CalculateLocalPlayerCollisionWithStaticBoxes(m_playerSphere, m_speed, m_direction);
	for (unsigned int i = 0; i < collidingBoxes.size(); i++)
	{ 
		float temp2 = collidingBoxes[i].m_extents.x - collidingBoxes[i].m_extents.z;
		if (temp2 < 0)
		{
			temp2 *= -1;
		}
		
		if (m_direction.x == 1 || m_direction.x == -1 || m_direction.z == 1 || m_direction.z == -1)
		{
			if (i > 0)
			{
				if ((collidingBoxes[i].m_center.x != collidingBoxes[i - 1].m_center.x) || (collidingBoxes[i].m_center.y != collidingBoxes[i - 1].m_center.y))
				{
					SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
				}
				else
				{
					SetDirection(DirectX::XMFLOAT3(m_direction.x, 0.0f, m_direction.z));
				}
			}
			else
			{
				SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
			}
		}
		else if (collidingBoxes[i].m_direction.w == 1.0f || temp2 < 0.5f)
		{
			CalculatePlayerCubeCollision(collidingBoxes[i]);
		}
		else
		{
			CalculatePlayerBoxCollision(collidingBoxes[i]);
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


		// Circel ekvation:
		// circleX * X + circleY * Y = Radius * Radius
		// Bryt ut så att y blir ensamt
		// Y = (Radius * Radius - circleX * X) / circleY		
		float yValue = (r * r - circleX * (circleX + offset)) / circleY;
		
		DirectX::XMFLOAT3 dir = DirectX::XMFLOAT3((circleX + offset) - circleX, 0, yValue - circleY);
		// Normalize
		float length = sqrt(dir.x * dir.x + dir.z * dir.z);
		dir.x = dir.x / length;
		dir.z = dir.z / length;
		SetDirection(dir);
	}

	float speed_X_Delta = (float)GLOBAL::GetInstance().GetDeltaTime() * m_speed;
	SendPosition(DirectX::XMFLOAT3(m_position.x + m_direction.x * speed_X_Delta, m_position.y + m_direction.y * speed_X_Delta, m_position.z + m_direction.z * speed_X_Delta));
}
void Player::CalculatePlayerCubeCollision(OBB p_collidingBoxes)
{
	bool rightOfBox = m_position.x >(p_collidingBoxes.m_center.x + p_collidingBoxes.m_extents.x);
	bool leftOfBox = m_position.x < (p_collidingBoxes.m_center.x - p_collidingBoxes.m_extents.x);
	bool aboveBox = m_position.z >(p_collidingBoxes.m_center.z + p_collidingBoxes.m_extents.z);
	bool belowBox = m_position.z < (p_collidingBoxes.m_center.z - p_collidingBoxes.m_extents.z);

	float x = m_direction.x;
	float z = m_direction.z;
	if (x < 0 && z < 0)//down left
	{
		if (rightOfBox == aboveBox)
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
		if (leftOfBox == aboveBox)
		{
			SetPosition(DirectX::XMFLOAT3(m_position.x, m_position.y, p_collidingBoxes.m_center.z + p_collidingBoxes.m_extents.z + m_playerSphere.m_radius*1.1f));
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
		if (rightOfBox == belowBox)
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
		if (leftOfBox == belowBox)
		{
			SetPosition(DirectX::XMFLOAT3(m_position.x, m_position.y, p_collidingBoxes.m_center.z - p_collidingBoxes.m_extents.z - m_playerSphere.m_radius*1.1f));
			x = 0;
			z = -1;
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
void Player::CalculatePlayerBoxCollision(OBB p_collidingBoxes)
{
	bool rightOfBox = m_position.x >(p_collidingBoxes.m_center.x + p_collidingBoxes.m_extents.z);
	bool leftOfBox = m_position.x < (p_collidingBoxes.m_center.x - p_collidingBoxes.m_extents.z);
	bool aboveBox = m_position.z >(p_collidingBoxes.m_center.z + p_collidingBoxes.m_extents.x);
	bool belowBox = m_position.z < (p_collidingBoxes.m_center.z - p_collidingBoxes.m_extents.x);
	float x = m_direction.x;
	float z = m_direction.z;
	if (x < 0 && z < 0)//down left
	{
		if (rightOfBox == aboveBox)
		{
			SetPosition(DirectX::XMFLOAT3(m_position.x + m_playerSphere.m_radius*1.1f, m_position.y, p_collidingBoxes.m_center.z + p_collidingBoxes.m_extents.x - m_playerSphere.m_radius*1.1f));
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
		if (leftOfBox == aboveBox)
		{
			SetPosition(DirectX::XMFLOAT3(p_collidingBoxes.m_center.x - p_collidingBoxes.m_extents.z - m_playerSphere.m_radius*1.1f, m_position.y, m_position.z));
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
		if (rightOfBox == belowBox)
		{
			SetPosition(DirectX::XMFLOAT3(p_collidingBoxes.m_center.x + p_collidingBoxes.m_extents.z + m_playerSphere.m_radius*1.1f, m_position.y, m_position.z));
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
		if (leftOfBox == belowBox)
		{
			SetPosition(DirectX::XMFLOAT3(m_position.x, m_position.y, p_collidingBoxes.m_center.z - p_collidingBoxes.m_extents.x + m_playerSphere.m_radius*1.1f));
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
	m_healthbar->Update(m_position, m_health, m_maxHealth, p_view, p_projection);
}

void Player::UpdateAbilityBar()
{
	m_abilityBar->Update((float)m_meleeSwing->GetCooldown(), 0.5f, 0);
	m_abilityBar->Update((float)m_shurikenAbility->GetCooldown(), SHURIKEN_COOLDOWN, 1);
	m_abilityBar->Update((float)m_dash->GetCooldown(), DASH_COOLDOWN, 2);
	m_abilityBar->Update((float)m_megaShuriken->GetCooldown(), MEGASHURIKEN_COOLDOWN, 3);
	//m_abilityBar->Update((float)m_spikeAbility->GetCooldown(), SPIKE_COOLDOWN, 4);
	m_abilityBar->Update((float)m_smokeBombAbility->GetCooldown(), SMOKEBOMB_COOLDOWN, 4);
}

void Player::Render()
{
	if (m_isAlive)
	{
		m_healthbar->Render();
		AnimatedObject::Render(m_team);
	}
	m_abilityBar->Render();
}

void Player::RenderDepth()
{
	if (m_isAlive)
	{
		AnimatedObject::RenderDepth();
	}
}

void Player::RenderOutlining()
{
	AnimatedObject::RenderOutlining();
}

void Player::SetIsAlive(bool p_isAlive)
{
	m_isAlive = p_isAlive;
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
	if (m_ability == m_meleeSwing)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Melee);
		Network::GetInstance()->SendAnimationState(AnimationState::Melee);
	}
	else if (m_ability == m_dash)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Special1);
		Network::GetInstance()->SendAnimationState(AnimationState::Special1);
	}
	else if (m_ability == m_megaShuriken)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Special2);
		Network::GetInstance()->SendAnimationState(AnimationState::Special2);
	}
	else if (m_ability == m_smokeBombAbility)
	{
		AnimatedObject::ChangeAnimationState(AnimationState::Tool);
		Network::GetInstance()->SendAnimationState(AnimationState::Tool);
	}
	else if (m_ability == m_shurikenAbility)
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