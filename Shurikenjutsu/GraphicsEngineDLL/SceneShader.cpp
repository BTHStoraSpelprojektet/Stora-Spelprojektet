#include "stdafx.h"
#include "SceneShader.h"
#include "InstanceManager.h"
#include "VisibilityComputer.h"
#include "..\CommonLibs\DirectXTex\WICTextureLoader\WICTextureLoader.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include "CompiledShaderReader.h"
#include "ShaderGlobals.h"

bool SceneShader::Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context)
{
	// Create the vertex shaders.
	std::string shaderPath = SHADER_PATH;

	std::vector<unsigned char> compiledVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Scene/VertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledVertexShader.data(), compiledVertexShader.size(), NULL, &m_vertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene vertex shader.");
		return false;
	}

	std::vector<unsigned char> compiledSSReverseVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/ShadowShapes/SSReverseVertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledSSReverseVertexShader.data(), compiledSSReverseVertexShader.size(), NULL, &m_reversedShadowVertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create sSReverseVertexShader vertex shader.");
		return false;
	}

	std::vector<unsigned char> compiledInstanceVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Scene/InstanceShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledInstanceVertexShader.data(), compiledInstanceVertexShader.size(), NULL, &m_instanceShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create instance vertex shader.");
		return false;
	}

	std::vector<unsigned char> compiledAnimatedVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Scene/AnimatedVertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledAnimatedVertexShader.data(), compiledAnimatedVertexShader.size(), NULL, &m_animatedVertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene animated vertex shader.");
		return false;
	}

	std::vector<unsigned char> compiledLineVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Line/LineVertexShader.cso");
	if (FAILED(p_device->CreateVertexShader(compiledLineVertexShader.data(), compiledLineVertexShader.size(), NULL, &m_lineVertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create line vertex shader.");
		return false;
	}

	std::vector<unsigned char> compiledOutliningVertexShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Scene/VertexShaderOutlining.cso");
	if (FAILED(p_device->CreateVertexShader(compiledOutliningVertexShader.data(), compiledOutliningVertexShader.size(), NULL, &m_vertexShaderOutlining)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene vertex shader.");
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC layout[4];
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

	layout[2].SemanticName = "NORMAL";
	layout[2].SemanticIndex = 0;
	layout[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[2].InputSlot = 0;
	layout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[2].InstanceDataStepRate = 0;

	layout[3].SemanticName = "TANGENT";
	layout[3].SemanticIndex = 0;
	layout[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[3].InputSlot = 0;
	layout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[3].InstanceDataStepRate = 0;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layout, size, compiledVertexShader.data(), compiledVertexShader.size(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene vertex input layout.");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC instanceLayout[8];
	unsigned int instancedSize;
	
	instanceLayout[0].SemanticName = "POSITION";
	instanceLayout[0].SemanticIndex = 0;
	instanceLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	instanceLayout[0].InputSlot = 0;
	instanceLayout[0].AlignedByteOffset = 0;
	instanceLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	instanceLayout[0].InstanceDataStepRate = 0;

	instanceLayout[1].SemanticName = "TEXCOORD";
	instanceLayout[1].SemanticIndex = 0;
	instanceLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	instanceLayout[1].InputSlot = 0;
	instanceLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instanceLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	instanceLayout[1].InstanceDataStepRate = 0;

	instanceLayout[2].SemanticName = "NORMAL";
	instanceLayout[2].SemanticIndex = 0;
	instanceLayout[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	instanceLayout[2].InputSlot = 0;
	instanceLayout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instanceLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	instanceLayout[2].InstanceDataStepRate = 0;

	instanceLayout[3].SemanticName = "TANGENT";
	instanceLayout[3].SemanticIndex = 0;
	instanceLayout[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	instanceLayout[3].InputSlot = 0;
	instanceLayout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instanceLayout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	instanceLayout[3].InstanceDataStepRate = 0;

	instanceLayout[4].SemanticName = "INSTANCEPOS";
	instanceLayout[4].SemanticIndex = 0;
	instanceLayout[4].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instanceLayout[4].InputSlot = 1;
	instanceLayout[4].AlignedByteOffset = 0;
	instanceLayout[4].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instanceLayout[4].InstanceDataStepRate = 1;

	instanceLayout[5].SemanticName = "INSTANCEPOS";
	instanceLayout[5].SemanticIndex = 1;
	instanceLayout[5].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instanceLayout[5].InputSlot = 1;
	instanceLayout[5].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instanceLayout[5].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instanceLayout[5].InstanceDataStepRate = 1;

	instanceLayout[6].SemanticName = "INSTANCEPOS";
	instanceLayout[6].SemanticIndex = 2;
	instanceLayout[6].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instanceLayout[6].InputSlot = 1;
	instanceLayout[6].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instanceLayout[6].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instanceLayout[6].InstanceDataStepRate = 1;
	
	instanceLayout[7].SemanticName = "INSTANCEPOS";
	instanceLayout[7].SemanticIndex = 3;
	instanceLayout[7].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	instanceLayout[7].InputSlot = 1;
	instanceLayout[7].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	instanceLayout[7].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	instanceLayout[7].InstanceDataStepRate = 1;


	// Compute size of layout.
	instancedSize = sizeof(instanceLayout) / sizeof(instanceLayout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(instanceLayout, instancedSize, compiledInstanceVertexShader.data(), compiledInstanceVertexShader.size(), &m_instanceLayout)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene vertex input layout.");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC animationLayout[6];
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
	animationLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	animationLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[1].InstanceDataStepRate = 0;

	animationLayout[2].SemanticName = "NORMAL";
	animationLayout[2].SemanticIndex = 0;
	animationLayout[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	animationLayout[2].InputSlot = 0;
	animationLayout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	animationLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[2].InstanceDataStepRate = 0;

	animationLayout[3].SemanticName = "TANGENT";
	animationLayout[3].SemanticIndex = 0;
	animationLayout[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	animationLayout[3].InputSlot = 0;
	animationLayout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	animationLayout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[3].InstanceDataStepRate = 0;

	animationLayout[4].SemanticName = "WEIGHT";
	animationLayout[4].SemanticIndex = 0;
	animationLayout[4].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	animationLayout[4].InputSlot = 0;
	animationLayout[4].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	animationLayout[4].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[4].InstanceDataStepRate = 0;

	animationLayout[5].SemanticName = "BONEINDEX";
	animationLayout[5].SemanticIndex = 0;
	animationLayout[5].Format = DXGI_FORMAT_R8G8B8A8_UINT;
	animationLayout[5].InputSlot = 0;
	animationLayout[5].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	animationLayout[5].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	animationLayout[5].InstanceDataStepRate = 0;

	// Compute size of layout.
	animationSize = sizeof(animationLayout) / sizeof(animationLayout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(animationLayout, animationSize, compiledAnimatedVertexShader.data(), compiledAnimatedVertexShader.size(), &m_animatedLayout)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene animated vertex input layout.");
		return false;
	}

	D3D11_INPUT_ELEMENT_DESC lineLayout[1];
	unsigned int lineSize;

	lineLayout[0].SemanticName = "POSITION";
	lineLayout[0].SemanticIndex = 0;
	lineLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	lineLayout[0].InputSlot = 0;
	lineLayout[0].AlignedByteOffset = 0;
	lineLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	lineLayout[0].InstanceDataStepRate = 0;

	// Compute size of layout.
	lineSize = sizeof(lineLayout) / sizeof(lineLayout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(lineLayout, lineSize, compiledLineVertexShader.data(), compiledLineVertexShader.size(), &m_lineLayout)))
	{
		ConsolePrintErrorAndQuit("Failed to create line vertex input layout.");
		return false;
	}

	ConsolePrintSuccess("Scene vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	D3D11_INPUT_ELEMENT_DESC layoutOutlining[3];
	unsigned int outlineSize;

	layoutOutlining[0].SemanticName = "POSITION";
	layoutOutlining[0].SemanticIndex = 0;
	layoutOutlining[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layoutOutlining[0].InputSlot = 0;
	layoutOutlining[0].AlignedByteOffset = 0;
	layoutOutlining[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layoutOutlining[0].InstanceDataStepRate = 0;

	layoutOutlining[1].SemanticName = "WEIGHT";
	layoutOutlining[1].SemanticIndex = 0;
	layoutOutlining[1].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layoutOutlining[1].InputSlot = 0;
	layoutOutlining[1].AlignedByteOffset = 44;
	layoutOutlining[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layoutOutlining[1].InstanceDataStepRate = 0;

	layoutOutlining[2].SemanticName = "BONEINDEX";
	layoutOutlining[2].SemanticIndex = 0;
	layoutOutlining[2].Format = DXGI_FORMAT_R8G8B8A8_UINT;
	layoutOutlining[2].InputSlot = 0;
	layoutOutlining[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layoutOutlining[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layoutOutlining[2].InstanceDataStepRate = 0;


	// Compute size of layout.
	outlineSize = sizeof(layoutOutlining) / sizeof(layoutOutlining[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layoutOutlining, outlineSize, compiledOutliningVertexShader.data(), compiledOutliningVertexShader.size(), &m_layoutOutlining)))
	{
		ConsolePrintErrorAndQuit("Failed to create outline vertex input layout.");
		return false;
	}

	ConsolePrintSuccess("Outlining vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Create PixelShaders.
	std::vector<unsigned char> compiledPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Scene/PixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledPixelShader.data(), compiledPixelShader.size(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene pixel shader");
		return false;
	}

	std::vector<unsigned char> compiledForwardPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Scene/PixelShaderForward.cso");
	if (FAILED(p_device->CreatePixelShader(compiledForwardPixelShader.data(), compiledForwardPixelShader.size(), NULL, &m_pixelShaderForward)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene pixel shader");
		return false;
	}

	std::vector<unsigned char> compiledReversePixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/ShadowShapes/SSReversePixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledReversePixelShader.data(), compiledReversePixelShader.size(), NULL, &m_reversedShadowPixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create reversed shadow pixel shader");
		return false;
	}

	ConsolePrintSuccess("Reversed shadow pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

	std::vector<unsigned char> compiledLinePixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Line/LinePixelShader.cso");
	if (FAILED(p_device->CreatePixelShader(compiledLinePixelShader.data(), compiledLinePixelShader.size(), NULL, &m_linePixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create line pixel shader");
		return false;
	}

	std::vector<unsigned char> compiledOutliningPixelShader = CompiledShaderReader::ReadShaderData(shaderPath + "Shaders/Scene/PixelShaderOutlining.cso");
	if (FAILED(p_device->CreatePixelShader(compiledOutliningPixelShader.data(), compiledOutliningPixelShader.size(), NULL, &m_pixelShaderOutlining)))
	{
		ConsolePrintErrorAndQuit("Failed to create line pixel shader");
		return false;
	}

	ConsolePrintSuccess("Scene pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

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
	if (FAILED(p_device->CreateRasterizerState(&rasterizer, &m_rasterizerStateBackCulled)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene back face culled rasterrizer state.");
		return false;
	}

	rasterizer.CullMode = D3D11_CULL_NONE;

	// Create the none culled rasterizer state.
	if (FAILED(p_device->CreateRasterizerState(&rasterizer, &m_rasterizerStateNoneCulled)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene none culled rasterizer state.");
		return false;
	}

	TurnOnBackFaceCulling(p_context);

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

	sampler.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampler.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampler.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

	// Create the shadow map sampler state.
	if (FAILED(p_device->CreateSamplerState(&sampler, &m_samplerShadowMapState)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene shadow sampler state.");
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
		ConsolePrintErrorAndQuit("Failed to create scene matrix buffer.");
		return false;
	}

	// Create the matrix buffer description. for outlining
	D3D11_BUFFER_DESC matrixBufferOutlining;
	matrixBufferOutlining.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferOutlining.ByteWidth = sizeof(MatrixBufferOutlining);
	matrixBufferOutlining.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferOutlining.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferOutlining.MiscFlags = 0;
	matrixBufferOutlining.StructureByteStride = 0;

	// Create the matrix buffer. outlining
	if (FAILED(p_device->CreateBuffer(&matrixBufferOutlining, NULL, &m_matrixBufferOutlining)))
	{
		ConsolePrintErrorAndQuit("Failed to create Outlining matrix buffer.");
		return false;
	}

	// Setup the description of the dynamic fog constant buffer that is in the vertex shader.
	D3D11_BUFFER_DESC fogBuffer;
	fogBuffer.Usage = D3D11_USAGE_DYNAMIC;
	fogBuffer.ByteWidth = sizeof(FogBuffer);
	fogBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	fogBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	fogBuffer.MiscFlags = 0;
	fogBuffer.StructureByteStride = 0;

	// Create the fog buffer.
	if (FAILED(p_device->CreateBuffer(&fogBuffer, NULL, &m_fogBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene fog buffer.");
		return false;
	}

	// Setup the description of the dynamic fog constant buffer that is in the vertex shader.
	D3D11_BUFFER_DESC colorBuffer;
	colorBuffer.Usage = D3D11_USAGE_DYNAMIC;
	colorBuffer.ByteWidth = sizeof(ColorBuffer);
	colorBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	colorBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	colorBuffer.MiscFlags = 0;
	colorBuffer.StructureByteStride = 0;

	// Create the fog buffer.
	if (FAILED(p_device->CreateBuffer(&colorBuffer, NULL, &m_colorBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create color buffer.");
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
		ConsolePrintErrorAndQuit("Failed to create scene frame buffer.");
		return false;
	}

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
		ConsolePrintErrorAndQuit("Failed to create scene animated buffer.");
		return false;
	}

	return true;
}

void SceneShader::Shutdown()
{
//#if defined(_DEBUG) || defined(PROFILE)
//	// Only works if device is created with the D3D10 or D3D11 debug layer, or when attached to PIX for Windows
//	const char c_szName[] = "PIXELSHADER.DEBUG";
//	m_pixelShader->SetPrivateData(WKPDID_D3DDebugObjectName,sizeof(c_szName) - 1, c_szName);
//#endif
	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

	if (m_reversedShadowVertexShader)
	{
		m_reversedShadowVertexShader->Release();
		m_reversedShadowVertexShader = 0;
	}

	if (m_instanceShader)
	{
		m_instanceShader->Release();
		m_instanceShader = 0;
	}

	if (m_animatedVertexShader)
	{
		m_animatedVertexShader->Release();
		m_animatedVertexShader = 0;
	}

	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	if (m_pixelShaderForward)
	{
		m_pixelShaderForward->Release();
		m_pixelShaderForward = 0;
	}

	if (m_reversedShadowPixelShader)
	{
		m_reversedShadowPixelShader->Release();
		m_reversedShadowPixelShader = 0;
	}

	if (m_lineVertexShader)
	{
		m_lineVertexShader->Release();
		m_lineVertexShader = 0;
	}

	if (m_linePixelShader)
	{
		m_linePixelShader->Release();
		m_linePixelShader = 0;
	}

	if (m_vertexShaderOutlining)
	{
		m_vertexShaderOutlining->Release();
		m_vertexShaderOutlining = 0;
	}

	if (m_pixelShaderOutlining)
	{
		m_pixelShaderOutlining->Release();
		m_pixelShaderOutlining = 0;
	}

	if (m_layoutOutlining)
	{
		m_layoutOutlining->Release();
		m_layoutOutlining = 0;
	}

	if (m_layout)
	{
		m_layout->Release();
		m_layout = 0;
	}

	if (m_instanceLayout)
	{
		m_instanceLayout->Release();
		m_instanceLayout = 0;
	}

	if (m_animatedLayout)
	{
		m_animatedLayout->Release();
		m_animatedLayout = 0;
	}

	if (m_lineLayout)
	{
		m_lineLayout->Release();
		m_lineLayout = 0;
	}

	if (m_samplerState)
	{
		m_samplerState->Release();
		m_samplerState = 0;
	}

	if (m_samplerShadowMapState)
	{
		m_samplerShadowMapState->Release();
		m_samplerShadowMapState = 0;
	}

	if (m_rasterizerStateBackCulled)
	{
		m_rasterizerStateBackCulled->Release();
		m_rasterizerStateBackCulled = 0;
	}

	if (m_rasterizerStateNoneCulled)
	{
		m_rasterizerStateNoneCulled->Release();
		m_rasterizerStateNoneCulled = 0;
	}

	if (m_shadowMap != nullptr)
	{
		m_shadowMap->Release();
		m_shadowMap = nullptr;
	}

	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	if (m_matrixBufferOutlining)
	{
		m_matrixBufferOutlining->Release();
		m_matrixBufferOutlining = 0;
	}

	if (m_fogBuffer)
	{
		m_fogBuffer->Release();
		m_fogBuffer = 0;
	}

	if (m_animationMatrixBuffer)
	{
		m_animationMatrixBuffer->Release();
		m_animationMatrixBuffer = 0;
	}

	if (m_frameBuffer)
	{
		m_frameBuffer->Release();
		m_frameBuffer = 0;
	}

	if (m_colorBuffer)
	{
		m_colorBuffer->Release();
		m_colorBuffer = 0;
	}
}

void SceneShader::PrepareRender(ID3D11DeviceContext* p_context)
{
	p_context->IASetInputLayout(m_layout);
	p_context->VSSetShader(m_vertexShader, NULL, 0);
}

void SceneShader::Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(Vertex);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetShaderResources(1, 1, &p_normalMap);	

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	
	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::RenderForward(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(Vertex);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetShaderResources(1, 1, &p_normalMap);
	p_context->PSSetShaderResources(2, 1, &m_shadowMap);

	p_context->PSSetSamplers(0, 1, &m_samplerState);
	p_context->PSSetSamplers(1, 1, &m_samplerShadowMapState);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);

	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShaderForward, NULL, 0);

	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::RenderReversedShadows(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(Vertex);
	const unsigned int offset = 0;

	p_context->VSSetShader(m_reversedShadowVertexShader, NULL, 0);
	p_context->PSSetShader(m_reversedShadowPixelShader, NULL, 0);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);

	UpdateReversedShadowMatrices(p_context);
	p_context->PSSetShaderResources(0, 1, &p_visibilityMap);
	p_context->PSSetShaderResources(1, 1, &p_texture);
	p_context->PSSetSamplers(0, 1, &m_samplerState);

	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::PrepareRenderAnimated(ID3D11DeviceContext* p_context)
{
	p_context->PSSetShaderResources(2, 1, &m_shadowMap);
	p_context->PSSetSamplers(0, 1, &m_samplerState);
	p_context->PSSetSamplers(1, 1, &m_samplerShadowMapState);

	p_context->IASetInputLayout(m_animatedLayout);
	p_context->VSSetShader(m_animatedVertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);
}

void SceneShader::RenderAnimated(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(VertexAnimated);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);
	UpdateAnimatedBuffer(p_context, p_boneTransforms);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetShaderResources(1, 1, &p_normalMap);	

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);

	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::RenderAnimatedOutlining(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms, DirectX::XMFLOAT4 p_color)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(VertexAnimated);
	const unsigned int offset = 0;

	UpdateWorldMatrixOutlining(p_context, p_worldMatrix, p_color);
	UpdateAnimatedBuffer(p_context, p_boneTransforms);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layoutOutlining);

	p_context->VSSetShader(m_vertexShaderOutlining, NULL, 0);
	p_context->PSSetShader(m_pixelShaderOutlining, NULL, 0);

	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::RenderAnimatedOutliningDepth(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(VertexAnimated);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);
	UpdateAnimatedBuffer(p_context, p_boneTransforms);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_animatedLayout);

	p_context->VSSetShader(m_animatedVertexShader, NULL, 0);
	p_context->PSSetShader(0, 0, 0);

	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::RenderLine(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix)
{
	// Set parameters and then render.
	unsigned int stride = sizeof(DirectX::XMFLOAT3);
	const unsigned int offset = 0;

	UpdateWorldMatrix(p_context, p_worldMatrix);
	UpdateColorBuffer(p_context, p_color.x, p_color.y, p_color.z);

	p_context->IASetVertexBuffers(0, 1, &p_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	p_context->IASetInputLayout(m_lineLayout);

	p_context->VSSetShader(m_lineVertexShader, NULL, 0);
	p_context->PSSetShader(m_linePixelShader, NULL, 0);

	p_context->Draw(p_numberOfVertices, 0);
}

void SceneShader::UpdateViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_viewMatrix = p_viewMatrix;
	m_projectionMatrix = p_projectionMatrix;
}

void SceneShader::UpdateLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_lightViewMatrix = p_viewMatrix;
	m_lightProjectionMatrix = p_projectionMatrix;
}

void SceneShader::UpdateShadowMap(ID3D11ShaderResourceView* p_shadowMap)
{
	m_shadowMap = p_shadowMap;
}

void SceneShader::UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix)
{
	DirectX::XMFLOAT4X4 worldMatrix = p_worldMatrix;
	DirectX::XMFLOAT4X4 viewMatrix = m_viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix = m_projectionMatrix;

	DirectX::XMFLOAT4X4 lightViewMatrix = m_lightViewMatrix;
	DirectX::XMFLOAT4X4 lightProjectionMatrix = m_lightProjectionMatrix;

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&worldMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&worldMatrix)));
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&viewMatrix)));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&projectionMatrix)));

	DirectX::XMStoreFloat4x4(&lightViewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&lightViewMatrix)));
	DirectX::XMStoreFloat4x4(&lightProjectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&lightProjectionMatrix)));

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map scene matrix buffer.");
		return;
	}

	// Get pointer to the matrix buffer data.
	MatrixBuffer* matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Set matrices in buffer.
	matrixBuffer->m_worldMatrix = DirectX::XMLoadFloat4x4(&worldMatrix);
	matrixBuffer->m_viewMatrix = DirectX::XMLoadFloat4x4(&viewMatrix);
	matrixBuffer->m_projectionMatrix = DirectX::XMLoadFloat4x4(&projectionMatrix);

	matrixBuffer->m_lightViewMatrix = DirectX::XMLoadFloat4x4(&lightViewMatrix);
	matrixBuffer->m_lightProjectionMatrix = DirectX::XMLoadFloat4x4(&lightProjectionMatrix);

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_matrixBuffer, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
}

void SceneShader::UpdateReversedShadowMatrices(ID3D11DeviceContext* p_context)
{
	DirectX::XMFLOAT4X4 identity;
	DirectX::XMStoreFloat4x4(&identity, DirectX::XMMatrixIdentity());

	DirectX::XMFLOAT4X4 worldMatrix = identity;
	DirectX::XMFLOAT4X4 viewMatrix = m_viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix = m_projectionMatrix;

	DirectX::XMFLOAT4X4 lightViewMatrix = VisibilityComputer::GetInstance().GetViewPolygonMatrix();
	DirectX::XMFLOAT4X4 lightProjectionMatrix = VisibilityComputer::GetInstance().GetProjectionPolygonMatrix();

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&worldMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&worldMatrix)));
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&viewMatrix)));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&projectionMatrix)));

	DirectX::XMStoreFloat4x4(&lightViewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&lightViewMatrix)));
	DirectX::XMStoreFloat4x4(&lightProjectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&lightProjectionMatrix)));

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map scene matrix buffer.");
		return;
	}

	// Get pointer to the matrix buffer data.
	MatrixBuffer* matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Set matrices in buffer.
	matrixBuffer->m_worldMatrix = DirectX::XMLoadFloat4x4(&worldMatrix);
	matrixBuffer->m_viewMatrix = DirectX::XMLoadFloat4x4(&viewMatrix);
	matrixBuffer->m_projectionMatrix = DirectX::XMLoadFloat4x4(&projectionMatrix);

	matrixBuffer->m_lightViewMatrix = DirectX::XMLoadFloat4x4(&lightViewMatrix);
	matrixBuffer->m_lightProjectionMatrix = DirectX::XMLoadFloat4x4(&lightProjectionMatrix);

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_matrixBuffer, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
}

