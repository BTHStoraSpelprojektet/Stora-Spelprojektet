#ifndef ABILITYBAR_H_
#define ABILITYBAR_H_

#include "GUIAbility.h"
#include <vector>

class AbilityBar
{
public:
	AbilityBar();
	~AbilityBar();

	bool Initialize(float p_positionX, float p_positionY, int p_numberOfAbilities);
	void Update();
	void Render();

private:
	std::vector<GUIAbility> m_abilities;
	GUIElement m_background;

};
#endif // !ABILITYBAR_H_
