// UnitTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include\gtest\gtest.h"
#include "..\Shurikenjutsu\Collisions.h"

//bool Collisions::SphereSphereCollision(Sphere a, Sphere s);
//bool Collisions::SphereSphereCollision(Sphere p_sphere1, Sphere p_sphere2);


Collisions c;
TEST(testing, temp)
{
	//bool t = c->SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 0.0f), Sphere(0.0f, 0.0f, 0.0f, 0.0f));
	//Collisions::SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f));
	//c.SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f));
	bool temp = c.SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f));
  	EXPECT_EQ(true,temp);

}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	std::system("pause");

	return 0;
}

