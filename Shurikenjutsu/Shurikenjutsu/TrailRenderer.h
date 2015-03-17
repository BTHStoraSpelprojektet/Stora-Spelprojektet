#ifndef TRAILRENDERER
#define TRAILRENDERER

#include <d3d11.h>
#include <DirectXMath.h>
#include <vector>

class Trail;

struct TrailPoint
{
	DirectX::XMFLOAT3 m_position;
	float m_angle;
	float m_width;
	DirectX::XMFLOAT2 m_timeValues;
	DirectX::XMFLOAT4 m_color;
	float m_endpoint;
};

class TrailRenderer
{
public:
	static TrailRenderer& GetInstance();

	bool Initialize(ID3D11Device* p_device);
	void Shutdown();

	void AddTrail(Trail* p_trail);
	void RenderTrails();

	void SetWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix);
	void SetViewMatrix(DirectX::XMFLOAT4X4 p_viewMatrix);
	void SetProjectionMatrix(DirectX::XMFLOAT4X4 p_projectionMatrix);

	DirectX::XMFLOAT4X4 GetWorldMatrix();
	DirectX::XMFLOAT4X4 GetViewMatrix();
	DirectX::XMFLOAT4X4 GetProjectionMatrix();

private:
	TrailRenderer() {};
	TrailRenderer(TrailRenderer const&);
	void operator=(TrailRenderer const&);

	void UpdateMatrixes();
	std::vector<unsigned char> ReadShaderData(std::string p_fileName);

	std::string m_VSVersion;
	std::string m_GSVersion;
	std::string m_PSVersion;

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11GeometryShader* m_geometryShader;

	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11SamplerState* m_samplerState;

	DirectX::XMFLOAT4X4 m_worldMatrix;
	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	std::vector<Trail*> m_trails;

	struct MatrixBuffer
	{
		DirectX::XMFLOAT4X4 m_worldMatrix;
		DirectX::XMFLOAT4X4 m_viewMatrix;
		DirectX::XMFLOAT4X4 m_projectionMatrix;
	};
};
#endif