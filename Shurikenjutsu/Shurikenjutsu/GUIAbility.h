#ifndef GUIABILITY_H_
#define GUIABILITY_H_

#include "GUIElement.h"

class GUIAbility
{
public:
	GUIAbility();
	~GUIAbility();

	bool Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height);
	void Update(float p_currentCooldown, float p_maxCooldown);
	void Render();

private:
	
	GUIElement m_border;
	GUIElement m_ability;
	GUIElement m_cooldown;
};
#endif // !GUIABILITY_H_
