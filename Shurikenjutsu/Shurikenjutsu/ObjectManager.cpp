#include "ObjectManager.h"


ObjectManager::ObjectManager(){}


ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize()
{
	DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(0.0f, 3.141592f / 2.0f, 0.0f);
	DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(0.0f, 0.0f, -2.0f);

	m_animatedCharacter.LoadModel("../Shurikenjutsu/Models/StickManAnimatedShape.SSP");
	translation = DirectX::XMFLOAT3(5.0f, 0.0f, 0.0f);
	m_animatedCharacter.Translate(translation);

	

	return true;
}

void ObjectManager::Shutdown()
{
	m_shurikens.clear();
}

void ObjectManager::Update(double p_deltaTime)
{
	m_animatedCharacter.Update(p_deltaTime);

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
	unsigned int storlek = m_shurikens.size();
	std::vector<ShurikenNet> tempNetShurikens = Network::GetShurikens();
	for (unsigned int i = 0; i < tempNetShurikens.size(); i++)
	{
			if (!isShurikenInList(tempNetShurikens[i].guid, tempNetShurikens[i].shurikenId))
			{
				AddShuriken("../Shurikenjutsu/Models/shurikenShape.SSP", DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), 10, tempNetShurikens[i].shurikenId, tempNetShurikens[i].guid);
			}		
	}
}

void ObjectManager::Render()
{
	GraphicsEngine::BeginRenderToShadowMap();

	for (unsigned int i = 0; i < m_staticmodels.size(); i++)
	{
		GraphicsEngine::Render(SHADERTYPE_DEPTH, m_staticmodels[i].GetMesh(), m_staticmodels[i].GetVertexCount(), m_staticmodels[i].GetWorldMatrix(), m_staticmodels[i].GetTexture());
	}

	GraphicsEngine::SetShadowMap();
	GraphicsEngine::ResetRenderTarget();

	for (unsigned int i = 0; i < m_staticmodels.size(); i++)
	{
		GraphicsEngine::Render(SHADERTYPE_SCENE, m_staticmodels[i].GetMesh(), m_staticmodels[i].GetVertexCount(), m_staticmodels[i].GetWorldMatrix(), m_staticmodels[i].GetTexture(), m_staticmodels[i].GetNormalMap(), 0, m_staticmodels[i].GetAnimation());
	}
	GraphicsEngine::Render(SHADERTYPE_ANIMATED, m_animatedCharacter.GetMesh(), m_animatedCharacter.GetVertexCount(), m_animatedCharacter.GetWorldMatrix(), m_animatedCharacter.GetTexture(), m_animatedCharacter.GetNormalMap(), 0, m_animatedCharacter.GetAnimation());
}

std::vector<Shuriken> ObjectManager::GetListOfShurikens() const
{
	return m_shurikens;
}

void ObjectManager::AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id, RakNet::RakNetGUID p_guid)
{
	Shuriken tempShuriken;
	tempShuriken.Initialize(p_filepath, p_pos, p_dir, p_speed, p_id, p_guid);
	//tempShuriken.AddNetworkShuriken(p_pos.x, p_pos.y, p_pos.z, p_dir.x, p_dir.y, p_dir.z, 0);
	m_shurikens.push_back(tempShuriken);
}

std::vector<Model> ObjectManager::GetListOfStaticModels() const
{
	return m_staticmodels;
}

void ObjectManager::AddStaticModel(Model model)
{
	m_staticmodels.push_back(model);
}

bool ObjectManager::isShurikenInList(RakNet::RakNetGUID p_guid, unsigned int p_shurikenId)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (p_shurikenId == m_shurikens[i].m_shurikenID && Network::GetMyGUID() == Network::GetMyGUID())//m_shurikens[i].m_guid)
		{
			return true;
		}
	}

	return false;
}