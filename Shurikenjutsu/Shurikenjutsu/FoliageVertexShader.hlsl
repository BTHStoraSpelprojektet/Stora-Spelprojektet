struct Vertex
{
	float3 m_position : POSITION;
	float2 m_uv : TEXCOORD0;
	float2 m_foliageUv : TEXCOORD1;
};

Vertex main(Vertex p_input)
{
	return p_input;
}