struct Vertex
{
	float3 m_position : POSITION;
	float2 m_offset : OFFSET;
};

Vertex main(Vertex p_input)
{
	return p_input;
}