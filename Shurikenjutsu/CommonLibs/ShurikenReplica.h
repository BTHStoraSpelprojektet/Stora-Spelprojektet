/*#ifndef SHURIKENREPLICA_H_
#define SHURIKENREPLICA_H_

#include "DefaultReplica.h"

class ShurikenReplica : public DefaultReplica
{
public:
	ShurikenReplica();
	~ShurikenReplica();

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

#endif SHURIKENREPLICA_H_*/