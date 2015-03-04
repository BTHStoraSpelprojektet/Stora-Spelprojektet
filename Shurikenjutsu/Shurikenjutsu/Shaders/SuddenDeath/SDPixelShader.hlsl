Texture2D m_texture : register (t0);
SamplerState m_sampler: register (s0);

struct Input
{
	float4 m_position : SV_POSITION;
	float2 m_UV : UV;
	float4 m_color : COLOR;
};

float4 main(Input p_input) : SV_TARGET
{
	// Sample texture and apply opacity.
	float4 pixel = m_texture.Sample(m_sampler, p_input.m_UV) * p_input.m_color;

	return pixel;
}