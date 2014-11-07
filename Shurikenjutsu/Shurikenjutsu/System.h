#ifndef SYSTEM
#define SYSTEM

class System
{
public:
    bool Initiliaze();
    void Run();

    bool KeepRunning();

private:
    bool m_run;

    void Update();
    void Render();
};
#endif