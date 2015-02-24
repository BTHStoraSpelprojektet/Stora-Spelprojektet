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
		ConsolePrintErrorAndQuit("Failed to create scene frame buffer.");
		return false;
	}



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
	m_vertexShader->Release();

	m_pixelShader->Release();

	m_frameBuffer->Release();
}

void ScreenSpace::Render(ID3D11DeviceContext* p_context, ID3D11ShaderResourceView* p_normal, ID3D11ShaderResourceView* p_color, ID3D11ShaderResourceView* p_depth)
{
	// Set parameters and then render.
	ID3D11ShaderResourceView* textures[3];
	textures[0] = p_normal;
	textures[1] = p_color;
	textures[2] = p_depth;
	
	p_context->PSSetShaderResources(3, 3, &textures[0]);

	p_context->IASetVertexBuffers(0, 0, 0, 0, 0);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(0);
	p_context->VSSetShader(m_vertexShader, 0, 0);
	p_context->PSSetShader(m_pixelShader, 0, 0);

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