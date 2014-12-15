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

	m_objectManager.Initialize();

	m_camera.ResetCamera();

	//Load level
	Level level("../Shurikenjutsu/Levels/testBana.SSPL");

	// Load objects on the level
	std::vector<LevelImporter::CommonObject> levelObjects = level.GetObjects();
	for (unsigned int i = 0; i < levelObjects.size(); i++)
	{
		Object object;
		object.Initialize(levelObjects[i].m_filePath.c_str(), DirectX::XMFLOAT3(levelObjects[i].m_translationX, levelObjects[i].m_translationY, levelObjects[i].m_translationZ), DirectX::XMFLOAT3(levelObjects[i].m_rotationX, levelObjects[i].m_rotationY, levelObjects[i].m_rotationZ), DirectX::XMFLOAT3(1.0f,1.0f,1.0f));
		m_objectManager.AddStaticObject(object);
	}
	std::vector<LevelImporter::LevelBoundingBox> temp = level.getLevelBoundingBoxes();
	std::vector<Box> wallList;
	for (unsigned int i = 0; i < temp.size(); i++)
	{
		LevelImporter::LevelBoundingBox box = temp[i];
		wallList.push_back(Box(box.m_translationX, box.m_translationY, box.m_translationZ, box.m_halfDepth*2, box.m_halfHeight*2, box.m_halfWidth*2));
	}
	// Initiate player
	m_playerManager.Initialize();
	CollisionManager::GetInstance()->Initialize(m_objectManager.GetStaticObjectList(), wallList);

	// ========== DEBUG TEMP LINES ==========
	if (FLAG_DEBUG == 1)
	{
		m_circle1.Initialize(DirectX::XMFLOAT3(m_playerManager.GetPlayerPosition().x, 0.2f, m_playerManager.GetPlayerPosition().z), 2.5f, 50, DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f));
		m_circle2.Initialize(DirectX::XMFLOAT3(m_playerManager.GetPlayerPosition().x, 0.2f, m_playerManager.GetPlayerPosition().z), 2.5f, 50, DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f));
		m_circle3.Initialize(DirectX::XMFLOAT3(m_playerManager.GetPlayerPosition().x, 0.2f, m_playerManager.GetPlayerPosition().z), 0.5f, 50, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

		m_debugDot.Initialize(DirectX::XMFLOAT3(m_playerManager.GetPlayerPosition().x, 0.2f, m_playerManager.GetPlayerPosition().z), 100, DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));

		m_mouseX = 0;
		m_mouseY = 0;
	}

	m_particles.Initialize(GraphicsEngine::GetDevice(), DirectX::XMFLOAT3(0.0f, 3.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(3.0f, 3.0f), PARTICLE_PATTERN_SMOKE);
	// ========== DEBUG TEMP LINES ==========

	// Frustum
	m_frustum = Frustum();

	return true;
}

void PlayingStateTest::Shutdown()
{
	m_camera.Shutdown();
	m_playerManager.Shutdown();
	m_objectManager.Shutdown();

	// ========== DEBUG TEMP LINES ==========
	if (FLAG_DEBUG == 1)
	{
		m_circle1.Shutdown();
		m_circle2.Shutdown();
		m_circle3.Shutdown();

		m_debugDot.Shutdown();
	}

	m_particles.Shutdown();
	// ========== DEBUG TEMP LINES ==========
}

void PlayingStateTest::Update()
{
	// Update global delta time.
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	
	// Update the players.
	m_playerManager.Update(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());

	// Handle camera input.
	m_camera.HandleInput();

	// The camera should follow the character if not flying.
	if (!GLOBAL::GetInstance().CAMERA_FLYING)
	{
		m_camera.FollowCharacter(m_playerManager.GetPlayerPosition());
	}

	// Get picking data.
	BasicPicking();

	// Update every object.
	m_objectManager.Update();

	// ========== DEBUG TEMP LINES ==========
	// Update the particles.
	m_particles.Update();
	// ========== DEBUG TEMP LINES ==========
}

