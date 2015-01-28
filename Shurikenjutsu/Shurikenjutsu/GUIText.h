#ifndef GUITEXT_H_
#define GUITEXT_H_

#include <string>

#include <D3D11.h>

class GUIText
{
public:
	GUIText();
	~GUIText();

	bool Initialize(std::string p_text, float p_size, float p_x, float p_y, UINT32 p_color);
	void Render();
	void Render2();

	void SetText(std::string p_text);
	void SetPosition(float p_x, float p_y);
	void SetSize(float p_size);
	void SetColor(UINT32 p_color);

	std::string GetText();
	float GetPositionX();
	float GetPositionY();
	float GetSize();
	UINT32 GetColor();

private:
	std::string m_text;
	float m_posx;
	float m_posy;
	float m_size;
	UINT32 m_color;
};

#endif