#include "GraphicsEngine.h"
#include "GraphicsEngineDLL.h"
#include "..\CommonLibs\CommonStructures.h"
#include "..\CommonLibs\CommonEnums.h"
#include "..\CommonLibs\TextureLibrary.h"

//GraphicsEngine* GraphicsEngine::m_instance;
//
//GraphicsEngine* GraphicsEngine::GetInstance()
//{
//	if (m_instance == nullptr)
//	{
//		m_instance = new GraphicsEngine();
//	}
//
//	return m_instance;
//}

bool GraphicsEngine::Initialize(HWND p_handle, float p_screenCurrentWidth, float p_screenCurrentHeight, float p_screenMaxWidth, float p_screenMaxHeight, bool p_fullscreen)
{
	
	return DLLGraphicsEngine::GE::GetInstance()->Initialize(p_handle, p_screenCurrentWidth, p_screenCurrentHeight, p_screenMaxWidth, p_screenMaxHeight, p_fullscreen);
}

void GraphicsEngine::Shutdown()
{
	DLLGraphicsEngine::GE::GetInstance()->Shutdown();
}

ID3D11ShaderResourceView* GraphicsEngine::Create2DTexture(std::string p_filename)
{
	return DLLGraphicsEngine::GE::GetInstance()->Create2DTexture(p_filename);
}

void GraphicsEngine::RenderScene(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderScene(p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);
}

void GraphicsEngine::RenderSceneForward(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderSceneForward(p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);
}

void GraphicsEngine::RenderReversedShadows(ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderReversedShadows(p_mesh, p_numberOfVertices, p_visibilityMap, p_texture);
}
void GraphicsEngine::RenderInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderInstanced(p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_instanceIndex);
}

void GraphicsEngine::RenderAnimated(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderAnimated(p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_boneTransforms);
}

void GraphicsEngine::RenderAnimatedOutliningDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderAnimatedOutliningDepth(p_mesh, p_numberOfVertices, p_worldMatrix, p_boneTransforms);
}

void GraphicsEngine::RenderAnimatedOutlining(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderAnimatedOutlining(p_mesh, p_numberOfVertices, p_worldMatrix, p_boneTransforms);
}

void GraphicsEngine::RenderDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderDepth(p_mesh, p_numberOfVertices, p_worldMatrix, p_texture);
}

void GraphicsEngine::RenderDepthInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderDepthInstanced(p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_instanceIndex);
}

void GraphicsEngine::RenderAnimatedDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderAnimatedDepth(p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_boneTransforms);
}

void GraphicsEngine::RenderGUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderGUI(p_worldMatrix, p_texture);
}

void GraphicsEngine::RenderGUIColor(DirectX::XMFLOAT4X4 p_worldMatrix, DirectX::XMFLOAT4 p_color)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderGUIColor(p_worldMatrix, p_color);
}

void GraphicsEngine::RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderLines(p_mesh, p_number, p_color, p_worldMatrix);
}

void GraphicsEngine::RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, bool p_isFire)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderParticles(p_mesh, p_vertexCount, p_worldMatrix, p_texture, p_isFire);
}

void GraphicsEngine::RenderFoliage()
{
	DLLGraphicsEngine::GE::GetInstance()->RenderFoliage();
}

void GraphicsEngine::SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	DLLGraphicsEngine::GE::GetInstance()->SetViewAndProjection(p_viewMatrix, p_projectionMatrix);
}

void GraphicsEngine::SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	DLLGraphicsEngine::GE::GetInstance()->SetLightViewAndProjection(p_viewMatrix, p_projectionMatrix);
}

void GraphicsEngine::SetShadowMap()
{
	DLLGraphicsEngine::GE::GetInstance()->SetShadowMap();
}

void GraphicsEngine::SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity)
{
	DLLGraphicsEngine::GE::GetInstance()->SetSceneFog(p_fogStart, p_fogEnd, p_fogDensity);
}

void GraphicsEngine::SetSceneDirectionalLight(DirectionalLight& p_dLight)
{
	DLLGraphicsEngine::GE::GetInstance()->SetSceneDirectionalLight(p_dLight);
}

void GraphicsEngine::SetScreenBuffer(DirectionalLight& p_dLight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view)
{
	DLLGraphicsEngine::GE::GetInstance()->SetScreenBuffer(p_dLight, p_projection, p_view);
}

void GraphicsEngine::SetLightBuffer(ID3D11ShaderResourceView* p_lightSRV)
{
	DLLGraphicsEngine::GE::GetInstance()->SetLightBuffer(p_lightSRV);
}

void GraphicsEngine::Clear()
{
	DLLGraphicsEngine::GE::GetInstance()->Clear();
}

void GraphicsEngine::Present()
{
	DLLGraphicsEngine::GE::GetInstance()->Present();
}

ID3D11Device* GraphicsEngine::GetDevice()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetDevice();
}

ID3D11DeviceContext* GraphicsEngine::GetContext()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetContext();
}

