#include "ObjectManager.h"
#include "Flags.h"
#include "Network.h"
#include "Frustum.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "SmokeBomb.h"
#include "Spikes.h"
#include "..\CommonLibs\ModelNames.h"
#include "FanBoomerang.h"
#include "Projectile.h"
#include "StickyTrap.h"
#include "Volley.h"
#include "ParticleEmitter.h"
#include "ConsoleFunctions.h"

ObjectManager::ObjectManager(){}
ObjectManager::~ObjectManager(){}

bool ObjectManager::Initialize(Level* p_level)
{	
	// Load objects on the level
	std::vector<LevelImporter::CommonObject> levelObjects = p_level->GetObjects();
	std::vector<LevelImporter::AnimatedObject> animatedLevelObjects = p_level->GetAnimatedObjects();
	std::vector<LevelImporter::ParticleEmitter> particleLevelEmitter = p_level->GetParticleEmitters();

	m_projectiles = std::vector<Projectile*>();

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
			GraphicsEngine::GetInstance()->AddInstanceBuffer(numberOfSameModel, modelPositions);
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

	m_animatedObjects.clear();
	for (unsigned int i = 0; i < animatedLevelObjects.size(); i++)
	{
		AnimatedObject* animObject = new AnimatedObject();

		animObject->Initialize(animatedLevelObjects[i].m_filePath.c_str(),
			DirectX::XMFLOAT3(animatedLevelObjects[i].m_translationX, animatedLevelObjects[i].m_translationY, animatedLevelObjects[i].m_translationZ),
			DirectX::XMFLOAT3(animatedLevelObjects[i].m_rotationX, animatedLevelObjects[i].m_rotationY, animatedLevelObjects[i].m_rotationZ),
			DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

		m_animatedObjects.push_back(animObject);
	}

	for (unsigned int i = 0; i < particleLevelEmitter.size(); i++)
	{
		ParticleEmitter* particleEmitter = new ParticleEmitter();

		if (particleLevelEmitter[i].type == EmitterType::BrazierFire){
		particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0, 1, 0),
				DirectX::XMFLOAT2(PARTICLE_FIRE_SIZE_X, PARTICLE_FIRE_SIZE_Y), PARTICLE_PATTERN_FIRE);
		}
		else if (particleLevelEmitter[i].type == EmitterType::FireSpark){
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0, 1, 0),
				DirectX::XMFLOAT2(PARTICLE_FIRE_SPARK_SIZE_X, PARTICLE_FIRE_SPARK_SIZE_Y), PARTICLE_PATTERN_FIRE_SPARK);
		}
		else if (particleLevelEmitter[i].type == EmitterType::LeafSakura){
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0.15f, -1.0f, -0.25f),
				DirectX::XMFLOAT2(PARTICLE_PINKLEAF_SIZE_X, PARTICLE_PINKLEAF_SIZE_Y), PARTICLE_PATTERN_PINK_LEAVES);
		}
		else if (particleLevelEmitter[i].type == EmitterType::LeafTree){
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0.15f, -1.0f, -0.25f),
				DirectX::XMFLOAT2(PARTICLE_GREENLEAF_SIZE_X, PARTICLE_GREENLEAF_SIZE_Y), PARTICLE_PATTERN_GREEN_LEAVES);
		}
		else if (particleLevelEmitter[i].type == EmitterType::LeafAcerPalmatum){
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0.15f, -1.0f, -0.25f),
				DirectX::XMFLOAT2(PARTICLE_GREENLEAF_SIZE_X, PARTICLE_GREENLEAF_SIZE_Y), PARTICLE_PATTERN_ACERPALMATUM_LEAVES);
		}
		else if (particleLevelEmitter[i].type == EmitterType::WorldMist){
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0.15f, -1.0f, -0.25f),
				DirectX::XMFLOAT2(PARTICLE_WORLDMIST_SIZE_X, PARTICLE_WORLDMIST_SIZE_Y), PARTICLE_PATTERN_WORLD_MIST);
		}
		else if (particleLevelEmitter[i].type == EmitterType::WorldDust){
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0.15f, -1.0f, -0.25f),
				DirectX::XMFLOAT2(PARTICLE_WORLDDUST_SIZE_X, PARTICLE_WORLDDUST_SIZE_Y), PARTICLE_PATTERN_WORLD_DUST);
		}
		else if (particleLevelEmitter[i].type == EmitterType::Fireflies){
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0.15f, -1.0f, -0.25f),
				DirectX::XMFLOAT2(PARTICLE_FIREFLIES_SIZE_X, PARTICLE_FIREFLIES_SIZE_Y), PARTICLE_PATTERN_FIREFLIES);
		}
		else{
			particleEmitter->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(particleLevelEmitter[i].m_translationX, particleLevelEmitter[i].m_translationY, particleLevelEmitter[i].m_translationZ),
				DirectX::XMFLOAT3(0, 1, 0),
				DirectX::XMFLOAT2(SMOKEBOMB_SIZE_X, SMOKEBOMB_SIZE_Y), PARTICLE_PATTERN_SMOKE);
		}
		particleEmitter->SetEmitParticleState(true);
		m_worldParticles.push_back(particleEmitter);
	}

	m_shurikenTrails.clear();

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

	for (unsigned int i = 0; i < m_animatedObjects.size(); i++)
	{
		m_animatedObjects[i]->Shutdown();
		delete m_animatedObjects[i];
	}
	m_animatedObjects.clear();

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i]->Shutdown();
		delete m_smokeBombList[i];
	}
	m_smokeBombList.clear();

	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		m_spikeTrapList[i]->Shutdown();
		delete m_spikeTrapList[i];
	}
	m_spikeTrapList.clear();

	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		m_fans[i]->Shutdown();
		delete m_fans[i];
	}
	m_fans.clear();

	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->Shutdown();
		delete m_projectiles[i];
		m_projectiles[i] = nullptr;
	}
	m_projectiles.clear();

	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		m_stickyTrapList[i]->Shutdown();
		delete m_stickyTrapList[i];
	}
	m_stickyTrapList.clear();

	for (unsigned int i = 0; i < m_worldParticles.size(); i++)
	{
		m_worldParticles[i]->Shutdown();
		delete m_worldParticles[i];
	}
	m_worldParticles.clear();

	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		m_volleys[i]->Shutdown();
		delete m_volleys[i];
	}
	m_volleys.clear();

	if (m_shurikenTrails.size() > 0)
	{
		for (unsigned int i = 0; i < m_shurikenTrails.size(); i++)
		{
			m_shurikenTrails[i]->Shutdown();
		}

		m_shurikenTrails.clear();
	}
}

