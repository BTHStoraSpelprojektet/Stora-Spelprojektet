#include "MovingObject.h"


MovingObject::MovingObject()
{
}


MovingObject::~MovingObject()
{
}

void MovingObject::SetDirection(DirectX::XMFLOAT3 p_direction)
{
	m_direction = p_direction;
}

DirectX::XMFLOAT3 MovingObject::GetDirection() const
{
	return m_direction;
}


void MovingObject::SetSpeed(float p_speed)
{
	m_speed = p_speed;
}

float MovingObject::GetSpeed() const
{
	return m_speed;
}
