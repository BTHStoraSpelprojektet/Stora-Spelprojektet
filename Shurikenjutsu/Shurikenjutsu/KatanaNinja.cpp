#include "KatanaNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "MeleeSwing.h"
#include "Dash.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
//#include "SmokeBombAbility.h"
#include "StickyTrapAbility.h"

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

bool KatanaNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction)
{
	bool result;

	result = Player::Initialize(KATANA_NINJA_MODEL_NAME, p_pos, p_direction);
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

	m_toolAbility = new StickyTrapAbility();
	m_toolAbility->Initialize();

	SetOriginalSpeed(GetSpeed());

	return true;
}

void KatanaNinja::Shutdown()
{
	Player::Shutdown();
}