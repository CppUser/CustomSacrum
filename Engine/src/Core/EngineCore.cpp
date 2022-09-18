#include "pch.h"
#include "EngineCore.h"


EngineCore* EngineCore::s_Instance = nullptr;


EngineCore::EngineCore(const WindowSpecs& specs)
{
    s_Instance = this;
    WindowProps m_WinData;
    m_WinData.Title = specs.Title;
    m_WinData.Width = specs.Width;
    m_WinData.Height = specs.Height;
    m_Window = Window::Create(WindowProps(m_WinData));
    

}

EngineCore::~EngineCore()
{
    Shutdown();
}

void EngineCore::Run()
{
    Init();
    while (m_isRunning)
    {
        //m_Window->PollEvents();
        m_Window->OnUpdate();
    }
    Shutdown();
}

void EngineCore::Close()
{
    m_isRunning = false;
}

void EngineCore::Shutdown()
{
    Close();
  
}