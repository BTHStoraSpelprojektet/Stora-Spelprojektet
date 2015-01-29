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
	Vertex()
	{
		m_position = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
		m_textureCoordinates = DirectX::XMFLOAT2(0.0f, 0.0f);
		m_normal = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
		m_tangent = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	Vertex(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT2 p_textureCoordinates, DirectX::XMFLOAT3 p_normal, DirectX::XMFLOAT3 p_tangent)
	{
		m_position = p_position;
		m_textureCoordinates = p_textureCoordinates;
		m_normal = p_normal;
		m_tangent = p_tangent;
	}
};

struct VertexOutlining
{
	// Variables.
	DirectX::XMFLOAT3 m_position;

	// Constructors.
	VertexOutlining(DirectX::XMFLOAT3 p_position)
	{
		m_position = p_position;
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
		m_distance = 0;
	}
};

struct Box
{
	DirectX::XMFLOAT3 m_center;
	DirectX::XMFLOAT3 m_extents;
	float m_radius;

	Box(){}
	Box(DirectX::XMFLOAT3 p_center, DirectX::XMFLOAT3 p_extents)
	{
		m_center = p_center;
		m_extents = p_extents;
		CalculateRadius();
	}
	Box(DirectX::XMFLOAT3 p_center, float p_xExtent, float p_yExtent, float p_zExtent)
	{
		m_center = p_center;

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);
		CalculateRadius();
	}
	Box(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_extents)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = p_extents;
		CalculateRadius();
	}
	Box(float p_xPos, float p_yPos, float p_zPos, float p_xExtent, float p_yExtent, float p_zExtent)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);
		CalculateRadius();
	}
	void CalculateRadius()
	{
		float max1 = std::fmaxf(m_extents.x, m_extents.y);
		float max2 = std::fmaxf(max1, m_extents.z);
		m_radius = std::sqrt(max2 * max2 + max2 * max2);
	}
};

struct OBB
{
	DirectX::XMFLOAT3 m_center;
	DirectX::XMFLOAT3 m_extents;
	DirectX::XMFLOAT4 m_direction;
	float m_radius;

	OBB(){}
	OBB(DirectX::XMFLOAT3 p_center, DirectX::XMFLOAT3 p_extents, DirectX::XMFLOAT4 p_direction)
	{
		m_center = p_center;
		m_extents = p_extents;
		m_direction = p_direction;
		CalculateRadius();
	}
	OBB(Box p_box)
	{
		m_center = p_box.m_center;
		m_extents = p_box.m_extents;
		m_direction = DirectX::XMFLOAT4(0.0f,0.0f,0.0f,1.0f);
		CalculateRadius();
	}
	OBB(DirectX::XMFLOAT3 p_center, float p_xExtent, float p_yExtent, float p_zExtent, DirectX::XMFLOAT4 p_direction)
	{
		m_center = p_center;

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = p_direction;
		CalculateRadius();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_extents, DirectX::XMFLOAT4 p_direction)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = p_extents;

		m_direction = p_direction;
		CalculateRadius();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, float p_xExtent, float p_yExtent, float p_zExtent, DirectX::XMFLOAT4 p_direction)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = p_direction;
		CalculateRadius();
	}
	OBB(DirectX::XMFLOAT3 p_center, float p_xExtent, float p_yExtent, float p_zExtent, float p_xDir, float p_yDir, float p_zDir)
	{
		m_center = p_center;

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
		CalculateRadius();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, DirectX::XMFLOAT3 p_extents, float p_xDir, float p_yDir, float p_zDir)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = p_extents;

		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
		CalculateRadius();
	}
	OBB(float p_xPos, float p_yPos, float p_zPos, float p_xExtent, float p_yExtent, float p_zExtent, float p_xDir, float p_yDir, float p_zDir)
	{
		m_center = DirectX::XMFLOAT3(p_xPos, p_yPos, p_zPos);

		m_extents = DirectX::XMFLOAT3(p_xExtent, p_yExtent, p_zExtent);

		m_direction = DirectX::XMFLOAT4(p_xDir, p_yDir, p_zDir, 0.0f);
		CalculateRadius();
	}
	void CalculateRadius()
	{
		float max1 = std::fmaxf(m_extents.x, m_extents.y);
		float max2 = std::fmaxf(max1, m_extents.z);
		m_radius = std::sqrt(max2 * max2 + max2 * max2);
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
	DirectX::XMFLOAT4X4 m_bindPoseTransform;
	DirectX::XMFLOAT4X4 m_geometricTransform;
};

struct AnimationStack
{
	char m_name[64];
	int m_endFrame;
	int m_jointCount;

	std::vector<BoneFrame*> m_root;
	std::vector<BindPose> m_bindPoses;
};

struct Point
{
	float x;
	float y;

	Point()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Point(float p_x, float p_y)
	{
		x = p_x;
		y = p_y;
	}
};

struct Line
{
	Point a;
	Point b;

	Line()
	{
	}

	Line(float ax, float ay, float bx, float by)
	{
		a = Point(ax, ay);
		b = Point(bx, by);
	}

	Line(Point p_a, Point p_b)
	{
		a = p_a;
		b = p_b;
	}
};

#endif