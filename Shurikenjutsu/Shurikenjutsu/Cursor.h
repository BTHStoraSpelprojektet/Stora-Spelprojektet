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



private:
	bool m_useCustomCursor;
	GUIElement *m_cursor;

	
};

#endif