#include "ScreenSpace.h"
#include "ConsoleFunctions.h"
#include <DirectXMath.h>
#include <Windows.h>
#include <D3Dcompiler.h>


ScreenSpace::ScreenSpace(){}
ScreenSpace::~ScreenSpace(){}


bool ScreenSpace::Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Composition/CompositionVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Composition/CompositionVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to compile vertex shader from file.");
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
		ConsolePrintErrorAndQuit("Failed to create screen vertex shader.");
		return false;
	}

	ConsolePrintSuccess("ScreenSpace.cpp: Vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Release useless local shaders.
	vertexShader->Release();
	vertexShader = 0;

	// Set variables to initial values.
	ID3D10Blob*	pixelShader = 0;
	errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Composition/CompositionPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/Composition/CompositionPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to compile pixel shader from file.");
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
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create pixel shader");
		return false;
	}

	pixelShader->Release();
	pixelShader = 0;

	// Create the cbuffer where "every frame" data is stored
	D3D11_BUFFER_DESC frameBuffer;
	frameBuffer.Usage = D3D11_USAGE_DYNAMIC;
	frameBuffer.ByteWidth = sizeof(FrameBuffer);
	frameBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	frameBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	frameBuffer.MiscFlags = 0;
	frameBuffer.StructureByteStride = 0;

	// Create the frame buffer.
	if (FAILED(p_device->CreateBuffer(&frameBuffer, NULL, &m_frameBuffer)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create frame buffer.");
		return false;
	}

	InitializeSSAO(p_device, p_context);

	return true;
}

