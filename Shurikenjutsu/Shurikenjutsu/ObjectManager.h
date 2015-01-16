#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_


#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "Shuriken.h"
#include "AnimatedObject.h"
#include "SmokeBomb.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	bool Initialize();
	void Shutdown();

	void Update();
	void Render();
	void RenderDepth();

	void AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, unsigned int p_shurikenID);
	void AddSmokeBomb(float p_xPos, float p_zPos, unsigned int p_smokeBombID);

	void AddStaticObject(Object p_object);
	std::vector<Object> GetStaticObjectList()const;

private:
	std::vector<SmokeBomb> m_smokeBombList;
	std::vector<Shuriken> m_shurikens;
	std::vector<Object> m_staticObjects;

	bool IsShurikenInList(unsigned int p_shurikenId);
	bool IsShurikenInNetworkList(unsigned int p_shurikenId);
	bool IsSmokeBombInList(unsigned int p_shurikenId);
};
#endif