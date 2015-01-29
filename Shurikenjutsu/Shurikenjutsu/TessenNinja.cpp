#include "TessenNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "MeleeSwing.h"
#include "Dash.h"
#include "ShurikenAbility.h"
#include "MegaShuriken.h"
#include "SmokeBombAbility.h"

TessenNinja::TessenNinja()
{
}


TessenNinja::~TessenNinja()
{
}

bool TessenNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction)
{
	bool result;

	result = Player::Initialize(TESSEN_NINJA_MODEL_NAME, p_pos, p_direction);
	if (!result)
	{
		return false;
	}

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

	return true;
}

void TessenNinja::Shutdown()
{
}