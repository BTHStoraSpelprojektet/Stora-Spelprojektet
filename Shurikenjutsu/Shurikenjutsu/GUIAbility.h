#ifndef GUIABILITY_H_
#define GUIABILITY_H_

#include "GUIElementColor.h"
#include "GUIElement.h"
#include "GUIText.h"
class GUIAbility
{
public:
	GUIAbility();
	~GUIAbility();

	bool Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture);
	void Update(float p_currentCooldown, float p_maxCooldown, int p_stacks);
	void Render();

private:
	
	GUIElementColor m_border;
	GUIElement m_ability;
	GUIElement m_cooldown;
	GUIText m_stacks;
	GUIText m_cooldownText;
	int m_lastnrofStacks;
};
#endif // !GUIABILITY_H_
