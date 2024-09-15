#include "boss.hpp"
#include <raylib.h>

Boss::Boss(Vector2 position)
{
    image = LoadTexture("../graphics/boss.png");
    this -> position = position;
}

Boss::~Boss(){
    
}

void Boss::Draw(){
    DrawTextureEx(image, position, 0, 1, WHITE);
}

void Boss::UnloadImages(){
    UnloadTexture(image);
}

void Boss::Update(int speed)
{
    position.x += speed;
}

Rectangle Boss::getRect()
{
    return Rectangle{position.x , position.y, 
                    (float) image.width, 
                    (float) image.height};
}
