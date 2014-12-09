#include "System.h"

int main(int p_argc, _TCHAR* p_argv[])
{
	System system;

	
	system.Initialize(p_argc, p_argv);

	system.Run();

	return 0;
}