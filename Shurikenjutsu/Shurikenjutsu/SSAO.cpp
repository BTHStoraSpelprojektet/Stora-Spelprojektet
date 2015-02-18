#include "SSAO.h"
#include "GraphicsEngine.h"


SSAO::SSAO(){}
SSAO::~SSAO(){}

void SSAO::BuildFrustumFarCorners(int textureWidth, int textureHeight, float fovy, float farz)
{
	float aspect = (float)textureWidth / (float)textureHeight;

	float halfHeight = farz * tanf(0.5f*fovy);
	float halfWidth = aspect * halfHeight;

	m_FrustumFarCorner[0] = DirectX::XMFLOAT4(-halfWidth, -halfHeight, farz, 0.0f);
	m_FrustumFarCorner[1] = DirectX::XMFLOAT4(-halfWidth, +halfHeight, farz, 0.0f);
	m_FrustumFarCorner[2] = DirectX::XMFLOAT4(+halfWidth, +halfHeight, farz, 0.0f);
	m_FrustumFarCorner[3] = DirectX::XMFLOAT4(+halfWidth, -halfHeight, farz, 0.0f);
}

void SSAO::BuildOffsetVectors()
{
	m_Offsets[0] = DirectX::XMFLOAT4(+1.0f, +1.0f, +1.0f, 0.0f);
	m_Offsets[1] = DirectX::XMFLOAT4(-1.0f, -1.0f, -1.0f, 0.0f);

	m_Offsets[2] = DirectX::XMFLOAT4(-1.0f, +1.0f, +1.0f, 0.0f);
	m_Offsets[3] = DirectX::XMFLOAT4(+1.0f, -1.0f, -1.0f, 0.0f);

	m_Offsets[4] = DirectX::XMFLOAT4(+1.0f, +1.0f, -1.0f, 0.0f);
	m_Offsets[5] = DirectX::XMFLOAT4(-1.0f, -1.0f, +1.0f, 0.0f);

	m_Offsets[6] = DirectX::XMFLOAT4(-1.0f, +1.0f, -1.0f, 0.0f);
	m_Offsets[7] = DirectX::XMFLOAT4(+1.0f, -1.0f, +1.0f, 0.0f);

	m_Offsets[8] = DirectX::XMFLOAT4(-1.0f, 0.0f, 0.0f, 0.0f);
	m_Offsets[9] = DirectX::XMFLOAT4(+1.0f, 0.0f, 0.0f, 0.0f);

	m_Offsets[10] = DirectX::XMFLOAT4(0.0f, -1.0f, 0.0f, 0.0f);
	m_Offsets[11] = DirectX::XMFLOAT4(0.0f, +1.0f, 0.0f, 0.0f);

	m_Offsets[12] = DirectX::XMFLOAT4(0.0f, 0.0f, -1.0f, 0.0f);
	m_Offsets[13] = DirectX::XMFLOAT4(0.0f, 0.0f, +1.0f, 0.0f);

	for (int i = 0; i < 14; i++)
	{
		float s = (rand() % 101 + 25.0f) / 100.0f;
		DirectX::XMStoreFloat4(&m_Offsets[i], DirectX::XMVector4Normalize(DirectX::XMLoadFloat4(&m_Offsets[i])));
		m_Offsets[i].w * s;
		m_Offsets[i].x * s;
		m_Offsets[i].y * s;
		m_Offsets[i].z * s;
	}
}

bool SSAO::Initialize(int textureWidth, int textureHeight, float fovy, float farz)
{
	// Ssao
	InitSSAOMap(textureWidth, textureHeight);
	BuildOffsetVectors();
	BuildFrustumFarCorners(textureWidth, textureHeight, fovy, farz);
	BuildRandomVec();

	m_T = DirectX::XMFLOAT4X4(
		0.5f, 0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.0f, 1.0f);

	return true;
}

void SSAO::Shutdown()
{
	if (m_SSAOSRV)
	{
		m_SSAOSRV->Release();
		m_SSAOSRV = 0;
	}

	if (m_SSAORTV)
	{
		m_SSAORTV->Release();
		m_SSAORTV = 0;
	}

	if (m_SSAORTT)
	{
		m_SSAORTT->Release();
		m_SSAORTT = 0;
	}

	if (m_SSAOBlurSRV)
	{
		m_SSAOBlurSRV->Release();
		m_SSAOBlurSRV = 0;
	}

	if (m_SSAOBlurRTV)
	{
		m_SSAOBlurRTV->Release();
		m_SSAOBlurRTV = 0;
	}

	if (m_SSAOBlurRTT)
	{
		m_SSAOBlurRTT->Release();
		m_SSAOBlurRTT = 0;
	}

	if (m_ScreenQuadVB)
	{
		m_ScreenQuadVB->Release();
		m_ScreenQuadVB = 0;
	}
}

void SSAO::BuildRandomVec()
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
	GraphicsEngine::GetDevice()->CreateTexture2D(&texDesc, &initData, &tex);

	GraphicsEngine::GetDevice()->CreateShaderResourceView(tex, 0, &m_RandomVecSRV);

	//view saves a reference.
	tex->Release();
	delete[]color;
	color = 0;
}

