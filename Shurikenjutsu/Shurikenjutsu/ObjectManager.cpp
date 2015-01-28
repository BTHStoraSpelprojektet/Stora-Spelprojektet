#include "ObjectManager.h"
#include "Flags.h"
#include "Network.h"
#include "Frustum.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "SmokeBomb.h"
#include "Spikes.h"

ObjectManager::ObjectManager(){}
ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize(Level* p_level)
{
	// Load objects on the level
	std::vector<LevelImporter::CommonObject> levelObjects = p_level->GetObjects();

	//Stuff needed for the loop
	std::vector<DirectX::XMFLOAT4X4> modelPositions;
	modelPositions.clear();
	int numberOfSameModel = 0;
	std::string prevModelFileName = levelObjects[0].m_filePath;

	Object object;
	object.Initialize(levelObjects[0].m_filePath.c_str(),
		DirectX::XMFLOAT3(levelObjects[0].m_translationX, levelObjects[0].m_translationY, levelObjects[0].m_translationZ),
		DirectX::XMFLOAT3(levelObjects[0].m_rotationX, levelObjects[0].m_rotationY, levelObjects[0].m_rotationZ),
		DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	AddStaticObject(object);
	
	numberOfSameModel++;//Räknar antaler modeller...
	modelPositions.push_back(m_staticObjects[0].GetWorldMatrix());//Pushbackar antalet positioner
	for (unsigned int i = 1; i < levelObjects.size(); i++)
	{		
		if (prevModelFileName != levelObjects[i].m_filePath)
		{
			GraphicsEngine::AddInstanceBuffer(numberOfSameModel, modelPositions);
			//Reset for new type of model
			numberOfSameModel = 0;
			modelPositions.clear();
		}

		Object object;
		object.Initialize(levelObjects[i].m_filePath.c_str(),
			DirectX::XMFLOAT3(levelObjects[i].m_translationX, levelObjects[i].m_translationY, levelObjects[i].m_translationZ),
			DirectX::XMFLOAT3(levelObjects[i].m_rotationX, levelObjects[i].m_rotationY, levelObjects[i].m_rotationZ),
			DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
		AddStaticObject(object);

		numberOfSameModel++;//Räknar antaler modeller...		
		prevModelFileName = levelObjects[i].m_filePath;//Tar nästa filväg inför nästa jämnförelse
		modelPositions.push_back(m_staticObjects[i].GetWorldMatrix());//Pushbackar antalet positioner
	}

	m_staticObjects[m_staticObjects.size()-1].CreateInstanceBuffer(numberOfSameModel, modelPositions);
	return true;
}

void ObjectManager::Shutdown()
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i]->Shutdown();
		delete m_shurikens[i];
	}
	m_shurikens.clear();

	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		m_staticObjects[i].Shutdown();
	}
	m_staticObjects.clear();

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i]->Shutdown();
		delete m_smokeBombList[i];
	}
	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		m_spikeTrapList[i]->Shutdown();
		delete m_spikeTrapList[i];
	}	
}

void ObjectManager::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	// Update all the shurikens
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i]->Update();
	}	

	// Update all the smokebombs
	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i]->Update();

		if (!m_smokeBombList[i]->GetIfActive())
		{
			// Remove Smoke bomb
			m_smokeBombList[i]->Shutdown();
			delete m_smokeBombList[i];
			m_smokeBombList.erase(m_smokeBombList.begin() + i);
			i--;
		}
	}

	// Update all the spikes
	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		m_spikeTrapList[i]->Update();

		if (!m_spikeTrapList[i]->GetIsAlive())
		{
			// Remove Spike Trap
			m_spikeTrapList[i]->Shutdown();
			delete m_spikeTrapList[i];
			m_spikeTrapList.erase(m_spikeTrapList.begin() + i);
			i--;
		}
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
					AddShuriken("../Shurikenjutsu/Models/MegaShurikenShape.SSP", DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), MEGASHURIKEN_SPEED, tempNetShurikens[i].shurikenId);
				}
				else
				{
					// Add shuriken
					AddShuriken("../Shurikenjutsu/Models/shurikenShape.SSP", DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), SHURIKEN_SPEED, tempNetShurikens[i].shurikenId);
				}
			}
		}

		for (unsigned int i = 0; i < m_shurikens.size(); i++)
		{
			if (!IsShurikenInNetworkList(m_shurikens[i]->GetID()))
			{
				// Remove shuriken
				m_shurikens[i]->Shutdown();
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
				AddSmokeBomb(tempSmokeBomb[i].startX, tempSmokeBomb[i].startZ, tempSmokeBomb[i].endX, tempSmokeBomb[i].endZ, tempSmokeBomb[i].smokeBombId);
			}
		}
		Network::GetInstance()->SetHaveUpdateSmokeBombList();
	}

	///
	if (Network::GetInstance()->IsSpikeTrapListUpdated())
	{
		std::vector<SpikeNet> tempSpikeTrapList = Network::GetInstance()->GetSpikeTraps();
		std::vector<Spikes> spikeTrapList;
		for (unsigned int i = 0; i < tempSpikeTrapList.size(); i++)
		{
			if (!IsSpikeTrapInList(tempSpikeTrapList[i].spikeId))
			{
				// Add Smoke bomb
				AddSpikeTrap(tempSpikeTrapList[i].startX, tempSpikeTrapList[i].startZ, tempSpikeTrapList[i].endX, tempSpikeTrapList[i].endZ, tempSpikeTrapList[i].spikeId);
			}
		}
		Network::GetInstance()->SetHaveUpdateSpikeTrapList();
	}
	////
}

