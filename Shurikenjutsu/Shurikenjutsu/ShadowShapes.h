#ifndef SHADOWSHAPES
#define SHADOWSHAPES

#include <vector>

#include "Structures.h"
#include "DebugDraw.h"

class ShadowShapes
{
public:
	static ShadowShapes& GetInstance();

	bool Initialize();
	void Shutdown();

	void AddStaticLine(Line p_line);
	void AddStaticShape(std::vector<Line> p_shape);

	int AddDynamicLine(Line p_line);
	int AddDynamicShape(std::vector<Line> p_shape);

	void RemoveDynamicLine(int p_atIndex);
	void RemoveDynamicShape(int p_atIndex, int p_numberOfLines);

	std::vector<Line> GetStaticLines();
	std::vector<Line> GetDynamicLines();

	void DebugRender();

private:
	ShadowShapes() {};
	ShadowShapes(ShadowShapes const&);
	void operator=(ShadowShapes const&);

	std::vector<Line> m_staticLines;
	std::vector<Line> m_dynamicLines;

	DebugLineList m_staticDebugLines;
	std::vector<DebugDot> m_staticDebugDots;
};
#endif