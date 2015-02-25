#ifndef HEALTHBAR_H_
#define HEALTHBAR_H_

#include "GraphicsEngine.h"
#include "TextureLibrary.h"
#include "GUIElement.h"

class ScoreBoard
{
public:
	ScoreBoard();
	~ScoreBoard();

	bool Initialize();
	void Shutdown();
	void Update();
	void Render();

private:
	ID3D11ShaderResourceView* m_texture;
	GUIElement* m_background;
	float m_boardHeight;
	float m_boardWidth;
};

#endif