void SceneShader::UpdateFogBuffer(ID3D11DeviceContext* p_context, float p_fogStart, float p_fogEnd, float p_fogDensity)
{
	// Lock the fog constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_fogBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map scene fog buffer.");
		return;
	}

	// Get a pointer to the data in the constant buffer.
	FogBuffer* fogBuffer = (FogBuffer*)mappedBuffer.pData;

	// Copy the fog information into the fog constant buffer.
	fogBuffer->m_fogStart = p_fogStart;
	fogBuffer->m_fogEnd = p_fogEnd;
	fogBuffer->m_fogDensity = p_fogDensity;

	// Unlock the constant buffer.
	p_context->Unmap(m_fogBuffer, 0);

	// Set the position of the fog constant buffer in the vertex shader.
	p_context->VSSetConstantBuffers(1, 1, &m_fogBuffer);
}

void SceneShader::UpdateColorBuffer(ID3D11DeviceContext* p_context, float R, float G, float B)
{
	// Lock the color constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_colorBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map color buffer.");
		return;
	}

	// Get a pointer to the data in the constant buffer.
	ColorBuffer* colorBuffer = (ColorBuffer*)mappedBuffer.pData;

	// Copy the fog information into the fog constant buffer.
	colorBuffer->m_color.x = R;
	colorBuffer->m_color.y = G;
	colorBuffer->m_color.z = B;
	colorBuffer->m_color.w = 1.0f;

	// Unlock the constant buffer.
	p_context->Unmap(m_colorBuffer, 0);

	// Set the position of the fog constant buffer in the vertex shader.
	p_context->VSSetConstantBuffers(3, 1, &m_colorBuffer);
}

