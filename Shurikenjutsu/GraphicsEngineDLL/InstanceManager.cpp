
#include "stdafx.h"
#include "InstanceManager.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include <DirectXMath.h>
#include <Windows.h>
#include <D3Dcompiler.h>
#include "..\CommonLibs\CommonStructures.h"
InstanceManager::InstanceManager(){}
InstanceManager::~InstanceManager(){}
void InstanceManager::Shutdown()
{
	for (unsigned int i = 0; i < m_instanceBufferList.size(); i++)
	{
		m_instanceBufferList[i]->Release();
		m_instanceBufferList[i] = 0;
	}
}
void InstanceManager::AddInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_position)
{
	if (p_numberOfInstances > 0)
	{
		m_numberOfInstanceList.push_back(p_numberOfInstances);
		InitializeInstanceBuffer(p_device, p_numberOfInstances, p_position);
	}
}
int InstanceManager::GetNumberOfInstanceBuffer()
{
	return m_instanceBufferList.size();
}
ID3D11Buffer* InstanceManager::GetInstanceBuffer(int p_index)
{
	return m_instanceBufferList[p_index];
}

int InstanceManager::GetNumberOfInstances(int p_index)
{
	return m_numberOfInstanceList[p_index];
}
void InstanceManager::UpdateDynamicInstanceBuffer(ID3D11DeviceContext* p_context, std::vector<DirectX::XMFLOAT4X4> p_matrixList, int p_index)
{	//TODO: Re mappar bufferns information med den inkommande vector med objekt med objektets instance index.
	//TODO 2: Skapa en vektor med objekt, utav varje typ av objekt, som skickas in i denna funktionen.
	//https://msdn.microsoft.com/en-us/library/windows/desktop/dn508285(v=vs.85).aspx

	D3D11_MAPPED_SUBRESOURCE mappedResource;
	if (FAILED(p_context->Map(m_instanceBufferList[p_index], 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource)))
	{
		ConsolePrintErrorAndQuit("Failed to update instance buffer.");
		return;
	}
	std::vector<InstancePos> instances;
	for (unsigned int i = 0; i < p_matrixList.size(); i++)
	{
		InstancePos temp;
		DirectX::XMStoreFloat4x4(&temp.position, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&p_matrixList[i])));
		instances.push_back(temp);
	}

	memcpy(mappedResource.pData, &instances[0], sizeof(InstancePos) *instances.size());

	p_context->Unmap(m_instanceBufferList[p_index], 0);

	m_numberOfInstanceList[p_index] = p_matrixList.size();
}
//Private

void InstanceManager::InitializeInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_matrices)
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
	instanceBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	instanceBufferDesc.ByteWidth = sizeof(InstancePos) * p_numberOfInstances;
	instanceBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	instanceBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	instanceBufferDesc.MiscFlags = 0;
	instanceBufferDesc.StructureByteStride = 0;

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