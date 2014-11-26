#include "ReplicaManager.h"


ReplicaManager::ReplicaManager()
{
}


ReplicaManager::~ReplicaManager()
{
}

RakNet::Connection_RM3* ReplicaManager::AllocConnection(const RakNet::SystemAddress &p_systemAddress, RakNet::RakNetGUID p_rakNetGUID) const
{
	return new ReplicaConnection(p_systemAddress, p_rakNetGUID);
}

void ReplicaManager::DeallocConnection(RakNet::Connection_RM3* p_connection) const
{
	delete p_connection;
}