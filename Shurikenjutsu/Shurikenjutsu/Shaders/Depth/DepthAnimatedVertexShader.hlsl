cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

// Animation matrix buffer.
cbuffer AnimationMatrixBuffer : register(b2)
{
	matrix m_boneTransforms[30];
};

struct Input
{
	float4 m_position : POSITION;
	float2 m_textureCoordinates : TEXCOORD0;
	float3 m_weight : WEIGHT;
	uint3 m_boneIndex : BONEINDEX;
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

	float weights[3] = { 0.0f, 0.0f, 0.0f };
	weights[0] = p_input.m_weight.x;
	weights[1] = p_input.m_weight.y;
	weights[2] = p_input.m_weight.z;

	float3 positionAnimated = float3(0.0f, 0.0f, 0.0f);

		for (int i = 0; i < 3; i++)
		{
			positionAnimated += weights[i] * mul(float4(p_input.m_position.xyz, 1.0f), m_boneTransforms[p_input.m_boneIndex[i]]).xyz;
		}

	// Transform vertex position to homogenous clip space.
	output.m_position = float4(positionAnimated, 1.0f);
	output.m_position = mul(output.m_position, m_worldMatrix);
	output.m_position = mul(output.m_position, m_viewMatrix);
	output.m_position = mul(output.m_position, m_projectionMatrix);

	output.m_depthPosition = output.m_position;

	output.m_textureCoordinates = p_input.m_textureCoordinates;

	// Return output.
	return output;
}