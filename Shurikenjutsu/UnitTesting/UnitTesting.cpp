// UnitTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include\gtest\gtest.h"
#include "Collisions.h"



TEST(testing, temp)
{
	Collisions* temp = new Collisions();
	//bool temp = Collisions::SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f));
	EXPECT_EQ(true,true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	std::system("pause");

	return 0;
}

