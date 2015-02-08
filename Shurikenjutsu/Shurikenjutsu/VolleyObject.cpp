#include "VolleyObject.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

VolleyObject::VolleyObject(){}
VolleyObject::~VolleyObject(){}

bool VolleyObject::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition)
{
	MovingObject::Initialize(p_filepath, p_startPosition, DirectX::XMFLOAT3(0, 0, 0), 0.0f);

	m_startPosition = p_startPosition;
	m_endPosition = p_endPosition;

	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	float length = sqrtf(x*x + z*z);
	m_percentX = x / length;
	m_percentZ = z / length;
	m_angle = asinf((9.82f * length) / (VOLLEY_SPEED * VOLLEY_SPEED)) * 0.5f;
	m_speed = sqrtf((length * 9.82f) / (sinf(2 * m_angle)));
	m_timeToLand = length / (m_speed * cosf(m_angle));

	return true;
}

void VolleyObject::Shutdown()
{
	MovingObject::Shutdown();
}

void VolleyObject::Update(float p_timer)
{
	if (p_timer < m_timeToLand)
	{
		float x = m_speed * p_timer * cosf(m_angle) * m_percentX;
		float y = m_speed * p_timer * sinf(m_angle) - 0.5f * 9.82f * p_timer * p_timer;
		float z = m_speed * p_timer * cosf(m_angle) * m_percentZ;

		m_position = DirectX::XMFLOAT3(m_startPosition.x + x, m_startPosition.y + 20.0f*y, m_startPosition.z + z);
	}
}

