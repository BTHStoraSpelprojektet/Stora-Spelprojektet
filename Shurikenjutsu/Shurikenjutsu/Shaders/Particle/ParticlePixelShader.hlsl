Texture2D m_texture : register (t0);
SamplerState m_sampler: register (s0);

struct PixelInput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : TEXCOORD0;
	float4 m_color : COLOR;
};

float4 main(PixelInput p_input) : SV_TARGET
{
	// Combine the texture color and the particle color to get the final pixel.
	float4 pixel = (m_texture.Sample(m_sampler, p_input.m_UV)) * p_input.m_color;

	clip(pixel.a - 0.15f);

	return pixel;
}