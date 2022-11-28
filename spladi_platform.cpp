#include "spladi_platform.h"

PlatformWindow *
PlatformCreateWindow(int width, int height)
{
    PlatformWindow *window = (PlatformWindow *)calloc(1, 1 * sizeof(PlatformWindow));
    return (window);
}