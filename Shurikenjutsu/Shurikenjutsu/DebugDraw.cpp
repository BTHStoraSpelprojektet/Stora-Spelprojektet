#include "DebugDraw.h"

DebugDraw& DebugDraw::GetInstance()
{
	static DebugDraw instance;

	return instance;
}

void DebugDraw::RenderLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint)
{
	std::vector<DirectX::XMFLOAT3> line;

	line.push_back(p_startPoint);
	line.push_back(p_endPoint);

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size());

	mesh->Release();
	mesh = 0;
}

void DebugDraw::RenderRectangle(DirectX::XMFLOAT3 p_centrum, float p_width, float p_height)
{
	std::vector<DirectX::XMFLOAT3> line;

	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_height / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_height / 2.0f));

	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_height / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_height / 2.0f));

	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_height / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_height / 2.0f));

	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_height / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_height / 2.0f));

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size());

	mesh->Release();
	mesh = 0;
}

void DebugDraw::RenderGenericShape(std::vector<DirectX::XMFLOAT3> p_shape)
{
	std::vector<DirectX::XMFLOAT3> line;

	for (int i = 0; i < p_shape.size() - 1; i++)
	{
		line.push_back(p_shape[i]);
		line.push_back(p_shape[i+1]);
	}

	line.push_back(p_shape[p_shape.size() - 1]);
	line.push_back(p_shape[0]);

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size());

	mesh->Release();
	mesh = 0;
}