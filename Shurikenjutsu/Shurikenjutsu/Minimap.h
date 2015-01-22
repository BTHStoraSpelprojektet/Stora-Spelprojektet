#ifndef MINIMAP_H_
#define MINIMAP_H_

#include "GraphicsEngine.h"
#include "TextureLibrary.h"
#include "GUIElement.h"


class Minimap
{
public:
	Minimap();
	~Minimap();

	bool Initialize();
	void Shutdown();
	void Update(DirectX::XMFLOAT3 p_playerPos);
	void Render();

private:
	ID3D11ShaderResourceView* m_texture;
	GUIElement* m_minimap;
	GUIElement* m_playerDot;

	DirectX::XMFLOAT3 m_playerDotStartPos;
};
#endif // !MINIMAP_H_

/*
Pos
uppe v
53	63

ner v
53	70

ner h
52	70

uppe h
52	63
*/