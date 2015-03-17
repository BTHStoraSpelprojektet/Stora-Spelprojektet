
#include "stdafx.h"
#include "ScreenSpace.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include "PointLights.h"
#include "..\CommonLibs\DirectXTex\WICTextureLoader\WICTextureLoader.h"
#include "CompiledShaderReader.h"
#include "ShaderGlobals.h"

ScreenSpace::ScreenSpace(){}
ScreenSpace::~ScreenSpace(){}


bool ScreenSpace::Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	std::string shaderPath = SHADER_PATH;

	// Create the vertex shader.
	std::vector<unsigned char> compiledVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Composition/CompositionVertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledVertexShader.data(), compiledVertexShader.size(), NULL, &m_vertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create screen vertex shader.");
		return false;
	}

	ConsolePrintSuccess("ScreenSpace.cpp: Vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Create vertex shader from buffer.
	std::vector<unsigned char> compiledQuadVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Composition/PointLightQuadCullingVS.cso");
	if (FAILED(p_device->CreateVertexShader(compiledQuadVertexShader.data(), compiledQuadVertexShader.size(), NULL, &m_quadVertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create quadCulling vertex shader.");
		return false;
	}

	// Create geometry shader from buffer.
	std::vector<unsigned char> compiledQuadGeometryShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Composition/PointLightQuadCullingGS.cso");
	if (FAILED(p_device->CreateGeometryShader(compiledQuadGeometryShader.data(), compiledQuadGeometryShader.size(), NULL, &m_quadGeometryShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create quadCulling geometry vertex shader.");
		return false;
	}

	ConsolePrintSuccess("ScreenSpace.cpp: QuadCulling geometry shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_GSVersion);

	// Create the pixel shader.
	std::vector<unsigned char> compiledPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Composition/CompositionPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledPixelShader.data(), compiledPixelShader.size(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create pixel shader");
		return false;
	}

	// Create the pixel shader.
	std::vector<unsigned char> compiledQuadPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Composition/PointLightQuadCullingPS.cso");
	if (FAILED(p_device->CreatePixelShader(compiledQuadPixelShader.data(), compiledQuadPixelShader.size(), NULL, &m_quadPixelShader)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create quadCulling pixel shader");
		return false;
	}

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

	InitializeDOF(p_device, p_context);

	return true;
}

bool ScreenSpace::InitializeSSAO(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	std::string shaderPath = SHADER_PATH;

	// Create the pixel shader.
	std::vector<unsigned char> compiledSSAOPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/SSAO/SSAOPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledSSAOPixelShader.data(), compiledSSAOPixelShader.size(), NULL, &m_pixelShaderSSAO)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create SSAO pixel shader");
		return false;
	}

	// Create the pixel shader.
	std::vector<unsigned char> compiledBlurHSSAOPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/SSAO/SSAOBlurHPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledBlurHSSAOPixelShader.data(), compiledBlurHSSAOPixelShader.size(), NULL, &m_pixelShaderSSAOBlurH)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create SSAO Blur H pixel shader");
		return false;
	}

	// Create the pixel shader.
	std::vector<unsigned char> compiledBlurVSSAOPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/SSAO/SSAOBlurVPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledBlurVSSAOPixelShader.data(), compiledBlurVSSAOPixelShader.size(), NULL, &m_pixelShaderSSAOBlurV)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create SSAO pixel shader");
		return false;
	}

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

bool ScreenSpace::InitializeDOF(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	std::string shaderPath = SHADER_PATH;

	// Create the pixel shader.
	std::vector<unsigned char> compiledDOFBlurHPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/DOF/DOFBlurHPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledDOFBlurHPixelShader.data(), compiledDOFBlurHPixelShader.size(), NULL, &m_pixelShaderDOFBlurH)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create DOF Blur H pixel shader");
		return false;
	}

	// Create the pixel shader.
	std::vector<unsigned char> compiledDOFBlurVPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/DOF/DOFBlurVPixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledDOFBlurVPixelShader.data(), compiledDOFBlurVPixelShader.size(), NULL, &m_pixelShaderDOFBlurV)))
	{
		ConsolePrintErrorAndQuit("ScreenSpace.cpp: Failed to create DOF Blur V pixel shader");
		return false;
	}

	return true;
}

