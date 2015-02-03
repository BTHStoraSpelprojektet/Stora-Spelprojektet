#include "TessenNinja.h"
#include "..\CommonLibs\ModelNames.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "MeleeSwing.h"
#include "Dash.h"
#include "WhipPrimaryAttackAbility.h"
#include "WhipSecondaryAttackAbility.h"
#include "SpikeAbility.h"
#include "FanBoomerangAbility.h"

TessenNinja::TessenNinja(){}
TessenNinja::~TessenNinja(){}

bool TessenNinja::Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction)
{
	bool result;

	result = Player::Initialize(TESSEN_NINJA_MODEL_NAME, p_pos, p_direction);
	if (!result)
	{
		return false;
	}

	SetSpeed(CHARACTER_TESSEN_SPEED);

	m_meleeAttack = new MeleeSwing();
	m_meleeAttack->Initialize();

	m_meleeSpecialAttack = new FanBoomerangAbility();
	m_meleeSpecialAttack->Initialize();

	m_rangeAttack = new WhipPrimaryAttackAbility();
	m_rangeAttack->Initialize();

	m_rangeSpecialAttack = new WhipSecondaryAttackAbility();
	m_rangeSpecialAttack->Initialize();

	m_toolAbility = new SpikeAbility();
	m_toolAbility->Initialize();

	return true;
}

void TessenNinja::Shutdown()
{
	Player::Shutdown();
}