struct PixelInput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : SIZE;
	float2 m_color : COLOR;
};

float4 main(PixelInput p_input) : SV_TARGET
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);
}