#include "SceneShader.h"

bool SceneShader::Initialize(ID3D11Device* p_device, HWND p_handle)
{
	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"VertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"VertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintError("Failed to compile scene vertex shader from file.");
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
		ConsolePrintError("Failed to create scene vertex shader.");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC layout[3];
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
	layout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[1].InstanceDataStepRate = 0;

	layout[2].SemanticName = "NORMAL";
	layout[2].SemanticIndex = 0;
	layout[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[2].InputSlot = 0;
	layout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[2].InstanceDataStepRate = 0;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layout, size, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintError("Failed to create scene vertex input layout.");
		return false;
	}

	ConsolePrintSuccess("Scene vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);
	ConsoleSkipLines(1);

	vertexShader->Release();
	vertexShader = 0;

	// Set variables to initial values.
	ID3D10Blob*	pixelShader = 0;
	errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"PixelShader.hlsl", NULL, NULL, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"PixelShader.hlsl", NULL, NULL, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintError("Failed to compile scene pixel shader from file.");
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
		ConsolePrintError("Failed to create scene pixel shader");
		return false;
	}

	ConsolePrintSuccess("Scene pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);
	ConsoleSkipLines(1);

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

	// Create the rasterizer state.
	if (FAILED(p_device->CreateRasterizerState(&rasterizer, &m_rasterizerState)))
	{
		ConsolePrintError("Failed to create scene rasterrizer state.");
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
		ConsolePrintError("Failed to create scene sampler state.");
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
		ConsolePrintError("Failed to create scene matrix buffer.");
		return false;
	}

	// Setup the description of the dynamic fog constant buffer that is in the vertex shader.
	D3D11_BUFFER_DESC fogBuffer;
	fogBuffer.Usage = D3D11_USAGE_DYNAMIC;
	fogBuffer.ByteWidth = sizeof(FogBuffer);
	fogBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	fogBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	fogBuffer.MiscFlags = 0;
	fogBuffer.StructureByteStride = 0;

	// Create the fog buffer.
	if (FAILED(p_device->CreateBuffer(&fogBuffer, NULL, &m_fogBuffer)))
	{
		ConsolePrintError("Failed to create scene fog buffer.");
		return false;
	}

	return true;
}

void SceneShader::Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMMATRIX& p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(Vertex);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);
	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);
	p_context->PSSetSamplers(0, 1, &m_samplerState);
	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::UpdateViewAndProjection(DirectX::XMMATRIX& p_viewMatrix, DirectX::XMMATRIX& p_projectionMatrix)
{
	m_viewMatrix = p_viewMatrix;
	m_projectionMatrix = p_projectionMatrix;
}

void SceneShader::UpdateFogBuffer(ID3D11DeviceContext* p_context, float p_fogStart, float p_fogEnd, float p_fogDensity)
{
	// Lock the fog constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_fogBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintError("Failed to map scene fog buffer.");
	}

	// Get a pointer to the data in the constant buffer.
	FogBuffer* fogBuffer;
	fogBuffer = (FogBuffer*)mappedBuffer.pData;

	// Copy the fog information into the fog constant buffer.
	fogBuffer->m_fogStart = p_fogStart;
	fogBuffer->m_fogEnd = p_fogEnd;
	fogBuffer->m_fogDensity = p_fogDensity;

	// Unlock the constant buffer.
	p_context->Unmap(m_fogBuffer, 0);

	// Set the position of the fog constant buffer in the vertex shader.
	p_context->VSSetConstantBuffers(1, 1, &m_fogBuffer);
}

void SceneShader::UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMMATRIX& p_worldMatrix)
{
	DirectX::XMMATRIX worldMatrix = p_worldMatrix;
	DirectX::XMMATRIX viewMatrix = m_viewMatrix;
	DirectX::XMMATRIX projectionMatrix = m_projectionMatrix;

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintError("Failed to map scene matrix buffer.");
	}

	// Get pointer to the matrix buffer data.
	MatrixBuffer* matrixBuffer;
	matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Transpose the matrices.
	worldMatrix = DirectX::XMMatrixTranspose(worldMatrix);
	viewMatrix = DirectX::XMMatrixTranspose(viewMatrix);
	projectionMatrix = DirectX::XMMatrixTranspose(projectionMatrix);

	// Set matrices in buffer.
	matrixBuffer->m_worldMatrix = worldMatrix;
	matrixBuffer->m_viewMatrix = viewMatrix;
	matrixBuffer->m_projectionMatrix = projectionMatrix;

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_matrixBuffer, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
}