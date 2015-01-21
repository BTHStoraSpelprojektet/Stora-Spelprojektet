#include "AbilityBar.h"


AbilityBar::AbilityBar(){}
AbilityBar::~AbilityBar(){}

bool AbilityBar::Initialize(float p_positionX, float p_positionY, int p_numberOfAbilities)
{
	DirectX::XMFLOAT3 position;
	float halfLength = 26.0f*(p_numberOfAbilities-1);

	// ABILITY 1
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 52.0f * float(0), p_positionY, 0.0f);
	GUIAbility temp;
	temp.Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_Melee.png"));
	m_abilities.push_back(temp);

	// ABILITY 2
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 52.0f * float(1), p_positionY, 0.0f);
	temp.Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_Ranged.png"));
	m_abilities.push_back(temp);

	// ABILITY 3
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 52.0f * float(2), p_positionY, 0.0f);
	temp.Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_Q.png"));
	m_abilities.push_back(temp);

	// ABILITY 4
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 52.0f * float(3), p_positionY, 0.0f);
	temp.Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_N1_E.png"));
	m_abilities.push_back(temp);

	// ABILITY 5
	position = DirectX::XMFLOAT3(p_positionX - halfLength + 52.0f * float(4), p_positionY, 0.0f);
	temp.Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_SmokeBomb.png"));
	m_abilities.push_back(temp);

	position = DirectX::XMFLOAT3(p_positionX, p_positionY, 0.0f);
	m_background.Initialize(position, 52.0f*p_numberOfAbilities + 4.0f, 56.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/tb_bg.png"));

	return true;
}

void AbilityBar::Shutdown()
{
}

// TODO: Send ability information to update
void AbilityBar::Update()
{
	for (unsigned int i = 0; i < m_abilities.size(); i++)
	{
		m_abilities[i].Update(0.0f,10.0f);
	}
}

void AbilityBar::Render()
{
	m_background.QueueRender();
	for (unsigned int i = 0; i < m_abilities.size(); i++)
	{
		m_abilities[i].Render();
	}
}

