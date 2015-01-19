#ifndef SMOKEBOMB_H
#define SMOKEBOMB_H
#include "ParticleEmitter.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "GraphicsEngine.h"
#include "Globals.h"

class SmokeBomb
{
public:
	bool Initialize(DirectX::XMFLOAT3 p_position, unsigned int p_smokeBombID);
	void Update();
	void Shutdown();
	void Render();

	void SetPosition(DirectX::XMFLOAT3 p_position);
	void ResetTimer();
	bool GetIfActive();
	Sphere GetSmokeSphere();
	unsigned int GetID();


private:
	bool m_isThrowing;
	Sphere m_SmokeSphere;
	ParticleEmitter m_particles;
	float m_timer;
	unsigned int m_smokeBombId;
};

#endif