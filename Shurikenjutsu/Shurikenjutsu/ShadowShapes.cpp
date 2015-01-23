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
}

void ShadowShapes::AddStaticLine(Line p_line)
{
	// Add the line to the list.
	m_staticLines.push_back(p_line);
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
	}

	else
	{
		ConsolePrintError("Tried to add an empty shape to the static shadow shapes.");
	}
}

void ShadowShapes::AddStaticSquare(Point p_topLeft, Point p_bottomRight)
{
	// Add top line.
	Line line = Line(p_topLeft, Point(p_bottomRight.x, p_topLeft.y));
	m_staticLines.push_back(line);

	// Add right line.
	line = Line(Point(p_bottomRight.x, p_topLeft.y), p_bottomRight);
	m_staticLines.push_back(line);

	// Add bottom line.
	line = Line(p_bottomRight, Point(p_topLeft.x, p_bottomRight.y));
	m_staticLines.push_back(line);

	// Add left line.
	line = Line(Point(p_topLeft.x, p_bottomRight.y), p_topLeft);
	m_staticLines.push_back(line);
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

	return index;
}

void ShadowShapes::AddMapBoundries(Point p_center, float p_width, float p_height)
{
	// Use static square function.
	AddStaticSquare(Point(p_center.x - p_width, p_center.y + p_height), Point(p_center.x + p_width, p_center.y - p_height));
}

void ShadowShapes::RemoveDynamicLine(int p_atIndex)
{

}

void ShadowShapes::RemoveDynamicShape(int p_atIndex, int p_numberOfLines)
{

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

}