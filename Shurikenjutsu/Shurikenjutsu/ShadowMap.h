#ifndef SHADOWMAP
#define SHADOWMAP

#include <d3d11.h>

#include "ConsoleFunctions.h"

class ShadowMap
{
public:
	bool Initialize(ID3D11Device* p_device, int p_width, int p_height);

	void Shutdown();

	void SetAsRenderTarget(ID3D11DeviceContext* p_deviceContext);
	void Clear(ID3D11DeviceContext* p_deviceContext);

	ID3D11ShaderResourceView* GetShadowMap();

private:
	ID3D11Texture2D* m_shadowMap;
	ID3D11RenderTargetView* m_shadowMapTargetView;
	ID3D11ShaderResourceView* m_shadowMapResourceView;

	ID3D11Texture2D* m_depthStencil;
	ID3D11DepthStencilView*	m_depthStencilView;
};
#endif