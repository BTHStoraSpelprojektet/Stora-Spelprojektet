#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_

#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "Shuriken.h"
#include "AnimatedObject.h"
#include "..\CommonLibs\Level.h"
#include "../CommonLibs/RakNet/RakNetTypes.h"
#include "Trail.h"

class Volley;
class Frustum;
class SmokeBomb;
class Spikes;
class FanBoomerang;
class Projectile;
class StickyTrap;
class ParticleEmitter;
class Sound;
class PointOfInterestManager;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	bool Initialize(Level* p_level);
	void Shutdown();
	void ShutdownExit();

	void Update();
	void Render();
	void RenderAnimated();
	void RenderDepth();
	void RenderAnimatedDepth();

	void AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_shurikenID);
	void AddSmokeBomb(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_smokeBombID);
	void AddSpikeTrap(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_spikeTrapID, int p_team);
	void AddStickyTrap(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_spikeTrapID, RakNet::RakNetGUID p_guid);
	void AddVolley(unsigned int p_id, float p_startX, float p_startZ, float p_endX, float p_endZ, RakNet::RakNetGUID p_guid);
	void AddFan(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id, RakNet::RakNetGUID p_owner);
	void AddStaticObject(Object p_object);
	std::vector<Object> GetStaticObjectList()const;
	std::vector<AnimatedObject*> GetAnimatedObjectList()const;
	
	void UpdateFrustum(Frustum* p_frustum);

	void AddProjectile(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid, float p_speed, int p_ability);
	void RemoveProjectile(unsigned int p_projId);

	void UpdateRenderLists();

	std::vector<StickyTrap*> GetStickyTrapList();

	void AddBloodSpots(DirectX::XMFLOAT3 p_pos);
	
	void SetSound(Sound* p_sound);

	void SpawnRunes(POINTOFINTERESTTYPE p_poiType, float p_x, float p_y, float p_z);
	void RunePickedUp(POINTOFINTERESTTYPE p_poiType, RakNet::RakNetGUID p_guid);
	void RunesRestartRound();

private:
	float CheckStickyTrapYPosition();
	bool CheckIfObjectIsInList(Object *p_object, std::vector<Object*> p_list);
	std::vector<Object*> CheckAmountOfSameModels(Object *p_object, std::vector<Object*> p_list);
	void ResetListSinceRoundRestarted();
	
	std::vector<SmokeBomb*> m_smokeBombList;
	std::vector<Spikes*> m_spikeTrapList;
	std::vector<StickyTrap*> m_stickyTrapList;
	std::vector<Shuriken*> m_shurikens;
	std::vector<Projectile*> m_projectiles;
	std::vector<FanBoomerang*> m_fans;
	std::vector<Object> m_staticObjects;
	std::vector<AnimatedObject*> m_animatedObjects;
	std::vector<ParticleEmitter*> m_worldParticles;
	std::vector<Object*> m_objectsToInstanceRender;
	std::vector<Object*> m_objectsToSingleRender;
	std::vector<Volley*> m_volleys;
	std::vector<ParticleEmitter*> m_bloodParticles;
	std::vector<float> m_bloodParticlesTimer;

	bool IsShurikenInList(unsigned int p_shurikenId);
	bool IsShurikenInNetworkList(unsigned int p_shurikenId);
	bool IsSmokeBombInList(unsigned int p_smokeBombId);
	bool IsSpikeTrapInList(unsigned int p_spikeTrapId);
	bool IsStickyTrapInList(unsigned int p_stickyeTrapId);
	bool IsFanInList(unsigned int p_fanId);
	bool IsFanInNetworkList(unsigned int p_fanId);

	Frustum* m_frustum;

	Sound* m_sound;

	std::vector<Trail*> m_shurikenTrails;
	std::vector<Trail*> m_fanTrails;
	std::vector<Trail*> m_kunaiTrails;
	std::vector<std::vector<Trail*>> m_volleyTrails;

	PointOfInterestManager* m_POIManager;
};
#endif