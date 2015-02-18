#ifndef DIRECTX
#define DIRECTX

#include <D3D11.h>
#include <string>

class DirectXWrapper
{
public:
	bool Initialize(HWND p_handle);
	void Shutdown();
	void Clear();
	void ClearOutlining();
	void Present();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	D3D_FEATURE_LEVEL GetVersion();
	IDXGISwapChain* GetSwapChain();

	void TurnOnAlphaBlending();
	void TurnOffAlphaBlending();

	void TurnOnDepthStencil();
	void TurnOffDepthStencil();
	void SetDepthStateForParticles();

	void SetClearColor(float R, float G, float B, float p_opacity);

	void ResetRenderTarget();

	void SetVsync(bool p_state);

	bool InitializeOutlinging();
	void SetOutliningPassOne();
	void SetOutliningPassTwo();

	void DoReportLiveObjects();
	void SetDebugName(ID3D11DeviceChild* child, const std::string& name);

	bool InitializePostProcessing();

	void SetRenderTargetsForGBuffers();
	void ClearRenderTargetsForGBuffers();
	ID3D11ShaderResourceView* GetPostProcessingSRV1();
	ID3D11ShaderResourceView* GetPostProcessingSRV2();

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
	ID3D11DepthStencilState* m_depthStateParticles;
	ID3D11DepthStencilState* m_outliningALWAYS;
	ID3D11DepthStencilState* m_outliningNOTEQUAL;

	ID3D11Debug *d3dDebug;

	int	m_width;
	int m_height;

	float m_clearColor[4];

	int m_vsync;

	// POST PROCESSING STUFF
	ID3D11RenderTargetView* m_postProcessingRTV[2];
	ID3D11ShaderResourceView* m_postProcessingSRV[2];
};
#endif;