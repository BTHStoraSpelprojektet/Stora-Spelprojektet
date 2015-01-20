#include "SmokeBomb.h"


bool SmokeBomb::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_smokeBombID)
{
	m_particles.Initialize(GraphicsEngine::GetDevice(), DirectX::XMFLOAT3(p_endPosition.x, SMOKEBOMB_POSITION_Y, p_endPosition.z),
		DirectX::XMFLOAT3(SMOKEBOMB_DIRECTION_X, SMOKEBOMB_DIRECTION_Y, SMOKEBOMB_DIRECTION_Z),
		DirectX::XMFLOAT2(SMOKEBOMB_SIZE_X, SMOKEBOMB_SIZE_Y), PARTICLE_PATTERN_SMOKE);


	m_isThrowing = true;
	m_SmokeSphere = Sphere(p_endPosition, SMOKEBOMB_SIZE_X);
	m_smokeBombId = p_smokeBombID;
	m_timer = 0;

	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	m_percentX = abs(x / (x + z));
	m_percentZ = abs(z / (x + z));
	float length = sqrtf(x*x + z*z);
	float degToRad = 3.14159265359f / 180;
	m_angle = 45 * degToRad;
	m_speed = sqrtf((length * 9.82f) / (sinf(2 * m_angle)));

	return true;
}
void SmokeBomb::Update()
{
	m_timer += (float)GLOBAL::GetInstance().GetDeltaTime();

	if (m_isThrowing)
	{
		float x = m_speed * m_timer * cosf(m_angle) * m_percentX;
		float y = m_speed * m_timer * sinf(m_angle) - 0.5f * 9.82 * m_timer * m_timer;
		float z = m_speed * m_timer * cosf(m_angle) * m_percentZ;

		if (y < 0.0f)
		{
			ResetTimer();
			m_isThrowing = false;
		}
	}
	else
	{		
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
}
void SmokeBomb::Shutdown()
{
	m_particles.Shutdown();
}
void SmokeBomb::Render()
{
	if (m_isThrowing)
	{
	}
	else
	{
		m_particles.Render();
	}
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
	if (m_isThrowing || m_timer < SMOKEBOMB_DURATION)
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