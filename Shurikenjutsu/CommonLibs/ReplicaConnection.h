#ifndef REPLICACONNECTION_H_
#define REPLICACONNECTION_H

#include "..\CommonLibs\RakNet\WindowsIncludes.h"
#include "..\CommonLibs\RakNet\ReplicaManager3.h"
#include "PlayerReplica.h"

class ReplicaConnection : public RakNet::Connection_RM3
{
public:
	ReplicaConnection(const RakNet::SystemAddress &p_systemAddress, RakNet::RakNetGUID p_guid);
	~ReplicaConnection();

	bool QueryGroupDownloadMessages() const;
	RakNet::Replica3* AllocReplica(RakNet::BitStream *p_allocationId, RakNet::ReplicaManager3 *p_replicaManager3);
private:

};

#endif