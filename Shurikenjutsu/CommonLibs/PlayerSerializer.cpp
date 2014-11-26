#include "PlayerSerializer.h"


PlayerSerializer::PlayerSerializer(bool p_isServer) : DefaultReplica(p_isServer)
{
	m_posX = 0;
	m_posY = 0;
	m_posZ = 0;
}


PlayerSerializer::~PlayerSerializer()
{
}

RakNet::RM3SerializationResult PlayerSerializer::Serialize(RakNet::SerializeParameters *p_serializeParameters)
{
	if (!m_isServer)
	{
		return RakNet::RM3SR_DO_NOT_SERIALIZE;
	}

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

void PlayerSerializer::Deserialize(RakNet::DeserializeParameters *p_deserializeParameters)
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