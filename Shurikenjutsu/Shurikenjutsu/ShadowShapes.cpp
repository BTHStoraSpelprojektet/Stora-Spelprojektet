#include "ShadowShapes.h"

ShadowShapes& ShadowShapes::GetInstance()
{
	static ShadowShapes instance;

	return instance;
}

bool ShadowShapes::Initialize()
{
	m_staticLines.clear();
	m_dynamicLines.clear();
	m_staticDebugDots.clear();

	m_staticDebugLines.Initialize(DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

	return true;
}

void ShadowShapes::Shutdown()
{
	m_staticLines.clear();
	m_dynamicLines.clear();

	if (FLAG_DEBUG == 1)
	{
		for (unsigned int i = 0; i < m_staticDebugDots.size(); i++)
		{
			m_staticDebugDots[i].Shutdown();
		}

		m_staticDebugDots.clear();
	}

	m_staticDebugLines.Shutdown();
}

void ShadowShapes::AddStaticLine(Line p_line)
{
	// Add the line to the list.
	m_staticLines.push_back(p_line);

	// Add debug data.
	if (FLAG_DEBUG == 1)
	{
		AddDebugLineAndDots(p_line.a, p_line.b);
	}
}

void ShadowShapes::AddStaticShape(std::vector<Line> p_shape)
{
	if (p_shape.size() > 0)
	{
		// Add all the lines to the list.
		for (unsigned int i = 0; i < p_shape.size(); i++)
		{
			m_staticLines.push_back(p_shape[i]);
		}

		// Add debug data.
		if (FLAG_DEBUG == 1)
		{
			for (unsigned int i = 0; i < p_shape.size(); i++)
			{
				AddDebugLineAndDots(p_shape[i].a, p_shape[i].b);
			}
		}
	}

	else
	{
		ConsolePrintError("Tried to add an empty shape to the static shadow shapes.");
	}
}

void ShadowShapes::AddStaticSquare(Point p_topLeft, Point p_bottomRight)
{
	// Add top line.
	Line top = Line(p_topLeft, Point(p_bottomRight.x, p_topLeft.y));
	m_staticLines.push_back(top); 
	
	// Add right line.
	Line right = Line(Point(p_bottomRight.x, p_topLeft.y), p_bottomRight);
	m_staticLines.push_back(right);

	// Add bottom line.
	Line bottom = Line(p_bottomRight, Point(p_topLeft.x, p_bottomRight.y));
	m_staticLines.push_back(bottom);

	// Add left line.
	Line left = Line(Point(p_topLeft.x, p_bottomRight.y), p_topLeft);
	m_staticLines.push_back(left);

	// Add debug data.
	if (FLAG_DEBUG == 1)
	{
		AddDebugLineAndDots(top.a, top.b);
		AddDebugLineAndDots(right.a, right.b);
		AddDebugLineAndDots(bottom.a, bottom.b);
		AddDebugLineAndDots(left.a, left.b);
	}
}

int ShadowShapes::AddDynamicLine(Line p_line)
{
	// Add the line to the list.
	m_dynamicLines.push_back(p_line);
	
	// Return the index at which the line was placed.
	return m_dynamicLines.size();
}

int ShadowShapes::AddDynamicShape(std::vector<Line> p_shape)
{ 
	int index = -1;

	if (p_shape.size() > 0)
	{
		// Add the first line to the list.
		m_dynamicLines.push_back(p_shape[0]);

		// Save the index at which the line was placed.
		index = m_dynamicLines.size();

		// Add the rest of the lines to the list.
		for (unsigned int i = 1; i < p_shape.size(); i++)
		{
			m_dynamicLines.push_back(p_shape[i]);
		}

		return index;
	}

	else
	{
		ConsolePrintError("Tried to add an empty shape to the dynamic shadow shapes.");

		return index;
	}
}

int ShadowShapes::AddSmokeBombShape(Point p_center)
{
	int index = 0;

	// TODO

	return index;
}

void ShadowShapes::AddMapBoundries(Point p_center, float p_width, float p_height)
{
	// Use static square function.
	AddStaticSquare(Point(p_center.x - p_width, p_center.y + p_height), Point(p_center.x + p_width, p_center.y - p_height));
}

void ShadowShapes::RemoveDynamicLine(int p_atIndex)
{
	// TODO
}

void ShadowShapes::RemoveDynamicShape(int p_atIndex, int p_numberOfLines)
{
	// TODO
}

std::vector<Line> ShadowShapes::GetStaticLines()
{
	return m_staticLines;
}

std::vector<Line> ShadowShapes::GetDynamicLines()
{
	return m_dynamicLines;
}

void ShadowShapes::DebugRender()
{
	// Render every static line.
	m_staticDebugLines.Render();

	// Render every static dot.
	for (unsigned int i = 0; i < m_staticDebugDots.size(); i++)
	{
		m_staticDebugDots[i].Render();
	}

	// TODO, render dynamic?
}

void ShadowShapes::AddDebugLineAndDots(Point p_a, Point p_b)
{
	// Add line to debug.
	m_staticDebugLines.AddLine(DirectX::XMFLOAT3(p_a.x, 0.2f, p_a.y), DirectX::XMFLOAT3(p_b.x, 0.2f, p_b.y));

	// Add blue start point.
	DebugDot start;
	start.Initialize(DirectX::XMFLOAT3(p_a.x, 0.2f, p_a.y), 21, DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));
	m_staticDebugDots.push_back(start);

	// Add red end point.
	DebugDot end;
	end.Initialize(DirectX::XMFLOAT3(p_b.x, 0.2f, p_b.y), 21, DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f));
	m_staticDebugDots.push_back(end);
}