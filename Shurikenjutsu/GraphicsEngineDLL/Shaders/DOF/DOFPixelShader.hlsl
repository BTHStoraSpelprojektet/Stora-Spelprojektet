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

Texture2D m_textures[3] : register(t3);

SamplerState m_sampler : register(s1);

struct Input
{
	float4 m_position  : SV_POSITION;
};

float main(Input p_input) : SV_Target
{
	float2 textureDimensions;
	m_textures[0].GetDimensions(textureDimensions.x, textureDimensions.y);
	float2 texOffset = float2(1.0f / textureDimensions.x, 0.0f);

		float2 load;
	load.x = p_input.m_position.x / textureDimensions.x;
	load.y = p_input.m_position.y / textureDimensions.y;

	float color = 0;
	float totalWeight = 0;

	float depth = m_textures[1].Sample(m_sampler, load * 2).x;

	//float3 normal = m_textures[2].Sample(m_sampler, load).xyz;
	//normal = (normal * 2.0f) - 1.0f;

	for (float i = -m_blurRadius; i <= m_blurRadius; ++i)
	{
		float2 tex = load + i*texOffset;

			float c = m_textures[0].Sample(m_sampler, tex).x;
		float neighborDepth = m_textures[1].Sample(m_sampler, tex * 2).x;
		//float3 neighborNormal = m_textures[2].Sample(m_sampler, tex).xyz;
		//neighborNormal = (neighborNormal * 2.0f) - 1.0f;

		//if (dot(neighborNormal, normal) >= 0.8f && abs(neighborDepth - depth) <= 0.2f)

		float ddiff = neighborDepth - depth;
		float w = exp(-i*i*m_falloff - ddiff*ddiff*100.0f);

		color += w*c;

		totalWeight += w;
	}


	return color / totalWeight;
}


