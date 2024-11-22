#include <windows.h>
#include "game.h"
#include "window.h"

// Global variable for the instance handle
HINSTANCE hInst;                               

int main() {
    // Initialize application and window
    if (!InitWindow(hInst, SW_SHOWNORMAL)) {
        return 1; // Exit if initialization fails
    }

    // Message loop (runs until window is closed)
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);   // Translates keystrokes to characters
        DispatchMessage(&msg);    // Dispatch message to window procedure
    }

    return static_cast<int>(msg.wParam);  // Return the exit code
}