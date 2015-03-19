#ifndef TOOLTIPPOPUP_H_
#define TOOLTIPPOPUP_H_

#include <string>

class GUIText;
class MenuItem;

class ToolTipPopUp
{
public:
	ToolTipPopUp();
	~ToolTipPopUp();
	void Initialize(float p_xPos, float p_yPos, std::string p_text, float p_size, float p_backGroundWidth, float p_backGroundHeight, float p_bgOffset);
	void Render();
	void Update(float p_xPos, float p_yPos, float p_size);
	void Shutdown();

private:
	GUIText* m_text;
	bool m_visible;
	float m_xMin, m_xMax;
	float m_yMin, m_yMax;
	float m_halfScreenX;
	float m_halfScreenY;
	MenuItem *m_toolTipBG;

};

#endif