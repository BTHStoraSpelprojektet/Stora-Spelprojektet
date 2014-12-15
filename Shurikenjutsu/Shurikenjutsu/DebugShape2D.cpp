#include "DebugShape2D.h"

void DebugShape2D::Initialize(std::vector<DirectX::XMFLOAT3> p_shape, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> lines;

	for (unsigned int i = 0; i < p_shape.size() - 1; i++)
	{
		lines.push_back(p_shape[i]);
		lines.push_back(p_shape[i + 1]);
	}

	lines.push_back(p_shape[p_shape.size() - 1]);
	lines.push_back(p_shape[0]);

	m_mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), lines);
	m_vertices = lines.size(); 
	m_color = p_color;
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
}

void DebugShape2D::Shutdown()
{
	m_mesh->Release();
	m_mesh = 0;
}

void DebugShape2D::Render()
{
	GraphicsEngine::RenderLines(m_mesh, m_vertices, m_color, m_worldMatrix);
}

void DebugShape2D::UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
}
