#pragma once
#include "Spaceship.hpp"
#include "obstacle.hpp"

class Game{
public:
    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleInput();

private:
    void CreateObstacles();
    std::vector<Obstacle> obstacles;
    Spaceship spaceship;
    void DeleteInactiveLasers();
};