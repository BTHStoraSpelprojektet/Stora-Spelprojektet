#ifndef PROJECTILEMANAGER_H_
#define PROJECTILEMANAGER_H_

#include "../CommonLibs/RakNet/RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerGlobals.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "..\CommonLibs\CommonStructures.h"

#include <vector>

class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);
	void AddProjectile(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ, int p_ability);
	void RemoveProjectile(unsigned int p_id);
	void BroadcastDestoyedProjectile(unsigned int p_id);
	void UpdateProjectiles(double p_deltaTime);
	std::vector<ProjectileNet> GetProjectiles();
	std::vector<Box> GetKunaiBoundingBoxes(int p_index);
	float GetProjectilePosX(int p_index);
	float GetProjectilePosY(int p_index);
	float GetProjectilePosZ(int p_index);
private:
	unsigned int GetProjectileUniqueId();


	RakNet::RakPeerInterface *m_serverPeer;

	std::vector<ProjectileNet> m_projectiles;

	std::vector<Box> m_shurikenBoundingBoxes;
	std::vector<Box> m_megaShurikenBoundingBoxes;
	std::vector<Box> m_kunaiBoundingBoxes;
};

#endif // !PROJECTILEMANAGER_H_


