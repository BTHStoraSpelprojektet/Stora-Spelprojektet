#include "MovingObject.h"


MovingObject::MovingObject(){}
MovingObject::~MovingObject(){}

bool MovingObject::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	if (!Object::Initialize(p_filepath, p_pos))
	{
		return false;
	}

	SetDirection(p_dir);
	SetSpeed(p_speed);

	return true;
}

void MovingObject::Shutdown()
{
	Object::Shutdown();
}

void MovingObject::SetDirection(DirectX::XMFLOAT3 p_direction)
{
	m_direction = p_direction;
	
}

DirectX::XMFLOAT3 MovingObject::GetDirection()
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
