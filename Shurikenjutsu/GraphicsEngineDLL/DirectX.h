#ifndef DIRECTX
#define DIRECTX

#include <D3D11.h>
#include <string>

class DirectXWrapper
{
public:
	DirectXWrapper();
	~DirectXWrapper();
	bool Initialize(HWND p_handle, float m_maxWindowHeight, float m_maxWindowWidth, bool p_fullscreen);
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
	void TurnOnPointLightAlphaBlending();

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

	// GBuffrar
	bool InitializeGBuffer();
	void SetRenderTargetsForGBuffers();
	void ScreenSpaceRenderTarget();
	void ClearRenderTargetsForGBuffers();
	ID3D11ShaderResourceView* GetGBufferSRV1();
	ID3D11ShaderResourceView* GetGBufferSRV2();
	ID3D11ShaderResourceView* GetDepthSRV();

	// Post Processing (SSAO)
	bool InitializePP();
	void SetRenderTargetsForPP1();
	void SetRenderTargetsForPP2();
	ID3D11ShaderResourceView* GetPPSRV1();
	ID3D11ShaderResourceView* GetPPSRV2();
	void ClearPPSRV();

	// Composition
	bool InitializeComposition();
	void SetRenderTargetForComposition();
	ID3D11ShaderResourceView* GetCompositionTexture();

	// Forward render
	void SetRenderTargetForForwardRendering();

	// Dof
	void SetRenderTargetForDOF();
	void DirectXWrapper::SetRenderTargetForDOF2();

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
	ID3D11BlendState* m_pointLightsAlphaEnabled;

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

	// GBuffers
	ID3D11RenderTargetView* m_gBufferRTV[2];
	ID3D11ShaderResourceView* m_gBufferSRV[2];

	//Depth
	ID3D11ShaderResourceView* m_depthSRV;

	// PP (SSAO)
	ID3D11RenderTargetView* m_pPRTV[2];
	ID3D11ShaderResourceView* m_pPSRV[2];

	// Composition
	ID3D11RenderTargetView* m_compositionRTV;
	ID3D11ShaderResourceView* m_compositionSRV;

	float m_maxWindowHeight;
	float m_maxWindowWidth;

};
#endif;