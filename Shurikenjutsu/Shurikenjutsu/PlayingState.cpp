#include "PlayingState.h"
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
#include "TeamStatusBar.h"
#include "Countdown.h"
#include "ConsoleFunctions.h"
#include "InGameMenu.h"
#include "VictoryScreenMenu.h"
#include "DeathBoard.h"
#include "ScoreBoard.h"
#include "SuddenDeathState.h"
#include "PointLights.h"
#include "Sound.h"

ParticleEmitter* TEST_POIemitter;

PlayingState::PlayingState(){}
PlayingState::~PlayingState(){}

void* PlayingState::operator new(size_t i)
{
	return _mm_malloc(i, 16);
}
void PlayingState::operator delete(void* p)
{
	_mm_free(p);
}

bool PlayingState::Initialize()
{
	return Initialize(LEVEL_NAME);
}

void PlayingState::EscapeIsPressed()
{

	if (m_inGameMenuIsActive)
	{
		m_inGameMenuIsActive = false;
	}
	else
	{
		m_inGameMenuIsActive = true;
	}
	if (Network::GetInstance()->GetMatchOver())
	{
		m_inGameMenuIsActive = false;
	}

	m_sound->StartStopMusic();
}

bool PlayingState::Initialize(std::string p_levelName)
{
	// Initialize the camera.
	m_camera = new Camera();
	m_camera->Initialize();
	m_camera->ResetCamera();

	// Load the level.
	Level level(p_levelName);

	// Initialize the shadow shapes. 
	std::vector<Line> lines = level.GetShadowsShapes();
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		ShadowShapes::GetInstance().AddStaticLine(lines[i]);
	}

	// Initialize the object manager.
	m_objectManager = new ObjectManager();
	m_objectManager->SetSound(m_sound);
	m_objectManager->Initialize(&level);

	// Load and place arena walls.
	std::vector<LevelImporter::LevelBoundingBox> temp = level.GetLevelBoundingBoxes();
	std::vector<Box> wallList;
	for (unsigned int i = 0; i < temp.size(); i++)
	{
		LevelImporter::LevelBoundingBox box = temp[i];
		wallList.push_back(Box(box.m_translationX, box.m_translationY, box.m_translationZ, box.m_halfDepth, box.m_halfHeight, box.m_halfWidth));
	}

	// Initiate the player.
	m_playerManager = new PlayerManager();
	m_playerManager->SetSound(m_sound);
	m_playerManager->Initialize(false);
	CollisionManager::GetInstance()->Initialize(m_objectManager->GetStaticObjectList(), m_objectManager->GetAnimatedObjectList(), wallList);

	// Initlialize the frustum.
	m_frustum = new Frustum();
	m_updateFrustum = true;
	m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	m_objectManager->UpdateFrustum(m_frustum);
	m_playerManager->UpdateFrustum(m_frustum);

	// Initialize the minimap.
	m_minimap = new Minimap();
	m_minimap->Initialize();
	
	// Initialize the score board
	ScoreBoard::GetInstance()->Initialize();
	
	// Initialize the team status bar.
	m_teamStatusBar = new TeamStatusBar();
	if (!m_teamStatusBar->Initialize())
	{
		return false;
	}

	// Initialize the directional light.
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.18f*0.25, 0.34f*0.25, 0.48f*0.25, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.18f, 0.34f, 0.48f, 1.0f);
	//m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.4f, 0.4f, 1.125f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.77f, 0.94f, 0.94f, 1.0f);
	//m_directionalLight.m_specular = DirectX::XMVectorSet(5.525f*0.5f, 5.525f*0.5f, 5.525f, 1.0f);
	DirectX::XMFLOAT4 direction = DirectX::XMFLOAT4(-1.0f, -4.0f, -2.0f, 0.0f);
	DirectX::XMStoreFloat4(&direction, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat4(&direction), DirectX::XMLoadFloat4x4(&m_camera->GetViewMatrix())));
	m_directionalLight.m_direction = DirectX::XMVector3Normalize(DirectX::XMLoadFloat4(&direction));

	ConsolePrintSuccess("Light source initialized successfully.");
	ConsoleSkipLines(1);

	// Initialize the Countdown.
	m_countdown = new Countdown();
	if(!m_countdown->Initialize())
	{
		return false;
	}

	m_renderOutlining = false;

	m_mouseX = 0;
	m_mouseY = 0;

	OnScreenResize();
	VisibilityComputer::GetInstance().UpdateVisibilityPolygon(Point(m_playerManager->GetPlayerPosition().x, m_playerManager->GetPlayerPosition().z), GraphicsEngine::GetInstance()->GetDevice());

	m_spectateIndex = -1;
	m_spectateCountDown = 0.0f;

	m_inGameMenuIsActive = false;
	m_inGameMenu = new InGameMenu();
	m_inGameMenu->Initialize();

	m_victoryMenu = new VictoryScreenMenu();
	if (!m_victoryMenu->Initialize())
	{
		return false;
	}

	m_suddenDeath = new SuddenDeathState();
	m_suddenDeath->Initialize();

	return true;
}

