#include "InstancedShader.h"

bool InstancedShader::Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context, HWND p_handle)
{
	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"InstancedVShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"InstancedVShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintError("Failed to compile scene vertex shader from file. @InstanceShader");
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
		ConsolePrintError("Failed to create scene vertex shader. @InstanceShader");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC layout[5];
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

	layout[3].SemanticName = "TANGENT";
	layout[3].SemanticIndex = 0;
	layout[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[3].InputSlot = 0;
	layout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[3].InstanceDataStepRate = 0;

	layout[4].SemanticName = "INSTANCEPOS";
	layout[4].SemanticIndex = 0;
	layout[4].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[4].InputSlot = 1;
	layout[4].AlignedByteOffset = 0;
	layout[4].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	layout[4].InstanceDataStepRate = 1;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layout, size, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintError("Failed to create scene vertex input layout. @InstanceShader");
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
	if (FAILED(D3DCompileFromFile(L"InstancedPShader.hlsl", NULL, NULL, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"InstancedPShader.hlsl", NULL, NULL, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
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
		ConsolePrintError("Failed to create scene pixel shader @InstanceShader");
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

	// Create the back face culled rasterizer state.
	if (FAILED(p_device->CreateRasterizerState(&rasterizer, &m_rasterizerStateBackCulled)))
	{
		ConsolePrintError("Failed to create scene back face culled rasterrizer state. @InstanceShader");
		return false;
	}

	rasterizer.CullMode = D3D11_CULL_NONE;

	// Create the none culled rasterizer state.
	if (FAILED(p_device->CreateRasterizerState(&rasterizer, &m_rasterizerStateNoneCulled)))
	{
		ConsolePrintError("Failed to create scene none culled rasterrizer state. @InstanceShader");
		return false;
	}

	TurnOnBackFaceCulling(p_context);

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
		ConsolePrintError("Failed to create scene sampler state. @InstanceShader");
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
		ConsolePrintError("Failed to create scene matrix buffer. @InstanceShader");
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
		ConsolePrintError("Failed to create scene fog buffer. @InstanceShader");
		return false;
	}

	m_instanceBufferList = std::vector<ID3D11Buffer*>();
	return true;
}

void InstancedShader::Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMMATRIX& p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex)
{
	// Set parameters and then render.
	unsigned int stride[2];
	unsigned int offset[2];
	ID3D11Buffer* bufferPointers[2];

	stride[0] = sizeof(Vertex);
	stride[1] = sizeof(InstancePos);

	offset[0] = 0;
	offset[1] = 0;

	bufferPointers[0] = p_mesh;
	bufferPointers[1] = m_instanceBufferList[p_instanceIndex];

	UpdateWorldMatrix(p_context, p_worldMatrix);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetShaderResources(1, 1, &p_normalMap);
	p_context->PSSetSamplers(0, 1, &m_samplerState);

	p_context->IASetVertexBuffers(0, 2, bufferPointers, stride, offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);

	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	p_context->DrawInstanced(p_numberOfVertices, m_numberOfInstanceList[p_instanceIndex], 0, 0);
}

void InstancedShader::UpdateViewAndProjection(DirectX::XMMATRIX& p_viewMatrix, DirectX::XMMATRIX& p_projectionMatrix)
{
	m_viewMatrix = p_viewMatrix;
	m_projectionMatrix = p_projectionMatrix;
}

void InstancedShader::UpdateFogBuffer(ID3D11DeviceContext* p_context, float p_fogStart, float p_fogEnd, float p_fogDensity)
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

void InstancedShader::UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMMATRIX& p_worldMatrix)
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

void InstancedShader::TurnOnBackFaceCulling(ID3D11DeviceContext* p_context)
{
	p_context->RSSetState(m_rasterizerStateBackCulled);
}

void InstancedShader::TurnOffBackFaceCulling(ID3D11DeviceContext* p_context)
{
	p_context->RSSetState(m_rasterizerStateNoneCulled);
}

void InstancedShader::AddInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances)
{
	m_numberOfInstanceList.push_back(p_numberOfInstances);
	m_instanceBufferList.push_back(InitializeInstanceBuffer(p_device, p_numberOfInstances));
}
ID3D11Buffer* InstancedShader::InitializeInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances)
{
	ID3D11Buffer* instanceBuffer;
	// Create the instance buffer description.
	//Calculate position of all instanced objects
	std::vector<InstancePos> m_instances(p_numberOfInstances);
	for (int i = 0; i < p_numberOfInstances; i++)
	{
		DirectX::XMStoreFloat3(&m_instances[i].position, DirectX::XMVectorSet(i * 4.0f, 0.0f, 0.0f, 0.0f));
	}

	D3D11_BUFFER_DESC instanceBufferDesc;
	instanceBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	instanceBufferDesc.ByteWidth = sizeof(InstancePos) * p_numberOfInstances;
	instanceBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	instanceBufferDesc.CPUAccessFlags = 0;
	instanceBufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA instanceData;
	instanceData.pSysMem = &m_instances[0];
	instanceData.SysMemPitch = 0;
	instanceData.SysMemSlicePitch = 0;

	// Create the Instance buffer.
	if (FAILED(p_device->CreateBuffer(&instanceBufferDesc, &instanceData, &instanceBuffer)))
	{
		ConsolePrintError("Failed to create instance buffer. @InstanceShader");
	}
	return instanceBuffer;
}