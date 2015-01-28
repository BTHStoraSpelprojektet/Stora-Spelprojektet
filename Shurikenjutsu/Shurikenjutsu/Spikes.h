#ifndef SPIKES_H
#define SPIKES_H

#include "Structures.h"
class Object;

class Spikes
{
public:
	bool Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_smokeBombID);
	void Update();
	void Shutdown();
	void Render();

	void SetPosition(DirectX::XMFLOAT3 p_position);
	void ResetTimer();
	bool GetIsAlive();
	Sphere GetSpikeSphere();
	unsigned int GetID();
	Object* GetSpikes();

private:
	bool m_isThrowing;
	bool m_hasInflictedDamage;

	Object* m_spikes;
	Object* m_spikesTrap;
	DirectX::XMFLOAT3 m_startPosition;
	float m_speed;
	float m_angle;
	float m_percentX;
	float m_percentZ;
	float m_timer;

	Sphere m_spikeSphere;
	unsigned int m_spikeId;
	float m_damage;
};


#endif