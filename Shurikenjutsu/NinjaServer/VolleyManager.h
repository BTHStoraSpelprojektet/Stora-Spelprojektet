#ifndef VOLLEYMANAGER_H_
#define VOLLEYMANAGER_H_

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <vector>
#include "..\CommonLibs\GameplayGlobalVariables.h"

class VolleyManager
{
public:
	VolleyManager();
	~VolleyManager();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);
	void Add(RakNet::RakNetGUID p_guid, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ);
	void Remove(int index);

	std::vector<VolleyNet> GetObjects();
	unsigned int GetUniqueId();

	float GetCurrentDistanceFromPlayer();
	void SetCurrentDistanceFromPlayer(float p_distance);

private:
	RakNet::RakPeerInterface *m_serverPeer;
	std::vector<VolleyNet> m_volleys;
	float m_currentDistanceFromPlayer;
};
#endif
