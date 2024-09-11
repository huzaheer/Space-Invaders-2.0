#include <raylib.h>
#include "Spaceship.hpp"
#include "game.hpp"
#include "alien.hpp"
#include <string>

std::string FormatWithLeadingZeros(int number, int width){
    std::string numbertext = std::to_string(number);
    int leadingzeroes = width - numbertext.length();
    numbertext = std::string(leadingzeroes, '0') + numbertext;
    return numbertext;
}

int main(void)
{

    Color my_purple = {72,72,136,255};
    Color yellow = {243, 216, 63, 255};
    // deciding dimensions of window
    int windowwidth = 800;
    int windowheight = 800;
     
    //initializing window
    InitWindow(windowwidth, windowheight, "Space Invaders 2.0");
    SetTargetFPS(60);

    Font font = LoadFontEx("../graphics/munro.ttf", 64, 0, 0);
    Texture2D ship_img =  LoadTexture("../graphics/Spaceship_Asset.png");

    Game game;

    ////////////////////////////// Game Loop ////////////////////////////////////
    while (WindowShouldClose() == false) { // Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)

        game.HandleInput();
        game.Update();

        BeginDrawing();

        ClearBackground(my_purple);
        DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, 2, yellow);
        DrawLineEx({25, 730}, {775, 730}, 3, yellow);

        //Game status indicator
        if (game.run){
            DrawTextEx(font, "Level 01", {600, 740}, 34, 2, yellow);
        } else {
            DrawTextEx(font, "Game Over", {600, 740}, 34, 2, yellow);
        }   
        
        //Lives indicator
        for (int i = 0; i < game.lives; i++){
            DrawTextureEx(ship_img, {float(50*i) + 55, 740}, 0, 0.7, WHITE);
        }

        //Score indicator
        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string final_score = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, final_score.c_str(), {50, 40}, 34, 2, yellow);

        //Highscore indicator
        DrawTextEx(font, "HIGH SCORE", {615, 15}, 34, 2, yellow);
        std::string final_highscore = FormatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, final_highscore.c_str(), {615, 40}, 34, 2, yellow);


        game.Draw();

        EndDrawing();
    }


    //Any window created must be closed
    CloseWindow();
}