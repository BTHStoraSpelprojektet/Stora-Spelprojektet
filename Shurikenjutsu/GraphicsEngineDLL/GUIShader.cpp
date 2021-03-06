#include "stdafx.h"
#include "GUIShader.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include <D3Dcompiler.h>
#include "..\CommonLibs\CommonStructures.h"
#include "CompiledShaderReader.h"
#include "ShaderGlobals.h"

bool GUIShader::Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	std::string shaderPath = SHADER_PATH;

	// Create the vertex shader.
	std::vector<unsigned char> compiledVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/GUI/GUIVertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledVertexShader.data(), compiledVertexShader.size(), NULL, &m_vertexShader)))
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
	if (FAILED(p_device->CreateInputLayout(layout, size, compiledVertexShader.data(), compiledVertexShader.size(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create GUI vertex input layout. @GUIShader");
		return false;
	}

	ConsolePrintSuccess("GUI vertex shader compiled successfully.");
	ConsolePrintText("GUI version: VS " + m_VSVersion);

	// Create the pixel shader.
	std::vector<unsigned char> compiledPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/GUI/GUIPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledPixelShader.data(), compiledPixelShader.size(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create GUI pixel shader @GUIShader");
		return false;
	}

	ConsolePrintSuccess("GUI pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

	std::vector<GUIVertex> quad;
	
	GUIVertex vertex;
	vertex.m_position = DirectX::XMFLOAT3(0.5f, -0.5f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(1, 1);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-0.5f, -0.5f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(0, 1);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-0.5f, 0.5f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(0, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(-0.5f, 0.5f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(0, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(0.5f, 0.5f, 0);
	vertex.m_textureCoordinates = DirectX::XMFLOAT2(1, 0);
	quad.push_back(vertex);

	vertex.m_position = DirectX::XMFLOAT3(0.5f, -0.5f, 0);
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
	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	if (m_layout)
	{
		m_layout->Release();
		m_layout = 0;
	}

	if (m_samplerState)
	{
		m_samplerState->Release();
		m_samplerState = 0;
	}

	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	if (m_quadBuffer)
	{
		m_quadBuffer->Release();
		m_quadBuffer = 0;
	}
}

void GUIShader::Render(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, float p_currentScreenWidth, float p_currentScreenHeight, float p_opacity)
{
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(GUIVertex);
	offset = 0;

	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map GUI matrix buffer.");
		return;
	}

	MatrixBuffer* matrixBuffer = NULL;
	matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	matrixBuffer->m_worldMatrix = p_worldMatrix;
	DirectX::XMStoreFloat4x4(&matrixBuffer->m_projectionMatrix, DirectX::XMMatrixOrthographicLH(p_currentScreenWidth, p_currentScreenHeight, 1.0f, 2.0f));
	matrixBuffer->m_opacity = p_opacity;

	p_context->Unmap(m_matrixBuffer, 0);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->IASetVertexBuffers(0, 1, &m_quadBuffer, &stride, &offset);
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);

	p_context->Draw(6, 0);
}

void GUIShader::PrepareRender(ID3D11DeviceContext* p_context)
{
	p_context->PSSetSamplers(0, 1, &m_samplerState);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);
	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);
}