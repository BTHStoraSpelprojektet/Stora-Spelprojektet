#include "GraphicsEngine.h"

DirectXWrapper GraphicsEngine::m_directX;
SceneShader GraphicsEngine::m_sceneShader;
InstancedShader GraphicsEngine::m_instanceShader;
GUIShader GraphicsEngine::m_GUIShader;
DepthShader GraphicsEngine::m_depthShader;
ParticleShader GraphicsEngine::m_particleShader;
HWND GraphicsEngine::m_windowHandle;
RenderTarget GraphicsEngine::m_shadowMap;

bool GraphicsEngine::Initialize(HWND p_handle)
{
	bool result = true;
	m_windowHandle = p_handle;

	// Initialize directX.
	result = m_directX.Initialize(p_handle);
	if (result)
	{
		m_directX.Present();
		ConsolePrintSuccess("DirectX initialized successfully.");
		std::string version = "DirectX version: " + CreateTitle(m_directX.GetVersion());
		ConsolePrintText(version);
		ConsoleSkipLines(1);
	}

	// Initialize the scene shader.
	if (m_sceneShader.Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("Scene shader initialized successfully.");
		ConsoleSkipLines(1);
	}

	// Initialize the instance shader
	if (m_instanceShader.Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("Instanced shader initialized successfully.");
		ConsoleSkipLines(1);
	}

	// Initialize 2D GUI shader.
	if (m_GUIShader.Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("GUI 2D shader initialized successfully.");
		ConsoleSkipLines(1);
	}

	// Initialize the particle shader.
	if (m_particleShader.Initialize(m_directX.GetDevice()))
	{
		ConsolePrintSuccess("Particle shader initialized successfully.");
		ConsoleSkipLines(1);
	}

	// Initialize the depth buffer.
	if (m_depthShader.Initialize(m_directX.GetDevice(), m_directX.GetContext()))
	{
		ConsolePrintSuccess("Depth shader initialized successfully.");
		ConsoleSkipLines(1);
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

	return result;
}

void GraphicsEngine::Shutdown()
{
	m_particleShader.Shutdown();
	m_shadowMap.Shutdown();

	// TODO shutdowns for everyone!
}

void GraphicsEngine::Render(SHADERTYPE p_shader, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex, std::vector<DirectX::XMMATRIX> p_boneTransforms)
{
	switch (p_shader)
	{
		case(SHADERTYPE_SCENE) :
		{
			m_sceneShader.Render(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);

			break;
		}
		case(SHADERTYPE_INSTANCED) :
		{
			m_instanceShader.Render( m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_instanceIndex);

			break;
		}
		case(SHADERTYPE_ANIMATED) :
		{
			m_sceneShader.RenderAnimated(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap, p_boneTransforms);

			break;
		}
		case(SHADERTYPE_DEPTH) :
		{
			m_depthShader.Render(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture);

			break;
		}

		default:
		{
			ConsolePrintErrorAndQuit("Invalid shader type passed to Render().");

			break;
		}
	}
}

void GraphicsEngine::Render(SHADERTYPE p_shader, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap)
{
	switch (p_shader)
	{
		case(SHADERTYPE_SCENE) :
		{
			GraphicsEngine::TurnOnAlphaBlending();
			m_sceneShader.Render(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture, p_normalMap);
			GraphicsEngine::TurnOffAlphaBlending();

			break;
		}

		case(SHADERTYPE_DEPTH) :
		{
			m_depthShader.Render(m_directX.GetContext(), p_mesh, p_numberOfVertices, p_worldMatrix, p_texture);

			break;
		}
	}
}

void GraphicsEngine::RenderUI(DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	m_GUIShader.Render(m_directX.GetContext(), p_worldMatrix, p_texture);
}

void GraphicsEngine::RenderLines(ID3D11Buffer* p_mesh, int p_number, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_sceneShader.RenderLine(m_directX.GetContext(), p_mesh, p_number, p_color, p_worldMatrix);
}

void GraphicsEngine::RenderParticles(ID3D11Buffer* p_mesh, int p_vertexCount, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture)
{
	m_particleShader.Render(m_directX.GetContext(), p_mesh, p_vertexCount, p_worldMatrix, p_texture);
}

void GraphicsEngine::SetViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_sceneShader.UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
	m_instanceShader.UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
	m_particleShader.UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
}

void GraphicsEngine::SetLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_sceneShader.UpdateLightViewAndProjection(p_viewMatrix, p_projectionMatrix);
	m_depthShader.UpdateViewAndProjection(p_viewMatrix, p_projectionMatrix);
}

void GraphicsEngine::SetShadowMap()
{
	if (m_shadowMap.GetRenderTarget() == nullptr)
	{
		ConsolePrintErrorAndQuit("Shadow map is a null pointer.");
	}

	m_sceneShader.UpdateShadowMap(m_shadowMap.GetRenderTarget());
}

void GraphicsEngine::SetSceneFog(float p_fogStart, float p_fogEnd, float p_fogDensity)
{
	m_sceneShader.UpdateFogBuffer(m_directX.GetContext(), p_fogStart, p_fogEnd, p_fogDensity);
	m_instanceShader.UpdateFogBuffer(m_directX.GetContext(), p_fogStart, p_fogEnd, p_fogDensity);
}

void GraphicsEngine::SetSceneDirectionalLight(DirectionalLight& p_dLight)
{
	m_sceneShader.UpdateFrameBuffer(m_directX.GetContext(), p_dLight);
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
	return m_sceneShader.GetShadowMap();
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

void GraphicsEngine::TurnOnAlphaBlending()
{
	m_directX.TurnOnAlphaBlending();
}

void GraphicsEngine::TurnOffAlphaBlending()
{
	m_directX.TurnOffAlphaBlending();
}

void GraphicsEngine::AddInstanceBuffer(int p_numberOfInstances)
{
	m_instanceShader.AddInstanceBuffer(m_directX.GetDevice(), p_numberOfInstances);
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

		GLOBAL::GetInstance().FULLSCREEN = true;
	}    
	
	else    
	{        
		if (FAILED(m_directX.GetSwapChain()->SetFullscreenState(false, nullptr)))
		{
			ConsolePrintErrorAndQuit("Setting windowed mode failed.");
			return false;
		}    
		
		GLOBAL::GetInstance().FULLSCREEN = false;
	}    

	return true;
}

void GraphicsEngine::BeginRenderToShadowMap()
{
	ID3D11ShaderResourceView* nullPointer = NULL;
	m_directX.GetContext()->PSSetShaderResources(0, 1, &nullPointer);

	m_shadowMap.SetAsRenderTarget(m_directX.GetContext());
	m_shadowMap.Clear(m_directX.GetContext());
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
	m_sceneShader.SetShadowMapDimensions(m_directX.GetDevice(), m_directX.GetContext(), p_width, p_height);
}