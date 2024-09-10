#include "Spaceship.hpp"
#include <raylib.h>
#include <vector>

Spaceship::Spaceship()
{
    //loads texture into GPU memory
    image = LoadTexture("../graphics/Spaceship_Asset.png");
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = (GetScreenHeight() - image.height);
    SinceLastFire = 0.0;
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

void Spaceship::Shoot()
{
    //-2 to account for width of laser which is 4
    if (GetTime() - SinceLastFire > 0.35){
        lasers.push_back(Laser({position.x + image.width/2 - 2, position.y}, -6));
        SinceLastFire = GetTime();
    }
}

Rectangle Spaceship::getRect()
{
    return Rectangle{position.x, position.y, float(image.width), float(image.height)};
}
