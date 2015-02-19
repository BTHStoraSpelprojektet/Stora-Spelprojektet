#ifndef FLOATINGTEXT_H_
#define FLOATINGTEXT_H_

#include "GUIText.h"
#include "Structures.h"

class FloatingText
{
public:
	void Initialize();
	void Update(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);
	void Shutdown();
	void Render();
	void SetReceivedDamageText(std::string p_damage);
private:
	void RenderText(GUIText* p_text);
	void CalculatePosition(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection, GUIText* p_text,float p_xOffset, float p_yOffset);
	void DecreaseTextOpacity(GUIText* p_text);

	GUIText* m_receivedDamageText;
};

#endif