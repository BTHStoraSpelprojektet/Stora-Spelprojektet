#include "ObjectManager.h"


ObjectManager::ObjectManager(){}


ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize()
{

}

void ObjectManager::Shutdown()
{

}

void ObjectManager::Update(double p_deltaTime)
{

}

std::vector<Shuriken> ObjectManager::GetListOfShurikens(int i) const
{
	return m_shurikens;
}

void ObjectManager::AddShuriken(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	Shuriken tempShuriken;
	tempShuriken.Initialize(p_device, p_filepath, p_pos, p_dir, p_speed);
	m_shurikens.push_back(tempShuriken);
}
