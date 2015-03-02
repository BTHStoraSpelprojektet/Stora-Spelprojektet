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

	struct Ninja
	{
		GUIElement portrait;
		int kill;
		int death;
		GUIText ninjaText;
	};

	static ScoreBoard* GetInstance();

	bool Initialize();
	void Shutdown();
	void Update();
	void Render();
	GUIText textst;
	void KillDeathRatio(RakNet::RakNetGUID p_ninjaKiller, RakNet::RakNetGUID p_ninjaKilled);

private:
	static ScoreBoard* m_instance;

	GUIElement m_background;
	GUIElement m_portrait;

	float m_boardHeight;
	float m_boardWidth;

	float m_portraitHeight;
	float m_portraitWidth;

	GUIText m_playerName;
	GUIText m_killDeathNumber;

	bool m_addedMyself;

	void ResizeRedColorList();
	void ResizeBlueColorList();

	int killerNinja;
	int takerNinja;

	//std::map<RakNet::RakNetGUID, GUIElement> m_redColorPlayers;
	//std::map<RakNet::RakNetGUID, GUIElement> m_blueColorPlayers;
	std::map<RakNet::RakNetGUID, Ninja> m_redColorPlayers;
	std::map<RakNet::RakNetGUID, Ninja> m_blueColorPlayers;

	std::vector<GUIText> m_text;

	std::string GetTextureName(int p_charNr);
};

#endif