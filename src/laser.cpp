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
    DrawRectangle(position.x, position.y, 4, 15, {255, 0, 0, 255});
    // std::cout << position.x << " " << position.y;
};

void Laser::Update()
{
    position.y += speed;
    if (position.y < 0){
        active = false;
    }
};