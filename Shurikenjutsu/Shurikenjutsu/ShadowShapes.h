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
	void UpdateBoundries(Point p_topLeft, Point p_bottomRight);

	void RemoveDynamicLine(int p_atIndex);
	void RemoveDynamicShape(int p_atIndex, int p_numberOfLines);

	std::vector<Line> GetBoundryLines();
	std::vector<Line> GetStaticLines(Point a, Point b);
	std::vector<Line> GetDynamicLines();

	std::vector<Point> GetUniquePoints();
	std::vector<Point> GetBoundryPoints();

	void DebugRender();

private:
	ShadowShapes() {};
	ShadowShapes(ShadowShapes const&);
	void operator=(ShadowShapes const&);

	void AddDebugLines(Point p_a, Point p_b);
	inline void AddUniquePoints(Point p_point);

	std::vector<Line> m_boundries;
	std::vector<Line> m_staticLines;
	std::vector<Line> m_dynamicLines;
	std::vector<Point> m_uniquePoints; 
	std::vector<Point> m_uniqueBoundryPoints;
	
	DebugLineList m_staticDebugLines;
};
#endif