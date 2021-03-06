#include "TeamStatusBar.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "InputManager.h"
#include <stdio.h>
#include "..\CommonLibs\ServerGlobals.h"
#include "Network.h"
#include "GUIElement.h"
#include "GUIText.h"

TeamStatusBar::TeamStatusBar(){}
TeamStatusBar::~TeamStatusBar(){}

bool TeamStatusBar::Initialize()
{
	// Team 1 = red
	// Team 2 = blue
	m_redColorPlayers = std::map<RakNet::RakNetGUID, GUIElement*>();
	m_blueColorPlayers = std::map<RakNet::RakNetGUID, GUIElement*>();
	m_dotSize = 50.0f;
	m_dotPosOffset = 55.0f;
	m_startOffset = 68.5f; // 67.5
	m_addedMyself = false;
	m_timeSec = 0;
	m_timeMin = 0;
	m_myTeam = 0;

	m_originPos = DirectX::XMFLOAT3(0.0f, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - 27.5f, 1.0f);

	// Background squares
	m_redSquares = std::vector<GUIElement*>();
	m_blueSquares = std::vector<GUIElement*>();
	
	// Background
	m_background = new GUIElement();
	m_background->Initialize(m_originPos, 80.0f, 55.0f, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_BACKGROUND));

	//Frame
	m_frame = new GUIElement();
	m_frame->Initialize(DirectX::XMFLOAT3(m_originPos.x, m_originPos.y - 12.5f, m_originPos.z), 570.0f, 80.0f, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_FRAME));

	// Deadplayer
	m_deadBluePlayer = std::vector<GUIElement*>();
	m_deadRedPlayer = std::vector<GUIElement*>();

	// Score text
	m_redScore = new GUIText();
	m_redScore->Initialize("0", 25.0f, m_originPos.x - 20.0f, m_originPos.y - 13.0f, 0xff0700B6);
	m_blueScore = new GUIText();
	m_blueScore->Initialize("0", 25.0f, m_originPos.x + 20.0f, m_originPos.y - 13.0f, 0xffB71300);

	// Timer text
	m_timerText = new GUIText();
	m_timerText->Initialize("", 25.0f, m_originPos.x, m_originPos.y + 15.0f, 0xffffffff);

	// Send so we are synced with the server
	Network::GetInstance()->SyncTimer();
	Network::GetInstance()->SyncTeamScore();
	return true;
}

void TeamStatusBar::Shutdown()
{
	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		delete it->second;
	}
	m_redColorPlayers.clear();

	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		delete it->second;
	}	
	m_blueColorPlayers.clear();

	for (unsigned int i = 0; i < m_redSquares.size(); i++)
	{
		delete m_redSquares[i];
	}
	m_redSquares.clear();

	for (unsigned int i = 0; i < m_blueSquares.size(); i++)
	{
		delete m_blueSquares[i];
	}
	m_blueSquares.clear();
	
	if (m_redScore != nullptr)
	{
		m_redScore->Shutdown();
		delete m_redScore;
		m_redScore = nullptr;
	}

	if (m_blueScore != nullptr)
	{
		m_blueScore->Shutdown();
		delete m_blueScore;
		m_blueScore = nullptr;
	}

	if (m_timerText != nullptr)
	{
		m_timerText->Shutdown();
		delete m_timerText;
		m_timerText = nullptr;
	}

	if (m_background != nullptr)
	{
		delete m_background;
		m_background = nullptr;
	}

	if (m_frame != nullptr)
	{
		delete m_frame;
		m_frame = nullptr;
	}

	for (unsigned int i = 0; i < m_deadBluePlayer.size(); i++)
	{
		delete m_deadBluePlayer[i];
	}
	m_deadBluePlayer.clear();

	for (unsigned int i = 0; i < m_deadRedPlayer.size(); i++)
	{
		delete m_deadRedPlayer[i];
	}
	m_deadRedPlayer.clear();
}

