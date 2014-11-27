// Matrix buffer.
cbuffer MatrixBuffer
{
	matrix m_worldMatrix;
	matrix m_viewMatrix;
	matrix m_projectionMatrix;

	matrix m_lightViewMatrix;
	matrix m_lightProjectionMatrix;
};

// Fog calculation buffer.
cbuffer FogBuffer
{
	float m_fogStart;
	float m_fogEnd;
	float m_fogDensity;
	float m_padding1;
};

cbuffer LightBuffer
{
	float4 m_lightPosition;
};

// Vertex input.
struct Input
{
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
	float3 m_normal : NORMAL;
	float3 m_tangent : TANGENT;
};

// Vertex output.
struct Output
{
	float4 m_positionHomogenous : SV_POSITION;
	float4 m_positionWorld : POSITION;
	float2 m_textureCoordinate : TEXCOORD0;
	float3 m_normal : NORMAL;
	float3 m_tangent : TANGENT;

	float m_fogFactor : FOG;
	float4 m_cameraPosition : CAMERA;

	float4 m_lightPositionHomogenous : TEXCOORD1;
	float3 m_lightPositionWorld : TEXCOORD2;
};

// Vertex shader
Output main(Input p_input)
{
	Output output;

	// Store vertex position in world space.
	output.m_positionWorld = p_input.m_positionWorld;
	output.m_positionWorld.w = 1.0f;
	output.m_positionWorld = mul(output.m_positionWorld, m_worldMatrix);

	output.m_lightPositionWorld = p_input.m_positionWorld.xyz;
	output.m_lightPositionHomogenous = p_input.m_positionWorld;
	output.m_lightPositionHomogenous.w = 1.0f;

	// Transform vertex position to homogenous clip space.
	output.m_positionHomogenous = p_input.m_positionWorld;
	output.m_positionHomogenous.w = 1.0f;
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_worldMatrix);
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_viewMatrix);
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_projectionMatrix);

	// Pass along the texture coordinates.
	output.m_textureCoordinate = p_input.m_textureCoordinate;

	// Transform  the normals.
	output.m_normal = p_input.m_normal;
	output.m_normal = mul(output.m_normal, (float3x3)m_worldMatrix);

	// Calculate the camera position.
	float4 cameraPosition;
	cameraPosition = mul(p_input.m_positionWorld, m_worldMatrix);
	cameraPosition = mul(cameraPosition, m_viewMatrix);
	output.m_cameraPosition = cameraPosition;

	// Pass on tangent.
	output.m_tangent = p_input.m_tangent;

	// Determine the light position based on the position of the light and the position of the vertex in the world.
	output.m_lightPositionWorld = m_lightPosition.xyz - output.m_positionWorld.xyz;

	// Normalize the light position vector.
	output.m_lightPositionWorld = normalize(output.m_lightPositionWorld);

	// Calculate the position of the vertice as viewed by the light source.
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_worldMatrix);
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_lightViewMatrix);
	output.m_positionHomogenous = mul(output.m_positionHomogenous, m_lightProjectionMatrix);

	// No fog.
	output.m_fogFactor = 1.0f;

	// Calculate linear fog.    
	//output.m_fogFactor = saturate((m_fogEnd - cameraPosition.z) / (m_fogEnd - m_fogStart));

	// Calculate exponential fog.    
	//output.m_fogFactor = saturate(1.0 / pow(2.71828, (cameraPosition.z * m_fogDensity)));

	// Calculate exponential 2 fog.    
	//output.m_fogFactor = saturate(1.0 / pow(2.71828, ((cameraPosition.z * m_fogDensity) * (cameraPosition.z * m_fogDensity))));

	// Return output.
	return output;
}