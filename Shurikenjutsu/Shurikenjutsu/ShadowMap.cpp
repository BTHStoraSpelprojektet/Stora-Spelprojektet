#include "ShadowMap.h"

bool ShadowMap::Initialize(ID3D11Device* p_device, int p_width, int p_height)
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
	if (FAILED(p_device->CreateTexture2D(&textureDescription, NULL, &m_shadowMap)))
	{
		ConsolePrintError("Failed to create shadow map texture.");
		return false;
	}

	// Describe the shadow map target view.
	D3D11_RENDER_TARGET_VIEW_DESC targetViewDescription;
	targetViewDescription.Format = textureDescription.Format;
	targetViewDescription.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	targetViewDescription.Texture2D.MipSlice = 0;

	// Create the shadow map target view, if this fails an error message is displayed.
	if (FAILED(p_device->CreateRenderTargetView(m_shadowMap, &targetViewDescription, &m_shadowMapTargetView)))
	{
		ConsolePrintError("Failed to create shadow map render target.");
		return false;
	}

	// Describe the shadow map shader resource view.
	D3D11_SHADER_RESOURCE_VIEW_DESC resourceViewDescription;
	resourceViewDescription.Format = textureDescription.Format;
	resourceViewDescription.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	resourceViewDescription.Texture2D.MostDetailedMip = 0;
	resourceViewDescription.Texture2D.MipLevels = 1;

	// Create the shadow map shader resource view, if this fails an error message is displayed.
	if (FAILED(p_device->CreateShaderResourceView(m_shadowMap, &resourceViewDescription, &m_shadowMapResourceView)))
	{
		ConsolePrintError("Failed to create shadow map shader resource.");
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
		ConsolePrintError("Failed to create shadow map depth stencil.");
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
		ConsolePrintError("Failed to create shadow map depth stencil view.");
		return false;
	}

	return true;
}

void ShadowMap::Shutdown()
{
	if (m_shadowMapResourceView)
	{
		m_shadowMapResourceView->Release();
		m_shadowMapResourceView = 0;
	}

	if (m_shadowMapTargetView)
	{
		m_shadowMapTargetView->Release();
		m_shadowMapTargetView = 0;
	}

	if (m_shadowMap)
	{
		m_shadowMap->Release();
		m_shadowMap = 0;
	}

	if (m_depthStencil)
	{
		m_depthStencil->Release();
		m_depthStencil = 0;
	}

	if (m_depthStencilView)
	{
		m_depthStencilView->Release();
		m_depthStencilView = 0;
	}
}

void ShadowMap::SetAsRenderTarget(ID3D11DeviceContext* p_deviceContext)
{
	// Set pixel shader shadow map to NULL.
	ID3D11ShaderResourceView* nullPointer = NULL;
	p_deviceContext->PSSetShaderResources(2, 1, &nullPointer);

	// Bind the shadow map as the new render target.
	p_deviceContext->OMSetRenderTargets(1, &m_shadowMapTargetView, m_depthStencilView);
}

void ShadowMap::Clear(ID3D11DeviceContext* p_deviceContext)
{
	// Set color to clear the back buffer to.
	float color[4] = {0.0f, 0.0f, 0.0f, 1.0f};

	// Clear back and depth buffers.
	p_deviceContext->ClearRenderTargetView(m_shadowMapTargetView, color);
	p_deviceContext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

ID3D11ShaderResourceView* ShadowMap::GetShadowMap()
{
	return m_shadowMapResourceView;
}