Texture2D m_texture : register (t0);
Texture2D m_shadowMap : register (t2);
SamplerState m_sampler: register (s0);

struct PixelInput
{
	float4 m_position : SV_POSITION;
	float2 m_uv : UVCOORD;
	float4 m_lightPositionHomogenous : LIGHTPOS;
};

float4 main(PixelInput p_input) : SV_TARGET
{
	float4 pixel = m_texture.Sample(m_sampler, p_input.m_uv);

	clip(pixel.a - 0.50f);

	float shadowSum = 0.0f;

	float2 shadowMapCoordinates;
	shadowMapCoordinates.x = p_input.m_lightPositionHomogenous.x / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;
	shadowMapCoordinates.y = -p_input.m_lightPositionHomogenous.y / p_input.m_lightPositionHomogenous.w / 2.0f + 0.5f;

	if ((saturate(shadowMapCoordinates.x) == shadowMapCoordinates.x) && (saturate(shadowMapCoordinates.y) == shadowMapCoordinates.y))
	{
		// Sample the shadow map using PCF.
		float depth = m_shadowMap.Sample(m_sampler, shadowMapCoordinates).r;

		// Calculate the depth of the light.
		float lightDepth = p_input.m_lightPositionHomogenous.z - 0.0001f;

		// Compare the depth of the shadow map and the depth of the light.
		shadowSum += lightDepth < depth;
	}

	return float4(pixel.xyz * (0.4f + 0.6f * shadowSum), 1.0f);
}