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

	m_model = (Model*)ModelLibrary::GetInstance()->GetModel(p_filepath);
	
	TransformBoundingBoxes();
	TransformShadowPoints();

	return true;
}

bool Object::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_rotation, DirectX::XMFLOAT3 p_scale)
{
	SetPosition(p_pos);
	SetScale(p_scale);
	SetRotation(p_rotation);

	m_model = (Model*)ModelLibrary::GetInstance()->GetModel(p_filepath);

	TransformBoundingBoxes();
	TransformShadowPoints();

	return true;
}

void Object::Shutdown()
{

}

void Object::Render(SHADERTYPE p_shader)
{
	GraphicsEngine::Render(p_shader, m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap());
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


Model* Object::GetModel()
{
	return m_model;
}

void Object::TransformBoundingBoxes()
{
	m_boundingBoxes.clear();
	m_debugBoxes.clear();

	std::vector<Box> bbList = m_model->GetBoundingBoxes();
	DirectX::XMFLOAT4X4 world = GetWorldMatrix();
	DirectX::XMFLOAT4 orientation;
	DirectX::XMStoreFloat4(&orientation, DirectX::XMQuaternionRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&m_rotation)));

	for (unsigned int i = 0; i < bbList.size(); i++)
	{
		OBB temp;
		temp.m_center = bbList[i].m_center;
		DirectX::XMFLOAT4 center = DirectX::XMFLOAT4(temp.m_center.x, temp.m_center.y, temp.m_center.z, 1.0f);
		DirectX::XMVECTOR transCenter = DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&center), DirectX::XMLoadFloat4x4(&world));
		DirectX::XMStoreFloat3(&temp.m_center, transCenter);
		temp.m_extents = bbList[i].m_extents;
		temp.m_direction = orientation;
		m_boundingBoxes.push_back(temp);

		DebugShape3D shape;
		std::vector<DirectX::XMFLOAT3> list;
		DirectX::XMFLOAT3 position;

		// Top right.
		position = DirectX::XMFLOAT3(bbList[i].m_center.x + temp.m_extents.x, bbList[i].m_center.y - temp.m_extents.y, bbList[i].m_center.z + temp.m_extents.z);
		DirectX::XMFLOAT4 newPos = DirectX::XMFLOAT4(position.x, position.y, position.z, 1.0f);
		DirectX::XMStoreFloat3(&position, DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&newPos), DirectX::XMLoadFloat4x4(&world)));
		list.push_back(position);

		// Bottom right.
		position = DirectX::XMFLOAT3(bbList[i].m_center.x + temp.m_extents.x, bbList[i].m_center.y - temp.m_extents.y, bbList[i].m_center.z - temp.m_extents.z);
		newPos = DirectX::XMFLOAT4(position.x, position.y, position.z, 1.0f);
		DirectX::XMStoreFloat3(&position, DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&newPos), DirectX::XMLoadFloat4x4(&world)));
		list.push_back(position);

		// Bottom left.
		position = DirectX::XMFLOAT3(bbList[i].m_center.x - temp.m_extents.x, bbList[i].m_center.y - temp.m_extents.y, bbList[i].m_center.z - temp.m_extents.z);
		newPos = DirectX::XMFLOAT4(position.x, position.y, position.z, 1.0f);
		DirectX::XMStoreFloat3(&position, DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&newPos), DirectX::XMLoadFloat4x4(&world)));
		list.push_back(position);

		// Top left.
		position = DirectX::XMFLOAT3(bbList[i].m_center.x - temp.m_extents.x, bbList[i].m_center.y - temp.m_extents.y, bbList[i].m_center.z + temp.m_extents.z);
		newPos = DirectX::XMFLOAT4(position.x, position.y, position.z, 1.0f);
		DirectX::XMStoreFloat3(&position, DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&newPos), DirectX::XMLoadFloat4x4(&world)));
		list.push_back(position);

		shape.Initialize(list, bbList[i].m_extents.y, DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));
		m_debugBoxes.push_back(shape);
	}
}

void Object::RenderDebugBoxes()
{
	for (unsigned int i = 0; i < m_debugBoxes.size(); i++)
	{
		m_debugBoxes[i].Render();
	}
}

void Object::RenderShadowShapes()
{
	m_debugShadowShapes.Render();
}

void Object::TransformShadowPoints()
{
	m_shadowPoints.clear();
	std::vector<DirectX::XMFLOAT3> saList = m_model->GetShadowPoints();
	DirectX::XMFLOAT4X4 world = GetWorldMatrix();

	for (unsigned int i = 0; i < saList.size(); i++)
	{
		DirectX::XMFLOAT4 position = DirectX::XMFLOAT4(saList[i].x, saList[i].y, saList[i].z, 1.0f);
		DirectX::XMVECTOR transCenter = DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&position), DirectX::XMLoadFloat4x4(&world));
		m_shadowPoints.push_back(DirectX::XMFLOAT3(position.x, position.y, position.z));
	}

	if (saList.size() > 0)
	{
		m_debugShadowShapes.Initialize(m_shadowPoints, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	}
}

std::vector<OBB> Object::GetBoundingBoxes()
{
	return m_boundingBoxes;
}

std::vector<DirectX::XMFLOAT3> Object::GetShadowPoints()
{
	return m_shadowPoints;
}