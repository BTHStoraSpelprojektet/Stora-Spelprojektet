struct PointLight
{
	float4 m_ambient;
	float4 m_diffuse;
	float4 m_specular;

	float3 m_position;
	float m_range;

	float3 m_attenuation;
	float m_padding;
};

struct DirectionalLight
{
	float4 m_ambient;
	float4 m_diffuse;
	float4 m_specular;
	float4 m_direction;
	float m_padding;
};

struct Material
{
	float4 m_ambient;
	float4 m_diffuse;
	float4 m_specular;
};

void ComputePointLight(Material p_material, PointLight p_light, float3 p_position, float3 p_normal, float3 p_toEye, out float4 p_ambient, out float4 p_diffuse, out float4 p_specular)
{
	p_ambient = float4(0.0f, 0.0f, 0.0f, 0.0f);
	p_diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
	p_specular = float4(0.0f, 0.0f, 0.0f, 0.0f);

	float3 lightVec = p_light.m_position - p_position;

	float d = length(lightVec);

	if (d > p_light.m_range)
		return;

	lightVec /= d;

	p_ambient = p_material.m_ambient * p_light.m_ambient;

	float diffuseFactor = dot(lightVec, p_normal);

	if (diffuseFactor > 0.0f)
	{
		float3 v = reflect(-lightVec, p_normal);
		float specFactor = pow(max(dot(v, p_toEye), 0.0f), p_material.m_specular.w);

		p_diffuse = diffuseFactor * p_material.m_diffuse * p_light.m_diffuse;
		p_specular = specFactor * p_material.m_specular * p_light.m_specular;
	}

	float att = 1.0f / dot(p_light.m_attenuation, float3(1.0f, d, d*d));

	p_ambient *= att;
	p_diffuse *= att;
	p_specular *= att;
}

void ComputeDirectionalLight(Material p_material, DirectionalLight p_light, float3 p_normal, float3 p_toEye, out float4 p_ambient, out float4 p_diffuse, out float4 p_specular)
{
	p_ambient = float4(0.0f, 0.0f, 0.0f, 1.0f);
	p_diffuse = float4(0.0f, 0.0f, 0.0f, 1.0f);
	p_specular = float4(0.0f, 0.0f, 0.0f, 1.0f);

	p_ambient += p_material.m_ambient * p_light.m_ambient;

	float3 lightVec = -p_light.m_direction.xyz;

	float diffuseFactor = dot(lightVec, p_normal);

	[flatten]
	if (diffuseFactor > 0.0f)
	{
		float specPower = max(p_material.m_specular.a, 1.0f);

		float3 v = reflect(-lightVec, p_normal);

		float specFactor = pow(max(dot(v, p_toEye), 0.0f), specPower);

		p_diffuse += diffuseFactor * p_material.m_diffuse * p_light.m_diffuse;
		p_specular += specFactor * p_material.m_specular * p_light.m_specular;
	}
}