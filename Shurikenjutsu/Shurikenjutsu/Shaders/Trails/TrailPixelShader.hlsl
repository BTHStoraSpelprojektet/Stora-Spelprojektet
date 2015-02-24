Texture2D m_texture : register (t0);
SamplerState m_sampler: register (s0);

struct PixelInput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : TEXCOORD0;
	float2 m_timeValues : TIMES;
	float4 m_color : COLOR;
};

float4 main(PixelInput p_input) : SV_TARGET
{
	// Sample texture, and blend in color.
	float4 pixel = (m_texture.Sample(m_sampler, p_input.m_UV)) * p_input.m_color;

	// Fade the trail by time lived.	
	pixel.w *= (p_input.m_timeValues.x - p_input.m_timeValues.y) / p_input.m_timeValues.x;

	return pixel;
}