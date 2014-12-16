#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, float p_speed, float p_damage, int p_spells, int p_health, int p_maxHealth, float p_agility)
{
	if (!MovingObject::Initialize(p_filepath, p_pos, p_direction, p_speed))
	{
		return false;
	}

	SetDamage(p_damage);
	m_spells = p_spells;
	SetHealth(p_health);
	SetMaxHealth(p_maxHealth);
	SetAgility(p_agility);
	SetAttackDirection(DirectX::XMFLOAT3(0, 0, 0));
	m_playerSphere = Sphere(0.0f,0.0f,0.0f,0.5f);
	m_inputManager = InputManager::GetInstance();
	m_ability = new Ability();
	m_noAbility = new Ability();
	m_dash = new Dash();
	m_meleeSwing = new MeleeSwing();
	m_shurikenAbility = new ShurikenAbility();
	m_isAlive = true;

	m_healthbar.Initialize(50.0f, 5.0f);

	return true;
}

void Player::Shutdown()
{
	MovingObject::Shutdown();
}

void Player::UpdateMe()
{
	// Check health and isAlive from server
	if (Network::GetInstance()->IsConnected())
	{
		SetHealth(Network::GetInstance()->GetMyPlayer().currentHP);
		SetMaxHealth(Network::GetInstance()->GetMyPlayer().maxHP);
		SetIsAlive(Network::GetInstance()->GetMyPlayer().isAlive);
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

	
	m_ability = m_noAbility;
	CheckForSpecialAttack();


	// Melee attack
	if (InputManager::GetInstance()->IsLeftMouseClicked())
	{
		m_ability = m_meleeSwing;
	}

	// Cast shuriken
	if (InputManager::GetInstance()->IsRightMouseClicked())
	{
		m_ability = m_shurikenAbility;
	}
	
	m_ability->Execute();
}

void Player::CheckForSpecialAttack()
{
	DirectX::XMFLOAT3 rayDirection = DirectX::XMFLOAT3(m_attackDir.x, 0.1f, m_attackDir.z);
	if (m_dashCd > 0)
	{
		m_dashCd -= (float)GLOBAL::GetInstance().GetDeltaTime();
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('v')))
	{
		if (m_dashCd <= 0)
		{
			m_dashCd = 0.5f;
			m_ability = m_dash;
		}
	}
	//if (m_inputManager->IsKeyPressed(VkKeyScan('e')))
	//{
	//	std::cout << "" << std::endl;
	//}
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

	return moved;
}

void Player::Update()
{

}

void Player::SetDamage(float p_damage)
{
	m_damage = p_damage;
}

float Player::GetDamage() const
{
	return m_damage;
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

void Player::SetAgility(float p_agility)
{
	m_agility = p_agility;
}

float Player::GetAgility() const
{
	return m_agility;
}

void Player::SendPosition(DirectX::XMFLOAT3 p_pos)
{
		MovingObject::SetPosition(p_pos);

		if (Network::GetInstance()->IsConnected())
	{
		DirectX::XMFLOAT3 pos = GetPosition();
		Network::GetInstance()->SendPlayerPos(pos.x, pos.y, pos.z);
	}
}

void Player::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	Object::SetPosition(p_pos);
}

DirectX::XMFLOAT3 Player::GetFacingDirection()
{
	return Object::GetRotation();
}

void Player::SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection)
{
	Object::SetRotation(p_facingDirection);
}

DirectX::XMFLOAT3 Player::GetAttackDirection()
{
	return m_attackDir;
}

void Player::SetMyAttackDirection(DirectX::XMFLOAT3 p_attackDir)
{
	m_attackDir = p_attackDir;
	CalculateFacingAngle();

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
	std::vector<OBB> collidingBoxes = CollisionManager::GetInstance()->CalculateLocalPlayerCollisionWithStaticObjects(m_playerSphere, m_speed, m_direction);
	for (unsigned int i = 0; i < collidingBoxes.size(); i++)
	{
		bool rightOfBox = m_position.x >(collidingBoxes[i].m_center.x + collidingBoxes[i].m_extents.x);
		bool leftOfBox = m_position.x < (collidingBoxes[i].m_center.x - collidingBoxes[i].m_extents.x);
		bool aboveBox = m_position.z >(collidingBoxes[i].m_center.z + collidingBoxes[i].m_extents.z);
		bool belowBox = m_position.z < (collidingBoxes[i].m_center.z - collidingBoxes[i].m_extents.z);
		float x = m_direction.x;
		float z = m_direction.z;
		if (x == 1 || x == -1)
		{
			x = 0;
		}
		else if (z == 1 || z == -1)
		{
			z = 0;
		}
		else if (x < 0 && z < 0)//down left
		{
			if (rightOfBox == aboveBox)
			{
				SetPosition(DirectX::XMFLOAT3(m_position.x, m_position.y, collidingBoxes[i].m_center.z + collidingBoxes[i].m_extents.z + m_playerSphere.m_radius*1.1f));

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
				SetPosition(DirectX::XMFLOAT3(m_position.x , m_position.y, collidingBoxes[i].m_center.z + collidingBoxes[i].m_extents.z + m_playerSphere.m_radius*1.1f));
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
				SetPosition(DirectX::XMFLOAT3(collidingBoxes[i].m_center.x + collidingBoxes[i].m_extents.x + m_playerSphere.m_radius*1.1f, m_position.y, m_position.z));
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
				SetPosition(DirectX::XMFLOAT3(m_position.x, m_position.y, collidingBoxes[i].m_center.z - collidingBoxes[i].m_extents.z - m_playerSphere.m_radius*1.1f));

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
	float speed_X_Delta = (float)GLOBAL::GetInstance().GetDeltaTime() * m_speed;
	SendPosition(DirectX::XMFLOAT3(m_position.x + m_direction.x * speed_X_Delta, m_position.y + m_direction.y * speed_X_Delta, m_position.z + m_direction.z * speed_X_Delta));
}

void Player::UpdateHealthBar(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	m_healthbar.Update(m_position, m_health, m_maxHealth, p_view, p_projection);
}

void Player::Render(SHADERTYPE p_shader)
{
	if (m_isAlive)
	{
		MovingObject::Render(p_shader);
		m_healthbar.Render();
	}
}

void Player::SetIsAlive(bool p_isAlive)
{
	m_isAlive = p_isAlive;
}