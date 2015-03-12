cbuffer MatrixBufferOutlining : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
	float3 m_color;
};

// Animation matrix buffer.
cbuffer AnimationMatrixBuffer : register(b2)
{
	matrix m_boneTransforms[30];
};

struct VS_INPUT
{
	float4 Pos : POSITION;
	float3 m_weight : WEIGHT;
	uint3 m_boneIndex : BONEINDEX;
};

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 color : COLOR;
};

PS_INPUT main( VS_INPUT input )
{
	PS_INPUT output = (PS_INPUT)0;
	
	float weights[3] = { 0.0f, 0.0f, 0.0f };
	weights[0] = input.m_weight.x;
	weights[1] = input.m_weight.y;
	weights[2] = input.m_weight.z;

	float3 positionAnimated = float3(0.0f, 0.0f, 0.0f);
	
	for (int i = 0; i < 3; i++)
	{
		positionAnimated += weights[i] * mul(float4(input.Pos.xyz, 1.0f), m_boneTransforms[input.m_boneIndex[i]]).xyz;
	}

	output.Pos = float4(positionAnimated, 1.0f);
	output.Pos = mul(output.Pos, m_worldMatrix);
	output.Pos = mul(output.Pos, m_viewMatrix);
	output.Pos = mul(output.Pos, m_projectionMatrix);
	output.color = float4(m_color, 1.0f);

	return output;
}