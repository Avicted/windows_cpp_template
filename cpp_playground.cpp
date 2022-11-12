#include "cpp_playground.h"

global_variable int Running = 1;
global_variable HINSTANCE hinst;
global_variable HWND hwndMain;

void* BitmapMemory;

int BitmapWidth;
int BitmapHeight;

int ClientWidth;
int ClientHeight;

// Draws a pixel at X, Y (from top left corner)
internal void 
DrawPixel(int X, int Y, u32 Color) 
{
    u32* Pixel = (u32*)BitmapMemory;
    Pixel += Y * BitmapWidth + X;
    *Pixel = Color;
}

internal void 
ClearScreen(u32 Color) 
{
    u32* Pixel = (u32*)BitmapMemory;
    for (int Index = 0; Index < BitmapWidth * BitmapHeight; ++Index) 
    {
        *Pixel++ = Color;
    }
}

LRESULT CALLBACK 
WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            TextOut(hdc, 0, 0, "Hello Team", 15);
            EndPaint(hWnd, &ps);
            return 0L;

        // Process other messages.   
    }
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

    // Get client area dimensions 
    RECT ClientRect;
    GetClientRect(hwnd, &ClientRect);
    ClientWidth = ClientRect.right - ClientRect.left;
    ClientHeight = ClientRect.bottom - ClientRect.top;

    BitmapWidth = ClientWidth;
    BitmapHeight = ClientHeight;

    // Allocate memory for the bitmap

    int BytesPerPixel = 4;

    BitmapMemory = VirtualAlloc(0,
        BitmapWidth * BitmapHeight * BytesPerPixel,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE
    );

    // BitmapInfo struct for StretchDIBits

    BITMAPINFO BitmapInfo;
    BitmapInfo.bmiHeader.biSize = sizeof(BitmapInfo.bmiHeader);
    BitmapInfo.bmiHeader.biWidth = BitmapWidth;
    // Negative height makes top left as the coordinate system origin for the DrawPixel function, otherwise its bottom left
    BitmapInfo.bmiHeader.biHeight = -BitmapHeight;
    BitmapInfo.bmiHeader.biPlanes = 1;
    BitmapInfo.bmiHeader.biBitCount = 32;
    BitmapInfo.bmiHeader.biCompression = BI_RGB;

    HDC DeviceContext = GetDC(hwnd);

	// Main loop
	while (Running)
	{
        // Process windows messages
        MSG Message;
        while (PeekMessage(&Message, nullptr, 0, 0, PM_REMOVE)) 
        {
            if (Message.message == WM_QUIT)
            {
                Running = false;
            }

            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }

        ClearScreen(0x333333);

        // Rendering
        for (int x = 0; x < BitmapWidth; ++x)
        {
            for (int y = 0; y < BitmapHeight; ++y)
            {
                DrawPixel(x, y, x * y);
            }
        }

        StretchDIBits(DeviceContext,
            0, 0,
            BitmapWidth, BitmapHeight,
            0, 0,
            ClientWidth, ClientHeight,
            BitmapMemory, &BitmapInfo,
            DIB_RGB_COLORS, SRCCOPY
        );
	}

	return (0);
}
