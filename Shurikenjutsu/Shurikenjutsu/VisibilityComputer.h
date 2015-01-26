#ifndef VISIBILITYCOMPUTER
#define VISIBILITYCOMPUTER

#include "ShadowShapes.h"

struct Intersection
{
	bool intersection;
	Point point;
	float T1;

	Intersection()
	{
		intersection = false;
		point = Point(0.0f, 0.0f);
		T1 = 0.0f;
	}
};

struct BoundingShape
{
	Point m_topLeft;
	Point m_bottomRight;

	BoundingShape()
	{
		m_topLeft = Point(0.0f, 0.0f);
		m_bottomRight = Point(0.0f, 0.0f);
	}

	BoundingShape(Point a, Point b)
	{
		m_topLeft = a;
		m_bottomRight = b;
	}
};

struct PolygonPoint
{
	float m_angle;
	Point m_point;

	PolygonPoint()
	{
		m_angle = 0.0f;
		m_point = Point(0.0f, 0.0f);
	}

	PolygonPoint(float p_angle, Point p_point)
	{
		m_angle = p_angle;
		m_point = p_point;
	}
};

class VisibilityComputer
{
public:
	static VisibilityComputer& GetInstance();

	bool Initialize();
	void Shutdown();

	void UpdateVisibilityPolygon(Point p_viewerPosition);
	void SetBoundryBox(Point p_topLeft, Point p_bottomRight);

	void RenderVisibilityPolygon();
	void RenderReversedVisibilityPolygon();

	bool IsPointVisible(Point p_point);

private:
	VisibilityComputer() {};
	VisibilityComputer(VisibilityComputer const&);
	void operator=(VisibilityComputer const&);

	Intersection GetIntertersectionPoint(Line p_ray, Line p_segment);
	inline std::vector<float> GetUniquePointAngles(Point p_viewerPoint);
	std::vector<PolygonPoint> QuickSortAngles(std::vector<PolygonPoint> p_list, int p_left, int p_right);

	void CalculateVisibilityPolygon();
	void CalculateReversedVisibilityPolygon();

	std::vector<Point> m_intersections;
	DirectX::XMFLOAT4X4 m_worldMatrix;
	ID3D11Buffer* m_mesh;
	int m_vertices;
	BoundingShape m_boundingBox;
};
#endif