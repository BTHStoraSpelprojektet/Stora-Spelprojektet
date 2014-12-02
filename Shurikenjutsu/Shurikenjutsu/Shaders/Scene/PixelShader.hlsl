#include "LightCalculation.hlsli"

// "Every frame" buffer
cbuffer FrameBuffer
{
	DirectionalLight m_directionalLight;
};

Texture2D m_texture : register(t0);
Texture2D m_normalMap  : register(t1);
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
	float4 m_cameraPosition : CAMERA;

	float4 m_lightPositionHomogenous : TEXCOORD1;
};

// Pixel shader function.
float4 main(Input p_input) : SV_Target
{
	// Set fog color.
	float4 fogColor = float4(0.5f, 0.5f, 0.5f, 1.0f);

	// Calculate light
	Material material;
	material.m_ambient = float4(1.0f, 1.0f, 1.0f, 1.0f);
	material.m_diffuse = float4(1.0f, 1.0f, 1.0f, 1.0f);
	material.m_specular = float4(1.0f, 1.0f, 1.0f, 1.0f);

	float4 A = m_directionalLight.m_ambient;
	float4 D = 0.0f;
	float4 S = 0.0f;

	// Calculate projected shadow map coordinates.
	float2 shadowMapCoordinates;
	shadowMapCoordinates.x = p_input.m_lightPositionHomogenous.x / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;
	shadowMapCoordinates.y = -p_input.m_lightPositionHomogenous.y / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;

	// Calculate if the coordinates are in the range 0 to 1. If they are then the pixel is lit.
	if ((saturate(shadowMapCoordinates.x) == shadowMapCoordinates.x) && (saturate(shadowMapCoordinates.y) == shadowMapCoordinates.y))
	{
		// Sample the shadow map at the projected shadow map coordinates.
		float depth = m_shadowMap.Sample(m_samplerShadowMap, shadowMapCoordinates).r;

		// Calculate the depth of the light.
		float lightDepth = p_input.m_lightPositionHomogenous.z / p_input.m_lightPositionHomogenous.w;

		// Subtract the bias from the depth value of the light.
		lightDepth = lightDepth - 0.001f;

		// Compare the depth of the shadow map and the depth of the light to determine whether to shadow or to light this pixel.
		if (lightDepth < depth)
		{
			// Sample NormalMap
			float3 normalMapSample = m_normalMap.Sample(m_sampler, p_input.m_textureCoordinate).rgb;
			// Uncompress NormalMap - to get it into the right range
			float3 normalT = 2.0f * normalMapSample - 1.0f;
			// Transforms from tangetspace to world space
			float3 bumpedNormalW = mul(normalT, p_input.m_tBN);
			//end of normalmap stuff

			// Normalize normals.
			float3 normal = normalize(bumpedNormalW);

			// Calculate the vector to the camera.
			float3 toCamera = normalize(p_input.m_cameraPosition.xyz - p_input.m_positionWorld.xyz);

			// Compute directional light
			ComputeDirectionalLight(material, m_directionalLight, normal, toCamera, A, D, S);
		}
	}

	// If the point is "behind" the shadow map, light it normally.
	else
	{
		// Sample NormalMap
		float3 normalMapSample = m_normalMap.Sample(m_sampler, p_input.m_textureCoordinate).rgb;
		// Uncompress NormalMap - to get it into the right range
		float3 normalT = 2.0f * normalMapSample - 1.0f;
		// Transforms from tangetspace to world space
		float3 bumpedNormalW = mul(normalT, p_input.m_tBN);
		//end of normalmap stuff

		// Normalize normals.
		float3 normal = normalize(bumpedNormalW);

		// Calculate the vector to the camera.
		float3 toCamera = normalize(p_input.m_cameraPosition.xyz - p_input.m_positionWorld.xyz);

		// Compute directional light
		ComputeDirectionalLight(material, m_directionalLight, normal, toCamera, A, D, S);
	}

	// Sample texture using texture coordinates.
	float4 textureColor = m_texture.Sample(m_sampler, p_input.m_textureCoordinate);
	
	// Add light.
	textureColor.xyz = textureColor.xyz*((A.xyz + D.xyz) + S.xyz);
	
	// Add fog.
	float4 coloredPixel = p_input.m_fogFactor * textureColor + (1.0f - p_input.m_fogFactor) * fogColor;

	// Return shaded pixel.
	return coloredPixel;
}