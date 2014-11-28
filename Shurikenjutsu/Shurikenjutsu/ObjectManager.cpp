#include "ObjectManager.h"


ObjectManager::ObjectManager(){}


ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize()
{
	/*m_plane.LoadModel("../Shurikenjutsu/Models/FloorShape.SSP");
	GraphicsEngine::AddInstanceBuffer(1);

	m_object.LoadModel("../Shurikenjutsu/Models/DecoratedObjectShape.SSP");
	GraphicsEngine::AddInstanceBuffer(3);*/

	

	DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(0.0f, 3.141592f / 2.0f, 0.0f);
	DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(0.0f, 0.0f, -2.0f);

	m_animatedCharacter.LoadModel("../Shurikenjutsu/Models/StickManAnimatedShape.SSP");
	translation = DirectX::XMFLOAT3(5.0f, 0.0f, 0.0f);
	m_animatedCharacter.Translate(translation);

	/*m_object.LoadModel("../Shurikenjutsu/Models/DecoratedObjectShape.SSP");
	m_object.Rotate(rotation);
	translation = DirectX::XMFLOAT3(0.0f, 0.0f, 2.0f);
	m_object.Translate(translation);*/

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
}

void ObjectManager::Render()
{
	//GraphicsEngine::Render(SHADERTYPE_INSTANCED, m_plane.GetMesh(), m_plane.GetVertexCount(), m_plane.GetWorldMatrix(), m_plane.GetTexture(), 0, m_plane.GetAnimation());
	//GraphicsEngine::Render(SHADERTYPE_INSTANCED, m_object.GetMesh(), m_object.GetVertexCount(), m_object.GetWorldMatrix(), m_object.GetTexture(), 1, m_object.GetAnimation());
	for (int i = 0; i < m_staticmodels.size(); i++)
	{
		GraphicsEngine::Render(SHADERTYPE_SCENE, m_staticmodels[i].GetMesh(), m_staticmodels[i].GetVertexCount(), m_staticmodels[i].GetWorldMatrix(), m_staticmodels[i].GetTexture(), m_staticmodels[i].GetNormalMap(), 0, m_staticmodels[i].GetAnimation());
	}
	GraphicsEngine::Render(SHADERTYPE_ANIMATED, m_animatedCharacter.GetMesh(), m_animatedCharacter.GetVertexCount(), m_animatedCharacter.GetWorldMatrix(), m_animatedCharacter.GetTexture(), m_animatedCharacter.GetNormalMap(), 0, m_animatedCharacter.GetAnimation());
}

std::vector<Shuriken> ObjectManager::GetListOfShurikens() const
{
	return m_shurikens;
}

void ObjectManager::AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	Shuriken tempShuriken;
	tempShuriken.Initialize(p_filepath, p_pos, p_dir, p_speed);
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
