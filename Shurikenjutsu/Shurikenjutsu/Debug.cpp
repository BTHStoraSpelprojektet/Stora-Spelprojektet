#include "Debug.h"

void Debug::RunTests(int p_argc, _TCHAR* p_argv[])
{
	::testing::InitGoogleTest(&p_argc, p_argv);

	RUN_ALL_TESTS();
}
TEST(case1, sphere_vs_sphere_collision)
{
	EXPECT_EQ(true, Collisions::SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 16.0f, 0.0f, 5.0f)));
}
TEST(case2, box_vs_box_collision)
{
	EXPECT_EQ(true, Collisions::BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(11.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
}
TEST(case3, sphere_vs_sphere_collision)
{
	EXPECT_EQ(true, Collisions::FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 12.0f, 5.0f, 5.0f, 5.0f)));
}
TEST(case4, box_vs_box_collision)
{
	EXPECT_EQ(true, Collisions::FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, 10.0f, 10.0f)));
	EXPECT_EQ(false, Collisions::FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, -10.0f, 10.0f)));
}
TEST(case5, sphere_vs_sphere_collision)
{
	EXPECT_EQ(true, Collisions::RayBoxCollision(&Ray(0.0f, 0.0f, 0.0f, 8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::RayBoxCollision(&Ray(0.0f, 0.0f, 0.0f, -8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)));
}
TEST(case6, box_vs_box_collision)
{
	EXPECT_EQ(true, Collisions::RaySphereCollision(&Ray(0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)));
	EXPECT_EQ(false, Collisions::RaySphereCollision(&Ray(0.0f, 0.0f, 0.0f, -10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)));
}