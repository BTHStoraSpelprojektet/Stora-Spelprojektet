#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_


#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "Shuriken.h"
#include "AnimatedObject.h"
#include "..\CommonLibs\Level.h"

class Frustum;
class SmokeBomb;
class Spikes;

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

	void UpdateFrustum(Frustum* p_frustum);
private:
	bool CheckIfObjectIsInList(Object *p_object, std::vector<Object*> p_list);
	std::vector<Object*> CheckAmountOfSameModels(Object *p_object, std::vector<Object*> p_list);
	void UpdateRenderLists();

	std::vector<SmokeBomb*> m_smokeBombList;
	std::vector<Spikes*> m_spikeTrapList;
	std::vector<Shuriken*> m_shurikens;
	std::vector<Object> m_staticObjects;
	std::vector<Object*> m_objectsToInstanceRender;
	std::vector<Object*> m_objectsToSingleRender;
	

	Frustum* m_frustum;

	bool IsShurikenInList(unsigned int p_shurikenId);
	bool IsShurikenInNetworkList(unsigned int p_shurikenId);
	bool IsSmokeBombInList(unsigned int p_smokeBombId);
	bool IsSpikeTrapInList(unsigned int p_spikeTrapId);
};
#endif