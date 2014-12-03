#include "DebugBox.h"

DebugBox::DebugBox(DirectX::XMFLOAT3 p_centrum, float p_width, float p_depth, float p_height, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> lines;

	// Bottom.
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));

	// In between.
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));

	// Top.
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	lines.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));

	m_mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), lines);
	m_vertices = lines.size();
	m_color = p_color;
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
}

DebugBox::~DebugBox()
{
	m_mesh->Release();
	m_mesh = 0;
}

void DebugBox::Render()
{
	GraphicsEngine::RenderLines(m_mesh, m_vertices, m_color, m_worldMatrix);
}

void DebugBox::UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
}