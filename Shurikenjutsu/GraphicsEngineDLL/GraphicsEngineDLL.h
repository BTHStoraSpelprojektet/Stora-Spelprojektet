
#define GRAPHICSENGINEDLL_API __declspec(dllexport)

#include <Windows.h>
#include <DirectXMath.h>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class WICTextureLoader;
class GUIShader;
class DepthShader;
class RenderTarget;
class ParticleShader;
class SceneShader;
class FoliageShader;
class ScreenSpace;
class InstanceManager;
class DirectXWrapper;

struct IFW1FontWrapper;
struct IDWriteFontCollection;
struct IDWriteTextLayout;
struct IFW1TextGeometry;
struct WindowRectangle;
struct DirectionalLight;
struct ID3D11ShaderResourceView;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11Buffer;

enum D3D_FEATURE_LEVEL;
namespace DLLGraphicsEngine
{

	class GE
	{
	public:
		GE(const GE&) = delete;
		GE& operator=(const GE&) = delete;

		static GRAPHICSENGINEDLL_API GE* GetInstance();


		GRAPHICSENGINEDLL_API bool Initialize(HWND p_handle, float p_screenCurrentWidth, float p_screenCurrentHeight, float p_screenMaxWidth, float p_screenMaxHeight, bool p_fullscreen);
		GRAPHICSENGINEDLL_API void Shutdown();

		GRAPHICSENGINEDLL_API void SetClearColor(float R, float G, float B, float p_opacity);
		GRAPHICSENGINEDLL_API void Clear();
		GRAPHICSENGINEDLL_API void Present();
		
		GRAPHICSENGINEDLL_API ID3D11Device* GetDevice();
		GRAPHICSENGINEDLL_API ID3D11DeviceContext* GetContext();
		GRAPHICSENGINEDLL_API D3D_FEATURE_LEVEL GetVersion();

		GRAPHICSENGINEDLL_API ID3D11ShaderResourceView* Create2DTexture(std::string p_filename);
		GRAPHICSENGINEDLL_API void RenderScene(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
		GRAPHICSENGINEDLL_API void RenderSceneForward(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
		GRAPHICSENGINEDLL_API void RenderReversedShadows(ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture);
		GRAPHICSENGINEDLL_API void RenderInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex);
		GRAPHICSENGINEDLL_API void RenderAnimated(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
		GRAPHICSENGINEDLL_API void RenderAnimatedOutlining(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
		GRAPHICSENGINEDLL_API void RenderDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
		GRAPHICSENGINEDLL_API void RenderDepthInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex);
		GRAPHICSENGINEDLL_API void RenderAnimatedOutliningDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
		GRAPHICSENGINEDLL_API void RenderAnimatedDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
		GRAPHICSENGINEDLL_API void RenderGUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
		GRAPHICSENGINEDLL_API void RenderGUIColor(DirectX::XMFLOAT4X4 p_worldMatrix, DirectX::XMFLOAT4 p_color);
		GRAPHICSENGINEDLL_API void RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix);
		GRAPHICSENGINEDLL_API void RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, bool p_isFire);
		GRAPHICSENGINEDLL_API void RenderFoliage();

		GRAPHICSENGINEDLL_API void SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
		GRAPHICSENGINEDLL_API void SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
		GRAPHICSENGINEDLL_API void SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity);
		GRAPHICSENGINEDLL_API void SetSceneDirectionalLight(DirectionalLight& p_dLight);
		GRAPHICSENGINEDLL_API void SetLightBuffer(ID3D11ShaderResourceView* p_lightSRV);

		GRAPHICSENGINEDLL_API void UpdateInstanceBuffers(std::vector<DirectX::XMFLOAT4X4> p_matrixList, int p_index);
		GRAPHICSENGINEDLL_API void SetShadowMap();//10

		GRAPHICSENGINEDLL_API void TurnOnPointLightAlphaBlending();
		GRAPHICSENGINEDLL_API void TurnOnAlphaBlending();
		GRAPHICSENGINEDLL_API void TurnOffAlphaBlending();

