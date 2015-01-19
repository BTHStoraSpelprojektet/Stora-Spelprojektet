#include "ObjectManager.h"


ObjectManager::ObjectManager(){}
ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize()
{
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

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i].Shutdown();
}

}

void ObjectManager::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	// Update all the shurikens
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].Update();
	}	

	// Update all the smokebombs
	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i].Update();
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
					AddShuriken("../Shurikenjutsu/Models/MegaShurikenShape.SSP", DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), tempNetShurikens[i].shurikenId);
				}
				else
				{
					// Add shuriken
					AddShuriken("../Shurikenjutsu/Models/shurikenShape.SSP", DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), tempNetShurikens[i].shurikenId);
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

	if (Network::GetInstance()->IsSmokeBombListUpdated())
	{
		std::vector<SmokeBombNet> tempSmokeBomb = Network::GetInstance()->GetSmokeBombs();
		std::vector<SmokeBomb> smokeBombList;
		for (unsigned int i = 0; i < tempSmokeBomb.size(); i++)
		{
			if (!IsSmokeBombInList(tempSmokeBomb[i].smokeBombId))
			{
				// Add Smoke bomb
				AddSmokeBomb(tempSmokeBomb[i].x, tempSmokeBomb[i].z, tempSmokeBomb[i].smokeBombId);
			}
		}
		for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
		{
			if (!m_smokeBombList[i].GetIfActive())
			{
				// Remove Smoke bomb
				m_smokeBombList[i].Shutdown();
				m_smokeBombList.erase(m_smokeBombList.begin() + i);
				i--;
			}
		}
		Network::GetInstance()->SetHaveUpdateSmokeBombList();
	}
}

void ObjectManager::Render()
{
	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		if (m_frustum.CheckSphere(m_staticObjects[i].GetFrustumSphere(), 5.5f))
		{
			m_staticObjects[i].Render();

			if (FLAG_DEBUG)
			{
				m_staticObjects[i].RenderDebugBoxes();
			}
		}
	}

	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (m_frustum.CheckSphere(m_shurikens[i].GetFrustumSphere(), 1.0f))
		{
			m_shurikens[i].Render();
		}
	}

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		if (m_frustum.CheckSphere(m_smokeBombList[i].GetSmokeSphere(), 2.0f))
		{
			m_smokeBombList[i].Render();
		}
	}
}

void ObjectManager::RenderDepth()
{
	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		Sphere sphere = m_staticObjects[i].GetFrustumSphere();
		sphere.m_position.x += 2.0f;
		sphere.m_position.z += 2.0f;
		if (m_frustum.CheckSphere(sphere, 7.5f))
		{
			m_staticObjects[i].RenderDepth();
		}
	}
}

void ObjectManager::AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, unsigned int p_shurikenID)
{
	Shuriken tempShuriken;
	tempShuriken.Initialize(p_filepath, p_pos, p_dir, p_shurikenID);
	m_shurikens.push_back(tempShuriken);
}

void ObjectManager::AddSmokeBomb(float p_xPos, float p_zPos, unsigned int p_smokeBombID)
{
	SmokeBomb tempSmokeBomb;
	tempSmokeBomb.Initialize(DirectX::XMFLOAT3(p_xPos, 0.0f, p_zPos), p_smokeBombID);
	tempSmokeBomb.ResetTimer();
	m_smokeBombList.push_back(tempSmokeBomb);
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
bool ObjectManager::IsSmokeBombInList(unsigned int p_smokeBombId)
{
	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		if (p_smokeBombId == m_smokeBombList[i].GetID())
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

void ObjectManager::UpdateFrustum(Frustum* p_frustum)
{
	m_frustum = *p_frustum;
}