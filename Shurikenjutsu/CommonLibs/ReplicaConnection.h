#ifndef REPLICACONNECTION_H_
#define REPLICACONNECTION_H

#include "ReplicaManager3.h"

class ReplicaConnection : RakNet::Connection_RM3
{
public:
	ReplicaConnection(const RakNet::SystemAddress &systemAddress, RakNet::RakNetGUID guid);
	~ReplicaConnection();

	bool QueryGroupDownloadMessages() const;
	RakNet::Replica3* AllocReplica(RakNet::BitStream *allocationId, RakNet::ReplicaManager3 *replicaManager3);
private:

};

#endif