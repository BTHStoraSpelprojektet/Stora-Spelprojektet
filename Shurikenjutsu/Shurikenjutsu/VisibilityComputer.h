#ifndef VISIBILITYCOMPUTER
#define VISIBILITYCOMPUTER

#include "ShadowShapes.h"

struct Intersection
{
	bool intersection;
	Point point;
	float T1;
};

class VisibilityComputer
{
public:
	static VisibilityComputer& GetInstance();

	bool Initialize();
	void Shutdown();

	void UpdateVisibilityPolygon(Point p_viewerPosition, Point p_picked);

	void RenderVisibilityPolygon();
	void RenderReversedVisibilityPolygon();

	bool IsPointVisible(Point p_point);

private:
	VisibilityComputer() {};
	VisibilityComputer(VisibilityComputer const&);
	void operator=(VisibilityComputer const&);

	Intersection GetIntertersectionPoint(Line p_ray, Line p_segment);

	void CalculateReversedVisibilityPolygon();

	DirectX::XMFLOAT4X4 m_worldMatrix;
	ID3D11Buffer* m_mesh;
	int m_vertices;

	// TODO, temp.
	DebugDot m_dot;
};
#endif