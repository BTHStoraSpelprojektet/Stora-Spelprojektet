#ifndef REPLICAMANAGER_H_
#define REPLICAMANAGER_H_

#include "ReplicaConnection.h"
#include "ReplicaManager3.h"


class ReplicaManager : public RakNet::ReplicaManager3
{
public:
	ReplicaManager();
	~ReplicaManager();

	RakNet::Connection_RM3* AllocConnection(const RakNet::SystemAddress &systemAddress, RakNet::RakNetGUID rakNetGUID) const;
	void DeallocConnection(RakNet::Connection_RM3* connection) const;
};

#endif