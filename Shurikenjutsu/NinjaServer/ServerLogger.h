#ifndef SERVERLOGGER_H_
#define SERVERLOGGER_H_

#include "..\CommonLibs\RakNet\PacketLogger.h"
#include "..\CommonLibs\RakNet\InternalPacket.h"
#include <string>
#include <iostream>

class ServerLogger : public RakNet::PacketLogger
{
public:
	ServerLogger();
	~ServerLogger();

	void Initialize();

	void OnDirectSocketSend(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress);
	void OnDirectSocketReceive(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress);
	void OnReliabilityLayerNotification(const char *errorMessage, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress, bool isError);
	void OnInternalPacket(RakNet::InternalPacket *internalPacket, unsigned frameNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time, int isSend);
	void OnAck(unsigned int messageNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time);
	void OnPushBackPacket(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress);

	void Update(double p_deltaTime);

private:
	RakNet::BitSize_t m_frameBitsIn, m_frameBitsOut;
	double m_time;
};

#endif