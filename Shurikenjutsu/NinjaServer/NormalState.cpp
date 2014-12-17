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

	if (OneTeamRemaining(m_playerManager.GetPlayers()))
	{
		int winningTeam = GetWinningTeam();
		SendWinningTeam(winningTeam);
		RespawnAllPlayers();
	}
}

bool NormalState::OneTeamRemaining(std::vector<PlayerNet> p_players)
{
	std::map<int, bool> teamsFound = std::map<int, bool>();
	

	for each (PlayerNet player in p_players)
	{
		if (teamsFound.find(player.team) != teamsFound.end())
		{
			// found
			if (!teamsFound[player.team])
			{
				teamsFound[player.team] = player.isAlive;
			}
		}
		else
		{
			// not found
			teamsFound[player.team] = player.isAlive;
		}
	}

	if (teamsFound.size() <= 1)
	{
		return false;
	}
	else
	{
		int teamsAlive = 0;
		for (std::map<int, bool>::iterator it = teamsFound.begin(); it != teamsFound.end(); it++)
		{
			if (it->second)
			{
				teamsAlive++;
			}
		}

		return teamsAlive <= 1;
	}
}

// Make sure OneTeamRemaining is true before calling this
int NormalState::GetWinningTeam()
{
	std::vector<PlayerNet> players = m_playerManager.GetPlayers();

	for each(PlayerNet player in players)
	{
		if (player.isAlive)
		{
			return player.team;
		}
	}

	return -1;
}

void NormalState::RespawnAllPlayers()
{
	std::vector<PlayerNet> players = m_playerManager.GetPlayers();
	for each (PlayerNet player in players)
	{
		m_playerManager.ResetHealth(player.guid);
		m_playerManager.RespawnPlayer(player.guid);
	}
}

void NormalState::SendWinningTeam(int p_winningTeam)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_ROUND_OVER);
	bitStream.Write(p_winningTeam);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}