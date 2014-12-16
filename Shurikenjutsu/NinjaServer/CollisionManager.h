#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"
#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\GetTime.h"
#include "..\CommonLibs\RakNet\NetworkIDManager.h"
#include "..\CommonLibs\RakNet\RakPeer.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include <vector>
#include "Collisions.h"
#include "PlayerManager.h"
#include "ShurikenManager.h"

class PlayerManager;
class CollisionManager
{
public:
	void Initialize(std::vector<OBB> p_StaticObjectList/*, std::vector<Sphere> p_sphereObjectList*/);

	std::vector<OBB> CalculateLocalPlayerCollisionWithStaticObjects(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction, float p_deltaTime);
	std::vector<bool> OuterWallCollision(Sphere p_playerSphere);


	void NormalMeleeAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager);
	void ShurikenCollisionChecks(ShurikenManager* p_shurikenManager, PlayerManager* p_playerManager);

private:
	bool OBBOBBtest(OBB p_OBB1, OBB p_OBB2);
	bool BoxBoxtest(Box p_box1, Box p_box2);




	static CollisionManager* m_instance;
	void SetLists(std::vector<OBB> p_StaticObjectList/*, std::vector<Sphere> p_sphereObjectList*/);
	std::vector<OBB> m_StaticObjectList;
	//std::vector<Sphere> m_sphereObjectList;
};
#endif

