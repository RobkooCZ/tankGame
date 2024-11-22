#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>

// Function to initialize the window
bool InitWindow(HINSTANCE hInstance, int nCmdShow);

// Window procedure function to handle messages
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// Function to get the main window handle
HWND GetMainWindow();

#endif // WINDOW_H
