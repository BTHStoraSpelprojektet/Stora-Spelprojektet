#include "GUIShader.h"

bool GUIShader::Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile GUI vertex shader from file.");
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
		ConsolePrintErrorAndQuit("Failed to create GUI vertex shader.");
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
	layout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[1].InstanceDataStepRate = 0;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layout, size, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create GUI vertex input layout. @GUIShader");
		return false;
	}

	ConsolePrintSuccess("GUI vertex shader compiled successfully.");
	ConsolePrintText("GUI version: VS " + m_VSVersion);

	vertexShader->Release();
	vertexShader = 0;

	// Set variables to initial values.
	ID3D10Blob*	pixelShader = 0;
	errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIPixelShader.hlsl", NULL, NULL, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIPixelShader.hlsl", NULL, NULL, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile GUI pixel shader from file.");
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
		ConsolePrintErrorAndQuit("Failed to create GUI pixel shader @GUIShader");
		return false;
	}

	ConsolePrintSuccess("GUI pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

	pixelShader->Release();
	pixelShader = 0;

	std::vector<GUIVertex> quad;
	
	GUIVertex vertex;
	vertex.m_position = DirectX::XMFLOAT3(1.0f, -1.0f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(1, 1);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-1.0f, -1.0f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(0, 1);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-1.0f, 1.0f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(0, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-1.0f, 1.0f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(0, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(1.0f, 1.0f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(1, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(1.0f, -1.0f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(1, 1);
	quad.push_back(vertex);

	// Setup vertex buffer description.
	D3D11_BUFFER_DESC vertexBuffer;
	vertexBuffer.Usage = D3D11_USAGE_DEFAULT;
	vertexBuffer.ByteWidth = sizeof(GUIVertex) * quad.size();
	vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBuffer.CPUAccessFlags = 0;
	vertexBuffer.MiscFlags = 0;
	vertexBuffer.StructureByteStride = 0;

	// Setup vertex buffer data.
	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = quad.data();
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	p_device->CreateBuffer(&vertexBuffer, &vertexData, &m_quadBuffer);

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
		ConsolePrintErrorAndQuit("Failed to create scene matrix buffer.");
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
		ConsolePrintErrorAndQuit("Failed to create scene sampler state.");
		return false;
	}

	return true;
}

void GUIShader::Shutdown()
{
	m_vertexShader->Release();
	m_pixelShader->Release();

	m_layout->Release();
	m_samplerState->Release();

	m_matrixBuffer->Release();

	m_quadBuffer->Release();

	m_colorVertexShader->Release();
	m_colorPixelShader->Release();
	m_colorLayout->Release();

	m_colorQuadBuffer->Release();

	m_colorBuffer->Release();
}

void GUIShader::Render(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	// Set parameters and then render.
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(GUIVertex);
	offset = 0;

	// Lock the "every frame" constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map GUI matrix buffer.");
	}

	// Get a pointer to the data in the constant buffer.
	MatrixBuffer* matrixBuffer;
	matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Copy the fog information into the frame constant buffer.
	matrixBuffer->m_worldMatrix = p_worldMatrix;

	DirectX::XMStoreFloat4x4(&matrixBuffer->m_projectionMatrix, DirectX::XMMatrixOrthographicLH((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, 1.0f, 2.0f));

	// Unlock the constant buffer.
	p_context->Unmap(m_matrixBuffer, 0);

	p_context->PSSetSamplers(0, 1, &m_samplerState);
	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->IASetVertexBuffers(0, 1, &m_quadBuffer, &stride, &offset);
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);
	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	p_context->Draw(6, 0);
}

bool GUIShader::InitializeColorShader(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIColorVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIColorVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile GUI color vertex shader from file.");
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
	if (FAILED(p_device->CreateVertexShader(vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), NULL, &m_colorVertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create GUI color vertex shader.");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC layout[1];
	unsigned int size;

	layout[0].SemanticName = "POSITION";
	layout[0].SemanticIndex = 0;
	layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[0].InputSlot = 0;
	layout[0].AlignedByteOffset = 0;
	layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[0].InstanceDataStepRate = 0;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layout, size, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_colorLayout)))
	{
		ConsolePrintErrorAndQuit("Failed to create GUI color vertex input layout. @GUIShader");
		return false;
	}

	ConsolePrintSuccess("GUI color vertex shader compiled successfully.");
	ConsolePrintText("GUI version: VS " + m_VSVersion);

	vertexShader->Release();
	vertexShader = 0;

	// Set variables to initial values.
	ID3D10Blob*	pixelShader = 0;
	errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIColorPixelShader.hlsl", NULL, NULL, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"Shaders/GUI/GUIColorPixelShader.hlsl", NULL, NULL, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile GUI color pixel shader from file.");
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
	if (FAILED(p_device->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_colorPixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create GUI color pixel shader @GUIShader");
		return false;
	}

	ConsolePrintSuccess("GUI color pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

	pixelShader->Release();
	pixelShader = 0;

	std::vector<GUIVertexColor> quad;

	GUIVertexColor vertex;
	vertex.m_position = DirectX::XMFLOAT3(0.5f, -0.5f, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-0.5f, -0.5f, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-0.5f, 0.5f, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-0.5f, 0.5f, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(0.5f, 0.5f, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(0.5f, -0.5f, 0);
	quad.push_back(vertex);

	// Setup vertex buffer description.
	D3D11_BUFFER_DESC vertexBuffer;
	vertexBuffer.Usage = D3D11_USAGE_DEFAULT;
	vertexBuffer.ByteWidth = sizeof(GUIVertexColor) * quad.size();
	vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBuffer.CPUAccessFlags = 0;
	vertexBuffer.MiscFlags = 0;
	vertexBuffer.StructureByteStride = 0;

	// Setup vertex buffer data.
	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = quad.data();
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	p_device->CreateBuffer(&vertexBuffer, &vertexData, &m_colorQuadBuffer);

	// Create the color buffer description.
	D3D11_BUFFER_DESC colorBuffer;
	colorBuffer.Usage = D3D11_USAGE_DYNAMIC;
	colorBuffer.ByteWidth = sizeof(MatrixBuffer);
	colorBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	colorBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	colorBuffer.MiscFlags = 0;
	colorBuffer.StructureByteStride = 0;

	// Create the matrix buffer.
	if (FAILED(p_device->CreateBuffer(&colorBuffer, NULL, &m_colorBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create GUI color buffer.");
		return false;
	}
	return true;
}

void GUIShader::RenderColor(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix, DirectX::XMFLOAT4 p_color)
{
	// Set parameters and then render.
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(GUIVertexColor);
	offset = 0;

	// Lock the "every frame" constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map GUI color matrix buffer.");
	}

	// Get a pointer to the data in the constant buffer.
	MatrixBuffer* matrixBuffer;
	matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Copy the fog information into the frame constant buffer.
	matrixBuffer->m_worldMatrix = p_worldMatrix;

	DirectX::XMStoreFloat4x4(&matrixBuffer->m_projectionMatrix, DirectX::XMMatrixOrthographicLH((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, 1.0f, 2.0f));

	// Unlock the constant buffer.
	p_context->Unmap(m_matrixBuffer, 0);

	// Store the color in colorBuffer
	if (FAILED(p_context->Map(m_colorBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map GUI color colorbuffer.");
	}

	// Get a pointer to the data in the constant buffer.
	ColorBuffer* colorBuffer;
	colorBuffer = (ColorBuffer*)mappedBuffer.pData;
	colorBuffer->m_color = p_color;

	// Unlock the constant buffer.
	p_context->Unmap(m_colorBuffer, 0);

	p_context->IASetVertexBuffers(0, 1, &m_colorQuadBuffer, &stride, &offset);
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
	p_context->PSSetConstantBuffers(2, 1, &m_colorBuffer);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_colorLayout);
	p_context->VSSetShader(m_colorVertexShader, NULL, 0);
	p_context->PSSetShader(m_colorPixelShader, NULL, 0);

	p_context->Draw(6, 0);
}