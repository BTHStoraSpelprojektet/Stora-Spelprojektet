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
	void Render(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_color, ID3D11ShaderResourceView* p_depth);
	
	void UpdateFrameBuffer(ID3D11DeviceContext* p_context, DirectionalLight& p_dlight, DirectX::XMFLOAT4X4 p_projection);

private:
	
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	std::string m_VSVersion;
	std::string m_PSVersion;

	ID3D11Buffer* m_frameBuffer;
	struct FrameBuffer
	{
		DirectionalLight m_directionalLight;
		DirectX::XMFLOAT4X4 m_projection;
	};
};
#endif