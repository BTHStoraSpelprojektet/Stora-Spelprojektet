#include "DirectX.h"

bool DirectXWrapper::Initialize(HWND p_handle)
{
	HRESULT result = S_OK;

	m_clearColor[0] = 0.0f;
	m_clearColor[1] = 0.6f;
	m_clearColor[2] = 0.9f;
	m_clearColor[3] = 1.0f;

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
	swapChainDescription.BufferDesc.Width = m_width;
	swapChainDescription.BufferDesc.Height = m_height;
	swapChainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDescription.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDescription.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDescription.OutputWindow = p_handle;
	swapChainDescription.SampleDesc.Count = 1;
	swapChainDescription.SampleDesc.Quality = 0;
	swapChainDescription.Windowed = TRUE;
	
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
		ConsolePrintError("DirectX swap chain and device failed to create.");
		return false;
	}

	// Retrieve the backbuffer texture from the swap chain.
	ID3D11Texture2D* backBuffer = NULL;
	if (FAILED(m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer)))
	{
		ConsolePrintError("DirectX back buffer failed to be retrieved.");
		return false;
	}

	// Create render target.
	if (FAILED(m_device->CreateRenderTargetView(backBuffer, NULL, &m_renderTarget)))
	{
		ConsolePrintError("DirectX render target failed to create.");
		return false;
	}

	// Release the back buffer.
	backBuffer->Release();

	// Initialize the depth stencil.
	D3D11_TEXTURE2D_DESC depthStencilDescription;
	ZeroMemory(&depthStencilDescription, sizeof(depthStencilDescription));
	depthStencilDescription.Width = m_width;
	depthStencilDescription.Height = m_height;
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
		ConsolePrintError("DirectX depth stencil failed to create.");
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
		ConsolePrintError("DirectX depth stencil view failed to create.");
		return false;
	}

	// Set device render target.
	m_context->OMSetRenderTargets(1, &m_renderTarget, m_depthStencilView);

	// Initialize the view port.
	D3D11_VIEWPORT viewPort;
	ZeroMemory(&viewPort, sizeof(viewPort));
	viewPort.Width = (float)m_width;
	viewPort.Height = (float)m_height;
	viewPort.MinDepth = 0.0f;
	viewPort.MaxDepth = 1.0f;
	viewPort.TopLeftX = 0;
	viewPort.TopLeftY = 0;

	// Create the view port.
	m_context->RSSetViewports(1, &viewPort);

	// Clear the render target.
	Clear();

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