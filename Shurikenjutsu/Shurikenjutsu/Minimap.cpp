#include "Minimap.h"
#include "Globals.h"


Minimap::Minimap()
{
}


Minimap::~Minimap()
{
}

bool Minimap::Initialize()
{
	m_playerDot = new GUIElement();
	m_minimap = new GUIElement();

	m_minimapWidth = 200.0f;
	m_minimapHeight = 250.0f;
	
	// Save center of minimap
	m_centerOfMinimapPos = DirectX::XMFLOAT3(-1 * (GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f) + (m_minimapWidth * 0.5f),
		-1 * (GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f) + (m_minimapHeight * 0.5f), 0.0f);
	
	// Initiliaze with pos, size and textures, draw center of texture at center of minimap..
	m_minimap->Initialize(m_centerOfMinimapPos,	m_minimapWidth, m_minimapHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/minimap.png"));
	
	m_playerDot->Initialize(m_centerOfMinimapPos, 10, 10, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/minimap_redDot.png"));
	
	return true;
}

void Minimap::Shutdown()
{
	// Shutdown minimap pointer
	if (m_minimap != NULL)
	{
		//m_minimap->Shutdown();
	}
	if (m_playerDot != NULL)
	{
		//m_playerDot->Shutdown();
	}
}

void Minimap::Update(DirectX::XMFLOAT3 p_playerPos)
{
	float xPercent, yPercent;
	DirectX::XMFLOAT3 playerPos = p_playerPos;
	playerPos.y = playerPos.z;
	playerPos.z = 0;

	// Calc where the player is on the minimap in precent from center
	xPercent = playerPos.x / 53;	// 53 size of map in x from middle
	yPercent = playerPos.y / 65;	// 67 size of map in z from middle
	playerPos.x = xPercent * m_minimapWidth * 0.5f;
	playerPos.y = yPercent * m_minimapHeight * 0.5f; 

	m_playerDot->SetPosition(DirectX::XMFLOAT3((m_centerOfMinimapPos.x + playerPos.x), (m_centerOfMinimapPos.y + playerPos.y), (m_centerOfMinimapPos.z + playerPos.z)));

}

void Minimap::Render()
{
	m_minimap->QueueRender();
	m_playerDot->QueueRender();
}