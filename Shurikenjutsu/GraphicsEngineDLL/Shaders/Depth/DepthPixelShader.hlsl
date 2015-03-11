Texture2D m_texture : register(t0);

SamplerState m_sampler : register(s0);

struct Input
{
	float4 m_position : SV_POSITION;
	float2 m_textureCoordinates : TEXCOORD0;
	float4 m_depthPosition : TEXCOORD1;
};

// Pixel depth shader function.
float main(Input p_input) : SV_TARGET
{
	float4 color = m_texture.Sample(m_sampler, p_input.m_textureCoordinates);

	clip(color.a - 0.15f);

	// Return depth value.
	return p_input.m_depthPosition.z;
}