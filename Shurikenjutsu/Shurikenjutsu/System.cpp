#include "System.h"

bool System::Initiliaze()
{
    bool result = true;

    m_run = true;

    return result;
}

void System::Run()
{
    Update();
    Render();
}

void System::Update()
{
    // Update game logic.
}

void System::Render()
{
    // Render game scene.
}

bool System::KeepRunning()
{
    return m_run;
}