struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 color : COLOR;
};

float4 main( PS_INPUT input) : SV_TARGET
{
	return input.color;
}