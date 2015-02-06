#ifndef STICKYTRAPMANAGER_H
#define STICKYTRAPMANAGER_H
#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <vector>

class StickyTrapManager
{
public:
	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);
	void AddStickyTrap(RakNet::RakNetGUID p_guid, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ);


	std::vector<StickyTrapNet> GetStickyTraps();
	unsigned int GetSpikeTrapUniqueId();

	void BroadcastEmptyStickyTraps(unsigned int p_id);
	float GetCurrentDistanceFromPlayer();
	void SetCurrentDistanceFromPlayer(float p_distance);


private:
	RakNet::RakPeerInterface *m_serverPeer;
	std::vector<StickyTrapNet> m_stickyTrapList;
	float m_currentDistanceFromPlayer;
};

#endif