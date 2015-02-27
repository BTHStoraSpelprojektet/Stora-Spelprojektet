#include "ScoreBoard.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"

ScoreBoard::ScoreBoard()
{

}

ScoreBoard::~ScoreBoard()
{

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
	m_redColorPlayers = std::map<RakNet::RakNetGUID, GUIElement>();
	m_blueColorPlayers = std::map<RakNet::RakNetGUID, GUIElement>();
	m_text = std::vector<GUIText>();

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
			GUIText kdr = GUIText();
			kdr.Initialize("3/5", 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * m_redColorPlayers.size()), 0xff000000);
			m_text.push_back(kdr);

			// Initalize portraits
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_redColorPlayers[player.guid] = element;
			m_addedMyself = true;
		}
		// Blue team
		else if (player.team == 2)
		{
			// Initialize text
			GUIText name = GUIText();
			name.Initialize("Player " + std::to_string(m_blueColorPlayers.size() + m_redColorPlayers.size() + 1) , 25.0f, -m_boardWidth / 2 + m_portraitWidth + 100.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * m_blueColorPlayers.size()), 0xff000000);
			m_text.push_back(name);
			GUIText kdr = GUIText();
			kdr.Initialize("3/5", 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * m_blueColorPlayers.size()), 0xff000000);
			m_text.push_back(kdr);

			// Initialize portrait
			GUIElement element = GUIElement();
			element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f/*skitlångtneråthelvete.y*/, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
			m_blueColorPlayers[player.guid] = element;
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
				GUIText kdr = GUIText();
				kdr.Initialize("3/5", 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * m_redColorPlayers.size()), 0xff000000);
				m_text.push_back(kdr);

				//Initialize Portrait
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f - (offset * m_redColorPlayers.size()), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_redColorPlayers[players[i].guid] = element;
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
				GUIText kdr = GUIText();
				kdr.Initialize("3/5", 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * m_blueColorPlayers.size()), 0xff000000);
				m_text.push_back(kdr);

				//Initialize portrait
				GUIElement element = GUIElement();
				element.Initialize(DirectX::XMFLOAT3(-m_boardWidth / 2 + m_portraitWidth / 2 + 25.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 377.0f - (offset * m_blueColorPlayers.size()), 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(players[i].charNr)));
				m_blueColorPlayers[players[i].guid] = element;
			}
		}
	}
}

void ScoreBoard::Render()
{
	// Render background
	m_background.QueueRender();

	// Render red team portraits
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_redColorPlayers.begin(); it != m_redColorPlayers.end(); it++)
	{
		it->second.QueueRender();
	}

	// Render blue team portraits
	for (std::map<RakNet::RakNetGUID, GUIElement>::iterator it = m_blueColorPlayers.begin(); it != m_blueColorPlayers.end(); it++)
	{
		it->second.QueueRender();
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