#pragma once
#include <raylib.h>

class Spaceship {  // Name the class correctly
public:
    Spaceship();   // Constructor declaration
    ~Spaceship();  // Destructor declaration
    void Draw();   // Method declarations
    void moveLeft();
    void moveRight();
    void fireLaser();

private:
    Texture2D image;     // Private members
    Vector2 position;
};