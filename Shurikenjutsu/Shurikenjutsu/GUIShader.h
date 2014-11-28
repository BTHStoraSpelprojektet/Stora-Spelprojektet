#ifndef GUISHADER_H_
#define GUISHADER_H_

#include <D3D11.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <Windows.h>
#include <vector>

#include "Structures.h"
#include "ConsoleFunctions.h"

class GUIShader
{
public:
	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context, HWND p_handle);

	void Render(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);

private:
	ID3D11Buffer* InitializeInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances);

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3D11InputLayout* m_layout;

	std::string m_VSVersion;
	std::string m_PSVersion;

	DirectX::XMFLOAT4X4 m_projectionMatrix;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMMATRIX m_worldMatrix;
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;
	};

	ID3D11Buffer* m_instanceBuffer;
	struct InstanceBuffer
	{
		DirectX::XMFLOAT2 m_position;
		DirectX::XMFLOAT4X4 m_scale;
		DirectX::XMFLOAT4X4 m_rotation;
	};

	ID3D11Buffer* m_quadBuffer;
	struct GUIVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_textureCoordinates;
	};
};
#endif