#pragma once
#include <vector>
#include <raylib.h>

class Boss{
    public:
        Boss(Vector2 position);
        ~Boss();
        void Draw();
        Texture2D image;
        void UnloadImages();
        void Update(int speed);
        Vector2 position;
        Rectangle getRect();
    private:
};