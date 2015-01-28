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
	MENUACTION_OPTIONAPPLY
};

class MenuItem
{
public:
	MenuItem();
	~MenuItem();

	bool Initialize(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture);
	bool Initialize(float p_x, float p_y, float p_size, ID3D11ShaderResourceView* p_texture);
	void Render();
	
	void SetBackgroundTexture(ID3D11ShaderResourceView* p_texture);
	virtual void Shutdown();

protected:

	float m_x;
	float m_y;
	float m_width;
	float m_height;

	GUIElement *m_background;
};

#endif // !MENUITEM_H_