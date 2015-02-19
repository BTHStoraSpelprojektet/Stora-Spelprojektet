#ifndef SPIKEMANAGER_H
#define SPIKEMANAGER_H
#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <vector>
class SpikeManager
{
public:
	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);
	void AddSpikeTrap(RakNet::RakNetGUID p_guid, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, int p_team);


	std::vector<SpikeNet> GetSpikeTraps();
	unsigned int GetSpikeTrapUniqueId();

	void BroadcastEmptySpikeTraps(unsigned int p_id);
	float GetCurrentDistanceFromPlayer();
	void SetCurrentDistanceFromPlayer(float p_distance);
	void ResetLists();

private:
	RakNet::RakPeerInterface *m_serverPeer;
	std::vector<SpikeNet> m_spikeTrapList;
	float m_currentDistanceFromPlayer;
};
#endif