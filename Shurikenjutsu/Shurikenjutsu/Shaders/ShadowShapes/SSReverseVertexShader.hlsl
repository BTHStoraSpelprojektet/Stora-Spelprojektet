// Matrix buffer.
cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;

	matrix m_lightViewMatrix;
	matrix m_lightProjectionMatrix;
};

// Fog calculation buffer.
cbuffer FogBuffer : register(b1)
{
	float m_fogStart;
	float m_fogEnd;
	float m_fogDensity;
	float m_padding;
};

// Vertex input.
struct Input
{
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
	float3 m_normal : NORMAL;
	float3 m_tangent : TANGENT;
};

// Vertex output.
struct Output
{
	float4 m_positionHomogenous : SV_POSITION;
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;

	float3x3 m_tBN : TBN;
	float4 m_lightPositionHomogenous : TEXCOORD1;
};

// Vertex shader
Output main(Input p_input)
{
	Output output;

	// Store vertex position in world space.
	output.m_positionWorld = p_input.m_positionWorld;
	output.m_positionWorld.w = 1.0f;
	output.m_positionWorld = mul(output.m_positionWorld, m_worldMatrix);

	// Transform vertex position to homogenous clip space.
	output.m_positionHomogenous = mul(output.m_positionWorld, m_viewMatrix);
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_projectionMatrix);

	// Pass along the texture coordinates.
	output.m_textureCoordinate = p_input.m_textureCoordinate;

	// Calculate the position of the vertice as viewed by the light source.
	output.m_lightPositionHomogenous = mul(output.m_positionWorld, m_lightViewMatrix);
	output.m_lightPositionHomogenous = mul(output.m_lightPositionHomogenous, m_lightProjectionMatrix);

	// Pass on tangent.
	float3 tangent = mul(float4(p_input.m_tangent, 0.0f), m_worldMatrix).xyz;
	tangent = mul(tangent, (float3x3)m_viewMatrix).xyz;

	// Transform  the normals.
	float3 normal = mul(float4(p_input.m_normal, 0.0f), m_worldMatrix).xyz;
	normal = mul(normal, (float3x3)m_viewMatrix).xyz;

	// Normalmap TBN matrix.
	float3 N = normal;
	float3 T = -normalize(tangent - dot(tangent, N)*N);
	float3 B = cross(N, T);

	output.m_tBN = float3x3(T, B, N);

	// Return output.
	return output;
}