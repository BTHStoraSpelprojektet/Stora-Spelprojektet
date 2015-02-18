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
	clip(textureColor.a - 0.15f);

	float shadowSum = 0.0f;

	// Set fog color.
	float4 fogColor = float4(0.5f, 0.5f, 0.5f, 1.0f);

	// Calculate light
	Material material;
	material.m_ambient = float4(1.0f, 1.0f, 1.0f, 1.0f);
	material.m_diffuse = float4(1.0f, 1.0f, 1.0f, 1.0f);

	float4 A = m_directionalLight.m_ambient;
	float4 D = 0.0f;
	float4 S = 0.0f;

	// Sample NormalMap.
	float4 normalMapSample = m_normalMap.Sample(m_sampler, p_input.m_textureCoordinate).rgba;
	material.m_specular = float4(normalMapSample.a, normalMapSample.a, normalMapSample.a, normalMapSample.a * 255.0f);

	// Uncompress NormalMap - to get it into the right range.
	float3 normalT = 2.0f * normalMapSample.xyz - 1.0f;

	// Transforms from tangetspace to world space.
	float3 bumpedNormalW = mul(normalT, p_input.m_tBN);

	// Normalize normals.
	float3 normal = normalize(bumpedNormalW);

	// Calculate the vector to the camera.
	float3 toCamera = normalize(m_directionalLight.m_cameraPosition.xyz - p_input.m_positionWorld.xyz);

	// Compute directional light
	ComputeDirectionalLight(material, m_directionalLight, normal, toCamera, A, D, S);

	// Calculate projected shadow map coordinates.
	float2 shadowMapCoordinates;
	shadowMapCoordinates.x = p_input.m_lightPositionHomogenous.x / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;
	shadowMapCoordinates.y = -p_input.m_lightPositionHomogenous.y / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;

	// Calculate if the coordinates are in the range 0 to 1. If they are then the pixel is lit.
	if ((saturate(shadowMapCoordinates.x) == shadowMapCoordinates.x) && (saturate(shadowMapCoordinates.y) == shadowMapCoordinates.y))
	{
		// Sample the shadow map using PCF.
		float depth[9];
		depth[0] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates).r;
		depth[1] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(0.0f, 1.0f / 1152.0f)).r;
		depth[2] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(1.0f / 2048.0f, 1.0f / 1152.0f)).r;
		depth[3] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(1.0f / 2048.0f, 0.0f)).r;
		depth[4] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(1.0f / 2048.0f, -1.0f / 1152.0f)).r;
		depth[5] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(0.0f, -1.0f / 1152.0f)).r;
		depth[6] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(-1.0f / 2048.0f, -1.0f / 1152.0f)).r;
		depth[7] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(-1.0f / 2048.0f, 0.0f)).r;
		depth[8] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(-1.0f / 2048.0f, 1.0f / 1152.0f)).r;

		// Calculate the depth of the light.
		float lightDepth = p_input.m_lightPositionHomogenous.z - 0.0001f;

		// Compare the depth of the shadow map and the depth of the light.
		shadowSum += lightDepth < depth[0];
		shadowSum += lightDepth < depth[1];
		shadowSum += lightDepth < depth[2];
		shadowSum += lightDepth < depth[3];
		shadowSum += lightDepth < depth[4];
		shadowSum += lightDepth < depth[5];
		shadowSum += lightDepth < depth[6];
		shadowSum += lightDepth < depth[7];
		shadowSum += lightDepth < depth[8];
		shadowSum = shadowSum / 9.0f;
	}

	// Add light.
	textureColor.xyz = textureColor.xyz*((A.xyz + D.xyz * shadowSum) + S.xyz * shadowSum);
	
	// Add fog.
	float4 coloredPixel = p_input.m_fogFactor * textureColor + (1.0f - p_input.m_fogFactor) * fogColor;

	// Return shaded pixel.
	p_output.a = float4(coloredPixel.xyz, 1.0f);
	p_output.b = float4(p_input.m_normal, 1.0f);
}