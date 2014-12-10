cbuffer MatrixBuffer
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

struct VertexInput
{
	float4 m_position : POSITION;
	float2 m_UV : TEXCOORD0;
	float4 m_color : COLOR;
};

struct VertexOutput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : TEXCOORD0;
	float4 m_color : COLOR;
};

VertexOutput main(VertexInput p_input)
{
	VertexOutput output;

	// Change the position vector to be 4 units for proper matrix calculations.
	p_input.m_position.w = 1.0f;

	// Calculate the position of the vertex against the world, view, and projection matrices.
	output.m_position = mul(p_input.m_position, m_worldMatrix);
	output.m_position = mul(output.m_position, m_viewMatrix);
	output.m_position = mul(output.m_position, m_projectionMatrix);

	// Store the texture coordinates for the pixel shader.
	output.m_UV = p_input.m_UV;

	// Store the particle color for the pixel shader. 
	output.m_color = p_input.m_color;

	return output;
}