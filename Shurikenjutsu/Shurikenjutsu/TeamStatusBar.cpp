#include "TeamStatusBar.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"
#include "TextureLibrary.h"

TeamStatusBar::TeamStatusBar()
{
}


TeamStatusBar::~TeamStatusBar()
{
}

bool TeamStatusBar::Initialize()
{
	// Team 1 = red
	// Team 2 = blue
	redColorDots = std::map<RakNet::RakNetGUID, GUIElement>();
	blueColorDots = std::map<RakNet::RakNetGUID, GUIElement>();
	m_dotSize = 30.0f;
	m_dotPosOffset = 40.0f;
	m_addedMyself = false;

	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	std::vector<PlayerNet> enemies = Network::GetInstance()->GetOtherPlayers();

	m_originPos = DirectX::XMFLOAT3(0.0f, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - 50.0f, 1.0f);

	return true;
}

void TeamStatusBar::Shutdown()
{
	redColorDots.clear();
	blueColorDots.clear();
}

void TeamStatusBar::Update()
{
	// Update yourself
	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	if (!m_addedMyself)
	{
		if (player.team == 1)
		{
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3((float)(redColorDots.size() + 1) * m_dotPosOffset, m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_RED_PLAYER));
			redColorDots[player.guid] = element;
			m_addedMyself = true;
		}
		else if (player.team == 2)
		{
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-((float)(blueColorDots.size() + 1) * m_dotPosOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_BLUE_PLAYER));
			blueColorDots[player.guid] = element;
			m_addedMyself = true;
		}
	}
	else
	{
		if (player.team == 1)
		{
			if (player.isAlive)
			{
				redColorDots[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_RED_PLAYER));
			}
			else
			{
				redColorDots[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
			}
		}
		else if(player.team == 2)
		{
			if (player.isAlive)
			{
				blueColorDots[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_BLUE_PLAYER));
			}
			else
			{
				blueColorDots[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
			}
		}
		
	}


	// Check for new and updated players isAlive
	std::vector<PlayerNet> players = Network::GetInstance()->GetOtherPlayers();
	std::map<RakNet::RakNetGUID, PlayerNet> playersMap = std::map<RakNet::RakNetGUID, PlayerNet>();
	for (unsigned int i = 0; i < players.size(); i++)
	{
		playersMap[players[i].guid] = players[i];
		// Team red
		if (players[i].team == 1)
		{
			if (redColorDots.find(players[i].guid) != redColorDots.end())
			{
				if (players[i].isAlive)
				{
					redColorDots[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_RED_PLAYER));
				}
				else
				{
					redColorDots[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
				}
			}
			else
			{
				// Add new red dot
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3((float)(redColorDots.size() + 1) * m_dotPosOffset, m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_RED_PLAYER));
				redColorDots[players[i].guid] = element;
			}
		}
		// Team blue
		else if (players[i].team == 2)
		{
			if (blueColorDots.find(players[i].guid) != blueColorDots.end())
			{
				if (players[i].isAlive)
				{
					blueColorDots[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_BLUE_PLAYER));
				}
				else
				{
					blueColorDots[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
				}
			}
			else
			{
				// Add new blue dot
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-((float)(blueColorDots.size() + 1) * m_dotPosOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_BLUE_PLAYER));
				blueColorDots[players[i].guid] = element;
			}
		}
	}

	// Check for dead players in red team
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = redColorDots.begin(); it != redColorDots.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a dead player
			it = redColorDots.erase(it);
			ResizeRedColorList();
		}
		else
		{
			++it;
		}
	}


	// Check for dead players in blue team
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = blueColorDots.begin(); it != blueColorDots.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a dead player
			it = blueColorDots.erase(it);
			ResizeBlueColorList();
		}
		else
		{
			++it;
		}
	}
}

void TeamStatusBar::Render()
{
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = redColorDots.begin(); it != redColorDots.end(); it++)
	{
		it->second.QueueRender();
	}
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = blueColorDots.begin(); it != blueColorDots.end(); it++)
	{
		it->second.QueueRender();
	}
}

void TeamStatusBar::ResizeRedColorList()
{
	int index = 0;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = redColorDots.begin(); it != redColorDots.end(); it++)
	{
		index++;
		redColorDots[it->first].SetPosition(DirectX::XMFLOAT3((float)index * m_dotPosOffset, m_originPos.y, m_originPos.z));
	}
}

void TeamStatusBar::ResizeBlueColorList()
{
	int index = 0;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = blueColorDots.begin(); it != blueColorDots.end(); it++)
	{
		index++;
		blueColorDots[it->first].SetPosition(DirectX::XMFLOAT3(-((float)index * m_dotPosOffset), m_originPos.y, m_originPos.z));
	}
}