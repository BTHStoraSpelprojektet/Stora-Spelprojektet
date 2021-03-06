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

// Animation matrix buffer.
cbuffer AnimationMatrixBuffer : register(b2)
{
	matrix m_boneTransforms[30];
};

// Vertex input.
struct Input
{
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
	float3 m_normal : NORMAL;
	float3 m_tangent : TANGENT;
	float3 m_weight : WEIGHT;
	uint3 m_boneIndex : BONEINDEX;
};

// Vertex output.
struct Output
{
	float4 m_positionHomogenous : SV_POSITION;
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
	float3x3 m_tBN : TBN;
};

// Vertex shader
Output main(Input p_input)
{
	Output output;

	float weights[3] = { 0.0f, 0.0f, 0.0f };
	weights[0] = p_input.m_weight.x;
	weights[1] = p_input.m_weight.y;
	weights[2] = p_input.m_weight.z;

	float3 positionAnimated = float3(0.0f, 0.0f, 0.0f);
	float3 normalAnimated = float3(0.0f, 0.0f, 0.0f);
	float3 tangentAnimated = float3(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 3; i++)
	{
		positionAnimated += weights[i] * mul(float4(p_input.m_positionWorld.xyz, 1.0f), m_boneTransforms[p_input.m_boneIndex[i]]).xyz;
		normalAnimated += weights[i] * mul(float4(p_input.m_normal, 0.0f), m_boneTransforms[p_input.m_boneIndex[i]]).xyz;
		tangentAnimated += weights[i] * mul(float4(p_input.m_tangent, 0.0f), m_boneTransforms[p_input.m_boneIndex[i]]).xyz;
	}

	// Store vertex position in world space.
	output.m_positionWorld = float4(positionAnimated, 1.0f);
	output.m_positionWorld.w = 1.0f;
	output.m_positionWorld = mul(output.m_positionWorld, m_worldMatrix);

	// Transform vertex position to homogenous clip space.
	output.m_positionHomogenous = mul(output.m_positionWorld, m_viewMatrix);
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_projectionMatrix);

	// Pass along the texture coordinates.
	output.m_textureCoordinate = p_input.m_textureCoordinate;

	// Transform  the normals.
	normalAnimated = mul(float4(normalAnimated, 0.0f), m_worldMatrix).xyz;
	normalAnimated = mul(normalAnimated, (float3x3)m_viewMatrix).xyz;

	tangentAnimated = mul(float4(tangentAnimated, 0.0f), m_worldMatrix).xyz;
	tangentAnimated = mul(tangentAnimated, (float3x3)m_viewMatrix).xyz;

	// Normalmap TBN matrix.
	float3 N = normalAnimated;
	float3 T = -normalize(tangentAnimated - dot(tangentAnimated, N)*N);
	float3 B = cross(N, T);

	output.m_tBN = float3x3(T, B, N);

	// Return output.
	return output;
}