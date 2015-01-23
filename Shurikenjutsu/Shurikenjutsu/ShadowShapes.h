#ifndef SHADOWSHAPES
#define SHADOWSHAPES

#include "DebugDraw.h"
#include "ConsoleFunctions.h"
#include "Structures.h"

class ShadowShapes
{
public:
	static ShadowShapes& GetInstance();

	bool Initialize();
	void Shutdown();

	void AddStaticLine(Line p_line);
	void AddStaticShape(std::vector<Line> p_shape);
	void AddStaticSquare(Point p_topLeft, Point p_bottomRight);

	int AddDynamicLine(Line p_line);
	int AddDynamicShape(std::vector<Line> p_shape);

	int AddSmokeBombShape(Point p_center);
	void AddMapBoundries(Point p_center, float p_width, float p_height);

	void RemoveDynamicLine(int p_atIndex);
	void RemoveDynamicShape(int p_atIndex, int p_numberOfLines);

	std::vector<Line> GetStaticLines();
	std::vector<Line> GetDynamicLines();

	void DebugRender();

private:
	ShadowShapes() {};
	ShadowShapes(ShadowShapes const&);
	void operator=(ShadowShapes const&);

	void AddDebugLineAndDots(Point p_a, Point p_b);

	std::vector<Line> m_staticLines;
	std::vector<Line> m_dynamicLines;

	DebugLineList m_staticDebugLines;
	std::vector<DebugDot> m_staticDebugDots;
};
#endif