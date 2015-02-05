#ifndef CURSOR_H_
#define CURSOS_H_

class GUIElement;
class Cursor
{
public:
	Cursor();
	~Cursor();

	bool Initialize();
	void Shutdown();

	void Update();
	void Render();

	void SetCustomCursor(bool p_useCustom);
	void SetRenderCursor(bool p_render);

	void LargeSize();
	void SmallSize();
private:
	bool m_useCustomCursor;
	bool m_renderCursor;
	GUIElement *m_cursor;
	
	float m_largeSize;
	float m_smallSize;
};

#endif