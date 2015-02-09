#include "NaginataNinja.h"
#include "../CommonLibs/ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "NaginataSlash.h"
#include "NaginataStab.h"
#include "Dash.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
//#include "SmokeBombAbility.h"
#include "KunaiAbility.h"
#include "StickyTrapAbility.h"


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

bool NaginataNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction)
{
	bool result;

	result = Player::Initialize(NAGINATA_NINJA_MODEL_NAME, p_pos, p_direction);
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

	m_rangeSpecialAttack = new MegaShuriken();
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