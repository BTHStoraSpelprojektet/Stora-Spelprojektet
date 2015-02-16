#include "NaginataNinja.h"
#include "../CommonLibs/ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "NaginataSlash.h"
#include "NaginataStab.h"
#include "InputManager.h"
#include "KunaiAbility.h"
#include "StickyTrapAbility.h"
#include "VolleyAbility.h"


NaginataNinja::NaginataNinja(){}
NaginataNinja::~NaginataNinja(){}

void* NaginataNinja::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void NaginataNinja::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool NaginataNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr)
{
	bool result;

	result = Player::Initialize(NAGINATA_NINJA_MODEL_NAME, p_pos, p_direction, p_charNr);
	if (!result)
	{
		return false;
	}

	SetSpeed(CHARACTER_NAGINATA_SPEED);

	m_meleeAttack = new NaginataSlash();
	m_meleeAttack->Initialize();

	m_meleeSpecialAttack = new NaginataStab();
	m_meleeSpecialAttack->Initialize();

	m_rangeAttack = new KunaiAbility();
	m_rangeAttack->Initialize();

	m_rangeSpecialAttack = new VolleyAbility();
	m_rangeSpecialAttack->Initialize();

	m_toolAbility = new StickyTrapAbility();
	m_toolAbility->Initialize();

	SetOriginalSpeed(GetSpeed());

	return true;
}

void NaginataNinja::Shutdown()
{
	Player::Shutdown();
}
void NaginataNinja::RenderAttackLocations()
{
	m_aimSphere->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
	m_aimArrow->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
	m_aimPole->SetPosition(DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.13f, InputManager::GetInstance()->Get3DMousePositionZ()));
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('e')))
	{
		if ((float)m_rangeSpecialAttack->GetCooldown() <= 0.0f)
		{

		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('q')))
	{
		if ((float)m_meleeSpecialAttack->GetCooldown() <= 0.0f)
		{
			m_aimSphere->SetScale(DirectX::XMFLOAT3(0.5f, m_aimSphere->GetScale().y, 0.5f));
			m_aimSphere->Render();
		}
	}
	if (InputManager::GetInstance()->IsKeyPressed(VkKeyScan('r')))
	{
		if ((float)m_toolAbility->GetCooldown() <= 0.0f)
		{
			m_aimSphere->SetScale(DirectX::XMFLOAT3(1.0f, m_aimSphere->GetScale().y, 1.0f));
			m_aimSphere->Render();
		}
	}
	if (InputManager::GetInstance()->IsRightMousePressed())
	{
		if (m_rangeAttack->GetStacks() > 0 || m_rangeAttack->GetStacks() == -1)
		{

		}
	}
	if (InputManager::GetInstance()->IsLeftMousePressed())
	{
		if ((float)m_meleeAttack->GetCooldown() <= 0.0f)
		{

		}
	}
}