#include "KatanaNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "MeleeSwing.h"
#include "Dash.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
#include "SmokeBombAbility.h"
#include "InputManager.h"
#include "AttackPredictionEditor.h"
//#include "StickyTrapAbility.h"

KatanaNinja::KatanaNinja(){}
KatanaNinja::~KatanaNinja(){}

void* KatanaNinja::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void KatanaNinja::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool KatanaNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr)
{
	bool result;

	result = Player::Initialize(KATANA_NINJA_MODEL_NAME, p_pos, p_direction, p_charNr);
	if (!result)
	{
		return false;
	}

	SetSpeed(CHARACTER_KATANA_SHURIKEN_SPEED);

	m_meleeAttack = new MeleeSwing();
	m_meleeAttack->Initialize();

	m_meleeSpecialAttack = new Dash();
	m_meleeSpecialAttack->Initialize();

	m_rangeAttack = new ShurikenAbility();
	m_rangeAttack->Initialize();

	m_rangeSpecialAttack = new MegaShuriken();
	m_rangeSpecialAttack->Initialize();

	m_toolAbility = new SmokeBombAbility();
	m_toolAbility->Initialize();

	SetOriginalSpeed(GetSpeed());

	return true;
}

void KatanaNinja::Shutdown()
{
	Player::Shutdown();
}

void KatanaNinja::RenderAttackLocations()
{
	GraphicsEngine::TurnOnAlphaBlending();
	if (InputManager::GetInstance()->IsLeftMousePressed())
	{
		if ((float)m_meleeAttack->GetCooldown() <= 0.0f)
		{
			m_ape->NormalMeleeAttackCone(m_aimFrustrum, m_attackDir, m_position);
			m_aimFrustrum->Render();
		}
	}
	if (InputManager::GetInstance()->IsRightMousePressed())
	{
		if (m_rangeAttack->GetStacks() > 0 || m_rangeAttack->GetStacks() == -1)
		{
			DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
			DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - m_position.x, 0.03f, mousePos3D.z - m_position.z);
			float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
			DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
			float yaw = atan2(m_attackDir.x, m_attackDir.z);

			m_aimArrow->SetPosition(DirectX::XMFLOAT3(mousePos3D));
			m_aimPole->SetPosition(DirectX::XMFLOAT3(m_position.x + vectorToMouseNorm.x * (poleLength * 0.5f), 0.03f, m_position.z + vectorToMouseNorm.z * (poleLength * 0.5f)));

			m_aimArrow->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));
			m_aimPole->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));

			m_aimArrow->SetScale(DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
			m_aimPole->SetScale(DirectX::XMFLOAT3(poleLength * 10.0f, 1.0f, 1.0f));

			m_aimPole->Render();
			m_aimArrow->Render();
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('q')))
	{
		if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
		{
			DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
			DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - m_position.x, 0.03f, mousePos3D.z - m_position.z);
			float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
			DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
			float yaw = atan2(m_attackDir.x, m_attackDir.z);

			m_aimPole->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));

			m_aimPole->SetScale(DirectX::XMFLOAT3(9.0f * 10.0f, 1.0f, 5.0f));
	
			m_aimPole->SetPosition(DirectX::XMFLOAT3(m_position.x + vectorToMouseNorm.x * 4.5f, 0.03f, m_position.z + vectorToMouseNorm.z * 4.5f));

			m_aimPole->Render();
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('e')))
	{
		if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
		{
			DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
			DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - m_position.x, 0.03f, mousePos3D.z - m_position.z);
			float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
			DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
			float yaw = atan2(m_attackDir.x, m_attackDir.z);

			m_aimArrow->SetPosition(DirectX::XMFLOAT3(mousePos3D));
			m_aimPole->SetPosition(DirectX::XMFLOAT3(m_position.x + vectorToMouseNorm.x * (poleLength * 0.5f), 0.03f, m_position.z + vectorToMouseNorm.z * (poleLength * 0.5f)));

			m_aimArrow->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));
			m_aimPole->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));

			m_aimArrow->SetScale(DirectX::XMFLOAT3(5.0f, 1.0f, 5.0f));
			m_aimPole->SetScale(DirectX::XMFLOAT3(poleLength * 10.0f, 1.0f, 5.0f));

			m_aimPole->Render();
			m_aimArrow->Render();
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('r')))
	{
		if ((float)m_toolAbility->GetCooldown() <= 0.0f)
		{
			DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());

			m_aimSphere->SetPosition(mousePos3D);
			m_aimSphere->SetScale(DirectX::XMFLOAT3(7.0f, m_aimSphere->GetScale().y, 7.0f));
			m_aimSphere->Render();
		}
	}
	GraphicsEngine::TurnOffAlphaBlending();
}