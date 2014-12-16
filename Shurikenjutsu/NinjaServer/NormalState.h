#ifndef NORMALSTATE_H_
#define NORMALSTATE_H_

#include "GameState.h"

class NormalState : public GameState
{
public:
	NormalState();
	~NormalState();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);

private:
	bool OneTeamLeft();
};

#endif