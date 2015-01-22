#ifndef HEALTHBAR_H_
#define HEALTHBAR_H_

#include <DirectXMath.h>

class GUIElementColor;
class HealthBar
{
public:
	HealthBar();
	~HealthBar();

	bool Initialize(float p_width, float p_height);
	void Shutdown();
	void Update(DirectX::XMFLOAT3 p_position, int p_health, int p_maxHealth, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);
	void Render();
private:

	void CalculatePosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);

	GUIElementColor* m_border;
	GUIElementColor* m_background;
	GUIElementColor* m_foreground;

};

#endif // !HEALTHBAR_H_