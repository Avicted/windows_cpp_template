#pragma once

#include "common_includes.h"
#include <X11/Xlib.h>

struct platform_window
{
    Display *d;
    Window Handle;
    XEvent e;
    const char *msg = "Hello, team!";
    int s;
};

platform_window OpenDisplay();