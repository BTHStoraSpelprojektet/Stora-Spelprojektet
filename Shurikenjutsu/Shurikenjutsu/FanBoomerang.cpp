#include "FanBoomerang.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

FanBoomerang::FanBoomerang(){}
FanBoomerang::~FanBoomerang(){}

bool FanBoomerang::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id)
{
	MovingObject::Initialize(p_filepath, p_pos, p_dir, p_speed);
	m_id = p_id;

	return true;
}

void FanBoomerang::Update(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, float p_speed)
{
	m_position = DirectX::XMFLOAT3(p_x, p_y, p_z);
	m_direction = DirectX::XMFLOAT3(p_dirX, p_dirY, p_dirZ);
	m_speed = 0;
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	//m_rotation.x += (float)(SHURIKEN_ROTATION_SPEED*deltaTime*0.1f);
	m_rotation.y += (float)(SHURIKEN_ROTATION_SPEED*deltaTime);
	//m_rotation.z += (float)(SHURIKEN_ROTATION_SPEED*deltaTime*0.1f);
}

unsigned int FanBoomerang::GetID()
{
	return m_id;
}
