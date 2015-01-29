#include "PlayingStateTest.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "Collisions.h"
#include "GraphicsEngine.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
#include "Frustum.h"
#include "Camera.h"
#include "Globals.h"
#include "ShadowShapes.h"
#include "Minimap.h"
#include "VisibilityComputer.h"
#include "..\CommonLibs\ModelNames.h"

PlayingStateTest::PlayingStateTest(){}
PlayingStateTest::~PlayingStateTest(){}

bool PlayingStateTest::Initialize()
{
	return Initialize(LEVEL_NAME);
}

bool PlayingStateTest::Initialize(std::string p_levelName)
{
	// Initialize the camera.
	m_camera = new Camera();
	m_camera->Initialize();
	m_camera->ResetCamera();

	// Load the level.
	Level level(p_levelName);

	// Initialize the objectmanager.
	m_objectManager = new ObjectManager();
	m_objectManager->Initialize(&level);

	// Load and place arena walls.
	std::vector<LevelImporter::LevelBoundingBox> temp = level.getLevelBoundingBoxes();
	std::vector<Box> wallList;
	for (unsigned int i = 0; i < temp.size(); i++)
	{
		LevelImporter::LevelBoundingBox box = temp[i];
		wallList.push_back(Box(box.m_translationX, box.m_translationY, box.m_translationZ, box.m_halfDepth, box.m_halfHeight, box.m_halfWidth));
	}

	// Initiate player
	m_playerManager = new PlayerManager();
	m_playerManager->Initialize();
	CollisionManager::GetInstance()->Initialize(m_objectManager->GetStaticObjectList(), wallList);

	// ========== DEBUG LINES ==========
	if (FLAG_DEBUG == 1)
	{
		m_debugDot.Initialize(DirectX::XMFLOAT3(m_playerManager->GetPlayerPosition().x, 0.2f, m_playerManager->GetPlayerPosition().z), 100, DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f));

		m_mouseX = 0;
		m_mouseY = 0;

		// TODO, change this to use the loaded maps values.
		VisibilityComputer::GetInstance().SetMapBoundries(Point(-51.0f, 51.0f), Point(51.0f, -51.0f));

		ShadowShapes::GetInstance().AddStaticSquare(Point(-0.5f, 0.5f), Point(0.5f, -0.5f));
	}
	// ========== DEBUG LINES ==========

	// Frustum
	m_frustum = new Frustum();
	m_updateFrustum = true;
	m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	m_objectManager->UpdateFrustum(m_frustum);
	m_playerManager->UpdateFrustum(m_frustum);

	// Initialize the minimap
	m_minimap = new Minimap();
	m_minimap->Initialize();
	
	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.4f, 0.4f, 0.4f, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(1.125f, 1.125f, 1.125f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(5.525f, 5.525f, 5.525f, 1.0f);
	DirectX::XMFLOAT4 direction = DirectX::XMFLOAT4(-1.0f, -4.0f, -2.0f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMVector3Normalize(DirectX::XMLoadFloat4(&direction));
	GraphicsEngine::InitializeOutling();

	return true;
}

void PlayingStateTest::Shutdown()
{
	m_camera->Shutdown();
	delete m_camera;

	if (m_playerManager != NULL)
	{
		m_playerManager->Shutdown();
		delete m_playerManager;
	}

	if (m_objectManager != NULL)
	{
		m_objectManager->Shutdown();
		delete m_objectManager;
	}

	// ========== DEBUG TEMP LINES ==========
	if (FLAG_DEBUG == 1)
	{
	m_debugDot.Shutdown();
	}
	// ========== DEBUG TEMP LINES ==========

	m_minimap->Shutdown();
}

GAMESTATESWITCH PlayingStateTest::Update()
{
	// Check if new level have started
	if (Network::GetInstance()->IsConnected() && Network::GetInstance()->NewLevel())
	{
		std::string levelName = Network::GetInstance()->LevelName();
		Network::GetInstance()->SetHaveUpdateNewLevel();
		Shutdown();
		Initialize(levelName);
		return GAMESTATESWITCH_NONE;
	}

	// Update global delta time.
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	BasicPicking();

	m_playerManager->Update();

	// Handle camera input.
	m_camera->HandleInput();

	// The camera should follow the character if not flying.
	if (!GLOBAL::GetInstance().CAMERA_FLYING)
	{
		m_camera->FollowCharacter(m_playerManager->GetPlayerPosition());
	}

	// Get picking data.
	BasicPicking();

	// Update every object.
	m_objectManager->Update();

	m_playerManager->UpdateHealthbars(m_camera->GetViewMatrix(), m_camera->GetProjectionMatrix());

	CollisionManager::GetInstance()->Update(m_mouseX, m_mouseY);

	// Update frustum
	if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('c')))
	{
		m_updateFrustum = false;
	}

	if (GetAsyncKeyState(VK_BACK))
	{
		m_updateFrustum = true;
	}

	if (m_updateFrustum)
	{
		m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
		m_objectManager->UpdateFrustum(m_frustum);
		m_playerManager->UpdateFrustum(m_frustum);
	}

	m_minimap->Update(m_playerManager->GetPlayerPosition());
	MinimapUpdatePos(m_minimap);

	m_minimap->SetPlayerTexture(m_playerManager->GetPlayerTeam());
	for (int i = 0; i < 7; i++)
	{
		m_minimap->SetTeamTexture(i, m_playerManager->GetEnemyTeam(i));
	}

	// Update Directional Light's camera position
	m_directionalLight.m_cameraPosition = DirectX::XMLoadFloat3(&m_camera->GetPosition());
	
	return GAMESTATESWITCH_NONE;
}

