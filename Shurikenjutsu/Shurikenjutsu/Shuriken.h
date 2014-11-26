#ifndef SHURIKEN_H_
#define SHURIKEN_H_
#include "MovingObject.h"

const float ShurikenSpeed = 15.70f;

class Shuriken : public MovingObject
{
public:
	Shuriken();
	~Shuriken();

	bool Initialize(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed);
	void Shutdown();

	void Update(double p_deltaTime);

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
};
#endif