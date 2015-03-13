#ifndef GUIABILITY_H_
#define GUIABILITY_H_

#include <DirectXMath.h>
#include <string>

struct ID3D11ShaderResourceView;
class GUIElement;
class GUIText;

class GUIAbility
{
public:
	GUIAbility();
	~GUIAbility();

	bool Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, std::string p_hotKey);
	void Shutdown();
	void Update(float p_currentCooldown, float p_maxCooldown, int p_stacks);
	void Render();

private:
	
	GUIElement* m_ability;
	GUIElement* m_cooldown;
	GUIText* m_stacks;
	GUIText* m_cooldownText;
	GUIText* m_hotKeyText;
	int m_lastnrofStacks;
};
#endif // !GUIABILITY_H_
