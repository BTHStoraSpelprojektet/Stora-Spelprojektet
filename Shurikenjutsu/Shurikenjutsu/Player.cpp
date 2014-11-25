#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

bool Player::Initialize(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	if (!MovingObject::Initialize(p_device, p_filepath, p_pos, p_direction, p_speed))
	{
		return false;
	}
	SetDamage(p_damage);
	m_spells = p_spells;
	SetHealth(p_health);
	SetAgility(p_agility);

	m_inputManager = InputManager::GetInstance();

	return true;
}

void Player::Shutdown()
{
	MovingObject::Shutdown();
}

void Player::Update(double p_deltaTime)
{
	if (m_inputManager->IsKeyPressed(VkKeyScan('w')))
	{
		SetSpeed(5.0f);
		SetDirection(DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));
		std::cout << "W TRYCKT!" << std::endl;
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('a')))
	{
		SetSpeed(5.0f);
		SetDirection(DirectX::XMFLOAT3(-1.0f, 0.0f, 0.0f));
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('s')))
	{
		SetSpeed(5.0f);
		SetDirection(DirectX::XMFLOAT3(0.0f, -1.0f, 0.0f));
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('d')))
	{
		SetSpeed(5.0f);
		SetDirection(DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f));
	}

	SetPosition(DirectX::XMFLOAT3(m_position.x + m_direction.x * m_speed*p_deltaTime, m_position.y + m_direction.y * m_speed*p_deltaTime, m_position.z + m_direction.z * m_speed*p_deltaTime));
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