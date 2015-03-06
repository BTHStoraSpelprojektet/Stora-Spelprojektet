#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#define WIN32_LEAN_AND_MEAN

#include "GraphicsEngine.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "GUIElement.h"
#include "Network.h"
#include "GUIText.h"

class ScoreBoard
{
public:
	ScoreBoard(const ScoreBoard&) = delete;
	ScoreBoard& operator=(const ScoreBoard&) = delete;

	struct Ninja
	{
		GUIElement portrait;
		int kill;
		int death;
		GUIText ninjaText;
		GUIText name;
	};

	static ScoreBoard* GetInstance();

	bool Initialize();
	void Shutdown();
	void Update();
	void Render();
	GUIText textst;
	void KillDeathRatio(RakNet::RakNetGUID p_ninjaKiller, RakNet::RakNetGUID p_ninjaKilled, int p_deaths, int p_kills);
	void AddKD(RakNet::RakNetGUID p_ninja, int p_deaths, int p_kills);

private:
	ScoreBoard();
	~ScoreBoard();

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

	int m_myTeam;

	std::map<RakNet::RakNetGUID, Ninja> m_redColorPlayers;
	std::map<RakNet::RakNetGUID, Ninja> m_blueColorPlayers;

	std::string GetTextureName(int p_charNr);
};

#endif