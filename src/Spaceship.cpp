#include "Spaceship.hpp"
#include <raylib.h>

Spaceship::Spaceship()
{
    //loads texture into GPU memory
    image = LoadTexture("../graphics/Spaceship_Asset.png");
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = (GetScreenHeight() - image.height);
}

Spaceship::~Spaceship()
{
    //frees data from GPU memory
    UnloadTexture(image);
}

void Spaceship::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void Spaceship::moveLeft()
{
    position.x -=7;
    if (position.x < 0){
        position.x = 0;
    }
}

void Spaceship::moveRight()
{
    position.x +=7;
    if (position.x > GetScreenWidth() - image.width){
        position.x = GetScreenWidth() - image.width;
    }
}