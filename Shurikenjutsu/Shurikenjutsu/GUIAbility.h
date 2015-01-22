#ifndef GUIABILITY_H_
#define GUIABILITY_H_

#include "GUIElementColor.h"

class GUIAbility
{
public:
	GUIAbility();
	~GUIAbility();

	bool Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture);
	void Update(float p_currentCooldown, float p_maxCooldown);
	void Render();

private:
	
	GUIElementColor m_border;
	GUIElement m_ability;
	GUIElement m_cooldown;
};
#endif // !GUIABILITY_H_
