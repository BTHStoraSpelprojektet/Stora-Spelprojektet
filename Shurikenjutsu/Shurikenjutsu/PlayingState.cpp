#include "PlayingState.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "Collisions.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
#include "Frustum.h"
#include "Camera.h"
#include "Globals.h"
#include "Minimap.h"
#include "TeamStatusBar.h"
#include "Countdown.h"
#include "InGameMenu.h"
#include "VictoryScreenMenu.h"
#include "DeathBoard.h"
#include "ScoreBoard.h"
#include "SuddenDeathState.h"
#include "Sound.h"
#include "POIGrapichalEffects.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include "..\CommonLibs\ModelNames.h"

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
	// Set pressed or release
	GLOBAL::GetInstance().APE_ON = false;

	// Initialize the camera.
	m_camera = new Camera();
	m_camera->Initialize();
	m_camera->ResetCamera();

	// Load the level.
	Level level(p_levelName);
	GraphicsEngine::SS_ClearStaticLines();
	// Initialize the shadow shapes. 
	std::vector<Line> lines = level.GetShadowsShapes();
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		GraphicsEngine::SS_AddStaticLine(lines[i]);
	}

	// Initialize the object manager.
	m_objectManager = new ObjectManager();
	m_objectManager->SetSound(m_sound);
	m_objectManager->Initialize(&level);
	// Send which runes have spawned
	Network::GetInstance()->SendSpawnedRunes();

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
	
	m_startText = new GUIText();
	m_startText->Initialize("Round started\nFight enemy team!", 70.0f, 0.0f, 0.0f, 0xffffffff);
	m_poiText = new GUIText();
	m_poiText->Initialize(" ", 50.0f, 0.0f, 0.0f, 0xffffffff);
	m_playerJoinedText = new GUIText();
	m_playerJoinedText->Initialize(" ", 50.0f, 0.0f, 250.0f, 0xffffffff);

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
	m_directionalLight.m_direction = DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(-1.0f, -4.0f, -2.0f, 0.0f));

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
	GraphicsEngine::UpdateVisibilityPolygon(Point(m_playerManager->GetPlayerPosition().x, m_playerManager->GetPlayerPosition().z), (float)GLOBAL::GetInstance().GetDeltaTime());

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

	POIGrapichalEffects::GetInstance().Initialize();

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

	if (m_startText != nullptr)
	{
		m_startText->Shutdown();
		delete m_startText;
		m_startText = nullptr;
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

	if (m_playerJoinedText != nullptr)
	{
		m_playerJoinedText->Shutdown();
		delete m_playerJoinedText;
		m_playerJoinedText = nullptr;
	}

	if (m_poiText != nullptr)
	{
		m_poiText->Shutdown();
		delete m_poiText;
		m_poiText = nullptr;
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
	
	POIGrapichalEffects::GetInstance().Shutdown();
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

	for (unsigned int i = 0; i < 3; i++)
	{
		DecreaseTextOpacity(m_startText);
		DecreaseTextOpacity(m_poiText);
		DecreaseTextOpacity(m_playerJoinedText);
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
	else if (GLOBAL::GetInstance().CAMERA_SPECTATE)
	{
		std::vector<Player*> tempList = m_playerManager->GetMyTeamPlayers(m_playerManager->GetPlayerTeam());
		if (m_spectateIndex > ((int)tempList.size() - 1) || m_spectateIndex < 0)
		{
			m_spectateIndex = 0;
		}
		if (tempList.size() != 0)
		{
			player = tempList[m_spectateIndex]->GetPosition();
			m_camera->FollowCharacter(player);
		}
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

	if (Network::GetInstance()->GetNewPlayerJoined())
	{
		PlayerJoinedText();
	}

	// Update the directional light camera position.
	m_directionalLight.m_cameraPosition = DirectX::XMLoadFloat3(&m_camera->GetPosition());
	
	OutliningRays();

	// Check if the screen changed.
	bool resized = false;
	if (GraphicsEngine::HasScreenChanged())
	{
		OnScreenResize();
		resized = true;
	} 
	
	// Update the countdown.
	m_countdown->Update();

	// Update scoreboard
	ScoreBoard::GetInstance()->Update();
	
	if (resized)
	{
		// Reupdate the polygon.
		GraphicsEngine::UpdateVisibilityPolygon(Point(player.x, player.z), (float)GLOBAL::GetInstance().GetDeltaTime());
	}

	// Update smokebomb shadow shapes.
	GraphicsEngine::SS_Update((float)GLOBAL::GetInstance().GetDeltaTime());
	
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

	SSBoundryUpdate(player);

	return GAMESTATESWITCH_NONE;
}

void PlayingState::Render()
{
	// Draw to the shadowmap.
	GraphicsEngine::BeginRenderToShadowMap();
	m_objectManager->RenderDepth();
	m_playerManager->RenderDepth(false);
	GraphicsEngine::SetShadowMap();

	GraphicsEngine::SetSceneDirectionalLight(m_directionalLight);

	// Render to the scene normally.
	GraphicsEngine::ClearRenderTargetsForGBuffers();
	GraphicsEngine::SetRenderTargetsForGBuffers();
	UpdatePOIEffects();
	m_objectManager->Render();
	m_playerManager->Render(false);
	
	GraphicsEngine::RenderFoliage();
	
	GraphicsEngine::SetSSAOBuffer(m_camera->GetProjectionMatrix());
	GraphicsEngine::RenderSSAO();

	// Composition
	GraphicsEngine::SetScreenBuffer(m_directionalLight, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	GraphicsEngine::SetPointLightLightBuffer(m_camera->GetViewMatrix());

	GraphicsEngine::Composition();
	GraphicsEngine::ApplyDOF();

	GraphicsEngine::SetForwardRenderTarget();
	GraphicsEngine::TurnOnAlphaBlending();

	GraphicsEngine::ResetRenderTarget();
	GraphicsEngine::SetDepthStateForParticles();
	GraphicsEngine::RenderVisibilityPolygon(Network::GetInstance()->GetMatchOver());
	GraphicsEngine::TurnOnDepthStencil();

	if (FLAG_DEBUG == 1)
	{
		GraphicsEngine::SS_DebugRender();
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

	GraphicsEngine::TurnOffAlphaBlending();

	if (Network::GetInstance()->IsSuddenDeath())
	{
		m_suddenDeath->Render(m_camera);
	}

	// Render character outlining.
	if (m_renderOutlining)
	{
		GraphicsEngine::ClearOutlining();
		GraphicsEngine::SetOutliningPassOne();
		m_playerManager->RenderOutliningPassOne();
		GraphicsEngine::SetOutliningPassTwo();
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

	m_startText->Render();
	if (Network::GetInstance()->GetRoundOver())
	{
		m_startText->SetColor(0xffffffff);
		Network::GetInstance()->RoundOverText();
	}

	m_poiText->Render();
	if (Network::GetInstance()->GetPoiSpawned())
	{
		m_poiText->SetText("Runes have spawned!");
		m_poiText->SetColor(0xffffffff);
		Network::GetInstance()->PoiText();
	}

	m_playerJoinedText->Render();

	GraphicsEngine::ResetRenderTarget();
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
	DirectX::XMFLOAT3 target;
	DirectX::XMFLOAT3 rayDir;
	DirectX::XMFLOAT3 rayPos = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	float rayDist = 0;
	float collisionDist = 0;

	rayPos = m_camera->GetOutliningRayPosition();
	target = m_camera->GetOutliningRayTarget();

	// Increase height of check
	target.y += 1;

	DirectX::XMStoreFloat3(&rayDir, DirectX::XMVectorSubtract(DirectX::XMLoadFloat3(&target), DirectX::XMLoadFloat3(&rayPos)));
	DirectX::XMStoreFloat3(&rayDir,	DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&rayDir)));

	Ray* ray = new Ray(rayPos, rayDir);

	if (Collisions::RayOBBCollision(ray, m_playerManager->GetPlayerBoundingBox()))
	{
		if (ray->m_distance != 0)
		{
			rayDist = ray->m_distance;
		}
	}

	if (CollisionManager::GetInstance()->CalculateRayLength(ray, rayDist))
	{
		m_renderOutlining = true;
	}
	else
	{
		m_renderOutlining = false;
	}
	
	delete ray;
}

DirectX::XMFLOAT3 PlayingState::NormalizeFloat3(DirectX::XMFLOAT3 p_f)
{
	float t2 = sqrt(p_f.x * p_f.x + p_f.y * p_f.y + p_f.z * p_f.z);

	return DirectX::XMFLOAT3(p_f.x / t2, p_f.y / t2, p_f.z/t2);
}

void PlayingState::MinimapUpdatePos(Minimap *p_minimap)
{
	std::vector<RakNet::RakNetGUID> visiblePlayers = std::vector<RakNet::RakNetGUID>();
	for (unsigned int i = 0; i < 7; i++)
	{
		m_minimap->SetPlayerPos(i, DirectX::XMFLOAT3(-1000, -1000, 0));

		Player* player = m_playerManager->GetEnemyTeamMember(i);

		if (player && player->GetIsAlive() && !player->IsInvis())
		{
			if ((m_playerManager->GetPlayerTeam() == m_playerManager->GetEnemyTeam(i) || GraphicsEngine::IsVisibilityPointVisible(Point(player->GetPosition().x, player->GetPosition().z))))
			{
				p_minimap->UpdatePlayersPositon(i, player->GetPosition());
				visiblePlayers.push_back(player->GetGuID());
			}
			else if (player &&  Network::GetInstance()->IsEnemyVisible(player->GetGuID()))
			{
				p_minimap->UpdatePlayersPositon(i, player->GetPosition());
			}
		}
		Network::GetInstance()->SetVisiblePlayers(visiblePlayers);
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
	GraphicsEngine::UpdateVisibilityTextureSize(width, height);

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
	GraphicsEngine::SetVisibilityProjectionPolygonMatrix(projection);
	// Tell the graphics engine that changes have been handled.
	GraphicsEngine::ScreenChangeHandled();
}

void PlayingState::SetSound(Sound* p_sound)
{
	m_sound = p_sound;
}

void PlayingState::DecreaseTextOpacity(GUIText* p_text)
{
	if (p_text->GetColor() < 16777216)
	{
		p_text->SetColor(0);
	}
	else
	{
		p_text->SetColor(p_text->GetColor() - 16777216);
	}
}

void PlayingState::SSBoundryUpdate(DirectX::XMFLOAT3 p_player)
{
	float width = (float)GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
	float height = (float)GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;

	// Get the new edges.
	DirectX::XMFLOAT3 pickedTopLeft = Pick(Point(0.0f, 0.0f));
	DirectX::XMFLOAT3 pickedTopRight = Pick(Point(width, 0.0f));
	DirectX::XMFLOAT3 pickedBottomRight = Pick(Point(width, height));
	DirectX::XMFLOAT3 pickedPlayer = Pick(Point(width * 0.5f, height * 0.5f));

	m_quadWidth = pickedPlayer.x - pickedTopLeft.x;
	m_quadHeightTop = pickedTopLeft.z - pickedPlayer.z;
	m_quadHeightBottom = pickedPlayer.z - pickedBottomRight.z;

	Point topLeft = Point(p_player.x - m_quadWidth - 10.0f, p_player.z + m_quadHeightTop + 10.0f);
	Point bottomLeft = Point(p_player.x + m_quadWidth + 10.0f, p_player.z - m_quadHeightBottom - 10.0f);

	// Update the visibility polygon boundries.
	GraphicsEngine::UpdateVisibilityMapBoundries(topLeft, bottomLeft);
}

void PlayingState::PlayerJoinedText()
{
	std::vector<PlayerNet> players = Network::GetInstance()->GetOtherPlayers();
	players.push_back(Network::GetInstance()->GetMyPlayer());

	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (players[i].guid == Network::GetInstance()->GetJustJoinedPlayer())
		{
			Network::GetInstance()->JoinedPlayerText();
			m_playerJoinedText->SetColor(0xffffffff);

			if (players[i].team == 1)
			{
				std::string text = players[i].name.C_String();
				text += " has joined the red team";
				m_playerJoinedText->SetText(text);
			}
			else if (players[i].team == 2)
			{
				std::string text = players[i].name.C_String();
				text += " has joined the blue team";
				m_playerJoinedText->SetText(text);
			}
		}
	}
}

void PlayingState::UpdatePOIEffects()
{
	if (Network::GetInstance()->GetMyPlayer().invis && Network::GetInstance()->GetMyPlayer().isAlive)
	{
		POIGrapichalEffects::GetInstance().RenderStealthEffect();
	}

	std::vector<PlayerNet> NetworkPlayers = Network::GetInstance()->GetOtherPlayers();
	NetworkPlayers.push_back(Network::GetInstance()->GetMyPlayer());

	for (unsigned int i = 0; i < NetworkPlayers.size(); i++)
	{
		if (!NetworkPlayers[i].invis)
		{
			DirectX::XMFLOAT3 position;

			if (NetworkPlayers.size() == m_playerManager->GetEveryPlayer().size())
			{
				position = m_playerManager->GetEveryPlayer()[i]->GetPosition();
			}

			else
			{
				position = DirectX::XMFLOAT3(NetworkPlayers[i].x, NetworkPlayers[i].y, NetworkPlayers[i].z);
			}

			if (NetworkPlayers[i].shield > 0.0f)
			{

				POIGrapichalEffects::GetInstance().UpdateShieldEffect(position, m_camera->GetViewMatrix(), m_camera->GetProjectionMatrix());
				POIGrapichalEffects::GetInstance().RenderShieldEffect();
			}

			if (NetworkPlayers[i].hasHealPOI)
			{
				position.y = 0.25f;
				POIGrapichalEffects::GetInstance().UpdateHealingEffect(position);
				POIGrapichalEffects::GetInstance().RenderHealingEffect();
			}
		}
		
	}
}