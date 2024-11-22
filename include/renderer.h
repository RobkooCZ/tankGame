// renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>

bool InitRenderer(HWND hWnd);  // Initialize the renderer
void Render();                 // Main render function (called every frame)
void CleanupRenderer();        // Cleanup resources

#endif // RENDERER_H