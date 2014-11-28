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

	void SetPosition(float p_x, float p_y, float p_z);
	float GetPosX();
	float GetPosY();
	float GetPosZ();
private:
	float m_posX, m_posY, m_posZ;
};

#endif