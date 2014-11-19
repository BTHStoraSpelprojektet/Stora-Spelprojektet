#include "Debug.h"


Debug::Debug()
{
}


Debug::~Debug()
{
}

void Debug::RunTests()
{
	CollisionTest1();
	CollisionTest2();
	CollisionTest3();
	CollisionTest4();
	CollisionTest5();
	CollisionTest6();
	CollisionTest7();
	CollisionTest8();
	CollisionTest9();
	CollisionTest10();
	CollisionTest11();
	CollisionTest12();
	CollisionTest13();
	CollisionTest14();
	CollisionTest15();
}
void Debug::CollisionTest1()
{
	if (m_collision.SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f)))
	{
		std::cout << "1. Sphere Sphere true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest2()
{
	if (!m_collision.SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 16.0f, 0.0f, 5.0f)))
	{
		std::cout << "2. Sphere Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest3()
{
	if (m_collision.BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "3. Box Box True" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest4()
{
	if (!m_collision.BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(11.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "4. Box Box false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest5()
{
	if (m_collision.SphereBoxCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Box(11.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "5. Sphere Box true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest6()
{
	if (!m_collision.SphereBoxCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Box(16.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "6. Sphere Box false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest7()
{
	if (m_collision.FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "7. Frustum Box true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest8()
{
	if (!m_collision.FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 12.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "8. Frustum Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest9()
{
	if (m_collision.FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, 10.0f, 10.0f)))
	{
		std::cout << "9. Frustum Sphere true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest10()
{
	if (!m_collision.FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, -10.0f, 10.0f)))
	{
		std::cout << "10. Frustum Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest11()
{
	if (m_collision.RayBoxCollision(Ray(0.0f, 0.0f, 0.0f, 8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "11. Ray Box true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest12()
{
	if (!m_collision.RayBoxCollision(Ray(0.0f, 0.0f, 0.0f, -8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "12. Ray Box false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest13()
{
	if (m_collision.RaySphereCollision(Ray(0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)))
	{
		std::cout << "13. Ray Sphere true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest14()
{
	if (!m_collision.RaySphereCollision(Ray(0.0f, 0.0f, 0.0f, -10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)))
	{
		std::cout << "14. Ray Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}
void Debug::CollisionTest15()
{
	if (m_collision.SphereSphereCollision(Sphere(0.0f, 5.0f, 0.0f, 5.0f), Sphere(0.0f, -6.0f, 0.0f, 5.0f)))
	{
		std::cout << "15. Sphere Sphere true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}