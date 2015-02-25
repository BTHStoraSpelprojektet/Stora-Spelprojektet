#include "PointLights.h"
#include "GraphicsEngine.h"

PointLights* PointLights::m_instance;

PointLights::PointLights()
{
}

PointLights::~PointLights()
{
}

PointLights* PointLights::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new PointLights();
	}

	return m_instance;
}

bool PointLights::Initialize()
{
	D3D11_BUFFER_DESC lightBufferDesc;
	lightBufferDesc.ByteWidth = sizeof(PointLight) * m_pointLights.size();
	lightBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	lightBufferDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	lightBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	lightBufferDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
	lightBufferDesc.StructureByteStride = sizeof(PointLight);

	GraphicsEngine::GetInstance()->GetDevice()->CreateBuffer(&lightBufferDesc, 0, &m_lightBuffer);

	GraphicsEngine::GetInstance()->GetDevice()->CreateShaderResourceView(m_lightBuffer, 0, &m_lightSRV);

	return true;
}

void PointLights::Shutdown()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}

	if (m_lightSRV)
	{
		delete m_lightSRV;
		m_lightSRV = nullptr;
	}
}

void PointLights::AddLight(PointLight& p_newLight)
{
	m_pointLights.push_back(p_newLight);
}

void PointLights::SetLightBuffer(DirectX::XMFLOAT4X4 p_viewMatrix)
{
	Initialize();

	if (m_pointLights.size() > 0)
	{
		D3D11_MAPPED_SUBRESOURCE mappedResource;
		GraphicsEngine::GetInstance()->GetContext()->Map(m_lightBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

		for (unsigned int i = 0; i < (unsigned int)m_pointLights.size(); i++)
		{
			m_pointLights[i].m_position = TransformPosition(m_pointLights[i].m_position, p_viewMatrix);
		}

		memcpy(mappedResource.pData, &m_pointLights[0], sizeof(PointLight)* m_pointLights.size());

		GraphicsEngine::GetInstance()->GetContext()->Unmap(m_lightBuffer, 0);
	}

	GraphicsEngine::GetInstance()->SetLightBuffer(m_lightSRV);
	m_pointLights.clear();
}

DirectX::XMFLOAT3 PointLights::TransformPosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_viewMatrix)
{
	DirectX::XMVECTOR returnPosition;
	DirectX::XMVECTOR originPosition;

	returnPosition = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	originPosition = DirectX::XMVectorSet(p_position.x, p_position.y, p_position.z, 1.0f);

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			returnPosition.m128_f32[y] += originPosition.m128_f32[x] * p_viewMatrix.m[x][y];
		}			
	}
	
	return DirectX::XMFLOAT3(returnPosition.m128_f32[0], returnPosition.m128_f32[1], returnPosition.m128_f32[2]);
}