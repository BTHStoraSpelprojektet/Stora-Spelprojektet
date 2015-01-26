#include "OutlingShader.h"

#include "DirectX.h"
#include "ConsoleFunctions.h"
#include "Globals.h"

OutliningShader::OutliningShader(){}

OutliningShader::OutliningShader(const OutliningShader& other){}

OutliningShader::~OutliningShader(){}

bool OutliningShader::Initialize()
{

	return true;
}


void OutliningShader::Shutdown()
{
	return;
}

void OutliningShader::Render()
{

	return;
}

void OutliningShader::InitializeBuffers()
{


}

bool OutliningShader::SetStencilStateOff(ID3D11Device* p_device, ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh)
{
	D3D11_DEPTH_STENCIL_DESC stencilDesc;
	stencilDesc.DepthEnable = true;
	stencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	stencilDesc.DepthFunc = D3D11_COMPARISON_ALWAYS;
	stencilDesc.StencilEnable = true;
	stencilDesc.StencilReadMask = 0xFF;
	stencilDesc.StencilWriteMask = 0xFF;
	stencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	stencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	stencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	stencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Create depth stencil state
	if (FAILED(p_device->CreateDepthStencilState(&stencilDesc, &m_stencilState)))
	{
		ConsolePrintErrorAndQuit("DirectX depth stencil enabled state failed to create.");
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
	if (FAILED(p_device->CreateTexture2D(&depthStencilDescription, NULL, &m_depthStencil)))
	{
		ConsolePrintErrorAndQuit("DirectX depth stencil failed to create. OutliningShader-SetOff");
		return false;
	}

	return true;
}

bool OutliningShader::SetStencilStateOn(ID3D11Device* p_device, ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh)
{
	D3D11_DEPTH_STENCIL_DESC stencilDesc;
	stencilDesc.DepthEnable = true;
	stencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	stencilDesc.DepthFunc = D3D11_COMPARISON_ALWAYS;
	stencilDesc.StencilEnable = true;
	stencilDesc.StencilReadMask = 0xFF;
	stencilDesc.StencilWriteMask = 0xFF;
	stencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	stencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_NOT_EQUAL;
	stencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	stencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_NOT_EQUAL;

	// Create depth stencil state
	if (FAILED(p_device->CreateDepthStencilState(&stencilDesc, &m_stencilState)))
	{
		ConsolePrintErrorAndQuit("DirectX depth stencil enabled state failed to create. OutliningShader-SetOn");
		return false;
	}

	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	return true;
}