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
	m_dotSize = 40.0f;
	m_dotPosOffset = 45.0f;
	m_startOffset = 2;
	m_addedMyself = false;
	m_timeSec = 0;
	m_timeMin = 0;

	m_originPos = DirectX::XMFLOAT3(0.0f, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - 40.0f, 1.0f);

	// Score text
	m_redScore = GUIText();
	m_redScore.Initialize("0", 25.0f, m_originPos.x + 15.0f, m_originPos.y - m_dotPosOffset * 0.3f, 0xff0700B6);
	m_blueScore = GUIText();
	m_blueScore.Initialize("0", 25.0f, m_originPos.x - 15.0f, m_originPos.y - m_dotPosOffset * 0.3f, 0xffB71300);

	// Timer text
	m_timerText = GUIText();
	m_timerText.Initialize("", 25.0f, m_originPos.x, m_originPos.y + m_dotPosOffset * 0.3f, 0xffffffff);

	// Send so we are synced with the server timer
	Network::GetInstance()->SyncTimer();

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
			element.Initialize(DirectX::XMFLOAT3((float)(redColorDots.size() + m_startOffset) * m_dotPosOffset, m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			redColorDots[player.guid] = element;
			m_addedMyself = true;
		}
		else if (player.team == 2)
		{
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-((float)(blueColorDots.size() + m_startOffset) * m_dotPosOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
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
				redColorDots[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
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
				blueColorDots[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
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
					redColorDots[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
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
				element.Initialize(DirectX::XMFLOAT3((float)(redColorDots.size() + m_startOffset) * m_dotPosOffset, m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
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
					blueColorDots[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
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
				element.Initialize(DirectX::XMFLOAT3(-((float)(blueColorDots.size() + m_startOffset) * m_dotPosOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
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

	// End of player check

	// Check for team score
	m_redScore.SetText(std::to_string(Network::GetInstance()->GetRedTeamScore()));
	m_blueScore.SetText(std::to_string(Network::GetInstance()->GetBlueTeamScore()));


	// Update timer
	// Check for new round (reset times)
	if (Network::GetInstance()->RoundRestarted())
	{
		m_timeSec = 0;
		m_timeMin = 0;
	}

	// Add time and change text
	m_timeSec += GLOBAL::GetInstance().GetDeltaTime();
	if (m_timeSec >= 60)
	{
		m_timeSec -= 60;
		m_timeMin += 1;
	}
	std::string secString = std::to_string((int)m_timeSec);
	if (m_timeSec < 10)
	{
		secString = "0" + secString;
	}
	m_timerText.SetText(std::to_string((int)m_timeMin) + ":" + secString);

	// Check if a new round is about to start (then show negative time i.e. -0:05 if new round is starting in 5 sec)
	if (Network::GetInstance()->RoundRestarting())
	{
		secString = std::to_string(Network::GetInstance()->GetRestartingTimer());
		if (Network::GetInstance()->GetRestartingTimer() < 10)
		{
			secString = "0" + secString;
		}
		m_timerText.SetText("-0:" + secString);
	}

	// Check for synced timer
	double min, sec;
	if (Network::GetInstance()->TimerSynced(min, sec))
	{
		m_timeMin = min;
		m_timeSec = sec;
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

	m_redScore.Render();
	m_blueScore.Render();

	m_timerText.Render();
}

void TeamStatusBar::ResizeRedColorList()
{
	int index = m_startOffset;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = redColorDots.begin(); it != redColorDots.end(); it++)
	{
		redColorDots[it->first].SetPosition(DirectX::XMFLOAT3((float)index * m_dotPosOffset, m_originPos.y, m_originPos.z));
		index++;
	}
}

void TeamStatusBar::ResizeBlueColorList()
{
	int index = m_startOffset;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = blueColorDots.begin(); it != blueColorDots.end(); it++)
	{
		blueColorDots[it->first].SetPosition(DirectX::XMFLOAT3(-((float)index * m_dotPosOffset), m_originPos.y, m_originPos.z));
		index++;
	}
}

std::string TeamStatusBar::GetTextureName(int p_charNr)
{
	//NINJA_TEXTURE
	std::string textureName = "";
	textureName = NINJA_TEXTURE;
	textureName += "ninja";
	switch (p_charNr)
	{
	case 0:
	{
		textureName += "1";
		break;
	}
	case 1:
	{
		textureName += "2";
		break;
	}
	case 2:
	{
		textureName += "3";
		break;
	}		
	}
	textureName += ".png";

	return textureName;
}