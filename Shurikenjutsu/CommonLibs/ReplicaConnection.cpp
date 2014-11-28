#include "ReplicaConnection.h"


ReplicaConnection::ReplicaConnection(const RakNet::SystemAddress &p_systemAddress, RakNet::RakNetGUID p_guid) : Connection_RM3(p_systemAddress, p_guid)
{
}


ReplicaConnection::~ReplicaConnection()
{
}

bool ReplicaConnection::QueryGroupDownloadMessages() const
{
	return true;
}

RakNet::Replica3* ReplicaConnection::AllocReplica(RakNet::BitStream *p_allocationId, RakNet::ReplicaManager3 *p_replicaManager3)
{
	RakNet::RakString typeName;
	p_allocationId->Read(typeName);

	if (typeName == "Player")
	{
		return new PlayerReplica;
	}
	if (typeName == "Shuriken")
	{
		return new ShurikenReplica;
	}
	return 0;
}