#ifndef DEBUGSTATE_H_
#define DEBUGSTATE_H_

#include "GameState.h"


class DebugState : public GameState
{
public:
	DebugState();
	~DebugState();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);

private:
};

#endif