		GRAPHICSENGINEDLL_API void TurnOnBackfaceCulling();
		GRAPHICSENGINEDLL_API void TurnOffBackfaceCulling();

		GRAPHICSENGINEDLL_API bool ToggleFullscreen(bool p_fullscreen, float p_currentScreenWidth, float p_currentScreenHeight);

		GRAPHICSENGINEDLL_API void AddInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_position);

		GRAPHICSENGINEDLL_API HWND GetWindowHandle();

		GRAPHICSENGINEDLL_API void BeginRenderToShadowMap();
		GRAPHICSENGINEDLL_API void ResetRenderTarget();//10

		GRAPHICSENGINEDLL_API ID3D11ShaderResourceView* GetShadowMap();
		GRAPHICSENGINEDLL_API ID3D11ShaderResourceView* GetSceneShaderShadowMap();

		GRAPHICSENGINEDLL_API void SetShadowMapDimensions(float p_width, float p_height);

		GRAPHICSENGINEDLL_API void TurnOnDepthStencil();
		GRAPHICSENGINEDLL_API void TurnOffDepthStencil();

		GRAPHICSENGINEDLL_API void SetDepthStateForParticles();

		GRAPHICSENGINEDLL_API int GetNumberOfInstanceBuffer();

		GRAPHICSENGINEDLL_API 	void SetVsync(bool p_state);

		GRAPHICSENGINEDLL_API 	void SetOutliningPassOne();
		GRAPHICSENGINEDLL_API 	void SetOutliningPassTwo();//10

		GRAPHICSENGINEDLL_API 	bool InitializeOutling();
		GRAPHICSENGINEDLL_API 	void ClearOutlining();

		GRAPHICSENGINEDLL_API 	IFW1FontWrapper* GetFontWrapper();
		GRAPHICSENGINEDLL_API 	IDWriteFontCollection* GetFontCollection();
		GRAPHICSENGINEDLL_API 	void AnalyzeText(IDWriteTextLayout* p_layout, float p_x, float p_y, UINT32 p_color, UINT p_flags);
		GRAPHICSENGINEDLL_API 	void RenderTextGeometry(UINT p_flags);

		GRAPHICSENGINEDLL_API 	bool HasScreenChanged();
		GRAPHICSENGINEDLL_API 	void ScreenChangeHandled();

		GRAPHICSENGINEDLL_API 	void DoReportLiveObjects();

		GRAPHICSENGINEDLL_API 	ID3D11ShaderResourceView* GetPostProcessingTexture1();//10
		GRAPHICSENGINEDLL_API 	ID3D11ShaderResourceView* GetPostProcessingTexture2();

		GRAPHICSENGINEDLL_API 	void ClearRenderTargetsForGBuffers();
		GRAPHICSENGINEDLL_API 	void SetRenderTargetsForGBuffers();

		GRAPHICSENGINEDLL_API 	void Composition();
		GRAPHICSENGINEDLL_API 	void SetScreenBuffer(DirectionalLight& p_dLight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view);

		GRAPHICSENGINEDLL_API 	void SetForwardRenderTarget();

		GRAPHICSENGINEDLL_API 	void RenderSSAO();
		GRAPHICSENGINEDLL_API 	void SetSSAOBuffer(DirectX::XMFLOAT4X4 p_projection);

		GRAPHICSENGINEDLL_API 	void ApplyDOF();
	private:
		static GE* m_instance;
		GE(){};
		~GE(){};

		std::string CreateTitle(D3D_FEATURE_LEVEL p_version);

		DirectXWrapper *m_directX;

		SceneShader* m_sceneShader;
		GUIShader* m_GUIShader;
		DepthShader* m_depthShader;
		ParticleShader* m_particleShader;
		FoliageShader* m_foliageShader;
		ScreenSpace* m_screenSpace;

		HWND m_windowHandle;

		RenderTarget *m_shadowMap;

		IFW1FontWrapper* m_fontWrapper;
		IFW1TextGeometry* m_textGeometry;
		IDWriteFontCollection* m_fontCollection;
		InstanceManager* m_instanceManager;

		bool m_screenChanged;

		float m_currentScreenWidth;
		float m_currentScreenHeight;

	};
}
