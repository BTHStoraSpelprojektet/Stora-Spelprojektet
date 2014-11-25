#ifndef INSTANCEDSHADER
#define INSTANCEDSHADER

#include <D3D11.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <Windows.h>
#include <vector>

#include "Structures.h"
#include "ConsoleFunctions.h"

class InstancedShader
{
public:
	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context, HWND p_handle, int p_numberOfIUnstances);

	void Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMMATRIX& p_worldMatrix, ID3D11ShaderResourceView* p_texture);

	void UpdateViewAndProjection(DirectX::XMMATRIX& p_viewMatrix, DirectX::XMMATRIX& p_projectionMatrix);
	void UpdateFogBuffer(ID3D11DeviceContext* p_context, float p_fogStart, float p_fogEnd, float p_fogDensity);

	void TurnOnBackFaceCulling(ID3D11DeviceContext* p_context);
	void TurnOffBackFaceCulling(ID3D11DeviceContext* p_context);

private:
	void UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMMATRIX& p_worldMatrix);

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_samplerState;

	ID3D11RasterizerState* m_rasterizerStateBackCulled;
	ID3D11RasterizerState* m_rasterizerStateNoneCulled;

	std::string m_VSVersion;
	std::string m_PSVersion;

	DirectX::XMMATRIX m_viewMatrix;
	DirectX::XMMATRIX m_projectionMatrix;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMMATRIX m_worldMatrix;
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;
	};

	ID3D11Buffer* m_fogBuffer;
	struct FogBuffer
	{
		float m_fogStart;
		float m_fogEnd;
		float m_fogDensity;
		float m_padding;
	};

	ID3D11Buffer* m_instanceBuffer;
	struct InstancePos
	{
		DirectX::XMFLOAT3 position;
	};
	//std::vector<InstancePos> m_instances;
	int m_numberOfObjects;
};
#endif