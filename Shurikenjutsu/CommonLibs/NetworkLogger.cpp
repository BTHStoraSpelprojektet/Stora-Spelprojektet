#include "NetworkLogger.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ServerGlobals.h"

NetworkLogger::NetworkLogger() : PacketLogger() {}
NetworkLogger::~NetworkLogger(){}

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B> &p)
{
	return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B, A> flip_map(const std::map<A, B> &src)
{
	std::multimap<B, A> dst;
	std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair<A, B>);
	return dst;
}

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
			#ifdef _DEBUG
				std::cout << "In: " << (int)bytesPerSecIn << "  Out: " << (int)bytesPerSecOut << std::endl;
			#endif			
		}
		ServerGlobals::BYTES_IN = (int)bytesPerSecIn;
		ServerGlobals::BYTES_OUT = (int)bytesPerSecOut;

		// Check most used packets
		// In
		std::multimap<int, std::string> flipped = flip_map(m_nrPacketsIn);
		int index = 0;
		std::string messagesIn = "";
		for (std::multimap<int, std::string>::reverse_iterator rit = flipped.rbegin(); rit != flipped.rend(); rit++)
		{
			if (ServerGlobals::IS_SERVER)
			{
				#ifdef _DEBUG
					//std::cout << "InMessage: " << rit->second << "  Nr: " << rit->first << std::endl;
				#endif			
			}
			messagesIn += "InMessage: " + rit->second + "  Nr: " + std::to_string(rit->first) + "\n";
			index++;
			if (index >= 5)
			{
				break;
			}
		}
		ServerGlobals::MESSAGES_IN = messagesIn.c_str();

		// Out
		flipped = flip_map(m_nrPacketsOut);
		index = 0;
		std::string messagesOut = "";
		for (std::multimap<int, std::string>::reverse_iterator rit = flipped.rbegin(); rit != flipped.rend(); rit++)
		{
			if (ServerGlobals::IS_SERVER)
			{
				#ifdef _DEBUG
					//std::cout << "OutMessage: " << rit->second << "  Nr: " << rit->first << std::endl;
				#endif			
			}
			messagesOut += "OutMessage: " + rit->second + "  Nr: " + std::to_string(rit->first) + "\n";
			index++;
			if (index >= 5)
			{
				break;
			}
		}
		ServerGlobals::MESSAGES_OUT = messagesOut.c_str();
		m_time = 0;
		m_frameBitsIn = 0;
		m_frameBitsOut = 0;
		m_nrPacketsIn.clear();
		m_nrPacketsOut.clear();
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
	std::string message = IDTOString(internalPacket->data[0]);

	if (isSend)
	{
		//std::cout << "Message out: " << IDTOString(internalPacket->data[0]) << std::endl;
		m_frameBitsOut += internalPacket->dataBitLength;

		if (!ServerGlobals::IS_SERVER) // This keep on crashin on the server, dunno why so put an if statement to not run it on the server
		{
			if (m_nrPacketsOut.size() == 0 || m_nrPacketsOut.find(message) == m_nrPacketsOut.end())
			{
				m_nrPacketsOut[message] = 1;
			}
			else
			{
				m_nrPacketsOut[message]++;
			}
		}
	}
	else
	{
		//std::cout << "Message in: " << IDTOString(internalPacket->data[0]) << std::endl;
		m_frameBitsIn += internalPacket->dataBitLength;

		if (!ServerGlobals::IS_SERVER) // This keep on crashin on the server, dunno why so put an if statement to not run it on the server
		{
			if (m_nrPacketsIn.size() == 0 || m_nrPacketsIn.find(message) == m_nrPacketsIn.end())
			{
				m_nrPacketsIn[message] = 1;
			}
			else
			{
				m_nrPacketsIn[message]++;
			}
		}
	}

}

void NetworkLogger::OnAck(unsigned int messageNumber, RakNet::SystemAddress remoteSystemAddress, RakNet::TimeMS time)
{
}

void NetworkLogger::OnPushBackPacket(const char *data, const RakNet::BitSize_t bitsUsed, RakNet::SystemAddress remoteSystemAddress)
{
}




//const char* NetworkLogger::UserIDTOString(unsigned char Id)
//{
//	const char *IDTable[((int)ID_NAGINATA_STAB_HAS_OCCURED) - (int)ID_NR_CONNECTIONS + 1] =
//	{
//		"ID_NR_CONNECTIONS"
//		"ID_DOWNLOAD_PLAYERS",
//		"ID_PLAYER_MOVED",
//		"ID_PLAYER_ROTATED",
//		"ID_SHURIKEN_THROWN",
//		"ID_SHURIKEN_REMOVE",
//		"ID_PROJECTILE_THROWN",
//		"ID_PROJECTILE_REMOVE",
//		"ID_RESPAWN_PLAYER",
//		"ID_MELEE_ATTACK",
//		"ID_PLAYER_INVALID_MOVE",
//		"ID_PLAYER_HP_CHANGED",
//		"ID_ABILITY",
//		"ID_ROUND_OVER",
//		"ID_RESTARTED_ROUND",
//		"ID_RESTARTING_ROUND",
//		"ID_RESTARTING_ROUND_TIMER",
//		"ID_SMOKEBOMB_THROW",
//		"ID_SMOKEBOMB_REMOVE",
//		"ID_MATCH_OVER",
//		"ID_NEW_LEVEL",
//		"ID_PLAYER_ANIMATION_CHANGED",
//		"ID_SPIKETRAP_THROW",
//		"ID_SPIKETRAP_REMOVE",
//		"ID_DASH_TO_LOCATION",
//		"ID_CHOOSE_CHAR",
//		"ID_FAN_THROWN",
//		"ID_FAN_REMOVE",
//		"ID_FAN_UPDATE",
//		"ID_FAN_DEAD_UPDATE",
//		"ID_VOLLEY_THROWN",
//		"ID_TIMER_SYNC",
//		"ID_STICKYTRAP_THROW",
//		"ID_STICKYTRAP_REMOVE",
//		"ID_SEND_TEAM_SCORE",
//		"ID_NAGINATA_STAB_HAS_OCCURED"
//	};
//
//	if (Id >= ID_NAGINATA_STAB_HAS_OCCURED - 1)
//	{
//		std::string str;
//		str = std::to_string(Id);
//		return str.c_str();
//	}
//	else
//	{
//		return (char*)IDTable[Id - ID_NR_CONNECTIONS - 1];
//	}
//
//}