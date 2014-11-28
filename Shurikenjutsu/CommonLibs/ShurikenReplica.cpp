#include "ShurikenReplica.h"


ShurikenReplica::ShurikenReplica()
{
	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;
}


ShurikenReplica::~ShurikenReplica()
{
}

RakNet::RakString ShurikenReplica::GetTypeName() const
{
	return "Shuriken";
}

RakNet::RM3SerializationResult ShurikenReplica::Serialize(RakNet::SerializeParameters *p_serializeParameters)
{
	if (!ServerGlobals::IS_SERVER)
		return RakNet::RM3SR_DO_NOT_SERIALIZE;

	RakNet::VariableDeltaSerializer::SerializationContext serializeContext;

	p_serializeParameters->pro[0].reliability = RELIABLE_ORDERED;

	// Start serialize
	m_variableDeltaSerializer.BeginIdenticalSerialize(&serializeContext, !(p_serializeParameters->whenLastSerialized), &p_serializeParameters->outputBitstream[0]);

	// Write variables
	m_variableDeltaSerializer.SerializeVariable(&serializeContext, m_posX);
	m_variableDeltaSerializer.SerializeVariable(&serializeContext, m_posY);
	m_variableDeltaSerializer.SerializeVariable(&serializeContext, m_posZ);

	// End Serialize
	m_variableDeltaSerializer.EndSerialize(&serializeContext);

	return RakNet::RM3SR_SERIALIZED_UNIQUELY;
}

void ShurikenReplica::Deserialize(RakNet::DeserializeParameters *p_deserializeParameters)
{
	RakNet::VariableDeltaSerializer::DeserializationContext deserializationContext;

	// Begin deserialize
	m_variableDeltaSerializer.BeginDeserialize(&deserializationContext, &p_deserializeParameters->serializationBitstream[0]);

	// Read variables
	m_variableDeltaSerializer.DeserializeVariable(&deserializationContext, m_posX);
	m_variableDeltaSerializer.DeserializeVariable(&deserializationContext, m_posY);
	m_variableDeltaSerializer.DeserializeVariable(&deserializationContext, m_posZ);

	// End deserialize
	m_variableDeltaSerializer.EndDeserialize(&deserializationContext);
}

void ShurikenReplica::SetPosition(float p_x, float p_y, float p_z)
{
	m_posX = p_x;
	m_posY = p_y;
	m_posZ = p_z;
}

float ShurikenReplica::GetPosX()
{
	return m_posX;
}

float ShurikenReplica::GetPosY()
{
	return m_posY;
}

float ShurikenReplica::GetPosZ()
{
	return m_posZ;
}