void SceneShader::UpdateWorldMatrixOutlining(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix, DirectX::XMFLOAT4 p_color)
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
	if (FAILED(p_context->Map(m_matrixBufferOutlining, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map outlining matrix buffer.");
		return;
	}

	// Get pointer to the matrix buffer data.
	MatrixBufferOutlining* matrixBuffer = (MatrixBufferOutlining*)mappedBuffer.pData;

	// Set matrices in buffer.
	matrixBuffer->m_worldMatrix = DirectX::XMLoadFloat4x4(&worldMatrix);
	matrixBuffer->m_viewMatrix = DirectX::XMLoadFloat4x4(&viewMatrix);
	matrixBuffer->m_projectionMatrix = DirectX::XMLoadFloat4x4(&projectionMatrix);
	matrixBuffer->m_color = p_color;

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_matrixBufferOutlining, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBufferOutlining);
}

void SceneShader::UpdateAnimatedBuffer(ID3D11DeviceContext* p_context, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_animationMatrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map scene animated matrix buffer.");
		return;
	}

	// Get pointer to the matrix buffer data.
	AnimationMatrixBuffer* animatedMatrixBuffer = (AnimationMatrixBuffer*)mappedBuffer.pData;

	// Set matrices in buffer.
	for (unsigned int i = 0; i < p_boneTransforms.size(); i++)
		animatedMatrixBuffer->m_boneTransforms[i] = DirectX::XMLoadFloat4x4(&p_boneTransforms[i]);

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_animationMatrixBuffer, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(2, 1, & m_animationMatrixBuffer);
}

