#ifndef DIRECTX
#define DIRECTX

#include <D3D11.h>

class DirectXWrapper
{
public:
	bool Initialize(HWND p_handle);
	void Clear();
	void Present();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	D3D_FEATURE_LEVEL GetVersion();
	IDXGISwapChain* GetSwapChain();

	void TurnOnAlphaBlending();
	void TurnOffAlphaBlending();

	void TurnOnDepthStencil();
	void TurnOffDepthStencil();

	void SetClearColor(float R, float G, float B, float p_opacity);

	void ResetRenderTarget();

	bool InitializeOutlinging();

private:
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_context;

	D3D_FEATURE_LEVEL m_version;

	IDXGISwapChain*	m_swapChain;
	D3D11_VIEWPORT m_viewPort;
	ID3D11RenderTargetView*	m_renderTarget;
	ID3D11Texture2D* m_depthStencil;
	ID3D11Texture2D* m_depthStencilOutlining;
	ID3D11DepthStencilView*	m_depthStencilView;
	ID3D11DepthStencilView*	m_depthStencilViewOutlining;

	ID3D11BlendState* m_alphaEnabled;
	ID3D11BlendState* m_alphaDisabled;

	ID3D11DepthStencilState* m_depthEnabled;
	ID3D11DepthStencilState* m_depthDisabled;
	ID3D11DepthStencilState* m_depthDisabledOutlining;
	ID3D11DepthStencilState* m_depthEnabledOutlining;

	int	m_width;
	int m_height;

	float m_clearColor[4];
};
#endif;