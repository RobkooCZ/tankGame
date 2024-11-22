// renderer.cpp
#include "renderer.h"
#include "config.h"
#include <windows.h>

// Global variables for device context and offscreen buffer
HDC hdc;           // Device Context for window
HDC hdcBuffer;     // Offscreen Device Context for drawing
HBITMAP hbmBuffer; // Offscreen Bitmap to hold the drawing

// Initialize the renderer
bool InitRenderer(HWND hWnd) {
    hdc = GetDC(hWnd);  // Get the window's device context

    // Create a compatible DC for offscreen rendering
    hdcBuffer = CreateCompatibleDC(hdc);

    // Get the client area of the window
    RECT rect;
    GetClientRect(hWnd, &rect);

    // Create a compatible bitmap for the buffer
    hbmBuffer = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);

    // Select the bitmap into the offscreen device context
    SelectObject(hdcBuffer, hbmBuffer);

    return true;
}

// Render function to draw to the window
void Render() {
    // Get the client area dimensions
    RECT rect;
    GetClientRect(GetForegroundWindow(), &rect);

    // ----- CREATE DIFFERENT COLORED BRUSHES FOR DRAWING -----
    HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));  // Red brush
    HBRUSH whiteBrush = CreateSolidBrush(RGB(255, 255, 255));  // White brush
    HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));  // Black brush

    // BACKGROUND
    FillRect(hdcBuffer, &rect, blackBrush);

    // DRAWING STUFF
    RECT rectToDraw = {XRES / 2 - 30, YRES / 2 - 30, XRES / 2 + 30, YRES / 2 + 30};
    FillRect(hdcBuffer, &rectToDraw, redBrush);

    // CLEAN UP BRUSHES
    DeleteObject(redBrush);
    DeleteObject(whiteBrush);
    DeleteObject(blackBrush);

    // Copy the offscreen buffer to the window (flip buffer)
    BitBlt(hdc, 0, 0, rect.right, rect.bottom, hdcBuffer, 0, 0, SRCCOPY);
}

// Cleanup renderer resources
void CleanupRenderer() {
    // Release resources
    DeleteDC(hdcBuffer);      // Delete the offscreen device context
    DeleteObject(hbmBuffer);  // Delete the offscreen bitmap
    ReleaseDC(GetForegroundWindow(), hdc);  // Release the window's device context
}