#include "alien.hpp"
#include <raylib.h>

Texture2D Alien::alienImages[3] = {};

Alien::Alien(int type, Vector2 position)
{
    this -> type = type;
    this -> position = position;

    if(alienImages[type - 1].id == 0){
        switch (type){
        case 1:
            alienImages[0] = LoadTexture("../graphics/1.png");
            break;
        case 2:
            alienImages[1] = LoadTexture("../graphics/2.png");
            break;
        case 3:
            alienImages[2] = LoadTexture("../graphics/3.png");
            break;
        default:
            alienImages[0] = LoadTexture("../graphics/1.png");
        }
    }
}

Alien::~Alien(){

}

void Alien::Draw(){
    // DrawTextureV(alienImages[type-1], position, WHITE);
    DrawTextureEx(alienImages[type-1], position, 0, 1.7, WHITE);
}

void Alien::UnloadImages(){
    for (int i = 0; i < 3; ++i){
        UnloadTexture(alienImages[i]);
    }
}

void Alien::AlienUpdate(int speed)
{
    position.x += speed;
}

int Alien::getType()
{
    return type;
}
