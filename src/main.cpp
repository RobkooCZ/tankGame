#include <windows.h>
#include "game.h"
#include "window.h"
#include "renderer.h"

// Declare hWnd as external since it's defined in window.cpp
extern HWND hWnd; // Add this line

HINSTANCE hInst; 

int main() {
    // Initialize application and window
    if (!InitWindow(hInst, SW_SHOWNORMAL)) {
        return 1; // Exit if initialization fails
    }

    // Initialize the renderer
    if (!InitRenderer(hWnd)) {  // Pass hWnd to renderer initialization
        return 1; // Exit if renderer initialization fails
    }

    // Message loop (runs until window is closed)
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);   // Translates keystrokes to characters
        DispatchMessage(&msg);    // Dispatch message to window procedure

        // Rendering call
        Render();  // Assuming RenderFrame handles the drawing
    }

    // Clean up renderer resources
    CleanupRenderer();  // Clean up renderer

    return static_cast<int>(msg.wParam);  // Return the exit code
}