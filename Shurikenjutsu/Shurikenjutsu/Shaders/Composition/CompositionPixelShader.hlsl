#include "../Scene/LightCalculation.hlsli"

cbuffer FrameBuffer : register(b0)
{
	DirectionalLight m_directionalLight;
	matrix m_projectionMatrix;
	matrix m_projectedLightSpace;
};

Texture2D m_shadowMap : register(t2);
Texture2D m_textures[4] : register(t3);

SamplerState m_samplerShadowMap  : register(s1);

struct Input
{
	float4 m_position: SV_POSITION;
};

float3 ComputePositionViewFromZ(float2 positionScreen, float viewSpaceZ)
{
	float2 screenSpaceRay = float2(positionScreen.x / m_projectionMatrix._11, positionScreen.y / m_projectionMatrix._22);

	float3 positionView;
	positionView.z = viewSpaceZ;
	positionView.xy = screenSpaceRay.xy * positionView.z;

	return positionView;
}

float ReadShadowMap(float3 positionView)
{
	float4 projectedCameraDir = mul(float4(positionView, 1.0f), m_projectedLightSpace);
	projectedCameraDir.xy /= projectedCameraDir.w;

	float2 textureCoordinates;
	textureCoordinates.x = (projectedCameraDir.x * 0.5f + 0.5f);
	textureCoordinates.y = (-projectedCameraDir.y * 0.5f + 0.5f);

	const float bias = 0.0001f;
	float depthValue = m_shadowMap.Sample(m_samplerShadowMap, textureCoordinates).r;
	return projectedCameraDir.z - bias < depthValue;
}

float4 main(Input p_input) : SV_Target
{
	uint3 load = uint3(p_input.m_position.xy, 0); //

	float4 normal = m_textures[0].Load(load).xyzw; //
	normal.xyz = normalize((normal.xyz * 2.0f) - 1.0f); //

	float4 albedo = m_textures[1].Load(load).xyzw; //

	float zBuffer = m_textures[2].Load(load).x; //

	float ssao = m_textures[3].Load(load * 0.5f).x; //

	float2 textureDimensions; //
	m_textures[0].GetDimensions(textureDimensions.x, textureDimensions.y); //

	float2 screenPixelOffset = float2(2.0f, -2.0f) / textureDimensions; //
	float2 positionScreen = (float2(p_input.m_position.xy) + 0.5f) * screenPixelOffset.xy + float2(-1.0f, 1.0f);  //

	float viewSpaceZ = m_projectionMatrix._43 / (zBuffer - m_projectionMatrix._33);
	float3 positionView = ComputePositionViewFromZ(positionScreen, viewSpaceZ);

	Material material;
	material.m_ambient = float4(1.0f, 1.0f, 1.0f, 1.0f);
	material.m_diffuse = float4(1.0f, 1.0f, 1.0f, 1.0f);
	material.m_specular = float4(albedo.a, albedo.a, albedo.a, albedo.a * 255.0f);

	float4 A = 0.0f;
	float4 D = 0.0f;
	float4 S = 0.0f;

	float shadowSum = ReadShadowMap(positionView);
	float3 toCamera = normalize(-positionView);

	ComputeDirectionalLight(material, m_directionalLight, normal.xyz, toCamera, A, D, S);

	albedo.xyz = albedo.xyz*((A.xyz + D.xyz * (shadowSum*0.5f + 0.5f)) + S.xyz * shadowSum)*ssao;
	albedo.w = 1.0f;

	return float4(albedo.xyz, 1.0f);
}


/* Old shadow map pcf

float2 shadowMapCoordinates;
shadowMapCoordinates.x = p_input.m_lightPositionHomogenous.x / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;
shadowMapCoordinates.y = -p_input.m_lightPositionHomogenous.y / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;

// Calculate if the coordinates are in the range 0 to 1. If they are then the pixel is lit.
if ((saturate(shadowMapCoordinates.x) == shadowMapCoordinates.x) && (saturate(shadowMapCoordinates.y) == shadowMapCoordinates.y))
{
// Sample the shadow map using PCF.
float depth[17];
depth[0] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates).r;
depth[1] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(0.0f, 1.0f / 1152.0f)).r;
depth[2] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(1.0f / 2048.0f, 1.0f / 1152.0f)).r;
depth[3] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(1.0f / 2048.0f, 0.0f)).r;
depth[4] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(1.0f / 2048.0f, -1.0f / 1152.0f)).r;
depth[5] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(0.0f, -1.0f / 1152.0f)).r;
depth[6] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(-1.0f / 2048.0f, -1.0f / 1152.0f)).r;
depth[7] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(-1.0f / 2048.0f, 0.0f)).r;
depth[8] = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates + float2(-1.0f / 2048.0f, 1.0f / 1152.0f)).r;
depth[9] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(0.0f, 2.0f / 1152.0f)).r;
depth[10] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(2.0f / 2048.0f, 2.0f / 1152.0f)).r;
depth[11] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(2.0f / 2048.0f, 0.0f)).r;
depth[12] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(2.0f / 2048.0f, -2.0f / 1152.0f)).r;
depth[13] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(0.0f, -2.0f / 1152.0f)).r;
depth[14] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(-2.0f / 2048.0f, -2.0f / 1152.0f)).r;
depth[15] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(-2.0f / 2048.0f, 0.0f)).r;
depth[16] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(-2.0f / 2048.0f, 2.0f / 1152.0f)).r;

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
shadowSum += lightDepth < depth[9];
shadowSum += lightDepth < depth[10];
shadowSum += lightDepth < depth[11];
shadowSum += lightDepth < depth[12];
shadowSum += lightDepth < depth[13];
shadowSum += lightDepth < depth[14];
shadowSum += lightDepth < depth[15];
shadowSum += lightDepth < depth[16];
shadowSum = shadowSum / 17.0f;
}

*/