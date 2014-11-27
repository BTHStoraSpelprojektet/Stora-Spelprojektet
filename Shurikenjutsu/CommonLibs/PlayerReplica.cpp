#include "PlayerReplica.h"


PlayerReplica::PlayerReplica() : DefaultReplica()
{
	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;
}


PlayerReplica::~PlayerReplica()
{
}

RakNet::RakString PlayerReplica::GetTypeName() const
{
	return "Player";
}

RakNet::RM3SerializationResult PlayerReplica::Serialize(RakNet::SerializeParameters *p_serializeParameters)
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

void PlayerReplica::Deserialize(RakNet::DeserializeParameters *p_deserializeParameters)
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

void PlayerReplica::SetPosition(float p_x, float p_y, float p_z)
{
	m_posX = p_x;
	m_posY = p_y;
	m_posZ = p_z;
}

float PlayerReplica::GetPosX()
{
	return m_posX;
}

float PlayerReplica::GetPosY()
{
	return m_posY;
}

float PlayerReplica::GetPosZ()
{
	return m_posZ;
}