#include "ServerGlobals.h"


ServerGlobals::ServerGlobals()
{
}


ServerGlobals::~ServerGlobals()
{
}

void ServerGlobals::SetIsServer(bool p_isServer)
{
	m_isServer = p_isServer;
}

bool ServerGlobals::GetIsServer()
{
	return m_isServer;
}