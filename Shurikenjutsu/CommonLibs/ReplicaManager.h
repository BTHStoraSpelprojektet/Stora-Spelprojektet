#ifndef REPLICAMANAGER_H_
#define REPLICAMANAGER_H_

#include "..\CommonLibs\RakNet\WindowsIncludes.h"
#include "ReplicaConnection.h"
#include "..\CommonLibs\RakNet\ReplicaManager3.h"


class ReplicaManager : public RakNet::ReplicaManager3
{
public:
	ReplicaManager() {}
	virtual ~ReplicaManager() {}
	RakNet::Connection_RM3* AllocConnection(const RakNet::SystemAddress &p_systemAddress, RakNet::RakNetGUID p_rakNetGUID) const;
	void DeallocConnection(RakNet::Connection_RM3* p_connection) const;
};

#endif