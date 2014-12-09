#ifndef STRUCTURES
#define STRUCTURES

#include <DirectXMath.h>

struct WindowRectangle
{
	// Variables.
	long x;
	long y;
	long width;
	long height;

	// Constructors.
	WindowRectangle()
	{
		x = 0;
		y = 0;
		width = 0;
		height = 0;
	}

	WindowRectangle(long p_x, long p_y, long p_width, long p_height)
	{
		x = p_x;
		y = p_y;

		width = p_width;
		height = p_height;
	}
};

struct Vertex
{
	// Variables.
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT2 m_textureCoordinates;
	DirectX::XMFLOAT3 m_normal;
	DirectX::XMFLOAT3 m_tangent;

	// Constructors.
	Vertex(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT2 p_textureCoordinates, DirectX::XMFLOAT3 p_normal, DirectX::XMFLOAT3 p_tangent)
	{
		m_position = p_position;
		m_textureCoordinates = p_textureCoordinates;
		m_normal = p_normal;
		m_tangent = p_tangent;
	}
};

struct VertexAnimated
{
	// Variables.
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT2 m_textureCoordinates;
	DirectX::XMFLOAT3 m_normal;
	DirectX::XMFLOAT3 m_tangent;
	DirectX::XMFLOAT3 m_weight;
	unsigned char m_boneIndex[3];

	// Constructors.
	VertexAnimated(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT2 p_textureCoordinates, DirectX::XMFLOAT3 p_normal, DirectX::XMFLOAT3 p_tangent, DirectX::XMFLOAT3 p_weight, unsigned char p_boneIndexX, unsigned char p_boneIndexY, unsigned char p_boneIndexZ)
	{
		m_position = p_position;
		m_textureCoordinates = p_textureCoordinates;
		m_normal = p_normal;
		m_tangent = p_tangent;
		m_weight = p_weight;
		m_boneIndex[0] = p_boneIndexX;
		m_boneIndex[0] = p_boneIndexY;
		m_boneIndex[0] = p_boneIndexZ;
	}
};

struct Sphere
{
	DirectX::XMFLOAT3 m_position;
	float m_radius;

	Sphere(){}
	Sphere(DirectX::XMFLOAT3 p_position, float p_radius)
	{
		m_position = p_position;
		m_radius = p_radius;
	}
	Sphere(float p_xPos, float p_yPos, float p_zPos, float p_radius)
	{
		m_position = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);
		m_radius = p_radius;
	}
};

struct Ray
{
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT4 m_direction;
	float m_distance;

	Ray(){}
	Ray(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction)
	{
		m_position = p_position;

		SetDirection(p_direction.x, p_direction.y, p_direction.z);
	}
	Ray(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_direction)
	{
		m_position = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		SetDirection(p_direction.x, p_direction.y, p_direction.z);
	}
	Ray(DirectX::XMFLOAT3 p_position, float p_xDir, float p_yDir, float p_zDir)
	{
		m_position = p_position;

		SetDirection(p_xDir, p_yDir, p_zDir);
	}
	Ray(float p_xPos, float p_yPos, float p_zPos, float p_xDir, float p_yDir, float p_zDir)
	{
		m_position = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		SetDirection(p_xDir, p_yDir, p_zDir);
	}
	void SetDirection(float p_xDir, float p_yDir, float p_zDir)
	{
		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
	}
};

struct Box
{
	DirectX::XMFLOAT3 m_center;
	DirectX::XMFLOAT3 m_extents;

	Box(){}
	Box(DirectX::XMFLOAT3 p_center, DirectX::XMFLOAT3 p_extents)
	{
		m_center = p_center;
		m_extents = p_extents;
	}
	Box(DirectX::XMFLOAT3 p_center, float p_xExtent, float p_yExtent, float p_zExtent)
	{
		m_center = p_center;

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);
	}
	Box(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_extents)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = p_extents;
	}
	Box(float p_xPos, float p_yPos, float p_zPos, float p_xExtent, float p_yExtent, float p_zExtent)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);
	}
};

struct OBB
{
	DirectX::XMFLOAT3 m_center;
	DirectX::XMFLOAT3 m_extents;
	DirectX::XMFLOAT4 m_direction;

