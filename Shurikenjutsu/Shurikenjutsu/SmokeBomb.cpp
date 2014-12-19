#include "SmokeBomb.h"


bool SmokeBomb::Initialize(DirectX::XMFLOAT3 p_position, unsigned int p_smokeBombID)
{
	m_particles.Initialize(GraphicsEngine::GetDevice(), DirectX::XMFLOAT3(p_position.x, SMOKEBOMB_POSITION_Y, p_position.z),
		DirectX::XMFLOAT3(SMOKEBOMB_DIRECTION_X, SMOKEBOMB_DIRECTION_Y, SMOKEBOMB_DIRECTION_Z),
		DirectX::XMFLOAT2(SMOKEBOMB_SIZE_X, SMOKEBOMB_SIZE_Y), PARTICLE_PATTERN_SMOKE);


	m_SmokeSphere = Sphere(p_position, SMOKEBOMB_SIZE_X);
	m_smokeBombId = p_smokeBombID;
	m_timer = 10;
	return true;
}
void SmokeBomb::Update()
{
	m_timer += GLOBAL::GetInstance().GetDeltaTime();
	m_particles.Update();
	if (m_timer < SMOKEBOMB_DURATION)
	{
		m_particles.SetEmitParticleState(true);
	}
	else
	{
		m_particles.SetEmitParticleState(false);
	}
}
void SmokeBomb::Shutdown()
{
	m_particles.Shutdown();
}
void SmokeBomb::Render()
{
	m_particles.Render();
}
void SmokeBomb::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_SmokeSphere.m_position = p_position;
	m_particles.SetPosition(DirectX::XMFLOAT3(p_position.x, SMOKEBOMB_POSITION_Y, p_position.z));
}
void SmokeBomb::ResetTimer()
{
	m_timer = 0;
}
bool SmokeBomb::GetIfActive()
{
	if (m_timer < SMOKEBOMB_DURATION)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Sphere SmokeBomb::GetSmokeSphere()
{
	return m_SmokeSphere;
}

unsigned int SmokeBomb::GetID()
{
	return m_smokeBombId;
}