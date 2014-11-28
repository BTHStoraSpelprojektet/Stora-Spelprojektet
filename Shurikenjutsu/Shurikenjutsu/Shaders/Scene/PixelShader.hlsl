#include "LightCalculation.hlsli"

// "Every frame" buffer
cbuffer FrameBuffer
{
	DirectionalLight m_directionalLight;
};

Texture2D m_texture;
Texture2D m_normalMap;

SamplerState m_sampler;

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

	// Sample NormalMap
	float3 normalMapSample = m_normalMap.Sample(m_sampler, p_input.m_textureCoordinate).rgb;
	// Uncompress NormalMap - to get it into the right range
	float3 normalT = 2.0f*normalMapSample - 1.0f;
	// Transforms from tangetspace to world space
	float3 bumpedNormalW = mul(normalT, p_input.m_tBN);
	//end of normalmap stuff

	float3 normal = normalize(p_input.m_normal);

	float3 toEye = normalize(p_input.m_cameraPosition.xyz - p_input.m_positionWorld.xyz);

	float4 A, D, S;

	ComputeDirectionalLight(material, m_directionalLight, bumpedNormalW, toEye, A, D, S);

	// Sample texture using texture coordinates.
	float4 textureColor = m_texture.Sample(m_sampler, p_input.m_textureCoordinate);

	// Add light
	textureColor.xyz = textureColor.xyz*((A.xyz + D.xyz) + S.xyz);
	
	// Add fog
	float4 coloredPixel = p_input.m_fogFactor * textureColor + (1.0f - p_input.m_fogFactor) * fogColor;

	// Return shaded pixel.
	return coloredPixel;
}