D3D_FEATURE_LEVEL GraphicsEngine::GetVersion()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetVersion();
}

void GraphicsEngine::SetClearColor(float R, float G, float B, float p_opacity)
{
	DLLGraphicsEngine::GE::GetInstance()->SetClearColor(R, G, B, p_opacity);
}

ID3D11ShaderResourceView* GraphicsEngine::GetShadowMap()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetShadowMap();
}

ID3D11ShaderResourceView* GraphicsEngine::GetSceneShaderShadowMap()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetSceneShaderShadowMap();
}

std::string GraphicsEngine::CreateTitle(D3D_FEATURE_LEVEL p_version)
{
	return DLLGraphicsEngine::GE::GetInstance()->CreateTitle(p_version);
}

void GraphicsEngine::TurnOnPointLightAlphaBlending()
{
	DLLGraphicsEngine::GE::GetInstance()->TurnOnPointLightAlphaBlending();
}

void GraphicsEngine::TurnOnAlphaBlending()
{
	DLLGraphicsEngine::GE::GetInstance()->TurnOnAlphaBlending();
}

void GraphicsEngine::TurnOffAlphaBlending()
{
	DLLGraphicsEngine::GE::GetInstance()->TurnOffAlphaBlending();
}

void GraphicsEngine::AddInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_matrices)
{
	DLLGraphicsEngine::GE::GetInstance()->AddInstanceBuffer(p_numberOfInstances, p_matrices);
}
int GraphicsEngine::GetNumberOfInstanceBuffer()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetNumberOfInstanceBuffer();
}
bool GraphicsEngine::ToggleFullscreen(bool p_fullscreen, float p_currentScreenWidth, float p_currentScreenHeight)
{
	return DLLGraphicsEngine::GE::GetInstance()->ToggleFullscreen(p_fullscreen, p_currentScreenWidth, p_currentScreenHeight);
}

void GraphicsEngine::BeginRenderToShadowMap()
{
	DLLGraphicsEngine::GE::GetInstance()->BeginRenderToShadowMap();
}

void GraphicsEngine::ResetRenderTarget()
{
	DLLGraphicsEngine::GE::GetInstance()->ResetRenderTarget();
}

HWND GraphicsEngine::GetWindowHandle()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetWindowHandle();
}

void GraphicsEngine::SetShadowMapDimensions(float p_width, float p_height)
{
	DLLGraphicsEngine::GE::GetInstance()->SetShadowMapDimensions(p_width, p_height);
}

void GraphicsEngine::TurnOnDepthStencil()
{
	DLLGraphicsEngine::GE::GetInstance()->TurnOnDepthStencil();
}

void GraphicsEngine::TurnOffDepthStencil()
{
	DLLGraphicsEngine::GE::GetInstance()->TurnOffDepthStencil();
}

void GraphicsEngine::SetDepthStateForParticles()
{
	DLLGraphicsEngine::GE::GetInstance()->SetDepthStateForParticles();
}

void GraphicsEngine::SetVsync(bool p_state)
{
	DLLGraphicsEngine::GE::GetInstance()->SetVsync(p_state);
}

bool GraphicsEngine::InitializeOutling()
{
	return DLLGraphicsEngine::GE::GetInstance()->InitializeOutling();
}

void GraphicsEngine::SetOutliningPassOne()
{
	DLLGraphicsEngine::GE::GetInstance()->SetOutliningPassOne();
}

void GraphicsEngine::SetOutliningPassTwo()
{
	DLLGraphicsEngine::GE::GetInstance()->SetOutliningPassTwo();
}

void GraphicsEngine::ClearOutlining()
{
	DLLGraphicsEngine::GE::GetInstance()->ClearOutlining();
}

void GraphicsEngine::UpdateInstanceBuffers(std::vector<DirectX::XMFLOAT4X4> p_matrixList, int p_index)
{
	DLLGraphicsEngine::GE::GetInstance()->UpdateInstanceBuffers(p_matrixList, p_index);
}

IFW1FontWrapper* GraphicsEngine::GetFontWrapper()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetFontWrapper();
}

IDWriteFontCollection* GraphicsEngine::GetFontCollection()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetFontCollection();
}

void GraphicsEngine::AnalyzeText(IDWriteTextLayout* p_layout, float p_x, float p_y, UINT32 p_color, UINT p_flags)
{
	DLLGraphicsEngine::GE::GetInstance()->AnalyzeText(p_layout, p_x, p_y, p_color, p_flags);
}

void GraphicsEngine::RenderTextGeometry(UINT p_flags)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderTextGeometry(p_flags);
}

bool GraphicsEngine::HasScreenChanged()
{
	return DLLGraphicsEngine::GE::GetInstance()->HasScreenChanged();
}

void GraphicsEngine::ScreenChangeHandled()
{
	DLLGraphicsEngine::GE::GetInstance()->ScreenChangeHandled();
}

ID3D11ShaderResourceView* GraphicsEngine::GetPostProcessingTexture1()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetPostProcessingTexture1();
}

