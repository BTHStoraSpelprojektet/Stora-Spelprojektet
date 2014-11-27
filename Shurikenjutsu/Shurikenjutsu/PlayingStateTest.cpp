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
	//float aspectRatio = .0f//(float)((window.width - 16) / (window.height - 39));
	m_camera.UpdateAspectRatio(1.0f);

	m_playerManager.Initialize();

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(0.0f, 20.0f, -10.0f);
	DirectX::XMFLOAT3 target = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);

	m_camera.UpdatePosition(position);
	m_camera.UpdateTarget(target);

	// Look vector.
	DirectX::XMFLOAT3 look = DirectX::XMFLOAT3(0.0f, -20.0f, 10.0f);
	m_camera.UpdateLook(look);

	// Up vector.
	DirectX::XMFLOAT3 right = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);
	DirectX::XMFLOAT3 up = DirectX::XMFLOAT3(0.0f, 10.0f, -20.0f);

	m_camera.UpdateUpVector(up);


	m_camera.UpdateRight(right);

	// Projection data.
	m_camera.UpdateFieldOfView(3.141592f * 0.5f);
	m_camera.UpdateAspectRatio(1.0f);
	m_camera.UpdateClippingPlanes(0.001f, 40.0f);
	m_camera.UpdateViewMatrix();
	m_camera.UpdateProjectionMatrix();

	GraphicsEngine::SetSceneViewAndProjection(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());

	m_camera.ResetCamera();

	return true;
}

void PlayingStateTest::Update(double p_deltaTime)
{
	// Temporary "Shuriken" spawn
	if (InputManager::GetInstance()->IsLeftMouseClicked())
	{
		m_objectManager.AddShuriken("../Shurikenjutsu/Models/shurikenShape.SSP", m_playerManager.GetPosition(0), DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f), 10.0f);
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
}

void PlayingStateTest::Render()
{
	std::vector<Player> tempList1 = m_playerManager.GetListOfPlayers();
	for (unsigned int i = 0; i < tempList1.size(); i++)
	{
		Model tempModel1 = tempList1[i].GetModel();
		GraphicsEngine::Render(SHADERTYPE_SCENE, tempModel1.GetMesh(), tempModel1.GetVertexCount(), tempModel1.GetWorldMatrix(), tempModel1.GetTexture());
	}

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