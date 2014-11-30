#ifndef GRAPHICSENGINE
#define GRAPHICSENGINE

#include "DirectX.h"
#include "SceneShader.h"
#include "InstancedShader.h"
#include "GUIShader.h"
#include "DepthShader.h"
#include "ShadowMap.h"

#include "Enumerations.h"
#include "Globals.h"

class GraphicsEngine
{
public:
	static bool Initialize(HWND p_handle);
	static void Shutdown();

	static void SetClearColor(float R, float G, float B, float p_opacity);
	static void Clear();
	static void Present();

	static ID3D11Device* GetDevice();
	static ID3D11DeviceContext* GetContext();
	static D3D_FEATURE_LEVEL GetVersion();

	static void Render(SHADERTYPE p_shader, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_numberOfInstances, std::vector<DirectX::XMMATRIX> p_boneTransforms);
	static void Render(SHADERTYPE p_shader, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	static void RenderUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);

	static void SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	static void SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	static void SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity);
	static void SetSceneDirectionalLight(DirectionalLight& p_dLight);
	static void SetLightPosition(DirectX::XMFLOAT3 p_position);

	static void SetShadowMap();

	static void TurnOnAlphaBlending();
	static void TurnOffAlphaBlending();

	static bool ToggleFullscreen(bool p_fullscreen);

	static void AddInstanceBuffer(int p_numberOfInstances);

	static HWND* GetWindowHandle();

	static void BeginRenderToShadowMap();
	static void ResetRenderTarget();

	static ID3D11ShaderResourceView* GetShadowMap();

private:
	GraphicsEngine(){};

	static std::string CreateTitle(D3D_FEATURE_LEVEL p_version);

	static DirectXWrapper m_directX;

	static SceneShader m_sceneShader;
	static InstancedShader m_instanceShader;
	static GUIShader m_GUIShader;
	static DepthShader m_depthShader;

	static HWND* m_windowHandle;

	static ShadowMap m_shadowMap;
};
#endif;