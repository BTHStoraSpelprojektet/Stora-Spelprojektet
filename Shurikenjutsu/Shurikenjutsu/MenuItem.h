#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "DirectX.h"

class GUIElement;
enum MENUACTION
{
	MENUACTION_BACK,
	MENUACTION_PLAY,
	MENUACTION_CHOOSENINJA,
	MENUACTION_NEXTNINJA,
	MENUACTION_PREVNINJA,
	MENUACTION_OPTIONS,
	MENUACTION_VSYNC,
	MENUACTION_FULLSCREEN,
	MENUACTION_IP,
	MENUACTION_CONNECT,
	MENUACTION_EMPTY,
};

class MenuItem
{
public:
	MenuItem();
	~MenuItem();

	bool Initialize(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, ID3D11ShaderResourceView* p_texture);
	bool Initialize(float p_x, float p_y, float p_size, MENUACTION p_action, ID3D11ShaderResourceView* p_texture);
	void Render();
	virtual bool IsClicked();
	MENUACTION GetAction();
	void SetBackgroundTexture(ID3D11ShaderResourceView* p_texture);

protected:

	float m_x;
	float m_y;
	float m_width;
	float m_height;

	GUIElement *m_background;

	MENUACTION m_action;
};

#endif // !MENUITEM_H_