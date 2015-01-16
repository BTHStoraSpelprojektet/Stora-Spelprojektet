#ifndef DEPTHSHADER
#define DEPTHSHADER

#include <D3D11.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <Windows.h>

#include "Structures.h"
#include "ConsoleFunctions.h"

class DepthShader
{
public:
	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context);

	void Shutdown();

	void Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4& p_worldMatrix, ID3D11ShaderResourceView* p_texture);

	void UpdateViewAndProjection(DirectX::XMFLOAT4X4& p_viewMatrix, DirectX::XMFLOAT4X4& p_projectionMatrix);


private:
	void UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4& p_worldMatrix);

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3D11InputLayout* m_layout;

	ID3D11RasterizerState* m_rasterizer;
	ID3D11SamplerState* m_samplerState;

	std::string m_VSVersion;
	std::string m_PSVersion;

	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMFLOAT4X4 m_worldMatrix;
		DirectX::XMFLOAT4X4 m_viewMatrix;
		DirectX::XMFLOAT4X4 m_projectionMatrix;
	};
};
#endif