#include "DefaultReplica.h"


DefaultReplica::DefaultReplica(bool p_isServer)
{
	m_isServer = p_isServer;
}


DefaultReplica::~DefaultReplica()
{
}

void DefaultReplica::NotifyReplicaOfMessageDeliveryStatus(RakNet::RakNetGUID p_guid, uint32_t p_receiptId, bool p_messageArrived)
{
	m_variableDeltaSerializer.OnMessageReceipt(p_guid, p_receiptId, p_messageArrived);
}

void DefaultReplica::WriteAllocationID(RakNet::Connection_RM3 *p_destinationConnection, RakNet::BitStream *p_allocationIdBitstream) const
{
	p_allocationIdBitstream->Write(GetTypeName());
}

void DefaultReplica::PrintStringInBitsream(RakNet::BitStream *p_bitStream)
{
	if (!(p_bitStream->GetNumberOfBitsUsed() == 0))
	{
		RakNet::RakString rakString;
		p_bitStream->Read(rakString);
		printf("Receive: %s\n", rakString.C_String());
	}
}

RakNet::RM3ConstructionState DefaultReplica::QueryConstruction(RakNet::Connection_RM3 *p_destinationConnection, RakNet::ReplicaManager3 *p_replicaManager3)
{
	return QueryConstruction_ClientConstruction(p_destinationConnection, m_isServer);
}

bool DefaultReplica::QueryRemoteConstruction(RakNet::Connection_RM3 *p_sourceConnection)
{
	return QueryRemoteConstruction_ClientConstruction(p_sourceConnection, m_isServer);
}

void DefaultReplica::SerializeConstruction(RakNet::BitStream *p_constructionBitstream, RakNet::Connection_RM3 *p_destinationConnection)
{
	m_variableDeltaSerializer.AddRemoteSystemVariableHistory(p_destinationConnection->GetRakNetGUID());

	p_constructionBitstream->Write(GetTypeName() + " SerializeConstruction");
}

bool DefaultReplica::DeserializeConstruction(RakNet::BitStream *p_constructionBitstream, RakNet::Connection_RM3 *p_sourceConnection)
{
	PrintStringInBitsream(p_constructionBitstream);
	return true;
}

void DefaultReplica::SerializeDestruction(RakNet::BitStream *p_destructionBitstream, RakNet::Connection_RM3 *p_destinationConnection)
{
	m_variableDeltaSerializer.RemoveRemoteSystemVariableHistory(p_destinationConnection->GetRakNetGUID());

	p_destructionBitstream->Write(GetTypeName() + " SerializeDestruction");
}

bool DefaultReplica::DeserializeDestruction(RakNet::BitStream *p_destructionBitstream, RakNet::Connection_RM3 *p_sourceConnection)
{
	PrintStringInBitsream(p_destructionBitstream);
	return true;
}

RakNet::RM3ActionOnPopConnection DefaultReplica::QueryActionOnPopConnection(RakNet::Connection_RM3 *p_droppedConnection) const
{
	return QueryActionOnPopConnection_Client(p_droppedConnection);
}

void DefaultReplica::DeallocReplica(RakNet::Connection_RM3 *p_sourceConnection)
{
	delete this;
}

RakNet::RM3QuerySerializationResult DefaultReplica::QuerySerialization(RakNet::Connection_RM3 *p_destinationConnection)
{
	return QuerySerialization_ServerSerializable(p_destinationConnection, m_isServer);
}

// This is for example, don't run the commented code
RakNet::RM3SerializationResult DefaultReplica::Serialize(RakNet::SerializeParameters *p_serializeParameters)
{
	// How to write function

	//if (topology == CLIENT)
	//{
	//	return RakNet::RM3SR_DO_NOT_SERIALIZE;
	//}
	//RakNet::VariableDeltaSerializer::SerializationContext serializationContext;

	//serializeParameters->pro[0].reliability = RELIABLE_ORDERED;
	//m_variableDeltaSerializer.BeginIdenticalSerialize(
	//	&serializationContext,
	//	!(serializeParameters->whenLastSerialized),
	//	&serializeParameters->outputBitstream[0]
	//	);
	//m_variableDeltaSerializer.SerializeVariable(&serializationContext, variable1);
	//m_variableDeltaSerializer.SerializeVariable(&serializationContext, variable2);
	//m_variableDeltaSerializer.EndSerialize(&serializationContext);

	return RakNet::RM3SR_SERIALIZED_UNIQUELY;
}


// This is just for example, don't run the commented code
void DefaultReplica::Deserialize(RakNet::DeserializeParameters *p_deserializeParameters)
{
	// How to write function

	//RakNet::VariableDeltaSerializer::DeserializationContext deserializationContext;

	//m_variableDeltaSerializer.BeginDeserialize(&deserializationContext, &deserializeParameters->serializationBitstream[0]);
	//if (m_variableDeltaSerializer.DeserializeVariable(&deserializationContext, variable1))
	//{
	//	//printf("variable1 changed to %i\n", variable1);
	//}
	//if (m_variableDeltaSerializer.DeserializeVariable(&deserializationContext, variable2))
	//{
	//	//printf("variable2 changed to %i\n", variable2);
	//}
	//m_variableDeltaSerializer.EndDeserialize(&deserializationContext);
}