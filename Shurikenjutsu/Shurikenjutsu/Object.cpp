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

	m_model = ModelLibrary::GetInstance()->GetModel(p_filepath);
	
	return true;
}

void Object::Shutdown()
{

}

void Object::Render(SHADERTYPE p_shader)
{
	GraphicsEngine::Render(p_shader, m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture());
}

void Object::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	m_position = p_pos;
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

DirectX::XMFLOAT4X4 Object::GetWorldMatrix()
{
	DirectX::XMFLOAT4X4 matrix;
	DirectX::XMStoreFloat4x4(&matrix,	DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat3(&m_scale)) *
										DirectX::XMMatrixRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&m_rotation)) *
										DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&m_position)));
	return matrix;
}
