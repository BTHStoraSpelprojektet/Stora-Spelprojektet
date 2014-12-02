// Matrix buffer.
cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;

	matrix m_lightViewMatrix;
	matrix m_lightProjectionMatrix;
};

float4 main(float3 p_position : POSITION) : SV_POSITION
{
	float4 output = float4(p_position.xyz, 1.0f);

	// Transform vertex position to homogenous clip space.
	output = mul(output, m_worldMatrix);
	output = mul(output, m_viewMatrix);
	output = mul(output, m_projectionMatrix);

	return output;
}