#ifndef PLAYERREPLICA_H_
#define PLAYERREPLICA_H_

#include "..\CommonLibs\RakNet\WindowsIncludes.h"
#include "DefaultReplica.h"

class PlayerReplica : public DefaultReplica
{
public:
	PlayerReplica();
	~PlayerReplica();

	RakNet::RakString GetTypeName() const;
	RakNet::RM3SerializationResult Serialize(RakNet::SerializeParameters *p_serializeParameters);
	void Deserialize(RakNet::DeserializeParameters *p_deserializeParameters);
private:
	float m_posX, m_posY, m_posZ;
};

#endif