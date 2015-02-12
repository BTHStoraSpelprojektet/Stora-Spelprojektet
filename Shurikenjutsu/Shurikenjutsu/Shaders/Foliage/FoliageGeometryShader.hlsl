cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;

	matrix m_lightViewMatrix;
	matrix m_lightProjectionMatrix;
};

cbuffer AngleBuffer : register(b1)
{
	float4 m_rotation;
};

struct GeometryInput
{
	float3 m_position : POSITION;
	float2 m_offset : OFFSET;
};

struct GeometryOutput
{
	float4 m_position : SV_POSITION;
	float2 m_uv : UVCOORD;
	float4 m_lightPositionHomogenous : LIGHTPOS;
};

[maxvertexcount(6)]
void main(point GeometryInput p_input[1], inout TriangleStream<GeometryOutput> p_output)
{
	float4 position[6];
	float2 uv[6];

	// Triangle 1, top left.
	position[0] = float4((p_input[0].m_position.x - 0.25f), p_input[0].m_position.y, p_input[0].m_position.z - p_input[0].m_offset.y, 1.0f); //y
	uv[0] = float2(0.0f, 1.0f);

	// Triangle 1, top right.
	position[1] = float4((p_input[0].m_position.x + 0.25f), p_input[0].m_position.y, p_input[0].m_position.z - p_input[0].m_offset.x, 1.0f); //x
	uv[1] = float2(1.0f, 1.0f);

	// Triangle 1, bottom right.
	position[2] = float4(p_input[0].m_position.x + 0.25f + m_rotation.x, 0.1f + p_input[0].m_offset.x, (p_input[0].m_position.z + 0.5f), 1.0f); //x
	uv[2] = float2(1.0f, 0.0f);

	// Triangle 2, top left.
	position[3] = position[0];
	uv[3] = uv[0];

	// Triangle 2, bottom right.
	position[4] = position[2];
	uv[4] = uv[2];

	// Triangle 2, bottom left.
	position[5] = float4(p_input[0].m_position.x - 0.25f + m_rotation.x, 1.0f + p_input[0].m_offset.y, (p_input[0].m_position.z + 0.5f), 1.0f); //y
	uv[5] = float2(0.0f, 0.0f);

	GeometryOutput output;
	[unroll]
	for (uint i = 0; i < 6; i++)
	{
		output.m_position = mul(position[i], m_viewMatrix);
		output.m_position = mul(output.m_position, m_projectionMatrix);

		output.m_lightPositionHomogenous = mul(position[i], m_lightViewMatrix);
		output.m_lightPositionHomogenous = mul(output.m_lightPositionHomogenous, m_lightProjectionMatrix);

		output.m_uv = uv[i];

		p_output.Append(output);
	}
}