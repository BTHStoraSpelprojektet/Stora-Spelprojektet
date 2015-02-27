#include "NormalState.h"

#include "SpikeManager.h"
#include "ProjectileManager.h"
#include "StickyTrapManager.h"
#include "VolleyManager.h"
#include "FanBoomerangManager.h"
#include "../Shurikenjutsu/ConsoleFunctions.h"

NormalState::NormalState(){}
NormalState::~NormalState(){}

bool NormalState::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	bool result;

	result = GameState::Initialize(p_serverPeer);
	if (!result)
	{
		return false;
	}

	result = Initialize();
	if (!result)
	{
		return false;
	}

	return true;
}

bool NormalState::Initialize(std::string p_levelName)
{
	bool result;

	result = GameState::Initialize(p_levelName);
	if (!result)
	{
		return false;
	}

	result = Initialize();
	if (!result)
	{
		return false;
	}
	
	return true;
}

bool NormalState::Initialize()
{
	m_roundLimit = 5;
	m_currentRound = 1;
	m_roundTimer = 10.0f;
	m_matchTimer = 20.0f;
	m_currentTimer = 10.0f;
	m_sendTime = (int)m_currentTimer;
	m_roundRestarting = false;
	m_matchOver = false;

	return true;
}

void NormalState::Shutdown()
{
	GameState::Shutdown();
}

void NormalState::Update(double p_deltaTime)
{
	GameState::Update(p_deltaTime);

	// Is the round restarting
	if (m_roundRestarting)
	{
		m_currentTimer -= (float)p_deltaTime;
		if ((int)m_currentTimer < m_sendTime)
		{
			m_sendTime = (int)m_currentTimer;
			SendRestartingRoundTime(m_sendTime + 1);
		}

		if (m_currentTimer <= 0.0f)
		{
			m_roundRestarting = false;
			SendRestartedRound();
			RespawnAllPlayers();
			ResetTime();
			ClearAllListAtRoundRestart();
		}
	}
	// Check if all rounds have been played and the match is over
	else if (m_matchOver)
	{
		m_currentTimer -= (float)p_deltaTime;
		if ((int)m_currentTimer < m_sendTime)
		{
			m_sendTime = (int)m_currentTimer;
			SendRestartingRoundTime(m_sendTime + 1);
		}

		if (m_currentTimer <= 0.0f)
		{
			StartNewLevel();
		}
	}
	// Check if there is only one team remaining
	else if (OneTeamRemaining(m_playerManager->GetPlayers()))
	{
		// Check which team won this round
		int winningTeam = GetRoundWinningTeam();
		SetTeamWon(winningTeam);
		SendWinningTeam(winningTeam);
		m_currentRound++;

		// See if the round limit has been reached else restart a new round
		if (m_currentRound > m_roundLimit)
		{
			SendMatchOver(GetTotalWinningTeam());
			m_currentTimer = m_matchTimer;
			m_sendTime = (int)m_matchTimer;
			m_matchOver = true;
		}
		else
		{
			m_currentTimer = m_roundTimer;
			m_sendTime = (int)m_roundTimer;
			m_roundRestarting = true;
			SendRestartingRound();
		}
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
int NormalState::GetRoundWinningTeam()
{
	std::vector<PlayerNet> players = m_playerManager->GetPlayers();

	for each(PlayerNet player in players)
	{
		if (player.isAlive)
		{
			return player.team;
		}
	}

	return -1;
}

int NormalState::GetTotalWinningTeam()
{
	int team = -1;
	int score = 0;

	for (std::map<int, int>::iterator it = m_winningTeams.begin(); it != m_winningTeams.end(); it++)
	{
		if (it->second > score || team == -1)
		{
			team = it->first;
			score = it->second;
		}
	}
	return team;
}

void NormalState::SetTeamWon(int p_winningTeam)
{
	if (m_winningTeams.find(p_winningTeam) != m_winningTeams.end())
	{
		// found
		m_winningTeams[p_winningTeam]++;
	}
	else
	{
		// not found
		m_winningTeams[p_winningTeam] = 1;
	}

}

void NormalState::RespawnAllPlayers()
{
	std::vector<PlayerNet> players = m_playerManager->GetPlayers();
	for each (PlayerNet player in players)
	{
		m_playerManager->ResetHealth(player.guid);
		m_playerManager->RespawnPlayer(player.guid);
	}
}

void NormalState::SendWinningTeam(int p_winningTeam)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_ROUND_OVER);
	bitStream.Write(p_winningTeam);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);

	if (p_winningTeam == 1)
	{
		ConsolePrintText("The red team won this match!");
		ConsoleSkipLines(1);
	}

	else
	{
		ConsolePrintText("The blue team won this match!");
		ConsoleSkipLines(1);
	}
}

void NormalState::SendRestartedRound()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_RESTARTED_ROUND);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void NormalState::SendRestartingRound()
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_RESTARTING_ROUND);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);

	ConsolePrintText("Next round starts in: ");
	ConsoleSkipLines(1);
}

void NormalState::SendRestartingRoundTime(int p_time)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_RESTARTING_ROUND_TIMER);
	bitStream.Write(p_time);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_SEQUENCED, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);

	ConsolePrintText(p_time + "...");
	ConsoleSkipLines(1);
}

void NormalState::StartNewLevel()
{
	Shutdown();
	Initialize(LEVEL_NAME);

	ConsolePrintSuccess("New level initialized!");
	ConsoleSkipLines(1);

	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_NEW_LEVEL);
	bitStream.Write(LEVEL_NAME);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void NormalState::SendMatchOver(int p_winningTeam)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_MATCH_OVER);
	bitStream.Write(p_winningTeam);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 4, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void NormalState::ClearAllListAtRoundRestart()
{
	m_shurikenManager->ResetLists();
	m_smokeBombManager->ResetLists();
	m_spikeManager->ResetLists();
	m_fanBoomerangManager->ResetLists();
	m_projectileManager->ResetLists();
	m_stickyTrapManager->ResetLists();
	m_volleyManager->ResetLists();
}