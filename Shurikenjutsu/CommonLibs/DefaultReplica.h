#ifndef DEFAULTREPLICA_H_
#define DEFAULTREPLICA_H

//#include "RakPeerInterface.h"
//#include "MessageIdentifiers.h"
//#include "BitStream.h"
//#include "RakNetTypes.h"
//#include "GetTime.h"
//#include "NetworkIDManager.h"

#include "ReplicaManager3.h"
#include "VariableDeltaSerializer.h"

class DefaultReplica : public RakNet::Replica3
{
public:
	DefaultReplica(bool p_isServer);
	~DefaultReplica();

	virtual RakNet::RakString GetTypeName() const = 0;
	void NotifyReplicaOfMessageDeliveryStatus(RakNet::RakNetGUID p_guid, uint32_t p_receiptId, bool p_messageArrived);
	void WriteAllocationID(RakNet::Connection_RM3 *p_destinationConnection, RakNet::BitStream *p_allocationIdBitstream) const;
	void PrintStringInBitsream(RakNet::BitStream *p_bitStream);
	RakNet::RM3ConstructionState QueryConstruction(RakNet::Connection_RM3 *p_destinationConnection, RakNet::ReplicaManager3 *p_replicaManager3);
	bool QueryRemoteConstruction(RakNet::Connection_RM3 *p_sourceConnection);
	void SerializeConstruction(RakNet::BitStream *p_constructionBitstream, RakNet::Connection_RM3 *p_destinationConnection);
	bool DeserializeConstruction(RakNet::BitStream *p_constructionBitstream, RakNet::Connection_RM3 *p_sourceConnection);
	void SerializeDestruction(RakNet::BitStream *p_destructionBitstream, RakNet::Connection_RM3 *p_destinationConnection);
	bool DeserializeDestruction(RakNet::BitStream *p_destructionBitstream, RakNet::Connection_RM3 *p_sourceConnection);
	RakNet::RM3ActionOnPopConnection QueryActionOnPopConnection(RakNet::Connection_RM3 *p_droppedConnection) const;
	void DeallocReplica(RakNet::Connection_RM3 *p_sourceConnection);
	RakNet::RM3QuerySerializationResult QuerySerialization(RakNet::Connection_RM3 *p_destinationConnection);
	RakNet::RM3SerializationResult Serialize(RakNet::SerializeParameters *p_serializeParameters);
	void Deserialize(RakNet::DeserializeParameters *p_deserializeParameters);

protected:
	RakNet::VariableDeltaSerializer m_variableDeltaSerializer;
	bool m_isServer;
};

#endif