#include "ScoreBoard.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"

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
	m_redColorPlayers = std::map<RakNet::RakNetGUID, Ninja>();//std::map<RakNet::RakNetGUID, GUIElement>();
	m_blueColorPlayers = std::map<RakNet::RakNetGUID, Ninja>();;//std::map<RakNet::RakNetGUID, GUIElement>();
	//m_text = std::vector<GUIText>();

	textst = GUIText();
	textst.Initialize("HURRR", 25.0f, 0.0f, 0.0f, 0xff000000);
	return true;
}

void ScoreBoard::Shutdown()
{
	// Hoohhohoohohohohohohoohohohohoh
	m_redColorPlayers.clear();
	m_blueColorPlayers.clear();
	m_text.clear();

	m_playerName.Shutdown();
	m_killDeathNumber.Shutdown();
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
			GUIText name = GUIText();
			name.Initialize("Player " + std::to_string(m_blueColorPlayers.size() + m_redColorPlayers.size() + 1), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 100.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * m_redColorPlayers.size()), 0xff000000);
			m_text.push_back(name);
			m_redColorPlayers[player.guid].death = 0;
			m_redColorPlayers[player.guid].kill = 0;
			m_redColorPlayers[player.guid].ninjaText.Initialize(std::to_string(m_redColorPlayers[player.guid].kill) + "/" + std::to_string(m_redColorPlayers[player.guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * (m_redColorPlayers.size() - 1)), 0xff000000);
			//textst.SetText(std::to_string(m_redColorPlayers[player.guid].kill) + "/" + std::to_string(m_redColorPlayers[player.guid].death));
			//textst.SetPosition(-m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (60.0f * (m_redColorPlayers.size())));
			//m_text.push_back(textst);

			// Initalize portraits
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_redColorPlayers[player.guid].portrait = element;
			m_addedMyself = true;
		}
		// Blue team
		else if (player.team == 2)
		{
			// Initialize text
			GUIText name = GUIText();
			name.Initialize("Player " + std::to_string(m_blueColorPlayers.size() + m_blueColorPlayers.size() + 1) , 25.0f, -m_boardWidth / 2 + m_portraitWidth + 100.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * m_blueColorPlayers.size()), 0xff000000);
			m_text.push_back(name);
			m_blueColorPlayers[player.guid].death = 0;
			m_blueColorPlayers[player.guid].kill = 0;
			m_blueColorPlayers[player.guid].ninjaText.Initialize(std::to_string(m_blueColorPlayers[player.guid].kill) + "/" + std::to_string(m_blueColorPlayers[player.guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * (m_blueColorPlayers.size() - 1)), 0xff000000);

			// Initialize portrait
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f/*skitlångtneråthelvete.y*/, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_blueColorPlayers[player.guid].portrait = element;
			m_addedMyself = true;
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
				GUIText name = GUIText();
				name.Initialize("Player " + std::to_string(m_blueColorPlayers.size() + m_redColorPlayers.size() + 1), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 100.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * m_redColorPlayers.size()), 0xff000000);
				m_text.push_back(name);
				m_redColorPlayers[players[i].guid].death = 0;
				m_redColorPlayers[players[i].guid].kill = 0;
				m_redColorPlayers[players[i].guid].ninjaText.Initialize(std::to_string(m_redColorPlayers[players[i].guid].kill) + "/" + std::to_string(m_redColorPlayers[players[i].guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * (m_redColorPlayers.size() - 1)), 0xff000000);

				//Initialize Portrait
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * (m_redColorPlayers.size() - 1)), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_redColorPlayers[players[i].guid].portrait = element;
			}
		}
		// Blue team
		else if (players[i].team == 2)
		{
			if (m_blueColorPlayers.find(players[i].guid) == m_blueColorPlayers.end())
			{
				//Initialize text
				GUIText name = GUIText();
				name.Initialize("Player " + std::to_string(m_blueColorPlayers.size() + m_redColorPlayers.size() + 1), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 100.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * m_blueColorPlayers.size()), 0xff000000);
				m_text.push_back(name);
				m_blueColorPlayers[players[i].guid].death = 0;
				m_blueColorPlayers[players[i].guid].kill = 0;
				m_blueColorPlayers[players[i].guid].ninjaText.Initialize(std::to_string(m_blueColorPlayers[players[i].guid].kill) + "/" + std::to_string(m_blueColorPlayers[players[i].guid].death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * (m_blueColorPlayers.size() - 1)), 0xff000000);

				//Initialize portrait
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * (m_blueColorPlayers.size() - 1)), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_blueColorPlayers[players[i].guid].portrait = element;
			}
		}
	}
}

void ScoreBoard::Render()
{
	// Render background
	m_background.QueueRender();

	// Render red team portraits
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		it->second.portrait.QueueRender();
		it->second.ninjaText.Render();
		//textst.Initialize(std::to_string(it->second.kill) + "/" + std::to_string(it->second.death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (60.0f * (m_redColorPlayers.size() - 1)), 0xff000000);
		//textst.Render();
	}

	// Render blue team portraits
	for (std::map<RakNet::RakNetGUID, Ninja>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		it->second.portrait.QueueRender();
		it->second.ninjaText.Render();
		//textst.Initialize(std::to_string(it->second.kill) + "/" + std::to_string(it->second.death), 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (60.0f * (m_blueColorPlayers.size()- 1)), 0xff000000);
		//textst.SetText(std::to_string(it->second.kill) + "/" + std::to_string(it->second.death));
		//textst.SetPosition(-m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (60.0f * (m_blueColorPlayers.size() - 1)));
		//textst.Render();
	}

	// Render text
	for (unsigned int i = 0; i < m_text.size(); i++)
	{
		m_text[i].Render();
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

void ScoreBoard::KillDeathRatio(RakNet::RakNetGUID p_ninjaKiller, RakNet::RakNetGUID p_ninjaKilled)
{
	std::vector<PlayerNet> players = Network::GetInstance()->GetOtherPlayers();
	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	players.push_back(player);


	for (unsigned int i = 0; i < players.size(); i++)
	{
		// Red team
		if (players[i].team == 1)
		{
			m_redColorPlayers[p_ninjaKiller].kill += 1;
			m_blueColorPlayers[p_ninjaKilled].death += 1;
			m_redColorPlayers[p_ninjaKiller].ninjaText.SetText(std::to_string(m_redColorPlayers[p_ninjaKiller].kill) + "/" + std::to_string(m_redColorPlayers[p_ninjaKiller].death));
			m_blueColorPlayers[p_ninjaKilled].ninjaText.SetText(std::to_string(m_blueColorPlayers[p_ninjaKilled].kill) + "/" + std::to_string(m_blueColorPlayers[p_ninjaKilled].death));
		}
		// Blue team
		else if (players[i].team == 2)
		{
			m_blueColorPlayers[p_ninjaKiller].kill += 1;
			m_redColorPlayers[p_ninjaKilled].death += 1;
			m_redColorPlayers[p_ninjaKilled].ninjaText.SetText(std::to_string(m_redColorPlayers[p_ninjaKilled].kill) + "/" + std::to_string(m_redColorPlayers[p_ninjaKilled].death));
			m_blueColorPlayers[p_ninjaKiller].ninjaText.SetText(std::to_string(m_blueColorPlayers[p_ninjaKiller].kill) + "/" + std::to_string(m_blueColorPlayers[p_ninjaKiller].death));
		}
	}
}