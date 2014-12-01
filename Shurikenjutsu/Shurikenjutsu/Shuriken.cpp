#include "Shuriken.h"


Shuriken::Shuriken(){}

Shuriken::~Shuriken(){}

bool Shuriken::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id)
{
	if (MovingObject::Initialize(p_filepath, p_pos, p_dir, p_speed))
	{
		SetLifetime(2.0f);
		SetDamage(10);

		return true;
	}

	m_shurikenID = p_id;

	// Replica3Manager code, unused for now.
	/*m_shurikenReplica = new ShurikenReplica();
	m_shurikenReplica->SetPosition(GetPosition().x, GetPosition().y, GetPosition().z);
	*/

	// Replica3Manager code, unused for now.
	/*if (Network::ConnectedNow())
	{
		Network::AddReference(m_shurikenReplica);
	}*/

	// Create ID for the network on the object

	return false;
}

void Shuriken::Shutdown()
{
	/*Network::RemoveReference(m_shurikenReplica);
	delete m_shurikenReplica;
	*/

	MovingObject::Shutdown();
}

void Shuriken::Update(double p_deltaTime)
{
	// Update position
	m_position.x += (float)(m_direction.x*m_speed*p_deltaTime);
	m_position.y += (float)(m_direction.y*m_speed*p_deltaTime);
	m_position.z += (float)(m_direction.z*m_speed*p_deltaTime);

	m_rotation.y += (float)(ShurikenSpeed*p_deltaTime);

	// Update lifetime
	SetLifetime((float)(GetLifetime() - p_deltaTime));

	// Update World Matrix
	m_model.UpdateWorldMatrix(m_position, m_scale, m_rotation);
}

void Shuriken::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	MovingObject::SetPosition(p_pos);

	if (Network::IsConnected())
	{ 
		// Replica3Manager code, unused for now.
		/*DirectX::XMFLOAT3 pos = GetPosition();
		m_shurikenReplica->SetPosition(pos.x, pos.y, pos.z);
		*/
	}
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

bool Shuriken::IsDead()
{
	return (m_lifetime <= 0);
}

void Shuriken::AddNetworkShuriken(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_id)
{
	Network::AddShurikens( p_x,  p_y,  p_z,  p_dirX,  p_dirY,  p_dirZ, p_id);
}