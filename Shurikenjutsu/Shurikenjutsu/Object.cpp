#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

bool Object::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos)
{
	SetPosition(p_pos);
	SetScale(DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	SetRotation(DirectX::XMFLOAT3(0.0f,0.0f, 0.0f));

	if (!m_model.LoadModel(p_filepath))
	{
		return false;
	}
	
	return true;
}

void Object::Shutdown()
{
	m_model.Shutdown();
}

void Object::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	m_position = p_pos;

	m_model.Translate(p_pos);
}

DirectX::XMFLOAT3 Object::GetPosition() const
{
	return m_position;
}

DirectX::XMFLOAT3 Object::GetScale() const
{
	return m_scale;
}

void Object::SetScale(DirectX::XMFLOAT3 p_scale)
{
	m_scale = p_scale;
}

DirectX::XMFLOAT3 Object::GetRotation() const
{
	return m_rotation;
}

void Object::SetRotation(DirectX::XMFLOAT3 p_rotation)
{
	m_rotation = p_rotation;
}

Model Object::GetModel()
{
	return m_model;
}
