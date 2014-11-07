#include "System.h"

int main()
{
    System system;

    system.Initiliaze();

    while (system.KeepRunning())
    {
        system.Run();
    }

    return 0;
}