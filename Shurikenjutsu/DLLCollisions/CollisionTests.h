#ifdef COLLISIONSDLL_EXPORTS
#define COLLISIONSDLL_API_desclspec(dllexport)
#else
#define COLLISIONSDLL_API_desclspec(dllimport)
#endif	

class CollisionTests
{
public:
	static void function1();
};

