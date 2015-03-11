#ifndef SHADOWSHAPES
#define SHADOWSHAPES

#include "..\CommonLibs\CommonStructures.h"
class DebugLineList;


struct SmokeBombShadowShape
{
	bool m_alive;

	Point m_uniquePoints[4];
	Line m_segments[4];

	float m_timePassed;
	float m_timeToLive;
};

class ShadowShapes
{
public:
	static ShadowShapes* GetInstance();

	bool Initialize();
	void Shutdown();

	void AddStaticLine(Line p_line);
	void AddStaticShape(std::vector<Line> p_shape);
	void AddStaticSquare(Point p_topLeft, Point p_bottomRight);
	void AddSmokeBombShape(Point p_center, float p_deltaTime);

	void UpdateBoundries(Point p_topLeft, Point p_bottomRight);
	void Update(float p_deltaTime);
	
	std::vector<Line> GetStaticLines(Point a, Point b);
	std::vector<Point> GetUniquePoints(Point a, Point b);

	std::vector<Point> GetBoundryPoints();
	std::vector<Line> GetBoundryLines();

	void clearStaticLines();

	void DebugRender();

private:

	static ShadowShapes* m_instance;
	ShadowShapes() {};
	ShadowShapes(ShadowShapes const&);
	void operator=(ShadowShapes const&);

	void AddDebugLines(Point p_a, Point p_b);
	inline void AddUniquePoints(Point p_point);

	std::vector<Line> m_boundries;
	std::vector<Line> m_staticLines;
	std::vector<Point> m_uniquePoints; 
	std::vector<Point> m_uniqueBoundryPoints;
	std::vector<SmokeBombShadowShape> m_smokeBombs;
	
	DebugLineList *m_staticDebugLines;
};
#endif