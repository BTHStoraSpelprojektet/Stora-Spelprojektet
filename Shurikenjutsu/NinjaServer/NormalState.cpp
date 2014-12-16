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

	// Spelare ska inte respawna förräns ett lag har vunnit
	// Död = sluta rendera?
	// Vänta tills alla på ett lag är döda
	// Sedan respawna ALLA
}

bool NormalState::OneTeamLeft()
{
	std::vector<PlayerNet> players = m_playerManager.GetPlayers();
	std::vector<int> teamsFound = std::vector<int>();
	bool found;
	for each (PlayerNet player in players)
	{
		found = false;
		for (unsigned int i = 0; i < teamsFound.size(); i++)
		{
			if (teamsFound[i] == player.team)
			{
				found = true;
			}
		}
		if (!found)
		{
			teamsFound.push_back(player.team);
		}
	}

	return (teamsFound.size() <= 1);
}