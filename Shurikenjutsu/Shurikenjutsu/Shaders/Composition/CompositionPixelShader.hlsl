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
	positionView.xy = positionView.xy * 0.5f + 0.5f;

	float4 projectedCameraDir = mul(float4(positionView, 1.0f), m_projectedLightSpace);
	projectedCameraDir.xy /= projectedCameraDir.w;

	float2 textureCoordinates;
	textureCoordinates.x = (projectedCameraDir.x * 0.5f + 0.5f);
	textureCoordinates.y = (-projectedCameraDir.y * 0.5f + 0.5f);

	const float bias = 0.0001f;
	float depthValue = m_shadowMap.Sample(m_samplerShadowMap, textureCoordinates).r - bias;
	return projectedCameraDir.z < depthValue;
}

float4 main(Input p_input) : SV_Target
{
	uint3 load = uint3(p_input.m_position.xy, 0); //

	float4 normal = m_textures[0].Load(load).xyzw; //
	normal.xyz = normalize((normal.xyz * 2.0f) - 1.0f); //
	float shadowSum = normal.w;

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

	shadowSum = ReadShadowMap(positionView);
	float3 toCamera = normalize(-positionView);

	ComputeDirectionalLight(material, m_directionalLight, normal.xyz, toCamera, A, D, S);

	albedo.xyz = albedo.xyz*((A.xyz + D.xyz * (shadowSum*0.5f + 0.5f)) + S.xyz * shadowSum)*ssao;
	albedo.w = 1.0f;

	//return mul(m_projectedLightSpace, float4(positionView, 1.0f));
	//return mul(float4(positionView, 1.0f), m_projectedLightSpace);
	return float4(albedo.xyz, 1.0f);
}