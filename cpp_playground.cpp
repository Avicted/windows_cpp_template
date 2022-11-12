#include "cpp_playground.h"

global_variable int Running = 1;
global_variable HINSTANCE hinst;
global_variable HWND hwndMain;

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int APIENTRY WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hInstancePrevious, 
    PSTR cmdline, 
    int cmdshow
)
{
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WinProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("TESTING");

    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,                              // Optional window styles.
        TEXT("TESTING"),                // Window class
        TEXT("TESTING"),                // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,// Size and position
        NULL,                           // Parent window    
        NULL,                           // Menu
        hInstance,                      // Instance handle
        NULL                            // Additional application data
    );

    if (hwnd == NULL)
    {
        return (0);
    }

    ShowWindow(hwnd, cmdshow);

	// Main loop
	while (Running)
	{
		MSG msg = { };
		while (GetMessage(&msg, NULL, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (0);
}
