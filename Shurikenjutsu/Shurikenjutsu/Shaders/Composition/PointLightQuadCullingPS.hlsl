#include "../Scene/LightCalculation.hlsli"

cbuffer FrameBuffer : register(b0)
{
	DirectionalLight m_directionalLight;
	matrix m_projectionMatrix;
};

Texture2D m_textures[4] : register(t3);

StructuredBuffer<PointLight> m_pointLights : register(t7);

struct Input
{
	float4 m_position: SV_POSITION;
	nointerpolation uint4 lightIndex : lightIndex;
};

float3 ComputePositionViewFromZ(float2 positionScreen, float viewSpaceZ)
{
	float2 screenSpaceRay = float2(positionScreen.x / m_projectionMatrix._11, positionScreen.y / m_projectionMatrix._22);

	float3 positionView;
	positionView.z = viewSpaceZ;
	positionView.xy = screenSpaceRay.xy * positionView.z;

	return positionView;
}

float4 main(Input p_input) : SV_Target
{
	uint3 load = uint3(p_input.m_position.xy, 0); //

	float4 normal = m_textures[0].Load(load).xyzw; //
	normal.xyz = normalize((normal.xyz * 2.0f) - 1.0f); //

	float3 albedo = m_textures[1].Load(load).xyz; //
	float specularPower = m_textures[1].Load(load).w; //

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
	material.m_specular = float4(specularPower, specularPower, specularPower, specularPower * 255.0f);

	float4 A = 0.0f;
	float4 D = 0.0f;
	float4 S = 0.0f;

	float3 toCamera = normalize(-positionView);

	ComputePointLight(material, m_pointLights[p_input.lightIndex.x], positionView, normal.xyz, toCamera, A, D, S);

	float4 light;
	light.xyz = albedo.xyz * ((A.xyz + D.xyz) + S.xyz) * ssao;
	light.w = D.w;

	return light;
}