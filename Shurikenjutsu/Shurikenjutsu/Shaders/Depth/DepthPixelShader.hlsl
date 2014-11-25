struct Input
{
	float4 m_position : POSITION;
};

// Pixel depth shader function.
float4 main(Input p_input) : SV_TARGET
{
	// Initialize outputs values.
	float depth;
	float4 value;

	// The depth value of the pixel is obtained by dividing the pixel depth by the homogeneous W coordinate.
	depth = p_input.m_position.z / p_input.m_position.w;

	// Save the depth value to the color, making the texture range from black to white.
	value = float4(depth, depth, depth, 1.0f);

	// Return depth value.
	return value;
}