#ifndef NETWORKLOGGER_H_
#define NETWORKLOGGER_H_

#include "..\CommonLibs\RakNet\PacketLogger.h"
#include "..\CommonLibs\RakNet\InternalPacket.h"
#include <string>
#include <iostream>

class NetworkLogger : public RakNet::PacketLogger
{
public:
	NetworkLogger();
	~NetworkLogger();

	void Initialize();

	void OnDirectSocketSend(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress);
	void OnDirectSocketReceive(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress);
	void OnReliabilityLayerNotification(const char *errorMessage, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress, bool isError);
	void OnInternalPacket(RakNet::InternalPacket *internalPacket, unsigned frameNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time, int isSend);
	void OnAck(unsigned int messageNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time);
	void OnPushBackPacket(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress);

	void Update(double p_deltaTime);
protected:
	//const char* UserIDTOString(unsigned char Id);
private:
	RakNet::BitSize_t m_frameBitsIn, m_frameBitsOut;
	double m_time;
};

#endif