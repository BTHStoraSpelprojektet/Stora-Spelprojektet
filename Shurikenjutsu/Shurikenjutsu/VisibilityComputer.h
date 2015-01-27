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

	bool Initialize(ID3D11Device* p_device);
	void Shutdown();

	void UpdateVisibilityPolygon(Point p_viewerPosition, ID3D11Device* p_device);
	void SetBoundryBox(Point p_topLeft, Point p_bottomRight);

	void RenderVisibilityPolygon(ID3D11DeviceContext* p_context);

	bool IsPointVisible(Point p_point);

	void SetReversedRenderMode(bool p_value);

	void SetMatrices(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);

private:
	VisibilityComputer() {};
	VisibilityComputer(VisibilityComputer const&);
	void operator=(VisibilityComputer const&);

	Intersection GetIntertersectionPoint(Line p_ray, Line p_segment);
	inline std::vector<float> GetUniquePointAngles(Point p_viewerPoint);

	void QuickSortAngles(std::vector<PolygonPoint>& p_list);
	void QuickSortAngles(std::vector<PolygonPoint>& p_list, int p_left, int p_right);

	void CalculateVisibilityPolygon(Point p_viewerPosition, ID3D11Device* p_device);
	void CalculateReversedVisibilityPolygon(ID3D11Device* p_device);

	void UpdateMatrices(ID3D11DeviceContext* p_context);

	std::vector<Point> m_intersections;
	std::vector<DirectX::XMFLOAT3> m_vertices;

	BoundingShape m_boundingBox;

	std::string m_VSVersion;
	std::string m_PSVersion;
	
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_mesh;
	ID3D11Buffer* m_reversedMesh;

	DirectX::XMFLOAT4X4 m_worldMatrix;
	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMMATRIX m_worldMatrix;
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;
	};

	bool m_renderReversed;
	bool m_render;
};
#endif