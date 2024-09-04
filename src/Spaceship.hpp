#pragma once
#include <raylib.h>
#include <vector>
#include "laser.hpp"

class Spaceship {  // Name the class correctly
public:
    Spaceship();   // Constructor declaration
    ~Spaceship();  // Destructor declaration
    void Draw();   // Method declarations
    void moveLeft();
    void moveRight();
    void fireLaser();
    void Shoot();
    std::vector<Laser> lasers;
    double SinceLastFire;

private:
    Texture2D image;     // Private members
    Vector2 position;
};