void ObjectManager::ShutdownExit()
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i]->ShutdownGameExit();
		delete m_shurikens[i];
	}
	m_shurikens.clear();

	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		m_staticObjects[i].ShutdownGameExit();
	}
	m_staticObjects.clear();

	for (unsigned int i = 0; i < m_animatedObjects.size(); i++)
	{
		m_animatedObjects[i]->ShutdownGameExit();
		delete m_animatedObjects[i];
	}
	m_animatedObjects.clear();

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		//m_smokeBombList[i]->ShutdownGameExit();
		delete m_smokeBombList[i];
	}
	m_smokeBombList.clear();

	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		//m_spikeTrapList[i]->ShutdownGameExit();
		delete m_spikeTrapList[i];
	}
	m_spikeTrapList.clear();

	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		m_fans[i]->ShutdownGameExit();
		delete m_fans[i];
	}
	m_fans.clear();

	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->ShutdownGameExit();
		delete m_projectiles[i];
		m_projectiles[i] = nullptr;
	}
	m_projectiles.clear();

	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		//m_stickyTrapList[i]->ShutdownGameExit();
		delete m_stickyTrapList[i];
	}
	m_stickyTrapList.clear();

	for (unsigned int i = 0; i < m_worldParticles.size(); i++)
	{
		//m_worldParticles[i]->ShutdownGameExit();
		delete m_worldParticles[i];
	}
	m_worldParticles.clear();

	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		//m_volleys[i]->ShutdownGameExit();
		delete m_volleys[i];
	}
	m_volleys.clear();
}

