#pragma once
#include "Core/Window.h"
#include <GLFW/glfw3.h>

class WinWindow : public Window
{
public:
    WinWindow(const WindowProps& props);
    virtual ~WinWindow();

    void OnUpdate() override;

    [[nodiscard]] unsigned int GetWidth() const override { return m_Data.Width; }
    [[nodiscard]] unsigned int GetHeight() const override { return m_Data.Height; }

    // Window attributes
   // void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
    void SetVSync(bool enabled) override;
    [[nodiscard]]  bool IsVSync() const override;

     virtual void* GetNativeWindow() const { return m_Window; }
private:
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();
private:
    GLFWwindow* m_Window;
    //Scope<GraphicsContext> m_Context;

    struct WindowData
    {
        std::string Title;
        unsigned int Width, Height;
        bool VSync;

        //EventCallbackFn EventCallback;
    };

    WindowData m_Data;
};

