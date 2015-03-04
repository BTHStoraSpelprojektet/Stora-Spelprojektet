#ifndef GUITEXT_H_
#define GUITEXT_H_

#include <string>
#include <vector>

#include <D3D11.h>
struct IDWriteTextLayout;
struct IDWriteTextFormat;

class GUIText
{
public:
	GUIText();
	~GUIText();

	bool Initialize(std::string p_text, float p_size, float p_x, float p_y, UINT32 p_color);
	bool InitializeCalibri(std::string p_text, float p_size, float p_x, float p_y, UINT32 p_color);
	void Render();
	void Shutdown();

	void SetText(std::string p_text);
	void SetPosition(float p_x, float p_y);
	void SetSize(float p_size);
	void SetColor(UINT32 p_color);

	float GetPositionX();
	float GetPositionY();

	float GetWidth();
	float GetHeight();

	UINT32 GetColor();
	IDWriteTextLayout* GetLayout();

private:
	float m_posx;
	float m_posy;
	float m_width;
	float m_height;
	int m_textLength;
	UINT32 m_color;
	IDWriteTextFormat* m_format;
	std::vector<IDWriteTextLayout*> m_layouts;
};

#endif