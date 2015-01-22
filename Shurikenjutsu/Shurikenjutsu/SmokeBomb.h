#ifndef SMOKEBOMB_H
#define SMOKEBOMB_H

#include "Object.h"
#include "ParticleEmitter.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "GraphicsEngine.h"
#include "Globals.h"

class SmokeBomb
{
public:
	bool Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_smokeBombID);
	void Update();
	void Shutdown();
	void Render();

	void SetPosition(DirectX::XMFLOAT3 p_position);
	void ResetTimer();
	bool GetIfActive();
	Sphere GetSmokeSphere();
	unsigned int GetID();
	Object GetBomb();


private:
	bool m_isThrowing;

	Object m_bomb;
	DirectX::XMFLOAT3 m_startPosition;
	float m_speed;
	float m_angle;
	float m_percentX;
	float m_percentZ;

	Sphere m_SmokeSphere;
	ParticleEmitter m_particles;
	float m_timer;
	unsigned int m_smokeBombId;
};

#endif