#include "ReplicaConnection.h"


ReplicaConnection::ReplicaConnection(const RakNet::SystemAddress &systemAddress, RakNet::RakNetGUID guid) : Connection_RM3(systemAddress, guid)
{
}


ReplicaConnection::~ReplicaConnection()
{
}

bool ReplicaConnection::QueryGroupDownloadMessages() const
{
	return true;
}

RakNet::Replica3* ReplicaConnection::AllocReplica(RakNet::BitStream *allocationId, RakNet::ReplicaManager3 *replicaManager3)
{
	RakNet::RakString typeName;
	allocationId->Read(typeName);

	if (typeName == "Player")
	{
		// return new PlayerSerializer
	}

	return 0;
}