	OBB(){}
	OBB(DirectX::XMFLOAT3 p_center, DirectX::XMFLOAT3 p_extents, DirectX::XMFLOAT4 p_direction)
	{
		m_center = p_center;
		m_extents = p_extents;
		m_direction = p_direction;
		//NormalizeDirction();
	}
	OBB(DirectX::XMFLOAT3 p_center, float p_xExtent, float p_yExtent, float p_zExtent, DirectX::XMFLOAT4 p_direction)
	{
		m_center = p_center;

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = p_direction;
		//NormalizeDirction();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_extents, DirectX::XMFLOAT4 p_direction)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = p_extents;

		m_direction = p_direction;
		//NormalizeDirction();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, float p_xExtent, float p_yExtent, float p_zExtent, DirectX::XMFLOAT4 p_direction)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = p_direction;
		//NormalizeDirction();
	}
	OBB(DirectX::XMFLOAT3 p_center, float p_xExtent, float p_yExtent, float p_zExtent, float p_xDir, float p_yDir, float p_zDir)
	{
		m_center = p_center;

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
		//NormalizeDirction();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_extents, float p_xDir, float p_yDir, float p_zDir)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = p_extents;

		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
		//NormalizeDirction();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, float p_xExtent, float p_yExtent, float p_zExtent, float p_xDir, float p_yDir, float p_zDir)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f); 
		//NormalizeDirction();
	}
	void NormalizeDirction()
	{
		float x = m_direction.x;
		float y = m_direction.y;
		float z = m_direction.z;
		float w = m_direction.w;
		float l = sqrt(x*x + y*y + z*z + w*w);
		m_direction = DirectX::XMFLOAT4(x/l, y/l, z/l, w/l);
	}
};

//struct Frustum
//{
//	DirectX::XMFLOAT3 m_position;
//	DirectX::XMFLOAT4 m_direction;
//	float m_leftAngle;
//	float m_rightAngle;
//	float m_topAngle;
//	float m_bottomAngle;
//	float m_nearDistance;
//	float m_farDistance;
//
//	Frustum(){}
//	Frustum(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction, float p_leftAngle, float p_rightAngle, float p_topAngle, float p_bottomAngle, float p_nearDist, float p_farDist)
//	{
//		m_position = p_position;
//		m_direction = DirectX::XMFLOAT4(p_direction.x, p_direction.y, p_direction.z, 0.0f);
//		SetAngles(p_leftAngle, p_rightAngle, p_topAngle, p_bottomAngle, p_nearDist, p_farDist);
//	}
//	Frustum(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4 p_direction, float p_leftAngle, float p_rightAngle, float p_topAngle, float p_bottomAngle, float p_nearDist, float p_farDist)
//	{
//		m_position = p_position;
//		m_direction = p_direction;
//		SetAngles(p_leftAngle, p_rightAngle, p_topAngle, p_bottomAngle, p_nearDist, p_farDist);
//	}
//	Frustum(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_direction, float p_leftAngle, float p_rightAngle, float p_topAngle, float p_bottomAngle, float p_nearDist, float p_farDist)
//	{
//		m_position = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);
//		m_direction = DirectX::XMFLOAT4(p_direction.x, p_direction.y, p_direction.z, 0.0f);
//		SetAngles(p_leftAngle, p_rightAngle, p_topAngle, p_bottomAngle, p_nearDist, p_farDist);
//	}
//	Frustum(DirectX::XMFLOAT3 p_position, float p_xDir, float p_yDir, float p_zDir, float p_leftAngle, float p_rightAngle, float p_topAngle, float p_bottomAngle, float p_nearDist, float p_farDist)
//	{
//		m_position = p_position;
//		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
//		SetAngles(p_leftAngle, p_rightAngle, p_topAngle, p_bottomAngle, p_nearDist, p_farDist);
//	}
//	Frustum(float p_xPos, float p_yPos, float p_zPos, float p_xDir, float p_yDir, float p_zDir, float p_leftAngle, float p_rightAngle, float p_topAngle, float p_bottomAngle, float p_nearDist, float p_farDist)
//	{
//		m_position = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);
//		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
//		SetAngles(p_leftAngle, p_rightAngle, p_topAngle, p_bottomAngle, p_nearDist, p_farDist);
//	}
//	void SetAngles(float p_leftAngle, float p_rightAngle, float p_topAngle, float p_bottomAngle, float p_nearDist, float p_farDist)
//	{
//		m_leftAngle = p_leftAngle;
//		m_rightAngle = p_rightAngle;
//		m_topAngle = p_topAngle;
//		m_bottomAngle = p_bottomAngle;
//		m_nearDistance = p_nearDist;
//		m_farDistance = p_farDist;
//	}
//};

struct DirectionalLight
{
	DirectX::XMVECTOR m_ambient;
	DirectX::XMVECTOR m_diffuse;
	DirectX::XMVECTOR m_specular;
	DirectX::XMVECTOR m_direction;
};

struct FrustumForCulling
{
	DirectX::XMFLOAT3 m_origin;
	DirectX::XMFLOAT4 m_orientation;

	float m_rightSlope;
	float m_leftSlope;
	float m_topSlope;
	float m_bottomSlope;
	float m_near, m_far; 
};

#endif