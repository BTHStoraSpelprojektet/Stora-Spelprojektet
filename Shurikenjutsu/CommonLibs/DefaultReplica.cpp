#include "DefaultReplica.h"


DefaultReplica::DefaultReplica()
{
}


DefaultReplica::~DefaultReplica()
{
}

void DefaultReplica::NotifyReplicaOfMessageDeliveryStatus(RakNet::RakNetGUID guid, uint32_t receiptId, bool messageArrived)
{
	m_variableDeltaSerializer.OnMessageReceipt(guid, receiptId, messageArrived);
}

void DefaultReplica::WriteAllocationID(RakNet::Connection_RM3 *destinationConnection, RakNet::BitStream *allocationIdBitstream) const
{
	allocationIdBitstream->Write(GetType());
}

void DefaultReplica::PrintStringInBitsream(RakNet::BitStream *bitStream)
{
	if (!(bitStream->GetNumberOfBitsUsed() == 0))
	{
		RakNet::RakString rakString;
		bitStream->Read(rakString);
		printf("Receive: %s\n", rakString.C_String());
	}
}

RakNet::RM3ConstructionState DefaultReplica::QueryConstruction(RakNet::Connection_RM3 *destinationConnection, RakNet::ReplicaManager3 *replicaManager3)
{
	return QueryConstruction_ClientConstruction(destinationConnection, topology != CLIENT);
}

bool DefaultReplica::QueryRemoteConstruction(RakNet::Connection_RM3 *sourceConnection)
{
	return QueryRemoteConstruction_ClientConstruction(sourceConnection, topology != CLIENT);
}

void DefaultReplica::SerializeConstruction(RakNet::BitStream *constructionBitstream, RakNet::Connection_RM3 *destinationConnection)
{
	m_variableDeltaSerializer.AddRemoteSystemVariableHistory(destinationConnection->GetRakNetGUID());

	constructionBitstream->Write(GetType() + " SerializeConstruction");
}

bool DefaultReplica::DeserializeConstruction(RakNet::BitStream *constructionBitstream, RakNet::Connection_RM3 *sourceConnection)
{
	PrintStringInBitsream(constructionBitstream);
	return true;
}

void DefaultReplica::SerializeDestruction(RakNet::BitStream *destructionBitstream, RakNet::Connection_RM3 *destinationConnection)
{
	m_variableDeltaSerializer.RemoveRemoteSystemVariableHistory(destinationConnection->GetRakNetGUID());

	destructionBitstream->Write(GetType() + " SerializeDestruction");
}

bool DefaultReplica::DeserializeDestruction(RakNet::BitStream *destructionBitstream, RakNet::Connection_RM3 *sourceConnection)
{
	PrintStringInBitsream(destructionBitstream);
	return true;
}

RakNet::RM3ActionOnPopConnection DefaultReplica::QueryActionOnPopConnection(RakNet::Connection_RM3 *droppedConnection) const
{
	return QueryActionOnPopConnection_Client(droppedConnection);
}

void DefaultReplica::DeallocReplica(RakNet::Connection_RM3 *sourceConnection)
{
	delete this;
}

RakNet::RM3QuerySerializationResult DefaultReplica::QuerySerialization(RakNet::Connection_RM3 *destinationConnection)
{
	return QuerySerialization_ServerSerializable(destinationConnection, topology != CLIENT);
}

// This is for example, don't run the commented code
RakNet::RM3SerializationResult DefaultReplica::Serialize(RakNet::SerializeParameters *serializeParameters)
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
void DefaultReplica::Deserialize(RakNet::DeserializeParameters *deserializeParameters)
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