void ObjectManager::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	if (Network::GetInstance()->RoundRestarted())
	{
		ResetListSinceRoundRestarted();
	}

	// Update all the shurikens
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i]->Update();
	}	

	// Update projectiles
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->Update();
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

	// Update all the spikes
	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		m_stickyTrapList[i]->Update();

		if (!m_stickyTrapList[i]->GetIsAlive())
		{
			// Remove Spike Trap
			m_stickyTrapList[i]->Shutdown();
			delete m_stickyTrapList[i];
			m_stickyTrapList.erase(m_stickyTrapList.begin() + i);
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
					AddShuriken(MEGA_SHURIKEN_MODEL_NAME, DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), tempNetShurikens[i].speed, tempNetShurikens[i].shurikenId);

					Trail* trail = new Trail();
					DirectX::XMFLOAT4 color;

					if (Network::GetInstance()->GetTeam(tempNetShurikens[i].guid) == 1)
					{
						color = DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
					}
					else if (Network::GetInstance()->GetTeam(tempNetShurikens[i].guid) == 2)
					{
						color = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
					}
					
					if (!trail->Initialize(60.0f, 0.25f, 0.60f, color, "../Shurikenjutsu/2DTextures/Trail.png"))
					{
						ConsolePrintErrorAndQuit("A shuriken trail failed to initialize!");
					}

					m_shurikenTrails.push_back(trail);
				}
				else
				{
					// Add shuriken
					AddShuriken(SHURIKEN_MODEL_NAME, DirectX::XMFLOAT3(tempNetShurikens[i].x, tempNetShurikens[i].y, tempNetShurikens[i].z), DirectX::XMFLOAT3(tempNetShurikens[i].dirX, tempNetShurikens[i].dirY, tempNetShurikens[i].dirZ), tempNetShurikens[i].speed, tempNetShurikens[i].shurikenId);

					Trail* trail = new Trail();
					DirectX::XMFLOAT4 color;

					if (Network::GetInstance()->GetTeam(tempNetShurikens[i].guid) == 1)
					{
						color = DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
					}
					else if (Network::GetInstance()->GetTeam(tempNetShurikens[i].guid) == 2)
					{
						color = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
					}

					if(!trail->Initialize(40.0f, 0.2f, 0.1f, color, "../Shurikenjutsu/2DTextures/Trail.png"))
					{
						ConsolePrintErrorAndQuit("A shuriken trail failed to initialize!");
					}
					m_shurikenTrails.push_back(trail);
				}
			}
		}

		for (unsigned int i = 0; i < m_shurikens.size(); i++)
		{
			if (!IsShurikenInNetworkList(m_shurikens[i]->GetID()))
			{
				// Remove shuriken
				m_shurikens[i]->Shutdown();
				delete m_shurikens[i];
				m_shurikens.erase(m_shurikens.begin() + i);

				m_shurikenTrails[i]->Shutdown();
				delete m_shurikenTrails[i];
				m_shurikenTrails.erase(m_shurikenTrails.begin() + i);

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

	if (Network::GetInstance()->IsSpikeTrapListUpdated())
	{
		std::vector<SpikeNet> tempSpikeTrapList = Network::GetInstance()->GetSpikeTraps();
		std::vector<Spikes> spikeTrapList;
		for (unsigned int i = 0; i < tempSpikeTrapList.size(); i++)
		{
			if (!IsSpikeTrapInList(tempSpikeTrapList[i].spikeId))
			{
				// Add Smoke bomb
				AddSpikeTrap(tempSpikeTrapList[i].startX, tempSpikeTrapList[i].startZ, tempSpikeTrapList[i].endX, tempSpikeTrapList[i].endZ, tempSpikeTrapList[i].spikeId, tempSpikeTrapList[i].team);
			}
		}
		Network::GetInstance()->SetHaveUpdateSpikeTrapList();
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (Network::GetInstance()->IsStickyTrapListUpdated())
	{
		std::vector<StickyTrapNet> tempStickyTrapList = Network::GetInstance()->GetStickyTrapList();
		std::vector<StickyTrap> stickyTrapList;
		for (unsigned int i = 0; i < tempStickyTrapList.size(); i++)
		{
			if (!IsStickyTrapInList(tempStickyTrapList[i].stickyTrapId))
			{
				// Add Smoke bomb
				AddStickyTrap(tempStickyTrapList[i].startX, tempStickyTrapList[i].startZ, tempStickyTrapList[i].endX, tempStickyTrapList[i].endZ, tempStickyTrapList[i].stickyTrapId, tempStickyTrapList[i].guid);
			}
		}
		Network::GetInstance()->SetHaveUpdateStickyTrapList();
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get fans from server
	std::vector<FanNet> tempNetFans = Network::GetInstance()->GetFanList();

	if (Network::GetInstance()->IsFanListUpdated())
	{
		// Add nonexisting fans
		for (unsigned int i = 0; i < tempNetFans.size(); i++)
		{
			if (!IsFanInList(tempNetFans[i].id))
			{
				AddFan(FANBOOMERANG_MODEL_NAME, DirectX::XMFLOAT3(tempNetFans[i].x, tempNetFans[i].y, tempNetFans[i].z), DirectX::XMFLOAT3(tempNetFans[i].dirX, tempNetFans[i].dirY, tempNetFans[i].dirZ), tempNetFans[i].speed, tempNetFans[i].id, tempNetFans[i].guid);
			}
		}

		// Remove dead fans
		for (unsigned int i = 0; i < m_fans.size(); i++)
		{
			if (!IsFanInNetworkList(m_fans[i]->GetID()))
			{
				m_fans[i]->Shutdown();
				delete m_fans[i];
				m_fans.erase(m_fans.begin() + i);
				i--;
			}
		}
		Network::GetInstance()->SetHaveUpdateFanList();
	}

	// Update all the fans
	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		for (unsigned int j = 0; j < tempNetFans.size(); j++)
		{
			if (m_fans[i]->GetID() == tempNetFans[j].id)
			{
				m_fans[i]->Update(tempNetFans[j].lifeTime <= 0.0f);
			}
		}
	}
		
	// Update Volleys
	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		bool remove = m_volleys[i]->Update();
		if (remove)
		{
			m_volleys[i]->Shutdown();
			delete m_volleys[i];
			m_volleys.erase(m_volleys.begin() + i);
			i--;
		}
	}

	for (unsigned int i = 0; i < m_worldParticles.size(); i++)
	{
		m_worldParticles[i]->Update();
	}

	UpdateRenderLists();
	
	for (unsigned int i = 0; i < m_shurikenTrails.size(); i++)
	{
		float angle = atan2(m_shurikens[i]->GetDirection().z, m_shurikens[i]->GetDirection().x);
		m_shurikenTrails[i]->Update(m_shurikens[i]->GetPosition(), angle);
	}
}

void ObjectManager::UpdateRenderLists()
{
	std::vector<Object*> tempList;
	m_objectsToInstanceRender.clear();
	m_objectsToSingleRender.clear();
	tempList.clear();

	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
	{
		Sphere sphere = m_staticObjects[i].GetFrustumSphere();
		sphere.m_position.x -= 3.0f;
		sphere.m_position.z -= 3.0f;
		if (m_frustum->CheckSphere(sphere, 10.0f))
		{
			m_staticObjects[i].UpdateRotation();
			tempList.push_back(&m_staticObjects[i]);
		}
	}

	std::vector<Object*>  temp;
	Object* prevObject = &m_staticObjects[m_staticObjects.size() - 1];
	for (unsigned int i = 0; i < tempList.size(); i++)
	{
		temp = CheckAmountOfSameModels(tempList[i], tempList);// Return vector med de ombjekt som finns i templist som är lika dana
		if (prevObject->GetModel() != temp[0]->GetModel())
		{
			if (temp.size() == 1)
			{
				m_objectsToSingleRender.push_back(tempList[i]);
			}
			else
			{
				if (!CheckIfObjectIsInList(tempList[i], m_objectsToInstanceRender))
				{
					m_objectsToInstanceRender.push_back(tempList[i]);
					GraphicsEngine::GetInstance()->UpdateInstanceBuffers(temp);
				}
			}
		}
		prevObject = temp[0];
	}
}

void ObjectManager::Render()
{
	for (unsigned int i = 0; i < m_objectsToInstanceRender.size(); i++)
	{
		m_objectsToInstanceRender[i]->RenderInstanced();
	}

	for (unsigned int i = 0; i < m_objectsToSingleRender.size(); i++)
	{
		m_objectsToSingleRender[i]->Render();
	}

	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (m_frustum->CheckSphere(m_shurikens[i]->GetFrustumSphere(), 1.0f))
		{
			m_shurikens[i]->Render();
		}
	}

	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		if (m_frustum->CheckSphere(m_projectiles[i]->GetFrustumSphere(), 1.0f))
		{
			m_projectiles[i]->Render();
		}
	}

	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		if (m_frustum->CheckSphere(m_fans[i]->GetFrustumSphere(), 1.0f))
		{
			m_fans[i]->Render();
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
			GraphicsEngine::GetInstance()->TurnOnAlphaBlending();
			m_spikeTrapList[i]->Render();
			GraphicsEngine::GetInstance()->TurnOffAlphaBlending();
		}
	}
	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		if (m_frustum->CheckSphere(m_stickyTrapList[i]->GetStickyTrapSphere(), 2.0f))
		{
			GraphicsEngine::GetInstance()->TurnOnAlphaBlending();
			m_stickyTrapList[i]->Render();
			GraphicsEngine::GetInstance()->TurnOffAlphaBlending();
		}
	}

	for (unsigned int i = 0; i < m_animatedObjects.size(); i++)
	{
		if (m_frustum->CheckSphere(m_animatedObjects[i]->GetFrustumSphere(), 1.0f))
		{
			m_animatedObjects[i]->Render();
		}
	}

	for (unsigned int i = 0; i < m_worldParticles.size(); i++)
	{
		
		m_worldParticles[i]->Render();
	}

	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		m_volleys[i]->Render();
	}

	for (unsigned int i = 0; i < m_shurikenTrails.size(); i++)
	{
		m_shurikenTrails[i]->Render();
	}
}

