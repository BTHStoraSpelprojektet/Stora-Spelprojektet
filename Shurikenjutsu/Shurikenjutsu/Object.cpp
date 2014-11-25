#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

bool Object::Initialize(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos)
{
	SetPosition(p_pos);


	if (!m_model.LoadModel(p_device, p_filepath))
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

	m_model.SetPosition(p_pos);
}

DirectX::XMFLOAT3 Object::GetPosition() const
{
	return m_position;
}

Model Object::GetModel()
{
	return m_model;
}
