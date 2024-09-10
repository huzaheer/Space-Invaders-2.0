#pragma once
#include <raylib.h>

class MysteryShip{
    public:
        MysteryShip();
        ~MysteryShip();
        void Draw();
        void Update();
        void Spawn();
    private:
        Texture2D image;
        Vector2 position;
        int speed;
        bool alive;
};