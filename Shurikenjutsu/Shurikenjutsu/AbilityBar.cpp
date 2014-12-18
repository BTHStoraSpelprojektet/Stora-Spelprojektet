#include "AbilityBar.h"


AbilityBar::AbilityBar(){}
AbilityBar::~AbilityBar(){}

bool AbilityBar::Initialize(float p_positionX, float p_positionY, int p_numberOfAbilities)
{
	DirectX::XMFLOAT3 position;
	float halfLength = 26.0f*(p_numberOfAbilities-1);

	for (unsigned int i = 0; i < p_numberOfAbilities; i++)
	{
		position = DirectX::XMFLOAT3(p_positionX-halfLength + 52.0f * float(i), p_positionY, 0.0f);
		GUIAbility temp;
		temp.Initialize(position, 50.0f, 50.0f);
		m_abilities.push_back(temp);
	}
	position = DirectX::XMFLOAT3(p_positionX, p_positionY, 0.0f);
	m_background.Initialize(position, 52.0f*p_numberOfAbilities + 4.0f, 56.0f, DirectX::XMFLOAT4(0.0f,0.0f,0.0f,1.0f));

	return true;
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