void SceneShader::TurnOnBackFaceCulling(ID3D11DeviceContext* p_context)
{
	p_context->RSSetState(m_rasterizerStateBackCulled);
}
void SceneShader::TurnOffBackFaceCulling(ID3D11DeviceContext* p_context)
{
	p_context->RSSetState(m_rasterizerStateNoneCulled);
}
void SceneShader::UpdateFrameBuffer(ID3D11DeviceContext* p_context, DirectionalLight& p_dlight)
{
	// Lock the "every frame" constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_frameBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map scene frame buffer.");
		return;
	}

	// Get a pointer to the data in the constant buffer.
	FrameBuffer* frameBuffer = (FrameBuffer*)mappedBuffer.pData;

	// Copy the fog information into the frame constant buffer.
	frameBuffer->m_directionalLight = p_dlight;

	// Unlock the constant buffer.
	p_context->Unmap(m_frameBuffer, 0);

	// Set the position of the frame constant buffer in the vertex shader.
	p_context->PSSetConstantBuffers(0, 1, &m_frameBuffer);
}
ID3D11ShaderResourceView* SceneShader::GetShadowMap()
{
	return m_shadowMap;
}
void SceneShader::SetShadowMapDimensions(ID3D11Device* p_device, ID3D11DeviceContext* p_context, float p_width, float p_height)
{
	ID3D11Buffer* buffer = NULL;

	// Create the cbuffer where size data is stored
	D3D11_BUFFER_DESC bufferDescription;
	bufferDescription.Usage = D3D11_USAGE_DYNAMIC;
	bufferDescription.ByteWidth = sizeof(ShadowMapSizeBuffer);
	bufferDescription.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	bufferDescription.MiscFlags = 0;
	bufferDescription.StructureByteStride = 0;

	// Create the frame buffer.
	if (FAILED(p_device->CreateBuffer(&bufferDescription, NULL, &buffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create scene shadow map dimension buffer.");
	}

	// Lock the size constant buffer so it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map scene shadow map dimension buffer.");
	}

	// Get a pointer to the data in the constant buffer.
	ShadowMapSizeBuffer* sizeBuffer = (ShadowMapSizeBuffer*)mappedBuffer.pData;

	// Copy the fog information into the frame constant buffer.
	sizeBuffer->m_shadowMapWidth = p_width;
	sizeBuffer->m_shadowMapHeight = p_height;

	// Unlock the constant buffer.
	p_context->Unmap(buffer, 0);

	// Set the position of the frame constant buffer in the vertex shader.
	p_context->PSSetConstantBuffers(1, 1, &buffer);

	buffer->Release();
	buffer = 0;
}
///Instancing
void SceneShader::RenderInstance(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex, InstanceManager* p_instanceManager)
{
	// Set parameters and then render.
	unsigned int stride[2];
	unsigned int offset[2];
	ID3D11Buffer* bufferPointers[2];

	stride[0] = sizeof(Vertex);
	stride[1] = sizeof(DirectX::XMFLOAT4X4);

	offset[0] = 0;
	offset[1] = 0;

	bufferPointers[0] = p_mesh;
	bufferPointers[1] =	p_instanceManager->GetInstanceBuffer(p_instanceIndex);

	UpdateWorldMatrix(p_context, p_worldMatrix);

	p_context->PSSetShaderResources(0, 1, &p_texture);
	p_context->PSSetShaderResources(1, 1, &p_normalMap);
	p_context->PSSetShaderResources(2, 1, &m_shadowMap);
	p_context->PSSetSamplers(0, 1, &m_samplerState);
	p_context->PSSetSamplers(1, 1, &m_samplerShadowMapState);

	p_context->IASetVertexBuffers(0, 2, bufferPointers, stride, offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_instanceLayout);

	p_context->VSSetShader(m_instanceShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	p_context->DrawInstanced(p_numberOfVertices, p_instanceManager->GetNumberOfInstances(p_instanceIndex), 0, 0);
}