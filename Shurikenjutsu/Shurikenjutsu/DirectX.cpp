#include "DirectX.h"

bool DirectXWrapper::Initialize(HWND p_handle)
{
	HRESULT result = S_OK;

	m_clearColor[0] = 0.0f;
	m_clearColor[1] = 0.0f;
	m_clearColor[2] = 0.0f;
	m_clearColor[3] = 0.0f;

	m_device = 0;
	m_context = 0;

	// Get the window size.
	RECT window;
	GetClientRect(p_handle, &window);
	m_width = (window.right - window.left);
	m_height = (window.bottom - window.top);

	// Initialize swap chain.
	DXGI_SWAP_CHAIN_DESC swapChainDescription;
	ZeroMemory(&swapChainDescription, sizeof(swapChainDescription));
	swapChainDescription.BufferCount = 1;
	swapChainDescription.BufferDesc.Width = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
	swapChainDescription.BufferDesc.Height = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
	swapChainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDescription.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDescription.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDescription.OutputWindow = p_handle;
	swapChainDescription.SampleDesc.Count = 1;
	swapChainDescription.SampleDesc.Quality = 0;

	if (GLOBAL::GetInstance().FULLSCREEN)
	{
		swapChainDescription.Windowed = FALSE;
	}

	else
	{
		swapChainDescription.Windowed = TRUE;
	}
	
	
	// DirectX versions to try and initialize.
	D3D_FEATURE_LEVEL versions[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};
	m_version = versions[0];

	// Create the swap chain and device.
	if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, versions, ARRAYSIZE(versions), D3D11_SDK_VERSION, &swapChainDescription, &m_swapChain, &m_device, &m_version, &m_context)))
	{
		ConsolePrintErrorAndQuit("DirectX swap chain and device failed to create.");
		return false;
	}

	// Retrieve the backbuffer texture from the swap chain.
	ID3D11Texture2D* backBuffer = NULL;
	if (FAILED(m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer)))
	{
		ConsolePrintErrorAndQuit("DirectX back buffer failed to be retrieved.");
		return false;
	}

	// Create render target.
	if (FAILED(m_device->CreateRenderTargetView(backBuffer, NULL, &m_renderTarget)))
	{
		ConsolePrintErrorAndQuit("DirectX render target failed to create.");
		return false;
	}

	// Release the back buffer.
	backBuffer->Release();

	D3D11_DEPTH_STENCIL_DESC depthState;
	depthState.DepthEnable = true;
	depthState.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthState.DepthFunc = D3D11_COMPARISON_LESS;
	depthState.StencilEnable = true;
	depthState.StencilReadMask = 0xFF;
	depthState.StencilWriteMask = 0xFF;
	depthState.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthState.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthState.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthState.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	depthState.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthState.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthState.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthState.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Create depth stencil state
	if (FAILED(m_device->CreateDepthStencilState(&depthState, &m_depthEnabled)))
	{
		ConsolePrintErrorAndQuit("DirectX depth stencil enabled state failed to create.");
		return false;
	}

	depthState.DepthEnable = false;
	depthState.StencilEnable = false;

	if (FAILED(m_device->CreateDepthStencilState(&depthState, &m_depthDisabled)))
	{
		ConsolePrintErrorAndQuit("DirectX depth stencil disabled state failed to create.");
		return false;
	}

	// Initialize the depth stencil.
	D3D11_TEXTURE2D_DESC depthStencilDescription;
	ZeroMemory(&depthStencilDescription, sizeof(depthStencilDescription));
	depthStencilDescription.Width = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
	depthStencilDescription.Height = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
	depthStencilDescription.MipLevels = 1;
	depthStencilDescription.ArraySize = 1;
	depthStencilDescription.Format = DXGI_FORMAT_D32_FLOAT;
	depthStencilDescription.SampleDesc.Count = 1;
	depthStencilDescription.SampleDesc.Quality = 0;
	depthStencilDescription.Usage = D3D11_USAGE_DEFAULT;
	depthStencilDescription.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilDescription.CPUAccessFlags = 0;
	depthStencilDescription.MiscFlags = 0;

	// Create depth stencil texture.
	if (FAILED(m_device->CreateTexture2D(&depthStencilDescription, NULL, &m_depthStencil)))
	{
		ConsolePrintErrorAndQuit("DirectX depth stencil failed to create.");
		return false;
	}

	// Initialize the depth stencil view.
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDescription;
	ZeroMemory(&depthStencilViewDescription, sizeof(depthStencilViewDescription));
	depthStencilViewDescription.Format = depthStencilViewDescription.Format;
	depthStencilViewDescription.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDescription.Texture2D.MipSlice = 0;

	// Create the depth stencil view.
	if (FAILED(m_device->CreateDepthStencilView(m_depthStencil, &depthStencilViewDescription, &m_depthStencilView)))
	{
		ConsolePrintErrorAndQuit("DirectX depth stencil view failed to create.");
		return false;
	}

	// Set device render target.
	m_context->OMSetRenderTargets(1, &m_renderTarget, m_depthStencilView);

	// Initialize the view port.
	ZeroMemory(&m_viewPort, sizeof(m_viewPort));
	m_viewPort.Width = (float)GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
	m_viewPort.Height = (float)GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
	m_viewPort.MinDepth = 0.0f;
	m_viewPort.MaxDepth = 1.0f;
	m_viewPort.TopLeftX = 0;
	m_viewPort.TopLeftY = 0;

	// Create the view port.
	m_context->RSSetViewports(1, &m_viewPort);

	// Clear the render target.
	Clear();

	// Create an alpha enabled blend state description.
	D3D11_BLEND_DESC blendState;
	ZeroMemory(&blendState, sizeof(D3D11_BLEND_DESC));

	blendState.RenderTarget[0].BlendEnable = TRUE;
	blendState.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendState.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	blendState.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	blendState.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendState.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	blendState.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	blendState.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	// Create the alpha blend state.
	if (FAILED(m_device->CreateBlendState(&blendState, &m_alphaEnabled)))
	{
		ConsolePrintErrorAndQuit("DirectX alpha enabled blend state failed to create.");
		return false;
	}

	blendState.RenderTarget[0].BlendEnable = FALSE;

	if (FAILED(m_device->CreateBlendState(&blendState, &m_alphaDisabled)))
	{
		ConsolePrintErrorAndQuit("DirectX alpha disabled blend state failed to create.");
		return false;
	}

	IDXGIDevice* device;
	m_device->QueryInterface(__uuidof(IDXGIDevice), (void **)&device);

	IDXGIAdapter* adapter;
	device->GetParent(__uuidof(IDXGIAdapter), (void **)&adapter);

	IDXGIFactory * factory;
	adapter->GetParent(__uuidof(IDXGIFactory), (void **)&factory);

	if (FAILED(factory->MakeWindowAssociation(p_handle, DXGI_MWA_NO_ALT_ENTER)))
	{
		ConsolePrintErrorAndQuit("Failed to disable alt enter.");
		return false;
	}

	return true;
}

