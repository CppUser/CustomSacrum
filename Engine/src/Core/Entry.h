#pragma once

#ifdef SM_PLATFORM_WINDOWS

EngineCore* Create(int argc, char** argv);
static bool g_EngineRunning = true;

int main(int argc, char** argv)
{
    
    EngineCore* engine = Create(argc, argv);
    engine->Run();
    delete engine;
    
}
#endif