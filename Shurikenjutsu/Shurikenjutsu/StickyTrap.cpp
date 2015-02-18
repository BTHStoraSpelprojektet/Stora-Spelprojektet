#include "StickyTrap.h"
#include "Object.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "GraphicsEngine.h"
#include "PlayerManager.h"
#include "ParticleEmitter.h"

bool StickyTrap::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_stickyTrapID, RakNet::RakNetGUID p_guid)
{
	m_stickyTrapBag = new Object();
	m_stickyTrapBag->Initialize("../Shurikenjutsu/Models/StickyTrapJar.SSP", p_startPosition);

	m_stickyTrap = new Object();
	int randomModel = std::rand() % 4 + 1;
	if (randomModel == 1)
	{
		m_stickyTrap->Initialize("../Shurikenjutsu/Models/StickyTrap1Shape.SSP", p_endPosition);
	}
	else if (randomModel == 2)
	{
		m_stickyTrap->Initialize("../Shurikenjutsu/Models/StickyTrap2Shape.SSP", p_endPosition);
	}
	else 
	{
		m_stickyTrap->Initialize("../Shurikenjutsu/Models/StickyTrap3Shape.SSP", p_endPosition);
	}

	int randomY = std::rand() % 8;
	m_stickyTrap->SetRotation(DirectX::XMFLOAT3(0.0f,(float)randomY,0.0f));

	m_startPosition = p_startPosition;
	m_isThrowing = true;
	m_stickyTrapSphere = Sphere(p_endPosition, STICKY_TRAP_RADIUS);
	m_StickyTrapID = p_stickyTrapID;

	m_speed = STICKY_TRAP_SPEED;
	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	float length = sqrtf(x*x + z*z);
	m_percentX = x / length;
	m_percentZ = z / length;
	m_angle = asinf((9.82f * length) / (m_speed * m_speed)) * 0.5f;

	m_guid = p_guid;

	m_stickyParticles = new ParticleEmitter();
	m_stickyParticles->Initialize(GraphicsEngine::GetInstance()->GetDevice(), p_endPosition, DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(0.2f, 0.2f), PARTICLE_PATTERN_BUBBLES);
	m_stickyParticles->SetEmitParticleState(true);
	return true;
}
void StickyTrap::Update()
{
	m_timer += (float)GLOBAL::GetInstance().GetDeltaTime();

	if (m_isThrowing)
	{
		float x = m_speed * m_timer * cosf(m_angle) * m_percentX;
		float y = m_speed * m_timer * sinf(m_angle) - 0.5f * 9.82f * m_timer * m_timer;
		float z = m_speed * m_timer * cosf(m_angle) * m_percentZ;

		m_stickyTrapBag->SetPosition(DirectX::XMFLOAT3(m_startPosition.x + x, m_startPosition.y + 10 * y, m_startPosition.z + z));

		if (y < 0.0f)
		{
			ResetTimer();
			m_isThrowing = false;
		}
	}
	m_stickyParticles->Update();
	
}
void StickyTrap::Shutdown()
{
	if (m_stickyParticles != nullptr)
	{
		m_stickyParticles->Shutdown();
		delete m_stickyParticles;
		m_stickyParticles = nullptr;
	}

	if (m_stickyTrapBag != nullptr)
	{
		m_stickyTrapBag->Shutdown();
		delete m_stickyTrapBag;
		m_stickyTrapBag = nullptr;
	}

	if (m_stickyTrap != nullptr)
	{
		m_stickyTrap->Shutdown();
		delete m_stickyTrap;
		m_stickyTrap = nullptr;
	}
}
void StickyTrap::Render()
{
	if (m_isThrowing)
	{
		m_stickyTrapBag->Render();
	}
	else
	{
		m_stickyTrap->Render();
		m_stickyParticles->Render();
	}
}
void StickyTrap::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_stickyTrapSphere.m_position = p_position;
}

void StickyTrap::ResetTimer()
{
	m_timer = 0;
}

Sphere StickyTrap::GetStickyTrapSphere()
{
	if (m_isThrowing)
	{
		return m_stickyTrapBag->GetFrustumSphere();
	}
	else
	{
		return m_stickyTrapSphere;
	}
}

unsigned int StickyTrap::GetID()
{
	return m_StickyTrapID;
}

Object* StickyTrap::GetStickyBag()
{
	if (m_isThrowing)
	{
		return m_stickyTrapBag;
	}
	else
	{
		return NULL;
	}

}

bool StickyTrap::GetIsAlive()
{
	if (m_timer < STICKY_TRAP_DURATION)
	{
		return true;
	}
	else
	{
		return false;
	}
}

RakNet::RakNetGUID StickyTrap::GetGUID()
{
	return m_guid;
}