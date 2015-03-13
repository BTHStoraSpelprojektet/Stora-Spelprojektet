Texture2D m_shadowMap : register(t0);
Texture2D m_texture : register(t1);

SamplerState m_sampler : register(s);

// Vertex structure.
struct Input
{
	float4 m_positionHomogenous : SV_POSITION;
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;

	float3x3 m_tBN : TBN;
	float4 m_lightPositionHomogenous : TEXCOORD1;
};

// Pixel shader function.
float4 main(Input p_input) : SV_Target
{
	float shadowSum = 0.0f;

	// Sample texture.
	float4 textureColor = m_texture.Sample(m_sampler, p_input.m_textureCoordinate);

	// Calculate projected shadow map coordinates.
	float2 shadowMapCoordinates;
	shadowMapCoordinates.x = p_input.m_lightPositionHomogenous.x / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;
	shadowMapCoordinates.y = -p_input.m_lightPositionHomogenous.y / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;

	// Calculate if the coordinates are in the range 0 to 1. If they are then the pixel is lit.
	if ((saturate(shadowMapCoordinates.x) == shadowMapCoordinates.x) && (saturate(shadowMapCoordinates.y) == shadowMapCoordinates.y))
	{
		// Sample the shadow map using PCF.
		float depth[17];
		depth[0] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates).r;
		depth[1] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(0.0f, 1.0f / 1152.0f)).r;
		depth[2] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(1.0f / 2048.0f, 1.0f / 1152.0f)).r;
		depth[3] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(1.0f / 2048.0f, 0.0f)).r;
		depth[4] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(1.0f / 2048.0f, -1.0f / 1152.0f)).r;
		depth[5] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(0.0f, -1.0f / 1152.0f)).r;
		depth[6] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(-1.0f / 2048.0f, -1.0f / 1152.0f)).r;
		depth[7] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(-1.0f / 2048.0f, 0.0f)).r;
		depth[8] = m_shadowMap.Sample(m_sampler, shadowMapCoordinates + float2(-1.0f / 2048.0f, 1.0f / 1152.0f)).r;
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

	// Return shaded pixel.
	return float4(textureColor.x, textureColor.y, textureColor.z, 0.8f - shadowSum);
}