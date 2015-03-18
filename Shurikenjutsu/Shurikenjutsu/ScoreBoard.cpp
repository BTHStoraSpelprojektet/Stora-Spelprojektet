#include "ScoreBoard.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"
#include <dwrite.h>

ScoreBoard* ScoreBoard::m_instance;

ScoreBoard::ScoreBoard()
{

}

ScoreBoard::~ScoreBoard()
{

}

ScoreBoard* ScoreBoard::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ScoreBoard();
	}

	return m_instance;
}

bool ScoreBoard::Initialize()
{
	m_addedMyself = false;

	// Height and width of the board texture
	m_boardHeight = 626.0f;
	m_boardWidth = 514.0f;

	// Height and width of the portrait textures
	m_portraitHeight = 50.0f;
	m_portraitWidth = 50.0f;

	// Initialize background
	m_background = GUIElement();
	m_background.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_boardWidth, m_boardHeight, TextureLibrary::GetInstance()->GetTexture(SCOREBOARD_BACKGROUND));

	// Initialize lists
	m_redColorPlayers = std::map<RakNet::RakNetGUID, Ninja>();
	m_blueColorPlayers = std::map<RakNet::RakNetGUID, Ninja>();

	// Initalize deadPlayers
	m_deadRedPlayers = std::vector<GUIElement*>();
	m_deadBluePlayers = std::vector<GUIElement*>();

	return true;
}

