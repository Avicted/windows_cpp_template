#pragma once
#include <cstdlib>

struct platform_window;

platform_window PlatformCreateWindow(int Width, int Height);
void PlatformCloseWindow(platform_window *Window);

#ifdef __linux__
// linux code goes here
#include "linux_platform.h"

#elif _WIN32
// windows code goes here
#include "win32_platform.h"

#else

#endif