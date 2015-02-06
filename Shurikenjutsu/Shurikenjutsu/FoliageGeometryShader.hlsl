cbuffer MatrixBuffer : register(b0)
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;
};

struct GeometryInput
{
	float3 m_position : POSITION;
	float2 m_uv : TEXCOORD0;
	float2 m_foliageUv : TEXCOORD1;
};

struct GeometryOutput
{
	float4 m_position : SV_POSITION;
	float2 m_UV : SIZE;
	float2 m_color : COLOR;
};

[maxvertexcount(3)]
void main(point GeometryInput p_input[1], inout TriangleStream<GeometryOutput> p_output)
{
	GeometryOutput element;
	element.m_position = float4(p_input[0].m_position, 1.0f);
	element.m_UV = float2(0.0f, 0.0f);
	element.m_color = float2(0.0f, 0.0f);
	p_output.Append(element);
}