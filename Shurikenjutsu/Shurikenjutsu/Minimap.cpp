#include "Minimap.h"


Minimap::Minimap()
{
}


Minimap::~Minimap()
{
}

bool Minimap::Initialize()
{
	m_playerDot = new GUIElement();
	// Create minimap as guielement for instant fix for pos and rendering
	m_minimap = new GUIElement();
	float sizeX = 200.0f;
	float sizeY = 200.0f;
	// Initiliaze with pos, size and textures
	m_minimap->Initialize(DirectX::XMFLOAT3(-1 * (GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f) + (sizeX * 0.5f),
		-1 * (GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f) + (sizeY * 0.5f), 0.0f),
		sizeX, sizeY, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/minimap.png"));
	
	m_playerDotStartPos = DirectX::XMFLOAT3(-1 * (GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f) + (sizeX * 0.5f),
		-1 * (GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f) + (sizeY * 0.5f), 0.0f);
	
	m_playerDot->Initialize(m_playerDotStartPos, 10, 10, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/minimap_redDot.png"));
	
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
	float xPercent, zPercent;
	bool xPositive, zPositive;
	xPositive = true;
	zPositive = true;
	DirectX::XMFLOAT3 playerPos = p_playerPos;
	playerPos.y = playerPos.z;
	playerPos.z = 0;
	/*if (playerPos.x < 0)
	{
		xPositive = false;
		playerPos.x *= -1;
	}
	if (playerPos.z < 0)
	{
		zPositive = false;
		playerPos.z *= -1;
	}*/

	xPercent = playerPos.x / 53;	// 53 size of map in x from middle
	zPercent = playerPos.z / 65;	// 65 size of map in z from middle
	
	playerPos.x = xPercent * 100;
	playerPos.z = zPercent * 100;

	m_playerDot->SetPosition(DirectX::XMFLOAT3((m_playerDotStartPos.x + playerPos.x), (m_playerDotStartPos.y + playerPos.y), (m_playerDotStartPos.z + playerPos.z)));

}

void Minimap::Render()
{
	m_minimap->QueueRender();
	m_playerDot->QueueRender();
}