void ObjectManager::Render()
{
	m_objectsToRender.clear();
	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		if (m_frustum->CheckSphere(m_staticObjects[i].GetFrustumSphere(), 5.5f))
		{
			if (CheckIfModelIsInObjectToRenderList(&m_staticObjects[i]))
			{
				m_objectsToRender.push_back(&m_staticObjects[i]);
				m_staticObjects[i].RenderInstanced();
			}
		}
	}

	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (m_frustum->CheckSphere(m_shurikens[i]->GetFrustumSphere(), 1.0f))
		{
			m_shurikens[i]->Render();
		}
	}
	
	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		if (m_frustum->CheckSphere(m_smokeBombList[i]->GetSmokeSphere(), 2.0f))
		{
			m_smokeBombList[i]->Render();
		}
	}

	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		if (m_frustum->CheckSphere(m_spikeTrapList[i]->GetSpikeSphere(), 2.0f))
		{
			m_spikeTrapList[i]->Render();
		}
	}
}

void ObjectManager::RenderDepth()
{
	m_objectsToShadowRender.clear();
	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		Sphere sphere = m_staticObjects[i].GetFrustumSphere();
		sphere.m_position.x -= 3.0f;
		sphere.m_position.z -= 3.0f;
		if (m_frustum->CheckSphere(sphere, 7.5f))
		{
			if (CheckIfModelIsInObjectToShadowRenderList(&m_staticObjects[i]))
			{
				m_objectsToShadowRender.push_back(&m_staticObjects[i]);
				m_staticObjects[i].RenderDepthInstanced();
			}
		}
	}

	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i]->RenderDepth();
	}

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i]->GetBomb()->RenderDepth();
	}

	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		m_spikeTrapList[i]->GetSpikesBag()->RenderDepth();
	}

}

void ObjectManager::AddShuriken(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_shurikenID)
{
	Shuriken *tempShuriken;
	tempShuriken = new Shuriken();
	tempShuriken->Initialize(p_filepath, p_pos, p_dir, p_shurikenID);
	tempShuriken->SetSpeed(p_speed);
	m_shurikens.push_back(tempShuriken);
}

void ObjectManager::AddSmokeBomb(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_smokeBombID)
{
	SmokeBomb *tempSmokeBomb;
	tempSmokeBomb = new SmokeBomb();
	tempSmokeBomb->Initialize(DirectX::XMFLOAT3(p_startPosX, 0.0f, p_startPosZ), DirectX::XMFLOAT3(p_endPosX, 0.0f, p_endPosZ), p_smokeBombID);
	tempSmokeBomb->ResetTimer();
	m_smokeBombList.push_back(tempSmokeBomb);
}

void ObjectManager::AddSpikeTrap(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_smokeBombID)
{
	Spikes *tempSpikeTrap;
	tempSpikeTrap = new Spikes();
	tempSpikeTrap->Initialize(DirectX::XMFLOAT3(p_startPosX, 0.01f, p_startPosZ), DirectX::XMFLOAT3(p_endPosX, 0.01f, p_endPosZ), p_smokeBombID);
	tempSpikeTrap->ResetTimer();
	m_spikeTrapList.push_back(tempSpikeTrap);
}

void ObjectManager::AddStaticObject(Object p_object)
{
	m_staticObjects.push_back(p_object);
}

bool ObjectManager::IsShurikenInList(unsigned int p_shurikenId)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (p_shurikenId == m_shurikens[i]->GetID())
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
		if (p_smokeBombId == m_smokeBombList[i]->GetID())
		{
			return true;
		}
	}

	return false;
}

bool ObjectManager::IsSpikeTrapInList(unsigned int p_spikeTrapId)
{
	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		if (p_spikeTrapId == m_spikeTrapList[i]->GetID())
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
	m_frustum = p_frustum;
}

bool ObjectManager::CheckIfModelIsInObjectToRenderList(Object *p_object)
{
	for (unsigned int i = 0; i < m_objectsToRender.size(); i++)
	{
		if (m_objectsToRender[i]->GetModel() == p_object->GetModel())
		{
			return false;
		}
	}
	return true;
}

bool ObjectManager::CheckIfModelIsInObjectToShadowRenderList(Object *p_object)
{
	for (unsigned int i = 0; i < m_objectsToShadowRender.size(); i++)
	{
		if (m_objectsToShadowRender[i]->GetModel() == p_object->GetModel())
		{
			return false;
		}
	}
	return true;
}