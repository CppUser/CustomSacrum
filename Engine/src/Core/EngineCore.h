#pragma once

#include "Core/Window.h"

struct WindowSpecs
{
    std::string Title;
    uint32_t Width;
    uint32_t Height;
};

class EngineCore
{
public:
    EngineCore(const WindowSpecs& specs);
    virtual ~EngineCore();

    void Run();
    void Close();

    virtual void Init() {}
    virtual void Shutdown();

    inline Window& GetWindow() { return *m_Window; }
private:
    std::unique_ptr<Window> m_Window;
    WindowSpecs m_WinSpecs;
    bool m_isRunning = true;

    static EngineCore* s_Instance;
};

EngineCore* Create(int argc, char** argv);