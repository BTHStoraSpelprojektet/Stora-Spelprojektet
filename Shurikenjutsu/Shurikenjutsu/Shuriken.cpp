#include "Shuriken.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"


Shuriken::Shuriken(){}
Shuriken::~Shuriken(){}

bool Shuriken::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, unsigned int p_shurikenID)
{
	if (MovingObject::Initialize(p_filepath, p_pos, p_dir, SHURIKEN_SPEED))
	{
		SetLifetime(SHURIKEN_DURATION);
	}
	else
	{
		return false;
	}

	m_shurikenID = p_shurikenID;

	return true;
}

void Shuriken::Shutdown()
{
	MovingObject::Shutdown();
}

void Shuriken::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	// Update position
	m_position.x += (float)(m_direction.x*m_speed*deltaTime);
	m_position.y += (float)(m_direction.y*m_speed*deltaTime);
	m_position.z += (float)(m_direction.z*m_speed*deltaTime);

	m_rotation.y += (float)(SHURIKEN_ROTATION_SPEED*deltaTime);

	// Update lifetime
	SetLifetime((float)(GetLifetime() - deltaTime));

}

void Shuriken::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	MovingObject::SetPosition(p_pos);
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

unsigned int Shuriken::GetID()
{
	return m_shurikenID;
}