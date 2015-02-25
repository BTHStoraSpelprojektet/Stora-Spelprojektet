#ifndef STRUCTURES
#define STRUCTURES

#include "..\CommonLibs\CommonStructures.h"

struct WindowRectangle
{
	// Variables.
	long x;
	long y;
	long width;
	long height;

	// Constructors.
	WindowRectangle()
	{
		x = 0;
		y = 0;
		width = 0;
		height = 0;
	}

	WindowRectangle(long p_x, long p_y, long p_width, long p_height)
	{
		x = p_x;
		y = p_y;

		width = p_width;
		height = p_height;
	}
};

struct DirectionalLight
{
	DirectX::XMVECTOR m_ambient;
	DirectX::XMVECTOR m_diffuse;
	DirectX::XMVECTOR m_specular;
	DirectX::XMVECTOR m_direction;
	DirectX::XMVECTOR m_cameraPosition;
};

struct PointLight
{
	DirectX::XMVECTOR m_ambient;
	DirectX::XMVECTOR m_diffuse;
	DirectX::XMVECTOR m_specular;

	DirectX::XMFLOAT3 m_position;
	float m_range;

	DirectX::XMFLOAT3 m_attenuation;
	float m_padding;
};

#endif