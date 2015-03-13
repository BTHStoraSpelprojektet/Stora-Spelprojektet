#include "LightCalculation.hlsli"

// "Every frame" buffer
cbuffer FrameBuffer : register(b0)
{
	DirectionalLight m_directionalLight;
};

cbuffer ShadowMapSize : register(b1)
{
	float m_shadowMapWidth;
	float m_shadowMapHeight;
	float p0;
	float p1;
};

Texture2D m_texture : register(t0);
Texture2D m_normalMap : register(t1);
Texture2D m_shadowMap : register(t2);

SamplerState m_sampler : register(s0);
SamplerState m_samplerShadowMap  : register(s1);

// Vertex structure.
struct Input
{
	float4 m_positionHomogenous : SV_POSITION;
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
	float3x3 m_tBN : TBN;
};

struct gBuffer
{
	float4 a: SV_Target0;
	float4 b: SV_Target1;
};

// Pixel shader function.
void main(Input p_input , out gBuffer p_output)
{
	// Sample texture using texture coordinates.
	float4 textureColor = m_texture.Sample(m_sampler, p_input.m_textureCoordinate);
	clip(textureColor.a - 0.50f);

	// Sample NormalMap.
	float4 normalMapSample = m_normalMap.Sample(m_sampler, p_input.m_textureCoordinate).rgba;

	// Uncompress NormalMap - to get it into the right range.
	float3 normalT = 2.0f * normalMapSample.xyz - 1.0f;

	// Transforms from tangetspace to view space.
	float3 bumpedNormalW = mul(normalT, p_input.m_tBN);

	// Normalize normals.
	float3 normal = normalize(bumpedNormalW);

	// Compress normals so they will fit in the 8bit space of the gBuffer.
	normal = 0.5f * normal + 0.5f;

	// Write to the gBuffers
	p_output.a = float4(textureColor.xyz, normalMapSample.a);
	p_output.b = float4(normal, 1.0f);
}