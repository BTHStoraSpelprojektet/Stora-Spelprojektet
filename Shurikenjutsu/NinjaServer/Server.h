#ifndef SERVER
#define SERVER

#include <iostream>
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "BitStream.h"
#include "RakNetTypes.h"  // MessageID

#define MAX_CLIENTS 10
#define SERVER_PORT 60000

class Server
{
public:
	Server();
	~Server();
	bool Initialize();
	void Shutdown();
	void Update();
	void ReceviePacket();
private:
	RakNet::RakPeerInterface *m_serverPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;

};

#endif SERVER