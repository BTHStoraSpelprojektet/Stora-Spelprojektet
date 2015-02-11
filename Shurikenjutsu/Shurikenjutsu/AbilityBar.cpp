#include "AbilityBar.h"
#include "TextureLibrary.h"
#include "GUIAbility.h"
#include "GUIElement.h"
#include "..\CommonLibs\ModelNames.h"
#include "Network.h"

AbilityBar::AbilityBar(){}
AbilityBar::~AbilityBar(){}

bool AbilityBar::Initialize(float p_positionX, float p_positionY, int p_numberOfAbilities)
{
	DirectX::XMFLOAT3 position;
	float halfLength = 26.0f*(p_numberOfAbilities-1);

	// ABILITY 1
	position = DirectX::XMFLOAT3(p_positionX - halfLength, p_positionY, 0.0f);
	GUIAbility *temp;
	temp = new GUIAbility();
	temp->Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetAbility1Name()));
	m_abilities.push_back(temp);

	// ABILITY 2
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 52.0f, p_positionY, 0.0f);
	temp = new GUIAbility();
	temp->Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetAbility2Name()));
	m_abilities.push_back(temp);

	// ABILITY 3
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 104.0f, p_positionY, 0.0f);
	temp = new GUIAbility();
	temp->Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetAbility3Name()));
	m_abilities.push_back(temp);

	// ABILITY 4
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 156.0f, p_positionY, 0.0f);
	temp = new GUIAbility();
	temp->Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetAbility4Name()));
	m_abilities.push_back(temp);

	// ABILITY 5
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 208.0f, p_positionY, 0.0f);
	temp = new GUIAbility();
	temp->Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(GetAbility5Name()));
	m_abilities.push_back(temp);

	position = DirectX::XMFLOAT3(p_positionX, p_positionY, 0.0f);
	m_background = new GUIElement();
	m_background->Initialize(position, 52.0f*p_numberOfAbilities + 4.0f, 56.0f, TextureLibrary::GetInstance()->GetTexture(ABILITY_BG_TEXTURE));

	return true;
}

void AbilityBar::Shutdown()
{
	for (unsigned int i = 0; i < m_abilities.size(); i++)
	{
		delete m_abilities[i];
		m_abilities[i] = 0;
	}
	m_abilities.clear();
}

// TODO: Send ability information to update
void AbilityBar::Update(float p_cooldown, float p_fullCooldown, int p_stacks, int p_index)
{
	m_abilities[p_index]->Update(p_cooldown, p_fullCooldown, p_stacks);
}

void AbilityBar::Render()
{
	m_background->QueueRender();
	for (unsigned int i = 0; i < m_abilities.size(); i++)
	{
		m_abilities[i]->Render();
	}
}

std::string AbilityBar::GetAbility1Name()
{
	switch (Network::GetInstance()->GetMyPlayer().charNr)
	{
	case 0:
	{
		return ABILITY_KATANA_TEXTURE;
		break;
	}
	case 1:
	{
		return ABILITY_TESSEN_TEXTURE;
		break;
	}
	case 2:
		return ABILITY_NAGINATA_TEXTURE;
		break;
	}

	return ABILITY_CD_TEXTURE;
}

std::string AbilityBar::GetAbility2Name()
{
	switch (Network::GetInstance()->GetMyPlayer().charNr)
	{
	case 0:
	{
		return ABILITY_SHURIKEN_TEXTURE;
		break;
	}
	case 1:
	{
		return ABILITY_WHIP_TEXTURE;
		break;
	}
	case 2:
		return ABILITY_KUNAI_TEXTURE;
		break;
	}

	return ABILITY_CD_TEXTURE;
}

std::string AbilityBar::GetAbility3Name()
{
	switch (Network::GetInstance()->GetMyPlayer().charNr)
	{
	case 0:
	{
		return ABILITY_DASH_TEXTURE;
		break;
	}
	case 1:
	{
		return ABILITY_TESSEN_THROWING_TEXTURE;
		break;
	}
	case 2:
	{
		return ABILITY_NAGINATA_STAB_TEXTURE;
		break;
	}
	}

	return ABILITY_CD_TEXTURE;
}

std::string AbilityBar::GetAbility4Name()
{
	switch (Network::GetInstance()->GetMyPlayer().charNr)
	{
	case 0:
	{
		return ABILITY_MEGA_SHURIKEN_TEXTURE;
		break;
	}
	case 1:
	{
		return ABILITY_WHIP_SPECIAL_TEXTURE;
		break;
	}
	case 2:
	{
		return ABILITY_KUNAI_VOLLEY_TEXTURE;
		break;
	}
	}

	return ABILITY_CD_TEXTURE;
}

std::string AbilityBar::GetAbility5Name()
{
	switch (Network::GetInstance()->GetMyPlayer().charNr)
	{
	case 0:
	{
		return ABILITY_SMOKE_BOMB_TEXTURE;
		break;
	}
	case 1:
	{
		return ABILITY_CALTROP_TEXTURE;
		break;
	}
	case 2:
		//return ABILIY_STICKYTRAP_TEXTURE;
		break;
	}

	return ABILITY_CD_TEXTURE;
}