void PlayingState::Shutdown()
{
	if (m_suddenDeath != nullptr)
	{
		m_suddenDeath->Shutdown();
		delete m_suddenDeath;
		m_suddenDeath = nullptr;
	}

	ScoreBoard::GetInstance()->Shutdown();

	if (m_victoryMenu != nullptr)
	{
		m_victoryMenu->Shutdown();
		delete m_victoryMenu;
		m_victoryMenu = nullptr;
	}

	if (m_inGameMenu != nullptr)
	{
		m_inGameMenu->Shutdown();
		delete m_inGameMenu;
		m_inGameMenu = nullptr;
	}

	if (m_camera != nullptr)
	{
		m_camera->Shutdown();
		delete m_camera;
		m_camera = nullptr;
	}

	if (m_playerManager != nullptr)
	{
		m_playerManager->Shutdown();
		delete m_playerManager;
		m_playerManager = nullptr;
	}

	if (m_objectManager != nullptr)
	{
		m_objectManager->Shutdown();
		delete m_objectManager;
		m_objectManager = nullptr;
	}

	if (m_minimap != nullptr)
	{
		m_minimap->Shutdown();
		delete m_minimap;
		m_minimap = nullptr;
	}

	if (m_teamStatusBar != nullptr)
	{
		m_teamStatusBar->Shutdown();
		delete m_teamStatusBar;
		m_teamStatusBar = nullptr;
	}

	if (m_countdown != nullptr)
	{
		m_countdown->Shutdown();
		delete m_countdown;
		m_countdown = nullptr;
	}

	if (m_frustum != nullptr)
	{
		m_frustum->Shutdown();
		delete m_frustum;
		m_frustum = nullptr;
	}

	if (CollisionManager::GetInstance() != nullptr)
	{
		CollisionManager::GetInstance()->Shutdown();
	}
}

void PlayingState::ShutdownExit()
{
	if (m_objectManager != nullptr)
	{
		m_objectManager->ShutdownExit();
	}
}

