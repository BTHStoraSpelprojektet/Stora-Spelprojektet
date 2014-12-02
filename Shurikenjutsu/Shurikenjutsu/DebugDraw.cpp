#include "DebugDraw.h"

DebugDraw& DebugDraw::GetInstance()
{
	static DebugDraw instance;

	return instance;
}

void DebugDraw::RenderLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> line;

	line.push_back(p_startPoint);
	line.push_back(p_endPoint);

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size(), p_color);

	mesh->Release();
	mesh = 0;
}

void DebugDraw::RenderRectangle(DirectX::XMFLOAT3 p_centrum, float p_width, float p_depth, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> line;

	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));

	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));

	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));

	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size(), p_color);

	mesh->Release();
	mesh = 0;
}

void DebugDraw::Render2DShape(std::vector<DirectX::XMFLOAT3> p_shape, DirectX::XMFLOAT3 p_color)
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

	GraphicsEngine::RenderLine(mesh, line.size(), p_color);

	mesh->Release();
	mesh = 0;
}

void DebugDraw::RenderBox(DirectX::XMFLOAT3 p_centrum, float p_width, float p_depth, float p_height, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> line;

	// Bottom.
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));

	// In between.
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));

	// Top.
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x + p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z + p_depth / 2.0f));
	line.push_back(DirectX::XMFLOAT3(p_centrum.x - p_width / 2.0f, p_centrum.y + p_height, p_centrum.z - p_depth / 2.0f));

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size(), p_color);

	mesh->Release();
	mesh = 0;
}

void DebugDraw::Render3DShape(std::vector<DirectX::XMFLOAT3> p_shape, float p_height, DirectX::XMFLOAT3 p_color)
{
	std::vector<DirectX::XMFLOAT3> shapeTop = p_shape;
	for (int i = 0; i < shapeTop.size(); i++)
	{
		shapeTop[i].y += p_height;
	}

	std::vector<DirectX::XMFLOAT3> line;

	// Bottom.
	for (int i = 0; i < p_shape.size() - 1; i++)
	{
		line.push_back(p_shape[i]);
		line.push_back(p_shape[i + 1]);
	}
	line.push_back(p_shape[p_shape.size() - 1]);
	line.push_back(p_shape[0]);

	// In between.
	for (int i = 0; i < p_shape.size(); i++)
	{
		line.push_back(p_shape[i]);
		line.push_back(shapeTop[i]);
	}

	// Top.
	for (int i = 0; i < p_shape.size() - 1; i++)
	{
		line.push_back(shapeTop[i]);
		line.push_back(shapeTop[i + 1]);
	}
	line.push_back(shapeTop[shapeTop.size() - 1]);
	line.push_back(shapeTop[0]);

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size(), p_color);

	mesh->Release();
	mesh = 0;
}