void PlayingStateTest::Render()
{
	m_frustum.ConstructFrustum(1000, m_camera.GetProjectionMatrix(), m_camera.GetViewMatrix());

	bool testBB = false;

	// Draw to the shadowmap.
	GraphicsEngine::BeginRenderToShadowMap();

	m_playerManager.Render(SHADERTYPE_DEPTH);
	m_objectManager.Render(SHADERTYPE_DEPTH);

	GraphicsEngine::SetShadowMap();
	GraphicsEngine::ResetRenderTarget();

	// Draw to the scene.
	m_playerManager.Render(SHADERTYPE_SCENE);
	m_objectManager.Render(SHADERTYPE_SCENE);
	m_objectManager.RenderShurikens(SHADERTYPE_SCENE);
	m_objectManager.Render(SHADERTYPE_ANIMATED);

	if (FLAG_DEBUG == 1)
	{
		ShadowShapes::GetInstance().DebugRender();
	}

	// ========== DEBUG TEMP LINES ==========
	if (FLAG_DEBUG == 1)
	{
		DirectX::XMFLOAT4X4 circleWorld;
		DirectX::XMStoreFloat4x4(&circleWorld, DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&m_playerManager.GetPlayerPosition())));

		m_circle1.UpdateWorldMatrix(circleWorld);
		m_circle1.Render();

		m_circle3.UpdateWorldMatrix(circleWorld);
		m_circle3.Render();

		DirectX::XMFLOAT3 translate = DirectX::XMFLOAT3(m_playerManager.GetPlayerPosition().x + m_playerManager.GetAttackDirection().x * m_circle2.GetRadius(), 0.0f, m_playerManager.GetPlayerPosition().z + m_playerManager.GetAttackDirection().z * m_circle2.GetRadius());
		DirectX::XMStoreFloat4x4(&circleWorld, DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&translate)));

		m_circle2.UpdateWorldMatrix(circleWorld);
		m_circle2.Render();
		if (m_frustum.CheckCube(m_playerManager.GetPlayerPosition().x, m_playerManager.GetPlayerPosition().y, m_playerManager.GetPlayerPosition().z, 1.0f))
		{
			testBB = true;
		}
		if (testBB)
		{
			m_debugDot.Render();
		}

		DebugDraw::GetInstance().RenderSingleLine(DirectX::XMFLOAT3(m_playerManager.GetPlayerPosition().x, 0.2f, m_playerManager.GetPlayerPosition().z), DirectX::XMFLOAT3(m_mouseX, 0.2f, m_mouseY), DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	}

	m_particles.Render();
	// ========== DEBUG TEMP LINES ==========
}

void PlayingStateTest::ToggleFullscreen(bool p_fullscreen)
{
	m_camera.ToggleFullscreen(p_fullscreen);
}
void PlayingStateTest::MeleeAttack()
{
	/*std::vector<Object> modelList = m_objectManager.GetStaticObjectList();
	for (unsigned int i = 0; i < modelList.size(); i++)
	{
		std::vector<Box> boxList = modelList[i].GetModel()->GetBoundingBoxes();
		if (boxList.size() != 0)
		{
			for (unsigned int j = 0; j < boxList.size(); j++)
			{
				Box box = boxList[j];

				box.m_center.x += modelList[i].GetPosition().x;
				box.m_center.y += modelList[i].GetPosition().y;
				box.m_center.z += modelList[i].GetPosition().z;

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
	}*/
}

void PlayingStateTest::BasicPicking()
{
	int mouseOffsetX = 0;
	int mouseOffsetY = 0;

	if (!GLOBAL::GetInstance().FULLSCREEN)
	{
		mouseOffsetX = 6;
		mouseOffsetY = 20;
	}

	int mousePosX = InputManager::GetInstance()->GetMousePositionX() + mouseOffsetX;
	int mousePosY = InputManager::GetInstance()->GetMousePositionY() + mouseOffsetY;

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

	// ========== DEBUG TEMP LINES ==========
	if (FLAG_DEBUG == 1)
	{
		DirectX::XMFLOAT4X4 world;
		DirectX::XMFLOAT3 translate = DirectX::XMFLOAT3(shurPos.x, 0.0f, shurPos.z);
		DirectX::XMMATRIX matrix = DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&translate));
		DirectX::XMStoreFloat4x4(&world, matrix);

		m_debugDot.UpdateWorldMatrix(world);

		m_mouseX = shurPos.x;
		m_mouseY = shurPos.z;
	}
	// ========== DEBUG TEMP LINES ==========
}

DirectX::XMFLOAT3 PlayingStateTest::NormalizeFloat3(DirectX::XMFLOAT3 p_f)
{
	float t2 = sqrt(p_f.x * p_f.x + p_f.y * p_f.y + p_f.z * p_f.z);
	return DirectX::XMFLOAT3(p_f.x / t2, p_f.y / t2, p_f.z/t2);
}
