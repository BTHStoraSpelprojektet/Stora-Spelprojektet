#include "TrailRenderer.h"

#include "ConsoleFunctions.h"
#include "GraphicsEngine.h"
#include <D3Dcompiler.h>

TrailRenderer& TrailRenderer::GetInstance()
{
	static TrailRenderer instance;

	return instance;
}

bool TrailRenderer::Initialize(ID3D11Device* p_device)
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
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Trails/Particle/TrailVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Trails/Particle/TrailVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile trail vertex shader from file.");
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
		ConsolePrintErrorAndQuit("Failed to create trail vertex shader.");
		return false;
	}

	// Create the vertex input layout description.
	D3D11_INPUT_ELEMENT_DESC layout[6];
	layout[0].SemanticName = "POSITION";
	layout[0].SemanticIndex = 0;
	layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[0].InputSlot = 0;
	layout[0].AlignedByteOffset = 0;
	layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[0].InstanceDataStepRate = 0;

	layout[1].SemanticName = "ANGLE";
	layout[1].SemanticIndex = 0;
	layout[1].Format = DXGI_FORMAT_R32_FLOAT;
	layout[1].InputSlot = 0;
	layout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[1].InstanceDataStepRate = 0;

	layout[2].SemanticName = "WIDTH";
	layout[2].SemanticIndex = 0;
	layout[2].Format = DXGI_FORMAT_R32_FLOAT;
	layout[2].InputSlot = 0;
	layout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[2].InstanceDataStepRate = 0;

	layout[3].SemanticName = "TIMES";
	layout[3].SemanticIndex = 0;
	layout[3].Format = DXGI_FORMAT_R32G32_FLOAT;
	layout[3].InputSlot = 0;
	layout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[3].InstanceDataStepRate = 0;

	layout[4].SemanticName = "COLOR";
	layout[4].SemanticIndex = 0;
	layout[4].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	layout[4].InputSlot = 0;
	layout[4].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[4].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[4].InstanceDataStepRate = 0;

	layout[5].SemanticName = "BOOL";
	layout[5].SemanticIndex = 0;
	layout[5].Format = DXGI_FORMAT_R32_FLOAT;
	layout[5].InputSlot = 0;
	layout[5].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[5].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[5].InstanceDataStepRate = 0;

	// Get number of elements in the layout.
	unsigned int numberOfElements = sizeof(layout) / sizeof(layout[0]);

	// Create vertex layout.
	if (FAILED(p_device->CreateInputLayout(layout, numberOfElements, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create trail vertex layout.");
		return false;
	}

	ConsolePrintSuccess("Trail vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Release vertex shader since it is no longer required.
	vertexShader->Release();
	vertexShader = 0;

	// Compile the geometry shader.
	ID3D10Blob* geometryShader = 0;
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Trails/TrailGeometryShader.hlsl", NULL, NULL, "main", "gs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &geometryShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Trails/TrailGeometryShader.hlsl", NULL, NULL, "main", "gs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &geometryShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile trail geometry shader from file.");
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
		ConsolePrintErrorAndQuit("Failed to create trail geometry vertex shader.");
		return false;
	}

	ConsolePrintSuccess("Trail geometry shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_GSVersion);

	// Release pixel shader since it is no longer required.
	geometryShader->Release();
	geometryShader = 0;

	// Compile the pixel shader.
	ID3D10Blob*	pixelShader = 0;
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Trails/TrailPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Trails/TrailPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile trail pixel shader from file.");
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
		ConsolePrintErrorAndQuit("Failed to create trail pixel shader.");
		return false;
	}

	ConsolePrintSuccess("Trail pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

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
		ConsolePrintErrorAndQuit("Failed to create trail matrix buffer.");
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
		ConsolePrintErrorAndQuit("Failed to create trail sampler state.");
		return false;
	}

	// Store identity matrices.
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_viewMatrix, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_projectionMatrix, DirectX::XMMatrixIdentity());
	UpdateMatrixes();

	return true;
}

void TrailRenderer::Shutdown()
{
	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = nullptr;
	}

	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = nullptr;
	}

	if (m_geometryShader)
	{
		m_geometryShader->Release();
		m_geometryShader = nullptr;
	}

	if (m_layout)
	{
		m_layout->Release();
		m_layout = nullptr;
	}

	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = nullptr;
	}

	if (m_samplerState)
	{
		m_samplerState->Release();
		m_samplerState = nullptr;
	}
}

void TrailRenderer::RenderTrail(ID3D11Buffer* p_vertexBuffer, unsigned int p_points, ID3D11ShaderResourceView* p_texture)
{
	// Set vertex buffer stride and offset.
	ID3D11DeviceContext* context = GraphicsEngine::GetInstance()->GetContext();
	unsigned int stride = sizeof(TrailPoint);
	unsigned int offset = 0;

	// Set vertex, geometry and pixel shaders.
	context->VSSetShader(m_vertexShader, NULL, 0);
	context->GSSetShader(m_geometryShader, NULL, 0);
	context->PSSetShader(m_pixelShader, NULL, 0);

	context->PSSetShaderResources(0, 1, &p_texture);
	context->PSSetSamplers(0, 1, &m_samplerState);
	context->GSSetConstantBuffers(0, 1, &m_matrixBuffer);

	context->IASetVertexBuffers(0, 1, &p_vertexBuffer, &stride, &offset);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
	context->IASetInputLayout(m_layout);

	// Render the polygons.
	context->Draw(p_points, 0);

	context->GSSetShader(NULL, NULL, 0);
}

void TrailRenderer::SetWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
	UpdateMatrixes();
}

void TrailRenderer::SetViewMatrix(DirectX::XMFLOAT4X4 p_viewMatrix)
{
	m_viewMatrix = p_viewMatrix;
	UpdateMatrixes();
}

void TrailRenderer::SetProjectionMatrix(DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_projectionMatrix = p_projectionMatrix;
	UpdateMatrixes();
}

DirectX::XMFLOAT4X4 TrailRenderer::GetWorldMatrix()
{
	return m_worldMatrix;
}

DirectX::XMFLOAT4X4 TrailRenderer::GetViewMatrix()
{
	return m_viewMatrix;
}

DirectX::XMFLOAT4X4 TrailRenderer::GetProjectionMatrix()
{
	return m_projectionMatrix;
}

void TrailRenderer::UpdateMatrixes()
{
	DirectX::XMFLOAT4X4 worldMatrix = m_worldMatrix;
	DirectX::XMFLOAT4X4 viewMatrix = m_viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix = m_projectionMatrix;

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&worldMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&worldMatrix)));
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&viewMatrix)));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&projectionMatrix)));

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(GraphicsEngine::GetInstance()->GetContext()->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map particle matrix buffer.");
		return;
	}

	// Get pointer to buffer data.
	MatrixBuffer* matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Copy matrices into the buffer.
	matrixBuffer->m_worldMatrix = m_worldMatrix;
	matrixBuffer->m_viewMatrix = viewMatrix;
	matrixBuffer->m_projectionMatrix = projectionMatrix;

	// Unlock the buffer.
	GraphicsEngine::GetInstance()->GetContext()->Unmap(m_matrixBuffer, 0);
}