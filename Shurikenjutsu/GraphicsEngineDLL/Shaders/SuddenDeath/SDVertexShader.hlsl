cbuffer MatrixBuffer : register(b0)
{
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
	float4 m_color;
};

struct Input
{
	float3 m_position : POSITION;
	float2 m_UV : UV;
};

struct Output
{
	float4 m_position : SV_POSITION;
	float2 m_UV : UV;
	float4 m_color : COLOR;
};

Output main(Input p_input)
{
	Output output;
	output.m_position = float4(p_input.m_position.xyz, 1.0f);
	output.m_position = mul(output.m_position, m_viewMatrix);
	output.m_position = mul(output.m_position, m_projectionMatrix);
	output.m_UV = p_input.m_UV;
	output.m_color = m_color;

	return output;
}