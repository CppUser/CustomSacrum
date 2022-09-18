#include "pch.h"
#include "Window.h"
#include "Platform/WinWindow.h"

std::unique_ptr<Window> Window::Create(const WindowProps& props /*= WindowProps()*/)
{
#ifdef SM_PLATFORM_WINDOWS
    return std::make_unique<WinWindow>(props);
#else
    printf("Unknown platform!");
    return nullptr;
#endif
}
