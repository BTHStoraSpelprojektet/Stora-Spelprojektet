#ifndef STICKYTRAP_H
#define STICKYTRAP_H

#include "Structures.h"
class Object;

class StickyTrap
{
public:
	bool Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_stickyTrapID);
	void Update();
	void Shutdown();
	void Render();

	void SetPosition(DirectX::XMFLOAT3 p_position);
	void ResetTimer();
	bool GetIsAlive();
	Sphere GetStickyTrapSphere();
	unsigned int GetID();
	Object* GetStickyBag();
private:
	bool m_isThrowing;
	bool m_hasInflictedDamage;

	Object* m_stickyTrapBag;
	Object* m_stickyTrap;
	DirectX::XMFLOAT3 m_startPosition;
	float m_speed;
	float m_angle;
	float m_percentX;
	float m_percentZ;
	float m_timer;

	Sphere m_sStickyTrapSphere;
	unsigned int m_StickyTrapID;
	float m_decreasePercentage;
};

#endif