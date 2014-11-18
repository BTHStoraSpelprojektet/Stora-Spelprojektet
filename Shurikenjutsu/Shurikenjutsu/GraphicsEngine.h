#ifndef GRAPHICSENGINE
#define GRAPHICSENGINE

#include "DirectX.h"
#include "SceneShader.h"
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

	void Render(SHADERTYPE p_shader, ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_texture);

	void SetSceneMatrices(DirectX::XMMATRIX& p_worldMatrix, DirectX::XMMATRIX& p_viewMatrix, DirectX::XMMATRIX& p_projectionMatrix);
	void SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity);

private:
	std::string CreateTitle(D3D_FEATURE_LEVEL p_version);

	DirectXWrapper m_directX;

	SceneShader m_sceneShader;
};
#endif;