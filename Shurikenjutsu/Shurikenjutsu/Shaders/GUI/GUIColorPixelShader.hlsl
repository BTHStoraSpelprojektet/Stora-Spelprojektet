cbuffer Color : register(b2)
{
	float4 m_color;
};

struct Input
{
	float4 m_position: SV_POSITION;
};

float4 main(Input p_input) : SV_Target
{
	return m_color;
}