#ifndef RENDERTARGET
#define RENDERTARGET

#include <d3d11.h>

#include "ConsoleFunctions.h"

class RenderTarget
{
public:
	bool Initialize(ID3D11Device* p_device, int p_width, int p_height);

	void Shutdown();

	void SetAsRenderTarget(ID3D11DeviceContext* p_deviceContext);
	void Clear(ID3D11DeviceContext* p_deviceContext);

	ID3D11ShaderResourceView* GetRenderTarget();

private:
	ID3D11Texture2D* m_renderTarget;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11ShaderResourceView* m_resourceView;

	ID3D11Texture2D* m_depthStencil;
	ID3D11DepthStencilView*	m_depthStencilView;
};
#endif