#ifndef STRUCTURES
#define STRUCTURES

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
#endif