#include "laser.hpp"
#include <iostream>

Laser::Laser(Vector2 position, int speed)
{
    this -> position = position;
    this -> speed = speed;
    this -> active = true;
};

void Laser::Draw()
{
    if (active){
        DrawRectangle(position.x, position.y, 4, 15, {255, 0, 0, 255});
    }
};

void Laser::Update()
{
    if (position.y < 0 || position.y > GetScreenHeight()){
        active = false;
    } else {
        position.y += speed;
    }
}
Rectangle Laser::getRect()
{
    return Rectangle{position.x, position.y, float(4), float(15)};
};