#include "ObjectManager.h"


ObjectManager::ObjectManager(){}


ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize()
{
	return true;
}

void ObjectManager::Shutdown()
{
	m_shurikens.clear();
}

void ObjectManager::Update(double p_deltaTime)
{
	// Update all the shurikens
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].Update(p_deltaTime);
		if (m_shurikens[i].IsDead())
		{
			m_shurikens.erase(m_shurikens.begin()+i);
			i--;
		}
	}
}

std::vector<Shuriken> ObjectManager::GetListOfShurikens() const
{
	return m_shurikens;
}

void ObjectManager::AddShuriken(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	Shuriken tempShuriken;
	tempShuriken.Initialize(p_device, p_filepath, p_pos, p_dir, p_speed);
	m_shurikens.push_back(tempShuriken);
}
