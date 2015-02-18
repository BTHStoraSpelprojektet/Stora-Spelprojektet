struct Output
{
	float4 pos : SV_POSITION;
};

Output main(float3 p_position : POSITION)
{
	Output o;
	o.pos = float4(p_position, 1.0f);
	return o;
}