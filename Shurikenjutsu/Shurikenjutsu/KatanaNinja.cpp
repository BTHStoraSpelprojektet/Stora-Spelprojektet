#include "KatanaNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "MeleeSwing.h"
#include "Dash.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
#include "SmokeBombAbility.h"
#include "InputManager.h"
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
	if (InputManager::GetInstance()->IsRightMousePressed())
	{
		if (m_rangeAttack->GetStacks() > 0 || m_rangeAttack->GetStacks() == -1)
		{
			m_aimFrustrum->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
		}
	}
	if (InputManager::GetInstance()->IsLeftMousePressed())
	{
		if ((float)m_meleeAttack->GetCooldown() <= 0.0f)
		{
			m_aimArrow->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
			m_aimPole->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('e')))
	{
		if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
		{
			m_aimArrow->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
			m_aimPole->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('q')))
	{
		if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
		{
			m_aimArrow->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
			m_aimPole->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('r')))
	{
		if ((float)m_toolAbility->GetCooldown() <= 0.0f)
		{
			m_aimSphere->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
			m_aimSphere->SetScale(DirectX::XMFLOAT3(1.0f, m_aimSphere->GetScale().y, 1.0f));
			m_aimSphere->Render();
		}
	}
}