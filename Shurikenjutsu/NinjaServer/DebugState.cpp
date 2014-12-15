#include "DebugState.h"


DebugState::DebugState()
{
}


DebugState::~DebugState()
{
}

bool DebugState::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	bool result;

	result = GameState::Initialize(p_serverPeer);
	if (!result)
	{
		return false;
	}

	return true;
}

void DebugState::Shutdown()
{
	GameState::Shutdown();
}

void DebugState::Update(double p_deltaTime)
{
	GameState::Update(p_deltaTime);
}