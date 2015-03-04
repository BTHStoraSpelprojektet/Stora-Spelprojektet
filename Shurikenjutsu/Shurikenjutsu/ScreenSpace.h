#ifndef SCREENSPACE_H_
#define SCREENSPACE_H_

#include <D3D11.h>
#include <vector>
#include "Structures.h"

class ScreenSpace
{
public:
	ScreenSpace();
	~ScreenSpace();

	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context);

	void Shutdown();
	void Render(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_color, ID3D11ShaderResourceView* p_depth, ID3D11ShaderResourceView* p_ssao);
	void RenderLights(ID3D11DeviceContext* p_context);
	void RenderSSAO(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_depth);
	void BlurImage(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_depth, ID3D11ShaderResourceView* p_normal, bool p_horizontal);

	void DOF(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_depth, bool p_horizontal);
	void UpdateFrameBuffer(ID3D11DeviceContext* p_context, DirectionalLight& p_dlight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view);
	void UpdateSSAOBuffer(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_projection);
	void SetLightBuffer(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_lightSRV);

private:
	
	void BuildRandomVec(ID3D11Device* p_device, ID3D11DeviceContext* p_context);
	void BuildOffsetVectors();
	bool InitializeSSAO(ID3D11Device* p_device, ID3D11DeviceContext* p_context);
	bool InitializeDOF(ID3D11Device* p_device, ID3D11DeviceContext* p_context);

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3D11VertexShader* m_quadVertexShader;
	ID3D11GeometryShader* m_quadGeometryShader;
	ID3D11PixelShader* m_quadPixelShader;

	std::string m_VSVersion;
	std::string m_GSVersion;
	std::string m_PSVersion;

	ID3D11Buffer* m_frameBuffer;
	struct FrameBuffer
	{
		DirectionalLight m_directionalLight;
		DirectX::XMFLOAT4X4 m_projection;
	};

	// SSAO
	ID3D11PixelShader* m_pixelShaderSSAO;
	ID3D11PixelShader* m_pixelShaderSSAOBlurH;
	ID3D11PixelShader* m_pixelShaderSSAOBlurV;

	ID3D11Buffer* m_ssaoBuffer;
	struct SSAOCB
	{
		DirectX::XMFLOAT4X4 m_projection;
		DirectX::XMFLOAT4X4 m_T;
		DirectX::XMFLOAT4 m_offsetVectors[14];
	};

	ID3D11ShaderResourceView* m_randomVectors;
	DirectX::XMFLOAT4 m_offsetVectors[14];

	ID3D11SamplerState* m_samplerDepth;
	ID3D11SamplerState* m_samplerRandom;
	ID3D11SamplerState* m_samplerBlur;

	DirectX::XMFLOAT4X4 T;

	// DOF
	ID3D11PixelShader* m_pixelShaderDOFBlurH;
	ID3D11PixelShader* m_pixelShaderDOFBlurV;

};
#endif