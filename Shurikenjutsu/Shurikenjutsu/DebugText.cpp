#include "DebugText.h"
#include "GUIText.h"
#include "Globals.h"
#include "Network.h"
#include "InputManager.h"

DebugText* DebugText::m_instance;

DebugText::DebugText(){}
DebugText::~DebugText(){}

DebugText* DebugText::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new DebugText();
	}

	return m_instance;
}

bool DebugText::Initialize()
{
	m_originPos = DirectX::XMFLOAT3((-(float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH + 100.0f) * 0.5f, ((float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT - 20.0f) * 0.5f, 1.0f);
	m_size = 20.0f;
	m_renderText = false;
	#ifdef _DEBUG
		m_renderText = true;
	#endif

	m_fpsText = new GUIText();
	m_fpsText->InitializeCalibri("0 fps", m_size, m_originPos.x, m_originPos.y, 0xFFFFFFFF);

	m_virtualMemText = new GUIText();
	m_virtualMemText->InitializeCalibri("VRAM: 0 MB", m_size, m_originPos.x, m_originPos.y - 25.0f, 0xFFFFFFFF);

	m_physicalMemText = new GUIText();
	m_physicalMemText->InitializeCalibri("RAM: 0 MB", m_size, m_originPos.x, m_originPos.y - 50.0f, 0xFFFFFFFF);

	m_pingText = new GUIText();
	m_pingText->InitializeCalibri("0 ms", m_size, m_originPos.x, m_originPos.y - 75.0f, 0xFFFFFFFF);

	m_inMessagesText = new GUIText();
	m_inMessagesText->InitializeCalibri("In: 0 B/s", m_size, m_originPos.x, m_originPos.y - 100.0f, 0xFFFFFFFF);

	m_outMessagesText = new GUIText();
	m_outMessagesText->InitializeCalibri("Out: 0 B/s", m_size, m_originPos.x, m_originPos.y - 125.0f, 0xFFFFFFFF);

	return true;
}

void DebugText::Shutdown()
{
	if (m_fpsText != nullptr)
	{
		m_fpsText->Shutdown();
		delete m_fpsText;
		m_fpsText = nullptr;
	}

	if (m_virtualMemText != nullptr)
	{
		m_virtualMemText->Shutdown();
		delete m_virtualMemText;
		m_virtualMemText = nullptr;
	}

	if (m_physicalMemText != nullptr)
	{
		m_physicalMemText->Shutdown();
		delete m_physicalMemText;
		m_physicalMemText = nullptr;
	}

	if (m_pingText != nullptr)
	{
		m_pingText->Shutdown();
		delete m_pingText;
		m_pingText = nullptr;
	}

	if (m_inMessagesText != nullptr)
	{
		m_inMessagesText->Shutdown();
		delete m_inMessagesText;
		m_inMessagesText = nullptr;
	}

	if (m_outMessagesText != nullptr)
	{
		m_outMessagesText->Shutdown();
		delete m_outMessagesText;
		m_outMessagesText = nullptr;
	}

	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

void DebugText::Update()
{
	if (InputManager::GetInstance()->IsKeyClicked(VK_F1))
	{
		m_renderText = !m_renderText;
	}

	if (m_renderText)
	{
		SetFPSText(GLOBAL::GetInstance().FPS);
		SetPingText(Network::GetInstance()->GetLastPing());
		SetInMessagesText(ServerGlobals::BYTES_IN);
		SetOutMessagesText(ServerGlobals::BYTES_OUT);
	}
}

void DebugText::Render()
{
	if (m_renderText)
	{
		m_fpsText->Render();
		m_virtualMemText->Render();
		m_physicalMemText->Render();
		m_pingText->Render();
		m_inMessagesText->Render();
		m_outMessagesText->Render();
	}
}

void DebugText::SetFPSText(std::string p_fps)
{
	m_fpsText->SetText(p_fps + " FPS");
	
	int fps = std::stoi(p_fps);
	if (fps < 30)
	{
		m_fpsText->SetColor(0xFF0000FF);
	}
	else
	{
		m_fpsText->SetColor(0xFFFFFFFF);
	}
}

void DebugText::SetVRAMText(int p_vramMBUsed)
{
	m_virtualMemText->SetText("VRAM: " + std::to_string(p_vramMBUsed) + " MB");

	if (p_vramMBUsed > 256)
	{
		m_fpsText->SetColor(0xFF0000FF);
	}
	else
	{
		m_fpsText->SetColor(0xFFFFFFFF);
	}
}

void DebugText::SetRAMText(int p_ramMBUsed)
{
	m_physicalMemText->SetText("RAM: " + std::to_string(p_ramMBUsed) + " MB");

	if (p_ramMBUsed > 256)
	{
		m_fpsText->SetColor(0xFF0000FF);
	}
	else
	{
		m_fpsText->SetColor(0xFFFFFFFF);
	}
}

void DebugText::SetPingText(int p_ping)
{
	m_pingText->SetText(std::to_string(p_ping) + " ms");
}

void DebugText::SetInMessagesText(int p_inMessages)
{
	m_inMessagesText->SetText("In: " + std::to_string(p_inMessages) + " B/s");
}

void DebugText::SetOutMessagesText(int p_outMessages)
{
	m_outMessagesText->SetText("Out: " + std::to_string(p_outMessages) + " B/s");
}