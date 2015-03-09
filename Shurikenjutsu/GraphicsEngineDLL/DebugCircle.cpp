#include "stdafx.h"
#include "DebugCircle.h"
#include "GraphicsEngineDLL.h"

void DebugCircle::Initialize(DirectX::XMFLOAT3 p_centrum, float p_radius, int p_resolution, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> lines;
	DirectX::XMFLOAT3 position;

	// Every line but the last.
	for (int i = 0; i < p_resolution; ++i)
	{
		position.x = p_centrum.x + cos(2 * 3.141592f * i / p_resolution) * p_radius;
		position.y = p_centrum.y;
		position.z = p_centrum.z + sin(2 * 3.141592f * i / p_resolution) * p_radius;

		lines.push_back(position);

		position.x = p_centrum.x + cos(2 * 3.141592f * (i + 1) / p_resolution) * p_radius;
		position.y = p_centrum.y;
		position.z = p_centrum.z + sin(2 * 3.141592f * (i + 1) / p_resolution) * p_radius;

		lines.push_back(position);
	}

	m_mesh = Buffer::CreateLineBuffer(GraphicsEngine::GE::GetInstance()->GetDevice(), lines);
	m_vertices = lines.size();
	m_color = p_color;
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
	m_radius = p_radius;
}

void DebugCircle::Shutdown()
{
	if (m_mesh)
	{
		m_mesh->Release();
		m_mesh = 0;
	}
}

void DebugCircle::Render()
{
	GraphicsEngine::GE::GetInstance()->RenderLines(m_mesh, m_vertices, m_color, m_worldMatrix);
}

void DebugCircle::UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
}

float DebugCircle::GetRadius()
{
	return m_radius;
}