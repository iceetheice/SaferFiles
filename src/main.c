#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define RAYGUI_IMPLEMENTATION
#include "gui.h"


int main()
{
    InitWindow(600, 300, "SaferFiles");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        updateGUI();
        BeginDrawing();
        ClearBackground(WHITE);
        drawGUI();
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}