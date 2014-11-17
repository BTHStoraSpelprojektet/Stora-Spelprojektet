#ifndef GRAPHICSENGINE
#define GRAPHICSENGINE

#include "DirectX.h"
#include "SceneShader.h"

class GraphicsEngine
{
public:
	bool Initialize(HWND p_handle);

	void Clear();
	void Render();
	void Present();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	D3D_FEATURE_LEVEL GetVersion();

	void SetClearColor(float R, float G, float B, float p_opacity);

private:
	std::string CreateTitle(D3D_FEATURE_LEVEL p_version);

	DirectXWrapper m_directX;

	SceneShader m_sceneShader;
};
#endif;