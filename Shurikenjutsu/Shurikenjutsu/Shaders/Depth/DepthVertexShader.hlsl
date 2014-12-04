cbuffer MatrixBuffer
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

struct Input
{
	float4 m_position : POSITION;
	float2 m_textureCoordinates : TEXCOORD0;
};

struct Output
{
	float4 m_position : SV_POSITION;
	float2 m_textureCoordinates : TEXCOORD0;
	float4 m_depthPosition : TEXCOORD1;
};

// Vertex depth shader function.
Output main(Input p_input)
{
	// Setup vertex output.
	Output output;

	output.m_position = p_input.m_position;
	output.m_position.w = 1.0f;

	// Transform vertex position to homogenous clip space.
	output.m_position = mul(p_input.m_position, m_worldMatrix);
	output.m_position = mul(output.m_position, m_viewMatrix);
	output.m_position = mul(output.m_position, m_projectionMatrix);

	output.m_depthPosition = output.m_position;

	output.m_textureCoordinates = p_input.m_textureCoordinates;

	// Return output.
	return output;
}