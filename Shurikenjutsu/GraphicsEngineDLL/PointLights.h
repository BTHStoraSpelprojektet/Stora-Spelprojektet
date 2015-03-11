#ifndef POINTLIGHTS_H_
#define POINTLIGHTS_H_

#include <D3D11.h>
#include <vector>
#include <DirectXMath.h>

struct PointLight;

class PointLights
{
public:
	static PointLights* GetInstance();

	bool Initialize();
	void Shutdown();

	void AddLight(PointLight& p_newLight);
	void SetLightBuffer(DirectX::XMFLOAT4X4 p_viewMatrix);
	int GetLightCount();
	void ClearLights();

private:
	PointLights();
	~PointLights();

	DirectX::XMFLOAT3 TransformPosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_viewMatrix);

	static PointLights* m_instance;

	ID3D11Buffer* m_lightBuffer;
	ID3D11ShaderResourceView* m_lightSRV;

	std::vector<PointLight> m_newPointLights;
	std::vector<PointLight> m_pointLights;
};

#endif