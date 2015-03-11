#ifndef GUIABILITY_H_
#define GUIABILITY_H_

#include "GUIElement.h"
#include "GUIText.h"
class GUIAbility
{
public:
	GUIAbility();
	~GUIAbility();

	bool Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, std::string p_hotKey);
	void Update(float p_currentCooldown, float p_maxCooldown, int p_stacks);
	void Render();

private:
	
	GUIElement m_ability;
	GUIElement m_cooldown;
	GUIText m_stacks;
	GUIText m_cooldownText;
	GUIText m_hotKeyText;
	int m_lastnrofStacks;
};
#endif // !GUIABILITY_H_
