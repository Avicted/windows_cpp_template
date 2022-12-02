#include "spladi_platform.h"
#include "linux_platform.h"
#include "win32_platform.h"

platform_window PlatformCreateWindow(int width, int height)
{

#ifdef __linux__
    // linux code goes here
    platform_window window = OpenDisplay();
    return (window);
#elif _WIN32
    // windows code goes here

#else

#endif

    return (window);
}