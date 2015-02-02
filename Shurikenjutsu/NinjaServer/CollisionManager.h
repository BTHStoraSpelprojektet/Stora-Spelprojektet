#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"
#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\GetTime.h"
#include "..\CommonLibs\RakNet\NetworkIDManager.h"
#include "..\CommonLibs\RakNet\RakPeer.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include <vector>
#include "Collisions.h"
#include "..\CommonLibs\ServerMessages.h"

class FanBoomerangManager;
class ShurikenManager;
class PlayerManager;
class SpikeManager;

class CollisionManager
{
public:
	void Initialize(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList);

	std::vector<bool> OuterWallCollision(Sphere p_playerSphere);

	void NormalMeleeAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager);
	void ShurikenCollisionChecks(ShurikenManager* p_shurikenManager, PlayerManager* p_playerManager);
	void FanCollisionChecks(double p_deltaTime, FanBoomerangManager* p_fanBoomerangManager, PlayerManager* p_playerManager);

	void SpikeTrapCollisionChecks(SpikeManager* p_spikeManager, PlayerManager* p_playerManager, float p_deltaTime);
	float CalculateDashRange(PlayerNet p_attackingPlayer, PlayerManager* p_playerManager);


private:
	bool OBBOBBTest(OBB p_OBB1, OBB p_OBB2);
	bool BoxBoxTest(Box p_box1, Box p_box2);
	bool SphereSphereTest(Sphere p_spikeTrap, Sphere p_player);
	bool OBBSphereTest(OBB p_OBB, Sphere p_sphere);

	static CollisionManager* m_instance;
	void SetLists(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList);
	std::vector<OBB> m_staticBoxList;
	std::vector<Sphere> m_staticSphereList;
};
#endif

