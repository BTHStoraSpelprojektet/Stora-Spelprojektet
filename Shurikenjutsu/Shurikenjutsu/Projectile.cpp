#include "Projectile.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "../CommonLibs/ModelNames.h"
#include "Globals.h"

Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}

bool Projectile::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, unsigned int p_projID, int p_projType, RakNet::RakNetGUID p_guid)
{
	const char* filepath = "";
	switch (p_projType)
	{
	case 0:
		m_projSpeed = SHURIKEN_SPEED;
		m_projDuration = SHURIKEN_DURATION;
		m_projRotationSpeed = SHURIKEN_ROTATION_SPEED;
		filepath = SHURIKEN_MODEL_NAME;
		break;
	case 1:
		m_projSpeed = MEGASHURIKEN_SPEED;
		m_projDuration = MEGASHURIKEN_DURATION;
		m_projRotationSpeed = 0;//MEGASHURIKEN_ROTATION_SPEED;
		filepath = MEGA_SHURIKEN_MODEL_NAME;
		break;
	case 2:
		m_projSpeed = KUNAI_SPEED;
		m_projDuration = KUNAI_DURATION;
		m_projRotationSpeed = KUNAI_ROTATION_SPEED; 
		filepath = KUNAI_MODEL_NAME;
		break;
	default:
		break;
	}

	if (MovingObject::Initialize(filepath, p_pos, p_dir, m_projSpeed))
	{
		SetLifetime(m_projDuration);
	}
	else
	{
		return false;
	}

	m_projId = p_projID;
	m_guid = p_guid;

	return true;
}

void Projectile::Shutdown()
{
	MovingObject::Shutdown();
}

void Projectile::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	// Update position
	m_position.x += (float)(m_direction.x*m_speed*deltaTime);
	m_position.y += (float)(m_direction.y*m_speed*deltaTime);
	m_position.z += (float)(m_direction.z*m_speed*deltaTime);

	m_rotation.y += (float)(m_projRotationSpeed*deltaTime);

	// Update lifetime
	SetLifetime((float)(GetLifetime() - deltaTime));

}

void Projectile::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	MovingObject::SetPosition(p_pos);
}

void Projectile::SetLifetime(float p_lifetime)
{
	m_lifetime = p_lifetime;
}

float Projectile::GetLifetime() const
{
	return m_lifetime;
}

void Projectile::SetDamage(int p_damage)
{
	m_damage = p_damage;
}

int Projectile::GetDamage() const
{
	return m_damage;
}

unsigned int Projectile::GetID()
{
	return m_projId;
}

RakNet::RakNetGUID Projectile::GetGUID()
{
	return m_guid;
}