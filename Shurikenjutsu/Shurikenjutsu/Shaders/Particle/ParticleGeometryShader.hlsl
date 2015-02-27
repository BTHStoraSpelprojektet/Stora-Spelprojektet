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
	float m_rotation : ROTATION;
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

	//=======================================================
	//
	//    Particle geometry constructed from point M;
	//    6 vertex points, 2 triangles.
	//
	//   (t1)-------(t2)
	//    |         / |
	//    |  1    /   |
	//    |    (M)    |
	//    |   /    2  |
	//    | /         |
	//   (b1)-------(b2)
	//
	//=======================================================

	// Corners of the quad.
	float3 t1 = float3(- p_input[0].m_size.x, 0.0f, p_input[0].m_size.y);
	float3 t2 = float3(p_input[0].m_size.x, 0.0f, p_input[0].m_size.y);
	float3 b1 = float3(-p_input[0].m_size.x, 0.0f, - p_input[0].m_size.y);
	float3 b2 = float3(+p_input[0].m_size.x, 0.0f, - p_input[0].m_size.y);

	// Triangle 1, left.
	position[0] = float4(t1, 1.0f);
	uv[0] = float2(0.0f, 0.0f);
	position[1] = float4(t2, 1.0f);
	uv[1] = float2(1.0f, 0.0f);
	position[2] = float4(b1, 1.0f);
	uv[2] = float2(0.0f, 1.0f);

	// Triangle 2, right.
	position[3] = float4(t2, 1.0f);
	uv[3] = float2(1.0f, 0.0f);
	position[4] = float4(b2, 1.0f);
	uv[4] = float2(1.0f, 1.0f);
	position[5] = float4(b1, 1.0f);
	uv[5] = float2(0.0f, 1.0f);

	// Precalculate sine and cosine.
	float cosine = cos(p_input[0].m_rotation);
	float sine = sin(p_input[0].m_rotation);
	float3 translation = p_input[0].m_position;

	// Rotation and translation matrix.
	matrix M;
	M._11 =		cosine;		M._12 =		0.0f;		M._13 =		sine;		M._14 = 0.0f;
	M._21 =		0.0f;		M._22 =		1.0f;		M._23 =		0.0f;		M._24 = 0.0f;
	M._31 =		-sine;		M._32 =		0.0f;		M._33 =		cosine;		M._34 = 0.0f;
	M._41 = translation.x;	M._42 = translation.y;	M._43 = translation.z;	M._44 = 1.0f;

	// OUtput geometry.
	GeometryOutput output;
	[unroll]
	for (uint i = 0; i < 6; i++)
	{
		output.m_position = mul(position[i], M);
		output.m_position = mul(output.m_position, m_viewMatrix);
		output.m_position = mul(output.m_position, m_projectionMatrix);

		output.m_UV = uv[i];

		output.m_color = p_input[0].m_color;

		p_output.Append(output);
	}
}