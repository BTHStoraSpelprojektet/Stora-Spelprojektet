struct Input
{
	float4 m_position: SV_POSITION;
	float2 m_textureCoordinate :TEXCOORD;
	float m_opacity : OPACITY;
};

SamplerState m_sampler;
Texture2D m_texture;

float4 main(Input p_input) : SV_Target
{
	float4 pixel = m_texture.Sample(m_sampler, p_input.m_textureCoordinate);

	pixel.a *= p_input.m_opacity;

	return pixel;
}