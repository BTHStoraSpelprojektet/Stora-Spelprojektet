#include "Player.h"
#include <iostream>
#include "..\CommonLibs\ConsoleFunctions.h"

Player::Player(){}
Player::~Player(){}

bool Player::Initialize(std::string p_modelName, RakNet::RakNetGUID p_guid, int p_team, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction)
{
	m_boundingBoxes = ModelLibrary::GetInstance()->GetModel(p_modelName)->GetBoundingBoxes();
	m_guid = p_guid;
	m_team = p_team;
	m_position = p_position;
	m_direction = p_direction;
	m_gcd = 0.0f;

	ConsolePrintText("New player added.");
	ConsoleSkipLines(1);

	return false; // TODO, change all of this class.
}

void Player::Shutdown()
{
}

void Player::Update(double p_deltaTime)
{
}

void Player::Move(DirectX::XMFLOAT3 p_position)
{
}

void Player::Rotate(DirectX::XMFLOAT3 p_rotation)
{
}

void Player::Respawn(DirectX::XMFLOAT3 p_position)
{
}

std::vector<Box> Player::GetBoundingBoxes()
{
	return m_boundingBoxes;
}