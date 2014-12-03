#include "PlayingStateTest.h"


PlayingStateTest::PlayingStateTest()
{
	twoPi = 6.28318530718f;
}

PlayingStateTest::~PlayingStateTest()
{
}

bool PlayingStateTest::Initialize()
{
	m_camera.Initialize();

	m_playerManager.Initialize();

	m_objectManager.Initialize();

	m_camera.ResetCamera();

	//Load level
	Level level(&m_objectManager, "../Shurikenjutsu/Levels/testBana.SSPL");
	GLOBAL::GetInstance().shurikenThrownID = 0;
	return true;
}

void PlayingStateTest::Shutdown()
{
	m_camera.Shutdown();
	m_playerManager.Shutdown();
	m_objectManager.Shutdown();
}

void PlayingStateTest::Update(double p_deltaTime)
{
	// Temporary "Shuriken" spawn
	if (InputManager::GetInstance()->IsLeftMouseClicked())
	{
		MeleeAttack();
	}
	
	BasicPicking();

	if (InputManager::GetInstance()->IsRightMouseClicked())
	{
		Network::AddShurikens(m_playerManager.GetPlayerPosition().x, m_playerManager.GetPlayerPosition().y, m_playerManager.GetPlayerPosition().z, m_playerManager.GetAttackDirection().x, m_playerManager.GetAttackDirection().y, m_playerManager.GetAttackDirection().z);
	}

	m_objectManager.Update(p_deltaTime);
	m_playerManager.Update(p_deltaTime);

	if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('f')))
	{
		if (GLOBAL::GetInstance().FULLSCREEN)
		{
			m_camera.ToggleFullscreen(false);
		}
		else
		{
			m_camera.ToggleFullscreen(true);
		}
	}

	m_camera.MoveCamera(p_deltaTime);
	if (!GLOBAL::GetInstance().flyingCamera)
	{
		m_camera.FollowCharacter(m_playerManager.GetPlayerPosition());
	}
}

void PlayingStateTest::Render()
{
	// Draw to the scene.
	m_playerManager.Render(SHADERTYPE_SCENE);
	m_objectManager.Render(SHADERTYPE_SCENE);

	// Draw to the shadowmap.
	GraphicsEngine::BeginRenderToShadowMap();

	m_playerManager.Render(SHADERTYPE_DEPTH);
	m_objectManager.Render(SHADERTYPE_DEPTH);

	GraphicsEngine::SetShadowMap();
	GraphicsEngine::ResetRenderTarget();

	DirectX::XMFLOAT4X4 world;
	DirectX::XMStoreFloat4x4(&world, DirectX::XMMatrixTranspose(DirectX::XMMatrixScaling(100.0f, 100.0f, 1.0f) * DirectX::XMMatrixRotationRollPitchYaw(0.0f, 0.0f, 0.0f) * DirectX::XMMatrixTranslation(-500.0f, -370.0f, 0.0f)));
	GraphicsEngine::RenderUI(world, GraphicsEngine::GetShadowMap());

	DirectX::XMFLOAT4X4 world2;
	DirectX::XMStoreFloat4x4(&world2, DirectX::XMMatrixTranspose(DirectX::XMMatrixScaling(100.0f, 100.0f, 1.0f) * DirectX::XMMatrixRotationRollPitchYaw(0.0f, 0.0f, 0.0f) * DirectX::XMMatrixTranslation(-280.0f, -370.0f, 0.0f)));
	GraphicsEngine::RenderUI(world2, GraphicsEngine::GetSceneShaderShadowMap());
}

void PlayingStateTest::RenderAlpha()
{
	// Draw Shurikens
	std::vector<Shuriken> tempList = m_objectManager.GetListOfShurikens();
	for (unsigned int i = 0; i < tempList.size(); i++)
	{
		Model tempModel = tempList[i].GetModel();
		GraphicsEngine::Render(SHADERTYPE_SCENE, tempModel.GetMesh(), tempModel.GetVertexCount(), tempModel.GetWorldMatrix(), tempModel.GetTexture(), tempModel.GetNormalMap());
	}
}

void PlayingStateTest::ToggleFullscreen(bool p_fullscreen)
{
	m_camera.ToggleFullscreen(p_fullscreen);
}
void PlayingStateTest::MeleeAttack()
{
	std::vector<Model> modelList = m_objectManager.GetListOfStaticModels();
	for (unsigned int i = 0; i < modelList.size(); i++)
	{
		std::vector<Box> boxList = modelList[i].GetBoundingBoxes();
		if (boxList.size() != 0)
		{
			for (unsigned int j = 0; j < boxList.size(); j++)
			{
				Box box = boxList[j];

				DirectX::XMFLOAT3 playerPos = m_playerManager.GetPlayerPosition();
				Sphere sphere = Sphere(playerPos, 5.0f);
				DirectX::XMFLOAT3 attackDirection = m_playerManager.GetAttackDirection();
				if (Collisions::MeleeAttackCollision(sphere, box, attackDirection))
				{
					std::cout << "HIT" << std::endl;
				}
				else
				{
					std::cout << "MISS" << std::endl;
				}
			}
		}
	}
}

void PlayingStateTest::BasicPicking()
{
	int mousePosX = InputManager::GetInstance()->GetMousePositionX();
	int mousePosY = InputManager::GetInstance()->GetMousePositionY();

	DirectX::XMFLOAT3 rayDir;
	DirectX::XMFLOAT3 rayPos = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);

	DirectX::XMFLOAT4X4 proj = m_camera.GetProjectionMatrix();
	float viewSpaceX = (2.0f * (float)mousePosX / (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH - 1) / proj._11;
	float viewSpaceY = -((2.0f * (float)mousePosY / (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT - 1) / proj._22);
	float viewSpaceZ = 1.0f;

	rayDir = DirectX::XMFLOAT3(viewSpaceX, viewSpaceY, viewSpaceZ);

	DirectX::XMFLOAT4X4 viewInverse;
	DirectX::XMVECTOR determinant;
	DirectX::XMStoreFloat4x4(&viewInverse, DirectX::XMMatrixInverse(&determinant, DirectX::XMLoadFloat4x4(&m_camera.GetViewMatrix())));

	DirectX::XMStoreFloat3(&rayPos,DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&rayPos), DirectX::XMLoadFloat4x4(&viewInverse)));
	DirectX::XMStoreFloat3(&rayDir, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&rayDir), DirectX::XMLoadFloat4x4(&viewInverse)));

	float t = -rayPos.y / rayDir.y;

	DirectX::XMFLOAT3 shurPos = DirectX::XMFLOAT3(rayPos.x + t*rayDir.x, rayPos.y + t*rayDir.y, rayPos.z + t*rayDir.z);
	DirectX::XMFLOAT3 shurDir = DirectX::XMFLOAT3(-(m_playerManager.GetPlayerPosition().x - shurPos.x), -(m_playerManager.GetPlayerPosition().y - shurPos.y), -(m_playerManager.GetPlayerPosition().z - shurPos.z));
	
	m_playerManager.SetAttackDirection(NormalizeFloat3(NormalizeFloat3(shurDir)));
}

DirectX::XMFLOAT3 PlayingStateTest::NormalizeFloat3(DirectX::XMFLOAT3 p_f)
{
	float t2 = sqrt(p_f.x * p_f.x + p_f.y * p_f.y + p_f.z * p_f.z);
	return DirectX::XMFLOAT3(p_f.x / t2, p_f.y / t2, p_f.z/t2);
}