void DirectXWrapper::Clear()
{
	// Clear render target.
	m_context->ClearRenderTargetView(m_renderTarget, m_clearColor);
	m_context->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void DirectXWrapper::Present()
{
	m_swapChain->Present(0, 0);
}

IDXGISwapChain* DirectXWrapper::GetSwapChain()
{
	return m_swapChain;
}

ID3D11Device* DirectXWrapper::GetDevice()
{
	return m_device;
}

ID3D11DeviceContext* DirectXWrapper::GetContext()
{
	return m_context;
}

D3D_FEATURE_LEVEL DirectXWrapper::GetVersion()
{
	return m_version;
}

void DirectXWrapper::SetClearColor(float R, float G, float B, float p_opacity)
{
	m_clearColor[0] = R;
	m_clearColor[1] = G;
	m_clearColor[2] = B;
	m_clearColor[3] = p_opacity;
}

void DirectXWrapper::TurnOnAlphaBlending()
{
	float blendFactor[4];

	blendFactor[0] = 0.0f;
	blendFactor[1] = 0.0f;
	blendFactor[2] = 0.0f;
	blendFactor[3] = 0.0f;

	m_context->OMSetBlendState(m_alphaEnabled, blendFactor, 0xffffffff);
}

void DirectXWrapper::TurnOffAlphaBlending()
{
	float blendFactor[4];

	blendFactor[0] = 0.0f;
	blendFactor[1] = 0.0f;
	blendFactor[2] = 0.0f;
	blendFactor[3] = 0.0f;

	m_context->OMSetBlendState(m_alphaDisabled, blendFactor, 0xffffffff);
}

void DirectXWrapper::ResetRenderTarget()
{
	m_context->OMSetRenderTargets(1, &m_renderTarget, m_depthStencilView);
}