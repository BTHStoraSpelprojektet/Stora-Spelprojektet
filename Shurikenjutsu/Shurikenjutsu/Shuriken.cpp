#include "Shuriken.h"


Shuriken::Shuriken(){}

Shuriken::~Shuriken(){}

bool Shuriken::Initialize(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	if (MovingObject::Initialize(p_device, p_filepath, p_pos, p_dir, p_speed))
	{
		SetLifetime(5.0f);
		SetDamage(0);

		return true;
	}

	return false;
}

void Shuriken::Shutdown()
{
	MovingObject::Shutdown();
}

void Shuriken::Update(double p_deltaTime)
{
	// Update position
	DirectX::XMFLOAT3 tempPosition = GetPosition();
	DirectX::XMFLOAT3 tempDirection = GetDirection();

	tempPosition.x += (float)(tempDirection.x*p_deltaTime);
	tempPosition.y += (float)(tempDirection.y*p_deltaTime);
	tempPosition.z += (float)(tempDirection.z*p_deltaTime);

	SetPosition(tempPosition);

	// Update lifetime
	SetLifetime((float)(GetLifetime() - p_deltaTime));
}

void Shuriken::SetLifetime(float p_lifetime)
{
	m_lifetime = p_lifetime;
}

float Shuriken::GetLifetime() const
{
	return m_lifetime;
}

void Shuriken::SetDamage(int p_damage)
{
	m_damage = p_damage;
}

int Shuriken::GetDamage() const
{
	return m_damage;
}