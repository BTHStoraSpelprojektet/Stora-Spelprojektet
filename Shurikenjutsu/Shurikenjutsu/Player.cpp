#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

bool Player::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	if (!MovingObject::Initialize(p_filepath, p_pos, p_direction, p_speed))
	{
		return false;
	}
	SetDamage(p_damage);
	m_spells = p_spells;
	SetHealth(p_health);
	SetAgility(p_agility);
	SetAttackDirection(DirectX::XMFLOAT3(0, 0, 0));

	m_inputManager = InputManager::GetInstance();

	return true;
}

void Player::Shutdown()
{
	MovingObject::Shutdown();
}

void Player::UpdateMe(double p_deltaTime)
{
	// Move
	bool moved = false;
	float x, y, z;

	x = 0;
	y = 0;
	z = 0;
	Box charBox = Box(m_position, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	bool up =		Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(0.0f, 0.0f, 31.0f), DirectX::XMFLOAT3(40.0f, 1.0f, 1.0f)));
	bool down =		Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(0.0f, 0.0f, -39.0f), DirectX::XMFLOAT3(40.0f, 1.0f, 1.0f)));
	bool left =		Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(-31.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(1.0f, 1.0f, 40.0f)));
	bool right =	Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(39.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(1.0f, 1.0f, 40.0f)));
	if (m_inputManager->IsKeyPressed(VkKeyScan('w')))
	{
		if (!up)
		{ 
		SetSpeed(5.0f);
		z += 1;
		moved = true;
		}
	}

	if (m_inputManager->IsKeyPressed(VkKeyScan('a')))
	{
		if (!left)
		{
		SetSpeed(5.0f);
		x += -1;
		moved = true;
		}
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('s')))
	{
		if (!down)
		{
		SetSpeed(5.0f);
		z += -1;
		moved = true;
		}
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('d')))
	{
		if (!right)
		{
		SetSpeed(5.0f);
		x += 1;
		moved = true;
		}
	}

	DirectX::XMVECTOR tempVector = DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(x, y, z));
	tempVector = DirectX::XMVector3Normalize(tempVector);
	DirectX::XMFLOAT3 tempFloat;
	DirectX::XMStoreFloat3(&tempFloat, tempVector);
	SetDirection(tempFloat);
	if (moved || Network::ConnectedNow())
	{
		SendPosition(DirectX::XMFLOAT3(m_position.x + m_direction.x * m_speed * (float)p_deltaTime, m_position.y + m_direction.y * m_speed * (float)p_deltaTime, m_position.z + m_direction.z * m_speed * (float)p_deltaTime));
	}

	// Melee attack
	if (InputManager::GetInstance()->IsLeftMouseClicked())
	{
		Network::DoMeleeAttack();
	}

	// Cast shuriken
	if (InputManager::GetInstance()->IsRightMouseClicked())
	{
		Network::AddShurikens(GetPosition().x, 1.0f, GetPosition().z, GetAttackDirection().x, GetAttackDirection().y, GetAttackDirection().z);
	}
}

void Player::Update(double p_deltaTime)
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

void Player::SetHealth(unsigned int p_health)
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

unsigned int Player::GetHealth() const
{
	return m_health;
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

	if (Network::IsConnected())
	{
		DirectX::XMFLOAT3 pos = GetPosition();
		Network::SendPlayerPos(p_pos.x, p_pos.y, p_pos.z);
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

	if (Network::IsConnected())
	{
		DirectX::XMFLOAT3 dir = GetAttackDirection();
		Network::SendPlayerDir(dir.x, dir.y, dir.z);
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