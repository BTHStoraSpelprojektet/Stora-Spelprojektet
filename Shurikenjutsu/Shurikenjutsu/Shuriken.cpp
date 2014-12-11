#include "Shuriken.h"


Shuriken::Shuriken(){}

Shuriken::~Shuriken(){}

bool Shuriken::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_shurikenID)
{
	if (MovingObject::Initialize(p_filepath, p_pos, p_dir, p_speed))
	{
		SetLifetime(2.0f);
		SetDamage(10);
	}
	else
	{
		return false;
	}

	m_shurikenID = p_shurikenID;

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

	return true;
}

void Shuriken::Shutdown()
{
	/*Network::RemoveReference(m_shurikenReplica);
	delete m_shurikenReplica;
	*/

	MovingObject::Shutdown();
}

void Shuriken::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	// Update position
	m_position.x += (float)(m_direction.x*m_speed*deltaTime);
	m_position.y += (float)(m_direction.y*m_speed*deltaTime);
	m_position.z += (float)(m_direction.z*m_speed*deltaTime);

	m_rotation.y += (float)(ShurikenSpeed*deltaTime);

	// Update lifetime
	SetLifetime((float)(GetLifetime() - deltaTime));

	// Update World Matrix
}

void Shuriken::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	MovingObject::SetPosition(p_pos);

	if (Network::GetInstance()->IsConnected())
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

unsigned int Shuriken::GetID()
{
	return m_shurikenID;
}