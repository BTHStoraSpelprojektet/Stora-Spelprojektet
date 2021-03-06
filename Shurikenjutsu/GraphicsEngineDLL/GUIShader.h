#ifndef GUISHADER_H_
#define GUISHADER_H_

#include <D3D11.h>
#include <Windows.h>
#include <vector>
#include <DirectXMath.h>

class GUIShader
{
public:
	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context);

	void Shutdown();

	void Render(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, float p_currentScreenWidth, float p_currentScreenHeight, float p_opacity);
	void PrepareRender(ID3D11DeviceContext* p_context);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_samplerState;

	std::string m_VSVersion;
	std::string m_PSVersion;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMFLOAT4X4 m_worldMatrix;
		DirectX::XMFLOAT4X4 m_projectionMatrix;
		float m_opacity;
		DirectX::XMFLOAT3 m_padding;
	};

	ID3D11Buffer* m_quadBuffer;
	struct GUIVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_textureCoordinates;
	};
};
#endif