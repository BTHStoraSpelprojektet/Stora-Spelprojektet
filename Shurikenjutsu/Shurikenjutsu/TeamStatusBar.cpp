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
	m_redColorPlayers = std::map<RakNet::RakNetGUID, GUIElement>();
	m_blueColorPlayers = std::map<RakNet::RakNetGUID, GUIElement>();
	m_dotSize = 40.0f;
	m_dotPosOffset = 45.0f;
	m_startOffset = 2;
	m_addedMyself = false;
	m_timeSec = 0;
	m_timeMin = 0;

	m_originPos = DirectX::XMFLOAT3(0.0f, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - 40.0f, 1.0f);

	// Background squares
	m_redSquares = std::vector<GUIElement>();
	m_blueSquares = std::vector<GUIElement>();


	// Score text
	m_redScore = GUIText();
	m_redScore.Initialize("0", 25.0f, m_originPos.x + 15.0f, m_originPos.y - m_dotPosOffset * 0.3f, 0xff0700B6);
	m_blueScore = GUIText();
	m_blueScore.Initialize("0", 25.0f, m_originPos.x - 15.0f, m_originPos.y - m_dotPosOffset * 0.3f, 0xffB71300);

	// Timer text
	m_timerText = GUIText();
	m_timerText.Initialize("", 25.0f, m_originPos.x, m_originPos.y + m_dotPosOffset * 0.3f, 0xffffffff);

	// Send so we are synced with the server
	Network::GetInstance()->SyncTimer();
	Network::GetInstance()->SyncTeamScore();

	return true;
}

void TeamStatusBar::Shutdown()
{
	m_redColorPlayers.clear();
	m_blueColorPlayers.clear();
	m_redSquares.clear();
	m_blueSquares.clear();
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
			element.Initialize(DirectX::XMFLOAT3((float)(m_redColorPlayers.size() + m_startOffset) * m_dotPosOffset, m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_redColorPlayers[player.guid] = element;
			AddRedSquare();
			m_addedMyself = true;
		}
		else if (player.team == 2)
		{
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-((float)(m_blueColorPlayers.size() + m_startOffset) * m_dotPosOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_blueColorPlayers[player.guid] = element;
			AddBlueSquare();
			m_addedMyself = true;
		}
	}
	else
	{
		if (player.team == 1)
		{
			if (player.isAlive)
			{
				m_redColorPlayers[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			}
			else
			{
				m_redColorPlayers[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
			}
		}
		else if(player.team == 2)
		{
			if (player.isAlive)
			{
				m_blueColorPlayers[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			}
			else
			{
				m_blueColorPlayers[player.guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
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
			if (m_redColorPlayers.find(players[i].guid) != m_redColorPlayers.end())
			{
				if (players[i].isAlive)
				{
					m_redColorPlayers[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				}
				else
				{
					m_redColorPlayers[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
				}
			}
			else
			{
				// Add new red dot
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3((float)(m_redColorPlayers.size() + m_startOffset) * m_dotPosOffset, m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_redColorPlayers[players[i].guid] = element;
				AddRedSquare();
			}
		}
		// Team blue
		else if (players[i].team == 2)
		{
			if (m_blueColorPlayers.find(players[i].guid) != m_blueColorPlayers.end())
			{
				if (players[i].isAlive)
				{
					m_blueColorPlayers[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				}
				else
				{
					m_blueColorPlayers[players[i].guid].SetTexture(TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
				}
			}
			else
			{
				// Add new blue dot
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-((float)(m_blueColorPlayers.size() + m_startOffset) * m_dotPosOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_blueColorPlayers[players[i].guid] = element;
				AddBlueSquare();
			}
		}
	}

	// Check for dead players in red team
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a dead player
			it = m_redColorPlayers.erase(it);
			ResizeRedColorList();
			m_redSquares.pop_back();
		}
		else
		{
			++it;
		}
	}


	// Check for dead players in blue team
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a dead player
			it = m_blueColorPlayers.erase(it);
			ResizeBlueColorList();
			m_blueSquares.pop_back();
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
	unsigned int index = 0;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		if (index < m_redSquares.size())
		{
			m_redSquares[index].SetPosition(it->second.GetPosition());
			m_redSquares[index].QueueRender();
		}
		it->second.QueueRender();
		index++;
	}
	index = 0;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		if (index < m_blueSquares.size())
		{
			m_blueSquares[index].SetPosition(it->second.GetPosition());
			m_blueSquares[index].QueueRender();
		}
		it->second.QueueRender();
		index++;
	}

	m_redScore.Render();
	m_blueScore.Render();

	m_timerText.Render();
}

void TeamStatusBar::ResizeRedColorList()
{
	int index = m_startOffset;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		m_redColorPlayers[it->first].SetPosition(DirectX::XMFLOAT3((float)index * m_dotPosOffset, m_originPos.y, m_originPos.z));
		index++;
	}
}

void TeamStatusBar::ResizeBlueColorList()
{
	int index = m_startOffset;
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		m_blueColorPlayers[it->first].SetPosition(DirectX::XMFLOAT3(-((float)index * m_dotPosOffset), m_originPos.y, m_originPos.z));
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

void TeamStatusBar::AddRedSquare()
{
	GUIElement square = GUIElement();
	square.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_dotSize + 5, m_dotSize + 5, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_RED_PLAYER));
	m_redSquares.push_back(square);
}

void TeamStatusBar::AddBlueSquare()
{
	GUIElement square = GUIElement();
	square.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_dotSize + 5, m_dotSize + 5, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_BLUE_PLAYER));
	m_blueSquares.push_back(square);
}