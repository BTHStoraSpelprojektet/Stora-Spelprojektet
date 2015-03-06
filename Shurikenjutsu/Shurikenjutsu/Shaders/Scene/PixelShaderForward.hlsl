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
	float3 m_normal : NORMAL;
	float3 m_tangent : TANGENT;

	float3x3 m_tBN : TBN;

	float m_fogFactor : FOG;

	float4 m_lightPositionHomogenous : TEXCOORD1;
};

// Pixel shader function.
float4 main(Input p_input) : SV_Target
{
	// Sample texture using texture coordinates.
	float4 textureColor = m_texture.Sample(m_sampler, p_input.m_textureCoordinate);
	clip(textureColor.a - 0.15f);

	// Return shaded pixel.
	return textureColor;
}