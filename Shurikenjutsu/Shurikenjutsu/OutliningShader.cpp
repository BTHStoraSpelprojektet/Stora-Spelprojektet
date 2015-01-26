#include "OutlingShader.h"

#include "DirectX.h"
#include "ConsoleFunctions.h"
#include "Globals.h"

OutliningShader::OutliningShader(){}

OutliningShader::OutliningShader(const OutliningShader& other){}

OutliningShader::~OutliningShader(){}

bool OutliningShader::Initialize(ID3D11Device* p_device)
{
	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	instanceVertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"Shaders/Depth/DepthVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"Shaders/Depth/DepthVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile depth vertex shader from file.");
			return false;
		}

		else
		{
			m_VSVersion = "4.0";
		}
	}

	else
	{
		m_VSVersion = "5.0";
	}

	// Create the vertex shader.
	if (FAILED(p_device->CreateVertexShader(vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), NULL, &m_vertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth vertex shader.");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC layout[2];
	unsigned int size;

	layout[0].SemanticName = "POSITION";
	layout[0].SemanticIndex = 0;
	layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[0].InputSlot = 0;
	layout[0].AlignedByteOffset = 0;
	layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[0].InstanceDataStepRate = 0;

	layout[1].SemanticName = "TEXCOORD";
	layout[1].SemanticIndex = 0;
	layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	layout[1].InputSlot = 0;
	layout[1].AlignedByteOffset = D3D10_APPEND_ALIGNED_ELEMENT;
	layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[1].InstanceDataStepRate = 0;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layout, size, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth vertex input layout.");
		return false;
	}

	ConsolePrintSuccess("Depth vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"Shaders/Depth/InstancingDepthVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &instanceVertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"Shaders/Depth/InstancingDepthVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &instanceVertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile depth vertex shader from file.");
			return false;
		}

		else
		{
			m_VSVersion = "4.0";
		}
	}

	else
	{
		m_VSVersion = "5.0";
	}

	// Create the vertex shader.
	if (FAILED(p_device->CreateVertexShader(instanceVertexShader->GetBufferPointer(), instanceVertexShader->GetBufferSize(), NULL, &m_instanceShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth vertex shader.");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC instancedLayout[6];
	unsigned int instanceSize;

	instancedLayout[0].SemanticName = "POSITION";
	instancedLayout[0].SemanticIndex = 0;
	instancedLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	instancedLayout[0].InputSlot = 0;
	instancedLayout[0].AlignedByteOffset = 0;
	instancedLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	instancedLayout[0].InstanceDataStepRate = 0;

	instancedLayout[1].SemanticName = "TEXCOORD";
	instancedLayout[1].SemanticIndex = 0;
	instancedLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	instancedLayout[1].InputSlot = 0;
	instancedLayout[1].AlignedByteOffset = D3D10_APPEND_ALIGNED_ELEMENT;
	instancedLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	instancedLayout[1].InstanceDataStepRate = 0;

	instancedLayout[2].SemanticName = "INSTANCEPOS";
	instancedLayout[2].SemanticIndex = 0;
	instancedLayout[2].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instancedLayout[2].InputSlot = 1;
	instancedLayout[2].AlignedByteOffset = 0;
	instancedLayout[2].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instancedLayout[2].InstanceDataStepRate = 1;

	instancedLayout[3].SemanticName = "INSTANCEPOS";
	instancedLayout[3].SemanticIndex = 1;
	instancedLayout[3].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instancedLayout[3].InputSlot = 1;
	instancedLayout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instancedLayout[3].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instancedLayout[3].InstanceDataStepRate = 1;

	instancedLayout[4].SemanticName = "INSTANCEPOS";
	instancedLayout[4].SemanticIndex = 2;
	instancedLayout[4].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instancedLayout[4].InputSlot = 1;
	instancedLayout[4].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instancedLayout[4].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instancedLayout[4].InstanceDataStepRate = 1;

	instancedLayout[5].SemanticName = "INSTANCEPOS";
	instancedLayout[5].SemanticIndex = 3;
	instancedLayout[5].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instancedLayout[5].InputSlot = 1;
	instancedLayout[5].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instancedLayout[5].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instancedLayout[5].InstanceDataStepRate = 1;

	// Compute size of layout.
	instanceSize = sizeof(instancedLayout) / sizeof(instancedLayout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(instancedLayout, instanceSize, instanceVertexShader->GetBufferPointer(), instanceVertexShader->GetBufferSize(), &m_instanceLayout)))
	{
		ConsolePrintErrorAndQuit("Failed to create instance depth vertex input layout.");
		return false;
	}

	ConsolePrintSuccess("Depth vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	vertexShader->Release();
	vertexShader = 0;
	instanceVertexShader->Release();
	instanceVertexShader = 0;

	// Set variables to initial values.
	ID3D10Blob*	pixelShader = 0;
	errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"Shaders/Depth/DepthPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"Shaders/Depth/DepthPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile depth pixel shader from file.");
			return false;
		}

		else
		{
			m_PSVersion = "4.0";
		}
	}

	else
	{
		m_PSVersion = "5.0";
	}

	// Create the pixel shader.
	if (FAILED(p_device->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth pixel shader");
		return false;
	}

	ConsolePrintSuccess("Depth pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

	pixelShader->Release();
	pixelShader = 0;

	// Create the rasterizer description.
	D3D11_RASTERIZER_DESC rasterizer;
	rasterizer.FillMode = D3D11_FILL_SOLID;
	rasterizer.CullMode = D3D11_CULL_BACK;
	rasterizer.FrontCounterClockwise = false;
	rasterizer.DepthBias = 0;
	rasterizer.SlopeScaledDepthBias = 0.0f;
	rasterizer.DepthBiasClamp = 0.0f;
	rasterizer.DepthClipEnable = true;
	rasterizer.ScissorEnable = false;
	rasterizer.MultisampleEnable = false;
	rasterizer.AntialiasedLineEnable = false;

	// Create the back face culled rasterizer state.
	if (FAILED(p_device->CreateRasterizerState(&rasterizer, &m_rasterizer)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth rasterizer state.");
		return false;
	}

	// Create the matrix buffer description.
	D3D11_BUFFER_DESC matrixBuffer;
	matrixBuffer.Usage = D3D11_USAGE_DYNAMIC;
	matrixBuffer.ByteWidth = sizeof(MatrixBuffer);
	matrixBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBuffer.MiscFlags = 0;
	matrixBuffer.StructureByteStride = 0;

	// Create the matrix buffer.
	if (FAILED(p_device->CreateBuffer(&matrixBuffer, NULL, &m_matrixBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth matrix buffer.");
		return false;
	}

	// Create the sampler state description.
	D3D11_SAMPLER_DESC sampler;
	sampler.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sampler.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampler.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sampler.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sampler.MipLODBias = 0.0f;
	sampler.MaxAnisotropy = 1;
	sampler.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	sampler.BorderColor[0] = 0;
	sampler.BorderColor[1] = 0;
	sampler.BorderColor[2] = 0;
	sampler.BorderColor[3] = 0;
	sampler.MinLOD = 0;
	sampler.MaxLOD = D3D11_FLOAT32_MAX;

	// Create the texture sampler state.
	if (FAILED(p_device->CreateSamplerState(&sampler, &m_samplerState)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth sampler state.");
		return false;
	}

	if (!InitializeAnimatedDepth(p_device, p_context))
	{
		ConsolePrintErrorAndQuit("Failed to Initialize animated depth");
		return false;
	}

	return true;
}
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

bool OutliningShader::SetStencilStateOff(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
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
		ConsolePrintErrorAndQuit("DirectX depth stencil enabled state failed to create. OutliningShader-SetOff");
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

bool OutliningShader::SetStencilStateOn(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
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