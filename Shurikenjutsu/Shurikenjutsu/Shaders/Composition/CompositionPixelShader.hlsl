struct Input
{
	float4 m_position : SV_POSITION;
	float2 m_textureCoordinates : TEXCOORD0;
};

// Pixel depth shader function.
float main(Input p_input) : SV_TARGET
{
	return p_input.m_position;
}