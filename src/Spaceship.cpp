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