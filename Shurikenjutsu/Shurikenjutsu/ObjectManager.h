#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_


#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "Shuriken.h"
#include "AnimatedObject.h"
#include "..\CommonLibs\Level.h"
#include "../CommonLibs/RakNet/RakNetTypes.h"

class Frustum;
class SmokeBomb;
class Spikes;
class FanBoomerang;
class Projectile;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	bool Initialize(Level* p_level);
	void Shutdown();

	void Update();
	void Render();
	void RenderDepth();

	void AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_shurikenID);
	void AddSmokeBomb(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_smokeBombID);
	void AddSpikeTrap(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_spikeTrapID);
	void AddStaticObject(Object p_object);
	std::vector<Object> GetStaticObjectList()const;

	void AddFan(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id);

	void UpdateFrustum(Frustum* p_frustum);

	void AddProjectile(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid, float p_speed, int p_ability);

	void UpdateRenderLists();

private:
	bool CheckIfObjectIsInList(Object *p_object, std::vector<Object*> p_list);
	std::vector<Object*> CheckAmountOfSameModels(Object *p_object, std::vector<Object*> p_list);

	std::vector<SmokeBomb*> m_smokeBombList;
	std::vector<Spikes*> m_spikeTrapList;
	std::vector<Shuriken*> m_shurikens;
	std::vector<Projectile*> m_projectiles;
	std::vector<FanBoomerang*> m_fans;
	std::vector<Object> m_staticObjects;
	std::vector<AnimatedObject*> m_animatedObjects;
	std::vector<Object*> m_objectsToInstanceRender;
	std::vector<Object*> m_objectsToSingleRender;
	

	Frustum* m_frustum;

	bool IsShurikenInList(unsigned int p_shurikenId);
	bool IsShurikenInNetworkList(unsigned int p_shurikenId);
	bool IsSmokeBombInList(unsigned int p_smokeBombId);
	bool IsSpikeTrapInList(unsigned int p_spikeTrapId);
	bool IsFanInList(unsigned int p_fanId);
	bool IsFanInNetworkList(unsigned int p_fanId);
};
#endif