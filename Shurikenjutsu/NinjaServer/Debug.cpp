#include "Debug.h"


Debug::Debug()
{
}


Debug::~Debug()
{
}

void Debug::RunTests(int p_argc, _TCHAR* p_argv[])
{
	::testing::InitGoogleTest(&p_argc, p_argv);

	RUN_ALL_TESTS();

	std::cout << std::endl;
}

TEST(JohanTest1, asdas)
{
}