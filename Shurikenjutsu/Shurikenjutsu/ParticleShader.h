#ifndef PARTICLESHADER
#define PARTICLESHADER

#include <d3d11.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#include "ConsoleFunctions.h"

class ParticleShader
{
public:
	bool Initialize(ID3D11Device* p_device);
	void Shutdown();

	void Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, ID3D11Buffer* p_indices, int p_indexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);

	void UpdateViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);

private:
	void UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix);

	std::string m_VSVersion;
	std::string m_PSVersion;

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11SamplerState* m_samplerState;

	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	struct MatrixBuffer
	{
		DirectX::XMFLOAT4X4 m_worldMatrix;
		DirectX::XMFLOAT4X4 m_viewMatrix;
		DirectX::XMFLOAT4X4 m_projectionMatrix;
	};

	struct ParticleVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_UVCoordinates;
		DirectX::XMFLOAT4 m_color;
	};
};
#endif