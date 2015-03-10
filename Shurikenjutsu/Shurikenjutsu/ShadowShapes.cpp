#include "ShadowShapes.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "Globals.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include "VisibilityComputer.h"

ShadowShapes& ShadowShapes::GetInstance()
{
	static ShadowShapes instance;

	return instance;
}

bool ShadowShapes::Initialize()
{
	m_boundries.clear();
	m_staticLines.clear();
	m_uniquePoints.clear();
	m_uniqueBoundryPoints.clear();

	m_staticDebugLines.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));

	return true;
}

void ShadowShapes::Shutdown()
{
	m_boundries.clear();
	m_staticLines.clear();
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

void ShadowShapes::clearStaticLines(){
	m_staticLines.clear();
	m_uniquePoints.clear();
	m_staticDebugLines.Shutdown();
	m_staticDebugLines.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));
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

void ShadowShapes::AddSmokeBombShape(Point p_center)
{
	SmokeBombShadowShape smokebomb;

	smokebomb.m_alive = true;

	smokebomb.m_uniquePoints[0] = Point(p_center.x, p_center.y + 3.5f);
	smokebomb.m_uniquePoints[1] = Point(p_center.x + 3.5f, p_center.y);
	smokebomb.m_uniquePoints[2] = Point(p_center.x, p_center.y - 3.5f);
	smokebomb.m_uniquePoints[3] = Point(p_center.x - 3.5f, p_center.y);

	smokebomb.m_segments[0] = Line(smokebomb.m_uniquePoints[0], smokebomb.m_uniquePoints[1]);
	smokebomb.m_segments[1] = Line(smokebomb.m_uniquePoints[1], smokebomb.m_uniquePoints[2]);
	smokebomb.m_segments[2] = Line(smokebomb.m_uniquePoints[2], smokebomb.m_uniquePoints[3]);
	smokebomb.m_segments[3] = Line(smokebomb.m_uniquePoints[3], smokebomb.m_uniquePoints[0]);

	smokebomb.m_timePassed = 0.0f;
	smokebomb.m_timeToLive = SMOKEBOMB_DURATION + 0.5f;

	m_smokeBombs.push_back(smokebomb);

	VisibilityComputer::GetInstance().UpdateVisibilityPolygon(VisibilityComputer::GetInstance().GetLastPosition(), GraphicsEngine::GetInstance()->GetDevice());
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

void ShadowShapes::Update()
{
	float dt = (float)GLOBAL::GetInstance().GetDeltaTime();

	// Add delta time to all smokebombs.
	for (unsigned int i = 0; i < m_smokeBombs.size(); i++)
	{
		m_smokeBombs[i].m_timePassed += dt;

		if (m_smokeBombs[i].m_timePassed > m_smokeBombs[i].m_timeToLive)
		{
			m_smokeBombs[i].m_alive = false;
		}
	}

	bool deletedThisFrame = false;

	// Clear old smokebombs.
	for (unsigned int i = m_smokeBombs.size(); i-- > 0;)
	{
		if (!m_smokeBombs[i].m_alive)
		{
			m_smokeBombs.erase(m_smokeBombs.begin() + i);

			deletedThisFrame = true;
		}
	}

	if (deletedThisFrame)
	{
		VisibilityComputer::GetInstance().UpdateVisibilityPolygon(VisibilityComputer::GetInstance().GetLastPosition(), GraphicsEngine::GetInstance()->GetDevice());
	}
}

std::vector<Line> ShadowShapes::GetBoundryLines()
{
	return m_boundries;
}

std::vector<Line> ShadowShapes::GetStaticLines(Point a, Point b)
{
	std::vector<Line> list;

	// Add boundries.
	for (unsigned int i = 0; i < m_boundries.size(); i++)
	{
		list.push_back(m_boundries[i]);
	}

	for (unsigned int i = 0; i < m_staticLines.size(); i++)
	{
		if ((m_staticLines[i].a.x >= a.x && m_staticLines[i].a.x <= b.x && m_staticLines[i].a.y <= a.y && m_staticLines[i].a.y >= b.y) && (m_staticLines[i].b.x >= a.x && m_staticLines[i].b.x <= b.x && m_staticLines[i].b.y <= a.y && m_staticLines[i].b.y >= b.y))
		{
				list.push_back(m_staticLines[i]);
		}
	}

	for (unsigned int i = 0; i < m_smokeBombs.size(); i++)
	{
		if (m_smokeBombs[i].m_uniquePoints[3].x > a.x || m_smokeBombs[i].m_uniquePoints[1].x < b.x || m_smokeBombs[i].m_uniquePoints[0].y < a.y || m_smokeBombs[i].m_uniquePoints[2].y > b.y)
		{
			list.push_back(m_smokeBombs[i].m_segments[0]);
			list.push_back(m_smokeBombs[i].m_segments[1]);
			list.push_back(m_smokeBombs[i].m_segments[2]);
			list.push_back(m_smokeBombs[i].m_segments[3]);
		}
	}

	return list;
}

void ShadowShapes::DebugRender()
{
	// Render every static line.
	m_staticDebugLines.Render();
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

std::vector<Point> ShadowShapes::GetUniquePoints(Point a, Point b)
{
	std::vector<Point> points;

	// Add boundries.
	for (unsigned int i = 0; i < m_uniqueBoundryPoints.size(); i++)
	{
		points.push_back(m_uniqueBoundryPoints[i]);
	}

	// Add the points inside the boundries.
	for (unsigned int i = 0; i < m_uniquePoints.size(); i++)
	{
		if (m_uniquePoints[i].x > a.x && m_uniquePoints[i].x < b.x && m_uniquePoints[i].y < a.y && m_uniquePoints[i].y > b.y)
		{
			points.push_back(m_uniquePoints[i]);
		}
	}

	for (unsigned int i = 0; i < m_smokeBombs.size(); i++)
	{
		if (m_smokeBombs[i].m_uniquePoints[3].x > a.x || m_smokeBombs[i].m_uniquePoints[1].x < b.x || m_smokeBombs[i].m_uniquePoints[0].y < a.y || m_smokeBombs[i].m_uniquePoints[2].y > b.y)
		{
			points.push_back(m_smokeBombs[i].m_uniquePoints[0]);
			points.push_back(m_smokeBombs[i].m_uniquePoints[1]);
			points.push_back(m_smokeBombs[i].m_uniquePoints[2]);
			points.push_back(m_smokeBombs[i].m_uniquePoints[3]);
		}
	}

	return points;
}

std::vector<Point> ShadowShapes::GetBoundryPoints()
{
	return m_uniqueBoundryPoints;
}