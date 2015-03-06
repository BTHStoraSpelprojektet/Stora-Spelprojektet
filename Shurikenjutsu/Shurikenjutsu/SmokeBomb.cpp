#include "SmokeBomb.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "GraphicsEngine.h"
#include "Globals.h"
#include "ParticleEmitter.h"
#include "Object.h"
#include "..\CommonLibs\ModelNames.h"
#include "ShadowShapes.h"
#include "..\CommonLibs\ConsoleFunctions.h"

bool SmokeBomb::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_smokeBombID)
{
	m_bomb = new Object();
	m_bomb->Initialize(SMOKE_BOMB, p_startPosition);

	m_particles = new ParticleEmitter();
	m_particles->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(p_endPosition.x, SMOKEBOMB_POSITION_Y, p_endPosition.z),
	DirectX::XMFLOAT3(SMOKEBOMB_DIRECTION_X, SMOKEBOMB_DIRECTION_Y, SMOKEBOMB_DIRECTION_Z),
	DirectX::XMFLOAT2(SMOKEBOMB_SIZE_X, SMOKEBOMB_SIZE_Y), PARTICLE_PATTERN_SMOKE);
	m_particles->SetColor(DirectX::XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f));

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
	
	m_trail = new Trail();
	if (!m_trail->Initialize(50.0f, 0.2f, 0.2f, DirectX::XMFLOAT4(0.83f, 0.86f, 0.06f, 1.0f), "../Shurikenjutsu/2DTextures/Particles/Trail.png"))
	{
		ConsolePrintErrorAndQuit("A smoke bomb trail failed to initialize!");
	}

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

		m_bomb->SetPosition(DirectX::XMFLOAT3(m_startPosition.x + x, m_startPosition.y + 10 * y, m_startPosition.z + z));

		m_trail->Update(m_bomb->GetPosition(), m_angle);

		if (y < 0.0f)
		{
			m_trail->Shutdown();
			delete m_trail;
			m_trail = nullptr;

			ResetTimer();
			m_isThrowing = false;
			
			ShadowShapes::GetInstance().AddSmokeBombShape(Point(m_startPosition.x + x, m_startPosition.z + z));
		}
	}

	else
	{		
		m_particles->Update();

		if (m_timer < SMOKEBOMB_DURATION)
		{
			m_particles->SetEmitParticleState(true);
		}

		else
		{
			m_particles->SetEmitParticleState(false);
		}
	}
}

void SmokeBomb::Shutdown()
{
	if (m_bomb != nullptr)
	{
		m_bomb->Shutdown();
		delete m_bomb;
		m_bomb = nullptr;
	}

	if (m_particles != nullptr)
	{
		m_particles->Shutdown();
		delete m_particles;
		m_particles = nullptr;
	}

	if (m_trail)
	{
		m_trail->Shutdown();
		delete m_trail;
		m_trail = nullptr;
	}
}

void SmokeBomb::Render()
{
	m_bomb->Render();

	if(!m_isThrowing)
	{
		m_particles->Render();
	}

	else
	{
		if (m_trail)
		{
			m_trail->Render();
		}
	}
}

void SmokeBomb::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_SmokeSphere.m_position = p_position;
	m_particles->SetPosition(DirectX::XMFLOAT3(p_position.x, SMOKEBOMB_POSITION_Y, p_position.z));
}

void SmokeBomb::ResetTimer()
{
	m_timer = 0;
}

bool SmokeBomb::GetIfActive()
{
	if (m_isThrowing || m_timer < SMOKEBOMB_DURATION || m_particles->GetParticleCount() > 0)
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
		return m_bomb->GetFrustumSphere();
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

Object* SmokeBomb::GetBomb()
{
	return m_bomb;
}