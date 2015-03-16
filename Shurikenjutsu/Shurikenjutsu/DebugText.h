#ifndef DEBUGTEXT_H_
#define DEBUGTEXT_H_

#define WIN32_LEAN_AND_MEAN

#include <DirectXMath.h>
#include <string>

class GUIText;

class DebugText
{
public:
	DebugText(const DebugText&) = delete;
	DebugText& operator=(const DebugText&) = delete;

	static DebugText* GetInstance();

	bool Initialize();
	void Shutdown();

	void Update();
	void Render();

	void SetFPSText(std::string p_fps);
	void SetVRAMText(int p_vramMBUsed);
	void SetRAMText(int p_ramMBUsed);
	void SetPingText(int p_ping);
	void SetInMessagesText(int p_inMessages);
	void SetOutMessagesText(int p_outMessages);
private:
	DebugText();
	~DebugText();

	static DebugText* m_instance;

	bool m_renderText;
	bool m_renderNetworkText;
	DirectX::XMFLOAT3 m_originPos;
	float m_size;

	GUIText* m_fpsText;
	GUIText* m_virtualMemText;
	GUIText* m_physicalMemText;
	GUIText* m_pingText;
	GUIText* m_inMessagesText;
	GUIText* m_outMessagesText;
	GUIText* m_inNrMessages;
	GUIText* m_outNrMessages;
};

#endif