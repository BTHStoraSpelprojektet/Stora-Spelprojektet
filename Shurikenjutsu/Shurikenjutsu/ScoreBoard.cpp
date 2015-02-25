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
	// Height and width of the board texture
	m_boardHeight = 626.0f;
	m_boardWidth = 514.0f;

	// Height and width of the portrait textures
	m_portraitHeight = 50.0f;
	m_portraitWidth = 50.0f;

	// Initialize background
	m_background = GUIElement();
	m_background.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_boardWidth, m_boardHeight, TextureLibrary::GetInstance()->GetTexture(SCOREBOARD_BACKGROUND));
	
	// Test! Initialize portraits(will probably be done otherwhere)
	// Positions - half the board to the left and then the portrait texture width + the border to the right
	PlayerNet player = Network::GetInstance()->GetMyPlayer();
	m_portrait = GUIElement();
	m_portrait.Initialize(DirectX::XMFLOAT3(-m_boardWidth/2 + m_portraitWidth/2 + 25.0f, m_boardHeight/2 - m_portraitHeight/2 - 97.0f, 0.0f), 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetTextureName(player.charNr)));
	
	// Text
	// Position gonna be fixed not to be hard coded
	m_playerName = GUIText();
	m_killNumber = GUIText();
	m_deathNumber = GUIText();
	m_playerName.Initialize("Player 1", 25.0f, -m_boardWidth / 2 + m_portraitWidth + 100.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f, 0xff000000);
	m_killNumber.Initialize("3/"/*fix slash later*/, 25.0f, -m_boardWidth / 2 + m_portraitWidth + 300.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f, 0xff000000);
	m_deathNumber.Initialize("5", 25.0f, -m_boardWidth / 2 + m_portraitWidth + 320.0f, m_boardHeight / 2 - m_portraitHeight / 2 - 97.0f, 0xff000000);

	return true;
}

void ScoreBoard::Shutdown()
{
	// Hoohhohoohohohohohohoohohohohoh
}

void ScoreBoard::Update()
{

}

void ScoreBoard::Render()
{
	m_background.QueueRender();
	m_portrait.QueueRender();
	m_playerName.Render();
	m_deathNumber.Render();
	m_killNumber.Render();
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