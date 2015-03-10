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

	GraphicsEngine(const GraphicsEngine&) = delete;
	GraphicsEngine& operator=(const GraphicsEngine&) = delete;

	static GraphicsEngine* GetInstance();

	bool Initialize(HWND p_handle, float p_screenCurrentWidth, float p_screenCurrentHeight, float p_screenMaxWidth, float p_screenMaxHeight, bool p_fullscreen);
	void Shutdown();

	void SetClearColor(float R, float G, float B, float p_opacity);
	void Clear();
	void Present();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	D3D_FEATURE_LEVEL GetVersion();

	ID3D11ShaderResourceView* Create2DTexture(std::string p_filename);

	void RenderScene(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
	void RenderSceneForward(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
	void RenderReversedShadows(ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture);
	void RenderInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex);
	void RenderAnimated(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void RenderAnimatedOutlining(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void RenderDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	void RenderDepthInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex);
	void RenderAnimatedOutliningDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void RenderAnimatedDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void RenderGUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture);
	void RenderGUIColor(DirectX::XMFLOAT4X4 p_worldMatrix, DirectX::XMFLOAT4 p_color);
	void RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix);
	void RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, bool p_isFire);
	void RenderFoliage();

	void SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	void SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	void SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity);
	void SetSceneDirectionalLight(DirectionalLight& p_dLight);
	void SetLightBuffer(ID3D11ShaderResourceView* p_lightSRV);

	void UpdateInstanceBuffers(std::vector<DirectX::XMFLOAT4X4> p_matrixList, int p_index);

	void SetShadowMap();

	void TurnOnPointLightAlphaBlending();
	void TurnOnAlphaBlending();
	void TurnOffAlphaBlending();

	void TurnOnBackfaceCulling();
	void TurnOffBackfaceCulling();

	bool ToggleFullscreen(bool p_fullscreen, float p_currentScreenWidth, float p_currentScreenHeight);

	void AddInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_position);

	HWND GetWindowHandle();

	void BeginRenderToShadowMap();
	void ResetRenderTarget();

	ID3D11ShaderResourceView* GetShadowMap();
	ID3D11ShaderResourceView* GetSceneShaderShadowMap();

	void SetShadowMapDimensions(float p_width, float p_height);

	void TurnOnDepthStencil();
	void TurnOffDepthStencil();

	void SetDepthStateForParticles();

	int GetNumberOfInstanceBuffer();

	void SetVsync(bool p_state);

	void SetOutliningPassOne();
	void SetOutliningPassTwo();

	bool InitializeOutling();
	void ClearOutlining();

	IFW1FontWrapper* GetFontWrapper();
	IDWriteFontCollection* GetFontCollection();
	void AnalyzeText(IDWriteTextLayout* p_layout, float p_x, float p_y, UINT32 p_color, UINT p_flags);
	void RenderTextGeometry(UINT p_flags);

	bool HasScreenChanged();
	void ScreenChangeHandled();

	void DoReportLiveObjects();

	ID3D11ShaderResourceView* GetPostProcessingTexture1();
	ID3D11ShaderResourceView* GetPostProcessingTexture2();

	void ClearRenderTargetsForGBuffers();
	void SetRenderTargetsForGBuffers();

	void Composition();
	void SetScreenBuffer(DirectionalLight& p_dLight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view);

	void SetForwardRenderTarget();

	void RenderSSAO();
	void SetSSAOBuffer(DirectX::XMFLOAT4X4 p_projection);

	void ApplyDOF();


	void UpdateVisibilityPolygon(Point p_point, float p_deltaTime);
	void AddNewPointLight(PointLight& p_newLight);
	void SetViewPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix);
	void SetPointLightLightBuffer(DirectX::XMFLOAT4X4 p_matrix);
	void UpdateVisibilityMapBoundries(Point p_topLeft, Point p_botLeft);
	void RenderVisibilityPolygon(bool p_isMatchOver);
	void SetVisibilityProjectionPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix);
	void UpdateVisibilityTextureSize(float p_maxScreenWidth, float p_maxScreenHeight);
	bool IsVisibilityPointVisible(Point p_point);
	ID3D11Buffer* CreateBuffer(BUFFERTYPE p_type, std::vector<Vertex> p_mesh, std::vector<VertexAnimated> p_meshAnimated);
	void SS_AddStaticLine(Line p_line);
	void SS_Update(float p_deltaTime);
	void SS_DebugRender();
	void SS_AddSmokeBomb(Point p_point, float p_deltaTime);
private:
	static GraphicsEngine* m_instance;
	GraphicsEngine(){};
	~GraphicsEngine(){};

	std::string CreateTitle(D3D_FEATURE_LEVEL p_version);
};
#endif //GRAPHICSENGINE_H_
