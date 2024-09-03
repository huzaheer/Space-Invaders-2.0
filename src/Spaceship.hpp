#pragma once
#include <raylib.h>

class {
    public:
        Spaceship();
        ~Spaceship();
        void Draw();
        void moveLeft();
        void moveRight();
        void fireLaser();

    private:
        Texture2D image;
        Vector2 position;
};