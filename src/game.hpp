#pragma once
#include "Spaceship.hpp"

class Game{
public:
    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleInput();

private:
    Spaceship spaceship;
    void DeleteInactiveLasers();
};