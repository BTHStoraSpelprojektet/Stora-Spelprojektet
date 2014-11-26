#ifndef GRAPHICSENGINE
#define GRAPHICSENGINE

#include "DirectX.h"
#include "SceneShader.h"
#include "InstancedShader.h"
#include "Enumerations.h"

class GraphicsEngine
{
public:
	bool Initialize(HWND p_handle);

	void SetClearColor(float R, float G, float B, float p_opacity);
	void Clear();
	void Present();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	D3D_FEATURE_LEVEL GetVersion();

	void Render(SHADERTYPE p_shader, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_numberOfInstances);

	void SetSceneViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	void SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity);
	void SetSceneDirectionalLight(DirectionalLight& p_dLight);

	void TurnOnAlphaBlending();
	void TurnOffAlphaBlending();

	void AddInstanceBuffer(int p_numberOfInstances);

private:
	std::string CreateTitle(D3D_FEATURE_LEVEL p_version);

	DirectXWrapper m_directX;

	SceneShader m_sceneShader;
	InstancedShader m_instanceShader;
};
#endif;