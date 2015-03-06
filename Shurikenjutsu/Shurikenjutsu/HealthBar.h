#ifndef HEALTHBAR_H_
#define HEALTHBAR_H_

#define WIN32_LEAN_AND_MEAN

#include <DirectXMath.h>
#include <string>

//class GUIElementColor;
typedef unsigned int UINT32;
class GUIElement;
class GUIText;
class HealthBar
{
public:
	HealthBar();
	~HealthBar();

	bool Initialize(float p_width, float p_height, std::string p_name, UINT32 p_color);
	void Shutdown();
	void Update(DirectX::XMFLOAT3 p_position, int p_health, int p_maxHealth, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);
	void Render();
private:

	void CalculatePosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);

	GUIElement* m_border;
	GUIElement* m_background;
	GUIElement* m_foreground;
	GUIText* m_nameText;

};

#endif // !HEALTHBAR_H_