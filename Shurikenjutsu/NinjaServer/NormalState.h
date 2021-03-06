#ifndef NORMALSTATE_H_
#define NORMALSTATE_H_

#include "GameState.h"

class NormalState : public GameState
{
public:
	NormalState();
	~NormalState();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer, std::vector<std::string> p_levelsName, int p_currentLevel);
	bool Initialize(int p_currentLevel);
	bool Initialize();
	void Shutdown();
	void Update(double p_deltaTime);
	void setLevels(std::vector<std::string> levels);

// public for testing with Google test
public:
	bool OneTeamRemaining(std::vector<PlayerNet> p_players);
private:	
	void ClearAllListAtRoundRestart();
	int GetRoundWinningTeam();
	int GetTotalWinningTeam();
	void RespawnAllPlayers();
	void SendWinningTeam(int p_winningTeam);
	void SetTeamWon(int p_winningTeam);
	
	void SendRestartedRound();
	void SendRestartingRound();
	void SendRestartingRoundTime(int p_time);
	void SendMatchOver(int p_winningTeam);

	void StartNewLevel();
	bool TeamScoreOverHalfPoints();

	float m_roundTimer;
	float m_currentTimer;
	int m_sendTime;
	int m_roundLimit;
	int m_currentRound;
	bool m_matchOver;
	float m_matchTimer;
};

#endif