void TeamStatusBar::Update()
{
	// Update yourself
	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	if (!m_addedMyself)
	{
		if (player.team == 1)
		{
			GUIElement* element = new GUIElement();
			element->Initialize(DirectX::XMFLOAT3(-((float)m_redColorPlayers.size() * m_dotPosOffset + m_startOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_redColorPlayers[player.guid] = element;
			AddRedSquare();
			m_addedMyself = true;
			m_myTeam = player.team;
		}
		else if (player.team == 2)
		{
			GUIElement* element = new GUIElement();
			element->Initialize(DirectX::XMFLOAT3(((float)m_blueColorPlayers.size() * m_dotPosOffset + m_startOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_blueColorPlayers[player.guid] = element;
			AddBlueSquare();
			m_addedMyself = true;
			m_myTeam = player.team;
		}
	}
	// Player have changed team so remove him from current potraits (that team, very change, such noob)
	else if (m_addedMyself && player.team != m_myTeam)
	{
		// Look which team the player is in and remove him
		if (m_redColorPlayers.find(player.guid) != m_redColorPlayers.end())
		{
			m_redColorPlayers.erase(player.guid);
			ResizeRedColorList();
			m_addedMyself = false;
			m_myTeam = 0;
		}
		if (m_blueColorPlayers.find(player.guid) != m_blueColorPlayers.end())
		{
			m_blueColorPlayers.erase(player.guid);
			ResizeBlueColorList();
			m_addedMyself = false;
			m_myTeam = 0;
		}
	}
	else
	{
		if (player.team == 1)
		{
			m_redColorPlayers[player.guid]->SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
		}
		else if(player.team == 2)
		{
			m_blueColorPlayers[player.guid]->SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
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
				m_redColorPlayers[players[i].guid]->SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
			}
			else
			{
				// Add new red dot
				GUIElement* element = new GUIElement();
				element->Initialize(DirectX::XMFLOAT3(-((float)m_redColorPlayers.size() * m_dotPosOffset + m_startOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_redColorPlayers[players[i].guid] = element;
				AddRedSquare();
			}

			// Check so player havn't changed from blue color
			if (m_blueColorPlayers.find(players[i].guid) != m_blueColorPlayers.end())
			{
				delete m_blueColorPlayers[players[i].guid];
				m_blueColorPlayers.erase(players[i].guid);
				ResizeBlueColorList();
			}
		}
		// Team blue
		else if (players[i].team == 2)
		{
			if (m_blueColorPlayers.find(players[i].guid) != m_blueColorPlayers.end())
			{
				m_blueColorPlayers[players[i].guid]->SetTexture(TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
			}
			else
			{
				// Add new blue dot
				GUIElement* element = new GUIElement();
				element->Initialize(DirectX::XMFLOAT3(((float)m_blueColorPlayers.size() * m_dotPosOffset + m_startOffset), m_originPos.y, m_originPos.z), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_blueColorPlayers[players[i].guid] = element;
				AddBlueSquare();
			}

			// Check so player havn't changed from red color
			if (m_redColorPlayers.find(players[i].guid) != m_redColorPlayers.end())
			{
				delete m_redColorPlayers[players[i].guid];
				m_redColorPlayers.erase(players[i].guid);
				ResizeRedColorList();
			}
		}
	}

	// Check for disconnected players in red team
	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a disconnected player
			delete it->second;
			it = m_redColorPlayers.erase(it);
			ResizeRedColorList();

			delete m_redSquares[m_redSquares.size() - 1];
			m_redSquares.pop_back();

			delete m_deadRedPlayer[m_deadRedPlayer.size() - 1];
			m_deadRedPlayer.pop_back();
		}
		else
		{
			++it;
		}
	}


	// Check for disconnected players in blue team
	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a disconnected player
			delete it->second;
			it = m_blueColorPlayers.erase(it);
			ResizeBlueColorList();

			delete m_blueSquares[m_blueSquares.size() - 1];
			m_blueSquares.pop_back();

			delete m_deadBluePlayer[m_deadBluePlayer.size() - 1];
			m_deadBluePlayer.pop_back();
		}
		else
		{
			++it;
		}
	}

	// End of player check

	// Check for team score
	m_redScore->SetText(std::to_string(Network::GetInstance()->GetRedTeamScore()));
	m_blueScore->SetText(std::to_string(Network::GetInstance()->GetBlueTeamScore()));


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
	m_timerText->SetText(std::to_string((int)m_timeMin) + ":" + secString);

	// Check if a new round is about to start (then show negative time i.e. -0:05 if new round is starting in 5 sec)
	if (Network::GetInstance()->RoundRestarting() || Network::GetInstance()->GetMatchOver())
	{
		secString = std::to_string(Network::GetInstance()->GetRestartingTimer());
		if (Network::GetInstance()->GetRestartingTimer() < 10)
		{
			secString = "0" + secString;
		}
		m_timerText->SetText("-0:" + secString);
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
	//Render frame
	m_frame->QueueRender();

	// Render background
	m_background->QueueRender();

	// Players
	unsigned int index = 0;
	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		if (index < m_redSquares.size())
		{
			m_redSquares[index]->SetPosition(it->second->GetPosition());
			m_redSquares[index]->QueueRender();
		}
		it->second->QueueRender();
		
		if (!Network::GetInstance()->GetPlayerByGuid(it->first).isAlive)
		{
			m_deadRedPlayer[index]->SetPosition(it->second->GetPosition());
			m_deadRedPlayer[index]->QueueRender();
		}
		index++;
	}
	index = 0;
	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		if (index < m_blueSquares.size())
		{
			m_blueSquares[index]->SetPosition(it->second->GetPosition());
			m_blueSquares[index]->QueueRender();
		}
		it->second->QueueRender();

		if (!Network::GetInstance()->GetPlayerByGuid(it->first).isAlive)
		{
			m_deadBluePlayer[index]->SetPosition(it->second->GetPosition());
			m_deadBluePlayer[index]->QueueRender();
		}
		index++;
	}

	// Score
	m_redScore->Render();
	m_blueScore->Render();

	// Timer
	m_timerText->Render();
}

void TeamStatusBar::ResizeRedColorList()
{
	float index = 0.0f;
	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		m_redColorPlayers[it->first]->SetPosition(DirectX::XMFLOAT3(-(index * m_dotPosOffset + m_startOffset), m_originPos.y, m_originPos.z));
		index++;
	}
}

void TeamStatusBar::ResizeBlueColorList()
{
	float index = 0.0f;
	for (std::map<RakNet::RakNetGUID, GUIElement*>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		m_blueColorPlayers[it->first]->SetPosition(DirectX::XMFLOAT3((index * m_dotPosOffset + m_startOffset), m_originPos.y, m_originPos.z));
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
	GUIElement* square = new GUIElement();
	square->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_dotSize + 5, m_dotSize + 5, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_RED_PLAYER));
	m_redSquares.push_back(square);

	GUIElement* deadSquare = new GUIElement();
	deadSquare->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
	m_deadRedPlayer.push_back(deadSquare);
}

void TeamStatusBar::AddBlueSquare()
{
	GUIElement* square = new GUIElement();
	square->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_dotSize + 5, m_dotSize + 5, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_BLUE_PLAYER));
	m_blueSquares.push_back(square);

	GUIElement* deadSquare = new GUIElement();
	deadSquare->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_dotSize, m_dotSize, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
	m_deadBluePlayer.push_back(deadSquare);
}