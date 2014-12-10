#ifndef PARTICLEBASE
#define PARTICLEBASE

#include <DirectXMath.h>

class ParticleBase
{

private:
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_direction;
	DirectX::XMFLOAT3 m_color;

	float m_velocity;

	bool m_alive;
};
#endif