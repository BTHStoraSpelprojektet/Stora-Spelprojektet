#include "CharacterAbilityDescription.h"
#include "MenuItem.h"
#include "Globals.h"
#include "TextResource.h"
#include "Structures.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "ToolTipPopUp.h"

CharacterAbilityDescription::CharacterAbilityDescription(){}
CharacterAbilityDescription::~CharacterAbilityDescription(){}

void CharacterAbilityDescription::Initialize(int p_ninjaIndex)
{
	float quarterHeight = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 3.3f;
	float quarterWidth = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 3.3f;

	m_FirstText = new ToolTipPopUp();
	m_FirstPic = new MenuItem();
	m_SecondText = new ToolTipPopUp();
	m_SecondPic = new MenuItem();
	m_ThirdText = new ToolTipPopUp();
	m_ThirdPic = new MenuItem();
	m_FourthText = new ToolTipPopUp();
	m_FourthPic = new MenuItem();
	float size = 75.0f;
	m_abilityBarBG = new MenuItem();
	m_abilityBarBG->Initialize(0.0f, -40.0f/*-quarterHeight*/, 370.0f, 100.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/abilitybarLobby.png"));

	DirectX::XMFLOAT2 ability1 = DirectX::XMFLOAT2(-126.0f, -40.0f);
	DirectX::XMFLOAT2 ability2 = DirectX::XMFLOAT2(-42.0f, -40.0f);
	DirectX::XMFLOAT2 ability3 = DirectX::XMFLOAT2(42.0f, -40.0f);
	DirectX::XMFLOAT2 ability4 = DirectX::XMFLOAT2(126.0f, -40.0f);

	float bgWidth = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 3.0f;
	float bgHeight = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 6.83f;
	if (p_ninjaIndex == 1)
	{
		m_FirstText->Initialize(ability1.x, ability1.y, KATANA_PRIMARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_FirstPic->Initialize(ability1.x, ability1.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N1_Melee.png"));

		m_SecondText->Initialize(ability2.x, ability2.y, SHURIKEN_PRIMARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_SecondPic->Initialize(ability2.x, ability2.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N1_Ranged.png"));

		m_ThirdText->Initialize(ability3.x, ability3.y, KATANA_SECONDARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_ThirdPic->Initialize(ability3.x, ability3.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N1_Q.png"));

		m_FourthText->Initialize(ability4.x, ability4.y, SHURIKEN_SECONDARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_FourthPic->Initialize(ability4.x, ability4.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N1_E.png"));

	}
	else if (p_ninjaIndex == 2)
	{
		m_FirstText->Initialize(ability1.x, ability1.y, TESSEN_PRIMARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_FirstPic->Initialize(ability1.x, ability1.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N2_Melee.png"));

		m_SecondText->Initialize(ability2.x, ability2.y, WHIP_PRIMARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_SecondPic->Initialize(ability2.x, ability2.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N2_Ranged.png"));

		m_ThirdText->Initialize(ability3.x, ability3.y, TESSEN_SECONDARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_ThirdPic->Initialize(ability3.x, ability3.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N2_Q.png"));

		m_FourthText->Initialize(ability4.x, ability4.y, WHIP_SECONDARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_FourthPic->Initialize(ability4.x, ability4.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N2_E.png"));
	}
	else
	{
		m_FirstText->Initialize(ability1.x, ability1.y, NAGINATA_PRIMARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_FirstPic->Initialize(ability1.x, ability1.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N3_Melee.png"));

		m_SecondText->Initialize(ability2.x, ability2.y, KUNAI_PRIMARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_SecondPic->Initialize(ability2.x, ability2.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N3_Ranged.png"));

		m_ThirdText->Initialize(ability3.x, ability3.y, NAGINATA_SECONDARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_ThirdPic->Initialize(ability3.x, ability3.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N3_Q.png"));

		m_FourthText->Initialize(ability4.x, ability4.y, KUNAI_SECONDARY_ATTACK, 50.0f, bgWidth, bgHeight, 0.0f);
		m_FourthPic->Initialize(ability4.x, ability4.y, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_N3_E.png"));
	}
}

void CharacterAbilityDescription::Update()
{
	m_FirstText->Update();
	m_SecondText->Update();
	m_ThirdText->Update();
	m_FourthText->Update();
}
void CharacterAbilityDescription::Shutdown()
{
	if (m_abilityBarBG != nullptr)
	{
		m_abilityBarBG->Shutdown();
		delete m_abilityBarBG;
		m_abilityBarBG = nullptr;
	}
	if (m_FirstText != nullptr)
	{
		m_FirstText->Shutdown();
		delete m_FirstText;
		m_FirstText = nullptr;
	}
	if (m_SecondText != nullptr)
	{
		m_SecondText->Shutdown();
		delete m_SecondText;
		m_SecondText = nullptr;
	}
	if (m_ThirdText != nullptr)
	{
		m_ThirdText->Shutdown();
		delete m_ThirdText;
		m_ThirdText = nullptr;
	}
	if (m_FourthText != nullptr)
	{
		m_FourthText->Shutdown();
		delete m_FourthText;
		m_FourthText = nullptr;
	}
	if (m_FirstPic != nullptr)
	{
		m_FirstPic->Shutdown();
		delete m_FirstPic;
		m_FirstPic = nullptr;
	}
	if (m_SecondPic != nullptr)
	{
		m_SecondPic->Shutdown();
		delete m_SecondPic;
		m_SecondPic = nullptr;
	}
	if (m_ThirdPic != nullptr)
	{
		m_ThirdPic->Shutdown();
		delete m_ThirdPic;
		m_ThirdPic = nullptr;
	}
	if (m_FourthPic != nullptr)
	{
		m_FourthPic->Shutdown();
		delete m_FourthPic;
		m_FourthPic = nullptr;
	}
}
void CharacterAbilityDescription::Render()
{
	//m_abilityBarBG->Render();
	m_FirstPic->Render();
	m_SecondPic->Render();
	m_ThirdPic->Render();
	m_FourthPic->Render();
	m_FirstText->Render();
	m_SecondText->Render();
	m_ThirdText->Render();
	m_FourthText->Render();
}
