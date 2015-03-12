#ifndef GRAPHICSENGINE_H_
#define GRAPHICSENGINE_H_

#include <DirectXMath.h>
#include <vector>
#include <Windows.h>

#pragma comment(lib, "GraphicsEngineDLL.lib")


class WICTextureLoader;
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
struct Point;
struct PointLight;
struct Vertex;
struct VertexAnimated;
struct Line;

enum D3D_FEATURE_LEVEL;
enum BUFFERTYPE;


class GraphicsEngine
{
private:

public:
	static bool Initialize(HWND p_handle, float p_screenCurrentWidth, float p_screenCurrentHeight, float p_screenMaxWidth, float p_screenMaxHeight, bool p_fullscreen);
	static void Shutdown();

	static void SetClearColor(float R, float G, float B, float p_opacity);
	static void Clear();
	static void Present();

	static ID3D11Device* GetDevice();
	static ID3D11DeviceContext* GetContext();
	static D3D_FEATURE_LEVEL GetVersion();

	static ID3D11ShaderResourceView* Create2DTexture(std::string p_filename);

	static void PrepareRenderScene();
	static void RenderScene(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
	static void RenderSceneForward(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
	static void RenderReversedShadows(ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture);
	static void RenderInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex);
	static void PrepareRenderAnimated();
	static void RenderAnimated(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	static void RenderAnimatedOutlining(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms, DirectX::XMFLOAT4 p_color);
	static void PrepareRenderDepth();
	static void RenderDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	static void PrepareRenderDepthInstanced();
	static void RenderDepthInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex);
	static void RenderAnimatedOutliningDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	static void PrepareRenderAnimatedDepth();
	static void RenderAnimatedDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	static void RenderGUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	static void PrepareRenderGUI();
	static void RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix);
	static void RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, bool p_isFire);
	static void RenderFoliage();

	static void SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	static void SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	static void SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity);
	static void SetSceneDirectionalLight(DirectionalLight& p_dLight);
	static void SetLightBuffer(ID3D11ShaderResourceView* p_lightSRV);

	static void UpdateInstanceBuffers(std::vector<DirectX::XMFLOAT4X4> p_matrixList, int p_index);

	static 	void SetShadowMap();

	static void TurnOnPointLightAlphaBlending();
	static void TurnOnAlphaBlending();
	static void TurnOffAlphaBlending();

	static void TurnOnBackfaceCulling();
	static void TurnOffBackfaceCulling();

	static bool ToggleFullscreen(bool p_fullscreen, float p_currentScreenWidth, float p_currentScreenHeight);

	static 	void AddInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_position);

	static HWND GetWindowHandle();

	static void BeginRenderToShadowMap();
	static void ResetRenderTarget();

	static ID3D11ShaderResourceView* GetShadowMap();
	static ID3D11ShaderResourceView* GetSceneShaderShadowMap();

	static void SetShadowMapDimensions(float p_width, float p_height);

	static void TurnOnDepthStencil();
	static void TurnOffDepthStencil();

	static 	void SetDepthStateForParticles();

	static int GetNumberOfInstanceBuffer();

	static void SetVsync(bool p_state);

	static 	void SetOutliningPassOne();
	static void SetOutliningPassTwo();

	static 	bool InitializeOutling();
	static void ClearOutlining();

	static IFW1FontWrapper* GetFontWrapper();
	static IDWriteFontCollection* GetFontCollection();
	static void AnalyzeText(IDWriteTextLayout* p_layout, float p_x, float p_y, UINT32 p_color, UINT p_flags);
	static void RenderTextGeometry(UINT p_flags);

	static bool HasScreenChanged();
	static void ScreenChangeHandled();

	static void DoReportLiveObjects();

	static ID3D11ShaderResourceView* GetPostProcessingTexture1();
	static ID3D11ShaderResourceView* GetPostProcessingTexture2();

	static void ClearRenderTargetsForGBuffers();
	static void SetRenderTargetsForGBuffers();

	static void Composition();
	static void SetScreenBuffer(DirectionalLight& p_dLight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view);

	static void SetForwardRenderTarget();

	static void RenderSSAO();
	static void SetSSAOBuffer(DirectX::XMFLOAT4X4 p_projection);

	static void ApplyDOF();


	static void UpdateVisibilityPolygon(Point p_point, float p_deltaTime);
	static void AddNewPointLight(PointLight& p_newLight);
	static void SetViewPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix);
	static void SetPointLightLightBuffer(DirectX::XMFLOAT4X4 p_matrix);
	static void UpdateVisibilityMapBoundries(Point p_topLeft, Point p_botLeft);
	static void RenderVisibilityPolygon(bool p_isMatchOver);
	static void SetVisibilityProjectionPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix);
	static void UpdateVisibilityTextureSize(float p_maxScreenWidth, float p_maxScreenHeight);
	static bool IsVisibilityPointVisible(Point p_point);
	static ID3D11Buffer* CreateBuffer(BUFFERTYPE p_type, std::vector<Vertex> p_mesh, std::vector<VertexAnimated> p_meshAnimated);
	static void SS_AddStaticLine(Line p_line);
	static 	void SS_Update(float p_deltaTime);
	static void SS_DebugRender();
	static void SS_AddSmokeBomb(Point p_point, float p_deltaTime);
	static void SS_ClearStaticLines();
private:

	static std::string CreateTitle(D3D_FEATURE_LEVEL p_version);
};
#endif //GRAPHICSENGINE_H_