void ScoreBoard::Shutdown()
{
	m_redColorPlayers.clear();
	m_blueColorPlayers.clear();

	m_deadRedPlayers.clear();
	m_blueColorPlayers.clear();

	m_playerName.Shutdown();
	m_killDeathNumber.Shutdown();

	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

void ScoreBoard::Update()
{
	// Update yourself
	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	float offset = 60.0f;
	if (!m_addedMyself)
	{
		// Red team
		if (player.team == 1)
		{
			// Initialize text
			m_redColorPlayers[player.guid].name.Initialize(player.name.C_String(), 25.0f, (-m_boardWidth / 2) + m_portraitWidth + 50.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * m_redColorPlayers.size()), 0xff000000);
			m_redColorPlayers[player.guid].name.SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
			m_redColorPlayers[player.guid].name.SetText(player.name.C_String());
			m_redColorPlayers[player.guid].death = player.deaths;
			m_redColorPlayers[player.guid].kill = player.kills;
			m_redColorPlayers[player.guid].ninjaText.Initialize(std::to_string(m_redColorPlayers[player.guid].kill) + "/" + std::to_string(m_redColorPlayers[player.guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * (m_redColorPlayers.size() - 1)), 0xff000000);

			// Initalize portraits
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_redColorPlayers[player.guid].portrait = element;
			GUIElement* temp = new GUIElement();
			temp->Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
			m_deadRedPlayers.push_back(temp);
			m_addedMyself = true;
			m_myTeam = player.team;
		}
		// Blue team
		else if (player.team == 2)
		{
			// Initialize text
			m_blueColorPlayers[player.guid].name.Initialize(player.name.C_String(), 25.0f, (-m_boardWidth / 2) + m_portraitWidth + 50.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (offset * m_blueColorPlayers.size()), 0xff000000);
			m_blueColorPlayers[player.guid].name.SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
			m_blueColorPlayers[player.guid].name.SetText(player.name.C_String());
			m_blueColorPlayers[player.guid].death = player.deaths;
			m_blueColorPlayers[player.guid].kill = player.kills;
			m_blueColorPlayers[player.guid].ninjaText.Initialize(std::to_string(m_blueColorPlayers[player.guid].kill) + "/" + std::to_string(m_blueColorPlayers[player.guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (offset * (m_blueColorPlayers.size() - 1)), 0xff000000);

			// Initialize portrait
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_blueColorPlayers[player.guid].portrait = element;
			GUIElement* temp = new GUIElement();
			temp->Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
			m_deadBluePlayers.push_back(temp);
			m_addedMyself = true;
			m_myTeam = player.team;
		}
	}
	else if (m_addedMyself && player.team != m_myTeam)
	{
		// Look which team the player is in and remove him/her
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
	
	// Check if there are any new players to add to the scoreboard
	std::vector<PlayerNet> players = Network::GetInstance()->GetOtherPlayers();
	std::map<RakNet::RakNetGUID, PlayerNet> playersMap = std::map<RakNet::RakNetGUID, PlayerNet>();
	for (unsigned int i = 0; i < players.size(); i++)
	{	
		playersMap[players[i].guid] = players[i];
		// Red team
		if (players[i].team == 1)
		{
			if (m_redColorPlayers.find(players[i].guid) == m_redColorPlayers.end())
			{
				//Initialize text
				m_redColorPlayers[players[i].guid].name.Initialize(players[i].name.C_String(), 25.0f, (-m_boardWidth / 2) + m_portraitWidth + 50.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * m_redColorPlayers.size()), 0xff000000);
				m_redColorPlayers[players[i].guid].name.SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
				m_redColorPlayers[players[i].guid].name.SetText(players[i].name.C_String());
				m_redColorPlayers[players[i].guid].death = players[i].deaths;
				m_redColorPlayers[players[i].guid].kill = players[i].kills;
				m_redColorPlayers[players[i].guid].ninjaText.Initialize(std::to_string(m_redColorPlayers[players[i].guid].kill) + "/" + std::to_string(m_redColorPlayers[players[i].guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * (m_redColorPlayers.size() - 1)), 0xff000000);

				//Initialize Portrait
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * (m_redColorPlayers.size() - 1)), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_redColorPlayers[players[i].guid].portrait = element;
				GUIElement* temp = new GUIElement();
				temp->Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * (m_redColorPlayers.size() - 1)), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
				m_deadRedPlayers.push_back(temp);
			}
			if (m_blueColorPlayers.find(players[i].guid) != m_blueColorPlayers.end())
			{
				m_blueColorPlayers.erase(players[i].guid);
				ResizeBlueColorList();
			}
		}
		// Blue team
		else if (players[i].team == 2)
		{
			if (m_blueColorPlayers.find(players[i].guid) == m_blueColorPlayers.end())
			{
				//Initialize text
				m_blueColorPlayers[players[i].guid].name.Initialize(players[i].name.C_String(), 25.0f, (-m_boardWidth / 2) + m_portraitWidth + 50.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (offset * m_blueColorPlayers.size()), 0xff000000);
				m_blueColorPlayers[players[i].guid].name.SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
				m_blueColorPlayers[players[i].guid].name.SetText(players[i].name.C_String());
				m_blueColorPlayers[players[i].guid].death = players[i].deaths;
				m_blueColorPlayers[players[i].guid].kill = players[i].kills;
				m_blueColorPlayers[players[i].guid].ninjaText.Initialize(std::to_string(m_blueColorPlayers[players[i].guid].kill) + "/" + std::to_string(m_blueColorPlayers[players[i].guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (offset * (m_blueColorPlayers.size() - 1)), 0xff000000);

				//Initialize portrait
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (offset * (m_blueColorPlayers.size() - 1)), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_blueColorPlayers[players[i].guid].portrait = element;
				GUIElement* temp = new GUIElement();
				temp->Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (offset * (m_blueColorPlayers.size() - 1)), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(TEAM_STATUS_DEAD_PLAYER));
				m_deadBluePlayers.push_back(temp);
			}
			if (m_redColorPlayers.find(players[i].guid) != m_redColorPlayers.end())
			{
				m_redColorPlayers.erase(players[i].guid);
				ResizeRedColorList();
			}
		}
	}

	// Check for disconnected players in red team
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a disconnected player
			it = m_redColorPlayers.erase(it);
			ResizeRedColorList();

			delete m_deadRedPlayers[m_deadRedPlayers.size() - 1];
			m_deadRedPlayers.pop_back();
		}
		else
		{
			++it;
		}
	}

	// Check for disconnected players in blue team
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end();)
	{
		if (it->first != player.guid && playersMap.find(it->first) == playersMap.end())
		{
			// Found a disconnected player
			it = m_blueColorPlayers.erase(it);
			ResizeBlueColorList();
			
			delete m_deadBluePlayers[m_deadBluePlayers.size() - 1];
			m_deadBluePlayers.pop_back();
		}
		else
		{
			++it;
		}
	}

}

void ScoreBoard::ResizeBlueColorList()
{
	float index = 0.0f;
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		m_blueColorPlayers[it->first].portrait.SetPosition(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (60.0f * index), 0.0f));
		m_deadBluePlayers[(unsigned int)index]->SetPosition(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (60.0f * index), 0.0f));
		m_blueColorPlayers[it->first].name.SetPosition(-m_boardWidth / 2 + m_portraitWidth + 50.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (60.0f * index));
		m_blueColorPlayers[it->first].ninjaText.SetPosition(-m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (60.0f * index));
		index++;
	}
}

void ScoreBoard::ResizeRedColorList()
{
	float index = 0.0f;
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		m_redColorPlayers[it->first].portrait.SetPosition(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (60.0f * (index)), 0.0f));
		m_deadRedPlayers[(unsigned int)index]->SetPosition(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (60.0f * index), 0.0f));
		m_redColorPlayers[it->first].name.SetPosition(-m_boardWidth / 2 + m_portraitWidth + 50.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (60.0f * index));
		m_redColorPlayers[it->first].ninjaText.SetPosition(-m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (60.0f * index));
		index++;
	}
}

