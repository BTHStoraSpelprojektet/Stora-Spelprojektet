#include "Debug.h"

void Debug::RunTests(int p_argc, _TCHAR* p_argv[])
{
	::testing::InitGoogleTest(&p_argc, p_argv);

	RUN_ALL_TESTS();

	std::cout << std::endl;
}

TEST(AlexTest1, sphere_vs_sphere_collision)
{
	EXPECT_EQ(true, Collisions::SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 16.0f, 0.0f, 5.0f)));
}

TEST(AlexTest2, box_vs_box_collision)
{
	EXPECT_EQ(true, Collisions::BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(11.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
}

TEST(AlexTest3, frustrum_vs_box_collision)
{
	EXPECT_EQ(true, Collisions::FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 12.0f, 5.0f, 5.0f, 5.0f)));
}

TEST(AlexTest4, frustrum_vs_sphere_collision)
{
	EXPECT_EQ(true, Collisions::FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, 10.0f, 10.0f)));
	EXPECT_EQ(false, Collisions::FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, -10.0f, 10.0f)));
}

TEST(AlexTest5, ray_vs_box_collision)
{
	EXPECT_EQ(true, Collisions::RayBoxCollision(&Ray(0.0f, 0.0f, 0.0f, 8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::RayBoxCollision(&Ray(0.0f, 0.0f, 0.0f, -8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
}

TEST(AlexTest6, ray_vs_sphere_collision)
{
	EXPECT_EQ(true, Collisions::RaySphereCollision(&Ray(0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::RaySphereCollision(&Ray(0.0f, 0.0f, 0.0f, -10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)));
}

TEST(AlexTest7, ray_vs_OBB_collision)
{
	EXPECT_EQ(true, Collisions::RayOBBCollision(&Ray(0.0f, 0.0f, 0.0f, 8.0f, 0.0f, 0.0f), OBB(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f)));
	EXPECT_EQ(false, Collisions::RayOBBCollision(&Ray(0.0f, 0.0f, 0.0f, -8.0f, 0.0f, 0.0f), OBB(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f)));
	EXPECT_EQ(true, Collisions::OBBSphereCollision(OBB(8.0f, 1.0f, 1.0f, 5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 3.0f), Sphere(0.0f,0.0f,0.0f,5.0f)));
}

TEST(AlexTest8, OBB_vs_OBB_collision)
{
	EXPECT_EQ(true, Collisions::OBBOBBCollision(OBB(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f), OBB(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f)));
	EXPECT_EQ(false, Collisions::OBBOBBCollision(OBB(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f), OBB(11.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f)));
}