#include "PlayingStateTest.h"


PlayingStateTest::PlayingStateTest()
{
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
	if (InputManager::GetInstance()->IsRightMouseClicked())
	{
		m_objectManager.AddShuriken("../Shurikenjutsu/Models/shurikenShape.SSP", m_playerManager.GetPlayerPosition(), DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f), 10.0f);
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
		GraphicsEngine::Render(SHADERTYPE_SCENE, tempModel.GetMesh(), tempModel.GetVertexCount(), tempModel.GetWorldMatrix(), tempModel.GetTexture());
	}
}

void PlayingStateTest::ToggleFullscreen(bool p_fullscreen)
{
	m_camera.ToggleFullscreen(p_fullscreen);
}
void PlayingStateTest::MeleeAttack()
{
	Box box = Box(DirectX::XMFLOAT3(20.0f, 1.0f, 5.0f), DirectX::XMFLOAT3(2.0f, 2.0f, 2.0f));
	DirectX::XMFLOAT3 shurikenDir = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);
	const char* shurikenFile = "../Shurikenjutsu/Models/shurikenShape.SSP";
	//The box
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x, box.m_center.y, box.m_center.z), DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f), 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x + box.m_extents.x, box.m_center.y + box.m_extents.y, box.m_center.z + box.m_extents.z), shurikenDir, 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x - box.m_extents.x, box.m_center.y - box.m_extents.y, box.m_center.z - box.m_extents.z), shurikenDir, 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x + box.m_extents.x, box.m_center.y - box.m_extents.y, box.m_center.z + box.m_extents.z), shurikenDir, 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x - box.m_extents.x, box.m_center.y + box.m_extents.y, box.m_center.z - box.m_extents.z), shurikenDir, 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x - box.m_extents.x, box.m_center.y + box.m_extents.y, box.m_center.z + box.m_extents.z), shurikenDir, 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x + box.m_extents.x, box.m_center.y - box.m_extents.y, box.m_center.z - box.m_extents.z), shurikenDir, 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x - box.m_extents.x, box.m_center.y - box.m_extents.y, box.m_center.z + box.m_extents.z), shurikenDir, 0.0f);
	m_objectManager.AddShuriken(shurikenFile, DirectX::XMFLOAT3(box.m_center.x + box.m_extents.x, box.m_center.y + box.m_extents.y, box.m_center.z - box.m_extents.z), shurikenDir, 0.0f);
	DirectX::XMFLOAT3 playerPos = m_playerManager.GetPlayerPosition();
	Sphere sphere = Sphere(playerPos, 5.0f);
	DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);

	m_objectManager.AddShuriken(shurikenFile,
		DirectX::XMFLOAT3(playerPos.x + attackDirection.x*sphere.m_radius,playerPos.y + attackDirection.y*sphere.m_radius,playerPos.z + attackDirection.z*sphere.m_radius),	shurikenDir, 0.0f);

	if (Collisions::MeleeAttackCollision(sphere, box, attackDirection))
	{
		std::cout << "Ouch!!!" << std::endl;
	}
	else
	{
		std::cout << "Missed muthafocker!!! MUHAHAHAHAHAHA" << std::endl;
	}
}