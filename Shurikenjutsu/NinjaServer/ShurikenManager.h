#ifndef SHURIKENMANAGERSERVER_H_
#define SHURIKENMANAGERSERVER_H_

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerGlobals.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <vector>

class ShurikenManager
{
public:
	ShurikenManager();
	~ShurikenManager();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);

	void AddShuriken(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ);
	void AddMegaShuriken(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ);
	void RemoveShuriken(unsigned int p_id);
	std::vector<ShurikenNet> GetShurikens();
	std::vector<Box> GetBoundingBoxes(int p_index);
	std::vector<Box> GetMegaBoundingBoxes(int p_index);
	float GetShurikenPosX(int p_index);
	float GetShurikenPosY(int p_index);
	float GetShurikenPosZ(int p_index);
private:
	void UpdateShurikens(double p_deltaTime);
	void BroadcastDestoyedShuriken(unsigned int p_id);
	unsigned int GetShurikenUniqueId();

	RakNet::RakPeerInterface *m_serverPeer;
	float m_shurikenSetTimeLeft;
	float m_megaShurikenSetTimeLeft;

	std::vector<ShurikenNet> m_shurikens;
	std::vector<Box> m_boundingBoxes;
	std::vector<Box> m_megaBoundingBoxes;
};

#endif