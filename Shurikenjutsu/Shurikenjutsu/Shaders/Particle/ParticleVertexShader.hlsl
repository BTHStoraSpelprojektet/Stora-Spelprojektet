struct Vertex
{
	float3 m_position : POSITION;
	float2 m_size : SIZE;
	float4 m_color : COLOR;
};

Vertex main(Vertex p_input)
{
	return p_input;
}