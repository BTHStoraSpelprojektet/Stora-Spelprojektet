#ifndef GRAPHICSENGINE
#define GRAPHICSENGINE

#include "DirectX.h"
#include "DirectXTex\DirectXTex.h"
#include "Structures.h"
#include "FW1FontWrapper_1_1\FW1FontWrapper.h"
#include <vector>
#include "InstanceManager.h"

class WICTextureLoader;
class GUIShader;
class DepthShader;
class RenderTarget;
class ParticleShader;
class SceneShader;
class Object;
class FoliageShader;
//class OutliningShader;

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
	
	static ID3D11ShaderResourceView* Create2DTexture(std::string p_filename);

	static void RenderScene(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
	static void RenderReversedShadows(ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap);
	static void RenderInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex);
	static void RenderAnimated(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	static void RenderAnimatedOutlining(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	static void RenderDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	static void RenderDepthInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex);
	static void RenderAnimatedDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	static void RenderGUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	static void RenderGUIColor(DirectX::XMFLOAT4X4 p_worldMatrix, DirectX::XMFLOAT4 p_color);
	static void RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix);
	static void RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	static void RenderFoliage();

	static void SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	static void SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	static void SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity);
	static void SetSceneDirectionalLight(DirectionalLight& p_dLight);

	static void UpdateInstanceBuffers(std::vector<Object*> p_ObjectList);

	static void SetShadowMap();

	static void TurnOnAlphaBlending();
	static void TurnOffAlphaBlending();

	static bool ToggleFullscreen(bool p_fullscreen);

	static void AddInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_position);

	static HWND GetWindowHandle();

	static void BeginRenderToShadowMap();
	static void ResetRenderTarget();

	static ID3D11ShaderResourceView* GetShadowMap();
	static ID3D11ShaderResourceView* GetSceneShaderShadowMap();

	static void SetShadowMapDimensions(float p_width, float p_height);

	static void TurnOnDepthStencil();
	static void TurnOffDepthStencil();

	static int GetNumberOfInstanceBuffer();

	static void SetVsync(bool p_state);

	static void SetOutliningPassOne();
	static void SetOutliningPassTwo();

	static bool InitializeOutling();
	static void ClearOutlining();

	static IFW1FontWrapper* GetFontWrapper();
	static void AnalyzeText(IDWriteTextLayout* p_layout, float p_x, float p_y, UINT32 p_color, UINT p_flags);
	static void RenderTextGeometry(UINT p_flags);

	static bool HasScreenChanged();
	static void ScreenChangeHandled();

private:
	GraphicsEngine(){};

	static std::string CreateTitle(D3D_FEATURE_LEVEL p_version);

	static DirectXWrapper m_directX;

	static SceneShader m_sceneShader;
	static GUIShader m_GUIShader;
	static DepthShader m_depthShader;
	static ParticleShader m_particleShader;
	static FoliageShader m_foliageShader;

	static HWND m_windowHandle;

	static RenderTarget m_shadowMap;

	static IFW1FontWrapper* m_fontWrapper;
	static IFW1TextGeometry* m_textGeometry;
	static InstanceManager* m_instanceManager;

	static bool m_screenChanged;
};
#endif;