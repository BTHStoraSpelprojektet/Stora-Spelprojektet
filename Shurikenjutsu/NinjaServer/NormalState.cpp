#include "NormalState.h"


NormalState::NormalState()
{
}


NormalState::~NormalState()
{
}

bool NormalState::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	bool result;

	result = GameState::Initialize(p_serverPeer);
	if (!result)
	{
		return false;
	}

	return true;
}

void NormalState::Shutdown()
{
	GameState::Shutdown();
}

void NormalState::Update(double p_deltaTime)
{
	GameState::Update(p_deltaTime);
}