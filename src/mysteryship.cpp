#include "mysteryship.hpp"
#include <raylib.h>

MysteryShip::MysteryShip(){
    image = LoadTexture("../graphics/special.png");
    alive = false;
}

MysteryShip::~MysteryShip(){
    UnloadTexture(image);
}

void MysteryShip::Draw()
{
    if (alive){
        DrawTextureEx(image, position, 1, 1.8, WHITE);
    }
}

void MysteryShip::Update()
{
    if (alive){
        position.x += speed;
    }
    if (position.x < 0 || position.x > GetScreenWidth() - image.width){
        alive = false;
    }
}

void MysteryShip::Spawn()
{
    alive = true;
    position.y = 40;
    int rand = GetRandomValue(0, 1);
    if (rand == 1){
        position.x = 0;
        speed = 6;
    } else {
        position.x = GetScreenWidth() - image.width;
        speed = -6;
    }
}