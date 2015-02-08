#include "StickyTrap.h"
#include "Object.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "GraphicsEngine.h"
#include "PlayerManager.h"

bool StickyTrap::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_smokeBombID)
{
	m_stickyTrapBag = new Object();
	m_stickyTrapBag->Initialize("../Shurikenjutsu/Models/CaltropBagShape.SSP", p_startPosition);

	m_stickyTrap = new Object();
	m_stickyTrap->Initialize("../Shurikenjutsu/Models/CaltropFieldTCShape.SSP", p_endPosition);

	m_startPosition = p_startPosition;
	m_isThrowing = true;
	m_sStickyTrapSphere = Sphere(p_endPosition, SPIKE_SIZE_X);
	m_StickyTrapID = p_smokeBombID;

	m_speed = SPIKE_SPEED;
	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	float length = sqrtf(x*x + z*z);
	m_percentX = x / length;
	m_percentZ = z / length;
	m_angle = asinf((9.82f * length) / (m_speed * m_speed)) * 0.5f;

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
	
}
void StickyTrap::Shutdown()
{
	m_stickyTrapBag->Shutdown();
	delete m_stickyTrapBag;
	m_stickyTrap->Shutdown();
	delete m_stickyTrap;
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
	}
}
void StickyTrap::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_sStickyTrapSphere.m_position = p_position;
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
		return m_sStickyTrapSphere;
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