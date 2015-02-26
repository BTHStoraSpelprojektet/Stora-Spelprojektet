#include "NetworkLogger.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ServerGlobals.h"

NetworkLogger::NetworkLogger() : PacketLogger() {}
NetworkLogger::~NetworkLogger(){}

void NetworkLogger::Initialize()
{
	m_frameBitsIn = 0;
	m_frameBitsOut = 0;
	m_time = 0;
	ServerGlobals::BYTES_IN = 0;
	ServerGlobals::BYTES_OUT = 0;
}

void NetworkLogger::Update(double p_deltaTime)
{
	m_time += p_deltaTime;
	if (m_time > 5)
	{
		double bytesPerSecIn = (m_frameBitsIn / 8) / m_time;
		double bytesPerSecOut = (m_frameBitsOut / 8) / m_time;
		if (ServerGlobals::IS_SERVER)
		{
			std::cout << "In: " << (int)bytesPerSecIn << "  Out: " << (int)bytesPerSecOut << std::endl;
		}
		ServerGlobals::BYTES_IN = (int)bytesPerSecIn;
		ServerGlobals::BYTES_OUT = (int)bytesPerSecOut;
		m_time = 0;
		m_frameBitsIn = 0;
		m_frameBitsOut = 0;
	}
}

void NetworkLogger::OnDirectSocketSend(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress)
{
}

void NetworkLogger::OnDirectSocketReceive(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress)
{
}

void NetworkLogger::OnReliabilityLayerNotification(const char *errorMessage, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress, bool isError)
{
}

void NetworkLogger::OnInternalPacket(RakNet::InternalPacket *internalPacket, unsigned frameNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time, int isSend)
{
	if (isSend)
	{
		//std::cout << "Message out: " << IDTOString(internalPacket->data[0]) << std::endl;
		m_frameBitsOut += internalPacket->dataBitLength;
	}
	else
	{
		//std::cout << "Message in: " << IDTOString(internalPacket->data[0]) << std::endl;
		m_frameBitsIn += internalPacket->dataBitLength;
	}

}

void NetworkLogger::OnAck(unsigned int messageNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time)
{
}

void NetworkLogger::OnPushBackPacket(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress)
{
}

const char* NetworkLogger::UserIDTOString(unsigned char Id)
{
	const char *IDTable[((int)ID_NAGINATA_STAB_HAS_OCCURED) - (int)ID_NR_CONNECTIONS + 1] =
	{
		"ID_NR_CONNECTIONS"
		"ID_DOWNLOAD_PLAYERS",
		"ID_PLAYER_MOVED",
		"ID_PLAYER_ROTATED",
		"ID_SHURIKEN_THROWN",
		"ID_SHURIKEN_REMOVE",
		"ID_PROJECTILE_THROWN",
		"ID_PROJECTILE_REMOVE",
		"ID_RESPAWN_PLAYER",
		"ID_MELEE_ATTACK",
		"ID_PLAYER_INVALID_MOVE",
		"ID_PLAYER_HP_CHANGED",
		"ID_ABILITY",
		"ID_ROUND_OVER",
		"ID_RESTARTED_ROUND",
		"ID_RESTARTING_ROUND",
		"ID_RESTARTING_ROUND_TIMER",
		"ID_SMOKEBOMB_THROW",
		"ID_SMOKEBOMB_REMOVE",
		"ID_MATCH_OVER",
		"ID_NEW_LEVEL",
		"ID_PLAYER_ANIMATION_CHANGED",
		"ID_SPIKETRAP_THROW",
		"ID_SPIKETRAP_REMOVE",
		"ID_DASH_TO_LOCATION",
		"ID_CHOOSE_CHAR",
		"ID_FAN_THROWN",
		"ID_FAN_REMOVE",
		"ID_FAN_UPDATE",
		"ID_FAN_DEAD_UPDATE",
		"ID_VOLLEY_THROWN",
		"ID_TIMER_SYNC",
		"ID_STICKYTRAP_THROW",
		"ID_STICKYTRAP_REMOVE",
		"ID_SEND_TEAM_SCORE",
		"ID_NAGINATA_STAB_HAS_OCCURED"
	};

	if (Id >= ID_NAGINATA_STAB_HAS_OCCURED - 1)
	{
		std::string str;
		str = std::to_string(Id);
		return str.c_str();
	}
	else
	{
		return (char*)IDTable[Id - ID_NR_CONNECTIONS - 1];
	}

}