ID3D11ShaderResourceView* GraphicsEngine::GetPostProcessingTexture2()
{
	return DLLGraphicsEngine::GE::GetInstance()->GetPostProcessingTexture2();
}

void GraphicsEngine::ClearRenderTargetsForGBuffers()
{
	DLLGraphicsEngine::GE::GetInstance()->ClearRenderTargetsForGBuffers();
}

void GraphicsEngine::SetRenderTargetsForGBuffers()
{
	DLLGraphicsEngine::GE::GetInstance()->SetRenderTargetsForGBuffers();
}

void GraphicsEngine::DoReportLiveObjects()
{
	DLLGraphicsEngine::GE::GetInstance()->DoReportLiveObjects();
}

void GraphicsEngine::Composition()
{
	DLLGraphicsEngine::GE::GetInstance()->Composition();
}

void GraphicsEngine::SetForwardRenderTarget()
{
	DLLGraphicsEngine::GE::GetInstance()->SetForwardRenderTarget();
}

void GraphicsEngine::RenderSSAO()
{
	DLLGraphicsEngine::GE::GetInstance()->RenderSSAO();
}

void GraphicsEngine::SetSSAOBuffer(DirectX::XMFLOAT4X4 p_projection)
{
	DLLGraphicsEngine::GE::GetInstance()->SetSSAOBuffer(p_projection);
}

void GraphicsEngine::ApplyDOF()
{
	DLLGraphicsEngine::GE::GetInstance()->ApplyDOF();
}

void GraphicsEngine::TurnOffBackfaceCulling()
{
	DLLGraphicsEngine::GE::GetInstance()->TurnOffBackfaceCulling();
}

void GraphicsEngine::TurnOnBackfaceCulling()
{
	DLLGraphicsEngine::GE::GetInstance()->TurnOnBackfaceCulling();
}

void GraphicsEngine::UpdateVisibilityPolygon(Point p_point, float p_deltaTime)
{	
	DLLGraphicsEngine::GE::GetInstance()->UpdateVisibilityPolygon(p_point, p_deltaTime);
}
void GraphicsEngine::AddNewPointLight(PointLight& p_newLight)
{
	DLLGraphicsEngine::GE::GetInstance()->AddNewPointLight(p_newLight);
}
void GraphicsEngine::SetViewPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix)
{
	DLLGraphicsEngine::GE::GetInstance()->SetViewPolygonMatrix(p_matrix);
}
void GraphicsEngine::SetPointLightLightBuffer(DirectX::XMFLOAT4X4 p_matrix)
{
	DLLGraphicsEngine::GE::GetInstance()->SetPointLightLightBuffer(p_matrix);
}
void GraphicsEngine::UpdateVisibilityMapBoundries(Point p_topLeft, Point p_botLeft)
{
	DLLGraphicsEngine::GE::GetInstance()->UpdateVisibilityMapBoundries(p_topLeft, p_botLeft);
}
void GraphicsEngine::RenderVisibilityPolygon(bool p_isMatchOver)
{
	DLLGraphicsEngine::GE::GetInstance()->RenderVisibilityPolygon(p_isMatchOver, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Particles/ShadowShapeTexture.png"));
}
void GraphicsEngine::SetVisibilityProjectionPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix)
{
	DLLGraphicsEngine::GE::GetInstance()->SetVisibilityProjectionPolygonMatrix(p_matrix);
}
void GraphicsEngine::UpdateVisibilityTextureSize(float p_maxScreenWidth, float p_maxScreenHeight)
{
	DLLGraphicsEngine::GE::GetInstance()->UpdateVisibilityTextureSize(p_maxScreenWidth, p_maxScreenHeight);
}
bool GraphicsEngine::IsVisibilityPointVisible(Point p_point)
{
	return DLLGraphicsEngine::GE::GetInstance()->IsVisibilityPointVisible(p_point);
}
ID3D11Buffer* GraphicsEngine::CreateBuffer(BUFFERTYPE p_type, std::vector<Vertex> p_mesh, std::vector<VertexAnimated> p_meshAnimated)
{
	return DLLGraphicsEngine::GE::GetInstance()->CreateBuffer(p_type, p_mesh, p_meshAnimated);
}
void GraphicsEngine::SS_AddStaticLine(Line p_line)
{
	DLLGraphicsEngine::GE::GetInstance()->SS_AddStaticLine(p_line);
}
void GraphicsEngine::SS_Update(float p_deltaTime)
{
	DLLGraphicsEngine::GE::GetInstance()->SS_Update(p_deltaTime);
}
void GraphicsEngine::SS_DebugRender()
{
	DLLGraphicsEngine::GE::GetInstance()->SS_DebugRender();
}
void GraphicsEngine::SS_AddSmokeBomb(Point p_point, float p_deltaTime)
{
	DLLGraphicsEngine::GE::GetInstance()->SS_AddSmokeBomb(p_point, p_deltaTime);
}