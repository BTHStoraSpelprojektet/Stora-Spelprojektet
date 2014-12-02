#ifndef SHURIKEN_H_
#define SHURIKEN_H_

#define WIN32_LEAN_AND_MEAN
#include "MovingObject.h"



const float ShurikenSpeed = 15.70f;

class Shuriken : public MovingObject
{
public:
	Shuriken();
	~Shuriken();

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_shurikenID);
	void Shutdown();

	void Update(double p_deltaTime);

	void SetPosition(DirectX::XMFLOAT3 p_pos);

	void SetRotation(float p_angle);
	float GetRotation() const;

	void SetLifetime(float p_lifetime);
	float GetLifetime() const;

	void SetDamage(int p_damage);
	int GetDamage() const;

	unsigned int GetID();
private:
	float m_lifetime;
	int m_damage;
	unsigned int m_shurikenID;
	// Replica3 unused
	//ShurikenReplica* m_shurikenReplica;
	
};
#endif SHURIKEN_H_