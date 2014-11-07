#ifndef DIRECTX
#define DIRECTX

#include <D3D11.h>
#include "ConsoleFunctions.h"

class DirectX
{
public:
	bool Initialize(HWND p_handle);
	void Clear();
	void Present();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	D3D_FEATURE_LEVEL GetVersion();

	void SetClearColor(float R, float G, float B, float p_opacity);

private:
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_context;

	D3D_FEATURE_LEVEL m_version;

	IDXGISwapChain*	m_swapChain;
	ID3D11RenderTargetView*	m_renderTarget;
	ID3D11Texture2D* m_depthStencil;
	ID3D11DepthStencilView*	m_depthStencilView;

	int	m_width;
	int m_height;

	float m_clearColor[4];
};
#endif;