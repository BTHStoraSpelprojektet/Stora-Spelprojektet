#ifndef SERVERGLOBALS_H_
#define SERVERGLOBALS_H_

#define MAX_CLIENTS 10
#define SERVER_PORT 60000
#define SERVER_ADDRESS "194.47.150.15"

class ServerGlobals
{
public:
	ServerGlobals();
	~ServerGlobals();

	static bool IS_SERVER;

};

#endif