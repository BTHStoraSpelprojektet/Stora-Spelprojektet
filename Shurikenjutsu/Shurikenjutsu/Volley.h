#ifndef VOLLEY_H_
#define VOLLEY_H_

#include <vector>
#include "Structures.h"

class VolleyObject;

class Volley
{
public:
	Volley();
	~Volley();

	bool Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition);
	void Shutdown();
	void Update();
	void Render();
	void RenderDepth();

private:
	void AddRandomProjectiles(int p_amount, DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition);
	std::vector<VolleyObject*> m_projectiles;

	float m_timer;
	bool m_isThrowing;
	int m_id;
};
#endif