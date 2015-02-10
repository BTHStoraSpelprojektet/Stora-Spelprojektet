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
	m_speedY = sqrtf(VOLLEY_HEIGHT / (2.0f*VOLLEY_GRAVITY));
	m_timeToLand = 2.0f*m_speedY / VOLLEY_GRAVITY;
	m_speed = length / m_timeToLand;
	m_angle = 3.14f / m_timeToLand;
	m_lifeTime = m_timeToLand + 0.5f;
	m_lastPosition = m_startPosition;
	return true;
}

void VolleyObject::Shutdown()
{
	MovingObject::Shutdown();
}

bool VolleyObject::Update(float p_timer)
{
	// Update
	if (p_timer < m_timeToLand)
	{
		float x = m_speed * p_timer * m_percentX;
		float y = VOLLEY_HEIGHT*m_speedY*sinf(p_timer*m_angle);
		float z = m_speed * p_timer * m_percentZ;

		m_position = DirectX::XMFLOAT3(m_startPosition.x + x, m_startPosition.y + y, m_startPosition.z + z);

		// Rotate
		DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(m_position.x - m_lastPosition.x, m_position.y - m_lastPosition.y, m_position.z - m_lastPosition.z);
		DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(-atan2f(direction.y, (float)abs(direction.z)), atan2f(direction.x, direction.z), 0);
		SetRotation(rotation);
		m_lastPosition = m_position;
	}

	// Remove;
	else if (p_timer > m_lifeTime)
	{
		return true;
	}
	
	return false;
}