void ScreenSpace::Shutdown()
{
//#if defined(_DEBUG) || defined(PROFILE)
//	// Only works if device is created with the D3D10 or D3D11 debug layer, or when attached to PIX for Windows
//	const char c_szName[] = "PIXELSHADER.DEBUG";
//	m_pixelShader->SetPrivateData(WKPDID_D3DDebugObjectName, sizeof(c_szName) - 1, c_szName);
//#endif
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

	if (m_samplerDepth)
	{
		m_samplerDepth->Release();
		m_samplerDepth = nullptr;
	}
	if (m_samplerRandom)
	{
		m_samplerRandom->Release();
		m_samplerRandom = nullptr;
	}
	if (m_samplerBlur)
	{
		m_samplerBlur->Release();
		m_samplerBlur = nullptr;
	}
	if (m_pixelShaderDOFBlurH)
	{
		m_pixelShaderDOFBlurH->Release();
		m_pixelShaderDOFBlurH = nullptr;
	}
	if (m_pixelShaderDOFBlurV)
	{
		m_pixelShaderDOFBlurV->Release();
		m_pixelShaderDOFBlurV = nullptr;
	}

	if (m_quadVertexShader)
	{
		m_quadVertexShader->Release();
		m_quadVertexShader = nullptr;
	}

	if (m_quadGeometryShader)
	{
		m_quadGeometryShader->Release();
		m_quadGeometryShader = nullptr;
	}

	if (m_quadPixelShader)
	{
		m_quadPixelShader->Release();
		m_quadPixelShader = nullptr;
	}
}

void ScreenSpace::Render(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_color, ID3D11ShaderResourceView* p_depth, ID3D11ShaderResourceView* p_ssao)
{
	// Set parameters and then render.

	// Render fullscreen triangle
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

void ScreenSpace::RenderLights(ID3D11DeviceContext* p_context)
{
	// Render point lights
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);

	p_context->VSSetShader(m_quadVertexShader, 0, 0);
	p_context->GSSetShader(m_quadGeometryShader, 0, 0);
	p_context->PSSetShader(m_quadPixelShader, 0, 0);

	int activeLights = PointLights::GetInstance()->GetLightCount();
	p_context->Draw(activeLights, 0);
	PointLights::GetInstance()->ClearLights();

	p_context->GSSetShader(0, 0, 0);
}

void ScreenSpace::RenderSSAO(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_depth)
{
	// Set parameters and then render.
	ID3D11ShaderResourceView* textures[3];
	textures[0] = p_normal;
	textures[1] = p_depth;
	textures[2] = m_randomVectors;

	p_context->PSSetShaderResources(3, 3, &textures[0]);
	p_context->PSSetSamplers(2, 1, &m_samplerDepth);
	p_context->PSSetSamplers(3, 1, &m_samplerRandom);
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
	p_context->PSSetSamplers(4, 1, &m_samplerBlur);
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

void ScreenSpace::DOF(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_depth, bool p_horizontal)
{
	// Set parameters and then render.
	ID3D11ShaderResourceView* textures[2];
	textures[0] = p_texture;
	textures[1] = p_depth;

	p_context->PSSetShaderResources(3, 2, &textures[0]);
	p_context->PSSetSamplers(0, 1, &m_samplerBlur);
	p_context->IASetVertexBuffers(0, 0, 0, 0, 0);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(0);
	p_context->VSSetShader(m_vertexShader, 0, 0);

	if (p_horizontal)
	{
		p_context->PSSetShader(m_pixelShaderDOFBlurH, 0, 0);
	}
	else
	{
		p_context->PSSetShader(m_pixelShaderDOFBlurV, 0, 0);
	}

	p_context->Draw(3, 0);
}

void ScreenSpace::UpdateLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_lightViewMatrix = p_viewMatrix;
	m_lightProjectionMatrix = p_projectionMatrix;
}

void ScreenSpace::UpdateFrameBuffer(ID3D11DeviceContext* p_context, DirectionalLight& p_dlight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view)
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
	DirectX::XMFLOAT4X4 lView = p_view;
	lView._41 = 0.0f;
	lView._42 = 0.0f;
	lView._43 = 0.0f;
	frameBuffer->m_directionalLight.m_direction = DirectX::XMVector3TransformNormal(frameBuffer->m_directionalLight.m_direction, DirectX::XMLoadFloat4x4(&lView));
	frameBuffer->m_directionalLight.m_direction = DirectX::XMVector3Normalize(frameBuffer->m_directionalLight.m_direction);

	DirectX::XMStoreFloat4x4(&frameBuffer->m_projection, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&p_projection)));

	DirectX::XMMATRIX viewInverse = DirectX::XMMatrixInverse(&DirectX::XMMatrixDeterminant(DirectX::XMLoadFloat4x4(&p_view)), DirectX::XMLoadFloat4x4(&p_view));
	DirectX::XMMATRIX projectedLightSpace = DirectX::XMMatrixMultiply(DirectX::XMMatrixMultiply(viewInverse, DirectX::XMLoadFloat4x4(&m_lightViewMatrix)), DirectX::XMLoadFloat4x4(&m_lightProjectionMatrix));
	DirectX::XMStoreFloat4x4(&frameBuffer->m_projectedLightSpace, DirectX::XMMatrixTranspose(projectedLightSpace));

	// Unlock the constant buffer.
	p_context->Unmap(m_frameBuffer, 0);

	// Set the position of the frame constant buffer in the vertex shader.
	p_context->VSSetConstantBuffers(7, 1, &m_frameBuffer);
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

void ScreenSpace::SetLightBuffer(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_lightSRV)
{
	p_context->VSSetShaderResources(7, 1, &p_lightSRV);
	p_context->PSSetShaderResources(7, 1, &p_lightSRV);
}