GAMESTATESWITCH PlayingState::Update()
{
	// Check if a new level have started.
	if (Network::GetInstance()->IsConnected() && Network::GetInstance()->NewLevel())
	{
		std::string levelName = Network::GetInstance()->LevelName();
		Network::GetInstance()->SetHaveUpdateNewLevel();
		Shutdown();

		return GAMESTATESWITCH_CHOOSENINJA;
	}

	// Update global delta time.
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	
	CollisionManager::GetInstance()->Update(m_mouseX, m_mouseY);

	// Get picking data.
	BasicPicking();
	m_playerManager->SetStickyTrapList(m_objectManager->GetStickyTrapList());
	m_playerManager->Update(false);

	if (!m_playerManager->GetPlayerIsAlive())
	{
		if (!GLOBAL::GetInstance().CAMERA_SPECTATE)
		{
			m_spectateCountDown = 2.0f;
		}

		GLOBAL::GetInstance().CAMERA_SPECTATE = true;
	}

	else 
	{
		GLOBAL::GetInstance().CAMERA_SPECTATE = false;
		m_spectateIndex = -1;
	}

	if (m_spectateCountDown > 0.0f)
	{
		m_spectateCountDown -= (float)deltaTime;
	}

	// Calculate new visibility polygon boundries.
	DirectX::XMFLOAT3 player = m_playerManager->GetPlayerPosition();

	// Update sudden death gas if the time is right.
	if (Network::GetInstance()->IsSuddenDeath())
	{
		m_suddenDeath->Update();
	}

	// Handle camera input.
	m_camera->HandleInput();

	// The camera should follow the character if not flying.
	if (GLOBAL::GetInstance().CAMERA_FLYING)
	{
		// Handle camera input.
		m_camera->HandleInput();
	}
	else if (Network::GetInstance()->GetMatchOver())
	{
		if (Network::GetInstance()->GetRestartingTimer() <= 7)
		{
			m_camera->MenuCameraRotation();
		}

		switch (m_victoryMenu->Update())
		{
			case IN_GAME_MENU_CONTINUE:
			{
				return GAMESTATESWITCH_CHOOSENINJA;

				break;
			}

			case IN_GAME_MENU_TO_MAIN:
			{
				Network::GetInstance()->Disconnect();
				return GAMESTATESWITCH_MENU;

				break;
			}
		}
	}

	else if (GLOBAL::GetInstance().CAMERA_SPECTATE && m_spectateCountDown <= 0.0f)
	{
		player = m_playerManager->GetTeamMemberPosSpectate(m_spectateIndex, m_playerManager->GetPlayerTeam());
		m_camera->FollowCharacter(player);
	}

	else
	{
		m_camera->FollowCharacter(player);
	}

	if (InputManager::GetInstance()->IsLeftMouseClicked() && GLOBAL::GetInstance().CAMERA_SPECTATE)
	{
		m_spectateIndex += 1;
	}

	// Update every scene object.
	TrailRenderer::GetInstance().SetViewMatrix(m_camera->GetViewMatrix());
	TrailRenderer::GetInstance().SetProjectionMatrix(m_camera->GetProjectionMatrix());
	m_objectManager->Update();
	OBB playerOBB = m_playerManager->GetPlayerBoundingBox();

	// Update health bars.
	m_playerManager->UpdateHealthbars(m_camera->GetViewMatrix(), m_camera->GetProjectionMatrix());

	// Run debug checks.
	if (FLAG_DEBUG == 1)
	{
		if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('l')))
		{
			m_updateFrustum = false;
		}

		if (GetAsyncKeyState(VK_BACK))
		{
			m_updateFrustum = true;
		}
	}

	// Update the frustum.
	if (m_updateFrustum)
	{
		m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
		m_objectManager->UpdateFrustum(m_frustum);
		m_playerManager->UpdateFrustum(m_frustum);
	}

	// Update the minimap.
	m_minimap->Update(m_playerManager->GetPlayerPosition());
	MinimapUpdatePos(m_minimap);
	m_minimap->SetPlayerTexture(m_playerManager->GetPlayerTeam());
	for (int i = 0; i < 7; i++)
	{
		m_minimap->SetTeamTexture(i, m_playerManager->GetEnemyTeam(i));
	}

	// Update the team status bar.
	m_teamStatusBar->Update();

	// Update the directional light camera position.
	m_directionalLight.m_cameraPosition = DirectX::XMLoadFloat3(&m_camera->GetPosition());
	
	OutliningRays();

	// Check if the screen changed.
	bool resized = false;
	if (GraphicsEngine::GetInstance()->HasScreenChanged())
	{
		OnScreenResize();
		resized = true;
	} 
	
	Point topLeft = Point(player.x - m_quadWidth, player.z + m_quadHeightTop);
	Point bottomLeft = Point(player.x + m_quadWidth, player.z - m_quadHeightBottom - 10.0f);
	
	// Keep the the visibility polygon boundries within the maps boundries.
	topLeft.x < -45.0f ? topLeft.x = -45.0f : topLeft.x;
	topLeft.y > 52.0f ? topLeft.y = 52.0f : topLeft.y;
	bottomLeft.x > 45.0f ? bottomLeft.x = 45.0f : bottomLeft.x;
	bottomLeft.y < -52.0f ? bottomLeft.y = -52.0f : bottomLeft.y;

	// Update the visibility polygon boundries.
	VisibilityComputer::GetInstance().UpdateMapBoundries(topLeft, bottomLeft);

	// Update the countdown.
	m_countdown->Update();

	// Update scoreboard
	ScoreBoard::GetInstance()->Update();
	
	if (resized)
	{
		// Reupdate the polygon.
		VisibilityComputer::GetInstance().UpdateVisibilityPolygon(Point(player.x, player.z), GraphicsEngine::GetInstance()->GetDevice());
	}

	// Update smokebomb shadow shapes.
	ShadowShapes::GetInstance().Update(); 
	
	// Set have updated network stuff last in the update.
	Network::GetInstance()->SetHaveUpdatedAfterRestartedRound();
	
	DeathBoard::GetInstance()->Update();

	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan(VK_TAB)))
	{
		//ScoreBoard::GetInstance()->Render();
		m_scoreBoardIsActive = true;
	}

	else
	{
		m_scoreBoardIsActive = false;
	}

	BasicPicking();

	if (m_inGameMenuIsActive && !Network::GetInstance()->GetMatchOver())
	{
		switch (m_inGameMenu->Update())
		{
			case IN_GAME_MENU_RESUME:
			{
				m_inGameMenuIsActive = false;
				m_sound->StopMusic();

				break;
			}
			case IN_GAME_MENU_TO_MAIN:
			{
				Network::GetInstance()->Disconnect();
				return GAMESTATESWITCH_MENU;
				break;
			}
			case IN_GAME_MENU_QUIT:
			{
				PostQuitMessage(0);
				break;
			}
			default:
			{
				break;
			}
		}
	}

	m_camera->Update3DSound(m_sound, player.x, player.y, player.z);

	return GAMESTATESWITCH_NONE;
}

