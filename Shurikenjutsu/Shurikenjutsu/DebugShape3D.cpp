#include "DebugShape3D.h"

DebugShape3D::DebugShape3D(std::vector<DirectX::XMFLOAT3> p_shape, float p_height, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> shapeTop = p_shape;
	for (unsigned int i = 0; i < shapeTop.size(); i++)
	{
		shapeTop[i].y += p_height;
	}

	std::vector<DirectX::XMFLOAT3> lines;

	// Bottom.
	for (unsigned int i = 0; i < p_shape.size() - 1; i++)
	{
		lines.push_back(p_shape[i]);
		lines.push_back(p_shape[i + 1]);
	}
	lines.push_back(p_shape[p_shape.size() - 1]);
	lines.push_back(p_shape[0]);

	// In between.
	for (unsigned int i = 0; i < p_shape.size(); i++)
	{
		lines.push_back(p_shape[i]);
		lines.push_back(shapeTop[i]);
	}

	// Top.
	for (unsigned int i = 0; i < p_shape.size() - 1; i++)
	{
		lines.push_back(shapeTop[i]);
		lines.push_back(shapeTop[i + 1]);
	}
	lines.push_back(shapeTop[shapeTop.size() - 1]);
	lines.push_back(shapeTop[0]);

	m_mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), lines);
	m_vertices = lines.size();
	m_color = p_color;
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
}

DebugShape3D::~DebugShape3D()
{
	m_mesh->Release();
	m_mesh = 0;
}

void DebugShape3D::Render()
{
	GraphicsEngine::RenderLines(m_mesh, m_vertices, m_color, m_worldMatrix);
}

void DebugShape3D::UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
}
