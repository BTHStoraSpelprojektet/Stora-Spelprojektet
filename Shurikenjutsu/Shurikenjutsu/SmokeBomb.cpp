#include "SmokeBomb.h"

bool SmokeBomb::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_smokeBombID)
{
	m_bomb.Initialize("../Shurikenjutsu/Models/SmokeBomb.SSP", p_startPosition);

	m_particles.Initialize(GraphicsEngine::GetDevice(), DirectX::XMFLOAT3(p_endPosition.x, SMOKEBOMB_POSITION_Y, p_endPosition.z),
		DirectX::XMFLOAT3(SMOKEBOMB_DIRECTION_X, SMOKEBOMB_DIRECTION_Y, SMOKEBOMB_DIRECTION_Z),
		DirectX::XMFLOAT2(SMOKEBOMB_SIZE_X, SMOKEBOMB_SIZE_Y), PARTICLE_PATTERN_SMOKE);


	m_startPosition = p_startPosition;
	m_isThrowing = true;
	m_SmokeSphere = Sphere(p_endPosition, SMOKEBOMB_SIZE_X);
	m_smokeBombId = p_smokeBombID;
	m_timer = 0;

	m_speed = SMOKEBOMB_SPEED;
	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	float length = sqrtf(x*x + z*z);
	m_percentX = x / length;
	m_percentZ = z / length;
	m_angle = asinf((9.82f * length) / (m_speed * m_speed)) * 0.5f;
	
	return true;
}

void SmokeBomb::Update()
{
	m_timer += (float)GLOBAL::GetInstance().GetDeltaTime();

	if (m_isThrowing)
	{
		float x = m_speed * m_timer * cosf(m_angle) * m_percentX;
		float y = m_speed * m_timer * sinf(m_angle) - 0.5f * 9.82f * m_timer * m_timer;
		float z = m_speed * m_timer * cosf(m_angle) * m_percentZ;

		m_bomb.SetPosition(DirectX::XMFLOAT3(m_startPosition.x + x, m_startPosition.y + 10 * y, m_startPosition.z + z));

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
	if(m_isThrowing)
	{
		m_bomb.Render();
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
	if (m_isThrowing || m_timer < SMOKEBOMB_DURATION || m_particles.GetParticleCount() > 0)
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
	if (m_isThrowing)
	{
		return m_bomb.GetFrustumSphere();
	}
	else
	{
		return m_SmokeSphere;
	}
}

unsigned int SmokeBomb::GetID()
{
	return m_smokeBombId;
}