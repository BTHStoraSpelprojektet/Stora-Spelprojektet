#ifndef MINIMAP_H_
#define MINIMAP_H_

#include <DirectXMath.h>

struct ID3D11ShaderResourceView;
class GUIElement;

class Minimap
{
public:
	Minimap();
	~Minimap();

	bool Initialize();
	void Shutdown();
	void Update(DirectX::XMFLOAT3 p_playerPos);
	void Render();

	void UpdatePlayersPositon(int p_index, DirectX::XMFLOAT3 p_pos);
	DirectX::XMFLOAT3 ConvertPosToMinimapPos(DirectX::XMFLOAT3 p_playerPos);
	void SetTeamTexture(int p_index, int p_team);
	void SetPlayerTexture(int p_team);
	void SetPlayerPos(int p_index, DirectX::XMFLOAT3 p_pos);

private:
	ID3D11ShaderResourceView* m_texture;
	GUIElement* m_minimap;
	GUIElement* m_playerDot;
	GUIElement* m_background;
	GUIElement* m_otherPlayers[7];

	float m_minimapWidth, m_minimapHeight;

	DirectX::XMFLOAT3 m_centerOfMinimapPos;
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