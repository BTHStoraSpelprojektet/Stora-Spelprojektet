struct Input
{
	float4 m_position : SV_POSITION;
};

float4 main(Input p_input) : SV_TARGET
{
	return float4(0.0f, 0.0f, 0.0f, 0.5f);
}