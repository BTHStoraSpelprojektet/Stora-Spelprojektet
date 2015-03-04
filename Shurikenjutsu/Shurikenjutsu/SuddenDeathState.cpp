#include "SuddenDeathState.h"
#include "GUIText.h"
#include "Globals.h"
#include "GraphicsEngine.h"
#include <D3Dcompiler.h>
#include "ConsoleFunctions.h"
#include "TextureLibrary.h"
#include "Camera.h"

SuddenDeathState::SuddenDeathState()
{

}

SuddenDeathState::~SuddenDeathState()
{

}

void SuddenDeathState::Initialize()
{
	m_UVForward = false;
	m_gasOpacity = 0.0f;
	m_gasHeight = 0.0f;

	m_title = new GUIText();
	m_title->Initialize("Sudden death! Only the center is safe!", 50.0f, 0.0f, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.25f, 0xffffffff);

	// Setup precalculated positions.
	DirectX::XMFLOAT3 positions[12];
	positions[0] = DirectX::XMFLOAT3(-45.0f, m_gasHeight, 52.0f);
	positions[1] = DirectX::XMFLOAT3(45.0f, m_gasHeight, 52.0f);
	positions[2] = DirectX::XMFLOAT3(-45.0f, m_gasHeight, -52.0f);
	positions[3] = DirectX::XMFLOAT3(45.0f, m_gasHeight, -52.0f);
	positions[4] = DirectX::XMFLOAT3(-12.0f, m_gasHeight, 12.0f);
	positions[5] = DirectX::XMFLOAT3(12.0f, m_gasHeight, 12.0f);
	positions[6] = DirectX::XMFLOAT3(-12.0f, m_gasHeight, -12.0f);
	positions[7] = DirectX::XMFLOAT3(12.0f, m_gasHeight, -12.0f);
	positions[8] = DirectX::XMFLOAT3(0.0f, -12.0f, 12.0f);
	positions[9] = DirectX::XMFLOAT3(12.0f, -12.0f, 0.0f);
	positions[10] = DirectX::XMFLOAT3(0.0f, -12.0f, -12.0f);
	positions[11] = DirectX::XMFLOAT3(-12.0f, -12.0f, 0.0f);

	float wallRadius = 12.0f;
	float halfWallRadius = wallRadius * 0.5f;

	// Setup precalculated uv coordinates.
	DirectX::XMFLOAT2 UV[9];
	UV[0] = DirectX::XMFLOAT2(0.5f, 0.0f);
	UV[1] = DirectX::XMFLOAT2(1.0f, 0.0f);
	UV[2] = DirectX::XMFLOAT2(0.5f, 1.0f);
	UV[3] = DirectX::XMFLOAT2(1.0f, 1.0f);
	UV[4] = DirectX::XMFLOAT2(0.75f - (halfWallRadius / 90.0f), 0.5f - (wallRadius / 104.0f));
	UV[5] = DirectX::XMFLOAT2(0.75f + (halfWallRadius / 90.0f), 0.5f - (wallRadius / 104.0f));
	UV[6] = DirectX::XMFLOAT2(0.75f - (halfWallRadius / 90.0f), 0.5f + (wallRadius / 104.0f));
	UV[7] = DirectX::XMFLOAT2(0.75f + (halfWallRadius / 90.0f), 0.5f + (wallRadius / 104.0f));
	UV[8] = DirectX::XMFLOAT2(0.75f, 0.5f);

	// Triangle 1.
	m_mesh[0] = SuddenDeathVertex(positions[0], UV[0]);
	m_originalValues[0] = DirectX::XMFLOAT2(UV[0].x, positions[0].y);
	m_mesh[1] = SuddenDeathVertex(positions[1], UV[1]);
	m_originalValues[1] = DirectX::XMFLOAT2(UV[1].x, positions[1].y);
	m_mesh[2] = SuddenDeathVertex(positions[5], UV[5]);
	m_originalValues[2] = DirectX::XMFLOAT2(UV[5].x, positions[5].y);

	// Triangle 2.
	m_mesh[3] = SuddenDeathVertex(positions[0], UV[0]);
	m_originalValues[3] = DirectX::XMFLOAT2(UV[0].x, positions[0].y);
	m_mesh[4] = SuddenDeathVertex(positions[5], UV[5]);
	m_originalValues[4] = DirectX::XMFLOAT2(UV[5].x, positions[5].y);
	m_mesh[5] = SuddenDeathVertex(positions[4], UV[4]);
	m_originalValues[5] = DirectX::XMFLOAT2(UV[4].x, positions[4].y);

	// Triangle 3.
	m_mesh[6] = SuddenDeathVertex(positions[7], UV[7]);
	m_originalValues[6] = DirectX::XMFLOAT2(UV[7].x, positions[7].y);
	m_mesh[7] = SuddenDeathVertex(positions[1], UV[1]);
	m_originalValues[7] = DirectX::XMFLOAT2(UV[1].x, positions[1].y);
	m_mesh[8] = SuddenDeathVertex(positions[3], UV[3]);
	m_originalValues[8] = DirectX::XMFLOAT2(UV[3].x, positions[3].y);

	// Triangle 4.
	m_mesh[9] = SuddenDeathVertex(positions[5], UV[5]);
	m_originalValues[9] = DirectX::XMFLOAT2(UV[5].x, positions[5].y);
	m_mesh[10] = SuddenDeathVertex(positions[1], UV[1]);
	m_originalValues[10] = DirectX::XMFLOAT2(UV[1].x, positions[1].y);
	m_mesh[11] = SuddenDeathVertex(positions[7], UV[7]);
	m_originalValues[11] = DirectX::XMFLOAT2(UV[7].x, positions[7].y);

	// Triangle 5.
	m_mesh[12] = SuddenDeathVertex(positions[3], UV[3]);
	m_originalValues[12] = DirectX::XMFLOAT2(UV[3].x, positions[3].y);
	m_mesh[13] = SuddenDeathVertex(positions[2], UV[2]);
	m_originalValues[13] = DirectX::XMFLOAT2(UV[2].x, positions[2].y);
	m_mesh[14] = SuddenDeathVertex(positions[6], UV[6]);
	m_originalValues[14] = DirectX::XMFLOAT2(UV[6].x, positions[6].y);

	// Triangle 6.
	m_mesh[15] = SuddenDeathVertex(positions[3], UV[3]);
	m_originalValues[15] = DirectX::XMFLOAT2(UV[3].x, positions[3].y);
	m_mesh[16] = SuddenDeathVertex(positions[6], UV[6]);
	m_originalValues[16] = DirectX::XMFLOAT2(UV[6].x, positions[6].y);
	m_mesh[17] = SuddenDeathVertex(positions[7], UV[7]);
	m_originalValues[17] = DirectX::XMFLOAT2(UV[7].x, positions[7].y);

	// Triangle 7.
	m_mesh[18] = SuddenDeathVertex(positions[2], UV[2]);
	m_originalValues[18] = DirectX::XMFLOAT2(UV[2].x, positions[2].y);
	m_mesh[19] = SuddenDeathVertex(positions[0], UV[0]);
	m_originalValues[19] = DirectX::XMFLOAT2(UV[0].x, positions[0].y);
	m_mesh[20] = SuddenDeathVertex(positions[4], UV[4]);
	m_originalValues[20] = DirectX::XMFLOAT2(UV[4].x, positions[4].y);

	// Triangle 8.
	m_mesh[21] = SuddenDeathVertex(positions[2], UV[2]);
	m_originalValues[21] = DirectX::XMFLOAT2(UV[2].x, positions[2].y);
	m_mesh[22] = SuddenDeathVertex(positions[4], UV[4]);
	m_originalValues[22] = DirectX::XMFLOAT2(UV[4].x, positions[4].y);
	m_mesh[23] = SuddenDeathVertex(positions[6], UV[6]);
	m_originalValues[23] = DirectX::XMFLOAT2(UV[6].x, positions[6].y);

	// Triangle 9.
	m_mesh[24] = SuddenDeathVertex(positions[4], UV[4]);
	m_originalValues[24] = DirectX::XMFLOAT2(UV[4].x, positions[4].y);
	m_mesh[25] = SuddenDeathVertex(positions[5], UV[5]);
	m_originalValues[25] = DirectX::XMFLOAT2(UV[5].x, positions[5].y);
	m_mesh[26] = SuddenDeathVertex(positions[8], UV[8]);
	m_originalValues[26] = DirectX::XMFLOAT2(UV[8].x, positions[8].y);

	// Triangle 10.
	m_mesh[27] = SuddenDeathVertex(positions[5], UV[5]);
	m_originalValues[27] = DirectX::XMFLOAT2(UV[5].x, positions[5].y);
	m_mesh[28] = SuddenDeathVertex(positions[7], UV[7]);
	m_originalValues[28] = DirectX::XMFLOAT2(UV[7].x, positions[7].y);
	m_mesh[29] = SuddenDeathVertex(positions[9], UV[8]);
	m_originalValues[29] = DirectX::XMFLOAT2(UV[8].x, positions[9].y);

	// Triangle 11.
	m_mesh[30] = SuddenDeathVertex(positions[7], UV[7]);
	m_originalValues[30] = DirectX::XMFLOAT2(UV[7].x, positions[7].y);
	m_mesh[31] = SuddenDeathVertex(positions[6], UV[6]);
	m_originalValues[31] = DirectX::XMFLOAT2(UV[6].x, positions[6].y);
	m_mesh[32] = SuddenDeathVertex(positions[10], UV[8]);
	m_originalValues[32] = DirectX::XMFLOAT2(UV[8].x, positions[10].y);

	// Triangle 12.
	m_mesh[33] = SuddenDeathVertex(positions[6], UV[6]);
	m_originalValues[33] = DirectX::XMFLOAT2(UV[6].x, positions[6].y);
	m_mesh[34] = SuddenDeathVertex(positions[4], UV[4]);
	m_originalValues[34] = DirectX::XMFLOAT2(UV[4].x, positions[4].y);
	m_mesh[35] = SuddenDeathVertex(positions[11], UV[8]);
	m_originalValues[35] = DirectX::XMFLOAT2(UV[8].x, positions[11].y);

	// Setup vertex buffer description.
	D3D11_BUFFER_DESC vertexBuffer;
	vertexBuffer.Usage = D3D11_USAGE_DYNAMIC;
	vertexBuffer.ByteWidth = sizeof(SuddenDeathVertex) * NUMBER_OF_VERTICES;
	vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBuffer.MiscFlags = 0;
	vertexBuffer.StructureByteStride = 0;

	// Setup vertex buffer data.
	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = m_mesh;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	GraphicsEngine::GetInstance()->GetDevice()->CreateBuffer(&vertexBuffer, &vertexData, &m_vertexBuffer);

	// Setup matrices.
	MatrixBuffer* matrices = new MatrixBuffer();
	
	DirectX::XMFLOAT4X4 view;
	DirectX::XMStoreFloat4x4(&view, DirectX::XMMatrixIdentity());
	matrices->m_viewMatrix = DirectX::XMLoadFloat4x4(&view);

	DirectX::XMFLOAT4X4 projection;
	DirectX::XMStoreFloat4x4(&projection, DirectX::XMMatrixIdentity());
	matrices->m_projectionMatrix = DirectX::XMLoadFloat4x4(&projection);

	matrices->m_color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	// Create the matrix buffer description.
	D3D11_BUFFER_DESC matrixBuffer;
	matrixBuffer.Usage = D3D11_USAGE_DYNAMIC;
	matrixBuffer.ByteWidth = sizeof(MatrixBuffer);
	matrixBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBuffer.MiscFlags = 0;
	matrixBuffer.StructureByteStride = 0;

	// Setup matrix buffer data.
	D3D11_SUBRESOURCE_DATA matrixData;
	matrixData.pSysMem = matrices;
	matrixData.SysMemPitch = 0;
	matrixData.SysMemSlicePitch = 0;

	// Create the matrix buffer.
	GraphicsEngine::GetInstance()->GetDevice()->CreateBuffer(&matrixBuffer, &matrixData, &m_matrixBuffer);

	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SuddenDeath/SDVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SuddenDeath/SDVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile sudden death vertex shader from file.");
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
	if (FAILED(GraphicsEngine::GetInstance()->GetDevice()->CreateVertexShader(vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), NULL, &m_vertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create sudden death vertex shader.");
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

	layout[1].SemanticName = "UV";
	layout[1].SemanticIndex = 0;
	layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	layout[1].InputSlot = 0;
	layout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[1].InstanceDataStepRate = 0;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(GraphicsEngine::GetInstance()->GetDevice()->CreateInputLayout(layout, size, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create sudden death vertex input layout.");
	}

	ConsolePrintSuccess("Sudden death vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Release useless local shaders.
	vertexShader->Release();
	vertexShader = 0;

	// Set variables to initial values.
	ID3D10Blob*	pixelShader = 0;
	errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SuddenDeath/SDPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/SuddenDeath/SDPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile sudden death pixel shader from file.");
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
	if (FAILED(GraphicsEngine::GetInstance()->GetDevice()->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create sudden death pixel shader");
	}

	ConsolePrintSuccess("Sudden death pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

	// Release useless local variables.
	pixelShader->Release();
	pixelShader = 0;

	if (!m_texture)
	{
		m_texture = TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/SuddenDeathTexture.png");
	}

	ConsolePrintSuccess("Sudden death state initialized successfully.");
	ConsoleSkipLines(1);
}

void SuddenDeathState::Shutdown()
{	
	if (m_title)
	{
		m_title->Shutdown();
		delete m_title;
		m_title = nullptr;
	}

	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = nullptr;
	}

	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = nullptr;
	}

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

	if (m_layout)
	{
		m_layout->Release();
		m_layout = nullptr;
	}
}

void SuddenDeathState::Update()
{
	// Increase opacity gradually until fully faded in.
	if (m_gasOpacity < 0.65f)
	{
		m_gasOpacity += (float)(GLOBAL::GetInstance().GetDeltaTime() * 0.035f);

		if (m_gasOpacity >= 0.65f)
		{
			m_gasOpacity = 0.65f;
		}
	}

	// Increase height gradually until satisfied.
	if (m_gasHeight < 2.5)
	{
		m_gasHeight += (float)(GLOBAL::GetInstance().GetDeltaTime() * 0.1f);
	}

	// Increment UV offset.
	if (!m_UVForward)
	{
		m_UVOffset += (float)(GLOBAL::GetInstance().GetDeltaTime() * 0.005f);

		if (m_UVOffset >= 1.0f)
		{
			m_UVOffset -= 1.0f;
		}
	}

	// UV offset.
	for (unsigned int i = 0; i < NUMBER_OF_VERTICES; i++)
	{
		m_mesh[i].m_position.y = m_originalValues[i].y + m_gasHeight;
		m_mesh[i].m_UV.x = m_originalValues[i].x - m_UVOffset;
	}

	// Update buffer.
	D3D11_MAPPED_SUBRESOURCE resource;
	GraphicsEngine::GetInstance()->GetContext()->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	memcpy(resource.pData, m_mesh, sizeof(SuddenDeathVertex) * NUMBER_OF_VERTICES);
	GraphicsEngine::GetInstance()->GetContext()->Unmap(m_vertexBuffer, 0);
}

void SuddenDeathState::Render(Camera* p_camera)
{
	GraphicsEngine::GetInstance()->TurnOnAlphaBlending();
	GraphicsEngine::GetInstance()->TurnOffBackfaceCulling();

	// Render the sudden death warning.
	m_title->Render();

	// Set parameters and then render.
	unsigned int stride = sizeof(SuddenDeathVertex);
	const unsigned int offset = 0;

	ID3D11DeviceContext* context = GraphicsEngine::GetInstance()->GetContext();

	context->VSSetShader(m_vertexShader, NULL, 0);
	context->PSSetShader(m_pixelShader, NULL, 0);

	context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	context->IASetInputLayout(m_layout);

	DirectX::XMFLOAT4X4 viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix;

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&p_camera->GetViewMatrix())));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&p_camera->GetProjectionMatrix())));

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map sudden death matrix buffer.");
		return;
	}

	// Get pointer to the matrix buffer data.
	MatrixBuffer* matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Set matrices in buffer.
	matrixBuffer->m_viewMatrix = DirectX::XMLoadFloat4x4(&viewMatrix);
	matrixBuffer->m_projectionMatrix = DirectX::XMLoadFloat4x4(&projectionMatrix);
	matrixBuffer->m_color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, m_gasOpacity);

	// Unlock the matrix buffer after it has been written to.
	context->Unmap(m_matrixBuffer, 0);

	context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
	context->PSSetShaderResources(0, 1, &m_texture);

	context->Draw(NUMBER_OF_VERTICES, 0);

	GraphicsEngine::GetInstance()->TurnOnBackfaceCulling();
	GraphicsEngine::GetInstance()->TurnOffAlphaBlending();
}