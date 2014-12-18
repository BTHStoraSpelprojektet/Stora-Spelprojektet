#include "Debug.h"


Debug::Debug()
{
}


Debug::~Debug()
{
}

void Debug::RunTests(int p_argc, _TCHAR* p_argv[])
{
	::testing::InitGoogleTest(&p_argc, p_argv);

	RUN_ALL_TESTS();

	std::cout << std::endl;
}

TEST(JohanTest1, one_team_remaining)
{
	std::vector<PlayerNet> players;
	PlayerNet player;
	NormalState normalState;

	// One player
	players = std::vector<PlayerNet>();
	player.team = 1;
	player.isAlive = true;
	players.push_back(player);
	EXPECT_EQ(false, normalState.OneTeamRemaining(players));

	// Two players (1 dead, 1 alive)
	players = std::vector<PlayerNet>();
	player.team = 1;
	player.isAlive = true;
	players.push_back(player);
	player.team = 2;
	player.isAlive = false;
	players.push_back(player);
	EXPECT_EQ(true, normalState.OneTeamRemaining(players));

	// Two players (Both alive)
	players = std::vector<PlayerNet>();
	player.team = 1;
	player.isAlive = true;
	players.push_back(player);
	player.team = 2;
	player.isAlive = true;
	players.push_back(player);
	EXPECT_EQ(false, normalState.OneTeamRemaining(players));

	// Three players (Team 1 = 1 alive and 1 dead, Team 2 = 1 alive)
	players = std::vector<PlayerNet>();
	player.team = 1;
	player.isAlive = true;
	players.push_back(player);
	player.team = 1;
	player.isAlive = false;
	players.push_back(player);
	player.team = 2;
	player.isAlive = true;
	players.push_back(player);
	EXPECT_EQ(false, normalState.OneTeamRemaining(players));
}