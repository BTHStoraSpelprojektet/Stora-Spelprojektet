#ifndef SERVERMESSAGES_H_
#define SERVERMESSAGES_H_

#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"

struct PlayerNet
{
	float x, y, z;
	RakNet::RakNetGUID guid;
};

struct ShurikenNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	unsigned int shurikenId;
	RakNet::RakNetGUID guid;
	float lifeTime;
};

enum Messages
{
	ID_NR_CONNECTIONS = ID_USER_PACKET_ENUM + 1,
	ID_DOWNLOAD_PLAYERS,
	ID_PLAYER_MOVED,
	ID_SHURIKEN_THROWN,
	ID_SHURIKEN_REMOVE
};

#endif