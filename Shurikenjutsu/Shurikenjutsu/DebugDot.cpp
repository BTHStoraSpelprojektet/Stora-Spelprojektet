#include "DebugDot.h"

void DebugDot::Initialize(DirectX::XMFLOAT3 p_centrum, int p_resolution, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> lines;
	DirectX::XMFLOAT3 position;

	// Every line but the last.
	for (int i = 0; i < p_resolution; ++i)
	{
		position.x = p_centrum.x;
		position.y = p_centrum.y;
		position.z = p_centrum.z;

		lines.push_back(position);

		position.x = p_centrum.x + cos(2 * 3.141592f * i / p_resolution) * 0.2f;
		position.y = p_centrum.y;
		position.z = p_centrum.z + sin(2 * 3.141592f * i / p_resolution) * 0.2f;

		lines.push_back(position);
	}

	m_mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), lines);
	m_vertices = lines.size();
	m_color = p_color;
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
}

void DebugDot::Shutdown()
{
	m_mesh->Release();
	m_mesh = 0;
}

void DebugDot::Render()
{
	GraphicsEngine::RenderLines(m_mesh, m_vertices, m_color, m_worldMatrix);
}

void DebugDot::UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
}