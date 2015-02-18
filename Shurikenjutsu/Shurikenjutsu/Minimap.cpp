#include "Minimap.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"
#include "VisibilityComputer.h"

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
	m_background = new GUIElement();
	m_vision = new GUIElement();
	
	m_minimapWidth = 222.0f;
	m_minimapHeight = 250.0f;
	
	// Save center of minimap.
	m_centerOfMinimapPos = DirectX::XMFLOAT3(-1 * (GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f) + (m_minimapWidth * 0.5f), -1 * (GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f) + (m_minimapHeight * 0.5f), 0.0f);
	
	// Initiliaze with pos, size and textures, draw center of texture at center of minimap.
	m_minimap->Initialize(m_centerOfMinimapPos,	m_minimapWidth, m_minimapHeight, TextureLibrary::GetInstance()->GetTexture(MINIMAP_TEXTURE));
	m_playerDot->Initialize(m_centerOfMinimapPos, 10, 10, TextureLibrary::GetInstance()->GetTexture(MINIMAP_RED_DOT_TEXTURE));
	m_background->Initialize(DirectX::XMFLOAT3(m_centerOfMinimapPos.x + 12.0f, m_centerOfMinimapPos.y + 12.0f, 0.0f) , 246, 275, TextureLibrary::GetInstance()->GetTexture(MINIMAP_BG_TEXTURE));
	m_vision->Initialize(m_centerOfMinimapPos, m_minimapWidth, m_minimapHeight, TextureLibrary::GetInstance()->GetTexture(MINIMAP_TEXTURE));

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
	if (m_minimap != nullptr)
	{
		delete m_minimap;
		m_minimap = nullptr;
	}

	if (m_playerDot != nullptr)
	{
		delete m_playerDot;
		m_playerDot = nullptr;
	}

	if (m_background != nullptr)
	{
		delete m_background;
		m_background = nullptr;
	}

	for (int i = 0; i < 7; i++)
	{
		if (m_otherPlayers[i] != nullptr)
		{
			delete m_otherPlayers[i];
			m_otherPlayers[i] = nullptr;
		}
	}

	if (m_vision != nullptr)
	{
		delete m_vision;
		m_vision = nullptr;
	}
}

void Minimap::Update(DirectX::XMFLOAT3 p_playerPos)
{
	m_playerDot->SetPosition(ConvertPosToMinimapPos(p_playerPos));
	m_vision->SetPosition(ConvertPosToMinimapPos(p_playerPos));
}

void Minimap::Render()
{
	m_background->QueueRender();
	m_minimap->QueueRender();

	for (int i = 0; i < 7; i++)
	{
		m_otherPlayers[i]->QueueRender();
	}

	m_playerDot->QueueRender();

	m_vision->SetTexture(VisibilityComputer::GetInstance().GetMinimapTarget());
	m_vision->QueueRender();
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
	float offset = 13;

	// Calc where the player is on the minimap in precent from center
	xPercent = playerPos.x / MAPSIZEX;	// 43 size of map in x from middle
	yPercent = playerPos.y / MAPSIZEY;	// 50 size of map in z from middle
	playerPos.x = xPercent * (m_minimapWidth - offset) * 0.5f;
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