#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#define WIN32_LEAN_AND_MEAN

#include "GraphicsEngine.h"
#include "TextureLibrary.h"
#include "GUIElement.h"
#include "Network.h"
#include "GUIText.h"

class ScoreBoard
{
public:
	ScoreBoard();
	~ScoreBoard();

	bool Initialize();
	void Shutdown();
	void Update();
	void Render();

private:
	GUIElement m_background;
	GUIElement m_portrait;

	float m_boardHeight;
	float m_boardWidth;

	float m_portraitHeight;
	float m_portraitWidth;

	GUIText m_playerName;
	GUIText m_killNumber;
	GUIText m_deathNumber;

	std::string GetTextureName(int p_charNr);
};

#endif