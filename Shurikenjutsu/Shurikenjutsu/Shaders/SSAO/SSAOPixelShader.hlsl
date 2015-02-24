cbuffer cbPerFrame : register(b4)
{
	matrix m_projectionMatrix;
	matrix m_T;
	float4 gOffsetVectors[14];
};

Texture2D m_textures[3] : register(t3);

SamplerState samDepth : register(s0);
SamplerState samRandom : register(s1);

struct Input
{
	float4 m_position : SV_POSITION;
};

float3 ComputePositionViewFromZ(float2 positionScreen, float viewSpaceZ)
{
	float2 screenSpaceRay = float2(positionScreen.x / m_projectionMatrix._11, positionScreen.y / m_projectionMatrix._22);

	float3 positionView;
	positionView.z = viewSpaceZ;
	positionView.xy = screenSpaceRay.xy * positionView.z;

	return positionView;
}

float OcclusionFunction(float distz)
{
	float gOcclusionFadeStart = 0.2f;
	float gOcclusionFadeEnd = 2.0f;
	float gSurfaceEpsilon = 0.05f;

	float occlusion = 0.0f;
	if (distz > gSurfaceEpsilon)
	{
		float fadeLength = gOcclusionFadeEnd - gOcclusionFadeStart;
		occlusion = saturate((gOcclusionFadeEnd - distz) / fadeLength);
	}
	return occlusion;
}

float main(Input p_input) : SV_TARGET
{
	float gOcclusionRadius = 0.5f;

	int gSampleCount = 14;
	float2 normPos = p_input.m_position.xy / 256;
	uint3 load = uint3(p_input.m_position.xy, 0);

	float3 normal = m_textures[0].Load(load*2).xyz;
	normal = (normal * 2.0f) - 1.0f;

	float zBuffer = m_textures[1].Load(load*2).x;

	float3 randVec = 2.0f * m_textures[2].Sample(samRandom, 4.0f * normPos).xyz - 1.0f;
	//randVec = normalize(randVec);

	float2 textureDimensions;
	m_textures[0].GetDimensions(textureDimensions.x, textureDimensions.y);

	float2 screenPixelOffset = float2(2.0f, -2.0f) / textureDimensions; //
	float2 positionScreen = (float2(p_input.m_position.xy) + 0.5f) * screenPixelOffset.xy + float2(-1.0f, 1.0f);  //

	float viewSpaceZ = m_projectionMatrix._43 / (zBuffer - m_projectionMatrix._33);
	float3 p = ComputePositionViewFromZ(positionScreen, viewSpaceZ);

	float occlusionSum = 0.0f;
	for (int i = 0; i < gSampleCount; i++)
	{
		float3 offset = reflect(gOffsetVectors[i].xyz, randVec);
		float flip = sign(dot(offset, normal));
		float3 q = p + flip * gOcclusionRadius * offset;
		float4 projQ = mul(float4(q, 1.0f), m_T);
		projQ /= projQ.w;
		float rz = m_textures[1].Sample(samDepth, projQ.xy*2).x;
		rz = m_projectionMatrix._43 / (rz - m_projectionMatrix._33);
		float3 r = (rz / q.z)*q;
		float distZ = p.z - r.z;
		float dp = max(dot(normal, normalize(r - p)), 0.0f);
		float occlusion = dp * OcclusionFunction(distZ);
		occlusionSum += occlusion;
	}

	occlusionSum /= gSampleCount;
	float access = 1.0f - occlusionSum;
	float ssao = saturate(pow(access, 2.0f));

	return ssao;
}