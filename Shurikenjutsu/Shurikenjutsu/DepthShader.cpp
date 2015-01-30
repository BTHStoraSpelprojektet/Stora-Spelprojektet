#include "DepthShader.h"
#include "ConsoleFunctions.h"
#include <D3Dcompiler.h>
#include <DirectXMath.h>

bool DepthShader::Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	instanceVertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/DepthVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/DepthVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
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
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/InstancingDepthVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &instanceVertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/InstancingDepthVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &instanceVertexShader, &errorMessage)))
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
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/DepthPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/DepthPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
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

void DepthShader::Shutdown()
{
	m_vertexShader->Release();
	m_pixelShader->Release();
	m_layout->Release();
	m_rasterizer->Release();
	m_samplerState->Release();

	m_instanceShader->Release();
}

void DepthShader::Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4& p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(Vertex);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetSamplers(0, 1, &m_samplerState);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);

	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	p_context->Draw(p_numberOfVertices, 0);
}

void DepthShader::UpdateViewAndProjection(DirectX::XMFLOAT4X4& p_viewMatrix, DirectX::XMFLOAT4X4& p_projectionMatrix)
{
	m_viewMatrix = p_viewMatrix;
	m_projectionMatrix = p_projectionMatrix;
}

void DepthShader::UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4& p_worldMatrix)
{
	DirectX::XMFLOAT4X4 worldMatrix = p_worldMatrix;
	DirectX::XMFLOAT4X4 viewMatrix = m_viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix = m_projectionMatrix;

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map depth matrix buffer.");
	}

	// Get pointer to the matrix buffer data.
	MatrixBuffer* matrixBuffer;
	matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&worldMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&worldMatrix)));
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&viewMatrix)));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&projectionMatrix)));

	// Set matrices in buffer.
	matrixBuffer->m_worldMatrix = worldMatrix;
	matrixBuffer->m_viewMatrix = viewMatrix;
	matrixBuffer->m_projectionMatrix = projectionMatrix;

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_matrixBuffer, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
}

///Instancing
void DepthShader::RenderInstance(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex)
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
	p_context->PSSetSamplers(0, 1, &m_samplerState);

	p_context->IASetVertexBuffers(0, 2, bufferPointers, stride, offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_instanceLayout);

	p_context->VSSetShader(m_instanceShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	p_context->DrawInstanced(p_numberOfVertices, m_numberOfInstanceList[p_instanceIndex], 0, 0);
}
void DepthShader::AddInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_position)
{
	if (p_numberOfInstances > 0)
	{
		m_numberOfInstanceList.push_back(p_numberOfInstances);
		InitializeInstanceBuffer(p_device, p_numberOfInstances, p_position);
	}
}
int DepthShader::GetNumberOfInstanceBuffer()
{
	return m_instanceBufferList.size();
}
void DepthShader::InitializeInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_matrices)
{
	ID3D11Buffer* instanceBuffer;
	// Create the instance buffer description.
	//Calculate position of all instanced objects
	std::vector<InstancePos> m_instances;
	m_instances.clear();
	for (int i = 0; i < p_numberOfInstances; i++)
	{
		InstancePos temp;
		DirectX::XMStoreFloat4x4(&temp.position, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&p_matrices[i])));
		m_instances.push_back(temp);
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
		ConsolePrintErrorAndQuit("Failed to create instance buffer.");
	}
	m_instanceBufferList.push_back(instanceBuffer);
}

bool DepthShader::InitializeAnimatedDepth(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	ID3D10Blob*	animatedVertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile animated vertex shader
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/DepthAnimatedVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &animatedVertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Depth/DepthAnimatedVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &animatedVertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile depth animated vertex shader from file.");
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

	// Create the animated vertex shader.
	if (FAILED(p_device->CreateVertexShader(animatedVertexShader->GetBufferPointer(), animatedVertexShader->GetBufferSize(), NULL, &m_animatedVertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth animated vertex shader.");
		return false;
	}

	// Configure animated vertex layout.
	D3D11_INPUT_ELEMENT_DESC animationLayout[4];
	unsigned int animationSize;

	animationLayout[0].SemanticName = "POSITION";
	animationLayout[0].SemanticIndex = 0;
	animationLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	animationLayout[0].InputSlot = 0;
	animationLayout[0].AlignedByteOffset = 0;
	animationLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[0].InstanceDataStepRate = 0;

	animationLayout[1].SemanticName = "TEXCOORD";
	animationLayout[1].SemanticIndex = 0;
	animationLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	animationLayout[1].InputSlot = 0;
	animationLayout[1].AlignedByteOffset = 12;
	animationLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[1].InstanceDataStepRate = 0;

	animationLayout[2].SemanticName = "WEIGHT";
	animationLayout[2].SemanticIndex = 0;
	animationLayout[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	animationLayout[2].InputSlot = 0;
	animationLayout[2].AlignedByteOffset = 44;
	animationLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[2].InstanceDataStepRate = 0;

	animationLayout[3].SemanticName = "BONEINDEX";
	animationLayout[3].SemanticIndex = 0;
	animationLayout[3].Format = DXGI_FORMAT_R8G8B8A8_UINT;
	animationLayout[3].InputSlot = 0;
	animationLayout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	animationLayout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[3].InstanceDataStepRate = 0;

	// Compute size of layout.
	animationSize = sizeof(animationLayout) / sizeof(animationLayout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(animationLayout, animationSize, animatedVertexShader->GetBufferPointer(), animatedVertexShader->GetBufferSize(), &m_animatedLayout)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth animated vertex input layout.");
		return false;
	}

	animatedVertexShader->Release();
	animatedVertexShader = 0;

	// Create the animated matrix buffer description.
	D3D11_BUFFER_DESC animatedMatrixBuffer;
	animatedMatrixBuffer.Usage = D3D11_USAGE_DYNAMIC;
	animatedMatrixBuffer.ByteWidth = sizeof(AnimationMatrixBuffer);
	animatedMatrixBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	animatedMatrixBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	animatedMatrixBuffer.MiscFlags = 0;
	animatedMatrixBuffer.StructureByteStride = 0;

	// Create the animated matrix buffer.
	if (FAILED(p_device->CreateBuffer(&animatedMatrixBuffer, NULL, &m_animationMatrixBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create depth animated buffer.");
		return false;
	}

	return true;
}

void DepthShader::RenderAnimated(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4& p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(VertexAnimated);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);
	UpdateAnimatedBuffer(p_context, p_boneTransforms);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetSamplers(0, 1, &m_samplerState);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_animatedLayout);

	p_context->VSSetShader(m_animatedVertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	p_context->Draw(p_numberOfVertices, 0);
}

void DepthShader::UpdateAnimatedBuffer(ID3D11DeviceContext* p_context, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_animationMatrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map scene animated matrix buffer.");
	}

	// Get pointer to the matrix buffer data.
	AnimationMatrixBuffer* animatedMatrixBuffer;
	animatedMatrixBuffer = (AnimationMatrixBuffer*)mappedBuffer.pData;

	// Set matrices in buffer.
	for (unsigned int i = 0; i < p_boneTransforms.size(); i++)
		animatedMatrixBuffer->m_boneTransforms[i] = DirectX::XMLoadFloat4x4(&p_boneTransforms[i]);

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_animationMatrixBuffer, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(2, 1, &m_animationMatrixBuffer);
}