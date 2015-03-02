struct PointLight
{
	float4 m_ambient;
	float4 m_diffuse;
	float4 m_specular;

	float3 m_position;
	float m_range;
};

struct DirectionalLight
{
	float4 m_ambient;
	float4 m_diffuse;
	float4 m_specular;
	float4 m_direction;
	float4 m_cameraPosition;
};

cbuffer FrameBuffer : register(b7)
{
	DirectionalLight m_directionalLight;
	matrix m_projectionMatrix;
};

StructuredBuffer<PointLight> m_pointLights : register(t7);

void UpdateClipRegionRoot(float nc,          
	float lc, 
	float lz,   
	float lightRadius,
	float cameraScale,
	inout float clipMin,
	inout float clipMax)
{
	float nz = (lightRadius - nc * lc) / lz;
	float pz = (lc * lc + lz * lz - lightRadius * lightRadius) /
		(lz - (nz / nc) * lc);

	[flatten] if (pz > 0.0f) 
	{
		float c = -nz * cameraScale / nc;
		[flatten] if (nc > 0.0f) 
		{
			clipMin = max(clipMin, c);
		}
		else 
		{                          
			clipMax = min(clipMax, c);
		}
	}
}

void UpdateClipRegion(float lc,    
	float lz,          
	float lightRadius,
	float cameraScale,
	inout float clipMin,
	inout float clipMax)
{
	float rSq = lightRadius * lightRadius;
	float lcSqPluslzSq = lc * lc + lz * lz;
	float d = rSq * lc * lc - lcSqPluslzSq * (rSq - lz * lz);

	if (d > 0) {
		float a = lightRadius * lc;
		float b = sqrt(d);
		float nx0 = (a + b) / lcSqPluslzSq;
		float nx1 = (a - b) / lcSqPluslzSq;

		UpdateClipRegionRoot(nx0, lc, lz, lightRadius, cameraScale, clipMin, clipMax);
		UpdateClipRegionRoot(nx1, lc, lz, lightRadius, cameraScale, clipMin, clipMax);
	}
}

float4 ComputeClipRegion(float3 lightPosView, float lightRadius)
{
	float4 clipRegion = float4(1, 1, 0, 0);

	float2 clipMin = float2(-1.0f, -1.0f);
	float2 clipMax = float2(1.0f, 1.0f);

	UpdateClipRegion(lightPosView.x, lightPosView.z, lightRadius, m_projectionMatrix._11, clipMin.x, clipMax.x);
	UpdateClipRegion(lightPosView.y, lightPosView.z, lightRadius, m_projectionMatrix._22, clipMin.y, clipMax.y);

	clipRegion = float4(clipMin, clipMax);

	return clipRegion;
}

struct GSInput
{
	float4 coords : coords;
	float quadZ : quadZ;
	uint lightIndex : lightIndex;
};

GSInput main(uint lightIndex : SV_VertexID)
{
	GSInput output;
	output.lightIndex = lightIndex;

	PointLight light = m_pointLights[lightIndex];
	output.coords = ComputeClipRegion(light.m_position, light.m_range);

	float quadDepth = light.m_position.z - light.m_range;

	float4 quadClip = mul(float4(0.0f, 0.0f, quadDepth, 1.0f), m_projectionMatrix);
	output.quadZ = quadClip.z / quadClip.w;

	return output;
}

