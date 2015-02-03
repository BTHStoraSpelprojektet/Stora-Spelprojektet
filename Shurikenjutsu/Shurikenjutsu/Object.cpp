#include "Object.h"
#include "Network.h"
#include <DirectXCollision.h>
#include "Model.h"
#include "AnimationControl.h"
#include "ShadowShapes.h"

Object::Object(){}
Object::~Object(){}
bool Object::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos)
{
	SetPosition(p_pos);
	SetScale(DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	SetRotation(DirectX::XMFLOAT3(0.0f,0.0f, 0.0f));

	m_model = (Model*)ModelLibrary::GetInstance()->GetModel(p_filepath);
	
	TransformBoundingBoxes();
	TransformBoundingSpheres();
	TransformShadowPoints();

	m_InstanceIndex = GraphicsEngine::GetNumberOfInstanceBuffer();

	return true;
}

bool Object::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_rotation, DirectX::XMFLOAT3 p_scale)
{
	SetPosition(p_pos);
	SetScale(p_scale);
	SetRotation(p_rotation);

	m_model = (Model*)ModelLibrary::GetInstance()->GetModel(p_filepath);

	TransformBoundingBoxes();
	TransformBoundingSpheres();
	TransformShadowPoints();


	m_InstanceIndex = GraphicsEngine::GetNumberOfInstanceBuffer();

	return true;
}

void Object::Shutdown(){}

void Object::Render()
{
	GraphicsEngine::RenderScene(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap());
}

void Object::RenderDepth()
{
	GraphicsEngine::RenderDepth(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture());
}

void Object::RenderDepthInstanced()
{
	GraphicsEngine::RenderDepthInstanced(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_InstanceIndex);
}

void Object::RenderInstanced()
{
	GraphicsEngine::RenderInstanced(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap(), m_InstanceIndex);
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
	DirectX::XMStoreFloat4x4(&matrix, DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat3(&m_scale)) * 
		DirectX::XMMatrixRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&m_rotation)) * 
		DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&m_position)));
	
	return matrix;
}

DirectX::XMFLOAT4X4 Object::GetWorldMatrixScaled(float p_scale)
{

	DirectX::XMFLOAT4X4 matrix;
	DirectX::XMStoreFloat4x4(&matrix, DirectX::XMMatrixTranslation(0.0f,-0.1f, 0.0f) *
		DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(p_scale, p_scale, p_scale))) *
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
	}
}

void Object::TransformBoundingSpheres()
{
	m_boundingSpheres.clear();

	std::vector<Sphere> sphereList = m_model->GetBoundingSpheres();
	DirectX::XMFLOAT4X4 world = GetWorldMatrix();
	DirectX::XMFLOAT4 orientation;
	DirectX::XMStoreFloat4(&orientation, DirectX::XMQuaternionRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&m_rotation)));

	for (unsigned int i = 0; i < sphereList.size(); i++)
	{
		Sphere temp;
		temp.m_position = sphereList[i].m_position;
		DirectX::XMFLOAT4 center = DirectX::XMFLOAT4(temp.m_position.x, temp.m_position.y, temp.m_position.z, 1.0f);
		DirectX::XMVECTOR transCenter = DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&center), DirectX::XMLoadFloat4x4(&world));
		DirectX::XMStoreFloat3(&temp.m_position, transCenter);
		temp.m_radius = sphereList[i].m_radius;
		m_boundingSpheres.push_back(temp);
	}
}

void Object::TransformShadowPoints()
{
	std::vector<Line> lines = m_model->GetShadowLines();

	if (lines.size() > 0)
	{
		DirectX::XMFLOAT4X4 world = GetWorldMatrix();

		DirectX::XMFLOAT3 a;
		DirectX::XMFLOAT3 b;

		for (unsigned int i = 0; i < lines.size(); i++)
		{
			a = DirectX::XMFLOAT3(lines[i].a.x, 0.0f, lines[i].a.y);
			b = DirectX::XMFLOAT3(lines[i].b.x, 0.0f, lines[i].b.y);

			DirectX::XMStoreFloat3(&a, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&a), DirectX::XMLoadFloat4x4(&world)));
			DirectX::XMStoreFloat3(&b, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&b), DirectX::XMLoadFloat4x4(&world)));

			ShadowShapes::GetInstance().AddStaticLine(Line(Point(a.x, a.z), Point(b.x, b.z)));
		}
	}
}

std::vector<OBB> Object::GetBoundingBoxes()
{
	return m_boundingBoxes;
}

std::vector<Sphere> Object::GetBoundingSpheres()
{
	return m_boundingSpheres;
}

Sphere Object::GetFrustumSphere()
{
	Sphere tempSphere = m_model->GetFrustumSphere();

	tempSphere.m_position.x += m_position.x;
	tempSphere.m_position.y += m_position.y;
	tempSphere.m_position.z += m_position.z;

	return tempSphere;
}

void Object::CreateInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_positions)
{
	GraphicsEngine::AddInstanceBuffer(p_numberOfInstances, p_positions);
}

int Object::GetInstanceIndex() const
{
	return m_InstanceIndex;
}

void Object::SetInstanceIndex(int p_instanceIndex)
{
	m_InstanceIndex = p_instanceIndex;
}