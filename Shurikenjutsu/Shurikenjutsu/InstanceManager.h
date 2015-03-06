#ifndef INSTANCEMANAGER_H
#define INSTANCEMANAGER_H

#include <vector>
#include <D3D11.h>
#include <DirectXMath.h>
class Object;
class InstanceManager
{
public:
	InstanceManager();
	~InstanceManager();

	void Shutdown();
	void AddInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_position);
	int GetNumberOfInstanceBuffer();
	ID3D11Buffer* GetInstanceBuffer(int p_index);
	int GetNumberOfInstances(int p_index);

	void UpdateDynamicInstanceBuffer(ID3D11DeviceContext* p_context, std::vector<DirectX::XMFLOAT4X4> p_ObjectList, int p_index);
private:
	void InitializeInstanceBuffer(ID3D11Device* p_device, int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_matrices);

	//Instancing
	std::vector<ID3D11Buffer*> m_instanceBufferList;
	std::vector<int> m_numberOfInstanceList;
};

#endif