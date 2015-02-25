#include "ScoreBoard.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"

ScoreBoard::ScoreBoard()
{

}

ScoreBoard::~ScoreBoard()
{

}

bool ScoreBoard::Initialize()
{
	m_boardHeight = 626.0f;
	m_boardWidth = 514.0f;

	m_background = new GUIElement();
	m_background->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), m_boardWidth, m_boardHeight, TextureLibrary::GetInstance()->GetTexture(SCOREBOARD_BACKGROUND));
	return true;
}

void ScoreBoard::Shutdown()
{

}

void ScoreBoard::Update()
{

}

void ScoreBoard::Render()
{
	m_background->QueueRender();
}