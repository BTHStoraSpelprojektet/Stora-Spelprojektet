cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

struct GeometryInput
{
	float3 m_position : POSITION;
	float m_angle : ANGLE;
	float m_width : WIDTH;
	float2 m_timeValues : TIMES;
	float4 m_color : COLOR;
	float m_endpoint : BOOL;
};

struct GeometryOutput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : TEXCOORD0;
	float2 m_timeValues : TIMES;
	float4 m_color : COLOR;
};

[maxvertexcount(12)]
void main(line GeometryInput p_input[2], inout TriangleStream<GeometryOutput> p_output)
{
	GeometryOutput output;
	float4 position[12];
	float2 uv[12];

	//=======================================================
	//
	//    Trail geometry constructed from points T and B.
	//    12 vertex points, 4 triangles.
	//
	//   (t1)--(T)--(t2)  <=  Top Point.
	//    |         / |       (p_input[0])
	//    |  1    /   |
	//    |     /     |
	//    |   /    2  |
	//    | /         |
	//   (m1)--(M)--(m2)  <=  Middle Point.
	//    |         / |       (middlePoint)
	//    |  3    /   |
	//    |     /     |
	//    |   /    4  |
	//    | /         |       Bottom Point.
	//   (b1)--(B)--(b2)  <=  (p_input[1])             
	//
	//=======================================================

	// Interpolate a middle point.
	GeometryInput middlePoint;
	middlePoint.m_position.x = (p_input[0].m_position.x + p_input[1].m_position.x) * 0.5f;
	middlePoint.m_position.y = (p_input[0].m_position.y + p_input[1].m_position.y) * 0.5f;
	middlePoint.m_position.z = (p_input[0].m_position.z + p_input[1].m_position.z) * 0.5f;
	middlePoint.m_angle = (p_input[0].m_angle + p_input[1].m_angle) * 0.5f;
	middlePoint.m_width = (p_input[0].m_width + p_input[1].m_width) * 0.5f;
	middlePoint.m_timeValues.x = (p_input[0].m_timeValues.x + p_input[1].m_timeValues.x) * 0.5f;
	middlePoint.m_timeValues.y = (p_input[0].m_timeValues.y + p_input[1].m_timeValues.y) * 0.5f;
	middlePoint.m_color = p_input[0].m_color;
	middlePoint.m_endpoint = false;

	float3 t1;
	float3 t2;
	float3 m1;
	float3 m2;
	float3 b1;
	float3 b2;

	// Calculate corners for tile segments.
	if (p_input[1].m_endpoint == 0.0f)
	{
		t1 = float3(p_input[0].m_position.x - (cos(p_input[0].m_angle) * p_input[0].m_width), p_input[0].m_position.y, p_input[0].m_position.z + (sin(p_input[0].m_angle) * p_input[0].m_width));
		t2 = float3(p_input[0].m_position.x - (cos(p_input[0].m_angle) * p_input[0].m_width), p_input[0].m_position.y, p_input[0].m_position.z - (sin(p_input[0].m_angle) * p_input[0].m_width));
		m1 = float3(middlePoint.m_position.x - (cos(middlePoint.m_angle) * middlePoint.m_width), middlePoint.m_position.y, middlePoint.m_position.z + (sin(middlePoint.m_angle) * middlePoint.m_width));
		m2 = float3(middlePoint.m_position.x + (cos(middlePoint.m_angle) * middlePoint.m_width), middlePoint.m_position.y, middlePoint.m_position.z - (sin(middlePoint.m_angle) * middlePoint.m_width));
		b1 = float3(p_input[1].m_position.x - (cos(p_input[1].m_angle) * p_input[1].m_width), p_input[1].m_position.y, p_input[1].m_position.z + (sin(p_input[1].m_angle) * p_input[1].m_width));
		b2 = float3(p_input[1].m_position.x + (cos(p_input[1].m_angle) * p_input[1].m_width), p_input[1].m_position.y, p_input[1].m_position.z - (sin(p_input[1].m_angle) * p_input[1].m_width));
	}

	// Calculate corners for tile end segments.
	else
	{
		t1 = float3(p_input[0].m_position.x - (cos(p_input[0].m_angle) * p_input[0].m_width), p_input[0].m_position.y, p_input[0].m_position.z + (sin(p_input[0].m_angle) * p_input[0].m_width));
		t2 = float3(p_input[0].m_position.x - (cos(p_input[0].m_angle) * p_input[0].m_width), p_input[0].m_position.y, p_input[0].m_position.z - (sin(p_input[0].m_angle) * p_input[0].m_width));
		m1 = float3(middlePoint.m_position.x - (cos(middlePoint.m_angle) * (middlePoint.m_width * 0.5f)), middlePoint.m_position.y, middlePoint.m_position.z + (sin(middlePoint.m_angle) * (middlePoint.m_width * 0.5f)));
		m2 = float3(middlePoint.m_position.x + (cos(middlePoint.m_angle) * (middlePoint.m_width * 0.5f)), middlePoint.m_position.y, middlePoint.m_position.z - (sin(middlePoint.m_angle) * (middlePoint.m_width * 0.5f)));
		b1 = p_input[1].m_position;
		b2 = float3(0.0f, 0.0f, 0.0f);
	}
	
	// Triangle 1, top left.
	position[0] = float4(t1, 1.0f);
	uv[0] = float2(0.0f, 0.0f);
	position[1] = float4(t2, 1.0f);
	uv[1] = float2(1.0f, 0.0f);
	position[2] = float4(m1, 1.0f);
	uv[2] = float2(0.0f, 1.0f);

	// Triangle 2, top right.
	position[3] = float4(t2, 1.0f);
	uv[3] = float2(1.0f, 0.0f);
	position[4] = float4(m2, 1.0f);
	uv[4] = float2(1.0f, 1.0f);
	position[5] = float4(m1, 1.0f);
	uv[5] = float2(0.0f, 1.0f);

	// Triangle 3, bottom left.
	position[6] = float4(m1, 1.0f);
	uv[6] = float2(0.0f, 0.0f);
	position[7] = float4(m2, 1.0f);
	uv[7] = float2(1.0f, 0.0f);
	position[8] = float4(b1, 1.0f);
	uv[8] = float2(0.0f, 1.0f);

	// If this is the end of the trail, remove one triangle.
	if (p_input[1].m_endpoint == 0.0f)
	{
		// Triangle 4, bottom right.
		position[9] = float4(m2, 1.0f);
		uv[9] = float2(1.0f, 0.0f);
		position[10] = float4(b2, 1.0f);
		uv[10] = float2(1.0f, 1.0f);
		position[11] = float4(b1, 1.0f);
		uv[11] = float2(0.0f, 1.0f);
	}

	[unroll] // Top quad.
	for (uint i = 0; i < 6; i++)
	{
		// Transform and append geometry.
		output.m_position = mul(position[i], m_worldMatrix);
		output.m_position = mul(output.m_position, m_viewMatrix);
		output.m_position = mul(output.m_position, m_projectionMatrix);
		output.m_UV = uv[i];
		output.m_timeValues = p_input[0].m_timeValues;
		output.m_color = p_input[0].m_color;

		p_output.Append(output);
	}

	uint last = 12 - (int)p_input[1].m_endpoint;

	[unroll] // Bottom quad.
	for (uint j = 5; j < 12 - last; j++)
	{
		// Transform and append geometry.
		output.m_position = mul(position[j], m_worldMatrix);
		output.m_position = mul(output.m_position, m_viewMatrix);
		output.m_position = mul(output.m_position, m_projectionMatrix);
		output.m_UV = uv[j];
		output.m_timeValues = p_input[1].m_timeValues;
		output.m_color = p_input[1].m_color;

		p_output.Append(output);
	}
}