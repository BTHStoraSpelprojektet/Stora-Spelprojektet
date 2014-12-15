#include "ShadowShapes.h"

// Singleton constructor
ShadowShapes& ShadowShapes::GetInstance()
{
	static ShadowShapes instance;
	return instance;
}

void ShadowShapes::AddShadowShape(ShadowShape p_shadowShape)
{
	m_shadowShapes.push_back(p_shadowShape);

	std::vector<DirectX::XMFLOAT3> shape;
	for (unsigned int i = 0; i < p_shadowShape.m_lineSegments.size(); i++)
	{
		shape.push_back(DirectX::XMFLOAT3(p_shadowShape.m_lineSegments[i].m_startPoint.x, 0.1f, p_shadowShape.m_lineSegments[i].m_startPoint.y));

		DebugDot debugdot;
		debugdot.Initialize(shape[i], 100, DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f));
		m_debugDots.push_back(debugdot);
	}

	DebugShape2D debugShape;
	debugShape.Initialize(shape, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	m_debugShapes.push_back(debugShape);
}

void ShadowShapes::RemoveShadowShape(unsigned int p_index)
{
	m_shadowShapes.erase(m_shadowShapes.begin() + p_index);

	m_debugShapes[p_index].Shutdown();
	m_debugShapes.erase(m_debugShapes.begin() + p_index);
}

void ShadowShapes::DebugRender()
{
	// Render lines.
	for (unsigned int i = 0; i < m_debugShapes.size(); i++)
	{
		m_debugShapes[i].Render();
	}

	// Render dots.
	for (unsigned int i = 0; i < m_debugDots.size(); i++)
	{
		m_debugDots[i].Render();
	}
}