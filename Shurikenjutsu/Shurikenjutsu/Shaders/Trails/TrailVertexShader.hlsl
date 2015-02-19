struct TrailPoint
{
	float3 m_position : POSITION;
	float m_angle : ANGLE;
	float2 m_width : WIDTH;
	float2 m_timeValues : TIMES;
	float4 m_color : COLOR;
};

TrailPoint main(TrailPoint p_input)
{
	return p_input;
}