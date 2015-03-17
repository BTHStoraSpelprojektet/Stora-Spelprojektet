#include "TrailRenderer.h"

#include "..\CommonLibs\ConsoleFunctions.h"
#include "GraphicsEngine.h"
#include <D3Dcompiler.h>
#include "Trail.h"
#include "..\GraphicsEngineDLL\ShaderGlobals.h"
#include <fstream>

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

	std::string shaderPath = SHADER_PATH;

	// Create vertex shader from buffer.
	std::vector<unsigned char> compiledVertexShader = ReadShaderData(shaderPath + "Shaders/Trail/TrailVertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledVertexShader.data(), compiledVertexShader.size(), NULL, &m_vertexShader)))
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
	if (FAILED(p_device->CreateInputLayout(layout, numberOfElements, compiledVertexShader.data(), compiledVertexShader.size(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create trail vertex layout.");
		return false;
	}

	ConsolePrintSuccess("Trail vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Create geometry shader from buffer.
	std::vector<unsigned char> compiledGeometryShader = ReadShaderData(shaderPath + "Shaders/Trail/TrailGeometryShader.cso");
	if (FAILED(p_device->CreateGeometryShader(compiledGeometryShader.data(), compiledGeometryShader.size(), NULL, &m_geometryShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create trail geometry vertex shader.");
		return false;
	}

	ConsolePrintSuccess("Trail geometry shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_GSVersion);

	// Create pixel shader from buffer.
	std::vector<unsigned char> compiledPixelShader = ReadShaderData(shaderPath + "Shaders/Trail/TrailPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledPixelShader.data(), compiledPixelShader.size(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create trail pixel shader.");
		return false;
	}

	ConsolePrintSuccess("Trail pixel shader compiled successfully.");
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

	ConsoleSkipLines(1);
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
		//m_matrixBuffer->Release();
		//m_matrixBuffer = nullptr;
	}

	if (m_samplerState)
	{
		/*m_samplerState->Release();
		m_samplerState = nullptr;*/
	}
}

void TrailRenderer::AddTrail(Trail* p_trail)
{
	m_trails.push_back(p_trail);
}

void TrailRenderer::RenderTrails()
{
	ID3D11DeviceContext* context = GraphicsEngine::GetContext();

	GraphicsEngine::TurnOffBackfaceCulling();

	// Set vertex buffer stride and offset.		
	unsigned int stride = sizeof(TrailPoint);
	unsigned int offset = 0;

	// Set vertex, geometry and pixel shaders.
	context->VSSetShader(m_vertexShader, NULL, 0);
	context->GSSetShader(m_geometryShader, NULL, 0);
	context->PSSetShader(m_pixelShader, NULL, 0);

	context->PSSetSamplers(0, 1, &m_samplerState);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	context->IASetInputLayout(m_layout);

	for (unsigned int i = 0; i < m_trails.size(); i++)
	{
		ID3D11ShaderResourceView* tempSRV = m_trails[i]->GetTexture();
		context->PSSetShaderResources(0, 1, &tempSRV);		
		context->GSSetConstantBuffers(0, 1, &m_matrixBuffer);

		ID3D11Buffer* tempBuffer = m_trails[i]->GetBuffer();
		context->IASetVertexBuffers(0, 1, &tempBuffer, &stride, &offset);

		// Render the polygons.
		context->Draw(m_trails[i]->GetSize(), 0);
	}

	GraphicsEngine::TurnOnBackfaceCulling();

	m_trails.clear();
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
	if (FAILED(GraphicsEngine::GetContext()->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
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
	GraphicsEngine::GetContext()->Unmap(m_matrixBuffer, 0);
}

std::vector<unsigned char> TrailRenderer::ReadShaderData(std::string p_fileName)
{
	std::vector<unsigned char> fileData;

	// open the file
	std::ifstream vertexFile(p_fileName, std::ios::in | std::ios::binary | std::ios::ate);

	// if open was successful
	if (vertexFile.is_open())
	{
		// find the length of the file
		int Length = (int)vertexFile.tellg();

		// collect the file data
		fileData.resize(Length);
		vertexFile.seekg(0, std::ios::beg);
		vertexFile.read(reinterpret_cast<char*>(&fileData[0]), Length);
		vertexFile.close();
	}

	return fileData;
}