bool ScreenSpace::InitializeSSAO(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	ID3D10Blob*	pixelShader = 0;
	ID3D10Blob* errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SSAO/SSAOPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SSAO/SSAOPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to compile SSAO pixel shader from file.");
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
	if (FAILED(p_device->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_pixelShaderSSAO)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create SSAO pixel shader");
		return false;
	}

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SSAO/SSAOBlurHPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SSAO/SSAOBlurHPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to compile SSAO BlurH pixel shader from file.");
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
	if (FAILED(p_device->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_pixelShaderSSAOBlurH)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create SSAO Blur H pixel shader");
		return false;
	}

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SSAO/SSAOBlurVPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SSAO/SSAOBlurVPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to compile SSAO Blur V pixel shader from file.");
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
	if (FAILED(p_device->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_pixelShaderSSAOBlurV)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create SSAO pixel shader");
		return false;
	}

	pixelShader->Release();
	pixelShader = 0;

	// Create the cbuffer where "every frame" data is stored
	D3D11_BUFFER_DESC frameBuffer;
	frameBuffer.Usage = D3D11_USAGE_DYNAMIC;
	frameBuffer.ByteWidth = sizeof(SSAOCB);
	frameBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	frameBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	frameBuffer.MiscFlags = 0;
	frameBuffer.StructureByteStride = 0;

	// Create the frame buffer.
	if (FAILED(p_device->CreateBuffer(&frameBuffer, NULL, &m_ssaoBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create SSAO frame buffer.");
		return false;
	}

	BuildOffsetVectors();
	BuildRandomVec(p_device, p_context);
	D3D11_SAMPLER_DESC samplerDesc;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 1e5f;
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	if (FAILED(p_device->CreateSamplerState(&samplerDesc, &m_samplerDepth)))
	{
		ConsolePrintErrorAndQuit("Failed to create SSAO depth sampler state.");
		return false;
	}

	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.BorderColor[3] = 0;
	if (FAILED(p_device->CreateSamplerState(&samplerDesc, &m_samplerRandom)))
	{
		ConsolePrintErrorAndQuit("Failed to create SSAO random sampler state.");
		return false;
	}

	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

	if (FAILED(p_device->CreateSamplerState(&samplerDesc, &m_samplerBlur)))
	{
		ConsolePrintErrorAndQuit("Failed to create SSAO blur sampler state.");
		return false;
	}

	T = DirectX::XMFLOAT4X4(0.5f, 0.0f, 0.0f, 0.0f,
							0.0f, -0.5f, 0.0f, 0.0f,
							0.0f, 0.0f, 1.0f, 0.0f,
							0.5f, 0.5f, 0.0f, 1.0f);

	return true;
}

void ScreenSpace::Shutdown()
{
#if defined(_DEBUG) || defined(PROFILE)
	// Only works if device is created with the D3D10 or D3D11 debug layer, or when attached to PIX for Windows
	const char c_szName[] = "PIXELSHADER.DEBUG";
	m_pixelShader->SetPrivateData(WKPDID_D3DDebugObjectName,
		sizeof(c_szName) - 1, c_szName);
#endif
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

	if (m_frameBuffer)
	{
		m_frameBuffer->Release();
		m_frameBuffer = nullptr;
	}

	if (m_pixelShaderSSAO)
	{
		m_pixelShaderSSAO->Release();
		m_pixelShaderSSAO = nullptr;
	}

	if (m_pixelShaderSSAOBlurH)
	{
		m_pixelShaderSSAOBlurH->Release();
		m_pixelShaderSSAOBlurH = nullptr;
	}

	if (m_pixelShaderSSAOBlurV)
	{
		m_pixelShaderSSAOBlurV->Release();
		m_pixelShaderSSAOBlurV = nullptr;
	}

	if (m_ssaoBuffer)
	{
		m_ssaoBuffer->Release();
		m_ssaoBuffer = nullptr;
	}

	if (m_randomVectors)
	{
		m_randomVectors->Release();
		m_randomVectors = nullptr;
	}
}

void ScreenSpace::Render(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_color, ID3D11ShaderResourceView* p_depth, ID3D11ShaderResourceView* p_ssao)
{
	// Set parameters and then render.
	ID3D11ShaderResourceView* textures[4];
	textures[0] = p_normal;
	textures[1] = p_color;
	textures[2] = p_depth;
	textures[3] = p_ssao;
	
	p_context->PSSetShaderResources(3, 4, &textures[0]);

	p_context->IASetVertexBuffers(0, 0, 0, 0, 0);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(0);
	p_context->VSSetShader(m_vertexShader, 0, 0);
	p_context->PSSetShader(m_pixelShader, 0, 0);

	p_context->Draw(3, 0);
}

void ScreenSpace::RenderSSAO(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_depth)
{
	// Set parameters and then render.
	ID3D11ShaderResourceView* textures[3];
	textures[0] = p_normal;
	textures[1] = p_depth;
	textures[2] = m_randomVectors;

	p_context->PSSetShaderResources(3, 3, &textures[0]);
	p_context->PSSetSamplers(0, 1, &m_samplerDepth);
	p_context->PSSetSamplers(1, 1, &m_samplerRandom);
	p_context->IASetVertexBuffers(0, 0, 0, 0, 0);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(0);
	p_context->VSSetShader(m_vertexShader, 0, 0);
	p_context->PSSetShader(m_pixelShaderSSAO, 0, 0);

	p_context->Draw(3, 0);
}

void ScreenSpace::BlurImage(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_depth, ID3D11ShaderResourceView* p_normal, bool p_horizontal)
{
	// Set parameters and then render.
	ID3D11ShaderResourceView* textures[3];
	textures[0] = p_texture;
	textures[1] = p_depth;
	textures[2] = p_normal;

	p_context->PSSetShaderResources(3, 3, &textures[0]);
	p_context->PSSetSamplers(0, 1, &m_samplerBlur);
	p_context->IASetVertexBuffers(0, 0, 0, 0, 0);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(0);
	p_context->VSSetShader(m_vertexShader, 0, 0);

	if (p_horizontal)
	{
		p_context->PSSetShader(m_pixelShaderSSAOBlurH, 0, 0);
	}
	else
	{
		p_context->PSSetShader(m_pixelShaderSSAOBlurV, 0, 0);
	}

	p_context->Draw(3, 0);
}

void ScreenSpace::UpdateFrameBuffer(ID3D11DeviceContext* p_context, DirectionalLight& p_dlight, DirectX::XMFLOAT4X4 p_projection)
{	
	// Lock the "every frame" constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_frameBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map screen frame buffer.");
		return;
	}

	// Get a pointer to the data in the constant buffer.
	FrameBuffer* frameBuffer = (FrameBuffer*)mappedBuffer.pData;

	// Copy the fog information into the frame constant buffer.
	frameBuffer->m_directionalLight = p_dlight;
	DirectX::XMStoreFloat4x4(&frameBuffer->m_projection, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&p_projection)));

	// Unlock the constant buffer.
	p_context->Unmap(m_frameBuffer, 0);

	// Set the position of the frame constant buffer in the vertex shader.
	p_context->PSSetConstantBuffers(0, 1, &m_frameBuffer);
	
}

