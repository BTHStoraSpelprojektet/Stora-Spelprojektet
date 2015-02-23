struct TrailPoint
{
	float3 m_position : POSITION;
	float m_angle : ANGLE;
	float m_width : WIDTH;
	float2 m_timeValues : TIMES;
	float4 m_color : COLOR;
	float m_endpoint : BOOL;
};

TrailPoint main(TrailPoint p_input)
{
	return p_input;
}