void PlayingState::Render()
{
	// Draw to the shadowmap.
	GraphicsEngine::GetInstance()->BeginRenderToShadowMap();
	m_objectManager->RenderDepth();
	m_playerManager->RenderDepth(false);
	GraphicsEngine::GetInstance()->SetShadowMap();

	GraphicsEngine::GetInstance()->SetSceneDirectionalLight(m_directionalLight);

	// Render to the scene normally.
	GraphicsEngine::GetInstance()->ClearRenderTargetsForGBuffers();
	GraphicsEngine::GetInstance()->SetRenderTargetsForGBuffers();
	m_objectManager->Render();
	m_playerManager->Render(false);
	
	GraphicsEngine::GetInstance()->RenderFoliage();
	
	GraphicsEngine::GetInstance()->SetSSAOBuffer(m_camera->GetProjectionMatrix());
	GraphicsEngine::GetInstance()->RenderSSAO();

	// Composition
	GraphicsEngine::GetInstance()->SetScreenBuffer(m_directionalLight, m_camera->GetProjectionMatrix());
	PointLights::GetInstance()->SetLightBuffer(m_camera->GetViewMatrix());

	GraphicsEngine::GetInstance()->Composition();
	GraphicsEngine::GetInstance()->ApplyDOF();

	GraphicsEngine::GetInstance()->SetForwardRenderTarget();
	GraphicsEngine::GetInstance()->TurnOnAlphaBlending();

	GraphicsEngine::GetInstance()->ResetRenderTarget();
	GraphicsEngine::GetInstance()->SetDepthStateForParticles();
	VisibilityComputer::GetInstance().RenderVisibilityPolygon(GraphicsEngine::GetInstance()->GetContext());
	GraphicsEngine::GetInstance()->TurnOnDepthStencil();

	if (FLAG_DEBUG == 1)
	{
		ShadowShapes::GetInstance().DebugRender();	
	}	

	// Render the UI.
	if (Network::GetInstance()->GetMatchOver())
	{
		m_victoryMenu->Render();
	}

	// Render the UI.
	m_minimap->Render();
	m_teamStatusBar->Render();
	m_countdown->Render();
	DeathBoard::GetInstance()->Render();

	GraphicsEngine::GetInstance()->TurnOffAlphaBlending();

	if (Network::GetInstance()->IsSuddenDeath())
	{
		m_suddenDeath->Render(m_camera);
	}

	// Render character outlining.
	if (m_renderOutlining)
	{
		GraphicsEngine::GetInstance()->ClearOutlining();
		GraphicsEngine::GetInstance()->SetOutliningPassOne();
		m_playerManager->RenderOutliningPassOne();
		GraphicsEngine::GetInstance()->SetOutliningPassTwo();
		m_playerManager->RenderOutliningPassTwo();
	}

	if (m_inGameMenuIsActive && !Network::GetInstance()->GetMatchOver())
	{
		m_inGameMenu->Render();
	}

	if (m_scoreBoardIsActive)
	{
		ScoreBoard::GetInstance()->Render();
	}

	GraphicsEngine::GetInstance()->ResetRenderTarget();
}

