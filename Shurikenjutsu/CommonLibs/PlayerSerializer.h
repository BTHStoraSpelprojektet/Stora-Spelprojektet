#ifndef PLAYERSERIALIZER_H_
#define PLAYERSERIALIZER_H_

#include "DefaultReplica.h"

class PlayerSerializer : public DefaultReplica
{
public:
	PlayerSerializer();
	~PlayerSerializer();

	RakNet::RakString GetTypeName();
	RakNet::RM3SerializationResult Serialize(RakNet::SerializeParameters *p_serializeParameters);
	void Deserialize(RakNet::DeserializeParameters *p_deserializeParameters);
private:
	float m_posX, m_posY, m_posZ;
};

#endif