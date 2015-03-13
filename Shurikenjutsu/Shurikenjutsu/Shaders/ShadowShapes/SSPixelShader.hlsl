struct Input
{
	float4 m_position : SV_POSITION;
};

float main(Input p_input) : SV_TARGET
{
	return 1.0f;
}