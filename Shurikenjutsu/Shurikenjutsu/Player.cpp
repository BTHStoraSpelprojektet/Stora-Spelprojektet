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
	if (!Object::Initialize(p_device, p_filepath, p_pos))
	{
		return false;
	}
	SetDirection(p_direction);
	SetSpeed(p_speed);
	SetDamage(p_damage);
	m_spells = p_spells;
	SetHealth(p_health);
	SetAgility(p_agility);

	return true;
}

void Player::Shutdown()
{
	Object::Shutdown();
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