#ifndef COMMONSTRUCTURES_H_
#define COMMONSTRUCTURES_H_

#include <DirectXMath.h>
#include <vector>

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
		m_direction = DirectX::XMFLOAT4(x / l, y / l, z / l, w / l);
	}
};

struct BoneFrame
{
	char m_name[64];

	float m_translation[3];
	float m_quaternion[4];
	float m_orientQuaternion[4];
	float m_rotEuler[3];
	double m_scale[3];

	int m_childrenCount;
	std::vector<BoneFrame*> m_children;
};

struct BindPose
{
	DirectX::XMMATRIX m_bindPoseTransform;
	DirectX::XMMATRIX m_geometricTransform;
};

struct AnimationStack
{
	char m_name[64];
	int m_endFrame;
	int m_jointCount;

	std::vector<BoneFrame*> m_root;
	std::vector<BindPose> m_bindPoses;
};

#endif