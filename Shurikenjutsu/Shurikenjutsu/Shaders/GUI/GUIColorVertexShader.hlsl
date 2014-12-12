cbuffer cPerObject
{
	matrix world;
	matrix projection;
};

struct Input
{
	float3 m_position : POSITION;
};

struct Output
{
	float4 m_position: SV_POSITION;
};

Output main(Input p_input)
{
	Output output = (Output)0;
	matrix worldt = transpose(world);
	output.m_position = mul(float4(p_input.m_position, 1), worldt);
	output.m_position = mul(float4(output.m_position), projection);
	output.m_position.w = 1.0f;

	return output;
}