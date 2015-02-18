#include "ServerLogger.h"


ServerLogger::ServerLogger() : PacketLogger() {}
ServerLogger::~ServerLogger(){}

void ServerLogger::Initialize()
{
	m_frameBitsIn = 0;
	m_frameBitsOut = 0;
	m_time = 0;
}

void ServerLogger::Update(double p_deltaTime)
{
	m_time += p_deltaTime;
	if (m_time > 5)
	{
		double bytePerSecIn = (m_frameBitsIn / 8) / m_time;
		double bytePerSecOut = (m_frameBitsOut / 8) / m_time;
		std::cout << "In: " << (int)bytePerSecIn << "  Out: " << (int)bytePerSecOut << std::endl;
		m_time = 0;
		m_frameBitsIn = 0;
		m_frameBitsOut = 0;
	}	
}

void ServerLogger::OnDirectSocketSend(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress)
{
}

void ServerLogger::OnDirectSocketReceive(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress)
{
}

void ServerLogger::OnReliabilityLayerNotification(const char *errorMessage, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress, bool isError)
{
}

void ServerLogger::OnInternalPacket(RakNet::InternalPacket *internalPacket, unsigned frameNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time, int isSend)
{
	if (isSend)
	{
		m_frameBitsOut += internalPacket->dataBitLength;
	}
	else
	{
		m_frameBitsIn += internalPacket->dataBitLength;
	}
	
}

void ServerLogger::OnAck(unsigned int messageNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time)
{
}

void ServerLogger::OnPushBackPacket(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress)
{
}