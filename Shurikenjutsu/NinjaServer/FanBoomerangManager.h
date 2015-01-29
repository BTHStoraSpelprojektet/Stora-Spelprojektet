#ifndef FANBOOMERANG_H_
#define FANBOOMERANG_H_

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerGlobals.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "..\CommonLibs\CommonStructures.h"
#include <vector>

class FanBoomerangManager
{
public:
	FanBoomerangManager();
	~FanBoomerangManager();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);

	void Add(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ);
	void Remove(unsigned int p_id);
	std::vector<FanNet> GetObjects();
	std::vector<Box> GetBoundingBoxes(int p_index);
	float GetPosX(int p_index);
	float GetPosY(int p_index);
	float GetPosZ(int p_index);

private:
	void BroadcastDestoyed(unsigned int p_id);
	unsigned int GetUniqueId();

	RakNet::RakPeerInterface *m_serverPeer;

	std::vector<FanNet> m_fans;
	std::vector<Box> m_boundingBoxes;
};

#endif