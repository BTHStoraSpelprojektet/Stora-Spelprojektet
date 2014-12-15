#ifndef SERVERGLOBALS_H_
#define SERVERGLOBALS_H_

#define MAX_CLIENTS 10
#define SERVER_PORT 60000
//#define SERVER_ADDRESS "194.47.150.130"
#define SERVER_ADDRESS "127.0.0.1"

// modle names
#define LEVEL_NAME "../Shurikenjutsu/Levels/testBana.SSPL"
#define SHURIKEN_MODEL_NAME "../Shurikenjutsu/Levels/testBana.SSPL"
#define PLAYER_MODEL_NAME "../Shurikenjutsu/Levels/testBana.SSPL"

class ServerGlobals
{
public:
	ServerGlobals();
	~ServerGlobals();

	static bool IS_SERVER;

};

#endif