#include "pch.h"
#include "WinWindow.h"

static uint8_t s_GLFWWindowCount = 0;

static void GLFWErrorCallback(int error, const char* description)
{
    //printf("GLFW Error ({0}): {1}", error, description);
}

WinWindow::WinWindow(const WindowProps& props)
{
    WinWindow::Init(props);
}

WinWindow::~WinWindow()
{
    WinWindow::Shutdown();
}

void WinWindow::Init(const WindowProps& props)
{
    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;

    if (s_GLFWWindowCount == 0)
    {
        //SM_PROFILE_SCOPE("glfwInit");
        int success = glfwInit();
        //SM_CORE_ASSERT(success, "Could not initialize GLFW!");
        glfwSetErrorCallback(GLFWErrorCallback);
    }

    {
        //SM_PROFILE_SCOPE("glfwCreateWindow");
#if defined(_DEBUG)
        //if (Renderer::GetAPI() == RendererAPI::API::OpenGL)
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
            
#endif
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        ++s_GLFWWindowCount;
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVSync(true);
}

void WinWindow::OnUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

void WinWindow::SetVSync(bool enabled)
{
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);

    m_Data.VSync = enabled;
}

bool WinWindow::IsVSync() const
{
    return m_Data.VSync;
}



void WinWindow::Shutdown()
{
    glfwDestroyWindow(m_Window);
    --s_GLFWWindowCount;

    if (s_GLFWWindowCount == 0)
    {
        glfwTerminate();
    }
}
