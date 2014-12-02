struct Input
{
	float4 m_position : SV_POSITION;
	float4 m_color : COLOR;
};

float4 main(Input p_input) : SV_TARGET
{
	return float4(p_input.m_color.x, p_input.m_color.y, p_input.m_color.z, 1.0f);
}