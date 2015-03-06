cbuffer cbSettings : register(b13)
{
	static const float m_weights[11] =
	{
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f
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
	float2 texOffset = float2(0.0f, 1.0f / textureDimensions.y);

	float2 load;
	load.x = p_input.m_position.x / textureDimensions.x;
	load.y = p_input.m_position.y / textureDimensions.y;

	float totalWeight = 0.0;

	float4 color = float4(0, 0, 0, 0);
	float a = m_textures[1].Sample(m_sampler, load).a;
	float4 comp = m_textures[0].Sample(m_sampler, load);

	[unroll]
	for (int i = -m_blurRadius; i <= m_blurRadius; ++i)
	{
		float2 tex = load + i*texOffset;

		float4 c = m_textures[1].Sample(m_sampler, tex);

		float w = m_weights[m_blurRadius + i];

		color += w*c;

		totalWeight += w;
	}
	color /= totalWeight;

	//return float4(a.xxx, 1.0f);
	//return float4(color.xyz, 1.0f);
	return float4(comp.xyz * (1.0f - a) + color.rgb*a, 1.0f);
}