void PlayingState::ToggleFullscreen(bool p_fullscreen)
{
	m_camera->ToggleFullscreen(p_fullscreen);
}

void PlayingState::BasicPicking()
{
	float mouseOffsetX = 0.0f;
	float mouseOffsetY = 0.0f;

	if (!GLOBAL::GetInstance().FULLSCREEN)
	{
		mouseOffsetX = 6.0f;
		mouseOffsetY = 20.0f;
	}

	float mousePosX = InputManager::GetInstance()->GetMousePositionX() + mouseOffsetX;
	float mousePosY = InputManager::GetInstance()->GetMousePositionY() + mouseOffsetY;

	DirectX::XMFLOAT3 shurPos = Pick(Point(mousePosX, mousePosY));
	DirectX::XMFLOAT3 shurDir = DirectX::XMFLOAT3(-(m_playerManager->GetPlayerPosition().x - shurPos.x), -(m_playerManager->GetPlayerPosition().y - shurPos.y), -(m_playerManager->GetPlayerPosition().z - shurPos.z));
	
	if (!Network::GetInstance()->GetMatchOver())
	{
		m_playerManager->SetAttackDirection(NormalizeFloat3(shurDir));
	}

	m_mouseX = shurPos.x;
	m_mouseY = shurPos.z;
	InputManager::GetInstance()->Set3DMousePosition(m_mouseX, m_mouseY);
}

DirectX::XMFLOAT3 PlayingState::Pick(Point p_point)
{
	DirectX::XMFLOAT3 rayDir;
	DirectX::XMFLOAT3 rayPos = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);

	DirectX::XMFLOAT4X4 proj = m_camera->GetProjectionMatrix();
	float viewSpaceX = (2.0f * p_point.x / (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH - 1) / proj._11;
	float viewSpaceY = -((2.0f * p_point.y / (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT - 1) / proj._22);
	float viewSpaceZ = 1.0f;

	rayDir = DirectX::XMFLOAT3(viewSpaceX, viewSpaceY, viewSpaceZ);

	DirectX::XMFLOAT4X4 viewInverse;
	DirectX::XMVECTOR determinant;
	DirectX::XMStoreFloat4x4(&viewInverse, DirectX::XMMatrixInverse(&determinant, DirectX::XMLoadFloat4x4(&m_camera->GetViewMatrix())));

	DirectX::XMStoreFloat3(&rayPos, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&rayPos), DirectX::XMLoadFloat4x4(&viewInverse)));
	DirectX::XMStoreFloat3(&rayDir, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&rayDir), DirectX::XMLoadFloat4x4(&viewInverse)));

	float t = -rayPos.y / rayDir.y;

	return DirectX::XMFLOAT3(rayPos.x + t*rayDir.x, rayPos.y + t*rayDir.y, rayPos.z + t*rayDir.z);
}

