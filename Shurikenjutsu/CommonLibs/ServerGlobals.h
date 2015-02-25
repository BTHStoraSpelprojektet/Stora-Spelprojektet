#ifndef SERVERGLOBALS_H_
#define SERVERGLOBALS_H_

#define MAX_CLIENTS 8
#define SERVER_PORT 60000
#define SERVER_ADDRESS "194.47.150.130"
//#define SERVER_ADDRESS "194.47.150.36" // Alexander's IP
//#define SERVER_ADDRESS "127.0.0.1"


class ServerGlobals
{
public:
	ServerGlobals();
	~ServerGlobals();

	static bool IS_SERVER;

	static int BYTES_IN;
	static int BYTES_OUT;

};

#endif