#ifndef SERVERGLOBALS_H_
#define SERVERGLOBALS_H_
class ServerGlobals
{
public:
	ServerGlobals();
	~ServerGlobals();

	static void SetIsServer(bool p_isServer);
	static bool GetIsServer();

private:
	static bool m_isServer;

};

#endif