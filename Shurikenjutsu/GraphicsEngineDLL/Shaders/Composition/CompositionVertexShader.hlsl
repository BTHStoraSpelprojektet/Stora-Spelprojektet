struct Output
{
	float4 m_position : SV_POSITION;
};

// Vertex depth shader function.
Output main(uint vertexID : SV_VertexID)
{
	Output output;

	float2 grid = float2((vertexID << 1) & 2, vertexID & 2);
	output.m_position = float4((grid * 2) + float2(-1.0f, -1.0f), 0.0f, 1.0f);// * float2(2.0f, -2.0f) + float2(-1.0f, 1.0f)
	output.m_position.x *= -1;

	return output;
}