#include "DebugLineList.h"

void DebugLineList::Initialize(DirectX::XMFLOAT3 p_color)
{
	m_lines.clear();
	m_color = p_color;
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
}

void DebugLineList::Shutdown()
{
	if (m_mesh)
	{
		m_mesh->Release();
		m_mesh = 0;
	}
}

void DebugLineList::AddLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint)
{
	m_lines.push_back(p_startPoint);
	m_lines.push_back(p_endPoint);

	m_mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), m_lines);
	m_vertices = m_lines.size();
}

void DebugLineList::RemoveLine(int p_index)
{
	m_lines.erase(m_lines.begin() + p_index, m_lines.begin() + p_index + 1);
	m_lines.shrink_to_fit();
}

void DebugLineList::Render()
{
	GraphicsEngine::RenderLines(m_mesh, m_vertices, m_color, m_worldMatrix);
}

void DebugLineList::UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
}