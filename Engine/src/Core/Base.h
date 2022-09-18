#pragma once

#include <memory>

#ifdef _DEBUG
#if defined(SM_PLATFORM_WINDOWS)
#define _DEBUGBREAK() __debugbreak()
#elif defined(SM_PLATFORM_WINDOWS)
#include <signal.h>
#define _DEBUGBREAK() raise(SIGTRAP)

#endif
#define _ENABLE_ASSERTS
#else
#define _DEBUGBREAK()
#endif