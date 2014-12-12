cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

struct GeometryInput
{
	float3 m_position : POSITION;
	float2 m_size : SIZE;
	float4 m_color : COLOR;
};

struct GeometryOutput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : TEXCOORD0;
	float4 m_color : COLOR;
};

[maxvertexcount(6)]
void main(point GeometryInput p_input[1], inout TriangleStream<GeometryOutput> p_output)
{
	float4 position[6];
	float2 uv[6];

	// Triangle 1, top left.
	position[0] = float4(p_input[0].m_position.x - p_input[0].m_size.x, p_input[0].m_position.y, p_input[0].m_position.z - p_input[0].m_size.y, 1.0f);
	uv[0] = float2(0.0f, 0.0f);

	// Triangle 1, top right.
	position[1] = float4(p_input[0].m_position.x + p_input[0].m_size.x, p_input[0].m_position.y, p_input[0].m_position.z - p_input[0].m_size.y, 1.0f);
	uv[1] = float2(1.0f, 0.0f);

	// Triangle 1, bottom right.
	position[2] = float4(p_input[0].m_position.x + p_input[0].m_size.x, p_input[0].m_position.y, p_input[0].m_position.z + p_input[0].m_size.y, 1.0f);
	uv[2] = float2(1.0f, 1.0f);

	// Triangle 2, top left.
	position[3] = position[0];
	uv[3] = uv[0];

	// Triangle 2, bottom right.
	position[4] = position[2];
	uv[4] = uv[2];

	// Triangle 2, bottom left.
	position[5] = float4(p_input[0].m_position.x - p_input[0].m_size.x, p_input[0].m_position.y, p_input[0].m_position.z + p_input[0].m_size.y, 1.0f);
	uv[5] = float2(0.0f, 1.0f);

	GeometryOutput output;
	[unroll]
	for (uint i = 0; i < 6; i++)
	{
		output.m_position = mul(position[i], m_worldMatrix);
		output.m_position = mul(output.m_position, m_viewMatrix);
		output.m_position = mul(output.m_position, m_projectionMatrix);

		output.m_UV = uv[i];

		output.m_color = p_input[0].m_color;

		p_output.Append(output);
	}
}