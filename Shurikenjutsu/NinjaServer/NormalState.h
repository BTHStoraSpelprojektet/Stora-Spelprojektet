#ifndef NORMALSTATE_H_
#define NORMALSTATE_H_

#include "GameState.h"
#include <map>

class NormalState : public GameState
{
public:
	NormalState();
	~NormalState();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);

private:
	bool OneTeamRemaining(std::vector<PlayerNet> p_players);
	int GetWinningTeam();
	void RespawnAllPlayers();
	void SendWinningTeam(int p_winningTeam);
};

#endif