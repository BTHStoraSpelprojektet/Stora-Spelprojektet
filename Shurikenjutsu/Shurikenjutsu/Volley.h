#ifndef VOLLEY_H_
#define VOLLEY_H_

#include <vector>
#include "Structures.h"

class MovingObject;

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
	void AddRandomProjectiles(int p_amount);
	std::vector<MovingObject*> m_projectiles;

	DirectX::XMFLOAT3 m_startPosition;
	DirectX::XMFLOAT3 m_endPosition;
	DirectX::XMFLOAT3 m_lastPosition;
	float m_timer;
	bool m_isThrowing;
	int m_id;
	float m_speed;
	float m_angle;
	float m_percentX;
	float m_percentZ;
};
#endif