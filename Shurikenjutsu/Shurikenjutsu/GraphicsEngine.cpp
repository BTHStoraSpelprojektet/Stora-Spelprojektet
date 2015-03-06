#include "GraphicsEngine.h"

#include "Enumerations.h"
#include "Globals.h"
#include "ParticleShader.h"
#include "WICTextureLoader.h"
#include "SceneShader.h"
#include "GUIShader.h"
#include "DepthShader.h"
#include "RenderTarget.h"
#include "ConsoleFunctions.h"
#include "VisibilityComputer.h"
#include "OutlingShader.h"
#include "Object.h"
#include "FoliageShader.h"
#include "ScreenSpace.h"
#include "Structures.h"
#include "InstanceManager.h"
#include "RenderTarget.h"
#include "CustomFont.h"

GraphicsEngine* GraphicsEngine::m_instance;

GraphicsEngine* GraphicsEngine::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GraphicsEngine();
	}

	return m_instance;
}

bool GraphicsEngine::Initialize(HWND p_handle)
{
	m_screenChanged = false;

	bool result = true;
	m_windowHandle = p_handle;

	// Initialize directX.
	if (m_directX.Initialize(p_handle))
	{
		m_directX.Present();
		ConsolePrintSuccess("DirectX initialized successfully.");
		std::string version = "DirectX version: " + CreateTitle(m_directX.GetVersion());
		ConsolePrintText(version);
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}
	
	// Initialize the scene shader.
	m_sceneShader = new SceneShader();
	if (m_sceneShader->Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("Scene shader initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Initialize 2D GUI shader.
	m_GUIShader = new GUIShader();
	if (m_GUIShader->Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("GUI 2D shader initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	if (m_GUIShader->InitializeColorShader(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("GUI 2D color shader initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Initialize the particle shader.
	m_particleShader = new ParticleShader();
	if (m_particleShader->Initialize(m_directX.GetDevice()))
	{
		ConsolePrintSuccess("Particle shader initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Initialize the depth buffer.
	m_depthShader = new DepthShader();
	if (m_depthShader->Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("Depth shader initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Initialize the foliage shader.
	m_foliageShader = new FoliageShader();
	if (m_foliageShader->Initialize(m_directX.GetDevice()))
	{
		ConsolePrintSuccess("Foliage shader initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Initialize the screen space shader.
	m_screenSpace = new ScreenSpace();
	if (m_screenSpace->Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("Foliage shader initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Initialize the visibility computer.
	if (ShadowShapes::GetInstance().Initialize())
	{
		ConsolePrintSuccess("ShadowShapes initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	if (VisibilityComputer::GetInstance().Initialize(GraphicsEngine::GetInstance()->GetDevice()))
	{
		ConsolePrintSuccess("VisibilityComputer initialized successfully.");
		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Initialize shadow map.
	if (m_shadowMap.Initialize(m_directX.GetDevice(), GLOBAL::GetInstance().MAX_SCREEN_WIDTH, GLOBAL::GetInstance().MAX_SCREEN_HEIGHT))
	{
		ConsolePrintSuccess("Shadow map initialized successfully.");

		std::string size = "Map size: " + std::to_string(GLOBAL::GetInstance().MAX_SCREEN_WIDTH);
		size.append("x" + std::to_string(GLOBAL::GetInstance().MAX_SCREEN_HEIGHT));
		ConsolePrintText(size);

		ConsoleSkipLines(1);
	}
	else
	{
		return false;
	}

	// Create the font wrapper.
	IFW1Factory* FW1Factory = NULL;
	HRESULT hResult = FW1CreateFactory(FW1_VERSION, &FW1Factory);
	hResult = FW1Factory->CreateFontWrapper(m_directX.GetDevice(), L"Arial", &m_fontWrapper);
	if (FAILED(hResult))
	{
		ConsolePrintError("Failed to create the font wrapper!");
	}
	else
	{
		ConsolePrintSuccess("Successfully created the font wrapper.");
	}
	ConsoleSkipLines(1);

	// Create text geometry
	hResult = FW1Factory->CreateTextGeometry(&m_textGeometry);
	if (FAILED(hResult))
	{
		ConsolePrintError("Failed to create the font wrapper!");
	}
	else
	{
		ConsolePrintSuccess("Successfully created the font geometry.");
	}
	ConsoleSkipLines(1);

	if (FW1Factory != NULL)
	{
		FW1Factory->Release();
	}

	// Get DWrite factory
	IDWriteFactory *writeFactory;
	hResult = m_fontWrapper->GetDWriteFactory(&writeFactory);

	// Set up custom font collection
	IDWriteFontCollectionLoader *collectionLoader = new CCollectionLoader(L"../Shurikenjutsu/Fonts/RagingRedLotusBB.ttf");

	hResult = writeFactory->RegisterFontCollectionLoader(collectionLoader);
	if (FAILED(hResult))
	{
		ConsolePrintError("Failed to create custom font!");
	}

	hResult = writeFactory->CreateCustomFontCollection(collectionLoader, NULL, 0, &m_fontCollection);
	if (FAILED(hResult))
	{
		ConsolePrintError("Failed to create custom font collection!");
	}

	writeFactory->UnregisterFontCollectionLoader(collectionLoader);
	collectionLoader->Release();
	writeFactory->Release();

	m_instanceManager = new InstanceManager();

	return result;
}

void GraphicsEngine::Shutdown()
{
	if (m_particleShader != nullptr)
	{
		m_particleShader->Shutdown();
		delete m_particleShader;
		m_particleShader = nullptr;
	}
	//if (m_shadowMap != nullptr)
	//{
		m_shadowMap.Shutdown();
	//	delete m_shadowMap;
	//	m_shadowMap = nullptr;
	//}
	if (m_sceneShader != nullptr)
	{
		m_sceneShader->Shutdown();
		delete m_sceneShader;
		m_sceneShader = nullptr;
	}

	if (m_GUIShader != nullptr)
	{
		m_GUIShader->Shutdown();
		delete m_GUIShader;
		m_GUIShader = nullptr;
	}

	if (m_depthShader != nullptr)
	{
		m_depthShader->Shutdown();
		delete m_depthShader;
		m_depthShader = nullptr;
	}

	if (m_foliageShader != nullptr)
	{
		m_foliageShader->Shutdown();
		delete m_foliageShader;
		m_foliageShader = nullptr;
	}

	if (m_screenSpace != nullptr)
	{
		m_screenSpace->Shutdown();
		delete m_screenSpace;
		m_screenSpace = nullptr;
	}

	if (m_fontWrapper != nullptr)
	{
		m_fontWrapper->Release();
		m_fontWrapper = nullptr;
	}

	if (m_textGeometry != nullptr)
	{
		m_textGeometry->Release();
		m_textGeometry = nullptr;
	}

	if (m_fontCollection != nullptr)
	{
		m_fontCollection->Release();
		m_fontCollection = nullptr;
	}

	if (m_instanceManager != nullptr)
	{
		m_instanceManager->Shutdown();
		delete m_instanceManager;
		m_instanceManager = nullptr;
	}

	m_directX.Shutdown();

	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

ID3D11ShaderResourceView* GraphicsEngine::Create2DTexture(std::string p_filename)
{
	ID3D11ShaderResourceView* textureView = NULL;
	std::wstring wstring;

	for (unsigned int i = 0; i < p_filename.length(); ++i)
	{
		wstring += wchar_t(p_filename[i]);
	}

	const wchar_t* your_result = wstring.c_str();

	HRESULT hr = DirectX::CreateWICTextureFromFile(m_directX.GetDevice(), m_directX.GetContext(), your_result, nullptr, &textureView, 0);
	if(FAILED(hr))
	{
		std::string text = "Filepath: ";
		text.append("'" + p_filename);
		text.append("'!");

		ConsolePrintError("Failed to create 2D texture from file! Missing or corrupt file?");
		ConsolePrintError(text);
	}

	return textureView;
}

void GraphicsEngine::RenderScene(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
{
	m_sceneShader->Render(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);
}

void GraphicsEngine::RenderSceneForward(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
{
	m_sceneShader->RenderForward(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);
}

void GraphicsEngine::RenderReversedShadows(ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture)
{
	m_sceneShader->RenderReversedShadows(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_visibilityMap, p_texture);
}
void GraphicsEngine::RenderInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex)
{
	m_sceneShader->RenderInstance(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_instanceIndex, m_instanceManager);
}

void GraphicsEngine::RenderAnimated(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	m_sceneShader->RenderAnimated(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_boneTransforms);
}

void GraphicsEngine::RenderAnimatedOutliningDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	m_sceneShader->RenderAnimatedOutliningDepth(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_boneTransforms);
}

void GraphicsEngine::RenderAnimatedOutlining(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	m_sceneShader->RenderAnimatedOutlining(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_boneTransforms);
}

void GraphicsEngine::RenderDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	m_depthShader->Render(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture);
}

void GraphicsEngine::RenderDepthInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex)
{
	m_depthShader->RenderInstance(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_instanceIndex, m_instanceManager);
}

void GraphicsEngine::RenderAnimatedDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
{
	m_depthShader->RenderAnimated(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_boneTransforms);
}

void GraphicsEngine::RenderGUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	m_GUIShader->Render(m_directX.GetContext(), p_worldMatrix, p_texture);
}

void GraphicsEngine::RenderGUIColor(DirectX::XMFLOAT4X4 p_worldMatrix, DirectX::XMFLOAT4 p_color)
{
	m_GUIShader->RenderColor(m_directX.GetContext(), p_worldMatrix, p_color);
}

void GraphicsEngine::RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_sceneShader->RenderLine(m_directX.GetContext(), p_mesh, p_number, p_color, p_worldMatrix);
}

void GraphicsEngine::RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, bool p_isFire)
{
	m_particleShader->Render(m_directX.GetContext(), p_mesh, p_vertexCount, p_worldMatrix, p_texture, p_isFire);
}

void GraphicsEngine::RenderFoliage()
{
	m_foliageShader->Render(m_directX.GetContext(), m_shadowMap.GetRenderTarget());
}

void GraphicsEngine::SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_sceneShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
	m_particleShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
	m_foliageShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
}

void GraphicsEngine::SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_sceneShader->UpdateLightViewAndProjection(p_viewMatrix, p_projectionMatrix);
	m_depthShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
	m_foliageShader->UpdateLightViewAndProjection(p_viewMatrix, p_projectionMatrix);
}

void GraphicsEngine::SetShadowMap()
{
	if (m_shadowMap.GetRenderTarget() == nullptr)
	{
		ConsolePrintErrorAndQuit("Shadow map is a null pointer.");
	}

	m_sceneShader->UpdateShadowMap(m_shadowMap.GetRenderTarget());
}

void GraphicsEngine::SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity)
{
	m_sceneShader->UpdateFogBuffer(m_directX.GetContext(), p_fogStart, p_fogEnd, p_fogDensity);
}

void GraphicsEngine::SetSceneDirectionalLight(DirectionalLight& p_dLight)
{
	m_sceneShader->UpdateFrameBuffer(m_directX.GetContext(), p_dLight);
}

void GraphicsEngine::SetScreenBuffer(DirectionalLight& p_dLight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view)
{
	m_screenSpace->UpdateFrameBuffer(m_directX.GetContext(), p_dLight, p_projection, p_view);
}

void GraphicsEngine::SetLightBuffer(ID3D11ShaderResourceView* p_lightSRV)
{
	m_screenSpace->SetLightBuffer(m_directX.GetContext(), p_lightSRV);
}

void GraphicsEngine::Clear()
{
	m_directX.Clear();
}

void GraphicsEngine::Present()
{
	m_directX.Present();
}

ID3D11Device* GraphicsEngine::GetDevice()
{
	return m_directX.GetDevice();
}

ID3D11DeviceContext* GraphicsEngine::GetContext()
{
	return m_directX.GetContext();
}

D3D_FEATURE_LEVEL GraphicsEngine::GetVersion()
{
	return m_directX.GetVersion();
}

void GraphicsEngine::SetClearColor(float R, float G, float B, float p_opacity)
{
	m_directX.SetClearColor(R, G, B, p_opacity);
}

ID3D11ShaderResourceView* GraphicsEngine::GetShadowMap()
{
	return m_shadowMap.GetRenderTarget();
}

ID3D11ShaderResourceView* GraphicsEngine::GetSceneShaderShadowMap()
{
	return m_sceneShader->GetShadowMap();
}

std::string GraphicsEngine::CreateTitle(D3D_FEATURE_LEVEL p_version)
{
	switch (p_version)
	{
		case(D3D_FEATURE_LEVEL_11_1) :
		{
			return "DirectX 11.1";
		}

		case(D3D_FEATURE_LEVEL_11_0) :
		{

			return "DirectX 11.0";
		}

		case(D3D_FEATURE_LEVEL_10_1) :
		{
			return "DirectX 10.1";
		}

		case(D3D_FEATURE_LEVEL_10_0) :
		{
			return "DirectX 10.0";
		}

		default:
		{
			ConsolePrintErrorAndQuit("Creating title from version failed.");
			return "ERROR";
		}
	}
}

void GraphicsEngine::TurnOnPointLightAlphaBlending()
{
	m_directX.TurnOnPointLightAlphaBlending();
}

void GraphicsEngine::TurnOnAlphaBlending()
{
	m_directX.TurnOnAlphaBlending();
}

void GraphicsEngine::TurnOffAlphaBlending()
{
	m_directX.TurnOffAlphaBlending();
}

void GraphicsEngine::AddInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_matrices)
{
	m_instanceManager->AddInstanceBuffer(m_directX.GetDevice(), p_numberOfInstances, p_matrices);
}
int GraphicsEngine::GetNumberOfInstanceBuffer()
{
	return m_instanceManager->GetNumberOfInstanceBuffer();
}
bool GraphicsEngine::ToggleFullscreen(bool p_fullscreen)
{    
	if (p_fullscreen)
	{               
		if (FAILED(m_directX.GetSwapChain()->SetFullscreenState(true, nullptr)))
		{            
			ConsolePrintErrorAndQuit("Setting fullscreen mode failed.");
			return false;
		}        

		m_screenChanged = true;

		GLOBAL::GetInstance().FULLSCREEN = true;
		GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
		GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
	}    
	
	else    
	{        
		if (FAILED(m_directX.GetSwapChain()->SetFullscreenState(false, nullptr)))
		{
			ConsolePrintErrorAndQuit("Setting windowed mode failed.");
			return false;
		}    

		m_screenChanged = true;
		
		GLOBAL::GetInstance().FULLSCREEN = false;
		GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MIN_SCREEN_WIDTH;
		GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MIN_SCREEN_HEIGHT;
	}    

	return true;
}

void GraphicsEngine::BeginRenderToShadowMap()
{
	// Set pixel shader textures to NULL.
	ID3D11ShaderResourceView* nullPointer = NULL;
	m_directX.GetContext()->PSSetShaderResources(0, 1, &nullPointer);
	m_directX.GetContext()->PSSetShaderResources(2, 1, &nullPointer);

	// Set color to clear the back buffer to.
	float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	m_shadowMap.SetAsRenderTarget(m_directX.GetContext());
	m_shadowMap.Clear(m_directX.GetContext(), color);
}

void GraphicsEngine::ResetRenderTarget()
{
	m_directX.ResetRenderTarget();
}

HWND GraphicsEngine::GetWindowHandle()
{
	return m_windowHandle;
}

void GraphicsEngine::SetShadowMapDimensions(float p_width, float p_height)
{
	m_sceneShader->SetShadowMapDimensions(m_directX.GetDevice(), m_directX.GetContext(), p_width, p_height);
}

void GraphicsEngine::TurnOnDepthStencil()
{
	m_directX.TurnOnDepthStencil();
}

void GraphicsEngine::TurnOffDepthStencil()
{
	m_directX.TurnOffDepthStencil();
}

void GraphicsEngine::SetDepthStateForParticles()
{
	m_directX.SetDepthStateForParticles();
}

void GraphicsEngine::SetVsync(bool p_state)
{
	m_directX.SetVsync(p_state);
}

bool GraphicsEngine::InitializeOutling()
{
	return m_directX.InitializeOutlinging();
}

void GraphicsEngine::SetOutliningPassOne()
{
	m_directX.SetOutliningPassOne();
}

void GraphicsEngine::SetOutliningPassTwo()
{
	m_directX.SetOutliningPassTwo();
}

void GraphicsEngine::ClearOutlining()
{
	m_directX.ClearOutlining();
}

void GraphicsEngine::UpdateInstanceBuffers(std::vector<DirectX::XMFLOAT4X4> p_matrixList, int p_index)
{
	m_instanceManager->UpdateDynamicInstanceBuffer(GetContext(), p_matrixList, p_index);
}

IFW1FontWrapper* GraphicsEngine::GetFontWrapper()
{
	return m_fontWrapper;
}

IDWriteFontCollection* GraphicsEngine::GetFontCollection()
{
	return m_fontCollection;
}

void GraphicsEngine::AnalyzeText(IDWriteTextLayout* p_layout, float p_x, float p_y, UINT32 p_color, UINT p_flags)
{
	m_fontWrapper->AnalyzeTextLayout(m_directX.GetContext(), p_layout, p_x, p_y, p_color, p_flags, m_textGeometry);
}

void GraphicsEngine::RenderTextGeometry(UINT p_flags)
{
	m_fontWrapper->Flush(m_directX.GetContext());
	m_fontWrapper->DrawGeometry(m_directX.GetContext(), m_textGeometry, NULL, NULL, p_flags);
	m_textGeometry->Clear();
}

bool GraphicsEngine::HasScreenChanged()
{
	return m_screenChanged;
}

void GraphicsEngine::ScreenChangeHandled()
{
	m_screenChanged = false;
}

ID3D11ShaderResourceView* GraphicsEngine::GetPostProcessingTexture1()
{
	return m_directX.GetCompositionTexture();
}

ID3D11ShaderResourceView* GraphicsEngine::GetPostProcessingTexture2()
{
	return m_directX.GetGBufferSRV2();
}

void GraphicsEngine::ClearRenderTargetsForGBuffers()
{
	m_directX.ClearRenderTargetsForGBuffers();
}

void GraphicsEngine::SetRenderTargetsForGBuffers()
{
	m_directX.SetRenderTargetsForGBuffers();
}

void GraphicsEngine::DoReportLiveObjects()
{
	m_directX.DoReportLiveObjects();
}

void GraphicsEngine::Composition()
{
	m_directX.SetRenderTargetForComposition();
	m_directX.TurnOnPointLightAlphaBlending();
	m_screenSpace->Render(m_directX.GetContext(), m_directX.GetGBufferSRV2(), m_directX.GetGBufferSRV1(), m_directX.GetDepthSRV(), m_directX.GetPPSRV1());


	m_screenSpace->RenderLights(m_directX.GetContext());
	TurnOffAlphaBlending();
}

void GraphicsEngine::SetForwardRenderTarget()
{
	m_directX.SetRenderTargetForForwardRendering();
}

void GraphicsEngine::RenderSSAO()
{
	m_directX.SetRenderTargetsForPP1();
	m_screenSpace->RenderSSAO(m_directX.GetContext(), m_directX.GetGBufferSRV2(), m_directX.GetDepthSRV());
	for (int i = 0; i < 1; i++)
	{
		m_directX.SetRenderTargetsForPP2();
		m_screenSpace->BlurImage(m_directX.GetContext(), m_directX.GetPPSRV1(), m_directX.GetDepthSRV(), m_directX.GetGBufferSRV2(), true);
		m_directX.SetRenderTargetsForPP1();
		m_screenSpace->BlurImage(m_directX.GetContext(), m_directX.GetPPSRV2(), m_directX.GetDepthSRV(), m_directX.GetGBufferSRV2(), false);
	}
}

void GraphicsEngine::SetSSAOBuffer(DirectX::XMFLOAT4X4 p_projection)
{
	m_screenSpace->UpdateSSAOBuffer(m_directX.GetContext(), p_projection);
}

void GraphicsEngine::ApplyDOF()
{
	m_directX.SetRenderTargetForDOF();
	m_directX.TurnOffDepthStencil();
	m_screenSpace->DOF(m_directX.GetContext(), m_directX.GetCompositionTexture(), m_directX.GetDepthSRV(), true);
	m_directX.SetRenderTargetForDOF2();
	m_screenSpace->DOF(m_directX.GetContext(), m_directX.GetCompositionTexture(), m_directX.GetGBufferSRV2(), false);
}

void GraphicsEngine::TurnOffBackfaceCulling()
{
	m_sceneShader->TurnOffBackFaceCulling(m_directX.GetContext());
}

void GraphicsEngine::TurnOnBackfaceCulling()
{
	m_sceneShader->TurnOnBackFaceCulling(m_directX.GetContext());
}