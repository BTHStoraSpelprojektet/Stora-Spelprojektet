cbuffer cPerObject
{
	matrix world;
	matrix projection;
};

struct Input
{
	float3 m_position : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
};

struct Output
{
	float4 m_position: SV_POSITION;
	float2 m_textureCoordinate :TEXCOORD;
};

Output main(Input p_input)
{
	Output output = (Output)0;
	matrix worldt = transpose(world);
	output.m_position = mul(float4(p_input.m_position, 1), worldt);
	output.m_position = mul(float4(output.m_position), projection);
	output.m_position.w = 1.0f;
	output.m_textureCoordinate = p_input.m_textureCoordinate;

	return output;
}