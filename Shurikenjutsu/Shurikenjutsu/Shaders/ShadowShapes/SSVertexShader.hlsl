cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

struct Output
{
	float4 m_position : SV_POSITION;
};

Output main(float3 p_position : POSITION)
{
	Output output;

	output.m_position = float4(p_position.xyz, 1.0f);
	output.m_position = mul(output.m_position, m_worldMatrix);
	output.m_position = mul(output.m_position, m_viewMatrix);
	output.m_position = mul(output.m_position, m_projectionMatrix);

	return output;
}