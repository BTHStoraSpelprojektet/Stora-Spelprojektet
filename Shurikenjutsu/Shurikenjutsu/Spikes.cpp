#include "Spikes.h"
#include "Object.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "GraphicsEngine.h"
#include "Network.h"

bool Spikes::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, unsigned int p_smokeBombID)
{
	m_spikeBag = new Object();
	m_spikeBag->Initialize("../Shurikenjutsu/Models/CaltropBagShape.SSP", p_startPosition);

	m_spikesTrap = new Object();
	if (Network::GetInstance()->GetMyPlayer().team == 1)
	{
		m_spikesTrap->Initialize("../Shurikenjutsu/Models/CaltropFieldTCRedShape.SSP", p_endPosition);
	}
	else
	{
		m_spikesTrap->Initialize("../Shurikenjutsu/Models/CaltropFieldTCBlueShape.SSP", p_endPosition);
	}

	m_startPosition = p_startPosition;
	m_isThrowing = true;
	m_spikeSphere = Sphere(p_endPosition, SPIKE_SIZE_X);
	m_spikeId = p_smokeBombID;

	m_speed = SPIKE_SPEED;
	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	float length = sqrtf(x*x + z*z);
	m_percentX = x / length;
	m_percentZ = z / length;
	m_angle = asinf((9.82f * length) / (m_speed * m_speed)) * 0.5f;

	return true;
}

void Spikes::Update()
{
	m_timer += (float)GLOBAL::GetInstance().GetDeltaTime();

	if (m_isThrowing)
	{
		float x = m_speed * m_timer * cosf(m_angle) * m_percentX;
		float y = m_speed * m_timer * sinf(m_angle) - 0.5f * 9.82f * m_timer * m_timer;
		float z = m_speed * m_timer * cosf(m_angle) * m_percentZ;

		m_spikeBag->SetPosition(DirectX::XMFLOAT3(m_startPosition.x + x, m_startPosition.y + 10 * y, m_startPosition.z + z));

		if (y < 0.0f)
		{
			ResetTimer();
			m_isThrowing = false;
		}
	}
}

void Spikes::Shutdown()
{
	if (m_spikeBag != nullptr)
	{
		m_spikeBag->Shutdown();
		delete m_spikeBag;
		m_spikeBag = nullptr;
	}

	if (m_spikesTrap != nullptr)
	{
		m_spikesTrap->Shutdown();
		delete m_spikesTrap;
		m_spikesTrap = nullptr;
	}
}

void Spikes::Render()
{
	if (m_isThrowing)
	{
		m_spikeBag->Render();
	}
	else
	{
		m_spikesTrap->Render();
	}
}

void Spikes::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_spikeSphere.m_position = p_position;
}

void Spikes::ResetTimer()
{
	m_timer = 0;
}

Sphere Spikes::GetSpikeSphere()
{
	if (m_isThrowing)
	{
		return m_spikeBag->GetFrustumSphere();
	}
	else
	{
		return m_spikeSphere;
	}
}

unsigned int Spikes::GetID()
{
	return m_spikeId;
}

Object* Spikes::GetSpikesBag()
{
	if (m_isThrowing)
	{
		return m_spikeBag;
	}
	else
	{
		return NULL;
	}
	
}

bool Spikes::GetIsAlive()
{
	if (m_timer < SPIKE_DURATION)
	{
		return true;
	}
	else
	{
		return false;
	}
}