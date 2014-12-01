#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_


#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "Shuriken.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	bool Initialize();
	void Shutdown();

	void Update(double p_deltaTime);
	void Render();

	std::vector<Shuriken> GetListOfShurikens() const;
	std::vector<Model> GetListOfStaticModels() const;
	void AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id);

	void AddStaticModel(Model model);
private:
	std::vector<Shuriken> m_shurikens;
	std::vector<Model> m_staticmodels;

	Model m_animatedCharacter;

	// unique ID for the network
	RakNet::NetworkIDManager m_networkIDManger;
	
};

#endif

