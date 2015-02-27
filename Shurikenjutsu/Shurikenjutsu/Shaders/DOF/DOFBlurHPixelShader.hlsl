cbuffer cbSettings : register(b13)
{
	static const float m_weights[11] =
	{
		0.05f, 0.05f, 0.1f, 0.1f, 0.1f, 0.2f, 0.1f, 0.1f, 0.1f, 0.05f, 0.05f
	};

	static const int m_blurRadius = 5;

	static const float m_sigma = (m_blurRadius + 1) / 2;
	static const float m_falloff = 1.0f / (2 * m_sigma*m_sigma);

};

Texture2D m_textures[2] : register(t3);

SamplerState m_sampler : register(s1);

struct Input
{
	float4 m_position  : SV_POSITION;
};

float4 main(Input p_input) : SV_Target
{
	float2 textureDimensions;
	m_textures[0].GetDimensions(textureDimensions.x, textureDimensions.y);
	float2 texOffset = float2(1.0f / textureDimensions.x, 0.0f);

	float2 load;
	load.x = p_input.m_position.x / textureDimensions.x;
	load.y = p_input.m_position.y / textureDimensions.y;

	float totalWeight = 0.0;

	float4 color = float4(0, 0, 0, 0);
	float depth = m_textures[1].Sample(m_sampler, load).x;

	[unroll]
	for (int i = -m_blurRadius; i <= m_blurRadius; ++i)
	{
		float2 tex = load + i*texOffset;

		float4 c = m_textures[0].Sample(m_sampler, tex);

		float w = m_weights[m_blurRadius + i];

		color += w*c;

		totalWeight += w;
	}
	color /= totalWeight;

	float z_n = 2.0 * depth - 1.0;
	float z_e = 2.0 * 0.1f * 1000.0f / (1000.0f + 0.1f - z_n * (1000.0f - 0.1f));

	float asd = (p_input.m_position.y - textureDimensions.y*0.5f) / textureDimensions.y;
	
	float b = 16.0f - asd*16.0f*0.5f;
	float a = 26.0f - asd*b*0.5f;
	

	float x = 1 / (a - b);
	float y = a / (a - b);

	float coc = -1 * (z_e*x - y);

	color.a = saturate(coc);

	return color;
}