#ifndef ABILITYBAR_H_
#define ABILITYBAR_H_

#include <vector>

class GUIAbility;
class GUIElement;

class AbilityBar
{
public:
	AbilityBar();
	~AbilityBar();

	bool Initialize(float p_positionX, float p_positionY, int p_numberOfAbilities);
	void Shutdown();
	void Update(float p_cooldown, float p_fullCooldown, int p_index);
	void Render();

private:
	std::vector<GUIAbility*> m_abilities;
	GUIElement* m_background;

};
#endif // !ABILITYBAR_H_
