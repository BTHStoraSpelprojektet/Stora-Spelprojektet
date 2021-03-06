#ifndef MENUITEM_H_
#define MENUITEM_H_

class GUIElement;
struct ID3D11ShaderResourceView;

enum MENUACTION
{
	MENUACTION_BACK,
	MENUACTION_PLAY,
	MENUACTION_CHOOSENINJA,
	MENUACTION_NEXTNINJA,
	MENUACTION_PREVNINJA,
	MENUACTION_NEXTTOOL,
	MENUACTION_PREVTOOL,
	MENUACTION_OPTIONS,
	MENUACTION_CREDITS,
	MENUACTION_CHECKBOX,
	MENUACTION_IP,
	MENUACTION_CONNECT,
	MENUACTION_EMPTY,
	MENUACTION_OPTIONAPPLY,
	MENUACTION_INGAME_RESUME,
	MENUACTION_INGAME_CONTINUE,
	MENUACTION_INGAME_TO_MAIN,
	MENUACTION_INGAME_QUIT,
	MENUACTION_PICK_RED_TEAM,
	MENUACTION_PICK_BLUE_TEAM,
	MENUACTION_RANDOM_NINJA,
	MENUACTION_CLICKED_QUESTIONMARK,
	MENUACTION_HOST_SERVER

};

class MenuItem
{
public:
	MenuItem();
	~MenuItem();

	bool Initialize(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture);
	bool Initialize(float p_x, float p_y, float p_size, ID3D11ShaderResourceView* p_texture);
	virtual void Render();
	
	void SetBackgroundTexture(ID3D11ShaderResourceView* p_texture);
	virtual void Shutdown();
	void SetPosition(float p_x,	float p_y);

protected:

	float m_x;
	float m_y;
	float m_width;
	float m_height;

	GUIElement *m_background;
};

#endif // !MENUITEM_H_