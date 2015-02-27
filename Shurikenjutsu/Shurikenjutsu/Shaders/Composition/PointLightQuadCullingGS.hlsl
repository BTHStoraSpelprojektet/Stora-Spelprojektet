struct GSInput
{
	float4 coords : coords;
	float quadZ : quadZ;
	uint lightIndex : lightIndex;
};

struct Input
{
	float4 positionViewport : SV_Position;
	nointerpolation uint4 lightIndex : lightIndex;
};

[maxvertexcount(4)]
void main(point GSInput p_input[1], inout TriangleStream<Input> p_quadStream)
{
	Input output;
	output.lightIndex = p_input[0].lightIndex;
	output.positionViewport.zw = float2(p_input[0].quadZ, 1.0f);

	if (all(p_input[0].coords.xy < p_input[0].coords.zw))
	{
		output.positionViewport.xy = p_input[0].coords.xw;
		p_quadStream.Append(output);
		output.positionViewport.xy = p_input[0].coords.zw;
		p_quadStream.Append(output);
		output.positionViewport.xy = p_input[0].coords.xy;
		p_quadStream.Append(output);
		output.positionViewport.xy = p_input[0].coords.zy;
		p_quadStream.Append(output);
		p_quadStream.RestartStrip();
	}
}