#ifndef VISIBILITYCOMPUTER
#define VISIBILITYCOMPUTER

#define WIN32_LEAN_AND_MEAN

#include "ShadowShapes.h"
#include "RenderTarget.h"

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

	void UpdateTextureSize(int p_width, int p_height);
	void UpdateVisibilityPolygon(Point p_viewerPosition, ID3D11Device* p_device);
	void UpdateMapBoundries(Point p_topLeft, Point p_bottomRight);

	void RenderVisibilityPolygon(ID3D11DeviceContext* p_context);

	bool IsPointVisible(Point p_point);

	void SetWorldPolygonMatrix(DirectX::XMFLOAT4X4 p_worldMatrix);
	void SetViewPolygonMatrix(DirectX::XMFLOAT4X4 p_viewMatrix);
	void SetProjectionPolygonMatrix(DirectX::XMFLOAT4X4 p_projectionMatrix);

	DirectX::XMFLOAT4X4 GetWorldPolygonMatrix();
	DirectX::XMFLOAT4X4 GetViewPolygonMatrix();
	DirectX::XMFLOAT4X4 GetProjectionPolygonMatrix();

	ID3D11ShaderResourceView* GetRenderTarget();
	ID3D11ShaderResourceView* GetMinimapTarget();

	void RebuildQuad(Point p_topLeft, Point p_bottomRight);

	Point GetLastPosition();

private:
	VisibilityComputer() {};
	VisibilityComputer(VisibilityComputer const&);
	void operator=(VisibilityComputer const&);

	Intersection GetIntertersectionPoint(Line p_ray, Line p_segment);
	inline std::vector<float> GetUniquePointAngles(Point p_viewerPoint);
	bool IsPointInPolygon(Point p_point, std::vector<Point> p_polygon);

	void QuickSortAngles(std::vector<PolygonPoint>& p_list);
	void QuickSortAngles(std::vector<PolygonPoint>& p_list, int p_left, int p_right);

	void CalculateVisibilityPolygon(Point p_viewerPosition, ID3D11Device* p_device);
	void CalculateReversedVisibilityPolygon(ID3D11DeviceContext* p_context);

	void UpdatePolygonMatrices(ID3D11DeviceContext* p_context);

	std::vector<Point> m_intersections;
	std::vector<DirectX::XMFLOAT3> m_vertices;

	BoundingShape m_boundingBox;
	Point m_lastPosition;

	std::string m_VSVersion;
	std::string m_PSVersion;
	
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_mesh;
	ID3D11Buffer* m_quadMesh;

	DirectX::XMFLOAT4X4 m_quadWorldMatrix;
	DirectX::XMFLOAT4X4 m_polygonWorldMatrix;
	DirectX::XMFLOAT4X4 m_polygonViewMatrix;
	DirectX::XMFLOAT4X4 m_polygonProjectionMatrix;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMMATRIX m_worldMatrix;
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;
	};

	RenderTarget m_renderTarget; 
	RenderTarget m_minimapTarget;
	ID3D11ShaderResourceView* m_texture;
};
#endif