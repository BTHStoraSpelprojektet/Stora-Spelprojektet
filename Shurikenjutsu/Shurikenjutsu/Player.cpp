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

	m_inputManager = InputManager::GetInstance();

	// Create copy for network
	m_playerNetworkCopy = new PlayerReplica();
	m_playerNetworkCopy->SetPosition(GetPosition().x, GetPosition().y, GetPosition().z);

	return true;
}

void Player::Shutdown()
{
	Network::RemoveReference(m_playerNetworkCopy);
	delete m_playerNetworkCopy;

	MovingObject::Shutdown();
}

void Player::Update(double p_deltaTime)
{
	if (Network::ConnectedNow())
	{
		Network::AddReference(m_playerNetworkCopy);
	}
	float x, y, z;
	x = 0;
	y = 0;
	z = 0;
	if (m_inputManager->IsKeyPressed(VkKeyScan('w')))
	{
		SetSpeed(5.0f);
		z += 1;
	}

	if (m_inputManager->IsKeyPressed(VkKeyScan('a')))
	{
		SetSpeed(5.0f);
		x += -1;
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('s')))
	{
		SetSpeed(5.0f);
		z += -1;
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('d')))
	{
		SetSpeed(5.0f);
		x += 1;
	}

	DirectX::XMVECTOR tempVector = DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(x, y, z));
	tempVector = DirectX::XMVector3Normalize(tempVector);
	DirectX::XMFLOAT3 tempFloat;
	DirectX::XMStoreFloat3(&tempFloat, tempVector);
	SetDirection(tempFloat);
	SetPosition(DirectX::XMFLOAT3(m_position.x + m_direction.x * m_speed * (float)p_deltaTime, m_position.y + m_direction.y * m_speed * (float)p_deltaTime, m_position.z + m_direction.z * m_speed * (float)p_deltaTime));
	m_model.UpdateWorldMatrix(m_position, m_scale, m_rotation);
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

void Player::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	Object::SetPosition(p_pos);

	if (Network::IsConnected())
	{
		DirectX::XMFLOAT3 pos = GetPosition();
		m_playerNetworkCopy->SetPosition(pos.x, pos.y, pos.z);
	}
}