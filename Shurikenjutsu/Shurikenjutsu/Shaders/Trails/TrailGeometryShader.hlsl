cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

struct GeometryInput
{
	float3 m_position : POSITION;
	float m_angle : ANGLE;
	float2 m_width : WIDTH;
	float2 m_timeValues : TIMES;
	float4 m_color : COLOR;
};

struct GeometryOutput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : TEXCOORD0;
	float2 m_timeValues : TIMES;
	float4 m_color : COLOR;
};

[maxvertexcount(?)]
void main(point GeometryInput p_input[2], inout TriangleStream<GeometryOutput> p_output)
{
	// TODO, do stuff with things here lol.
}