void PlayingState::OutliningRays()
{

	DirectX::XMFLOAT3 rayDir;
	DirectX::XMFLOAT3 rayPos = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	float rayDist = 0;
	float collisionDist = 0;

	rayPos = m_camera->GetPosition();
	rayDir = DirectX::XMFLOAT3(m_camera->GetViewMatrix()._13, m_camera->GetViewMatrix()._23, m_camera->GetViewMatrix()._33);
	Ray* rayTest = new Ray(rayPos, rayDir);

	if (Collisions::RayOBBCollision(rayTest, m_playerManager->GetPlayerBoundingBox()))
	{
		if (rayTest->m_distance != 0)
		{
			rayDist = rayTest->m_distance;
		}
	}

	if (CollisionManager::GetInstance()->CalculateRayLength(rayTest, rayDist))
	{
		m_renderOutlining = true;
	}

	else
	{
		m_renderOutlining = false;
	}
	
	delete rayTest;
}

DirectX::XMFLOAT3 PlayingState::NormalizeFloat3(DirectX::XMFLOAT3 p_f)
{
	float t2 = sqrt(p_f.x * p_f.x + p_f.y * p_f.y + p_f.z * p_f.z);

	return DirectX::XMFLOAT3(p_f.x / t2, p_f.y / t2, p_f.z/t2);
}

void PlayingState::MinimapUpdatePos(Minimap *p_minimap)
{
	for (unsigned int i = 0; i < 7; i++)
	{
		m_minimap->SetPlayerPos(i, DirectX::XMFLOAT3(-1000, -1000, 0));

		Player* player = m_playerManager->GetEnemyTeamMember(i);

		if (player && (m_playerManager->GetPlayerTeam() == m_playerManager->GetEnemyTeam(i) || VisibilityComputer::GetInstance().IsPointVisible(Point(player->GetPosition().x, player->GetPosition().z))))
		{
			p_minimap->UpdatePlayersPositon(i, player->GetPosition());
		}
	}
}

ObjectManager* PlayingState::GetObjectManager()
{
	return m_objectManager;
}

void PlayingState::OnScreenResize()
{
	float width = (float)GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
	float height = (float)GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;

	// Update texture size.
	VisibilityComputer::GetInstance().UpdateTextureSize((int)width, (int)height);

	// Get the new edges.
	DirectX::XMFLOAT3 pickedTopLeft = Pick(Point(0.0f, 0.0f));
	DirectX::XMFLOAT3 pickedTopRight = Pick(Point(width, 0.0f));
	DirectX::XMFLOAT3 pickedBottomRight = Pick(Point(width, height));
	DirectX::XMFLOAT3 pickedPlayer = Pick(Point(width * 0.5f, height * 0.5f));

	m_quadWidth = pickedPlayer.x - pickedTopLeft.x;
	m_quadHeightTop = pickedTopLeft.z - pickedPlayer.z;
	m_quadHeightBottom = pickedPlayer.z - pickedBottomRight.z;

	// Update projection matrix.
	DirectX::XMFLOAT4X4 projection;
	DirectX::XMStoreFloat4x4(&projection, DirectX::XMMatrixOrthographicLH(m_quadWidth * 2.0f, m_quadHeightTop + m_quadHeightBottom, 1.0f, 100.0f));
	VisibilityComputer::GetInstance().SetProjectionPolygonMatrix(projection);

	// Tell the graphics engine that changes have been handled.
	GraphicsEngine::GetInstance()->ScreenChangeHandled();
}

void PlayingState::SetSound(Sound* p_sound)
{
	m_sound = p_sound;
}