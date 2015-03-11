// GEDLL.cpp : Defines the exported functions for the DLL application.
//
//#ifndef GEDLL_H
//#define GEDLL_H

#include "stdafx.h"

#include "GraphicsEngineDLL.h"
#include "ParticleShader.h"
#include "SceneShader.h"
#include "GUIShader.h"
#include "DepthShader.h"
#include "RenderTarget.h"
#include "VisibilityComputer.h"
#include "OutlingShader.h"
#include "FoliageShader.h"
#include "ScreenSpace.h"
#include "InstanceManager.h"
#include "CustomFont.h"
#include "DirectX.h"
#include "FW1FontWrapper_1_1\FW1FontWrapper.h"
#include "..\CommonLibs\DirectXTex\DirectXTex\DirectXTex.h"
#include "PointLights.h"
#include "buffer.h"
#include "WICTextureLoader.h"

namespace DLLGraphicsEngine
{
	GE* GE::m_instance;

	GE* GE::GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new GE();
		}

		return m_instance;
	}

	bool GE::Initialize(HWND p_handle, float p_screenCurrentWidth, float p_screenCurrentHeight, float p_screenMaxWidth, float p_screenMaxHeight, bool p_fullscreen)
	{
		m_screenChanged = false;
		m_currentScreenHeight = p_screenCurrentHeight;
		m_currentScreenWidth = p_screenCurrentWidth;
		bool result = true;
		m_windowHandle = p_handle;

		// Initialize directX.
		m_directX = new DirectXWrapper();
		if (m_directX->Initialize(p_handle, p_screenMaxHeight, p_screenMaxWidth, p_fullscreen))
		{
			m_directX->Present();
//			ConsolePrintSuccess("DirectX initialized successfully.");
			std::string version = "DirectX version: " + CreateTitle(m_directX->GetVersion());
//			ConsolePrintText(version);
			//ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize the scene shader.
		m_sceneShader = new SceneShader();
		if (m_sceneShader->Initialize(m_directX->GetDevice(), m_directX->GetContext()))
		{
//			ConsolePrintSuccess("Scene shader initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize 2D GUI shader.
		m_GUIShader = new GUIShader();
		if (m_GUIShader->Initialize(m_directX->GetDevice(), m_directX->GetContext()))
		{
//			ConsolePrintSuccess("GUI 2D shader initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize the particle shader.
		m_particleShader = new ParticleShader();
		if (m_particleShader->Initialize(m_directX->GetDevice()))
		{
//			ConsolePrintSuccess("Particle shader initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize the depth buffer.
		m_depthShader = new DepthShader();
		if (m_depthShader->Initialize(m_directX->GetDevice(), m_directX->GetContext()))
		{
//			ConsolePrintSuccess("Depth shader initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize the foliage shader.
		m_foliageShader = new FoliageShader();
		if (m_foliageShader->Initialize(m_directX->GetDevice()))
		{
//			ConsolePrintSuccess("Foliage shader initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize the screen space shader.
		m_screenSpace = new ScreenSpace();
		if (m_screenSpace->Initialize(m_directX->GetDevice(), m_directX->GetContext()))
		{
//			ConsolePrintSuccess("Foliage shader initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize the visibility computer.
		if (ShadowShapes::GetInstance()->Initialize())
		{
//			ConsolePrintSuccess("ShadowShapes initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		if (VisibilityComputer::GetInstance().Initialize(GE::GetInstance()->GetDevice(), (int)p_screenCurrentWidth, (int)p_screenCurrentHeight))
		{
	//		ConsolePrintSuccess("VisibilityComputer initialized successfully.");
//			ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Initialize shadow map.
		m_shadowMap = new RenderTarget();
		if (m_shadowMap->Initialize(m_directX->GetDevice(), (int)p_screenMaxWidth, (int)p_screenMaxHeight))
		{
//			ConsolePrintSuccess("Shadow map initialized successfully.");

			std::string size = "Map size: " + std::to_string(p_screenMaxWidth);
			size.append("x" + std::to_string(p_screenMaxHeight));
	//		ConsolePrintText(size);

	//		ConsoleSkipLines(1);
		}
		else
		{
			return false;
		}

		// Create the font wrapper.
		IFW1Factory* FW1Factory = NULL;
		HRESULT hResult = FW1CreateFactory(FW1_VERSION, &FW1Factory);
		hResult = FW1Factory->CreateFontWrapper(m_directX->GetDevice(), L"Arial", &m_fontWrapper);
		if (FAILED(hResult))
		{
	//		ConsolePrintError("Failed to create the font wrapper!");
		}
		else
		{
//			ConsolePrintSuccess("Successfully created the font wrapper.");
		}
//		ConsoleSkipLines(1);

		// Create text geometry
		hResult = FW1Factory->CreateTextGeometry(&m_textGeometry);
		if (FAILED(hResult))
		{
//			ConsolePrintError("Failed to create the font wrapper!");
		}
		else
		{
//			ConsolePrintSuccess("Successfully created the font geometry.");
		}
//		ConsoleSkipLines(1);

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
	//		ConsolePrintError("Failed to create custom font!");
		}

		hResult = writeFactory->CreateCustomFontCollection(collectionLoader, NULL, 0, &m_fontCollection);
		if (FAILED(hResult))
		{
	//		ConsolePrintError("Failed to create custom font collection!");
		}

		writeFactory->UnregisterFontCollectionLoader(collectionLoader);
		collectionLoader->Release();
		writeFactory->Release();

		m_instanceManager = new InstanceManager();

		return result;
	}

	void GE::Shutdown()
	{
		if (m_particleShader != nullptr)
		{
			m_particleShader->Shutdown();
			delete m_particleShader;
			m_particleShader = nullptr;
		}
		if (m_shadowMap != nullptr)
		{
			m_shadowMap->Shutdown();
			delete m_shadowMap;
			m_shadowMap = nullptr;
		}
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
		if (m_directX != nullptr)
		{
			m_directX->Shutdown();
			delete m_directX;
			m_directX = nullptr;
		}
		PointLights::GetInstance()->Shutdown();
		ShadowShapes::GetInstance()->Shutdown();
		VisibilityComputer::GetInstance().Shutdown();

		if (m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	ID3D11ShaderResourceView* GE::Create2DTexture(std::string p_filename)
	{
		ID3D11ShaderResourceView* textureView = NULL;
		std::wstring wstring;

		for (unsigned int i = 0; i < p_filename.length(); ++i)
		{
			wstring += wchar_t(p_filename[i]);
		}

		const wchar_t* your_result = wstring.c_str();

		HRESULT hr = DirectX::CreateWICTextureFromFile(GetDevice(), GetContext(), your_result, nullptr, &textureView, 0);
		if (FAILED(hr))
		{
			std::string text = "Filepath: ";
			text.append("'" + p_filename);
			text.append("'!");

	//		ConsolePrintError("Failed to create 2D texture from file! Missing or corrupt file?");
	//		ConsolePrintError(text);
		}

		return textureView;
	}

	void GE::PrepareRenderScene()
	{
		m_sceneShader->PrepareRender(m_directX->GetContext());
	}

	void GE::RenderScene(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
	{
		m_sceneShader->Render(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);
	}

	void GE::RenderSceneForward(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
	{
		m_sceneShader->RenderForward(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);
	}

	void GE::RenderReversedShadows(ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture)
	{
		m_sceneShader->RenderReversedShadows(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_visibilityMap, p_texture);
	}
	void GE::RenderInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex)
	{
		m_sceneShader->RenderInstance(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_instanceIndex, m_instanceManager);
	}

	void GE::PrepareRenderAnimated()
	{
		m_sceneShader->PrepareRenderAnimated(m_directX->GetContext());
	}

	void GE::RenderAnimated(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
	{
		m_sceneShader->RenderAnimated(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_boneTransforms);
	}

	void GE::RenderAnimatedOutliningDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
	{
		m_sceneShader->RenderAnimatedOutliningDepth(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_boneTransforms);
	}

	void GE::RenderAnimatedOutlining(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
	{
		m_sceneShader->RenderAnimatedOutlining(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_boneTransforms);
	}

	void GE::PrepareRenderDepth()
	{
		m_depthShader->PrepareRender(m_directX->GetContext());
	}

	void GE::RenderDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
	{
		m_depthShader->Render(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture);
	}

	void GE::PrepareRenderDepthInstanced()
	{
		m_depthShader->PrepareRenderInstanced(m_directX->GetContext());
	}

	void GE::RenderDepthInstanced(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex)
	{
		m_depthShader->RenderInstance(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_instanceIndex, m_instanceManager);
	}

	void GE::PrepareRenderAnimatedDepth()
	{
		m_depthShader->PrepareRenderAnimated(m_directX->GetContext());
	}

	void GE::RenderAnimatedDepth(ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms)
	{
		m_depthShader->RenderAnimated(m_directX->GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_boneTransforms);
	}

	void GE::RenderGUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
	{
		m_GUIShader->Render(m_directX->GetContext(), p_worldMatrix, p_texture, m_currentScreenWidth, m_currentScreenHeight);
	}

	void GE::PrepareRenderGUI()
	{
		m_GUIShader->PrepareRender(m_directX->GetContext());
	}

	void GE::RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix)
	{
		m_sceneShader->RenderLine(m_directX->GetContext(), p_mesh, p_number, p_color, p_worldMatrix);
	}

	void GE::RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, bool p_isFire)
	{
		m_particleShader->Render(m_directX->GetContext(), p_mesh, p_vertexCount, p_worldMatrix, p_texture, p_isFire);
	}

	void GE::RenderFoliage()
	{
		m_foliageShader->Render(m_directX->GetContext(), m_shadowMap->GetRenderTarget());
	}

	void GE::SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
	{
		m_sceneShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
		m_particleShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
		m_foliageShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
	}

	void GE::SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
	{
		m_sceneShader->UpdateLightViewAndProjection(p_viewMatrix, p_projectionMatrix);
		m_depthShader->UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
		m_foliageShader->UpdateLightViewAndProjection(p_viewMatrix, p_projectionMatrix);
	}

	void GE::SetShadowMap()
	{
		if (m_shadowMap->GetRenderTarget() == nullptr)
		{
	//		ConsolePrintErrorAndQuit("Shadow map is a null pointer.");
		}

		m_sceneShader->UpdateShadowMap(m_shadowMap->GetRenderTarget());
	}

	void GE::SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity)
	{
		m_sceneShader->UpdateFogBuffer(m_directX->GetContext(), p_fogStart, p_fogEnd, p_fogDensity);
	}

	void GE::SetSceneDirectionalLight(DirectionalLight& p_dLight)
	{
		m_sceneShader->UpdateFrameBuffer(m_directX->GetContext(), p_dLight);
	}

	void GE::SetScreenBuffer(DirectionalLight& p_dLight, DirectX::XMFLOAT4X4 p_projection, DirectX::XMFLOAT4X4 p_view)
	{
		m_screenSpace->UpdateFrameBuffer(m_directX->GetContext(), p_dLight, p_projection, p_view);
	}

	void GE::SetLightBuffer(ID3D11ShaderResourceView* p_lightSRV)
	{
		m_screenSpace->SetLightBuffer(m_directX->GetContext(), p_lightSRV);
	}

	void GE::Clear()
	{
		m_directX->Clear();
	}

	void GE::Present()
	{
		m_directX->Present();
	}

	ID3D11Device* GE::GetDevice()
	{
		return m_directX->GetDevice();
	}

	ID3D11DeviceContext* GE::GetContext()
	{
		return m_directX->GetContext();
	}

	D3D_FEATURE_LEVEL GE::GetVersion()
	{
		return m_directX->GetVersion();
	}

	void GE::SetClearColor(float R, float G, float B, float p_opacity)
	{
		m_directX->SetClearColor(R, G, B, p_opacity);
	}

	ID3D11ShaderResourceView* GE::GetShadowMap()
	{
		return m_shadowMap->GetRenderTarget();
	}

	ID3D11ShaderResourceView* GE::GetSceneShaderShadowMap()
	{
		return m_sceneShader->GetShadowMap();
	}

	std::string GE::CreateTitle(D3D_FEATURE_LEVEL p_version)
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
//			ConsolePrintErrorAndQuit("Creating title from version failed.");
			return "ERROR";
		}
		}
	}

	void GE::TurnOnPointLightAlphaBlending()
	{
		m_directX->TurnOnPointLightAlphaBlending();
	}

	void GE::TurnOnAlphaBlending()
	{
		m_directX->TurnOnAlphaBlending();
	}

	void GE::TurnOffAlphaBlending()
	{
		m_directX->TurnOffAlphaBlending();
	}

	void GE::AddInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_matrices)
	{
		m_instanceManager->AddInstanceBuffer(m_directX->GetDevice(), p_numberOfInstances, p_matrices);
	}
	int GE::GetNumberOfInstanceBuffer()
	{
		return m_instanceManager->GetNumberOfInstanceBuffer();
	}
	bool GE::ToggleFullscreen(bool p_fullscreen, float p_currentScreenWidth, float p_currentScreenHeight)
	{
		if (p_fullscreen)
		{
			if (FAILED(m_directX->GetSwapChain()->SetFullscreenState(true, nullptr)))
			{
	//			ConsolePrintErrorAndQuit("Setting fullscreen mode failed.");
				return false;
			}

			m_screenChanged = true;

			//GLOBAL::GetInstance().FULLSCREEN = true;
			//GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
			//GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
		}

		else
		{
			if (FAILED(m_directX->GetSwapChain()->SetFullscreenState(false, nullptr)))
			{
	//			ConsolePrintErrorAndQuit("Setting windowed mode failed.");
				return false;
			}

			m_screenChanged = true;

			//GLOBAL::GetInstance().FULLSCREEN = false;
			//GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MIN_SCREEN_WIDTH;
			//GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MIN_SCREEN_HEIGHT;
		}
		m_currentScreenWidth = p_currentScreenWidth;
		m_currentScreenHeight = p_currentScreenHeight;
		return true;
	}

	void GE::BeginRenderToShadowMap()
	{
		// Set pixel shader textures to NULL.
		ID3D11ShaderResourceView* nullPointer = NULL;
		m_directX->GetContext()->PSSetShaderResources(0, 1, &nullPointer);
		m_directX->GetContext()->PSSetShaderResources(2, 1, &nullPointer);

		// Set color to clear the back buffer to.
		float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

		m_shadowMap->SetAsRenderTarget(m_directX->GetContext());
		m_shadowMap->Clear(m_directX->GetContext(), color);
	}

	void GE::ResetRenderTarget()
	{
		m_directX->ResetRenderTarget();
	}

	HWND GE::GetWindowHandle()
	{
		return m_windowHandle;
	}

	void GE::SetShadowMapDimensions(float p_width, float p_height)
	{
		m_sceneShader->SetShadowMapDimensions(m_directX->GetDevice(), m_directX->GetContext(), p_width, p_height);
	}

	void GE::TurnOnDepthStencil()
	{
		m_directX->TurnOnDepthStencil();
	}

	void GE::TurnOffDepthStencil()
	{
		m_directX->TurnOffDepthStencil();
	}

	void GE::SetDepthStateForParticles()
	{
		m_directX->SetDepthStateForParticles();
	}

	void GE::SetVsync(bool p_state)
	{
		m_directX->SetVsync(p_state);
	}

	bool GE::InitializeOutling()
	{
		return m_directX->InitializeOutlinging();
	}

	void GE::SetOutliningPassOne()
	{
		m_directX->SetOutliningPassOne();
	}

	void GE::SetOutliningPassTwo()
	{
		m_directX->SetOutliningPassTwo();
	}

	void GE::ClearOutlining()
	{
		m_directX->ClearOutlining();
	}

	void GE::UpdateInstanceBuffers(std::vector<DirectX::XMFLOAT4X4> p_matrixList, int p_index)
	{
		m_instanceManager->UpdateDynamicInstanceBuffer(GetContext(), p_matrixList, p_index);
	}

	IFW1FontWrapper* GE::GetFontWrapper()
	{
		return m_fontWrapper;
	}

	IDWriteFontCollection* GE::GetFontCollection()
	{
		return m_fontCollection;
	}

	void GE::AnalyzeText(IDWriteTextLayout* p_layout, float p_x, float p_y, UINT32 p_color, UINT p_flags)
	{
		m_fontWrapper->AnalyzeTextLayout(m_directX->GetContext(), p_layout, p_x, p_y, p_color, p_flags, m_textGeometry);
	}

	void GE::RenderTextGeometry(UINT p_flags)
	{
		m_fontWrapper->Flush(m_directX->GetContext());
		m_fontWrapper->DrawGeometry(m_directX->GetContext(), m_textGeometry, NULL, NULL, p_flags);
		m_textGeometry->Clear();
	}

	bool GE::HasScreenChanged()
	{
		return m_screenChanged;
	}

	void GE::ScreenChangeHandled()
	{
		m_screenChanged = false;
	}

	ID3D11ShaderResourceView* GE::GetPostProcessingTexture1()
	{
		return m_directX->GetCompositionTexture();
	}

	ID3D11ShaderResourceView* GE::GetPostProcessingTexture2()
	{
		return m_directX->GetGBufferSRV2();
	}

	void GE::ClearRenderTargetsForGBuffers()
	{
		m_directX->ClearRenderTargetsForGBuffers();
	}

	void GE::SetRenderTargetsForGBuffers()
	{
		m_directX->SetRenderTargetsForGBuffers();
	}

	void GE::DoReportLiveObjects()
	{
		m_directX->DoReportLiveObjects();
	}

	void GE::Composition()
	{
		m_directX->SetRenderTargetForComposition();
		m_directX->TurnOnPointLightAlphaBlending();
		m_screenSpace->Render(m_directX->GetContext(), m_directX->GetGBufferSRV2(), m_directX->GetGBufferSRV1(), m_directX->GetDepthSRV(), m_directX->GetPPSRV1());


		m_screenSpace->RenderLights(m_directX->GetContext());
		TurnOffAlphaBlending();
	}

	void GE::SetForwardRenderTarget()
	{
		m_directX->SetRenderTargetForForwardRendering();
	}

	void GE::RenderSSAO()
	{
		m_directX->SetRenderTargetsForPP1();
		m_screenSpace->RenderSSAO(m_directX->GetContext(), m_directX->GetGBufferSRV2(), m_directX->GetDepthSRV());
		for (int i = 0; i < 1; i++)
		{
			m_directX->SetRenderTargetsForPP2();
			m_screenSpace->BlurImage(m_directX->GetContext(), m_directX->GetPPSRV1(), m_directX->GetDepthSRV(), m_directX->GetGBufferSRV2(), true);
			m_directX->SetRenderTargetsForPP1();
			m_screenSpace->BlurImage(m_directX->GetContext(), m_directX->GetPPSRV2(), m_directX->GetDepthSRV(), m_directX->GetGBufferSRV2(), false);
		}
	}

	void GE::SetSSAOBuffer(DirectX::XMFLOAT4X4 p_projection)
	{
		m_screenSpace->UpdateSSAOBuffer(m_directX->GetContext(), p_projection);
	}

	void GE::ApplyDOF()
	{
		m_directX->SetRenderTargetForDOF();
		m_directX->TurnOffDepthStencil();
		m_screenSpace->DOF(m_directX->GetContext(), m_directX->GetCompositionTexture(), m_directX->GetDepthSRV(), true);
		m_directX->SetRenderTargetForDOF2();
		m_screenSpace->DOF(m_directX->GetContext(), m_directX->GetCompositionTexture(), m_directX->GetGBufferSRV2(), false);
	}

	void GE::TurnOffBackfaceCulling()
	{
		m_sceneShader->TurnOffBackFaceCulling(m_directX->GetContext());
	}

	void GE::TurnOnBackfaceCulling()
	{
		m_sceneShader->TurnOnBackFaceCulling(m_directX->GetContext());
	}

	void GE::UpdateVisibilityPolygon(Point p_point, float p_deltaTime)
	{
		VisibilityComputer::GetInstance().UpdateVisibilityPolygon(p_point, GetDevice(), p_deltaTime);
	}
	void GE::AddNewPointLight(PointLight& p_newLight)
	{
		PointLights::GetInstance()->AddLight(p_newLight);
	}
	void GE::SetViewPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix)
	{
		VisibilityComputer::GetInstance().SetViewPolygonMatrix(p_matrix);
	}
	void GE::SetPointLightLightBuffer(DirectX::XMFLOAT4X4 p_matrix)
	{
		PointLights::GetInstance()->SetLightBuffer(p_matrix);
	}

	void GE::UpdateVisibilityMapBoundries(Point p_topLeft, Point p_botLeft)
	{
		VisibilityComputer::GetInstance().UpdateMapBoundries(p_topLeft, p_botLeft);
	}
	void GE::RenderVisibilityPolygon(bool p_isMatchOver, ID3D11ShaderResourceView* p_texture)
	{
		VisibilityComputer::GetInstance().RenderVisibilityPolygon(GetContext(), p_isMatchOver, p_texture);
	}
	void GE::SetVisibilityProjectionPolygonMatrix(DirectX::XMFLOAT4X4 p_matrix)
	{
		VisibilityComputer::GetInstance().SetProjectionPolygonMatrix(p_matrix);
	}
	void GE::UpdateVisibilityTextureSize(float p_maxScreenWidth, float p_maxScreenHeight)
	{
		VisibilityComputer::GetInstance().UpdateTextureSize((int)p_maxScreenWidth, (int)p_maxScreenHeight);
	}
	bool GE::IsVisibilityPointVisible(Point p_point)
	{
		return VisibilityComputer::GetInstance().IsPointVisible(p_point);
	}
	ID3D11Buffer* GE::CreateBuffer(BUFFERTYPE p_type,  std::vector<Vertex> p_mesh, std::vector<VertexAnimated> p_meshAnimated)
	{
		return Buffer::CreateBuffer(p_type, GetDevice(), p_mesh, p_meshAnimated);
	}

	void GE::SS_AddStaticLine(Line p_line)
	{
		ShadowShapes::GetInstance()->AddStaticLine(p_line);
	}
	void GE::SS_Update(float p_deltaTime)
	{
		ShadowShapes::GetInstance()->Update(p_deltaTime);
	}
	void GE::SS_DebugRender()
	{
		ShadowShapes::GetInstance()->DebugRender();
	}
	void GE::SS_AddSmokeBomb(Point p_point, float p_deltaTime)
	{
		ShadowShapes::GetInstance()->AddSmokeBombShape(p_point, p_deltaTime);
	}

	void GE::SS_ClearStaticLines()
	{
		ShadowShapes::GetInstance()->clearStaticLines();
	}

}

//#endif