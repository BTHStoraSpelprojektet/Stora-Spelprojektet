#include "ReplicaManager.h"


ReplicaManager::ReplicaManager()
{
}


ReplicaManager::~ReplicaManager()
{
}

RakNet::Connection_RM3* ReplicaManager::AllocConnection(const RakNet::SystemAddress &systemAddress, RakNet::RakNetGUID rakNetGUID) const
{
	return new ReplicaConnection(systemAddress, rakNetGUID);
}

void ReplicaManager::DeallocConnection(RakNet::Connection_RM3* connection) const
{
	delete connection;
}