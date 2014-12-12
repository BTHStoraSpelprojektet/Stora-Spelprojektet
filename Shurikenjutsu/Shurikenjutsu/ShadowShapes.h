#ifndef SHADOWSHAPES
#define SHADOWSHAPES

#include <DirectXMath.h>
#include <vector>

#include "Structures.h"
#include "DebugDraw.h"

// Singleton class.
class ShadowShapes
{
public:
	static ShadowShapes& GetInstance();

	void AddShadowShape(ShadowShape p_shadowShape);
	void RemoveShadowShape(unsigned int p_index);

	void DebugRender();

private:
	ShadowShapes() {};
	ShadowShapes(ShadowShapes const&);
	void operator=(ShadowShapes const&);

	std::vector<ShadowShape> m_shadowShapes;

	std::vector<DebugShape2D> m_debugShapes;
	std::vector<DebugDot> m_debugDots;
};
#endif