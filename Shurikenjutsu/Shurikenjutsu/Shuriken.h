#ifndef SHURIKEN_H_
#define SHURIKEN_H_
#include "MovingObject.h"
#include "Network.h"


const float ShurikenSpeed = 15.70f;

class Shuriken : public MovingObject, public RakNet::NetworkIDObject
{
public:
	Shuriken();
	~Shuriken();

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed);
	void Shutdown();

	void Update(double p_deltaTime);

	void SetPosition(DirectX::XMFLOAT3 p_pos);

	void SetRotation(float p_angle);
	float GetRotation() const;

	void SetLifetime(float p_lifetime);
	float GetLifetime() const;

	void SetDamage(int p_damage);
	int GetDamage() const;

	bool IsDead();

private:
	float m_lifetime;
	int m_damage;
	RakNet::NetworkID m_networkID;

	// Replica3 unused
	//ShurikenReplica* m_shurikenReplica;
	
};
#endif