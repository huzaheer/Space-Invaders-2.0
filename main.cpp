#include "raylib.h"

int main(void)
{
    // deciding dimensions of window
    int windowwidth = 750;
    int windowheight = 700;

    //initializing window
    InitWindow(windowwidth, windowheight, "Space Invaders 2.0");
    SetTargetFPS(60);

    ////////////////////////////// Game Loop ////////////////////////////////////
    while (WindowShouldClose() == false) { // Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
        BeginDrawing();
        EndDrawing();
    }


    //Any window created must be closed
    CloseWindow();
}