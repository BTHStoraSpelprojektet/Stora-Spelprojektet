#include "CharacterAbilityDescription.h"
#include "MenuItem.h"
#include "GUIText.h"
#include "Globals.h"
#include "TextResource.h"
#include "Structures.h"
#include "TextureLibrary.h"

CharacterAbilityDescription::CharacterAbilityDescription(){}
CharacterAbilityDescription::~CharacterAbilityDescription(){}

void CharacterAbilityDescription::Initialize(int p_ninjaIndex)
{
	float quarterHeight = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 4.0f;
	float quarterWidth = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 3.0f;

	m_FirstText = new GUIText();
	m_FirstPic = new MenuItem();
	m_SecondText = new GUIText();
	m_SecondPic = new MenuItem();
	m_ThirdText = new GUIText();
	m_ThirdPic = new MenuItem();
	m_FourthText = new GUIText();
	m_FourthPic = new MenuItem();

	float size = 75.0f;
	float textSize = 25.0f;
	DirectX::XMFLOAT2 upLeftCorner = DirectX::XMFLOAT2(-size * 3, -quarterHeight);
	DirectX::XMFLOAT2 downLeftCorner = DirectX::XMFLOAT2(-size, -quarterHeight);
	DirectX::XMFLOAT2 upRightCorner = DirectX::XMFLOAT2(size, -quarterHeight);
	DirectX::XMFLOAT2 downRightCorner = DirectX::XMFLOAT2(size * 3, -quarterHeight);
	if (p_ninjaIndex == 1)
	{
		m_FirstText->Initialize(KATANA_PRIMARY_ATTACK, textSize, upLeftCorner.x/* - size*2*/, upLeftCorner.y - size, 0xffffffff);
		m_FirstPic->Initialize(upLeftCorner.x, upLeftCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_Melee.png"));

		m_SecondText->Initialize(KATANA_SECONDARY_ATTACK, textSize, downLeftCorner.x/* - size * 2*/, downLeftCorner.y - size, 0xffffffff);
		m_SecondPic->Initialize(downLeftCorner.x, downLeftCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_Q.png"));

		m_ThirdText->Initialize(SHURIKEN_PRIMARY_ATTACK, textSize, upRightCorner.x /* - size * 2*/, upRightCorner.y - size, 0xffffffff);
		m_ThirdPic->Initialize(upRightCorner.x, upRightCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_Ranged.png"));

		m_FourthText->Initialize(SHURIKEN_SECONDARY_ATTACK, textSize, downRightCorner.x /* - size * 2*/, downRightCorner.y - size, 0xffffffff);
		m_FourthPic->Initialize(downRightCorner.x, downRightCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_E.png"));

	}
	else if (p_ninjaIndex == 2)
	{
		m_FirstText->Initialize(TESSEN_PRIMARY_ATTACK, textSize, upLeftCorner.x /* - size * 2*/, upLeftCorner.y - size, 0xffffffff);
		m_FirstPic->Initialize(upLeftCorner.x, upLeftCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N2_Melee.png"));

		m_SecondText->Initialize(TESSEN_SECONDARY_ATTACK, textSize, downLeftCorner.x /* - size * 2*/, downLeftCorner.y - size, 0xffffffff);
		m_SecondPic->Initialize(downLeftCorner.x, downLeftCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N2_Q.png"));

		m_ThirdText->Initialize(WHIP_PRIMARY_ATTACK, textSize, upRightCorner.x/* - size * 2*/, upRightCorner.y - size, 0xffffffff);
		m_ThirdPic->Initialize(upRightCorner.x, upRightCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N2_Ranged.png"));

		m_FourthText->Initialize(WHIP_SECONDARY_ATTACK, textSize, downRightCorner.x /* - size * 2*/, downRightCorner.y - size, 0xffffffff);
		m_FourthPic->Initialize(downRightCorner.x, downRightCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N2_E.png"));
	}
	else
	{
		m_FirstText->Initialize(NAGINATA_PRIMARY_ATTACK, textSize, upLeftCorner.x/* - size * 2*/, upLeftCorner.y - size, 0xffffffff);
		m_FirstPic->Initialize(upLeftCorner.x, upLeftCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N3_Melee.png"));

		m_SecondText->Initialize(NAGINATA_SECONDARY_ATTACK, textSize, downLeftCorner.x /* - size * 2*/, downLeftCorner.y - size, 0xffffffff);
		m_SecondPic->Initialize(downLeftCorner.x, downLeftCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N3_Q.png"));

		m_ThirdText->Initialize(KUNAI_PRIMARY_ATTACK, textSize, upRightCorner.x /* - size * 2*/, upRightCorner.y - size, 0xffffffff);
		m_ThirdPic->Initialize(upRightCorner.x, upRightCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N3_Ranged.png"));

		m_FourthText->Initialize(KUNAI_SECONDARY_ATTACK, textSize, downRightCorner.x/* - size * 2*/, downRightCorner.y - size, 0xffffffff);
		m_FourthPic->Initialize(downRightCorner.x, downRightCorner.y, size, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N3_E.png"));
	}
}
void CharacterAbilityDescription::Shutdown()
{
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
	//m_FirstText->Render();
	//m_SecondText->Render();
	//m_ThirdText->Render();
	//m_FourthText->Render();
	m_FirstPic->Render();
	m_SecondPic->Render();
	m_ThirdPic->Render();
	m_FourthPic->Render();
}
