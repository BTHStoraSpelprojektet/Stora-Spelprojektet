#include "ObjectManager.h"


ObjectManager::ObjectManager(){}


ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize()
{
	DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(0.0f, 3.141592f / 2.0f, 0.0f);
	DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(0.0f, 0.0f, -2.0f);

	return true;
}

void ObjectManager::Shutdown()
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].Shutdown();
	}
	m_shurikens.clear();

	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		m_staticObjects[i].Shutdown();
	}
	m_staticObjects.clear();
}

void ObjectManager::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	//m_animatedCharacter.Update(p_deltaTime);

	// Update all the shurikens
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].Update();
	}

	if (Network::GetInstance()->IsShurikenListUpdated())
	{
		std::vector<ShurikenNet> tempNetShurikens = Network::GetInstance()->GetShurikens();
		for (unsigned int i = 0; i < tempNetShurikens.size(); i++)
		{
			if (!IsShurikenInList(tempNetShurikens[i].shurikenId))
			{
				if (tempNetShurikens[i].megaShuriken)
				{
					// Add Mega shuriken
					AddShuriken("../Shurikenjutsu/Models/MegaShurikenShape.SSP", DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), tempNetShurikens[i].speed, tempNetShurikens[i].shurikenId);
				}
				else
				{
					// Add shuriken
					AddShuriken("../Shurikenjutsu/Models/shurikenShape.SSP", DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), tempNetShurikens[i].speed, tempNetShurikens[i].shurikenId);
				}
				
			}
		}

		for (unsigned int i = 0; i < m_shurikens.size(); i++)
		{
			if (!IsShurikenInNetworkList(m_shurikens[i].GetID()))
			{
				// Remove shuriken
				m_shurikens[i].Shutdown();
				m_shurikens.erase(m_shurikens.begin() + i);
				i--;
			}
		}
		Network::GetInstance()->SetHaveUpdateShurikenList();
	}
}

void ObjectManager::Render(SHADERTYPE p_shader)
{
	if (p_shader == SHADERTYPE_SCENE || p_shader == SHADERTYPE_DEPTH)
	{
		for (unsigned int i = 0; i < m_staticObjects.size(); i++)
		{
			m_staticObjects[i].Render(p_shader);

			if (FLAG_DEBUG)
			{
				m_staticObjects[i].RenderDebugBoxes(); 
			}
		}
	}
}

void ObjectManager::RenderShurikens(SHADERTYPE p_shader)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].Render(p_shader);
	}
}

void ObjectManager::AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_shurikenID)
{
	Shuriken tempShuriken;
	tempShuriken.Initialize(p_filepath, p_pos, p_dir, p_speed, p_shurikenID);
	m_shurikens.push_back(tempShuriken);
}

void ObjectManager::AddStaticObject(Object p_object)
{
	m_staticObjects.push_back(p_object);
}

bool ObjectManager::IsShurikenInList(unsigned int p_shurikenId)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (p_shurikenId == m_shurikens[i].GetID())
		{
			return true;
		}
	}

	return false;
}

bool ObjectManager::IsShurikenInNetworkList(unsigned int p_shurikenId)
{
	std::vector<ShurikenNet> shurikenList = Network::GetInstance()->GetShurikens();

	for (unsigned int i = 0; i < shurikenList.size(); i++)
	{
		if (p_shurikenId == shurikenList[i].shurikenId)
		{
			return true;
		}
	}

	return false;
}

std::vector<Object> ObjectManager::GetStaticObjectList()const
{
	return m_staticObjects;
}