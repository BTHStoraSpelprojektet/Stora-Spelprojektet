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

enum
{
	CLIENT,
	SERVER
} topology;

class DefaultReplica : public RakNet::Replica3
{
public:
	DefaultReplica();
	~DefaultReplica();

	virtual RakNet::RakString GetType() const = 0;
	void NotifyReplicaOfMessageDeliveryStatus(RakNet::RakNetGUID guid, uint32_t receiptId, bool messageArrived);
	void WriteAllocationID(RakNet::Connection_RM3 *destinationConnection, RakNet::BitStream *allocationIdBitstream) const;
	void PrintStringInBitsream(RakNet::BitStream *bitStream);
	RakNet::RM3ConstructionState QueryConstruction(RakNet::Connection_RM3 *destinationConnection, RakNet::ReplicaManager3 *replicaManager3);
	bool QueryRemoteConstruction(RakNet::Connection_RM3 *sourceConnection);
	void SerializeConstruction(RakNet::BitStream *constructionBitstream, RakNet::Connection_RM3 *destinationConnection);
	bool DeserializeConstruction(RakNet::BitStream *constructionBitstream, RakNet::Connection_RM3 *sourceConnection);
	void SerializeDestruction(RakNet::BitStream *destructionBitstream, RakNet::Connection_RM3 *destinationConnection);
	bool DeserializeDestruction(RakNet::BitStream *destructionBitstream, RakNet::Connection_RM3 *sourceConnection);
	RakNet::RM3ActionOnPopConnection QueryActionOnPopConnection(RakNet::Connection_RM3 *droppedConnection) const;
	void DeallocReplica(RakNet::Connection_RM3 *sourceConnection);
	RakNet::RM3QuerySerializationResult QuerySerialization(RakNet::Connection_RM3 *destinationConnection);
	RakNet::RM3SerializationResult Serialize(RakNet::SerializeParameters *serializeParameters);
	void Deserialize(RakNet::DeserializeParameters *deserializeParameters);

private:
	RakNet::VariableDeltaSerializer m_variableDeltaSerializer;
};

#endif