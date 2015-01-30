#include "ShadowShapes.h"

ShadowShapes& ShadowShapes::GetInstance()
{
	static ShadowShapes instance;

	return instance;
}

bool ShadowShapes::Initialize()
{
	m_boundries.clear();
	m_staticLines.clear();
	m_dynamicLines.clear();

	m_uniquePoints.clear();
	m_uniqueBoundryPoints.clear();

	m_staticDebugLines.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));

	return true;
}

void ShadowShapes::Shutdown()
{
	m_boundries.clear();
	m_staticLines.clear();
	m_dynamicLines.clear();

	m_uniquePoints.clear();
	m_uniqueBoundryPoints.clear();

	m_staticDebugLines.Shutdown();
}

void ShadowShapes::AddStaticLine(Line p_line)
{
	// Add the line to the list.
	m_staticLines.push_back(p_line);

	// Add debug data.
	if (FLAG_DEBUG == 1)
	{
		AddDebugLines(p_line.a, p_line.b);
	}

	// Check if the points are unique, if so add the to the list.
	AddUniquePoints(p_line.a);
	AddUniquePoints(p_line.b);
}

void ShadowShapes::AddStaticShape(std::vector<Line> p_shape)
{
	if (p_shape.size() > 0)
	{
		// Add all the lines to the list.
		for (unsigned int i = 0; i < p_shape.size(); i++)
		{
			m_staticLines.push_back(p_shape[i]);

			// Check if the points are unique, if so add the to the list.
			AddUniquePoints(p_shape[i].a);
			AddUniquePoints(p_shape[i].b);
		}

		// Add debug data.
		if (FLAG_DEBUG == 1)
		{
			for (unsigned int i = 0; i < p_shape.size(); i++)
			{
				AddDebugLines(p_shape[i].a, p_shape[i].b);
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

	// Check if the points are unique, if so add the to the list.
	AddUniquePoints(top.a);
	AddUniquePoints(top.b);
	
	// Add right line.
	Line right = Line(Point(p_bottomRight.x, p_topLeft.y), p_bottomRight);
	m_staticLines.push_back(right);

	// Check if the points are unique, if so add the to the list.
	AddUniquePoints(right.a);
	AddUniquePoints(right.b);

	// Add bottom line.
	Line bottom = Line(p_bottomRight, Point(p_topLeft.x, p_bottomRight.y));
	m_staticLines.push_back(bottom);

	// Check if the points are unique, if so add the to the list.
	AddUniquePoints(bottom.a);
	AddUniquePoints(bottom.b);

	// Add left line.
	Line left = Line(Point(p_topLeft.x, p_bottomRight.y), p_topLeft);
	m_staticLines.push_back(left);

	// Check if the points are unique, if so add the to the list.
	AddUniquePoints(left.a);
	AddUniquePoints(left.b);

	// Add debug data.
	if (FLAG_DEBUG == 1)
	{
		AddDebugLines(top.a, top.b);
		AddDebugLines(right.a, right.b);
		AddDebugLines(bottom.a, bottom.b);
		AddDebugLines(left.a, left.b);
	}
}

void ShadowShapes::UpdateBoundries(Point p_topLeft, Point p_bottomRight)
{
	m_boundries.clear();
	m_uniqueBoundryPoints.clear();

	// Add top line.
	Line top = Line(p_topLeft, Point(p_bottomRight.x, p_topLeft.y));
	m_boundries.push_back(top);
	m_uniqueBoundryPoints.push_back(top.a);

	// Add right line.
	Line right = Line(Point(p_bottomRight.x, p_topLeft.y), p_bottomRight);
	m_boundries.push_back(right);
	m_uniqueBoundryPoints.push_back(right.a);

	// Add bottom line.
	Line bottom = Line(p_bottomRight, Point(p_topLeft.x, p_bottomRight.y));
	m_boundries.push_back(bottom);
	m_uniqueBoundryPoints.push_back(bottom.a);

	// Add left line.
	Line left = Line(Point(p_topLeft.x, p_bottomRight.y), p_topLeft);
	m_boundries.push_back(left);
	m_uniqueBoundryPoints.push_back(left.a);
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

void ShadowShapes::RemoveDynamicLine(int p_atIndex)
{
	m_dynamicLines.erase(m_dynamicLines.begin() + p_atIndex);

	// TODO, this will fuck over every other index...
}

void ShadowShapes::RemoveDynamicShape(int p_atIndex, int p_numberOfLines)
{
	m_dynamicLines.erase(m_dynamicLines.begin() + p_atIndex, m_dynamicLines.begin() + p_atIndex + p_numberOfLines);

	// TODO, this will fuck over every other index...
}

std::vector<Line> ShadowShapes::GetBoundryLines()
{
	return m_boundries;
}

std::vector<Line> ShadowShapes::GetStaticLines(Point a, Point b)
{
	std::vector<Line> list;

	for (unsigned int i = 0; i < m_staticLines.size(); i++)
	{
		if ((m_staticLines[i].a.x >= a.x && m_staticLines[i].a.x <= b.x && m_staticLines[i].a.y <= a.y && m_staticLines[i].a.y >= b.y) || (m_staticLines[i].b.x >= a.x && m_staticLines[i].b.x <= b.x && m_staticLines[i].b.y <= a.y && m_staticLines[i].b.y >= b.y))
		{
				list.push_back(m_staticLines[i]);
		}
	}

	return list;
}

std::vector<Line> ShadowShapes::GetDynamicLines()
{
	return m_dynamicLines;
}

void ShadowShapes::DebugRender()
{
	// Render every static line.
	m_staticDebugLines.Render();

	// TODO, perhaps render dynamic?
}

void ShadowShapes::AddDebugLines(Point p_a, Point p_b)
{
	// Add line to debug.
	m_staticDebugLines.AddLine(DirectX::XMFLOAT3(p_a.x, 0.2f, p_a.y), DirectX::XMFLOAT3(p_b.x, 0.2f, p_b.y));
}

inline void ShadowShapes::AddUniquePoints(Point p_point)
{
	// Check uniqueness.
	for (unsigned int i = 0; i < m_uniquePoints.size(); i++)
	{
		if (m_uniquePoints[i].x == p_point.x && m_uniquePoints[i].y == p_point.y)
		{
			// If not, break early.
			return;
		}
	}
	
	// If unique, add to list.
	m_uniquePoints.push_back(p_point);
}

std::vector<Point> ShadowShapes::GetUniquePoints()
{
	std::vector<Point> points;

	for (unsigned int i = 0; i < m_uniquePoints.size(); i++)
	{
		points.push_back(m_uniquePoints[i]);
	}

	for (unsigned int i = 0; i < m_uniqueBoundryPoints.size(); i++)
	{
		points.push_back(m_uniqueBoundryPoints[i]);
	}

	return points;
}

std::vector<Point> ShadowShapes::GetBoundryPoints()
{
	return m_uniqueBoundryPoints;
}