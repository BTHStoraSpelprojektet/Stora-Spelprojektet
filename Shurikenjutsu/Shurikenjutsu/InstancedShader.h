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
	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context);


private:
	ID3D11Buffer* InitializeInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances, std::vector<DirectX::XMFLOAT3> p_position);
	void UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix);

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_samplerState;

	ID3D11RasterizerState* m_rasterizerStateBackCulled;
	ID3D11RasterizerState* m_rasterizerStateNoneCulled;

	std::string m_VSVersion;
	std::string m_PSVersion;

	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;
	DirectX::XMFLOAT4X4 m_lightViewMatrix;
	DirectX::XMFLOAT4X4 m_lightProjectionMatrix;
	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMMATRIX m_worldMatrix;
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;

		DirectX::XMMATRIX m_lightViewMatrix;
		DirectX::XMMATRIX m_lightProjectionMatrix;
	};

	std::vector<ID3D11Buffer*> m_instanceBufferList;
	std::vector<int> m_numberOfInstanceList;
	struct InstancePos
	{
		DirectX::XMFLOAT3 position;
	};
};
#endif