void ObjectManager::RenderDepth()
{
	for (unsigned int i = 0; i < m_objectsToInstanceRender.size(); i++)
	{
		m_objectsToInstanceRender[i]->RenderDepthInstanced();
	}

	for (unsigned int i = 0; i < m_objectsToSingleRender.size(); i++)
	{
		m_objectsToSingleRender[i]->RenderDepth();
	}

	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i]->RenderDepth();
	}

	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->RenderDepth();
	}

	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		if (m_frustum->CheckSphere(m_fans[i]->GetFrustumSphere(), 1.0f))
		{
			m_fans[i]->RenderDepth();
		}
	}

	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i]->GetBomb()->RenderDepth();
	}

	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		Object* temp = m_spikeTrapList[i]->GetSpikesBag();
		if (temp != NULL)
		{
			temp->RenderDepth();
}
	}

	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		Object* temp = m_stickyTrapList[i]->GetStickyBag();
		if (temp != NULL)
		{
			temp->RenderDepth();
		}
	}

	for (unsigned int i = 0; i < m_animatedObjects.size(); i++)
	{
		if (m_frustum->CheckSphere(m_animatedObjects[i]->GetFrustumSphere(), 1.0f))
		{
			m_animatedObjects[i]->RenderDepth();
		}		
	}
	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		m_volleys[i]->RenderDepth();
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

