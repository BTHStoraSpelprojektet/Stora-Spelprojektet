#include "Lines.h"

Lines& Lines::GetInstance()
{
	static Lines instance;

	return instance;
}

void Lines::RenderStaticLines()
{
	if (m_lines.size() != 0)
	{
		ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), m_lines);

		GraphicsEngine::RenderLine(mesh, m_lines.size());

		mesh->Release();
		mesh = 0;
	}
}

void Lines::RenderSingleLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint)
{
	std::vector<DirectX::XMFLOAT3> line;

	line.push_back(p_startPoint);
	line.push_back(p_endPoint);

	ID3D11Buffer* mesh = Buffer::CreateLineBuffer(GraphicsEngine::GetDevice(), line);

	GraphicsEngine::RenderLine(mesh, line.size());

	mesh->Release();
	mesh = 0;
}

void Lines::AddStaticLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint)
{
	m_lines.push_back(p_startPoint);
	m_lines.push_back(p_endPoint);
}

void Lines::ClearStaticLines()
{
	m_lines.clear();
}
