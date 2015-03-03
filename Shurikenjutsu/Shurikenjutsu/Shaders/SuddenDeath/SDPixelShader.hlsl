Texture2D m_texture : register (t0);
SamplerState m_sampler: register (s0);

struct Input
{
	float4 m_position : SV_POSITION;
	float2 m_UV : UV;
	float m_opacity : OPACITY;
};

float4 main(Input p_input) : SV_TARGET
{
	// Sample texture.
	float4 color = (m_texture.Sample(m_sampler, p_input.m_UV));

	// Apply opacity.
	color.a * p_input.m_opacity;

	return color;
}