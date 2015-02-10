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
#include "../CommonLibs/CommonEnums.h"

class FanBoomerangManager;
class ShurikenManager;
class PlayerManager;
class SpikeManager;
class ProjectileManager;
class VolleyManager;

class CollisionManager
{
public:
	void Initialize(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList);

	std::vector<bool> OuterWallCollision(Sphere p_playerSphere);

	void NormalMeleeAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager, ABILITIES p_ability);
	void ShurikenCollisionChecks(ShurikenManager* p_shurikenManager, PlayerManager* p_playerManager);
	void ProjectileCollisionChecks(ProjectileManager* p_shurikenManager, PlayerManager* p_playerManager);
	void FanCollisionChecks(double p_deltaTime, FanBoomerangManager* p_fanBoomerangManager, PlayerManager* p_playerManager);

	void SpikeTrapCollisionChecks(SpikeManager* p_spikeManager, PlayerManager* p_playerManager);
	void NaginataStbDot(PlayerManager* p_playerManager);
	float CalculateDashRange(PlayerNet p_attackingPlayer, PlayerManager* p_playerManager);
	void WhipPrimaryAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager);
	void WhipSecondaryAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager);
	void NaginataStabAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager);
	float GetAngle(float p_x, float p_y);
	void SetDeltaTime(float p_deltaTime);

	void VolleyCollisionChecks(VolleyManager* p_volleymanager, PlayerManager* p_playerManager);

private:
	bool OBBOBBTest(OBB p_OBB1, OBB p_OBB2);
	bool BoxBoxTest(Box p_box1, Box p_box2);
	bool SphereSphereTest(Sphere p_spikeTrap, Sphere p_player);
	bool OBBSphereTest(OBB p_OBB, Sphere p_sphere);
	bool IntersectingObjectWhenAttacking(DirectX::XMFLOAT3 p_attackingPlayerPos, DirectX::XMFLOAT3 p_defendingPlayerPos);
	bool RayOBBTest(Ray *p_ray, OBB p_Obb);
	bool RaySphereTest(Ray *p_ray, Sphere p_sphere);

	static CollisionManager* m_instance;
	void SetLists(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList);
	std::vector<OBB> m_staticBoxList;
	std::vector<Sphere> m_staticSphereList;
	float m_deltaTime;

	struct NaginataStabAttacks
	{
		RakNet::RakNetGUID m_guid;
		float m_timer;
		bool m_performNaginataStabAttack;
	};
	std::vector<NaginataStabAttacks> m_performingStabAttackList;
};
#endif

