#include "common_includes.h"
#include "spladi_platform.h"

int main(int argc, char **argv)
{
    bool Running = 1;
    int width = 640;
    int height = 340;

    PlatformWindow *window = PlatformCreateWindow(width, height);

    printf("\n    Testing main\n");

    while (Running)
    {
        if (!Running)
        {
            Running = false;
            return (0);
        }
    }

    return (0);
}