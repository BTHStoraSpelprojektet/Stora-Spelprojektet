Texture2D m_texture;

SamplerState m_sampler;

// Vertex structure.
struct Input
{
	float4 m_positionHomogenous : SV_POSITION;
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
	float3 m_normal : NORMAL;

	float m_fogFactor : FOG;
};

// Pixel shader function.
float4 main(Input p_input) : SV_Target
{
	// Set fog color.
	float4 fogColor = float4(0.5f, 0.5f, 0.5f, 1.0f);

	// Sample texture using texture coordinates.
	float4 textureColor = m_texture.Sample(m_sampler, p_input.m_textureCoordinate);
	float4 coloredPixel = p_input.m_fogFactor * textureColor + (1.0f - p_input.m_fogFactor) * fogColor;

	// Return shaded pixel.
	return textureColor;
}