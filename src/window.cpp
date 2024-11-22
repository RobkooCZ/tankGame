// window.cpp
#include <windows.h>
#include "window.h"
#include "renderer.h"
#include "config.h"

// Global variable for storing the window handle
HWND hWnd;

// Function to initialize the window
bool InitWindow(HINSTANCE hInstance, int nCmdShow) {
    WNDCLASSA wc = {0};  // WNDCLASSA for narrow strings
    wc.lpfnWndProc = WndProc;         // Window procedure function
    wc.hInstance = hInstance;         // Handle to instance
    wc.lpszClassName = "TankGame";    // Narrow-character string for class name

    // Register the window class
    if (!RegisterClassA(&wc)) { 
        return false;  // Failed to register class
    }

    // Create the window with specific styles
    hWnd = CreateWindowExA(
        0,
        "TankGame",                    // Class name (narrow string)
        "Tank Game",                   // Window title (narrow string)
        WS_OVERLAPPEDWINDOW,           // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,  // Position 
        XRES,                           // Width
        YRES,                           // Height
        NULL,                          // Parent window (NULL for main window)
        NULL,                          // Menu (NULL for no menu)
        hInstance,                     // Application instance
        NULL                           // Additional parameters (NULL)
    );


    if (!hWnd) {
        return false; // Failed to create window
    }

    // Initialize the renderer
    if (!InitRenderer(hWnd)) {
        return false; // Renderer initialization failed
    }

    // Show and update the window
    ShowWindow(hWnd, nCmdShow);      
    UpdateWindow(hWnd);             

    return true;
}

// Window procedure to handle messages like close, resize, etc.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_SIZE:  // Handle resizing
            break;
        case WM_KEYDOWN: // Handle key presses (future game input)
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

// Main message loop
void MainLoop() {
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        // Render each frame
        Render();
    }

    // Cleanup resources on exit
    CleanupRenderer();
}