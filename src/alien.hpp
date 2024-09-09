#pragma once
#include <vector>
#include <raylib.h>

class Alien{
    public:
        Alien(int type, Vector2 position);
        ~Alien();
        void Draw();
        static Texture2D alienImages[3];
        Texture2D image;
        static void UnloadImages();
        void AlienUpdate(int speed);
        Vector2 position;
        int getType();
    private:
        int type;
};