void ObjectManager::AddSpikeTrap(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_spikeBombID, int p_team)
{
	Spikes *tempSpikeTrap;
	tempSpikeTrap = new Spikes();
	tempSpikeTrap->Initialize(DirectX::XMFLOAT3(p_startPosX, 0.02f, p_startPosZ), DirectX::XMFLOAT3(p_endPosX, 0.02f, p_endPosZ), p_spikeBombID, p_team);
	tempSpikeTrap->ResetTimer();
	m_spikeTrapList.push_back(tempSpikeTrap);
}

void ObjectManager::AddStickyTrap(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, unsigned int p_stickyTrapID, RakNet::RakNetGUID p_guid)
{
	StickyTrap *tempStickyTrap;
	tempStickyTrap = new StickyTrap();

	float yPos = CheckStickyTrapYPosition();
	tempStickyTrap->Initialize(DirectX::XMFLOAT3(p_startPosX, yPos, p_startPosZ), DirectX::XMFLOAT3(p_endPosX, yPos, p_endPosZ), p_stickyTrapID, p_guid);
	tempStickyTrap->ResetTimer();
	m_stickyTrapList.push_back(tempStickyTrap);
}
float ObjectManager::CheckStickyTrapYPosition()
{
	float returnValue = 0.001f;
	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		if (m_stickyTrapList[i]->GetStickyTrapSphere().m_position.y < 1.0f)
		{
			if (m_stickyTrapList[i]->GetStickyTrapSphere().m_position.y >= returnValue)
			{
				returnValue = m_stickyTrapList[i]->GetStickyTrapSphere().m_position.y + 0.01f;
			}
		}
	}
	return returnValue;
}
void ObjectManager::AddStaticObject(Object p_object)
{
	m_staticObjects.push_back(p_object);
}

