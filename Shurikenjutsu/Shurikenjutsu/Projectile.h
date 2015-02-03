#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "MovingObject.h"
#include "../CommonLibs/RakNet/RakNetTypes.h"

class Projectile :
	public MovingObject
{
public:
	Projectile();
	~Projectile();

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, unsigned int p_projId, int p_projType, RakNet::RakNetGUID p_guid);
	void Shutdown();

	void Update();

	void SetPosition(DirectX::XMFLOAT3 p_pos);

	void SetRotation(float p_angle);
	float GetRotation() const;

	void SetLifetime(float p_lifetime);
	float GetLifetime() const;

	void SetDamage(int p_damage);
	int GetDamage() const;

	unsigned int GetID();
	RakNet::RakNetGUID GetGUID();

private:
	float m_lifetime;
	int m_damage;
	unsigned int m_projId;
	float m_projSpeed;
	float m_projDuration;
	float m_projRotationSpeed;

	RakNet::RakNetGUID m_guid;
};

#endif // !PROJECTILE_H_