void PlayingStateTest::Render()
{
	bool testBB = false;

	// Draw to the shadowmap.
	GraphicsEngine::BeginRenderToShadowMap();
	m_objectManager->RenderDepth();
	m_playerManager->RenderDepth();
	GraphicsEngine::SetShadowMap();
	GraphicsEngine::ResetRenderTarget();

	GraphicsEngine::SetSceneDirectionalLight(m_directionalLight);

	// Draw to the scene.
	m_playerManager->Render();
	m_objectManager->Render();

	// ========== DEBUG LINES ==========
	if (FLAG_DEBUG == 1)
	{
		// Draw a dot at the mouse position.
		m_debugDot.Render();

		// Draw a line from the player to the dot.
		DebugDraw::GetInstance().RenderSingleLine(DirectX::XMFLOAT3(m_playerManager->GetPlayerPosition().x, 0.2f, m_playerManager->GetPlayerPosition().z), DirectX::XMFLOAT3(m_mouseX, 0.2f, m_mouseY), DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

		ShadowShapes::GetInstance().DebugRender();

		VisibilityComputer::GetInstance().RenderVisibilityPolygon(GraphicsEngine::GetContext());
	}
	// ========== DEBUG TEMP LINES ==========

	m_minimap->Render();

	// OUTLINING
	GraphicsEngine::ClearOutlining();
	GraphicsEngine::SetOutliningPassOne();
	m_playerManager->Render();
	GraphicsEngine::SetOutliningPassTwo();
	m_playerManager->RenderOutlining();
	GraphicsEngine::ResetRenderTarget();
}

void PlayingStateTest::ToggleFullscreen(bool p_fullscreen)
{
	m_camera->ToggleFullscreen(p_fullscreen);
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

	DirectX::XMFLOAT4X4 proj = m_camera->GetProjectionMatrix();
	float viewSpaceX = (2.0f * (float)mousePosX / (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH - 1) / proj._11;
	float viewSpaceY = -((2.0f * (float)mousePosY / (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT - 1) / proj._22);
	float viewSpaceZ = 1.0f;

	rayDir = DirectX::XMFLOAT3(viewSpaceX, viewSpaceY, viewSpaceZ);

	DirectX::XMFLOAT4X4 viewInverse;
	DirectX::XMVECTOR determinant;
	DirectX::XMStoreFloat4x4(&viewInverse, DirectX::XMMatrixInverse(&determinant, DirectX::XMLoadFloat4x4(&m_camera->GetViewMatrix())));

	DirectX::XMStoreFloat3(&rayPos,DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&rayPos), DirectX::XMLoadFloat4x4(&viewInverse)));
	DirectX::XMStoreFloat3(&rayDir, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&rayDir), DirectX::XMLoadFloat4x4(&viewInverse)));

	float t = -rayPos.y / rayDir.y;

	DirectX::XMFLOAT3 shurPos = DirectX::XMFLOAT3(rayPos.x + t*rayDir.x, rayPos.y + t*rayDir.y, rayPos.z + t*rayDir.z);
	DirectX::XMFLOAT3 shurDir = DirectX::XMFLOAT3(-(m_playerManager->GetPlayerPosition().x - shurPos.x), -(m_playerManager->GetPlayerPosition().y - shurPos.y), -(m_playerManager->GetPlayerPosition().z - shurPos.z));
	
	m_playerManager->SetAttackDirection(NormalizeFloat3(NormalizeFloat3(shurDir)));

	// ========== DEBUG LINES ==========
	if (FLAG_DEBUG == 1)
	{
		// Update dot location.
	DirectX::XMFLOAT4X4 world;
	DirectX::XMFLOAT3 translate = DirectX::XMFLOAT3(shurPos.x, 0.0f, shurPos.z);
	DirectX::XMMATRIX matrix = DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&translate));
	DirectX::XMStoreFloat4x4(&world, matrix);
	m_debugDot.UpdateWorldMatrix(world);

	m_mouseX = shurPos.x;
	m_mouseY = shurPos.z;
	}
	// ========== DEBUG LINES ==========
}

DirectX::XMFLOAT3 PlayingStateTest::NormalizeFloat3(DirectX::XMFLOAT3 p_f)
{
	float t2 = sqrt(p_f.x * p_f.x + p_f.y * p_f.y + p_f.z * p_f.z);
	return DirectX::XMFLOAT3(p_f.x / t2, p_f.y / t2, p_f.z/t2);
}

void PlayingStateTest::MinimapUpdatePos(Minimap *p_minimap)
{
	for (int i = 0; i < 7; i++)
	{
		if (m_playerManager->IsPlayersVisible(i) || m_playerManager->GetPlayerTeam() == m_playerManager->GetEnemyTeam(i))
		{
			m_playerManager->MinimapUpdatePos(p_minimap);
		}
		else
		{
			m_minimap->SetPlayerPos(i, DirectX::XMFLOAT3(-1000,-1000,0));
		}
	}
	
}