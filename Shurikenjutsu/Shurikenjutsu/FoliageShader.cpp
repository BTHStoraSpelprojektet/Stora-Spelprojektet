#include "FoliageShader.h"

#include <D3Dcompiler.h>
#include <fstream>
#include "..\CommonLibs\ConsoleFunctions.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "GraphicsEngine.h"

bool FoliageShader::Initialize(ID3D11Device* p_device)
{
	m_vertexShader = 0;
	m_geometryShader = 0;
	m_pixelShader = 0;
	m_layout = 0;
	m_matrixBuffer = 0;
	m_samplerState = 0;

	ID3D10Blob* errorMessage = 0;
	ID3D10Blob* vertexShader = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Foliage/FoliageVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Foliage/FoliageVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile foliage vertex shader from file.");
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

	// Create vertex shader from buffer.
	if (FAILED(p_device->CreateVertexShader(vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), NULL, &m_vertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create foliage vertex shader.");
		return false;
	}

	// Create the vertex input layout description.
	D3D11_INPUT_ELEMENT_DESC layout[2];
	layout[0].SemanticName = "POSITION";
	layout[0].SemanticIndex = 0;
	layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[0].InputSlot = 0;
	layout[0].AlignedByteOffset = 0;
	layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[0].InstanceDataStepRate = 0;

	layout[1].SemanticName = "OFFSET";
	layout[1].SemanticIndex = 0;
	layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	layout[1].InputSlot = 0;
	layout[1].AlignedByteOffset = 12;
	layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[1].InstanceDataStepRate = 0;

	// Get number of elements in the layout.
	unsigned int numberOfElements = sizeof(layout) / sizeof(layout[0]);

	// Create vertex layout.
	if (FAILED(p_device->CreateInputLayout(layout, numberOfElements, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create foliage vertex layout.");
		return false;
	}

	ConsolePrintSuccess("Foliage vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Release vertex shader since it is no longer required.
	vertexShader->Release();
	vertexShader = 0;

	// Compile the geometry shader.
	ID3D10Blob* geometryShader = 0;
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Foliage/FoliageGeometryShader.hlsl", NULL, NULL, "main", "gs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &geometryShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Foliage/FoliageGeometryShader.hlsl", NULL, NULL, "main", "gs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &geometryShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile foliage geometry shader from file.");
			return false;
		}

		else
		{
			m_GSVersion = "4.0";
		}
	}

	else
	{
		m_GSVersion = "5.0";
	}

	// Create geometry shader from buffer.
	if (FAILED(p_device->CreateGeometryShader(geometryShader->GetBufferPointer(), geometryShader->GetBufferSize(), NULL, &m_geometryShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create geometry vertex shader.");
		return false;
	}

	ConsolePrintSuccess("Foliage geometry shader compiled successfully.");
	ConsolePrintText("Foliage version: PS " + m_GSVersion);

	// Release pixel shader since it is no longer required.
	geometryShader->Release();
	geometryShader = 0;

	// Compile the pixel shader.
	ID3D10Blob*	pixelShader = 0;
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Foliage/FoliagePixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Foliage/FoliagePixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile foliage pixel shader from file.");
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

	// Create pixel shader from buffer.
	if (FAILED(p_device->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create foliage pixel shader.");
		return false;
	}

	ConsolePrintSuccess("Foliage pixel shader compiled successfully.");
	ConsolePrintText("Foliage version: PS " + m_PSVersion);

	// Release pixel shader since it is no longer required.
	pixelShader->Release();
	pixelShader = 0;

	// Setup description of the matrix buffer.
	D3D11_BUFFER_DESC matrixBufferDescription;
	matrixBufferDescription.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDescription.ByteWidth = sizeof(MatrixBuffer);
	matrixBufferDescription.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDescription.MiscFlags = 0;
	matrixBufferDescription.StructureByteStride = 0;

	// Create buffer.
	if (FAILED(p_device->CreateBuffer(&matrixBufferDescription, NULL, &m_matrixBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create foliage matrix buffer.");
		return false;
	}

	// Setup description of the Geometry shader constant buffer.
	/*D3D11_BUFFER_DESC*/ matrixBufferDescription;
	matrixBufferDescription.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDescription.ByteWidth = sizeof(AngleBuffer);
	matrixBufferDescription.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDescription.MiscFlags = 0;
	matrixBufferDescription.StructureByteStride = 0;

	// Create buffer.
	if (FAILED(p_device->CreateBuffer(&matrixBufferDescription, NULL, &m_angleBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create foliage matrix buffer.");
		return false;
	}

	// Create a texture sampler description.
	D3D11_SAMPLER_DESC samplerDescription;
	samplerDescription.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDescription.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDescription.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDescription.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDescription.MipLODBias = 0.0f;
	samplerDescription.MaxAnisotropy = 1;
	samplerDescription.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDescription.BorderColor[0] = 0;
	samplerDescription.BorderColor[1] = 0;
	samplerDescription.BorderColor[2] = 0;
	samplerDescription.BorderColor[3] = 0;
	samplerDescription.MinLOD = 0;
	samplerDescription.MaxLOD = D3D11_FLOAT32_MAX;

	// Create texture sampler.
	if (FAILED(p_device->CreateSamplerState(&samplerDescription, &m_samplerState)))
	{
		ConsolePrintErrorAndQuit("Failed to create foliage sampler state.");
		return false;
	}
	
	m_texture = GraphicsEngine::GetInstance()->Create2DTexture("../Shurikenjutsu/2DTextures/grassFoil2.png");
	m_normalMap = GraphicsEngine::GetInstance()->Create2DTexture("../Shurikenjutsu/2DTextures/blanknormalmap_50.png");
	
	ReadRawFile();

	// Setup vertex buffer description.
	D3D11_BUFFER_DESC vertexBuffer;
	vertexBuffer.Usage = D3D11_USAGE_DEFAULT;
	vertexBuffer.ByteWidth = sizeof(FoliageVertex) * m_vertices.size();
	vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBuffer.CPUAccessFlags = 0;
	vertexBuffer.MiscFlags = 0;
	vertexBuffer.StructureByteStride = 0;

	// Setup vertex buffer data.
	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = m_vertices.data();
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	p_device->CreateBuffer(&vertexBuffer, &vertexData, &m_vertexBuffer);

	// Create world matrix and transpose
	DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixTranspose(worldMatrix));

	// Initilize angle
	m_angle = 0.0f;

	return true;
}

void FoliageShader::ReadRawFile()
{	
	std::ifstream inFile;
	inFile.open("../Shurikenjutsu/GrassMap/grassMask.raw", std::ios::binary);

	inFile.seekg(0, std::ios::end);
	long fileSize = (long)inFile.tellg();
	inFile.seekg(0);

	int row = (int)sqrt((fileSize));

	std::vector<unsigned char> in(fileSize);

	if (inFile)
	{
		inFile.read((char*)&in[0], (std::streamsize)in.size());
		inFile.close();
	}

	FoliageVertex newVert;

	float r1;
	float r2;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if ((in[(row * i) + j] / 255.0f) > 0.5f)
			{		
				for (unsigned int k = 0; k < 3; k++)
				{
					newVert.m_position = DirectX::XMFLOAT3((j - (row * 0.5f)) * 0.5f, (in[(row * i) + j] / 255.0f), -(i - (row * 0.5f)) * 0.5f);

					r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

					newVert.m_position.x += r1;
					newVert.m_position.z += r2;

					newVert.m_offset = DirectX::XMFLOAT2(r1, r2);
					m_vertices.push_back(newVert);
				}
			}
		}
	}
}

void FoliageShader::Shutdown()
{
	// Release the vertex shader.
	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

	// Release the vertex shader.
	if (m_geometryShader)
	{
		m_geometryShader->Release();
		m_geometryShader = 0;
	}

	// Release the pixel shader.
	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	// Release the sampler state.
	if (m_samplerState)
	{
		m_samplerState->Release();
		m_samplerState = 0;
	}

	// Release the matrix buffer.
	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	// Release the layout.
	if (m_layout)
	{
		m_layout->Release();
		m_layout = 0;
	}

	if (m_angleBuffer)
	{
		m_angleBuffer->Release();
		m_angleBuffer = 0;
	}

	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	if (m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}

	if (m_normalMap)
	{
		m_normalMap->Release();
		m_normalMap = 0;
	}
}

void FoliageShader::Render(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* m_shadowMap)
{
	// Set vertex buffer stride and offset.
	unsigned int stride = sizeof(FoliageVertex);
	unsigned int offset = 0;

	UpdateConstantBuffer(p_context);
	UpdateAngleBuffer(p_context);

	p_context->PSSetShaderResources(0, 1, &m_texture);
	p_context->PSSetShaderResources(1, 1, &m_normalMap);
	p_context->PSSetShaderResources(2, 1, &m_shadowMap);
	p_context->PSSetSamplers(0, 1, &m_samplerState);

	p_context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
	p_context->IASetInputLayout(m_layout);

	// Set vertex and pixel shaders.
	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->GSSetShader(m_geometryShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	// Render the polygon.
	p_context->Draw(m_vertices.size(), 0);

	p_context->GSSetShader(NULL, NULL, 0);
}

void FoliageShader::UpdateViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_viewMatrix = p_viewMatrix;
	m_projectionMatrix = p_projectionMatrix;
}

void FoliageShader::UpdateLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_lightViewMatrix = p_viewMatrix;
	m_lightProjectionMatrix = p_projectionMatrix;
}

void FoliageShader::UpdateConstantBuffer(ID3D11DeviceContext* p_context)
{
	DirectX::XMFLOAT4X4 viewMatrix = m_viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix = m_projectionMatrix;

	DirectX::XMFLOAT4X4 lightViewMatrix = m_lightViewMatrix;
	DirectX::XMFLOAT4X4 lightProjectionMatrix = m_lightProjectionMatrix;

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&viewMatrix)));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&projectionMatrix)));

	DirectX::XMStoreFloat4x4(&lightViewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&lightViewMatrix)));
	DirectX::XMStoreFloat4x4(&lightProjectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&lightProjectionMatrix)));

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map foliage matrix buffer.");
	}

	// Get pointer to buffer data.
	MatrixBuffer* matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Copy matrices into the buffer.
	matrixBuffer->m_worldMatrix = m_worldMatrix;
	matrixBuffer->m_viewMatrix = viewMatrix;
	matrixBuffer->m_projectionMatrix = projectionMatrix;

	matrixBuffer->m_lightViewMatrix = lightViewMatrix;
	matrixBuffer->m_lightProjectionMatrix = lightProjectionMatrix;

	// Unlock the buffer.
	p_context->Unmap(m_matrixBuffer, 0);

	// Now set the constant buffer in the vertex shader with the updated values.
	p_context->GSSetConstantBuffers(0, 1, &m_matrixBuffer);
}

void FoliageShader::UpdateAngleBuffer(ID3D11DeviceContext* p_context)
{
	m_angle += 0.005f;

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_angleBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map foliage angle buffer.");
	}

	// Get pointer to buffer data.
	AngleBuffer* angleBuffer = (AngleBuffer*)mappedBuffer.pData;

	// Copy matrices into the buffer.
	angleBuffer->m_rotation.x = sin(m_angle) * 0.5f;

	// Unlock the buffer.
	p_context->Unmap(m_angleBuffer, 0);

	// Now set the constant buffer in the vertex shader with the updated values.
	p_context->GSSetConstantBuffers(1, 1, &m_angleBuffer);
}