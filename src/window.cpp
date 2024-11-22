#include <windows.h>
#include "window.h"

// Global variable for storing the window handle
HWND hWnd;

// Function to initialize the window
bool InitWindow(HINSTANCE hInstance, int nCmdShow) {
    WNDCLASSA wc = {0};  // WNDCLASSA for narrow strings
    wc.lpfnWndProc = WndProc;          // Window procedure function
    wc.hInstance = hInstance;          // Handle to instance
    wc.lpszClassName = "TankGame";     // Narrow-character string for class name

    if (!RegisterClassA(&wc)) {        // RegisterClassA for narrow-character strings
        return false; 
    }

    // Create the window with specific styles
    hWnd = CreateWindowExA(  // CreateWindowExA for narrow-character strings
        0,
        "TankGame",              // Class name (narrow string)
        "Tank Game",             // Window title (narrow string)
        WS_OVERLAPPEDWINDOW,     // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL  // Parent, menu, instance, and additional params
    );

    if (!hWnd) {
        return false; // Failed to create window
    }

    ShowWindow(hWnd, nCmdShow);  // Display the window
    UpdateWindow(hWnd);          // Update window

    return true;
}

// Window procedure to handle messages like close, resize, etc.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_SIZE:  // Handle resizing
            break;
        case WM_KEYDOWN: // Handle key presses (for later game input)
            break;
        case WM_DESTROY: // Handle window closing
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Function to get the main window handle
HWND GetMainWindow() {
    return hWnd;
}