#include <raylib.h>
#include "Spaceship.hpp"
#include "game.hpp"

int main(void)
{

    Color my_purple = {72,72,136,255};
    // deciding dimensions of window
    int windowwidth = 750;
    int windowheight = 700;

    //initializing window
    InitWindow(windowwidth, windowheight, "Space Invaders 2.0");
    SetTargetFPS(60);

    Game game;

    ////////////////////////////// Game Loop ////////////////////////////////////
    while (WindowShouldClose() == false) { // Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
        
        DrawRectangle(100, 100, 4, 15, {255, 0, 0, 255});

        game.HandleInput();
        game.Update();

        BeginDrawing();

        ClearBackground(my_purple);
        game.Draw();

        EndDrawing();
    }


    //Any window created must be closed
    CloseWindow();
}