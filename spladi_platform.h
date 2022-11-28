#pragma once
#include <cstdlib>

struct PlatformWindow
{
};

PlatformWindow *PlatformCreateWindow(int Width, int Height);

#ifdef __linux__
// linux code goes here
#include "linux_platform.h"

#elif _WIN32
// windows code goes here
#include "win32_platform.h"

#else
#endif
