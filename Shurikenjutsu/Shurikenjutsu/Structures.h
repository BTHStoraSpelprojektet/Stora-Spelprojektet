#ifndef STRUCTURES
#define STRUCTURES

#include <DirectXMath.h>

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

struct Vertex
{
	// Variables.
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT2 m_textureCoordinates;
	DirectX::XMFLOAT3 m_normal;
	DirectX::XMFLOAT3 m_tangent;

	// Constructors.
	Vertex(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT2 p_textureCoordinates, DirectX::XMFLOAT3 p_normal, DirectX::XMFLOAT3 p_tangent)
	{
		m_position = p_position;
		m_textureCoordinates = p_textureCoordinates;
		m_normal = p_normal;
		m_tangent = p_tangent;
	}
};
#endif