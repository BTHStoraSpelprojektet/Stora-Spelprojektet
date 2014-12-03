#include "DebugDraw.h"

DebugDraw& DebugDraw::GetInstance()
{
	static DebugDraw instance;

	return instance;
}

void DebugDraw::RenderSingleLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> line;

	line.push_back(p_startPoint);
	line.push_back(p_endPoint);

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	DirectX::XMFLOAT4X4 world;
	DirectX::XMStoreFloat4x4(&world, DirectX::XMMatrixIdentity());

	GraphicsEngine::RenderLines(mesh, line.size(), p_color, world);
}