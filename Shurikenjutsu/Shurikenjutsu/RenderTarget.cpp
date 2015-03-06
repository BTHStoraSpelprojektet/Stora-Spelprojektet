#include "RenderTarget.h"
#include "..\CommonLibs\ConsoleFunctions.h"

bool RenderTarget::Initialize(ID3D11Device* p_device, int p_width, int p_height)
{
	// Initialize the shadow map texture desdcription, and clear memory.
	D3D11_TEXTURE2D_DESC textureDescription;
	ZeroMemory(&textureDescription, sizeof(textureDescription));

	// Describe the shadow map texture.
	textureDescription.Width = p_width;
	textureDescription.Height = p_height;
	textureDescription.MipLevels = 1;
	textureDescription.ArraySize = 1;
	textureDescription.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	textureDescription.SampleDesc.Count = 1;
	textureDescription.Usage = D3D11_USAGE_DEFAULT;
	textureDescription.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	textureDescription.CPUAccessFlags = 0;
	textureDescription.MiscFlags = 0;

	// Create the shadow map texture, if this fails an error message is displayed.
	if (FAILED(p_device->CreateTexture2D(&textureDescription, NULL, &m_renderTarget)))
	{
		ConsolePrintErrorAndQuit("Failed to create render target texture.");
		return false;
	}

	// Describe the shadow map target view.
	D3D11_RENDER_TARGET_VIEW_DESC targetViewDescription;
	targetViewDescription.Format = textureDescription.Format;
	targetViewDescription.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	targetViewDescription.Texture2D.MipSlice = 0;

	// Create the shadow map target view, if this fails an error message is displayed.
 	if (FAILED(p_device->CreateRenderTargetView(m_renderTarget, &targetViewDescription, &m_renderTargetView)))
	{
		ConsolePrintErrorAndQuit("Failed to create render target.");
		return false;
	}

	// Describe the shadow map shader resource view.
	D3D11_SHADER_RESOURCE_VIEW_DESC resourceViewDescription;
	resourceViewDescription.Format = textureDescription.Format;
	resourceViewDescription.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	resourceViewDescription.Texture2D.MostDetailedMip = 0;
	resourceViewDescription.Texture2D.MipLevels = 1;

	// Create the shadow map shader resource view, if this fails an error message is displayed.
	if (FAILED(p_device->CreateShaderResourceView(m_renderTarget, &resourceViewDescription, &m_resourceView)))
	{
		ConsolePrintErrorAndQuit("Failed to create render target shader resource.");
		return false;
	}

	// Describe the depth stencil.
	D3D11_TEXTURE2D_DESC depthStencilDescription;
	ZeroMemory(&depthStencilDescription, sizeof(depthStencilDescription));
	depthStencilDescription.Width = p_width;
	depthStencilDescription.Height = p_height;
	depthStencilDescription.MipLevels = 1;
	depthStencilDescription.ArraySize = 1;
	depthStencilDescription.Format = DXGI_FORMAT_D32_FLOAT;
	depthStencilDescription.SampleDesc.Count = 1;
	depthStencilDescription.SampleDesc.Quality = 0;
	depthStencilDescription.Usage = D3D11_USAGE_DEFAULT;
	depthStencilDescription.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilDescription.CPUAccessFlags = 0;
	depthStencilDescription.MiscFlags = 0;

	// Create depth stencil texture. If this fails, display an error message.
	if (FAILED(p_device->CreateTexture2D(&depthStencilDescription, NULL, &m_depthStencil)))
	{
		ConsolePrintErrorAndQuit("Failed to create render depth stencil.");
		return false;
	}

	// Describe the depth stencil view.
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDescription;
	ZeroMemory(&depthStencilViewDescription, sizeof(depthStencilViewDescription));
	depthStencilViewDescription.Format = depthStencilViewDescription.Format;
	depthStencilViewDescription.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDescription.Texture2D.MipSlice = 0;

	// Create depth stencil view. If this fails, display an error message.
	if (FAILED(p_device->CreateDepthStencilView(m_depthStencil, &depthStencilViewDescription, &m_depthStencilView)))
	{
		ConsolePrintErrorAndQuit("Failed to create render target depth stencil view.");
		return false;
	}

	return true;
}

void RenderTarget::Shutdown()
{
	if (m_resourceView)
	{
		m_resourceView->Release();
		m_resourceView = nullptr;
	}

	if (m_renderTargetView)
	{
		m_renderTargetView->Release();
		m_renderTargetView = nullptr;
	}

	if (m_renderTarget)
	{
		m_renderTarget->Release();
		m_renderTarget = nullptr;
	}

	if (m_depthStencil)
	{
		m_depthStencil->Release();
		m_depthStencil = nullptr;
	}

	if (m_depthStencilView)
	{
		m_depthStencilView->Release();
		m_depthStencilView = nullptr;
	}
}

void RenderTarget::SetAsRenderTarget(ID3D11DeviceContext* p_deviceContext)
{
	// Bind the render target as the new render target.
	p_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);
}

void RenderTarget::Clear(ID3D11DeviceContext* p_deviceContext, float p_color[4])
{
	// Clear back and depth buffers.
	p_deviceContext->ClearRenderTargetView(m_renderTargetView, p_color);
	p_deviceContext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

ID3D11ShaderResourceView* RenderTarget::GetRenderTarget()
{
	return m_resourceView;
}