void ScoreBoard::Render()
{
	// Render background
	m_background.QueueRender();

	unsigned int index = 0;
	// Render red team
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		it->second.portrait.QueueRender();
		it->second.ninjaText.Render();
		it->second.name.Render();
		//if (!Network::GetInstance()->GetPlayerByGuid(it->first).isAlive)
		//{
		m_deadRedPlayers[index]->SetPosition(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (60.0f * (index)), 0.0f));
			m_deadRedPlayers[index]->QueueRender();
		//}
		index++;
	}

	// Render blue team
	index = 0;
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		it->second.portrait.QueueRender();
		it->second.ninjaText.Render();
		it->second.name.Render();
		//if (!Network::GetInstance()->GetPlayerByGuid(it->first).isAlive)
		//{
		m_deadRedPlayers[index]->SetPosition(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 367.0f - (60.0f * (index)), 0.0f));
			m_deadBluePlayers[index]->QueueRender();
		//}
		index++;
	}
}

std::string ScoreBoard::GetTextureName(int p_charNr)
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

void ScoreBoard::KillDeathRatio(RakNet::RakNetGUID p_ninjaKiller, RakNet::RakNetGUID p_ninjaKilled, int p_deaths, int p_kills)
{
	std::vector<PlayerNet> players = Network::GetInstance()->GetOtherPlayers();
	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	players.push_back(player);

	if (p_ninjaKiller == p_ninjaKilled)
	{
		for (unsigned int i = 0; i < players.size(); i++)
		{
			// Red team
			if (players[i].team == 1)
			{
				if (players[i].guid == p_ninjaKilled)
				{
					m_redColorPlayers[p_ninjaKilled].death = p_deaths;
					m_redColorPlayers[p_ninjaKilled].ninjaText.SetText(std::to_string(m_redColorPlayers[p_ninjaKilled].kill) + "/" + std::to_string(m_redColorPlayers[p_ninjaKilled].death));
					break;
				}
			}
			// Blue team
			else if (players[i].team == 2)
			{
				if (players[i].guid == p_ninjaKilled)
				{
					m_blueColorPlayers[p_ninjaKilled].death = p_deaths;
					m_blueColorPlayers[p_ninjaKilled].ninjaText.SetText(std::to_string(m_blueColorPlayers[p_ninjaKilled].kill) + "/" + std::to_string(m_blueColorPlayers[p_ninjaKilled].death));
					break;
				}
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < players.size(); i++)
		{
			// Red team
			if (players[i].team == 1)
			{
				if (players[i].guid == p_ninjaKiller)
				{
					m_redColorPlayers[p_ninjaKiller].kill = p_kills;
					m_blueColorPlayers[p_ninjaKilled].death = p_deaths;
					m_redColorPlayers[p_ninjaKiller].ninjaText.SetText(std::to_string(m_redColorPlayers[p_ninjaKiller].kill) + "/" + std::to_string(m_redColorPlayers[p_ninjaKiller].death));
					m_blueColorPlayers[p_ninjaKilled].ninjaText.SetText(std::to_string(m_blueColorPlayers[p_ninjaKilled].kill) + "/" + std::to_string(m_blueColorPlayers[p_ninjaKilled].death));
					break;
				}
			}
			// Blue team
			else if (players[i].team == 2)
			{
				if (players[i].guid == p_ninjaKiller)
				{
					m_blueColorPlayers[p_ninjaKiller].kill = p_kills;
					m_redColorPlayers[p_ninjaKilled].death = p_deaths;
					m_redColorPlayers[p_ninjaKilled].ninjaText.SetText(std::to_string(m_redColorPlayers[p_ninjaKilled].kill) + "/" + std::to_string(m_redColorPlayers[p_ninjaKilled].death));
					m_blueColorPlayers[p_ninjaKiller].ninjaText.SetText(std::to_string(m_blueColorPlayers[p_ninjaKiller].kill) + "/" + std::to_string(m_blueColorPlayers[p_ninjaKiller].death));
					break;
				}
			}
		}
	}
}

void ScoreBoard::AddKD(RakNet::RakNetGUID p_ninja, int p_deaths, int p_kills)
{
	std::vector<PlayerNet> players = Network::GetInstance()->GetOtherPlayers();
	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	players.push_back(player);

	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (players[i].guid == p_ninja)
		{
			players[i].kills = p_kills;
			players[i].deaths = p_deaths;
		}
	}
}