#include "linux_platform.h"

platform_window
OpenDisplay()
{
    platform_window Window = {}; // (platform_window)calloc(1, sizeof(platform_window));

    Window.d = XOpenDisplay(NULL);
    if (Window.d == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    Window.Handle = XCreateSimpleWindow(
        Window.d,
        RootWindow(Window.d, Window.s),
        10, 10, 100, 100, 1,
        BlackPixel(Window.d, Window.s),
        WhitePixel(Window.d, Window.s));

    return (Window);
}