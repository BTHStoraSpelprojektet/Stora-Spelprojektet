#include "stdafx.h"
#include "ParticleShader.h"
#include <D3Dcompiler.h>
#include "..\CommonLibs\ConsoleFunctions.h"
#include "CompiledShaderReader.h"
#include "ShaderGlobals.h"

bool ParticleShader::Initialize(ID3D11Device* p_device)
{
	m_vertexShader = 0;
	m_geometryShader = 0;
	m_pixelShader = 0;
	m_layout = 0;
	m_matrixBuffer = 0;
	m_samplerState = 0;

	std::string shaderPath = SHADER_PATH;

	// Create vertex shader from buffer.
	std::vector<unsigned char> compiledVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Particle/ParticleVertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledVertexShader.data(), compiledVertexShader.size(), NULL, &m_vertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create particle vertex shader.");
		return false;
	}

	// Create the vertex input layout description.
	D3D11_INPUT_ELEMENT_DESC layout[4];
	layout[0].SemanticName = "POSITION";
	layout[0].SemanticIndex = 0;
	layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[0].InputSlot = 0;
	layout[0].AlignedByteOffset = 0;
	layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[0].InstanceDataStepRate = 0;

	layout[1].SemanticName = "SIZE";
	layout[1].SemanticIndex = 0;
	layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	layout[1].InputSlot = 0;
	layout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[1].InstanceDataStepRate = 0;

	layout[2].SemanticName = "COLOR";
	layout[2].SemanticIndex = 0;
	layout[2].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	layout[2].InputSlot = 0;
	layout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[2].InstanceDataStepRate = 0;

	layout[3].SemanticName = "ROTATION";
	layout[3].SemanticIndex = 0;
	layout[3].Format = DXGI_FORMAT_R32_FLOAT;
	layout[3].InputSlot = 0;
	layout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[3].InstanceDataStepRate = 0;

	// Get number of elements in the layout.
	unsigned int numberOfElements = sizeof(layout) / sizeof(layout[0]);

	// Create vertex layout.
	if (FAILED(p_device->CreateInputLayout(layout, numberOfElements, compiledVertexShader.data(), compiledVertexShader.size(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create particle vertex layout.");
		return false;
	}
	
	ConsolePrintSuccess("Particle vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Create geometry shader from buffer.
	std::vector<unsigned char> compiledGeometryShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Particle/ParticleGeometryShader.cso");
	if (FAILED(p_device->CreateGeometryShader(compiledGeometryShader.data(), compiledGeometryShader.size(), NULL, &m_geometryShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create particle geometry vertex shader.");
		return false;
	}

	ConsolePrintSuccess("Particle geometry shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_GSVersion);

	// Create pixel shader from buffer.
	std::vector<unsigned char> compiledPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Particle/ParticlePixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledPixelShader.data(), compiledPixelShader.size(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create particle pixel shader.");
		return false;
	}

	// Create pixel shader from buffer.
	std::vector<unsigned char> compiledPixelShaderNotFire = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Particle/ParticlePixelShaderNotFire.cso");
	if (FAILED(p_device->CreatePixelShader(compiledPixelShaderNotFire.data(), compiledPixelShaderNotFire.size(), NULL, &m_pixelShaderNotFire)))
	{
		ConsolePrintErrorAndQuit("Failed to create particle pixel shader.");
		return false;
	}

	ConsolePrintSuccess("Particle pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

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
		ConsolePrintErrorAndQuit("Failed to create particle matrix buffer.");
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
		ConsolePrintErrorAndQuit("Failed to create particle sampler state.");
		return false;
	}

	return true;
}

void ParticleShader::Shutdown()
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
	
	// Release the pixel shader.
	if (m_pixelShaderNotFire)
	{
		m_pixelShaderNotFire->Release();
		m_pixelShaderNotFire = 0;
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
}

void ParticleShader::Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, bool p_isFire)
{
	// Set vertex buffer stride and offset.
	unsigned int stride = sizeof(ParticleVertex);
	unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetSamplers(0, 1, &m_samplerState);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
	p_context->IASetInputLayout(m_layout);

	// Set vertex and pixel shaders.
	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->GSSetShader(m_geometryShader, NULL, 0);

	if (p_isFire)
	{
		p_context->PSSetShader(m_pixelShader, NULL, 0);
	}
	else
	{
		p_context->PSSetShader(m_pixelShaderNotFire, NULL, 0);
	}

	// Render the polygon.
	p_context->Draw(p_vertexCount, 0);

	p_context->GSSetShader(NULL, NULL, 0);
}

void ParticleShader::UpdateViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_viewMatrix = p_viewMatrix;
	m_projectionMatrix = p_projectionMatrix;
}

void ParticleShader::UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix)
{
	DirectX::XMFLOAT4X4 worldMatrix = p_worldMatrix;
	DirectX::XMFLOAT4X4 viewMatrix = m_viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix = m_projectionMatrix;

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&worldMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&worldMatrix)));
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&viewMatrix)));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&projectionMatrix)));

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map particle matrix buffer.");
		return;
	}

	// Get pointer to buffer data.
	MatrixBuffer* matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Copy matrices into the buffer.
	matrixBuffer->m_worldMatrix = p_worldMatrix;
	matrixBuffer->m_viewMatrix = viewMatrix;
	matrixBuffer->m_projectionMatrix = projectionMatrix;

	// Unlock the buffer.
	p_context->Unmap(m_matrixBuffer, 0);

	// Now set the constant buffer in the vertex shader with the updated values.
	p_context->GSSetConstantBuffers(0, 1, &m_matrixBuffer);
}