void ObjectManager::AddFan(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id, RakNet::RakNetGUID p_owner)
{
	FanBoomerang* temp;
	temp = new FanBoomerang();
	temp->Initialize(p_filepath, p_pos, p_dir, p_speed, p_id, p_owner);
	temp->SetSpeed(p_speed);
	m_fans.push_back(temp);
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

bool ObjectManager::IsStickyTrapInList(unsigned int p_stickyTrapId)
{
	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		if (p_stickyTrapId == m_stickyTrapList[i]->GetID())
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

std::vector<AnimatedObject*> ObjectManager::GetAnimatedObjectList()const
{
	return m_animatedObjects;
}

void ObjectManager::UpdateFrustum(Frustum* p_frustum)
{
	m_frustum = p_frustum;
}

bool ObjectManager::CheckIfObjectIsInList(Object *p_object, std::vector<Object*> p_list)
{
	if (!p_list.empty())
	{
		if (p_list[0]->GetModel() == p_object->GetModel())
		{
			return true;
		}
	}
	return false;
}

std::vector<Object*> ObjectManager::CheckAmountOfSameModels(Object *p_object, std::vector<Object*> p_list)
{
	std::vector<Object*> returnList;
	if (!p_list.empty())
	{
		for (unsigned int i = 0; i < p_list.size(); i++)
		{
			if (p_list[i]->GetModel() == p_object->GetModel())
			{
				returnList.push_back(p_list[i]);
			}
		}
	}
	return returnList;
}

bool ObjectManager::IsFanInList(unsigned int p_fanId)
{
	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		if (p_fanId == m_fans[i]->GetID())
		{
			return true;
		}
	}

	return false;
}

bool ObjectManager::IsFanInNetworkList(unsigned int p_fanId)
{
	std::vector<FanNet> list = Network::GetInstance()->GetFanList();

	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (p_fanId == list[i].id)
		{
			return true;
		}
	}

	return false;
}

void ObjectManager::AddProjectile(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_uniqueId, RakNet::RakNetGUID p_guid, float p_speed, int p_ability)
{
	// Check if projectile exists
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		if (m_projectiles[i]->GetGUID() == p_guid && m_projectiles[i]->GetID() == p_uniqueId)
		{
			break;
		}
	}

	Projectile* tempProjectile;
	tempProjectile = new Projectile();
	tempProjectile->Initialize(DirectX::XMFLOAT3(p_x, p_y, p_z), DirectX::XMFLOAT3(p_dirX, p_dirY, p_dirZ), p_uniqueId, p_ability, p_guid);

	m_projectiles.push_back(tempProjectile);
}

std::vector<StickyTrap*> ObjectManager::GetStickyTrapList()
{
	return m_stickyTrapList;
}
void ObjectManager::RemoveProjectile(unsigned int p_projId)
{
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		if (m_projectiles[i]->GetID() == p_projId)
		{
			m_projectiles[i]->Shutdown();
			delete m_projectiles[i];
			m_projectiles.erase(m_projectiles.begin() + i);
			break;
		}
	}
}

void ObjectManager::AddVolley(unsigned int p_id, float p_startX, float p_startZ, float p_endX, float p_endZ, RakNet::RakNetGUID p_guid)
{
	Volley* temp = new Volley;
	DirectX::XMFLOAT3 start = DirectX::XMFLOAT3(p_startX, 0.0f, p_startZ);
	DirectX::XMFLOAT3 end = DirectX::XMFLOAT3(p_endX, 0.0f, p_endZ);
	temp->Initialize(start, end);
	m_volleys.push_back(temp);
}

void ObjectManager::ResetListSinceRoundRestarted()
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i]->Shutdown();
		delete m_shurikens[i];
	}
	m_shurikens.clear();
	for (unsigned int i = 0; i < m_smokeBombList.size(); i++)
	{
		m_smokeBombList[i]->Shutdown();
		delete m_smokeBombList[i];
	}
	m_smokeBombList.clear();
	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		m_spikeTrapList[i]->Shutdown();
		delete m_spikeTrapList[i];
	}
	m_spikeTrapList.clear();
	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		m_fans[i]->Shutdown();
		delete m_fans[i];
	}
	m_fans.clear();
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->Shutdown();
		delete m_projectiles[i];
	}
	m_projectiles.clear();
	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		m_stickyTrapList[i]->Shutdown();
		delete m_stickyTrapList[i];
	}
	m_stickyTrapList.clear();
	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		m_volleys[i]->Shutdown();
		delete m_volleys[i];
	}
	m_volleys.clear();
}