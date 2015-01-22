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
};

struct Point
{
	float x;
	float y;

	Point()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Point(float p_x, float p_y)
	{
		x = p_x;
		y = p_y;
	}
};

struct Line
{
	Point a;
	Point b;

	Line(float ax, float ay, float bx, float by)
	{
		a = Point(ax, ay);
		b = Point(bx, by);
	}

	Line(Point p_a, Point p_b)
	{
		a = p_a;
		b = p_b;
	}
};
#endif