#pragma once
#include "Spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include <vector>

class Game{
public:
    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleInput();

private:
    void CreateObstacles();
    void CreateAliens();
    std::vector<Obstacle> obstacles;
    Spaceship spaceship;
    void DeleteInactiveLasers();
    std::vector<Alien> aliens;
    void MoveAliens();
    int aliendirection;
};