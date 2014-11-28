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
	m_playerManager.Render();

	//Draw level objects
	std::vector<Model> tempModelList = m_objectManager.GetListOfStaticModels();
	for (unsigned int i = 0; i < tempModelList.size(); i++)
	{
		Model tempModel = tempModelList[i];
		//std::cout << "VtxCount: " << tempModel.GetVertexCount() << "\n";
		GraphicsEngine::Render(SHADERTYPE_SCENE, tempModel.GetMesh(), tempModel.GetVertexCount(), tempModel.GetWorldMatrix(), tempModel.GetTexture());
	}

	m_objectManager.Render();
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