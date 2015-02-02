#include "Minimap.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"

#define MAPSIZEX 43
#define MAPSIZEY 50

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
	m_minimap->Initialize(m_centerOfMinimapPos,	m_minimapWidth, m_minimapHeight, TextureLibrary::GetInstance()->GetTexture(MINIMAP_TEXTURE));
	
	m_playerDot->Initialize(m_centerOfMinimapPos, 10, 10, TextureLibrary::GetInstance()->GetTexture(MINIMAP_RED_DOT_TEXTURE));

	DirectX::XMFLOAT3 startPosForOtherPlayers = DirectX::XMFLOAT3(-1000, -1000, 0);
	for (int i = 0; i < 7; i++)
	{
		m_otherPlayers[i] = new GUIElement();
		m_otherPlayers[i]->Initialize(startPosForOtherPlayers, 10, 10, TextureLibrary::GetInstance()->GetTexture(MINIMAP_BLUE_DOT_TEXTURE));
	}
	
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
	m_playerDot->SetPosition(ConvertPosToMinimapPos(p_playerPos));
}

void Minimap::Render()
{
	m_minimap->QueueRender();
	for (int i = 0; i < 7; i++)
	{
		m_otherPlayers[i]->QueueRender();
	}
	m_playerDot->QueueRender();
}

void Minimap::UpdatePlayersPositon(int p_index, DirectX::XMFLOAT3 p_pos)
{
	DirectX::XMFLOAT3 pos = ConvertPosToMinimapPos(p_pos);
	m_otherPlayers[p_index]->SetPosition(pos);
}

DirectX::XMFLOAT3 Minimap::ConvertPosToMinimapPos(DirectX::XMFLOAT3 p_playerPos)
{
	float xPercent, yPercent;
	DirectX::XMFLOAT3 playerPos = p_playerPos;
	playerPos.y = playerPos.z;
	playerPos.z = 0;
	// offset for map being higher than width..
	float offset = 25;
	// Calc where the player is on the minimap in precent from center
	xPercent = playerPos.x / MAPSIZEX;	// 43 size of map in x from middle
	yPercent = playerPos.y / MAPSIZEY;	// 50 size of map in z from middle
	playerPos.x = xPercent * m_minimapWidth * 0.5f;
	playerPos.y = yPercent * (m_minimapHeight - offset) * 0.5f;
	playerPos.x = m_centerOfMinimapPos.x + playerPos.x;
	playerPos.y = m_centerOfMinimapPos.y + playerPos.y;
	return playerPos;
}

void Minimap::SetTeamTexture(int p_index, int p_team)
{
	if (p_team == 1)
	{
		m_otherPlayers[p_index]->SetTexture(TextureLibrary::GetInstance()->GetTexture(MINIMAP_RED_DOT_TEXTURE));
	}
	else
	{
		m_otherPlayers[p_index]->SetTexture(TextureLibrary::GetInstance()->GetTexture(MINIMAP_BLUE_DOT_TEXTURE));
	}
}

void Minimap::SetPlayerTexture(int p_team)
{
	if (p_team == 1)
	{
		m_playerDot->SetTexture(TextureLibrary::GetInstance()->GetTexture(MINIMAP_RED_DOT_TEXTURE));
	}
	else
	{
		m_playerDot->SetTexture(TextureLibrary::GetInstance()->GetTexture(MINIMAP_BLUE_DOT_TEXTURE));
	}
}

void Minimap::SetPlayerPos(int p_index, DirectX::XMFLOAT3 p_pos)
{
	m_otherPlayers[p_index]->SetPosition(p_pos);
}