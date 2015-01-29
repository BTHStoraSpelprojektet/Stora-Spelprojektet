#include "FanBoomerang.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

FanBoomerang::FanBoomerang(){}
FanBoomerang::~FanBoomerang(){}

void FanBoomerang::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	m_rotation.x += (float)(SHURIKEN_ROTATION_SPEED*deltaTime*0.1f);
	m_rotation.y += (float)(SHURIKEN_ROTATION_SPEED*deltaTime*0.1f);
	//m_rotation.z += (float)(SHURIKEN_ROTATION_SPEED*deltaTime*0.1f);
}
