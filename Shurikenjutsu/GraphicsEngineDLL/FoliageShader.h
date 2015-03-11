#ifndef FOLIAGESHADER
#define FOLIAGESHADER

#include <d3d11.h>
#include <DirectXMath.h>

#include <string>
#include <vector>

class FoliageShader
{
public:
	bool Initialize(ID3D11Device* p_device);
	void Shutdown();

	void Render(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* m_shadowMap);

	void UpdateViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	void UpdateLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);

private:
	void UpdateConstantBuffer(ID3D11DeviceContext* p_context);
	void UpdateAngleBuffer(ID3D11DeviceContext* p_context);
	void ReadRawFile();

	std::string m_VSVersion;
	std::string m_GSVersion;
	std::string m_PSVersion;

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11GeometryShader* m_geometryShader;

	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_samplerState;

	ID3D11Buffer* m_matrixBuffer;
	ID3D11Buffer* m_angleBuffer;

	DirectX::XMFLOAT4X4 m_worldMatrix;
	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	ID3D11Buffer* m_vertexBuffer;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	DirectX::XMFLOAT4X4 m_lightViewMatrix;
	DirectX::XMFLOAT4X4 m_lightProjectionMatrix;

	struct MatrixBuffer
	{
		DirectX::XMFLOAT4X4 m_worldMatrix;
		DirectX::XMFLOAT4X4 m_viewMatrix;
		DirectX::XMFLOAT4X4 m_projectionMatrix;

		DirectX::XMFLOAT4X4 m_lightViewMatrix;
		DirectX::XMFLOAT4X4 m_lightProjectionMatrix;
	};

	struct AngleBuffer
	{
		DirectX::XMFLOAT4 m_rotation;
	};

	struct FoliageVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_offset;
	};

	std::vector<FoliageVertex> m_vertices;
	float m_angle;
};
#endif