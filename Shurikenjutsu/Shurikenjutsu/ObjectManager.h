#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_


#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "Shuriken.h"
#include "AnimatedObject.h"
#include "SmokeBomb.h"
#include "Frustum.h"
#include "..\CommonLibs\Level.h"

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

	void AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, unsigned int p_shurikenID);
	void AddSmokeBomb(float p_xPos, float p_zPos, unsigned int p_smokeBombID);

	void AddStaticObject(Object p_object);
	std::vector<Object> GetStaticObjectList()const;

	void UpdateFrustum(Frustum* p_frustum);
private:
	std::vector<SmokeBomb> m_smokeBombList;
	std::vector<Shuriken> m_shurikens;
	std::vector<Object> m_staticObjects;
	std::vector<Object> m_objectsToRender;

	Frustum m_frustum;

	bool IsShurikenInList(unsigned int p_shurikenId);
	bool IsShurikenInNetworkList(unsigned int p_shurikenId);
	bool IsSmokeBombInList(unsigned int p_shurikenId);
};
#endif