void SSAO::SetRenderToSSAO()
{
	// Bind the render target view and depth stencil buffer to the output render pipeline.
	GraphicsEngine::GetContext()->OMSetRenderTargets(1, &m_SSAORTV, 0);
	GraphicsEngine::GetContext()->RSSetViewports(1, &m_SSAOVP);
}

void SSAO::ClearSSAO()
{
	float color[4] = { 0.5f, 0.5f, 0.5f, 0.0f };
	GraphicsEngine::GetContext()->ClearRenderTargetView(m_SSAORTV, color);
}

bool SSAO::InitSSAOMap(int textureWidth, int textureHeight)
{
	m_SSAOVP.TopLeftX = 0.0f;
	m_SSAOVP.TopLeftY = 0.0f;
	m_SSAOVP.Width = textureWidth / 2;
	m_SSAOVP.Height = textureHeight / 2;
	m_SSAOVP.MinDepth = 0.0f;
	m_SSAOVP.MaxDepth = 1.0f;

	D3D11_TEXTURE2D_DESC textureDesc;
	HRESULT result;
	D3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDesc;
	D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc;


	// Initialize the render target texture description.
	ZeroMemory(&textureDesc, sizeof(textureDesc));

	// Setup the render target texture description.
	textureDesc.Width = textureWidth / 2;
	textureDesc.Height = textureHeight / 2;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_R16G16B16A16_FLOAT;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;

	// Create the render target texture.
	result = GraphicsEngine::GetDevice()->CreateTexture2D(&textureDesc, NULL, &m_SSAORTT);
	if (FAILED(result))
	{
		return false;
	}
	result = GraphicsEngine::GetDevice()->CreateTexture2D(&textureDesc, NULL, &m_SSAOBlurRTT);
	if (FAILED(result))
	{
		return false;
	}

	// Setup the description of the render target view.
	renderTargetViewDesc.Format = textureDesc.Format;
	renderTargetViewDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	renderTargetViewDesc.Texture2D.MipSlice = 0;

	// Create the render target view.
	result = GraphicsEngine::GetDevice()->CreateRenderTargetView(m_SSAORTT, &renderTargetViewDesc, &m_SSAORTV);
	if (FAILED(result))
	{
		return false;
	}
	result = GraphicsEngine::GetDevice()->CreateRenderTargetView(m_SSAOBlurRTT, &renderTargetViewDesc, &m_SSAOBlurRTV);
	if (FAILED(result))
	{
		return false;
	}

	// Setup the description of the shader resource view.
	shaderResourceViewDesc.Format = textureDesc.Format;
	shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	shaderResourceViewDesc.Texture2D.MostDetailedMip = 0;
	shaderResourceViewDesc.Texture2D.MipLevels = 1;

	// Create the shader resource view.
	result = GraphicsEngine::GetDevice()->CreateShaderResourceView(m_SSAORTT, &shaderResourceViewDesc, &m_SSAOSRV);
	if (FAILED(result))
	{
		return false;
	}
	result = GraphicsEngine::GetDevice()->CreateShaderResourceView(m_SSAOBlurRTT, &shaderResourceViewDesc, &m_SSAOBlurSRV);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

HRESULT SSAO::RenderSSAO(DirectX::XMFLOAT4X4 p_P)
{
	ClearSSAO();
	SetRenderToSSAO();

	GraphicsEngine::GetContext()->IASetVertexBuffers(0, 1, NULL, 0, 0);
	GraphicsEngine::GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	DirectX::XMFLOAT4X4 PT;

	DirectX::XMStoreFloat4x4(&PT, DirectX::XMMatrixMultiply(DirectX::XMLoadFloat4x4(&p_P), DirectX::XMLoadFloat4x4(&m_T)));

	GraphicsEngine::GetContext()->Draw(0, 0);

	BlurSSAO();
	return S_OK;
}

void SSAO::BlurSSAO()
{
	for (int i = 0; i < 4; i++)
	{
		BlurSSAO(m_SSAOSRV, m_SSAOBlurRTV, true);
		BlurSSAO(m_SSAOBlurSRV, m_SSAORTV, false);
	}
}

void SSAO::BlurSSAO(ID3D11ShaderResourceView* input, ID3D11RenderTargetView* output, bool horizontal)
{
	float color[4] = { 0.5f, 0.5f, 0.5f, 0.0f };
	GraphicsEngine::GetContext()->ClearRenderTargetView(output, color);
	GraphicsEngine::GetContext()->OMSetRenderTargets(1, &output, 0);
	GraphicsEngine::GetContext()->RSSetViewports(1, &m_SSAOVP);

	GraphicsEngine::GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// SET SHADER RESOURCES!

	/*if (horizontal)
		mSsaoBlurShader->Apply(0);
	else
		mSsaoBlurShader->Apply(1);*/

	GraphicsEngine::GetContext()->Draw(0, 0);
}

ID3D11ShaderResourceView* SSAO::GetSSAO()
{
	return m_SSAOSRV;
}