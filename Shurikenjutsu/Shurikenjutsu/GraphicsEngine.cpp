#include "GraphicsEngine.h"

bool GraphicsEngine::Initialize(HWND p_handle)
{
	bool result = true;

	// Initialize directX.
	result = m_directX.Initialize(p_handle);
	if (result)
	{
		m_directX.Present();
		ConsolePrintSuccess("DirectX initialized successfully.");
		std::string version = "DirectX version: " + CreateTitle(m_directX.GetVersion());
		ConsolePrintText(version);
	}

	// Initialize scene shader.
	m_sceneShader.Initialize(m_directX.GetDevice(), p_handle);

	return result;
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
		ConsolePrintError("Creating title from version failed.");
		return "ERROR";
	}
	}
}