void ScreenSpace::UpdateSSAOBuffer(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_projection)
{
	// Lock the "every frame" constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_ssaoBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map screen frame buffer.");
		return;
	}

	// Get a pointer to the data in the constant buffer.
	SSAOCB* ssaoBuffer = (SSAOCB*)mappedBuffer.pData;

	// Copy the fog information into the frame constant buffer.
	DirectX::XMStoreFloat4x4(&ssaoBuffer->m_projection, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&p_projection)));
	DirectX::XMStoreFloat4x4(&ssaoBuffer->m_T, DirectX::XMMatrixMultiplyTranspose(DirectX::XMLoadFloat4x4(&p_projection), DirectX::XMLoadFloat4x4(&T)));

	for (unsigned int i = 0; i < 14; i++)
	{
		ssaoBuffer->m_offsetVectors[i] = m_offsetVectors[i];
	}

	// Unlock the constant buffer.
	p_context->Unmap(m_ssaoBuffer, 0);

	// Set the position of the frame constant buffer in the vertex shader.
	p_context->PSSetConstantBuffers(4, 1, &m_ssaoBuffer);
}

void ScreenSpace::BuildRandomVec(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	D3D11_TEXTURE2D_DESC texDesc;
	texDesc.Width = 256;
	texDesc.Height = 256;
	texDesc.MipLevels = 1;
	texDesc.ArraySize = 1;
	texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	texDesc.SampleDesc.Count = 1;
	texDesc.SampleDesc.Quality = 0;
	texDesc.Usage = D3D11_USAGE_IMMUTABLE;
	texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	texDesc.CPUAccessFlags = 0;
	texDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = { 0 };
	initData.SysMemPitch = 256 * sizeof(DirectX::XMFLOAT4);

	DirectX::XMFLOAT4* color = new DirectX::XMFLOAT4[256 * 256];

	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{

			DirectX::XMFLOAT3 v((float)(rand()) / (float)RAND_MAX, (float)(rand()) / (float)RAND_MAX, (float)(rand()) / (float)RAND_MAX);
			color[i * 256 + j] = DirectX::XMFLOAT4(v.x, v.y, v.z, 0.0f);
			
		}
	}

	initData.pSysMem = color;

	ID3D11Texture2D* tex = 0;

	p_device->CreateTexture2D(&texDesc, &initData, &tex);

	D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc;
	shaderResourceViewDesc.Format = texDesc.Format;
	shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	shaderResourceViewDesc.Texture2D.MostDetailedMip = 0;
	shaderResourceViewDesc.Texture2D.MipLevels = 1;

	p_device->CreateShaderResourceView(tex, 0, &m_randomVectors);

	//view saves a reference.
	tex->Release();
	delete[]color;
	color = 0;
}

void ScreenSpace::BuildOffsetVectors()
{
	m_offsetVectors[0] = DirectX::XMFLOAT4(+1.0f, +1.0f, +1.0f, 0.0f);
	m_offsetVectors[1] = DirectX::XMFLOAT4(-1.0f, -1.0f, -1.0f, 0.0f);

	m_offsetVectors[2] = DirectX::XMFLOAT4(-1.0f, +1.0f, +1.0f, 0.0f);
	m_offsetVectors[3] = DirectX::XMFLOAT4(+1.0f, -1.0f, -1.0f, 0.0f);

	m_offsetVectors[4] = DirectX::XMFLOAT4(+1.0f, +1.0f, -1.0f, 0.0f);
	m_offsetVectors[5] = DirectX::XMFLOAT4(-1.0f, -1.0f, +1.0f, 0.0f);

	m_offsetVectors[6] = DirectX::XMFLOAT4(-1.0f, +1.0f, -1.0f, 0.0f);
	m_offsetVectors[7] = DirectX::XMFLOAT4(+1.0f, -1.0f, +1.0f, 0.0f);

	m_offsetVectors[8] = DirectX::XMFLOAT4(-1.0f, 0.0f, 0.0f, 0.0f);
	m_offsetVectors[9] = DirectX::XMFLOAT4(+1.0f, 0.0f, 0.0f, 0.0f);

	m_offsetVectors[10] = DirectX::XMFLOAT4(0.0f, -1.0f, 0.0f, 0.0f);
	m_offsetVectors[11] = DirectX::XMFLOAT4(0.0f, +1.0f, 0.0f, 0.0f);

	m_offsetVectors[12] = DirectX::XMFLOAT4(0.0f, 0.0f, -1.0f, 0.0f);
	m_offsetVectors[13] = DirectX::XMFLOAT4(0.0f, 0.0f, +1.0f, 0.0f);

	for (int i = 0; i < 14; i++)
	{
		//float s = (rand() % 101 + 25.0f) / 100.0f;
		DirectX::XMStoreFloat4(&m_offsetVectors[i], DirectX::XMVector4Normalize(DirectX::XMLoadFloat4(&m_offsetVectors[i])));
		//m_offsetVectors[i].w *= s;
		//m_offsetVectors[i].x *= s;
		//m_offsetVectors[i].y *= s;
		//m_offsetVectors[i].z *= s;
	}
}