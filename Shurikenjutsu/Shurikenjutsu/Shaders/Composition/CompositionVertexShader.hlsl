struct Input
{
	float4 m_position : POSITION;
	float2 m_textureCoordinates : TEXCOORD0;
};

struct Output
{
	float4 m_position : SV_POSITION;
	float2 m_textureCoordinates : TEXCOORD0;
};

// Vertex depth shader function.
Output main(Input p_input)
{
	Output asdf = p_input;
	return asdf;
}