#ifndef STICKYTRAP_H
#define STICKYTRAP_H

#include "Structures.h"
#include "../CommonLibs/RakNet/RakNetTypes.h"
class Object;

class StickyTrap
{
public:
	bool Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_stickyTrapID, RakNet::RakNetGUID p_guid);
	void Update();
	void Shutdown();
	void Render();

	void SetPosition(DirectX::XMFLOAT3 p_position);
	void ResetTimer();
	bool GetIsAlive();
	Sphere GetStickyTrapSphere();
	unsigned int GetID();
	Object* GetStickyBag();
	RakNet::RakNetGUID GetGUID();
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

	Sphere m_stickyTrapSphere;
	unsigned int m_StickyTrapID;
	float m_decreasePercentage;
	RakNet::RakNetGUID m_guid;
};

#endif