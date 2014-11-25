#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_

#include "Shuriken.h"
#include <vector>
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	bool Initialize();
	void Shutdown();

	void Update(double p_deltaTime);

	std::vector<Shuriken> GetListOfShurikens() const;
	void AddShuriken(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed);

private:
	std::vector<Shuriken> m_shurikens;
	
};

#endif

