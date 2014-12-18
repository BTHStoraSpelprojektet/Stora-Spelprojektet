#include "GameState.h"

GameState::GameState()
{
}


GameState::~GameState()
{
}

bool GameState::Initialize()
{
	return true;
}

void GameState::Shutdown()
{

}

GAMESTATESWITCH GameState::Update()
{
	return GAMESTATESWITCH_NONE;
}

void GameState::Render()
{

}

void GameState::RenderAlpha()
{

}

void GameState::ToggleFullscreen(bool p_fullscreen)
{

}